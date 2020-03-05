# Solve backwards model by treating the lags as exogenous.
#' @importFrom nleqslv nleqslv
#' @importFrom umfpackr umf_solve_nl
#' @importFrom methods as
solve_backward_model <- function(model_index, mdldef, calc, solve_period, 
                                 data_period, endo_data, exo_data,
                                 get_back_res, get_back_jac, control, solver, 
                                 start_option, debug_eqs, homotopy, 
                                 silent, backrep, ...) {
  if (solver == "nleqslv") {
    jac_fun  <- function(...) {
      return(as(get_back_jac(...), "matrix"))
    }
  } else {
    jac_fun <- get_back_jac
  }

  if (!silent) {
    cat(sprintf("\nSolving backwards for period %s\n",
                as.character(solve_period)))
  }

  maxlag <- mdldef$max_endo_lag
  maxlead <- mdldef$max_endo_lead
  
  endo_data_period <-  period_range(start_period(solve_period) - maxlag,
                                    end_period(solve_period) + maxlead)
  endo_data_mat <- t(endo_data[endo_data_period])
  
  nper <- nperiod(solve_period)
  nper_data <- nperiod(endo_data_period)
  start_per <- start_period(solve_period)
  start_per_index <- maxlag + 1
  start_per_index_exo <- start_period(solve_period) - 
                          start_period(data_period) + 1
  solve_per_sel <- seq(start_per_index, nper_data - maxlead)
  var_indices <- get_var_indices_back(mdldef, start_per_index)
  
  nendo <- mdldef$endo_count
 
  slv_back <- function(endo_data_mat, exo_data) {
    # TODO: pass other arguments to slv_back
    itr_tot <- 0
    error   <- FALSE
    message <- "ok"
    for (iper in 1:nper) {
      period_index_exo <- start_per_index_exo + iper - 1
      per_txt <- as.character(start_per + (iper - 1))
      shift <- (iper - 1) * nendo
      lags <- endo_data_mat[var_indices$lags + shift]
      leads <- endo_data_mat[var_indices$leads + shift]
      curvar_indices <- var_indices$curvars + shift
      if (start_option == "current" || iper == 1) {
        start <- endo_data_mat[curvar_indices]
      }
      if (solver == "nleqslv") {
        out <- nleqslv(start, fn = get_back_res, jac = jac_fun, 
                       method = "Newton", lags = lags, leads = leads, 
                       exo_data = exo_data, period_index = period_index_exo, 
                       debug_eqs = debug_eqs, control = control, ...)
        error <- out$termcd != 1
      } else {
        out <- umf_solve_nl(start, fn = get_back_res, jac = jac_fun, 
                            lags = lags, leads = leads, exo_data = exo_data, 
                            period_index = period_index_exo, 
                            debug_eqs = debug_eqs, control = control, ...)
        error <- !out$solved
      }
      
      if (control$trace) {
        cat("\n")
      }
      
      if (error && !silent) {
        if (grepl("[Ff]unction.*contains non-finite value", out$message)) {
          res <- get_back_res(out$x, lags = lags, leads = leads, 
                              exo_data = exo_data, 
                              period_index = period_index_exo, 
                              debug_eqs = FALSE)
          names(res) <- paste("eq", seq_along(res))
          res <- res[!is.finite(res)]
          cat(sprintf(paste("Non-finite values in residuals in period %s",
                            "for the following equations:\n"), per_txt))
          n_max <- 50
          n_res <- length(res)
          print(res[1:min(n_res, n_max)])
          if (n_res > n_max) cat("[ -- omitted", n_res - n_max,
                                 "equations -- ]\n")
          cat("\n")
        } else {
          cat(paste0(sprintf("Error solving model in period %s:\n", per_txt),
                     out$message))
        }
      }
      
      if (!silent && !error && backrep == "period") {
        cat(sprintf("Convergence for %s in %d iterations\n", per_txt,
                    out$iter))
      }
      
      # update data
      endo_data_mat[curvar_indices] <- out$x
      
      if (start_option == "previous") start <- out$x
      
      itr_tot <- itr_tot + out$iter
      
      if (error) {
        message <- out$message
        break
      }
    }
    
    if (!silent && backrep == "total") {
      if (error) {
        cat(sprintf(paste("Backwards solve failed at period %s.",
                          "Total number of iterations: %d.\n"),
                    per_txt, itr_tot))
      } else {
        cat(sprintf(paste("Backwards solve succesfull. Total number of",
                          "iterations: %d.\n"), itr_tot))
      }
    }
    
    return(list(solved = !error, message = message,
                x = endo_data_mat[ , solve_per_sel, drop = FALSE]))
  }
  
  ret <- slv_back(endo_data_mat, exo_data)
  solved <- ret$solved
  result <- ret$x
  message <- ret$message
  
  if (!solved && homotopy) {
    
    ret <- solve_homotopy_back(endo_data_mat, exo_data, solve_fun = slv_back,
                               nper = nper, 
                               start_per_index_exo = start_per_index_exo, 
                               mdldef = mdldef, calc = calc,
                               model_index = model_index,
                               silent = silent,
                               trace = control$trace)
    
    if (ret$solved) {
      solved <- TRUE
      message <- "ok"
      result <- ret$solution
    }
  }
    
  return(list(solved = solved, message = message, x = as.numeric(result)))
}

# Returns the indices of the lags, leads and current variables in t(endo_data)
# for a specific period. Used to solve the model backwards,
# and in method get_back_jacob.
#
# INPUT:
#  mdldef       : a list with the model definitions as used in the DynMdl object.
#  period_index : the period index relative to the start of the data period.
#                 Thus a period_index of 1 corresponds to the first period
#                 in the data period
# RETURN:
#   a list with the indices of the lags, leads and current variables

get_var_indices_back <- function(mdldef, period_index) {
  
  nendo <- mdldef$endo_count
  max_lag <- mdldef$max_endo_lag
  max_lead <- mdldef$max_endo_lead

  lags <- which(mdldef$lead_lag_incidence[ , seq_len(max_lag)] != 0) + 
          (period_index - 1 - max_lag) * nendo
  
  if (max_lead > 0) {
      lead_cols <- seq_len(max_lead) + max_lag + 1
      leads <- which(mdldef$lead_lag_incidence[ , lead_cols] != 0) + 
               period_index * nendo
  } else {
    leads <- integer(0)
  }

  curvars <- seq_len(nendo) + (period_index - 1) * nendo

  return(list(lags = lags, leads = leads, curvars = curvars))
}
