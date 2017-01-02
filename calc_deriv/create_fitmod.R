create_fitmod <- function(mod_file, fit_instruments) {

    ret <- compute_first_order(mod_file)
    output_file <- "newmod.txt"

    # derivatives with respect to fit intruments
    d  <- ret$exo_deriv[ , fit_instruments]
    f <- function(x) {
        l_names <- paste("l", seq_along(x), sep = "_")
        x <- ifelse(nchar(x) > 0, paste(l_names, x, sep = " * "), x)
        ret <- paste(x[!is.na(x)], collapse = " + ")
        return (ret)
    }
    deriv1 <- apply(d, MARGIN = 2, FUN = f)
    sigmas <- paste("sigma", fit_instruments, sep = "_")
    deriv0 <- paste(fit_instruments, paste0(sigmas, "^2"), sep = " / ")

    writeLines(paste0(paste(deriv0, deriv1, sep = " + "), " = 0;"), output_file)

    # endogenous variables
    d  <- ret$endo_deriv

    # multiply with lagrange multipliers
    f <- function(x) {
        l_names <- paste("l", seq_along(x), sep = "_")
        l_names <- paste0(l_names, "[0]")
        x <- ifelse(nchar(x) > 0, paste(l_names, x, sep = " * "), x)
        return (x)
    }
    d <- apply(d, MARGIN = 2, FUN = f)

    pattern <- "\\[(-?\\d+)\\]"

    f <- function(x, endo_lags) {
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
    dshift <- apply(d, MARGIN = 1, FUN = f, endo_lags = ret$endo_lags)

    lli <- ret$model_info$dynamic_model$lead_lag_incidence

    dshift <- t(dshift)

    # handle **
    fpow <- function(x) {
        return (gsub("\\*\\*", "^", x))
    }
    dshift <- apply(dshift, MARGIN = c(1,2), FUN = fpow)

    for (var in 1:nrow(lli)) {
        row <- lli[var, ]
        i <- row[row > 0]
        dat <- as.character(dshift[, i])
        dat <- dat[!is.na(dat)]
        cat(paste0(paste(dat,  collapse = " + "), " = 0;\n"),
            file = output_file, append = TRUE)
    }

    return (invisible(NULL))
}
