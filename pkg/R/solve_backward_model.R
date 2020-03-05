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
  
  nper <- nperiod(solve_period)
  nper_data <- nperiod(data_period)
  nendo <- mdldef$endo_count
  start_per <- start_period(solve_period)
  start_per_index <- start_per - start_period(data_period) + 1
  solve_per_sel <- seq(start_per_index, start_per_index + nper - 1)
  var_indices <- get_var_indices_back(mdldef,  start_per_index)
  endo_data_mat <- t(endo_data)
  
  slv_back <- function() {
    itr_tot <- 0
    error   <- FALSE
    message <- "ok"
    for (iper in 1:nper) {
      period_index <- start_per_index + iper - 1
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
                       exo_data = exo_data, period_index = period_index, 
                       debug_eqs = debug_eqs, control = control, ...)
        error <- out$termcd != 1
      } else {
        out <- umf_solve_nl(start, fn = get_back_res, jac = jac_fun, 
                            lags = lags, leads = leads, exo_data = exo_data, 
                            period_index = period_index, 
                            debug_eqs = debug_eqs, control = control, ...)
        error <- !out$solved
      }
      
      if (control$trace) {
        cat("\n")
      }
      
      if (error && !silent) {
        if (grepl("[Ff]unction.*contains non-finite value", out$message)) {
          res <- get_back_res(out$x, lags = lags, leads = leads, 
                              exo_data = exo_data, period_index = period_index, 
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
  
  ret <- slv_back()
  solved <- ret$solved
  result <- ret$x
  message <- ret$message
  
  if (!solved && homotopy) {
    
    if (has_lags <- mdldef$max_endo_lag > 0) {
      maxlag <- mdldef$max_endo_lag
      lag_per_sel <- seq(start_per_index - maxlag, start_per_index - 1)
      lags_steady <- matrix(rep(mdldef$endos, maxlag), ncol = maxlag)
    }
    if (has_leads <- mdldef$max_endo_lead > 0) {
      maxlead <- mdldef$max_endo_lead
      lead_per_sel <- seq(start_per_index + nper, 
                          start_per_index + nper + maxlead - 1)
      leads_steady <- matrix(rep(mdldef$endos, maxlead), ncol = maxlead)
    }
   
    #
    # now prepare steady values of exogenous variables
    #
    fit <- mdldef$fit
    has_exos <- mdldef$exo_count > 0
    
    if (has_exos) {
      np <- nper_data
      if (fit) {
        exo_indices <- c(mdldef$fit_info$orig_exos, mdldef$fit_info$exo_vars)
        exo_data_steady <- matrix(rep(mdldef$exos[exo_indices], each = np), 
                                   nrow = np)
        colnames(exo_data_steady) <- mdldef$exo_names[exo_indices]
      } else {
        exo_data_steady <- matrix(rep(mdldef$exos, each = np), nrow = np)
        colnames(exo_data_steady) <- mdldef$exo_names
      }
    }
    
    if (has_exos) {
      # save the actual values of exogenous variables that we need
      # in the simulation
      if (fit) {
        exo_sim <- exo_data[ , exo_indices, drop = FALSE]
      } else {
        exo_sim <- exo_data
      }
    }
    if (has_lags) {
      lags_sim <- endo_data_mat[ , lag_per_sel, drop = FALSE]
    }
    if (has_leads) {
      leads_sim <- endo_data_mat[ , lag_per_sel, drop = FALSE]
    }

    endo_data_mat[ , solve_per_sel] <- mdldef$endos
    
    solve_fun_homotopy <- function(lambda) {
      
      if (has_exos) {
        if (fit) {
          exo_data[ , exo_indices] <<- exo_sim * lambda + 
                                  exo_data_steady * (1 - lambda)
          
        } else {
          exo_data <<- exo_sim * lambda + exo_data_steady * (1 - lambda)
        }
      }
      if (calc == "internal") {
        internal_dyn_set_exo(model_index, exo_data, nrow(exo_data))
      }
      
      if (has_lags) {
        endo_data_mat[ , lag_per_sel] <<- lags_sim * lambda +
                             lags_steady * (1 - lambda)
      }
      if (has_leads) {
        endo_data_mat[ , lead_per_sel] <<- leads_sim * lambda + 
                                leads_steady * (1 - lambda)
      }
      
      return(slv_back())
    }
    
    update_fun_homotopy <- function(x) {
      endo_data_mat[ , solve_per_sel] <<- x
    }
    
    ret <- solve_homotopy(solve_fun = solve_fun_homotopy, 
                          update_fun = update_fun_homotopy,
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
