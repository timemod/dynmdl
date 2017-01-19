# Solve a non-linear backwards system using package nleqslv
# param x: initial guess
# param fun: a function of x returning a vector of functional values
# param jacfun: a function that returns the Jacobian of the systems of equations,
#               typically as one of the  matrix classes of package Matrix
#' @importFrom nleqslv nleqslv
solve_backward_model <- function(model_period, endo_data, exo_data, params,
                                 lead_lag_incidence, f_dynamic, jac_dynamic,
                                 control) {

    start_per <- start_period(model_period)
    nper <- length_range(model_period)
    nendo <- ncol(endo_data)

    data <- t(endo_data)

    jac_cols <- lead_lag_incidence[, "0"]

    max_lag <- abs(as.numeric(colnames(lead_lag_incidence)[1]))
    lag_indices <- which(lead_lag_incidence[, 1 : max_lag] != 0)

    f <- function(x, lags, iper) {
        return (f_dynamic(c(lags, x), exo_data, params, iper + max_lag))
    }
    jac <- function(x, lags, iper) {
        return (jac_dynamic(c(lags, x), exo_data, params,
                            iper + max_lag)[, jac_cols])
    }

    itr_tot <- 0

    if (!control$silent) {
        cat(sprintf("\nSolving backwards model for period %s\n",
                as.character(model_period)))
    }

    error <- FALSE
    for (iper in 1:nper) {
        per_txt <- as.character(start_per + (iper - 1))
        lags <- data[lag_indices + (iper - 1) * nendo]
        cur_indices <- (1:nendo) + (iper - 1 + max_lag) * nendo
        start <- data[cur_indices]

        out <- nleqslv(start, fn = f, jac = jac, method = "Newton",
                       lags = lags, iper = iper)

        if (!control$silent) {
            if (out$termcd != 1) {
                cat(sprintf("No convergence for %s in %d iterations\n", per_txt,
                               out$iter))
                error <- TRUE
                break
            } else
                cat(sprintf("Convergence for %s in %d iterations\n", per_txt,
                            out$iter))
        }

        itr_tot <- itr_tot + out$iter
        data[cur_indices] <- out$x
    }

    if (!control$silent) {
        cat(sprintf("Total number of iterations: %d\n", itr_tot))
    }

    if (error) {
        stop("Solving backwards model not succesful")
    }

    # update data
    x <- data[(1 : (nper * nendo)) + max_lag * nendo]
    return (list(solved = !error, itr_tot = itr_tot, x = x))
}
