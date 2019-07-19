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
  
  vars <- model_info$endo_names
  # names of lagrange multipliers:
  l_vars   <- paste("l", seq_along(vars), sep = "_")
  fit_vars <- paste("fit", vars, sep = "_")
  exo_vars <- paste(vars, "exo", sep = "_")
  sigmas <- paste("sigma", instruments, sep = "_")
  old_instruments <- paste0(instruments, "_old")
  # TODO: check that the intersection of fit_vars, exo_vars,
  # l_vars and sigmas with vars is zero
  
  max_endo_lag <- model_info$dynamic_model$max_endo_lag
  lli <- model_info$dynamic_model$lead_lag_incidence
  
  #
  # get derivatives with respect to endogenous variables and fit instruments
  #
  
  derivatives <- as.data.frame(model_info$dynamic_model$derivatives)
 
  #printobj(derivatives)
  
  # n_endo_deriv is the number of derivatives with respect to endogenous
  # variables and lags/leads of endogenous model variables.
  n_endo_deriv <- max(lli)
  n_endo <- nrow(lli)
 
  # printobj(lli)

  # 
  # TODO: Do some of the manipulations below in the C++ code.
  #
  
  # get derivatives with respect to fit instruments
  instr_index <- match(instruments, model_info$exo_names)
  instr_cols <- instr_index + n_endo_deriv 
  res_deriv <- subset(derivatives, cols %in% instr_cols)
  res_deriv$instr_index <- res_deriv$cols - n_endo_deriv
  res_deriv$cols <- NULL
  colnames(res_deriv)[1] <- "eq"
  res_deriv$expressions <- gsub(pow_pattern, "^", res_deriv$expressions)
  
  #printobj(res_deriv)
  
  # derivatives with respect to endogenous variables
  if (fixed_period) {
    endo_cols_no_lag <- lli[ , max_endo_lag + 1]
    endo_deriv <- subset(derivatives, cols %in% endo_cols_no_lag)
    endo_deriv$endo_index <- match(endo_deriv$cols, lli[ , max_endo_lag + 1])
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
  
  #printobj(endo_deriv)

 
  convert_lags <- function(x) {
    # this function converts lags specified with [] to lags with ().
    # lag zero ([0]is  removed 
    repl_fun <- function(x) {
      i <- as.integer(x)
      if (i == 0) {
        return ("")
      } else {
        return (paste0("(", i, ")"))
      }
    }
    x$expressions <- gsubfn(lag_pattern, repl_fun, x$expressions)
    return(x)
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
  res_deriv <- convert_lags(res_deriv)
  
  #printobj(res_deriv)
  res_deriv <- mult_lagrange(res_deriv, l_vars)
  
  #printobj(res_deriv)
  # sum the expressions of all entries with the same fit instrument
  deriv1 <- aggregate(res_deriv$expressions, 
                      by = list(instr_index = res_deriv$instr_index),
                      FUN = function(x) {paste(x, collapse = " + ")})
  deriv1 <- deriv1$x
  
  
  if (any(deriv1 == "")) {
    problem_instruments <- colnames(res_deriv)[deriv1 == ""]
    stop(paste0("The following fit instruments do not occur in the model",
                " equations: ", paste(problem_instruments, collapse = ", "), 
                "."))
  }
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
    endo_deriv <- convert_lags(endo_deriv)
  } else {
    convert_lags_and_shift <- function(expression, shift) {
      repl <- function(x) {
        i <- as.integer(x) - shift
        if (i == 0) {
          return ("")
        } else {
          return (paste0("(", i, ")"))
        }
      }
      return(gsubfn(lag_pattern, repl, expression))
    }
    shifts <- endo_deriv$endo_lag
    endo_deriv$expressions <- mapply(FUN = convert_lags_and_shift, 
                                     endo_deriv$expressions, shifts)
  }
  #regts::printobj(endo_deriv)
  
  
  # first sum for each equation and endogenous variable over derivatives with respect
  # to different periods
  deriv <- aggregate(endo_deriv$expressions, 
                     by = list(eq = endo_deriv$eq, endo_index = endo_deriv$endo_index),
                     FUN = function(x) {paste(rev(x), collapse = " + ")})
  
  # now sum all equations with derivatives to the same variable
  deriv <- aggregate(deriv$x, by = list(endo_index = deriv$endo_index),
                    FUN = function(x) {paste(x, collapse = " + ")})
  deriv <- deriv$x
  
  endo_equations <- paste0(fit_vars, " * (", vars, " - ", exo_vars, ") + (1 - ", 
                          fit_vars, ") * (", deriv, ")", " = 0;")
  
  #regts::printobj(endo_equations)
  
  initialized_sigmas <- intersect(sigmas, model_info$param_names)
  fit_cond <- list(vars = vars, l_vars = l_vars, fit_vars = fit_vars,
                   exo_vars = exo_vars, instruments = instruments, 
                   old_instruments = old_instruments, sigmas = sigmas,
                   orig_exos = setdiff(model_info$exo_names, instruments),
                   res_equations = res_equations,
                   endo_equations = endo_equations,
                   initialized_sigmas = initialized_sigmas)
  
  return(fit_cond)
}
