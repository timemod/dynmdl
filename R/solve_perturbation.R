# Solve the model using the perturbation approach used in the Dynare function
# stoch_simul. This approach only allows for shocks in  the first solution period.
solve_perturbation <- function(mdl) {
    rules <- mdl$rules
    sel <-  which(rules$kstate[, 2, drop = FALSE] <= mdl$max_endo_lag + 1)
    k2 <- rules$kstate[sel, c(1,2), drop = FALSE]
    k2 <- k2[, 1, drop = FALSE] +
        (mdl$max_endo_lag + 1 - k2[, 2, drop = FALSE]) * mdl$endo_count

    endo_names <- names(mdl$endos)
    mdl$endo_data[1, endo_names] <- mdl$endo_data[1, endo_names] - mdl$endos

    nper <- length_range(mdl$model_period)

    exo_names <- names(mdl$exos)
    ex_ <- mdl$exo_data[, exo_names] - rep(mdl$exos, each = nrow(mdl$exo_data))

    check_per <- regperiod_range(start_period(mdl$model_period) + 1,
                                 end_period(mdl$exo_period))
    if (sum(abs(ex_[check_per])) > .Machine$double.eps) {
        # The dynare command stoch_simul only allows for shocks in the first
        # period. An analytical solution in a Taylor approximation requires
        # so called deterministic exogenoeous variables. I do not known
        # yet how this works.
        stop(paste("The perturbation approach currently only allows shocks",
                   "in the first period"))
    }

    if (mdl$max_exo_lead == 0 && mdl$max_endo_lead > 0) {
        # add an extra row to ex_, so that we can simulate up to the last period
        # in mdl$endo_period
        ex_[end_period(mdl$endo_period)] <- 0
    }

    iter <- NROW(ex_)
    if (length(rules$ghu) == 0) {
        # purely backward?
        stop("Situation where length(ghu) == 0 not yet supported")
    } else if (length(rules$ghx) == 0) {
        # purely forward
        stop("Situation where length(ghx) == 0 not yet supported")
    } else {
        epsilon <- rules$ghu %*% t(ex_)
        for (i in 2 : (iter + mdl$max_endo_lag)) {
            yhat <- t(mdl$endo_data[i - 1, rules$order_var[k2], drop = FALSE])
            mdl$endo_data[i, rules$order_var] <- rules$ghx %*% yhat  +
                                     epsilon[ , i - 1, drop = FALSE]
        }
        n <- iter + mdl$max_endo_lag
        mdl$endo_data[1:n, ] <- mdl$endo_data[1 : n, ]  +
                                rep(mdl$endos, each = n)
    }
    return (invisible(mdl))
}
