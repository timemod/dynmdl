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
create_fit_mod <- function(mod_file, preprocessed_mod_file, fit_mod, 
                           instruments, fixed_period, check_static_eqs, 
                           latex, latex_options, silent) {
  
  if (file.exists(fit_mod)) {
    unlink(fit_mod)
  }
  
  # run the Dynare parser to obtain the first order 
  # conditions for the fit procedure
  fit_cond <- get_fit_conditions(mod_file, instruments, fixed_period, 
                                 check_static_eqs, latex = latex, 
                                 latex_options = latex_options,
                                 silent = silent)
  
  # finally, create the mod file for the fit procedure
  convert_mod(preprocessed_mod_file, fit_mod, fit_cond = fit_cond, 
              fixed_period = fixed_period, check_static_eqs = check_static_eqs)
  
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
                        check_static_eqs) {
  
  fit_command <- "%$fit$"
  fit_end     <- "%$endfit$"
  
  # initialisation
  fit_block_found <- FALSE
  model_block_found <- FALSE
  in_model <- FALSE

  write_static_eqs <- fit_cond$write_static_eqs
  
  lag_pattern <- "\\[(-?\\d+)\\]"
  convert_lags <- function(expression) {
    # replace square brackets with normal parentheses
    return(gsub(lag_pattern, "(\\1)", expression))
  }
  write_first_order_eqs <- function(stat_eqs, dyn_eqs, output) {
    # Write first order conditions for the fit instruments or 
    # endogenous variables.
    neq <- length(dyn_eqs)
    if (write_static_eqs) {
      dyn_eqs_stat <- gsub(lag_pattern, "", dyn_eqs)
      write_stat_dyn <- dyn_eqs_stat != stat_eqs
    } else {
      write_stat_dyn <- rep(FALSE, neq)
    }
    dyn_eqs <- convert_lags(dyn_eqs)
    for (i in seq_len(neq)) {
      if (write_stat_dyn[i]) {
        writeLines("[static]", con = output)
        writeLines(strwrap(stat_eqs[i], width = 80, exdent = 4), con = output)
        writeLines("[dynamic]", con = output)
        writeLines(strwrap(dyn_eqs[i], width = 80, exdent = 4), con = output)
      } else {
        writeLines(strwrap(dyn_eqs[i], width = 80, exdent = 4), 
                   con = output)
      }
      writeLines("", con = output)
    } 
    return(invisible())
  }
  
  output <- file(output_file, open = "a")
  encoding <- as.character(readr::guess_encoding(input_file)[1, 1])
  input <- file(input_file, "r", encoding = encoding)
  
  tryCatch({
    while (TRUE) {
      line <- readLines(input, n = 1)
      if (length(line) == 0 ) {
        break
      }
      if (!fit_block_found && startsWith(trimws(line, "left"), fit_command)) {
        writeLines(c(
          "",
          "% Parameters for the standard deviation for the fit procedure:"
          ),  con = output)
        default_sigmas <- setdiff(fit_cond$sigmas, fit_cond$initialized_sigmas)
        if (length(default_sigmas) > 0) {
          param_lines <- paste("parameters", paste(default_sigmas,
                                                   collapse = " "), ";", "")
          writeLines(strwrap(param_lines, width = 80), con = output)
          # initial values for the sigmas (-1)
          writeLines(paste(default_sigmas, " = -1;", collapse = " "), 
                     con = output)
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
      } else if (!model_block_found && startsWith(trimws(line, "left"), 
                                                  "model")) {
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
                           paste(fit_cond$old_instruments, collapse = " "), 
                           ";", "")
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
  }, finally = {
    close(input)
    close(output)
  })
  return(invisible(NULL))
}
