homotopy <- function(endo_data, exo_data, solve_fun, mdldef, calc,
                     model_index, silent, trace, ...) {
 
  #
  # now prepare steady values of exogenous variables
  #
  fit <- mdldef$fit
  has_exos <- mdldef$exo_count > 0
  maxlag <- mdldef$max_endo_lag
  maxlead <- mdldef$max_endo_lead
  
  if (has_exos) {
    nper_exo <- nrow(exo_data)
    if (fit) {
      exo_indices <- c(mdldef$fit_info$orig_exos, mdldef$fit_info$exo_vars)
      exo_data_steady <- matrix(rep(mdldef$exos[exo_indices], each = nper_exo), 
                                nrow = nper_exo)
      #colnames(exo_data_steady) <- mdldef$exo_names[exo_indices]
    } else {
      exo_data_steady <- matrix(rep(mdldef$exos, each = nper_exo), 
                                nrow = nper_exo)
      #colnames(exo_data_steady) <- mdldef$exo_names
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
  if (endo_data$has_lags) {
    lags_sim <- lag_endos(endo_data)
    lags_steady <- matrix(rep(mdldef$endos, maxlag), ncol = maxlag)
  }
  if (endo_data$has_leads) {
    leads_sim <- lead_endos(endo_data)
    leads_steady <- matrix(rep(mdldef$endos, maxlead), ncol = maxlead)
  }
  
  cur_endos(endo_data) <- mdldef$endos
 
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
  
  step <- 0.5
  LAMBDA_MIN <- 0.1
  lambda_prev <- 0
  iteration <- 0
  success_counter <- 0
  solved <- FALSE
  solution <- NULL
  
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
        if (trace) {
          cat("\n\n")
        } else {
          cat("\n")
        }
      }
      cat(sprintf("-------> HOMOTOPY iteration = %d, lambda = %g <------\n\n",
                  iteration, lambda))
    }
    
    #
    # calculate new exogenous variables and lags/leads
    # TODO: create a function for this
    #
    if (has_exos) {
      if (fit) {
        exo_data[ , exo_indices] <- exo_sim * lambda + 
                                  exo_data_steady * (1 - lambda)
        
      } else {
        exo_data <- exo_sim * lambda + exo_data_steady * (1 - lambda)
      }
    }
    if (calc == "internal") {
      internal_dyn_set_exo(model_index, exo_data, nrow(exo_data))
    }
    
    if (endo_data$has_lags) {
      lag_endos(endo_data) <- lags_sim * lambda + lags_steady * (1 - lambda)
    }
    if (endo_data$has_leads) {
      lead_endos(endo_data) <- leads_sim * lambda + leads_steady * (1 - lambda)
    }
   
    ret <- solve_fun(endo_data, exo_data, ...)
    
    if (ret$solved) {
      if (lambda == 1) {
        if (!silent) {
          cat_header(sprintf("HOMOTOPY SUCCESFUL after %d iterations", 
                             iteration))
        }
        solution <- ret$x
        solved <- TRUE
        break
      }
      lambda_prev <- lambda
      succes_counter <- success_counter + 1
      if (success_counter >= 3) {
        step <- step * 2
        success_counter <- 0
      }
      # update endogenous variables with new solution
      cur_endos(endo_data) <- ret$x
      
    } else {
      # failure, step back
      success_counter <- 0
      step <- step / 2
    }
  }

  return(list(solved = solved, solution = solution))
}