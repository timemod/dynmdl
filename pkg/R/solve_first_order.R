# construct the solution of the linear state space model.
# also computes the eigenvalues.
#' @importFrom regts printobj
solve_first_order <- function(ss, calc, mdldef, jac_dynamic, 
                              check_only = FALSE, debug = FALSE, debug_eqs) {
  
  lead_lag_incidence <- mdldef$lead_lag_incidence
  static_exos <- mdldef$exos
  static_endos <- mdldef$endos
  params <- mdldef$params
  nendo <- mdldef$endo_count
  njac_cols <- length(which(mdldef$lead_lag_incidence != 0)) + mdldef$exo_count
  
  # max_lag and max_lead computed in the following way are not the same
  # as mdldef$max_lag or mdldef$max_lead when max_laglead_1 = TRUE:
  max_lag <- -as.integer(colnames(lead_lag_incidence)[1])
  max_lead <- as.integer(colnames(lead_lag_incidence)[ncol(lead_lag_incidence)])
  
  # solve_first_order does not works for endogenous
  # lags or leads > 1. For perturbation approaches, Dynare substitutes
  # these lags and leads by creating auxiliary variables and
  # equations. dynmdl does not do that.
  if (max_lag > 1 || max_lead > 1) {
    stop(paste("Function solve_first_order does not work for models",
               "with max_lag > 1 or max_lead > 1.\n",
               "Tip: call function dyn_mdl with option max_laglead_1 = TRUE."))
  }
  
  
  if (is.null(ss)) {
    ss <- init_state_space(length(static_exos), lead_lag_incidence, debug)
  }

  #
  # calculate the Jacobian
  #
  nper <- max_lag + max_lead + 1
  endos <- rep(static_endos, nper)
  y <- endos[which(lead_lag_incidence != 0)]
  
  it <- mdldef$max_exo_lag + 1 # time index for exogenous variables
  if (calc == "internal") {
    # exogenous variables are prepared in DynMdl method prepare_dynamic_model
    jacobia <- get_jac_dyn(mdldef$model_index, y, it, debug_eqs)
  } else {
    nper_exo <- mdldef$max_exo_lag + mdldef$max_exo_lead + 1 
    exos <- matrix(rep(static_exos, each = nper_exo), nrow = nper_exo)
    jacobia <- jac_dynamic(y, exos, params, it)
  }
  jacobia <- sparseMatrix(i = jacobia$rows, j = jacobia$cols,
                          x = jacobia$values, dims = c(nendo, njac_cols))
  jacobia <- as(jacobia, "matrix")
  jacobia <- jacobia[, ss$reorder_jacobian_columns, drop = FALSE]
  
  if (ss$nstatic) {
    ret <- qr(jacobia[, ss$index_s, drop = FALSE])
    Q <- qr.Q(ret, complete = TRUE)
    aa <- t(Q) %*% jacobia
  } else {
    aa <- jacobia
  }
  if (debug) {
    printobj(jacobia)
    printobj(aa)
  }
  
  # compute D and E matrix
  # The linearized model has the form
  # D * (z_t+1,  y_t+1)' = E * (z_t, y_t)'
  # where z_t = y_t-1
  n <- ss$nboth + ss$ndynamic
  D <- matrix(0, nrow = n, ncol = n)
  E <- matrix(0, nrow = n, ncol = n)
  D[ss$row_indx_de_1, ss$index_d1] <- aa[ss$row_indx, ss$index_d]
  D[ss$row_indx_de_2, ss$index_d2] <- diag(ss$nboth)
  E[ss$row_indx_de_1, ss$index_e1] <- -aa[ss$row_indx, ss$index_e]
  E[ss$row_indx_de_2, ss$index_e2] <- diag(ss$nboth)
  if (check_only) {
    ss$eigval <- geigen::geigen(E, D, only.values = TRUE)$values
  } else {
    qz_result <- geigen::gqz(E, D, sort = 'S')
    ss$eigval <- geigen::gevalues(qz_result)
  }
  
  ss$eigval <- order_eigval(ss$eigval)

  if (debug) {
    printobj(D)
    printobj(E)
    if (!check_only) printobj(qz_result)
  }
  
  sdim <- sum(abs(ss$eigval) <= 1)
  nba <- ss$nd - sdim
  
  if (check_only) {
    cat("EIGENVALUES:\n")
    cat(sprintf("%16s%16s%16s\n", "Modulus", "Real", "Imaginary"))
    for (eigv in ss$eigval) {
      cat(sprintf("%16g%16g%16g\n", Mod(eigv), Re(eigv), Im(eigv)))
    }
    cat("\n")
    cat(sprintf("\nThere are %d eigenvalue(s) larger than 1 in modulus\n", nba))
    cat(sprintf("for %d forward-looking variable(s)\n", ss$nsfwrd))
    
    return(ss)
  }
  
  if (nba > ss$nsfwrd) {
    stop("Blanchard & Kahn conditions are not satisfied: no stable equilibrium")
  } else if (nba < ss$nsfwrd) {
    stop("Blanchard & Kahn conditions are not satisfied: indeterminacy")
  }
  
 
  
  A <- aa[, ss$index_m, drop = FALSE]  # Jacobian matrix for lagged endogeneous variables
  B <- matrix(NA, nrow = nrow(aa), ncol = length(ss$index_c))
  B[, ss$cols_b] <- aa[, ss$index_c, drop = FALSE] # Jacobian matrix for contemporaneous
  # endogenous variables
  C <- aa[, ss$index_p, drop = FALSE] # Jacobian matrix for lead endogeneous variables
  
  nstable <- ss$nd - ss$nsfwrd
  if (nstable <= 0) {
    stop("No stable roots")
  } else {
    indx_stable_root <- seq_len(nstable)     # index of stable roots
  }
  if (ss$nd >= (ss$npred + ss$nboth + 1)) {
    indx_explosive_root <- (ss$npred + ss$nboth + 1) : ss$nd
    # index of explosive roots
  } else {
    stop(paste("No explosive roots. solve_first_order cannot handle this",
               "situation yet."))
  }
  
  Z <- t(qz_result$Z)
  Z11 <- Z[indx_stable_root,    indx_stable_root, drop = FALSE]
  Z21 <- Z[indx_explosive_root, indx_stable_root, drop = FALSE]
  Z22 <- Z[indx_explosive_root, indx_explosive_root, drop = FALSE]
  ss$gx <- -solve(Z22, Z21)
  
  # TODO: error if Z22 is new singular (see Matlab code)
  hx1 <- t(backsolve(qz_result$T[indx_stable_root, indx_stable_root, drop =
                                   FALSE], Z11, transpose = TRUE))
  hx2 <- t(solve(Z11, t(qz_result$S[indx_stable_root, indx_stable_root, drop =
                                      FALSE])))
  hx <- hx1 %*% hx2
  ss$ghx <- hx[ss$k1, , drop = FALSE]
  if (debug) {
    printobj(hx1)
    printobj(hx2)
    printobj(ss$k2)
  }
  if (ss$nboth + 1 <= length(ss$k2)) {
    ss$ghx <- rbind(ss$ghx,
                    ss$gx[ss$k2[(ss$nboth + 1) :
                                  length(ss$k2)], , drop = FALSE])
  }
  if (ss$nstatic) {
    B_static <- B[, 1:ss$nstatic, drop = FALSE]
  } else {
    B_static <- matrix(nrow = nrow(B), ncol = 0)
  }
  
  
  # static variables, backward variables, mixed variables and forward variables
  B_pred <- B[, (ss$nstatic + 1) : (ss$nstatic + ss$npred + ss$nboth)]
  if (ss$nstatic + ss$npred + ss$nboth + 1 <= ncol(B)) {
    B_fyd <- B[, (ss$nstatic + ss$npred + ss$nboth + 1) : ncol(B)]
  } else  {
    B_fyd <- matrix(nrow = nrow(B), ncol = 0)
  }
  
  if (ss$nstatic) {
    temp <- - C[1:ss$nstatic, , drop = FALSE] %*% ss$gx %*% hx
    b <- matrix(nrow = nrow(aa), ncol = length(ss$index_c))
    b[, ss$cols_b] <- aa[ , ss$index_c, drop = FALSE]
    b10 <- b[1:ss$nstatic, 1:ss$nstatic, drop = FALSE]
    b11 <- b[1:ss$nstatic, (ss$nstatic + 1) : ncol(b),
             drop = FALSE]
    temp[, ss$index_m] <- temp[, ss$index_m, drop = FALSE] -
      A[1:ss$nstatic, , drop = FALSE]
    temp <- solve(b10, temp - b11 %*% ss$ghx)
    ss$ghx <- rbind(temp, ss$ghx)
  }
  A_ <- cbind(B_static, C %*% ss$gx + B_pred, B_fyd)
  
  if (length(static_exos) > 0) {
    if (ss$nstatic) {
      fu <- t(Q) %*% jacobia[,  ss$innovations_idx, drop = FALSE]
    } else {
      fu <- jacobia[, ss$innovations_idx, drop = FALSE]
    }
    ss$ghu <- - solve(A_, fu)
  } else {
    ss$ghu <- matrix(nrow = 0, ncol = 0)
  }
  ss$Gy <- hx
  return (ss)
}
