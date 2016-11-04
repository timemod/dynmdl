solve_first_order <- function(mdl) {

    state_space <- StateSpace$new(mdl)
    order_var <- state_space$order_var

    npred <- mdl$npred
    nboth <- mdl$nboth
    nfwrd <- mdl$nfwrd
    nstatic <- mdl$nstatic
    ndynamic <- npred + nboth + nfwrd
    nsfwrd <- nfwrd + nboth

    max_lag <- mdl$max_endo_lag

    nz <- nnz(mdl$lead_lag_incidence)
    lead_id <- which(mdl$lead_lag_incidence[, max_lag + 2] != 0)
    lead_idx <- mdl$lead_lag_incidence[lead_id, max_lag + 2]
    if (max_lag) {
        lag_id <- which(mdl$lead_lag_incidence[, 1] != 0)
        lag_idx <- mdl$lead_lag_incidence[lag_id, 1]
    } else {
        lag_id <- numeric(0)
        lag_idx <- numeric(0)
    }
    both_id <- intersect(lead_id, lag_id)
    if (max_lag) {
        no_both_lag_id <- setdiff(lag_id, both_id)
    } else {
        no_both_lag_id <- lag_id
    }
    innovations_idx <- nz + 1:mdl$exo_count
    state_var <- c(no_both_lag_id, both_id)

    # indices of the endogenous variables at time t
    index_c <- nonzeros(mdl$lead_lag_incidence[, max_lag + 1])
    n_current <- length(index_c)

    index_s <- npred + nboth + seq_len(nstatic)
    indexi_0 <- npred + nboth

    npred0 <- nnz(mdl$lead_lag_incidence[no_both_lag_id, max_lag + 1])
    index_0m <- indexi_0 + nstatic  + seq_len(npred0)
    nfwrd0 <- nnz(mdl$lead_lag_incidence[lead_id, 2])
    index_0p <- indexi_0 + nstatic + npred0 + seq_len(nfwrd0)
    index_m <- seq_len(npred + nboth)
    index_p <- npred + nboth + n_current + seq_len(nfwrd + nboth)
    row_indx_de_1 <- seq_len(ndynamic)
    row_indx_de_2 <- ndynamic + seq_len(nboth)
    row_indx <- nstatic + row_indx_de_1
    index_d <- c(index_0m, index_p)
    llx <- mdl$lead_lag_incidence[order_var, , drop = FALSE]
    index_d1 <- c(which(llx[nstatic + seq_len(npred), max_lag + 1] != 0),
                  npred + nboth + seq_len(nsfwrd))
    index_d2 <- npred + seq_len(nboth)
    index_e <- c(index_m, index_0p);
    index_e1 <- c(seq_len(npred + nboth),
                  npred + nboth +
              which(llx[nstatic + npred + seq_len(nsfwrd), max_lag + 1] != 0)
    )
    index_e2 <- npred + nboth + seq_len(nboth)

    nper_exo <- mdl$max_exo_lag + mdl$max_exo_lead + 1

    nper_endo <- mdl$max_endo_lag + mdl$max_endo_lead + 1
    exos <- rep(mdl$exos, nper_exo)
    endos <- rep(mdl$endos, nper_endo)
    y <- endos[which(mdl$lead_lag_incidence != 0)]
    it <- mdl$max_exo_lag + 1
    jac <- mdl$f_dynamic(y, exo, mdl$params, it, jac = TRUE)

    vec <- llx[llx != 0]
    reorder_jacobian_columns <- c(vec, nz + seq_len(mdl$exo_count))
    jac <- jac[, reorder_jacobian_columns, drop = FALSE]

    if (nstatic > 0) {
        ret <- qr(jac[, index_s])
        qmat <- qr.Q(ret, complete = TRUE)
        jac <- t(qmat) %*% jac
    }

    n <- nboth + ndynamic
    d <- matrix(0, nrow = n, ncol = n)
    e <- matrix(0, nrow = n, ncol = n)
    d[row_indx_de_1, index_d1] <- jac[row_indx, index_d]
    d[row_indx_de_2, index_d2] <- diag(nboth)
    e[row_indx_de_1, index_e1] <- -jac[row_indx, index_e]
    e[row_indx_de_2, index_e2] <- diag(mdl$nboth)
    ret <- QZ::geigen(e, d, only.values = TRUE)
    eigval <- ret$ALPHA / ret$BETA

    sdim <- sum(abs(eigval) <= 1)
    nba <- nrow(state_space$kstate) - sdim
    if (nba > nsfwrd) {
        warning("Blanchard & Kahn conditions are not satisfied: no stable equilibrium")
    } else if (nba < nsfwrd) {
        warning("Blanchard & Kahn conditions are not satisfied: indeterminacy")
    }

    return (eigval)
}
