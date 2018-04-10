# Solve backwards model by treating the lags as exogenous.
#' @importFrom nleqslv nleqslv
#' @importFrom umfpackr umf_solve_nl
#' @importFrom methods as
solve_backward_model <- function(mdldef, calc, solve_period, data_period, 
                                 endo_data, exo_data, f_dynamic, 
                                 get_back_jac, control, solver, 
                                 start_option, ...) {
  
  if (calc == "internal") {
    f <- function(x, lags, period_index) {
      return(get_res_back_dyn(mdldef$model_index, x, lags, period_index))
    }
  } else {
    f <- function(x, lags, period_index) {
      return(f_dynamic(c(lags, x), exo_data, mdldef$params, period_index))
    }
  }
  
  if (solver == "nleqslv") {
    jac_fun <- function(x, lags, period_index) {
      return(as(get_back_jac(x, lags, period_index), "matrix"))
    }
  } else {
    jac_fun <- get_back_jac
  }

  if (!control$silent) {
    cat(sprintf("\nSolving backwards model for period %s\n",
                as.character(solve_period)))
  }

  control_ <- control
  if (solver == "nleqslv") {
    control_$silent <- NULL
  } else {
    control_["silent"] <- TRUE
  }
  
  nper <- nperiod(solve_period)
  nendo <- mdldef$endo_count
  start_per <- start_period(solve_period)
  start_per_index <- start_per - start_period(data_period) + 1
  var_indices <- get_var_indices_back(mdldef,  start_per_index)
  data <- t(endo_data)
  
  itr_tot <- 0
  t_f     <- 0
  t_jac   <- 0
  t_lu    <- 0
  t_solve <- 0
  error   <- FALSE
  
  for (iper in 1:nper) {
    period_index <- start_per_index + iper - 1
    per_txt <- as.character(start_per + (iper - 1))
    lags <- data[var_indices$lags + (iper - 1) * nendo]
    curvar_indices <- var_indices$curvars + (iper - 1) * nendo
    if (start_option == "current" || iper == 1) {
      start <- data[curvar_indices]
    }
    if (solver == "nleqslv") {
      out <- nleqslv(start, fn = f, jac = jac_fun, method = "Newton",
                     lags = lags, period_index = period_index, 
                     control = control_, ...)
      error <- out$termcd != 1
    } else {
      out <- umf_solve_nl(start, fn = f, jac = jac_fun, lags = lags,
                          period_index = period_index, control = control_,
                          ...)
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
    data[curvar_indices] <- out$x
    
    if (start_option == "previous") start <- out$x
    
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
  x <- data[(1 : (nper * nendo)) + (start_per_index - 1) * nendo]
  return (list(solved = !error, itr_tot = itr_tot, x = x,
               t_f = t_f, t_jac = t_jac, t_lu = t_lu, t_jac = t_jac))
}

# Returns the indices of the lags and current variables in t(endo_data)
# for a specific period. Used for solving the backward model and for DynMdl
# method get_back_jacob.
#
# INPUT:
#  mdldef       : a list with the model definitions as used in the DynMdl object.
#  period_index : the period index relative to the start of the data period.
#                 Thus a period_index of 1 corresponds to the first period
#                 in the data period
# RETURN:
#   a list with the indices of the lags and current variables

get_var_indices_back <- function(mdldef, period_index) {
  
  nendo <- mdldef$endo_count
  max_lag <- mdldef$max_endo_lag
  
  lags <- which(mdldef$lead_lag_incidence[, seq_len(max_lag)] != 0) + 
                           (period_index - 1 - max_lag) * nendo
  
  curvars <- seq_len(nendo) + (period_index - 1) * nendo
  
  return(list(lags = lags, curvars = curvars))
}