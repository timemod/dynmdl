nnz <- dynr:::nnz
nonzeros <- dynr:::nonzeros

solve_first_order2 <- function(mdl, solve = TRUE) {

    state_space <- dynr:::StateSpace$new(mdl)
    order_var <- state_space$order_var

    npred <- mdl$npred
    nboth <- mdl$nboth
    nfwrd <- mdl$nfwrd
    nstatic <- mdl$nstatic
    ndynamic <- npred + nboth + nfwrd
    nsfwrd <- nfwrd + nboth

    k1 <- seq_len(npred + nboth)
    k2 <- seq_len(nfwrd + nboth)

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
    jacobia <- mdl$f_dynamic(y, exo, mdl$params, it, jac = TRUE)

    vec <- llx[llx != 0]
    reorder_jacobian_columns <- c(vec, nz + seq_len(mdl$exo_count))
    jacobia <- jacobia[, reorder_jacobian_columns, drop = FALSE]

    if (nstatic) {
        ret <- qr(jacobia[, index_s, drop = FALSE])
        Q <- qr.Q(ret, complete = TRUE)
        aa <- t(Q) %*% jacobia
    } else {
        aa <- jacobia
    }

    cols_b <- which(mdl$lead_lag_incidence[, max_lag + 1, drop = FALSE] != 0,
                    arr.in = TRUE)[, 1]
    A <- aa[, index_m]  # Jacobian matirx for lagged endogeneous variables
    B <- matrix(NA, nrow = nrow(aa), ncol = length(index_c))
    B[, cols_b] <- aa[, index_c] # Jacobian matrix for contemporaneous
                                  # endogenous variables
    C <- aa[, index_p] # Jacobian matrix for lead endogeneous variables.

    n <- nboth + ndynamic
    d <- matrix(0, nrow = n, ncol = n)
    e <- matrix(0, nrow = n, ncol = n)
    d[row_indx_de_1, index_d1] <- aa[row_indx, index_d]
    d[row_indx_de_2, index_d2] <- diag(nboth)
    e[row_indx_de_1, index_e1] <- -aa[row_indx, index_e]
    e[row_indx_de_2, index_e2] <- diag(mdl$nboth)

    cat("d:")
    print(d)
    cat("e:")
    print(e)

    if (solve) {
        qz_result <- geigen::gqz(e, d, sort = 'S')
        eigval <- geigen::gevalues(qz_result)
    } else {
        eigval <- sort(geigen::geigen(e, d, only.values = TRUE)$values)
    }

    sdim <- sum(abs(eigval) <= 1)
    nd <- nrow(state_space$kstate)
    nba <- nd - sdim
    if (nba > nsfwrd) {
        warning("Blanchard & Kahn conditions are not satisfied: no stable equilibrium")
    } else if (nba < nsfwrd) {
        warning("Blanchard & Kahn conditions are not satisfied: indeterminacy")
    }

    if (!solve) {
        return (eigval)
    }
    cat("eigval:")
    print(eigval)

    indx_stable_root <- 1: (nd - nsfwrd)             # %=> index of stable roots
    indx_explosive_root <- (npred + nboth + 1) : nd  # => index of explosive roots
    #derivatives with respect to dynamic state variables
    #forward variables

    # TODO: what to do if there are no explosive roots or no stable roots?

    print(indx_stable_root)
    print(indx_explosive_root)
    cat("qz_result:")
    print(qz_result)
    Z <- t(qz_result$Z)
    Z11 <- Z[indx_stable_root,    indx_stable_root, drop = FALSE]
    Z21 <- Z[indx_explosive_root, indx_stable_root, drop = FALSE]
    Z22 <- Z[indx_explosive_root, indx_explosive_root, drop = FALSE]
    cat("Z21:\n")
    print(Z21)
    cat("Z22:\n")
    print(Z22)
    gx <- -solve(Z22, Z21)
    cat("gx:\n")
    print(gx)
    # TODO: error if Z22 is new singular (see Matlab code)
    hx1 <- t(backsolve(t(qz_result$T[indx_stable_root, indx_stable_root, drop =
                   FALSE]), Z11))
    cat("hx1:")
    print(hx1)
    hx2 <- t(solve(Z11, t(qz_result$S[indx_stable_root, indx_stable_root, drop =
                   FALSE])))
    cat("hx2:")
    print(hx2)
    hx <- hx1 %*% hx2
    cat("hx:")
    print(hx)
    ghx <- hx[k1, , drop = FALSE]
    print(nboth)
    if (nboth + 1 <= length(k2)) {
        ghx <- cbind(ghx, gx[k2[(nboth + 1) : length(k2)] , drop = FALSE])
    }
    cat("ghx:")
    print(ghx)

   if (nstatic > 0) {
      B_static <- B[, 1:nstatic]
   } else {
      B_static <- matrix(nrow = nrow(B), ncol = 0)
   }

  # static variables, backward variables, mixed variables and forward variables
  B_pred <- B[, (nstatic + 1) : (nstatic + npred + nboth)]
  if (nstatic + npred + nboth + 1 <= ncol(B)) {
      B_fyd <- B[, (nstatic + npred + nboth + 1) : ncol(B)]
  } else  {
      B_fyd <- matrix(nrow = nrow(B), ncol = 0)
  }
  cat("B_pred:\n") 
  print(B_pred)
  cat("B_fyd:\n") 
  print(B_fyd)

  if (nstatic) {
        temp <- - C[1:nstatic, ] %*% gx %*% hx
        b <- matrix(nrow = nrow(aa), ncol = length(index_c))
        b[, cols_b] <- aa[, index_c]
        b10 <- b[1:nstatic, 1:nstatic]
        b11 <- b[1:nstatic, (nstatic + 1) : ncol(b)]
        temp[, index_m] <- temp[, index_m] - A[1:nstatic, ]
        temp <- solve(b10, temp - b11 %*% ghx)
        ghx <- rbind(temp, ghx)
  }
  cat("ghx=\n")
  print(ghx)

  A_ <- cbind(B_static, C %*% gx + B_pred, B_fyd)
  cat("A_:\n")
  print(A_);

  if (mdl$exo_count) {
      if (nstatic) {
          fu <- t(Q) %*% jacobia[,  innovations_idx, drop = FALSE]
      } else {
          fu <- jacobia[, innovations_idx, drop = FALSE]
      }
      ghu <- - solve(A_, fu)
  } else {
      ghu <- matrix(nrow = 0, ncol = 0)
  }
  cat("ghu:\n")
  print(ghu)
}
