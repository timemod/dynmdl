# perform a stochastic simulation to first order
stoch_simul <- function(mdl) {
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
    cat("ex_\n")
    print(ex_)
    if (mdl$max_exo_lead == 0 && mdl$max_endo_lead > 0) {
        # add an extra row to ex_, so that we can simulate the last period
        ex_[end_period(mdl$endo_period)] <- 0
    }
    cat("ex_\n")
    print(ex_)

    cat("ghu\n")
    print(rules$ghu)

    iter <- nrow(ex_)
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
        mdl$endo_data[1:n, ] <- mdl$endo_data[1 : n] + rep(mdl$endos, each = n)
    }
    return (mdl)
}
