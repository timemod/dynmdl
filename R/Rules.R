# An R6 class with information about Decision and Transition Rules,
# used for stochastic simulations
#' @importFrom R6 R6Class
Rules <- R6Class("Rules",
    private = list(
        reorder_jacobian_columns = NULL,
        innovations_idx = NULL,
        index_s = NULL,
        index_m = NULL,
        index_c = NULL,
        index_p = NULL,
        row_indx = NULL,
        index_0m = NULL,
        index_0p = NULL,
        k1 = NULL,
        k2 = NULL,
        state_var = NULL,
        nd = NA_integer_,
        n_current     = NA_integer_,
        index_d       = NULL,
        index_e       = NULL,
        index_d1      = NULL,
        index_d2      = NULL,
        index_e1      = NULL,
        index_e2      = NULL,
        row_indx_de_1 = NULL,
        row_indx_de_2 = NULL,
        cols_b        = NULL
    ),
    public = list(
        order_var = NULL,
        inv_order_var = NULL,
        kstate = NULL,
        eigval = NULL,
        ghx = NULL,
        ghu = NULL,
        gx = NULL,
        Gy = NULL,
        initialize = function(mdl) {
            #
            # set up the administration
            #

            # make local copies of the fields of the mdl object
            npred <- mdl$npred
            nboth <- mdl$nboth
            nfwrd <- mdl$nfwrd
            nstatic <- mdl$nstatic
            ndynamic <- mdl$ndynamic
            nsfwrd <- mdl$nsfwrd
            lead_lag_incidence <- mdl$lead_lag_incidence
            max_lag <- mdl$max_endo_lag
            max_lead <- mdl$max_endo_lead
            klen <- max_lag + max_lead + 1

            lead_var <- which(lead_lag_incidence[, max_lag + 2] != 0)
            if (max_lag > 0) {
                lag_var <- which(lead_lag_incidence[, 1] != 0)
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
            self$order_var <- c(stat_var, pred_var, both_var, fwrd_var)
            self$inv_order_var <- numeric(mdl$endo_count)
            self$inv_order_var[self$order_var] <- seq_len(mdl$endo_count)

            # building kmask for z state vector in t+1
            if (max_lag > 0) {
                kmask <- numeric(0)
                if (max_lead > 0) {
                    kmask <- lead_lag_incidence[self$order_var, max_lag + 2,
                                                drop = FALSE]
                }
                kmask <- rbind(kmask, lead_lag_incidence[self$order_var, 1,
                                                         drop = FALSE])
            } else {
                if (max_lead == 0) {
                    # in this case lead_lag_incidence has no entry max_lag+2
                    error(paste('Dynare currently does not allow to solve"),
                          "purely static models in a stochastic context.'))
                }
                kmask <- lead_lag_incidence[self$order_var, max_lag + 2,
                                            drop = FALSE]
            }
            i_kmask <- which(kmask != 0)

            # composition of state vector
            # col 1: variable;           col 2: lead/lag in z(t+1);
            # col 3: A cols for t+1 (D); col 4: A cols for t (E)
            self$kstate <- matrix(0, nrow = mdl$endo_count * (klen - 1), ncol = 4)
            self$kstate[, 1] <- rep(seq_len(mdl$endo_count), klen - 1)
            self$kstate[, 2] <- t(kronecker(matrix(klen: 2, ncol = 1),
                                    matrix(1, ncol = mdl$endo_count)))

            kiy <- as.numeric(t(t(lead_lag_incidence[self$order_var, , drop = FALSE])
                                [klen:1, , drop = FALSE]))
            if (max_lead > 0) {
                self$kstate[1 : mdl$endo_count, 3] <- kiy[1 : mdl$endo_count] -
                         nnz(lead_lag_incidence[, max_lag+ 1 ])
                self$kstate[self$kstate[ , 3] < 0, 3] <- 0
                self$kstate[(mdl$endo_count + 1): nrow(self$kstate), 4] <-
                        kiy[(2 * mdl$endo_count + 1) : length(kiy)];
            } else {
                self$kstate[, 4] <- kiy[mdl$endo_count + 1 : length(kiy)]
            }
            self$kstate <- self$kstate[i_kmask, ]

            private$nd <- nrow(self$kstate)

            private$k1 <- seq_len(npred + nboth)
            private$k2 <- seq_len(nfwrd + nboth)

            max_lag <- mdl$max_endo_lag

            nz <- nnz(lead_lag_incidence)
            lead_id <- which(lead_lag_incidence[, max_lag + 2] != 0)
            lead_idx <- lead_lag_incidence[lead_id, max_lag + 2]
            if (max_lag) {
                lag_id <- which(mdl$lead_lag_incidence[, 1] != 0)
                lag_idx <- mdl$lead_lag_incidence[lag_id, 1]
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
            private$innovations_idx <- nz + 1:mdl$exo_count
            private$state_var <- c(no_both_lag_id, both_id)

            # indices of the endogenous variables at time t
            private$index_c <- nonzeros(lead_lag_incidence[, max_lag + 1])
            private$n_current <- length(private$index_c)

            private$index_s <- npred + nboth + seq_len(nstatic)
            indexi_0 <- npred + nboth

            npred0 <- nnz(mdl$lead_lag_incidence[no_both_lag_id, max_lag + 1])
            private$index_0m <- indexi_0 + nstatic  + seq_len(npred0)
            nfwrd0 <- nnz(lead_lag_incidence[lead_id, 2])
            private$index_0p <- indexi_0 + nstatic + npred0 + seq_len(nfwrd0)
            private$index_m <- seq_len(npred + nboth)
            private$index_p <- npred + nboth + private$n_current + seq_len(nfwrd + nboth)
            private$row_indx_de_1 <- seq_len(ndynamic)
            private$row_indx_de_2 <- ndynamic + seq_len(nboth)
            private$row_indx <- nstatic + private$row_indx_de_1
            private$index_d <- c(private$index_0m, private$index_p)
            llx <- lead_lag_incidence[self$order_var, , drop = FALSE]
            private$index_d1 <- c(which(llx[nstatic + seq_len(npred), max_lag + 1] != 0),
                           npred + nboth + seq_len(nsfwrd))
            private$index_d2 <- npred + seq_len(nboth)
            private$index_e <- c(private$index_m, private$index_0p);
            private$index_e1 <- c(seq_len(npred + nboth), npred + nboth +
                              which(llx[nstatic + npred +
                                seq_len(nsfwrd), max_lag + 1] != 0)
            )
            private$index_e2 <- npred + nboth + seq_len(nboth)

            private$cols_b <- which(lead_lag_incidence[, max_lag + 1, drop = FALSE] != 0,
                            arr.in = TRUE)[, 1]

            vec <- llx[llx != 0]
            private$reorder_jacobian_columns <- c(vec, nz +
                                                      seq_len(mdl$exo_count))
        },
        solve_first_order = function(mdl, only_eigval = FALSE) {

            # calculate the Jacobian
            nper_exo <- mdl$max_exo_lag + mdl$max_exo_lead + 1
            nper_endo <- mdl$max_endo_lag + mdl$max_endo_lead + 1
            exos <- rep(mdl$exos, nper_exo)
            endos <- rep(mdl$endos, nper_endo)
            y <- endos[which(mdl$lead_lag_incidence != 0)]
            it <- mdl$max_exo_lag + 1
            jacobia <- mdl$f_dynamic(y, exo, mdl$params, it, jac = TRUE)
            jacobia <- jacobia[, private$reorder_jacobian_columns, drop = FALSE]

            if (mdl$nstatic) {
                ret <- qr(jacobia[, private$index_s, drop = FALSE])
                Q <- qr.Q(ret, complete = TRUE)
                aa <- t(Q) %*% jacobia
            } else {
                aa <- jacobia
            }

            # compute D and E matrix
            # The linearized model has the form
            # D * (z_t+1,  y_t+1)' = E * (z_t, y_t)'
            # where z_t = y_t-1
            n <- mdl$nboth + mdl$ndynamic
            D <- matrix(0, nrow = n, ncol = n)
            E <- matrix(0, nrow = n, ncol = n)
            D[private$row_indx_de_1, private$index_d1] <- aa[private$row_indx,
                                                             private$index_d]
            D[private$row_indx_de_2, private$index_d2] <- diag(mdl$nboth)
            E[private$row_indx_de_1, private$index_e1] <- -aa[private$row_indx,
                                                              private$index_e]
            E[private$row_indx_de_2, private$index_e2] <- diag(mdl$nboth)
            if (only_eigval) {
                self$eigval <- sort(geigen::geigen(E, D, only.values = TRUE)$values)
            } else {
                qz_result <- geigen::gqz(E, D, sort = 'S')
                self$eigval <- geigen::gevalues(qz_result)
            }

            sdim <- sum(abs(self$eigval) <= 1)
            nba <- private$nd - sdim
            if (nba > mdl$nsfwrd) {
                stop("Blanchard & Kahn conditions are not satisfied: no stable equilibrium")
            } else if (nba < mdl$nsfwrd) {
                stop("Blanchard & Kahn conditions are not satisfied: indeterminacy")
            }

            if (only_eigval) {
                return (self$eigval)
            }

            A <- aa[, private$index_m, drop = FALSE]  # Jacobian matrix for lagged endogeneous variables
            B <- matrix(NA, nrow = nrow(aa), ncol = length(private$index_c))
            B[, private$cols_b] <- aa[, private$index_c, drop = FALSE] # Jacobian matrix for contemporaneous
            # endogenous variables
            C <- aa[, private$index_p, drop = FALSE] # Jacobian matrix for lead endogeneous variables

            indx_stable_root <- 1: (private$nd - mdl$nsfwrd)             # %=> index of stable roots
            indx_explosive_root <- (mdl$npred + mdl$nboth + 1) : private$nd  # => index of explosive roots
            #derivatives with respect to dynamic state variables
            #forward variables

            # TODO: what to do if there are no explosive roots or no stable roots?
            Z <- t(qz_result$Z)
            Z11 <- Z[indx_stable_root,    indx_stable_root, drop = FALSE]
            Z21 <- Z[indx_explosive_root, indx_stable_root, drop = FALSE]
            Z22 <- Z[indx_explosive_root, indx_explosive_root, drop = FALSE]
            self$gx <- -solve(Z22, Z21)
            # TODO: error if Z22 is new singular (see Matlab code)
            hx1 <- t(backsolve(qz_result$T[indx_stable_root, indx_stable_root, drop =
                                                 FALSE], Z11, transpose = TRUE))
            hx2 <- t(solve(Z11, t(qz_result$S[indx_stable_root, indx_stable_root, drop =
                                                  FALSE])))
            hx <- hx1 %*% hx2
            self$ghx <- hx[private$k1, , drop = FALSE]
            if (mdl$nboth + 1 <= length(private$k2)) {
                self$ghx <- rbind(self$ghx,
                                 self$gx[private$k2[(mdl$nboth + 1) :
                                                     length(private$k2)], , drop = FALSE])
            }
            if (mdl$nstatic) {
                B_static <- B[, 1:mdl$nstatic, drop = FALSE]
            } else {
                B_static <- matrix(nrow = nrow(B), ncol = 0)
            }

            # static variables, backward variables, mixed variables and forward variables
            B_pred <- B[, (mdl$nstatic + 1) : (mdl$nstatic + mdl$npred + mdl$nboth)]
            if (mdl$nstatic + mdl$npred + mdl$nboth + 1 <= ncol(B)) {
                B_fyd <- B[, (mdl$nstatic + mdl$npred + mdl$nboth + 1) : ncol(B)]
            } else  {
                B_fyd <- matrix(nrow = nrow(B), ncol = 0)
            }

            if (mdl$nstatic) {
                temp <- - C[1:mdl$nstatic, , drop = FALSE] %*% self$gx %*% hx
                b <- matrix(nrow = nrow(aa), ncol = length(private$index_c))
                b[, private$cols_b] <- aa[ , private$index_c, drop = FALSE]
                b10 <- b[1:mdl$nstatic, 1:mdl$nstatic, drop = FALSE]
                b11 <- b[1:mdl$nstatic, (mdl$nstatic + 1) : ncol(b),
                         drop = FALSE]
                temp[, private$index_m] <- temp[, private$index_m, drop = FALSE] -
                                         A[1:mdl$nstatic, , drop = FALSE]
                temp <- solve(b10, temp - b11 %*% self$ghx)
                self$ghx <- rbind(temp, self$ghx)
            }
            A_ <- cbind(B_static, C %*% self$gx + B_pred, B_fyd)

            if (mdl$exo_count) {
                if (mdl$nstatic) {
                    fu <- t(Q) %*% jacobia[,  private$innovations_idx, drop = FALSE]
                } else {
                    fu <- jacobia[, private$innovations_idx, drop = FALSE]
                }
                self$ghu <- - solve(A_, fu)
            } else {
                self$ghu <- matrix(nrow = 0, ncol = 0)
            }
            self$Gy <- hx
            return (invisible(self))
        }
    )
)
