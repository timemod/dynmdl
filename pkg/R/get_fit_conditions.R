# Computes the first order conditions for the fit procedure
#
# @param mod_file the filename of the mod file
# @param residuals a list of residuas used in the fit procedure
#' @importFrom gsubfn gsubfn
# @return a list with information about the derivatives
get_fit_conditions <- function(mod_file, residuals) {
    
    # regular expressions:
    lag_pattern <- "\\[(-?\\d+)\\]"

    model_info <- compute_derivatives(mod_file)
    with(model_info, {
        # a problem will occur if the residuals have
        # lags or leads. When computing derivatives with respect to the
        # exogenous variables, the dynare preprocessor ignores
        # leads and leads. For other variables a lag or lead > 1
        # would not result in an error
        # TODO: maybe we could search for lags and leads of residuals
        # in tbe mod file, and given an error only if the residuals
        # occur with this leads.
        if (dynamic_model$max_exo_lag > 0 ||  dynamic_model$max_exo_lead > 1) {
            stop("compute_first_order cannot handle exogenous lags and leads > 0")
        }
    })
    lli <- model_info$dynamic_model$lead_lag_incidence
    sel <- lli != 0
    rows <- row(lli)[sel]
    cols <- col(lli)[sel]
    endo_lags <- cols - model_info$dynamic_model$max_endo_lag - 1
    endo_names <- model_info$endo_names[rows]
    endo_deriv <- model_info$dynamic_model$derivatives[, 1:length(endo_names)]
    colnames(endo_deriv) <- paste0(endo_names, paste0("(", endo_lags, ")"))

    exo_deriv <- model_info$dynamic_model$derivatives[, -(1:length(endo_names))]
    colnames(exo_deriv) <- model_info$exo_names
    res_deriv <- exo_deriv[, residuals, drop = FALSE]
    
    # handle **
    fpow <- function(x) {
        return (gsub("\\*\\*", "^", x))
    }
    res_deriv  <- apply(res_deriv,  MARGIN = c(1,2), FUN = fpow)
    endo_deriv <- apply(endo_deriv, MARGIN = c(1,2), FUN = fpow)

    vars <- model_info$endo_names
    # names of lagrange multipliers:
    l_vars   <- paste("l", seq_along(vars), sep = "_")
    fit_vars <- paste("fit", vars, sep = "_")
    exo_vars <- paste(vars, "exo", sep = "_")
    sigmas <- paste("sigma", residuals, sep = "_")
    # TODO: check that the intersection of fit_vars, exo_vars,
    # l_vars and sigmas with vars is zero

    mult_lagrange <- function(x, l_names) {
        # multiply a column of derivatives with the
        # lagrange multipliers
        return (ifelse(nchar(x) > 0, paste(l_names, x, sep = " * "), x))
    }

    # replace [d] with () in exo_deriv
    handle_lags_res <- function(x) {
        if (is.na(x)) {
            return(x)
        }
        repl <- function(x) {
            i <- as.integer(x)
            if (i == 0) {
                return ("")
            } else {
                return (paste0("(", i, ")"))
            }
        }
        return(gsubfn(lag_pattern, repl, x))
    }
    res_deriv <- apply(res_deriv, MARGIN = c(1,2), FUN = handle_lags_res)

    res_deriv <- apply(res_deriv, MARGIN = 2, FUN = mult_lagrange, 
                       l_names = l_vars)
    endo_deriv <- apply(endo_deriv, MARGIN = 2, FUN = mult_lagrange,
                        l_names = paste0(l_vars, "[0]"))

    # derivatives with respect to fit intruments:
    sum_derivatives <- function(x) {
        return (paste(x[!is.na(x)], collapse = " + "))
    }
    deriv1 <- apply(res_deriv, MARGIN = 2, FUN = sum_derivatives)
    deriv0 <- paste(residuals, paste0(sigmas, "^2"), sep = " / ")
    res_equations <- (paste0(paste(deriv0, deriv1, sep = " + "), " = 0;"))

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
                x[i] <- gsubfn(lag_pattern, repl, x[i])
            }
        }
        return (x)
    }

    # endogenous variables
    dshift <- apply(endo_deriv, MARGIN = 1, FUN = handle_lags,
                    endo_lags = endo_lags)
    dshift <- t(dshift)

    nendo <- nrow(lli)
    endo_equations <- character(nendo)
    for (ivar in seq_len(nendo)) {
        row <- lli[ivar, ]
        i <- row[row > 0]
        dat <- as.character(dshift[, i])
        dat <- dat[!is.na(dat)]
        first_order <- paste(dat,  collapse = " + ")
        equation <- paste(fit_vars[ivar], "* (", vars[ivar], "-",
                          exo_vars[ivar], ") + (1 - ", fit_vars[ivar], ") * (",
                          first_order, ")", " = 0;")
        endo_equations[ivar] <- equation
    }

    return (list(vars = vars, l_vars = l_vars, fit_vars = fit_vars,
                 exo_vars = exo_vars, residuals = residuals, sigmas = sigmas,
                 orig_exos = setdiff(model_info$exo_names, residuals),
                 res_equations = res_equations,
                 endo_equations = endo_equations))
}
