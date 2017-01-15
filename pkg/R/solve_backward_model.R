# Solve a non-linear backwards system using package nleqslv
# param x: initial guess
# param fun: a function of x returning a vector of functional values
# param jacfun: a function that returns the Jacobian of the systems of equations,
#               typically as one of the  matrix classes of package Matrix
#' @importFrom nleqslv nleqslv
solve_backward_model <- function(model_period, endo_data, exo_data, params,
                                 lead_lag_incidence, f_dynamic) {

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
        return (f_dynamic(c(lags, x), exo_data, params, iper + max_lag,
                          jac = TRUE)[, jac_cols])
    }

    itr_tot <- 0

    cat(sprintf("\nSolving backwards model for period %s\n",
                as.character(model_period)))
    for (iper in 1:nper) {
        per_txt <- as.character(start_per + (iper - 1))
        lags <- data[lag_indices + (iper - 1) * nendo]
        cur_indices <- (1:nendo) + (iper - 1 + max_lag) * nendo
        start <- data[cur_indices]
        out <- nleqslv(start, fn = f, jac = jac, method = "Newton", lags = lags,
                       iper = iper)
        if (out$termcd != 1) {
            cat(sprintf("No convergence for %s in %d iterations\n", per_txt, out$iter))
        } else {
            cat(sprintf("Convergence for %s in %d iterations\n", per_txt, out$iter))
        }

        itr_tot <- itr_tot + out$iter
        data[cur_indices] <- out$x
    }
    cat("\n")

    x <- data[(1 : (nper * nendo)) + max_lag * nendo]

    return (list(itr_tot = itr_tot, x = x))
}
