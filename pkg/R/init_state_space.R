# initializes the state space representation of the linearized model
init_state_space <- function(nexo, lead_lag_incidence, debug = FALSE) {

    ss <- list()

    nendo <- nrow(lead_lag_incidence)

    max_lag <- -as.integer(colnames(lead_lag_incidence)[1])
    max_lead <- as.integer(colnames(lead_lag_incidence)[ncol(lead_lag_incidence)])

    klen <- max_lag + max_lead + 1

    if (max_lead > 0) {
        lead_var <- which(lead_lag_incidence[, max_lag + 2] != 0)
    } else {
        lead_var <- numeric(0)
    }
    if (max_lag > 0) {
        lag_var <- which(lead_lag_incidence[, 1] != 0)
        stat_var <- setdiff(1:nendo, union(lag_var, lead_var))
        both_var <- intersect(lead_var, lag_var)
        pred_var <- setdiff(lag_var, both_var)
        fwrd_var <- setdiff(lead_var, both_var)
    } else {
        pred_var <- numeric(0)
        both_var <- numeric(0)
        stat_var <- setdiff(1:nendo, lead_var)
        fwrd_var <- lead_var
    }
    ss$npred    <- length(pred_var)
    ss$nboth    <- length(both_var)
    ss$nstatic  <- length(stat_var)
    ss$nfwrd    <- length(fwrd_var)
    ss$ndynamic <- ss$npred + ss$nboth + ss$nfwrd
    ss$nsfwrd   <- ss$nfwrd + ss$nboth

    ss$order_var <- c(stat_var, pred_var, both_var, fwrd_var)
    ss$inv_order_var <- numeric(nendo)
    ss$inv_order_var[ss$order_var] <- seq_len(nendo)

    # building kmask for z state vector in t+1
    if (max_lag > 0) {
        kmask <- numeric(0)
        if (max_lead > 0) {
            kmask <- lead_lag_incidence[ss$order_var, max_lag + 2,
                                        drop = FALSE]
        }
        kmask <- rbind(kmask, lead_lag_incidence[ss$order_var, 1,
                                                 drop = FALSE])
    } else {
        if (max_lead == 0) {
            # in this case lead_lag_incidence has no entry max_lag+2
            stop(paste("Dynare currently does not allow to solve",
                       "purely static models in a stochastic context."))
        }
        kmask <- lead_lag_incidence[ss$order_var, max_lag + 2,
                                    drop = FALSE]
    }
    i_kmask <- which(kmask != 0)

    # composition of state vector
    # col 1: variable;           col 2: lead/lag in z(t+1);
    # col 3: A cols for t+1 (D); col 4: A cols for t (E)
    ss$kstate <- matrix(0, nrow = nendo * (klen - 1), ncol = 4)
    ss$kstate[, 1] <- rep(seq_len(nendo), klen - 1)
    ss$kstate[, 2] <- t(kronecker(matrix(klen: 2, ncol = 1),
                                     matrix(1, ncol = nendo)))

    kiy <- as.numeric(t(t(lead_lag_incidence[ss$order_var, , drop = FALSE])
                        [klen:1, , drop = FALSE]))
    if (max_lead > 0) {
        ss$kstate[1 : nendo, 3] <- kiy[1 : nendo] -
            nnz(lead_lag_incidence[, max_lag+ 1 ])
        ss$kstate[ss$kstate[ , 3] < 0, 3] <- 0
        ss$kstate[(nendo + 1): nrow(ss$kstate), 4] <-
            kiy[(2 * nendo + 1) : length(kiy)];
    } else {
        ss$kstate[, 4] <- kiy[(nendo + 1) : length(kiy)]
    }
    ss$kstate <- ss$kstate[i_kmask, ]

    ss$nd <- nrow(ss$kstate)

    ss$k1 <- seq_len(ss$npred + ss$nboth)
    ss$k2 <- seq_len(ss$nfwrd + ss$nboth)

    nz <- nnz(lead_lag_incidence)
    if (max_lead) {
        lead_id <- which(lead_lag_incidence[, max_lag + 2] != 0)
        lead_idx <- lead_lag_incidence[lead_id, max_lag + 2]
    } else {
        lead_id <- numeric(0)
        lead_idx <- numeric(0)
    }
    if (max_lag) {
        lag_id <- which(lead_lag_incidence[, 1] != 0)
        lag_idx <- lead_lag_incidence[lag_id, 1]
    } else {
        lag_id  <- numeric(0)
        lag_idx <- numeric(0)
    }
    both_id <- intersect(lead_id, lag_id)
    if (max_lag) {
        no_both_lag_id <- setdiff(lag_id, both_id)
    } else {
        no_both_lag_id <- lag_id
    }
    ss$innovations_idx <- nz + (1:nexo)
    ss$state_var <- c(no_both_lag_id, both_id)

    # indices of the endogenous variables at time t
    ss$index_c <- nonzeros(lead_lag_incidence[, max_lag + 1])
    ss$n_current <- length(ss$index_c)

    ss$index_s <- ss$npred + ss$nboth + seq_len(ss$nstatic)
    indexi_0 <- ss$npred + ss$nboth
    npred0 <- nnz(lead_lag_incidence[no_both_lag_id, max_lag + 1])
    index_0m <- indexi_0 + ss$nstatic  + seq_len(npred0)
    nfwrd0 <- nnz(lead_lag_incidence[lead_id, 2])
    index_0p <- indexi_0 + ss$nstatic + npred0 + seq_len(nfwrd0)
    ss$index_m <- seq_len(ss$npred + ss$nboth)
    ss$index_p <- ss$npred + ss$nboth + ss$n_current + seq_len(ss$nfwrd + ss$nboth)
    ss$row_indx_de_1 <- seq_len(ss$ndynamic)
    ss$row_indx_de_2 <- ss$ndynamic + seq_len(ss$nboth)
    ss$row_indx <- ss$nstatic + ss$row_indx_de_1
    ss$index_d <- c(index_0m, ss$index_p)
    llx <- lead_lag_incidence[ss$order_var, , drop = FALSE]
    ss$index_d1 <- c(which(llx[ss$nstatic + seq_len(ss$npred), max_lag + 1] != 0),
                        ss$npred + ss$nboth + seq_len(ss$nsfwrd))
    ss$index_d2 <- ss$npred + seq_len(ss$nboth)
    ss$index_e <- c(ss$index_m, index_0p);
    ss$index_e1 <- c(seq_len(ss$npred + ss$nboth), ss$npred + ss$nboth +
                            which(llx[ss$nstatic + ss$npred +
                                          seq_len(ss$nsfwrd), max_lag + 1] != 0)

    )
    ss$index_e2 <- ss$npred + ss$nboth + seq_len(ss$nboth)

    ss$cols_b <- which(lead_lag_incidence[, max_lag + 1, drop = FALSE] != 0,
                          arr.ind = TRUE)[, 1]

    vec <- llx[llx != 0]
    ss$reorder_jacobian_columns <- c(vec, nz + seq_len(nexo))
    return (ss)
}
