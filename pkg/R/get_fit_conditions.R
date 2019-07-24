# Computes the first order conditions for the fit procedure
#
# @param mod_file the filename of the mod file
# @param instruments a list of instruments used in the fit procedure
#' @importFrom gsubfn gsubfn
# @return a list with information about the derivatives
get_fit_conditions <- function(mod_file,  instruments, latex_basename, 
                               fixed_period = TRUE) {
  
  # regular expressions:
  lag_pattern <- "\\[(-?\\d+)\\]"
  pow_pattern <- "\\*\\*" 
  
  model_info <- compute_derivatives(mod_file, latex_basename, instruments, 
                                    fixed_period)
  
  list2env(model_info, envir = environment())
  list2env(dynamic_model, envir = environment())
  
  # Check if there are lags/leads on instruments. Dynare ignores lags and 
  # leads on exogeneous variables when computing the derivative, therefore
  # the fit procedure cannot handle this situation (actually it would be fine
  # if fixed_period = TRUE, but dyn_mdl still does not accept fit targets 
  # with lags and leads)
  if (any(instr_has_lag)) {
    problem_instruments <- instruments[instr_has_lag]
    stop(paste0("Fit instruments with lags or leads are not allowed.\n",
                "The following fit instruments have lags or leads: ",
                paste(problem_instruments, collapse = ", "), 
                "."))
  }
  
  #
  # create list of auxiliarty variables for the fit procedure
  #

  l_vars   <- paste("l", seq_along(endo_names), sep = "_")
  fit_vars <- paste("fit", endo_names, sep = "_")
  exo_vars <- paste(endo_names, "exo", sep = "_")
  sigmas <- paste("sigma", instruments, sep = "_")
  old_instruments <- paste0(instruments, "_old")
  initialized_sigmas <- intersect(sigmas, model_info$param_names)
  
  # TODO: check that the intersection of fit_vars, exo_vars,
  # l_vars and sigmas with vars is zero
  
  # replace ** by ^. Dynare employs the ^ 
  # TODO: it this necessary, why do the equations returned by compute_derivatives
  # return ** instead of ^ (^ is also the R operator for exponentiation)
  instr_deriv$expressions <- gsub(pow_pattern, "^", instr_deriv$expressions)
  endo_deriv$expressions <- gsub(pow_pattern, "^", endo_deriv$expressions)
  
  # 
  # several function definitions
  #

  convert_lags <- function(expressions) {
    # This function converts lags specified with square brackests ([]) 
    # in expressions to lags with (). lag zero ([0]) is  removed 
    repl_fun <- function(x) {
      i <- as.integer(x)
      if (i == 0) {
        return ("")
      } else {
        return (paste0("(", i, ")"))
      }
    }
    return(gsubfn(lag_pattern, repl_fun, expressions))
  }
  
  convert_lags_and_shift <- function(expression, endo_lag) {
    # Similar to function convert_lags, but with shifting of lags in the 
    # expressions. Expression is a derivative  of an equation with respect to 
    # an endogenous variable with lag endo_lag. Thus to obtain the derivative 
    # of the expression with respect to the current endogenous variable, we have 
    # to shift the lag with -endo_lag.
    repl <- function(x) {
      i <- as.integer(x) - endo_lag
      if (i == 0) {
        return ("")
      } else {
        return (paste0("(", i, ")"))
      }
    }
    return(gsubfn(lag_pattern, repl, expression))
  }
  
 
  mult_lagrange <- function(x, l_names) {
    # multiply the derivatives with the lagrange multiplier for each equation
    expr <- paste0("(", x$expressions, ")")
    x$expressions <- paste(l_names[x$eq], expr, sep = " * ")
    return(x)
  }
  
  #
  # derivatives with respect to fit instruments
  #

  # multiply all derivatives with the Lagrange multipliers   
  instr_deriv$expressions <- convert_lags(instr_deriv$expressions)
  
  instr_deriv <- mult_lagrange(instr_deriv, l_vars)
  
  # sum the expressions of all entries with the same fit instrument
  deriv_eq <- aggregate(instr_deriv$expressions, 
                      by = list(instr_index = instr_deriv$instr_index),
                      FUN = function(x) {paste(x, collapse = " + ")})
  
  if (nrow(deriv_eq) < length(instruments)) {
    problem_instruments <- instruments[setdiff(seq_along(instruments), 
                                               deriv_eq$instr_index)]
    stop(paste0("The following fit instruments do not occur in the model",
                " equations: ", paste(problem_instruments, collapse = ", "), 
                "."))
  }
  deriv_eq <- deriv_eq$x
  
  deriv_pnorm <- paste(instruments, paste0(sigmas, "^2"), sep = " / ")
  instr_equations <- paste0("(", sigmas, " >= 0) * (", 
                          paste(deriv_pnorm, deriv_eq, sep = " + "), 
                          ") + (", sigmas, " < 0) * (", instruments, 
                          " - ", old_instruments, ") = 0;")

  #
  # now create first order conditions for the endogenous variables
  #
  
  l_names <- l_vars
  if (!fixed_period) l_names <- paste0(l_vars, "[0]")
  endo_deriv <- mult_lagrange(endo_deriv, l_names)
  
  if (fixed_period) {
    endo_deriv$expressions <- convert_lags(endo_deriv$expressions)
  } else {
    endo_deriv$expressions <- mapply(FUN = convert_lags_and_shift,
                                     endo_deriv$expressions, 
                                     endo_deriv$endo_lag)
  }

  
  
  # first sum for each equation and endogenous variable over derivatives with respect
  # to different periods
  deriv_eq <- aggregate(endo_deriv$expressions, 
                         by = list(eq = endo_deriv$eq, 
                                   endo_index = endo_deriv$endo_index),
                         FUN = function(x) {paste(rev(x), collapse = " + ")})
  
  # now sum all equations with derivatives to the same variable
  deriv_eq <- aggregate(deriv_eq$x, by = list(endo_index = deriv_eq$endo_index),
                    FUN = function(x) {paste(x, collapse = " + ")})
  n_endo <- length(endo_names)
  if (nrow(deriv_eq) < n_endo) {
    problem_endos <- endo_names[setdiff(1:n_endo, deriv_eq$endo_index)]
    stop(paste0("The following endogenous variables do not occur in the model",
                " equations: ", paste(problem_endos, collapse = ", "), 
                "."))
  }
  deriv_eq <- deriv_eq$x

  
  endo_equations <- paste0(fit_vars, " * (", endo_names, " - ", exo_vars, 
                           ") + (1 - ",  fit_vars, ") * (", deriv_eq, ")", 
                           " = 0;")
  
 

  fit_cond <- list(vars = endo_names, l_vars = l_vars, fit_vars = fit_vars,
                   exo_vars = exo_vars, instruments = instruments, 
                   old_instruments = old_instruments, sigmas = sigmas,
                   orig_exos = setdiff(model_info$exo_names, instruments),
                   instr_equations = instr_equations,
                   endo_equations = endo_equations,
                   initialized_sigmas = initialized_sigmas)
  
  return(fit_cond)
}
