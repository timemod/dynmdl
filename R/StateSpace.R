#' @importFrom R6 R6Class
StateSpace <- R6Class("StateSpace",
    public = list(
        order_var = NULL,
        inv_order_var = NULL,
        kstate = NULL,
        initialize = function(mdl) {

            npred <- mdl$npred
            nboth <- mdl$nboth
            nfwrd <- mdl$nfwrd
            nstatic <- mdl$nstatic
            ndynamic <- npred + nboth + nfwrd
            nsfwrd <- mdl$nfwrd + nboth

            lead_lag_incidence <- mdl$lead_lag_incidence
            max_lag <- mdl$max_endo_lag
            max_lead <- mdl$max_endo_lead
            klen <- max_lag + max_lead + 1

            lead_var <- which(lead_lag_incidence[, max_lag + 2] != 0)
            if (max_lag > 0) {
                lag_var <- which(mdl$lead_lag_incidence[, 1] != 0)
                stat_var <- setdiff(1:mdl$endo_count, union(lag_var, lead_var))
                both_var <- intersect(lead_var, lag_var)
                pred_var <- setdiff(lag_var, both_var)
                fwrd_var <- setdiff(lead_var, both_var)
            } else {
                pred_var <- numeric(0)
                both_var <- numeric(0)
                stat_var <- setdiff(1:mdl$endo_count, lead_var)
                fwrd_var <- lead_var;
            }
            order_var <- c(stat_var, pred_var, both_var, fwrd_var)
            inv_order_var <- numeric(mdl$endo_count)
            inv_order_var[order_var] <- seq_len(mdl$endo_count)

            # building kmask for z state vector in t+1
            if (max_lag > 0) {
                kmask <- numeric(0)
                if (max_lead > 0) {
                    kmask <- lead_lag_incidence[order_var, max_lag + 2,
                                                drop = FALSE]
                }
                kmask <- cbind(kmask, lead_lag_incidence[order_var, 1,
                                                         drop = FALSE])
            } else {
                if (max_lead == 0) {
                    # in this case lead_lag_incidence has no entry max_lag+2
                    error(paste('Dynare currently does not allow to solve"),
                          "purely static models in a stochastic context.'))
                }
                kmask <- lead_lag_incidence[order_var, max_lag + 2,
                                            drop = FALSE]
            }
            i_kmask <- which(kmask != 0)

            # composition of state vector
            # col 1: variable;           col 2: lead/lag in z(t+1);
            # col 3: A cols for t+1 (D); col 4: A cols for t (E)
            kstate <- matrix(0, nrow = mdl$endo_count * (klen - 1), ncol = 4)
            kstate[, 1] <- rep(seq_len(mdl$endo_count), klen - 1)
            kstate[, 2] <- t(kronecker(matrix(klen: 2, ncol = 1),
                                    matrix(1, ncol = mdl$endo_count)))

            kiy <- as.numeric(t(t(lead_lag_incidence[order_var, , drop = FALSE])
                                [klen:1, , drop = FALSE]))
            if (max_lead > 0) {
                kstate[1 : mdl$endo_count, 3] <- kiy[1 : mdl$endo_count] -
                         nnz(lead_lag_incidence[, max_lag+ 1 ])
                kstate[kstate[ , 3] < 0, 3] <- 0
                kstate[(mdl$endo_count + 1): nrow(kstate), 4] <-
                        kiy[(2 * mdl$endo_count + 1) : length(kiy)];
            } else {
                kstate[, 4] <- kiy[mdl$endo_count + 1 : length(kiy)]
            }
            kstate <- kstate[i_kmask, ]

            self$order_var <- order_var
            self$inv_order_var <- inv_order_var
            self$kstate <- kstate
        }
    )
)
