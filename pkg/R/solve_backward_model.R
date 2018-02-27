# Solve a non-linear backwards system using package nleqslv
# param x: initial guess
# param fun: a function of x returning a vector of functional values
# param jacfun: a function that returns the Jacobian of the systems of equations,
#               typically as one of the  matrix classes of package Matrix
#' @importFrom nleqslv nleqslv
#' @importFrom umfpackr umf_solve_nl
#' @importFrom methods as
solve_backward_model <- function(model_index, calc, model_period, period_shift, 
                                 endo_data, exo_data,  params, 
                                 lead_lag_incidence, njac_cols, f_dynamic, 
                                 jac_dynamic, control, solver) {
  
  start_per <- start_period(model_period)
  nper <- nperiod(model_period)
  nendo <- ncol(endo_data)
  
  data <- t(endo_data)
  
  jac_cols <- lead_lag_incidence[, "0"]
  
  max_lag <- abs(as.numeric(colnames(lead_lag_incidence)[1]))
  lag_indices <- which(lead_lag_incidence[, 1 : max_lag] != 0) + 
                    (period_shift - max_lag) * nendo
  
  is_internal = calc == "internal"
  
  if (is_internal) {
    f <- function(x, lags, iper) {
      return(get_res_back_dyn(model_index, x, lags, iper, period_shift))
    }
  } else {
    f <- function(x, lags, iper) {
      return(f_dynamic(c(lags, x), exo_data, params, iper + period_shift))
    }
  }
  
  jac_sparse  <- function(x, lags, iper) {
      # note: x and params set by prepare_dynamic_model
      if (is_internal) {
        mat_info <- get_jac_back_dyn(model_index, x, lags, jac_cols, iper, 
                                     period_shift)
      } else {
        mat_info <- get_jac_backwards(x, lags, jac_cols, exo_data, 
                                      params, jac_dynamic, iper, period_shift)
      }
      ret <- sparseMatrix(i = mat_info$rows, j = mat_info$cols,
                          x = mat_info$values, 
                          dims = as.integer(rep(nendo, 2)))
      return(ret)
  }

  if (solver == "nleqslv") {
    jac_fun <- function(x, lags, iper) {
      return(as(jac_sparse(x, lags, iper), "matrix"))
    }
  } else {
    jac_fun <- jac_sparse
  }
  
  itr_tot <- 0
  t_f     <- 0
  t_jac   <- 0
  t_lu    <- 0
  t_solve <- 0
  
  if (!control$silent) {
    cat(sprintf("\nSolving backwards model for period %s\n",
                as.character(model_period)))
  }
  
  error <- FALSE
  
  control_ <- control
  if (solver == "nleqslv") {
    control_$silent <- NULL
  } else {
    control_["silent"] <- TRUE
  }
  for (iper in 1:nper) {
    per_txt <- as.character(start_per + (iper - 1))
    lags <- data[lag_indices + (iper - 1) * nendo]
    cur_indices <- (1:nendo) + (iper - 1 + period_shift) * nendo
    start <- data[cur_indices]
    if (solver == "nleqslv") {
      out <- nleqslv(start, fn = f, jac = jac_fun, method = "Newton",
                     lags = lags, iper = iper, control = control_)
      error <- out$termcd != 1
    } else {
      out <- umf_solve_nl(start, fn = f, jac = jac_fun, lags = lags,
                          iper = iper, control = control_)
      error <- !out$solved
      t_f     <- t_f     + out$t_f
      t_jac   <- t_jac   + out$t_jac
      t_lu    <- t_lu    + out$t_lu
      t_solve <- t_solve + out$t_solve
    }
    if (!control$silent) {
      if (error) {
        cat(sprintf("No convergence for %s in %d iterations\n", 
                    per_txt, out$iter))
      } else {
        cat(sprintf("Convergence for %s in %d iterations\n", per_txt,
                    out$iter))
      }
    }
    
    # update data
    data[cur_indices] <- out$x
    
    itr_tot <- itr_tot + out$iter
    
    if (error) {
      break
    }

  }
  
  if (!control$silent) {
    cat(sprintf("Total number of iterations: %d\n", itr_tot))
    cat(sprintf("Total time function eval. : %g\n", t_f))
    cat(sprintf("Total time Jacobian.      : %g\n", t_jac))
    cat(sprintf("Total time LU fact.       : %g\n", t_lu))
    cat(sprintf("Total time solve          : %g\n", t_solve))
  }

  # update data
  x <- data[(1 : (nper * nendo)) + period_shift * nendo]
  return (list(solved = !error, itr_tot = itr_tot, x = x,
               t_f = t_f, t_jac = t_jac, t_lu = t_lu, t_jac = t_jac))
}
