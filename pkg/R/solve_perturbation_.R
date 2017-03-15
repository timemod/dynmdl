# Auxiliary function for method solve_perturbation of class DynMdl.
# This function constructs the path of the endogenous variables
# based on the solution created by solve_first_order.
# The perturbation approach currently only works for models with
# - no exogenous lags and leads
# - no endogenous lags and leads > 1
# - only exogenous shocks in the first solution pertiod
#' @importFrom regts get_regperiod_range
solve_perturbation_  <- function(ss, max_lag, exo_data, endo_data, static_exos,
                                 static_endos) {

    nendo <- length(static_endos)

    sel <-  which(ss$kstate[, 2, drop = FALSE] <= max_lag + 1)
    k2 <- ss$kstate[sel, c(1,2), drop = FALSE]
    k2 <- k2[, 1, drop = FALSE] +
        (max_lag + 1 - k2[, 2, drop = FALSE]) * nendo

    endo_data[1, ] <- endo_data[1, ] - static_endos

    exo_ <- exo_data[ , ] - rep(static_exos, each = nrow(exo_data))

    data_period <- get_regperiod_range(exo_data)
    check_per <- regperiod_range(start_period(data_period) + max_lag + 1,
                                 end_period(data_period))
    # start_period(data_period) + max_lag + 1 is the second solution period
    if (sum(abs(exo_[check_per])) > .Machine$double.eps) {
        # Currentlty, only exogenous shocks in the first solution period are
        # allowed. Exogenous shocks at later times would requires
        # so called deterministic exogenoeous variables. dynmdl does not
        # support that.
        stop(paste("The perturbation approach currently only allows shocks",
                   "in the first period"))
    }

    if (length(ss$ghu) == 0) {
        # purely backward models?
        stop("Situation where length(ghu) == 0 not yet supported")
    } else if (length(ss$ghx) == 0) {
        # purely forward models?
        stop("Situation where length(ghx) == 0 not yet supported")
    }

    epsilon <- ss$ghu %*% t(exo_)
    for (i in 2 : length_range(data_period)) {
        yhat <- t(endo_data[i - 1, ss$order_var[k2], drop = FALSE])
        endo_data[i, ss$order_var] <- ss$ghx %*% yhat  +
                                    epsilon[ , i, drop = FALSE]
    }

    # add steady state values
    endo_data[ , ] <- endo_data[ , ]  + rep(static_endos, each = nrow(endo_data))
    return (endo_data)
}
