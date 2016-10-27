# returns a vector with lags
#' @importFrom regts regperiod_range
#' @importFrom regts start_period
get_lags <- function(mdl) {
    lag_per <- regperiod_range(start_period(mdl@endo_period),
                               start_period(mdl@model_period) - 1)
    return (as.numeric(t(mdl@endo_data[lag_per, ])))
}

# returns a vector with leads
#' @importFrom regts end_period
get_leads <- function(mdl) {
    lead_per <- regperiod_range(end_period(mdl@model_period) + 1,
                                end_period(mdl@endo_period))
    return (as.numeric(t(mdl@endo_data[lead_per, ])))
}

# returns a vector with endogenous variables in the solution period
get_solve_endo <- function(mdl) {
    return (as.numeric(t(mdl@endo_data[mdl@model_period, ])))
}
# returns the residual of the stacked-time system
# x is vector of endogenous variables in the solution period
get_residual <- function(x, mdl, lags, leads, nper) {
    i_cols <- which(mdl@lead_lag_incidence != 0)
    i_rows <- 1:mdl@endo_count
    residual <- numeric(nper * mdl@endo_count)
    data <- c(lags, x, leads)
    for (it in 1 : nper) {
        y <- data[i_cols]
        d <- mdl@f_dynamic(y, mdl@exo_data, mdl@params,
                           it + mdl@max_exo_lag)
        residual[i_rows] <- d
        i_cols <- i_cols + mdl@endo_count
        i_rows <- i_rows + mdl@endo_count
    }
    return (residual)
}

#' @importFrom methods new
#' @importFrom methods as
#' @importFrom Matrix Matrix
get_jac <- function(x, mdl, lags, leads, nper, sparse = TRUE) {
    endos <- c(get_lags(mdl), x, get_leads(mdl))
    jacfun <- function(y, it) {
        return (mdl@f_dynamic(y, mdl@exo_data, mdl@params, it, jac = TRUE)[[2]])
    }
    mat_info <- get_triplet_jac(mdl, endos, jacfun)
    n <- lensub(mdl@model_period) * mdl@endo_count
    jac <- new("dgTMatrix", i = mat_info$rows, j = mat_info$columns,
                        x = mat_info$values, Dim = as.integer(rep(n, 2)))

    if (sparse) {
        jac <- as(jac, "dgCMatrix")
    } else {
        jac <- as(jac, "matrix")
    }
    return (jac)
}
