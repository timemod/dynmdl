solve_homotopy <- function(solve_fun, update_fun, silent, trace) {
  
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
   
    ret <- solve_fun(lambda)
    
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
      update_fun(ret$x)
    } else {
      # failure, step back
      success_counter <- 0
      step <- step / 2
    }
  }

  return(list(solved = solved, solution = solution))
}