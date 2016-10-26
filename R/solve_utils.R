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

# returns a matrix with exogenous variables, including lagged exogenous
# variables
get_exo <- function(mdl) {
    if (mdl@exo_count > 0) {
        exo  <- mdl@exo_data
    } else {
        exo <- matrix(nrow = 0, ncol = 0)
    }
}

# returns a vector with endogenous variables in the solution period
get_solve_endo <- function(mdl) {
    return (as.numeric(t(mdl@endo_data[mdl@model_period, ])))
}
# returns the residual of the stacked-time system
# x is vector of endogenous variables in the solution period
get_residual <- function(x, mdl, lags, leads, exo, nper) {
    i_cols <- which(mdl@lead_lag_incidence != 0)
    i_rows <- 1:mdl@endo_count
    residual <- numeric(nper * mdl@endo_count)
    data <- c(lags, x, leads)
    for (it in 1 : nper) {
        y <- data[i_cols]
        d <- mdl@f_dynamic(y, exo, mdl@params,
                           it + mdl@max_exo_lag)
        residual[i_rows] <- d
        i_cols <- i_cols + mdl@endo_count
        i_rows <- i_rows + mdl@endo_count
    }
    return (residual)
}

#' @importFrom Matrix Matrix
get_jac <- function(x, mdl, lags, leads, exo, nper, sparse = TRUE) {
    imat <- mdl@lead_lag_incidence
    i_cols <- which(imat != 0)
    i_cols_a0 <- which(imat[, 2] != 0)
    i_cols_a1 <- which(imat[, 2:3] != 0)
    i_cols_a  <- i_cols
    i_cols_0  <- imat[, 2][imat[, 2] != 0]
    i_cols_1  <- imat[, 2:3][imat[, 2:3] != 0]
    i_cols_t  <- imat[, 1:2][imat[, 1:2] != 0]

    # the Jacobian returned by mdl@f_dynamics also
    # contains the derivatives of the exogenous variables
    # in the colums last. The first length(i_cols)
    # columns contains the derivatives to the
    # endogenous variables, lags and leads
    # TODO: in this package we do'nt need derivatives
    # of the equations to exogenous variables, therfore
    # modify the preprocessor.
    i_cols_j  <- 1 : length(i_cols)
    i_rows <- 1:mdl@endo_count
    data <- c(lags, x, leads)
    dim <- nper * mdl@endo_count
    if (sparse) {
        # sparse matrix from the Matrix package
        a <- Matrix(0, nrow = dim, ncol = dim)
    } else {
        # a normal R matrix
        a <- matrix(0, nrow = dim, ncol = dim)
    }
    for (it in 1 : nper) {
        y <- data[i_cols]
        jac <- mdl@f_dynamic(y, exo, mdl@params,
                             it + mdl@max_exo_lag, jac = TRUE)[[2]]
        if (nper == 1) {
            a[i_rows, i_cols_a0] <- jac[ , i_cols_0]
        } else if (it == 1) {
            a[i_rows, i_cols_a1] <- jac[ , i_cols_1]
        } else if (it == nper) {
            a[i_rows, i_cols_a[i_cols_t]] <- jac[ , i_cols_t]
        } else {
            a[i_rows, i_cols_a] <- jac[ , i_cols_j]
        }
        i_cols <- i_cols + mdl@endo_count
        i_rows <- i_rows + mdl@endo_count
        if (it > 1) {
            i_cols_a <- i_cols_a + mdl@endo_count
        }
    }
    return (a)
}
