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
  
  model_info <- compute_derivatives(mod_file, latex_basename)
  
  # Check if there are lags/leads on instruments. Dynare ignores lags and 
  # leads on exogeneous variables when computing the derivative, therefore
  # the fit procedure cannot handle this situation.
  exo_has_lag <- model_info$dynamic_model$exo_has_lag
  names(exo_has_lag) <- model_info$exo_names
  if (any(exo_has_lag[instruments])) {
    problem_instruments <- instruments[exo_has_lag[instruments]]
    stop(paste0("There are fit instruments with lags or leads: ", 
                paste(problem_instruments, collapse = ", "), 
                "."))
  }
  
  #
  # create list of auxiliarty variables for the fit procedure
  #
  
  endo_names <- model_info$endo_names
  # names of lagrange multipliers:
  l_vars   <- paste("l", seq_along(endo_names), sep = "_")
  fit_vars <- paste("fit", endo_names, sep = "_")
  exo_vars <- paste(endo_names, "exo", sep = "_")
  sigmas <- paste("sigma", instruments, sep = "_")
  old_instruments <- paste0(instruments, "_old")
  initialized_sigmas <- intersect(sigmas, model_info$param_names)
  
  # TODO: check that the intersection of fit_vars, exo_vars,
  # l_vars and sigmas with vars is zero
  
  
  derivatives <- as.data.frame(model_info$dynamic_model$derivatives)

  lli <- model_info$dynamic_model$lead_lag_incidence
  max_endo_lag <- model_info$dynamic_model$max_endo_lag
  
  # n_endo_deriv is the number of derivatives with respect to endogenous
  # variables and lags/leads of endogenous model variables.
  n_endo_deriv <- max(lli)
  n_endo <- nrow(lli)

  # 
  # TODO: Do some of the manipulations below in the C++ code.
  #
  
  # get derivatives with respect to fit instruments
  exo_index_instr <- match(instruments, model_info$exo_names)
  # exo_index_instr if the index of the fit instrument in the list of exogenous 
  # variables
  instr_cols <- exo_index_instr + n_endo_deriv 
  res_deriv <- subset(derivatives, cols %in% instr_cols)
  exo_index <- res_deriv$cols - n_endo_deriv
  res_deriv$instr_index <- match(exo_index, exo_index_instr)
  res_deriv$cols <- NULL
  colnames(res_deriv)[1] <- "eq"
  res_deriv$expressions <- gsub(pow_pattern, "^", res_deriv$expressions)
  
  # derivatives with respect to endogenous variables
  if (fixed_period) {
    endo_cols_no_lag <- lli[ , max_endo_lag + 1]
    endo_deriv <- subset(derivatives, cols %in% endo_cols_no_lag)
    endo_deriv$endo_index <- match(endo_deriv$cols, endo_cols_no_lag)
  } else {
    sel <- lli != 0
    lli_endo_index <- row(lli)[sel]
    lli_lags <- col(lli)[sel] - model_info$dynamic_model$max_endo_lag - 1
    endo_deriv <- subset(derivatives, cols <= n_endo_deriv)
    endo_deriv$endo_index <- lli_endo_index[endo_deriv$cols]
    endo_deriv$endo_lag <- lli_lags[endo_deriv$cols]
  }
  endo_deriv$cols <- NULL
  colnames(endo_deriv)[1] <- "eq"
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
  res_deriv$expressions <- convert_lags(res_deriv$expressions)
  
  res_deriv <- mult_lagrange(res_deriv, l_vars)
  
  # sum the expressions of all entries with the same fit instrument
  deriv1 <- aggregate(res_deriv$expressions, 
                      by = list(instr_index = res_deriv$instr_index),
                      FUN = function(x) {paste(x, collapse = " + ")})
  
  if (nrow(deriv1) < length(instruments)) {
    problem_instruments <- instruments[setdiff(seq_along(instruments), 
                                               deriv1$instr_index)]
    stop(paste0("The following fit instruments do not occur in the model",
                " equations: ", paste(problem_instruments, collapse = ", "), 
                "."))
  }
  
  deriv1 <- deriv1$x
  
  deriv0 <- paste(instruments, paste0(sigmas, "^2"), sep = " / ")
  res_equations <- paste0("(", sigmas, " >= 0) * (", 
                          paste(deriv0, deriv1, sep = " + "), 
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
  deriv <- aggregate(endo_deriv$expressions, 
                     by = list(eq = endo_deriv$eq, endo_index = endo_deriv$endo_index),
                     FUN = function(x) {paste(rev(x), collapse = " + ")})
  
  # now sum all equations with derivatives to the same variable
  deriv <- aggregate(deriv$x, by = list(endo_index = deriv$endo_index),
                    FUN = function(x) {paste(x, collapse = " + ")})
  
  if (nrow(deriv) < n_endo) {
    problem_endos <- endo_names[setdiff(1:n_endo, deriv1$endo_index)]
    stop(paste0("The following endogenous variables do not occur in the model",
                " equations: ", paste(problem_endos, collapse = ", "), 
                "."))
  }
  deriv <- deriv$x
  
  endo_equations <- paste0(fit_vars, " * (", endo_names, " - ", exo_vars, ") + (1 - ", 
                          fit_vars, ") * (", deriv, ")", " = 0;")
  
 

  fit_cond <- list(vars = endo_names, l_vars = l_vars, fit_vars = fit_vars,
                   exo_vars = exo_vars, instruments = instruments, 
                   old_instruments = old_instruments, sigmas = sigmas,
                   orig_exos = setdiff(model_info$exo_names, instruments),
                   res_equations = res_equations,
                   endo_equations = endo_equations,
                   initialized_sigmas = initialized_sigmas)
  
  return(fit_cond)
}
