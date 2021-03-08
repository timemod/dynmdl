# Computes the first order conditions for the fit procedure
#
# @param mod_file the filename of the mod file
# @param instruments a list of instruments used in the fit procedure
#' @importFrom gsubfn gsubfn
#' @importFrom stats aggregate
# @return a list with information about the derivatives
get_fit_conditions <- function(mod_file,  instruments, 
                               fixed_period, check_static_eqs,
                               latex, latex_options, silent) {
  
  # call C++ function compute_derivatives
  call_compute_derivatives <- function() {
    return(compute_derivatives(mod_file, instruments, fixed_period, 
                               check_static_eqs, latex, latex_options))
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
  deriv_dyn <- deriv_info$deriv_dyn
  deriv_stat <- deriv_info$deriv_stat
  
  # Check if there are lags/leads on instruments. Dynare ignores lags and 
  # leads on exogeneous variables when computing the derivatives, therefore
  # the fit procedure cannot handle this situation (actually it would be fine
  # if fixed_period = TRUE, but for the moment we still does not accept 
  # fit instruments with lags and leads).
  instr_has_lag <- deriv_dyn$instr_has_lag
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
  equation_has_static <- deriv_info$equation_has_static
  
  # TODO: check that the intersection of fit_vars, exo_vars,
  # l_vars and sigmas with endo_names and exo_names is zero.
  
  if (check_static_eqs) {
    write_static_eqs <- any(equation_has_static)
  } else {
    write_static_eqs <- FALSE
  }
  dyn_fit_eqs <- get_fit_equations(deriv_dyn$instr_deriv, 
                                   deriv_dyn$endo_deriv,
                                   endo_names, instruments, sigmas, l_vars,
                                   fit_vars, old_instruments, exo_vars,
                                   fixed_period, dynamic = TRUE)

  if (write_static_eqs) {
    if (fixed_period) {
      # For those equations that do no have a separate static and dynamic
      # equation, convert the dynamic derivatives to static derivatives
      # by removing lags and leads. This is not necessary if fixed_period is FALSE,
      # because in that case the static derivatives are the same as the dynamic
      # derivatives (with lags and leads replaced).
      deriv_stat <- convert_deriv_stat(deriv_stat, deriv_dyn, 
                                           equation_has_static)
    }
    stat_fit_eqs <- get_fit_equations(deriv_stat$instr_deriv, 
                                    deriv_stat$endo_deriv,
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
                   write_static_eqs = write_static_eqs,
                   dyn_fit_eqs = dyn_fit_eqs, stat_fit_eqs = stat_fit_eqs,
                   initialized_sigmas = initialized_sigmas)
  
  return(fit_cond)
}


get_fit_equations <- function(instr_deriv, endo_deriv, endo_names, instruments, 
                              sigmas, l_vars, fit_vars, old_instruments, 
                              exo_vars, fixed_period, dynamic) {
  
  lag_pattern <- "\\[(-?\\d+)\\]"
  # 
  # several function definitions
  #
  
  shift_lags <- function(expression, shift) {
    # This function shift lags specified with square brackests (e.g. x[-3]). 
    # The lags are shifted  with -shift, so if shift is -1, the result is
    # x[-2]. If the shifted lag is zero, then the lag [0] is omitted.
    repl_fun <- function(x) {
      i <- as.integer(x) - shift
      if (i == 0) {
        return("")
      } else {
        return(paste0("[", i, "]"))
      }
    }
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
  instr_deriv <- mult_lagrange(instr_deriv, l_vars)
  
  instr_deriv$expressions <- gsub("\\[0\\]", "", instr_deriv$expressions)
  
  # sum the expressions of all entries with the same fit instrument
  deriv_eq <- aggregate(instr_deriv$expressions, 
                        by = list(instr_index = instr_deriv$instr_index),
                        FUN = function(x) {paste(x, collapse = " + ")})
  
  if (nrow(deriv_eq) < length(instruments)) {
    problem_instruments <- instruments[setdiff(seq_along(instruments), 
                                               deriv_eq$instr_index)]
    txt <- if (dynamic) " " else " static "
    stop(paste0("The following fit instruments do not occur in the", txt, 
                "model equations: ", 
                paste(problem_instruments, collapse = ", "), "."))
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
  
  if (dynamic && !fixed_period) {
    endo_deriv$expressions <- mapply(FUN = shift_lags, 
                                     endo_deriv$expressions, 
                                     endo_deriv$endo_lag)
  } else {
    endo_deriv$expressions <- gsub("\\[0\\]", "", endo_deriv$expressions)
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

convert_deriv_stat <- function(deriv_stat, deriv_dyn, equation_has_static) { 
  
  # For those equations that do no have a separate static and dynamic
  # equation, replace the static derivatives with the dynamic derivatives
  # with removed lags/leads. This is needed when fixed_period = TRUE. 
  # This is not necessary if fixed_period is FALSE,
  # because in that case the static derivatives are the same as the dynamic
  # derivatives (with lags and leads replaced).
  
  lag_pattern <- "\\[(-?\\d+)\\]"
  
  convert_deriv_internal <- function(stat, dyn) {
    dyn$endo_lag <- NULL
    dyn$expressions <- gsub(lag_pattern, "", dyn$expressions)
    
    stat <- stat[equation_has_static[stat$eq], , drop = FALSE]
    dyn <- dyn[!equation_has_static[dyn$eq], , drop = FALSE]
    
    deriv <- rbind(dyn, stat)
    deriv <- deriv[order(deriv$eq), , drop = FALSE]
    return(deriv)
  }
  
  deriv_stat$endo_deriv <- convert_deriv_internal(deriv_stat$endo_deriv, 
                                                  deriv_dyn$endo_deriv)
  deriv_stat$instr_deriv <- convert_deriv_internal(deriv_stat$instr_deriv, 
                                                   deriv_dyn$instr_deriv)
  return(deriv_stat)
}
