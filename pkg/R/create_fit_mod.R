# Constructs a mod file for the fit procedure based on a mod file with
# special %$fit$ block in the mod file.
# The mod file should be allready have been preprocessed by the macro directive
# The function assumes that there is a single fit block, 
# and that both the fit block and the model block are in the
# main mod file. Macro preprocessor directives @#if, @#for etc. should be
# repeated in the fit block
# @param mod_file the filename of the mod file with #FIT tags (already 
#                                                        preprocessed)
# @param fit_mod the name of the file used for the fit procedure
# @param instruments a character vector with the names of the fit instruments
# @return a list with the names of the auxiliary variables
#' @importFrom stringi stri_split_fixed
create_fit_mod <- function(mod_file, fit_mod, instruments, latex_basename, 
                           fixed_period, check_static_fit, latex, 
                           latex_options, silent) {
  
  if (file.exists(fit_mod)) {
    unlink(fit_mod)
  }
  
  # run the Dynare parser to obtain the first order 
  # conditions for the fit procedure
  fit_cond <- get_fit_conditions(mod_file, instruments, latex_basename, 
                                 fixed_period, check_static_fit, latex = latex, 
                                 latex_options = latex_options,
                                 silent = silent)
  
  # finally, create the mod file for the fit procedure
  convert_mod(mod_file, fit_mod, fit_cond = fit_cond, 
              fixed_period = fixed_period, check_static_fit = check_static_fit)
  
  # return information about the fit variables
  with (fit_cond, {
    return(list(fixed_period = fixed_period, orig_endos = vars, 
                orig_exos = orig_exos, 
                l_vars = l_vars, fit_vars = fit_vars,
                exo_vars = exo_vars, instruments = instruments, 
                old_instruments = old_instruments, sigmas = sigmas))
  })
}


convert_mod <- function(input_file, output_file, fit_cond, fixed_period,
                        check_static_fit) {
  
  fit_command <- "%$fit$"
  fit_end     <- "%$endfit$"
  
  input <- file(input_file, "r")
  output <- file(output_file, open = "a")
  
  # initialisation
  fit_block_found <- FALSE
  model_block_found <- FALSE
  in_model <- FALSE
  
  add_empty_string <- function(x) {
    d <- data.frame(x, "")
    return(as.character(t(d)))
  }
  
  has_static_version <- fit_cond$has_static_version
  lag_pattern <- "\\[(-?\\d+)\\]"
  convert_lags <- function(expression) {
    repl_fun <- function(x) {
      i <- as.integer(x) 
      if (i == 0) {
        return ("")
      } else {
        return (paste0("(", i, ")"))
      }
    }
    return(gsubfn(lag_pattern, repl_fun, expression))
  }
  write_first_order_eqs <- function(stat_eqs, dyn_eqs, output) {
    if (!check_static_fit || !any(has_static_version)) {
      eqs <- convert_lags(dyn_eqs)
      eqs <- add_empty_string(eqs)
      writeLines(strwrap(eqs, width = 80, exdent = 4), con = output)
      return(invisible())
    }
    neq <- length(dyn_eqs)
    stat_eqs_conv <- convert_lags(stat_eqs)
    dyn_eqs_conv <- convert_lags(dyn_eqs) 
    for (i in seq_len(neq)) {
      stat_eq <- stat_eqs[i]
      dyn_eq <- dyn_eqs[i]
      dyn_eq_stat <- gsub(lag_pattern, "", dyn_eq)
      if (stat_eq == dyn_eq_stat) {
        writeLines(strwrap(dyn_eqs_conv[i], width = 80, exdent = 4), 
                   con = output)
      } else {
        writeLines("[static]", con = output)
        writeLines(strwrap(stat_eqs_conv[i], width = 80, exdent = 4), 
                   con = output)
        writeLines("[dynamic]", con = output)
        writeLines(strwrap(dyn_eqs_conv[i], width = 80, exdent = 4), 
                   con = output)
      }
      writeLines("", con = output)
    } 
    return(invisible())
  }
  
  while (TRUE) {
    line <- readLines(input, n = 1)
    if (length(line) == 0 ) {
      break
    }
    if (!fit_block_found && startsWith(trimws(line, "left"), fit_command)) {
      writeLines(c("",
                   "% Parameters for the standard deviation for the fit procedure:"),
                 con = output)
      default_sigmas <- setdiff(fit_cond$sigmas, fit_cond$initialized_sigmas)
      if (length(default_sigmas) > 0) {
        param_lines <- paste("parameters", paste(default_sigmas,
                                               collapse = " "), ";", "")
        writeLines(strwrap(param_lines, width = 80), con = output)
        # initial values for the sigmas (-1)
        writeLines(paste(default_sigmas, " = -1;", collapse = " "), con = output)
      }
      
      
      line <- readLines(input, n = 1)
      line <- trimws(line)
      while (!startsWith(line, fit_end)) {
        writeLines(gsub("varexo", "var   ", line), con = output)
        line <- readLines(input, n = 1)
        if (length(line) == 0) {
          break
        }
        line <- trimws(line)
      }
      writeLines("", con = output)
      fit_block_found <- TRUE
    } else if (!model_block_found && startsWith(trimws(line, "left"), "model")) {
      in_model <- TRUE
      lambda_lines <- paste("var", 
                            paste(fit_cond$l_vars, collapse = " "), ";", "")
      writeLines(strwrap(lambda_lines, width = 80), con = output)
      fit_lines <- paste("varexo", 
                         paste(fit_cond$fit_vars, collapse = " "), ";", "")
      writeLines(strwrap(fit_lines, width = 80), con = output)
      exo_lines <- paste("varexo", 
                         paste(fit_cond$exo_vars, collapse = " "), ";", "")
      writeLines(strwrap(exo_lines, width = 80), con = output)
      exo_lines <- paste("varexo", 
                         paste(fit_cond$old_instruments, collapse = " "), ";", "")
      writeLines(strwrap(exo_lines, width = 80), con = output)
      writeLines(c("", line, ""), con = output)
      writeLines(c("% Model equations", ""), con = output)
      model_found <- TRUE
    } else if (in_model && endsWith(trimws(line, "right"), "end;")) {
      writeLines(gsub("end;", "", line), con = output)
      writeLines(c("% First order conditions fit instruments:", ""),
                 con = output)
      write_first_order_eqs(fit_cond$stat_fit_eqs$instr_equations,
                            fit_cond$dyn_fit_eqs$instr_equations, output)
      writeLines(c("", "% First order conditions endogenous variables:",
                   ""), con = output)
      write_first_order_eqs(fit_cond$stat_fit_eqs$endo_equations,
                            fit_cond$dyn_fit_eqs$endo_equations, output)
      writeLines("end;", con = output)
      in_model <- FALSE
    } else {
      writeLines(line, con = output)
    }
  }
  close(input)
  close(output)
  return(invisible(NULL))
}
