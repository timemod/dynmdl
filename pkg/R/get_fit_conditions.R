# Computes the first order conditions for the fit procedure
#
# @param mod_file the filename of the mod file
# @param instruments a list of instruments used in the fit procedure
#' @importFrom gsubfn gsubfn
#' @importFrom stats aggregate
# @return a list with information about the derivatives
get_fit_conditions <- function(mod_file,  instruments, latex_basename, 
                               fixed_period, check_static_fit,
                               latex, latex_options,
                               silent) {
  
  # call C++ function compute_derivatives
  call_compute_derivatives <- function() {
    return(compute_derivatives(mod_file, latex_basename, instruments, 
                               fixed_period, latex, latex_options))
  }
  if (silent) {
    output <- capture.output({
      deriv_info <- call_compute_derivatives()
    })
  } else {
    cat("\n** Parsing the mod file to create fit equations **\n\n")
    deriv_info <- call_compute_derivatives()
    cat("\n** Parsing the fit mod file **\n\n")
  }
  
  endo_names <- deriv_info$endo_names
  exo_names <- deriv_info$exo_names
  param_names <- deriv_info$param_names
  dynamic_deriv <- deriv_info$dynamic_model
  static_deriv <- deriv_info$static_model
  
  # Check if there are lags/leads on instruments. Dynare ignores lags and 
  # leads on exogeneous variables when computing the derivatives, therefore
  # the fit procedure cannot handle this situation (actually it would be fine
  # if fixed_period = TRUE, but for the moment we still does not accept 
  # fit instruments with lags and leads).
  instr_has_lag <- dynamic_deriv$instr_has_lag
  if (any(instr_has_lag)) {
    stop(paste0("Fit instruments with lags or leads are not allowed.\n",
                "The following fit instruments have lags or leads: ",
                paste(instruments[instr_has_lag], collapse = ", "), 
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
  initialized_sigmas <- intersect(sigmas, param_names)
  has_static_version <- deriv_info$has_static_version
  
  # TODO: check that the intersection of fit_vars, exo_vars,
  # l_vars and sigmas with endo_names and exo_names is zero.
  
  dyn_fit_eqs <- get_fit_equations(dynamic_deriv$instr_deriv, 
                                   dynamic_deriv$endo_deriv,
                                   endo_names, instruments, sigmas, l_vars,
                                   fit_vars, old_instruments, exo_vars,
                                   fixed_period, dynamic = TRUE)
  
  if (check_static_fit && any(has_static_version)) {
    if (fixed_period) {
      # For those equations that do no have a separate static and dynamic
      # equation, replace the static equations with the dynamic derivatives.
      static_deriv <- convert_static_deriv(static_deriv, dynamic_deriv, 
                                           has_static_version)
    }
    stat_fit_eqs <- get_fit_equations(static_deriv$instr_deriv, 
                                    static_deriv$endo_deriv,
                                    endo_names, instruments, sigmas, l_vars,
                                    fit_vars, old_instruments, exo_vars,
                                    fixed_period, dynamic = FALSE)
  } else {
    stat_fit_eqs <- NULL
  }
  
  fit_cond <- list(vars = endo_names, l_vars = l_vars, fit_vars = fit_vars,
                   exo_vars = exo_vars, instruments = instruments, 
                   old_instruments = old_instruments, sigmas = sigmas,
                   orig_exos = setdiff(exo_names, instruments),
                   has_static_version = has_static_version,
                   dyn_fit_eqs = dyn_fit_eqs, stat_fit_eqs = stat_fit_eqs,
                   initialized_sigmas = initialized_sigmas)
  
  return(fit_cond)
}


get_fit_equations <- function(instr_deriv, endo_deriv, endo_names, instruments, 
                              sigmas, l_vars, fit_vars, old_instruments, 
                              exo_vars, fixed_period, dynamic) {
  
  # 
  # several function definitions
  #
  
  convert_lags <- function(expression, shift = 0) {
    # This function converts lags specified with square brackests (e.g. x[-3]) 
    # in expressions to lags with () (e.g. x(3)). Lag zero ([0]) is disregarded.
    # If argument shift has been specified, then the lags are shifted 
    # with -shift.
    repl_fun <- function(x) {
      i <- as.integer(x) - shift
      if (i == 0) {
        return ("")
      } else {
        return (paste0("(", i, ")"))
      }
    }
    lag_pattern <- "\\[(-?\\d+)\\]"
    return(gsubfn(lag_pattern, repl_fun, expression))
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
  if (dynamic && !fixed_period) l_names <- paste0(l_vars, "[0]")
  endo_deriv <- mult_lagrange(endo_deriv, l_names)
  
  if (fixed_period || !dynamic) {
    endo_deriv$expressions <- convert_lags(endo_deriv$expressions)
  } else {
    endo_deriv$expressions <- mapply(FUN = convert_lags, 
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
 
  return(list(instr_equations = instr_equations, 
              endo_equations = endo_equations))
}

convert_static_deriv <- function(static_deriv, dynamic_deriv, 
                                 has_static_version) { 
  
  # For those equations that do no have a separate static and dynamic
  # equation, replace the static derivatives with the dynamic derivatives
  # with removed lags/leads.
  # This is needed when the dynamic derivatives are derived with 
  # fixed_period = TRUE 
  
  lag_pattern <- "\\[(-?\\d+)\\]"
  
  convert_internal <- function(stat_deriv, dyn_deriv) {
    dyn_deriv$endo_lag <- NULL
    stat_deriv$expressions <- gsub(lag_pattern, "", stat_deriv$expressions)
    dyn_deriv$expressions <- gsub(lag_pattern, "", dyn_deriv$expressions)
    
    stat_deriv <- stat_deriv[has_static_version[stat_deriv$eq], , drop = FALSE]
    dyn_deriv <- dyn_deriv[!has_static_version[dyn_deriv$eq], , drop = FALSE]
    
    deriv <- rbind(dyn_deriv, stat_deriv)
    deriv <- deriv[order(deriv$eq), , drop = FALSE]
    return(deriv)
  }
  
  static_deriv$endo_deriv <- convert_internal(static_deriv$endo_deriv, 
                                            dynamic_deriv$endo_deriv)
  static_deriv$instr_deriv <- convert_internal(static_deriv$instr_deriv, 
                                             dynamic_deriv$instr_deriv)
  return(static_deriv)
}