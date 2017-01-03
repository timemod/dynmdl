create_fitmod <- function(mod_file, fit_instruments) {

    output_file <- "newmod.mod"

    ret <- compute_first_order(mod_file)
    sink(output_file)

    vars <- ret$model_info$endo_names
    # names of lagrange multipliers:
    l_vars   <- paste("l", seq_along(names), sep = "_")
    fit_vars <- paste("fit", vars, sep = "_")
    exo_vars <- paste(vars, "exo", sep = "_")
    sigmas <- paste("sigma", fit_instruments, sep = "_")
    # TODO: check that the intersection of fit_vars, exo_vars,
    # l_vars and sigmas with vars is zero

    mult_lagrange <- function(x, l_names) {
        # multiply a column of derivatives with the
        # lagrange multipliers
        return (ifelse(nchar(x) > 0, paste(l_names, x, sep = " * "), x))
    }

    res_deriv <- apply(ret$exo_deriv[ , fit_instruments], MARGIN = 2,
                       FUN = mult_lagrange, l_names = l_vars)
    endo_deriv <- apply(ret$endo_deriv, MARGIN = 2, FUN = mult_lagrange,
                        l_names = paste0(l_vars, "[0]"))

    # derivatives with respect to fit intruments:
    sum_derivatives <- function(x) {
        return (paste(x[!is.na(x)], collapse = " + "))
    }
    deriv1 <- apply(res_deriv, MARGIN = 2, FUN = sum_derivatives)
    deriv0 <- paste(fit_instruments, paste0(sigmas, "^2"), sep = " / ")

    writeLines("% derivatives of the fit instruments:")
    writeLines(paste0(paste(deriv0, deriv1, sep = " + "), " = 0;"))
    writeLines("")

    # endogenous variables
    pattern <- "\\[(-?\\d+)\\]"
    handle_lags <- function(x, endo_lags) {
        repl <- function(x) {
            i <- as.integer(x) - shift
            if (i == 0) {
                return ("")
            } else {
                return (paste0("(", i, ")"))
            }
        }
        for (i in seq_along(x)) {
            shift <- endo_lags[i]
            if (!is.na(x[i])) {
                x[i] <- gsubfn(pattern, repl, x[i])
            }
        }
        return (x)
    }
    dshift <- apply(endo_deriv, MARGIN = 1, FUN = handle_lags,
                    endo_lags = ret$endo_lags)
    dshift <- t(dshift)

    lli <- ret$model_info$dynamic_model$lead_lag_incidence

    # handle **
    fpow <- function(x) {
        return (gsub("\\*\\*", "^", x))
    }
    dshift <- apply(dshift, MARGIN = c(1,2), FUN = fpow)

    writeLines(c("", "% First order conditions endogenous variables:", ""))
    for (ivar in 1:nrow(lli)) {
        row <- lli[ivar, ]
        i <- row[row > 0]
        dat <- as.character(dshift[, i])
        dat <- dat[!is.na(dat)]
        first_order <- paste(dat,  collapse = " + ")
        equation <- paste(fit_vars[ivar], "* (", vars[ivar], "-",
                          exo_vars[ivar], ") + (1 - ", fit_vars[ivar], ") * (",
                          first_order, ")", " = 0;")
        writeLines(strwrap(equation, width = 80))
        writeLines("")
    }

    sink()
    return (invisible(NULL))
}
