# Solve a non-linear backwards system using package nleqslv
# param x: initial guess
# param fun: a function of x returning a vector of functional values
# param jacfun: a function that returns the Jacobian of the systems of equations,
#               typically as one of the  matrix classes of package Matrixt
time_functions <- function(model_period, endo_data, exo_data, params,
                          lead_lag_incidence, f_dynamic, jac_dynamic) {

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

    lags <- data[lag_indices]
    cur_indices <- (1:nendo) + (max_lag) * nendo
    start <- data[cur_indices]

    cat("Timing function evaluation:\n")
    print(system.time(
        f(start, lags, 1)
    ))

    cat("Timing Jacobian evaluation:\n")
    print(system.time(
        jac(start, lags, 1)
    ))

    return(invisible(NULL))
}
