# Solve backwards model by treating the lags as exogenous.
#' @importFrom nleqslv nleqslv
#' @importFrom umfpackr umf_solve_nl
#' @importFrom methods as
solve_backward_model <- function(model_index, mdldef, calc, solve_period, 
                                 data_period, endo_data, exo_data, f_dynamic, 
                                 get_back_jac, control, solver, 
                                 start_option, debug_eqs, homotopy, 
                                 silent, backrep, ...) {
  
  if (calc == "internal") {
    f <- function(x, lags, leads, period_index, debug_eqs) {
      return(get_res_back_dyn(model_index, x, lags, leads, period_index, 
                              debug_eqs))
    }
  } else {
    f <- function(x, lags, leads, period_index, debug_eqs) {
      return(f_dynamic(c(lags, x, leads), exo_data, mdldef$params, period_index))
    }
  }
  
  if (solver == "nleqslv") {
    jac_fun <- function(x, lags, leads, period_index, debug_eqs) {
      return(as(get_back_jac(x, lags, leads, period_index, debug_eqs), 
                "matrix"))
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
  
  if (homotopy) {
    endo_data_mat_before <- endo_data_mat[ , solve_per_sel, drop = FALSE]
  }
  
  slv_back <- function() {
    itr_tot <- 0
    error   <- FALSE
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
        out <- nleqslv(start, fn = f, jac = jac_fun, method = "Newton",
                       lags = lags, leads = leads, period_index = period_index, 
                       debug_eqs = debug_eqs, control = control, ...)
        error <- out$termcd != 1
      } else {
        out <- umf_solve_nl(start, fn = f, jac = jac_fun, lags = lags,
                            leads = leads, period_index = period_index, 
                            debug_eqs = debug_eqs, control = control, ...)
        error <- !out$solved
      }
      
      if (control$trace) {
        cat("\n")
      }
      
      if (error && !silent) {
        if (grepl("[Ff]unction.*contains non-finite value", out$message)) {
          res <- f(out$x, lags = lags, leads = leads, 
                   period_index = period_index, debug_eqs = FALSE)
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
      endo_data_mat[curvar_indices] <<- out$x
      
      if (start_option == "previous") start <- out$x
      
      itr_tot <- itr_tot + out$iter
      
      if (error) {
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
    
    return(solved = !error)
  }
  
  solved <- slv_back()
  
  result <- endo_data_mat[ , solve_per_sel, drop = FALSE]
  
  if (!solved && homotopy) {
    
    if (!silent) {
      cat_header <- function(txt) {
        pre <- paste(rep("+", 10), collapse = "")
        post <- paste(rep("+", 80 - 10 - nchar(txt) - 2), collapse = "")
        cat(paste0("\n", pre, " ", txt, " ", post, "\n\n"))
        return()
      }
      cat("\n")
      cat_header("HOMOTOPY")
    }
    
    # create steady endo data. Note: timeseries are stored rowwise
    endo_data_mat_steady <- matrix(rep(mdldef$endos, nper), ncol = nper)
    
    #
    # TODO: do something with lags and leads:
    # lead indiced in endo_data etc.
    #
    
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
        steady_exo_names <- mdldef$exo_names[exo_indices]
      } else {
        exo_data_steady <- matrix(rep(mdldef$exos, each = np), nrow = np)
        steady_exo_names <- mdldef$exo_names
      }
      exo_data_steady <- regts(exo_data_steady, names = steady_exo_names, 
                               period = get_period_range(exo_data))
    }
    
    if (has_exos) {
      # save the actual values of exogenous variables that we need
      # in the simulation
      if (!fit) {
        exo_sim <- exo_data
      } else {
        exo_sim <- exo_data[ , exo_indices, drop = FALSE]
      }
    }

    if (isTRUE(all.equal(endo_data_mat_before, endo_data_mat_steady, 
                         check.attributes = FALSE, tolerance = 1e-4))) {
      # if the original values of the endogenous variables are equal to
      # the steady state values, then the initial homotopy step is 0.5.
      # Otherwise we use a step of 1. Just setting all endogenous variables
      # equal to the steady state value often helps.
      step <- 0.5
    } else {
      # just try to set the endogenous variables in the simiulation
      # period equal to the steady state valuesm keeping the exogenous variables
      # at the original values.
      step <- 1
    }
    
    endo_data_mat[ , solve_per_sel] <- endo_data_mat_steady

    LAMBDA_MIN <- 0.1
    lambda_prev <- 0
    iteration <- 0
    success_counter <- 0
    homotopy_solved <- FALSE
    
    while (TRUE) {
      if (step < LAMBDA_MIN) {
        # minimum homotopy step size of 0.1 seems reasonable
        if (!silent) {
          cat_header(sprintf("HOMOTOPY FAILED (step < %g, final lambda = %g)", 
                             LAMBDA_MIN, lambda))
        }
        break
      }
      iteration <- iteration + 1
      lambda <- lambda_prev + step
      if (lambda >= 1) {
        # make sure that lambda does not exceed the target
        lambda <- 1
        step <- lambda - lambda_prev
      }
      if (!silent) {
        if (iteration > 1) {
          if (control$trace) {
            cat("\n\n")
          } else {
            cat("\n")
          }
        }
        cat(sprintf("-------> HOMOTOPY iteration = %d, lambda = %g <------\n\n",
                    iteration, lambda))
      }
      if (has_exos) {
        if (fit) {
          exo_data[ , exo_indices] <- exo_sim * lambda + 
                             exo_data_steady * (1 - lambda)
    
        } else {
          exo_data <- exo_sim * lambda + exo_data_steady * (1 - lambda)
        }
      }
      
      # if (has_lags) lags <- lags_sim * lambda + 
      #   lags_steady * (1 - lambda)
      # 
      # if (has_leads) leads <- leads_sim * lambda + 
      #   leads_steady * (1 - lambda)
      
      if (calc == "internal") {
        internal_dyn_set_exo(model_index, exo_data, nrow(exo_data))
      }
      
      back_solved <- slv_back()
 
      if (back_solved) {
        if (lambda == 1) {
          if (!silent) {
            cat_header(sprintf("HOMOTOPY SUCCESFUL after %d iterations", 
                               iteration))
          }
          result <- endo_data_mat[ , solve_per_sel, drop = FALSE]
          homotopy_solved <- TRUE
          break
        }
        lambda_prev <- lambda
        succes_counter <- success_counter + 1
        if (success_counter >= 3) {
          step <- step * 2
          success_counter <- 0
        }
      } else {
        # failure, step back
        success_counter <- 0
        step <- step / 2
      }
    }
    
    solved <- homotopy_solved
    # end of homotopy approach
  }
    
  return(list(solved = solved, x = as.numeric(result)))
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
