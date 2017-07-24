# Constructs a mod file for the fit procedure based on a mod file with
# special %$fit$ block in the mod file.
# The function assumes that there is a single fit block, 
# and that both the fit block and the model block are in the
# main mod file. Macro preprocessor directives @#if, @#for etc. should be
# repeated in the fit block
# @param mod_file the filename of the mod file with #FIT tags
# @param fit_mod the name of the file used for the fit procedure
# @return a list with the names of the auxiliary variables
#' @importFrom stringi stri_split_fixed
create_fit_mod <- function(mod_file, fit_mod, debug = FALSE) {
  
  if (file.exists(fit_mod)) {
    unlink(fit_mod)
  }
  
  if (debug) {
    fit_control_file <- "fit_control_file.mod"
    expanded_file    <- "expanded.mod"
    if (file.exists(fit_control_file)) {
      unlink(fit_control_file)
    }
    if (file.exists(expanded_file)) {
      unlink(expanded_file)
    }
  } else {
    fit_control_file <- tempfile()
    expanded_file    <- tempfile()
  }
  
  create_fit_control_file(mod_file, fit_control_file)
  run_macro(fit_control_file, expanded_file)
  
  # analyse expaned file line to find a list of residuals
  fit_txt <- paste(readLines(expanded_file), collapse = " ")
  fit_txt <- gsub("\\$.+?\\$", "", fit_txt) # remove latex names
  fit_txt <- gsub("\\(.+?\\)", "", fit_txt) # remove long names
  m <- gregexpr("varexo([^;]+)", fit_txt, perl = TRUE)
  ma <- regmatches(fit_txt, m)
  residuals <- strsplit(ma[[1]], split = "\\s+")
  residuals <- setdiff(unlist(residuals), "varexo")
  
  if (!debug) {
    unlink(expanded_file)
  }
  
  # run the Dynare parser to obtain the first order 
  # conditions for the fit procedure
  fit_cond <- get_fit_conditions(mod_file, residuals)
  
  # finally, create the mod file for the fit procedure
  convert_mod(mod_file, fit_mod, fit_cond = fit_cond)
  
  # return information about the fit variables
  with (fit_cond, {
    return (list(orig_endos = vars, orig_exos = orig_exos, 
                 l_vars = l_vars, fit_vars = fit_vars,
                 exo_vars = exo_vars, residuals = residuals, 
                 sigmas = sigmas))
  })
}


create_fit_control_file <- function(mod_file, fit_control_file) {
  
  # read the original model file, and process the fit block.
  fit_command <- "%$fit$"
  fit_end <- "%$endfit$"
  
  input <- file(mod_file, "r")
  output <- file(fit_control_file, open = "a")
  
  while (TRUE) {
    line <- readLines(input, n = 1)
    if (length(line) == 0 ) {
      break
    }
    if (startsWith(trimws(line, "left"), "@#define")) {
      writeLines(line, con = output)
    }
    if (startsWith(trimws(line, "left"), fit_command)) {
      line <- readLines(input, n = 1)
      line <- trimws(line)
      while (!startsWith(line, fit_end)) {
        # remove comment:
        line <- stri_split_fixed(line, "%", n = 2)[[1]][1]
        writeLines(line, con = output)
        line <- readLines(input, n = 1)
        if (length(line) == 0) {
          stop(paste("Error: fit block in model file not", 
                     "closed with %$endfit block"))
          break
        }
        line <- trimws(line)
      }
      break;
    }
  }
  close(input)
  close(output)
  return(invisible(NULL))
}

convert_mod <- function(input_file, output_file, fit_cond) {
  
  fit_command <- "%$fit$"
  fit_end     <- "%$endfit$"
  
  input <- file(input_file, "r")
  output <- file(output_file, open = "a")
  
  # initialisation
  fit_block_found <- FALSE
  model_block_found <- FALSE
  in_model <- FALSE
  
  while (TRUE) {
    line <- readLines(input, n = 1)
    if (length(line) == 0 ) {
      break
    }
    if (!fit_block_found && startsWith(trimws(line, "left"), fit_command)) {
      writeLines(c("",
                   "% Parameters for the standard deviation for the fit procedure:"),
                 con = output)
      param_lines <- paste("parameters", paste(fit_cond$sigmas,
                                               collapse = " "), ";", "")
      writeLines(strwrap(param_lines, width = 80), con = output)
      writeLines("", con = output)
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
      writeLines(c("", line, ""), con = output)
      writeLines(c("% Model equations", ""), con = output)
      model_found <- TRUE
    } else if (in_model && endsWith(trimws(line, "right"), "end;")) {
      writeLines(gsub("end;", "", line), con = output)
      writeLines(c("% First order condition the resisuals:", ""),
                 con = output)
      writeLines(strwrap(fit_cond$res_equations, width = 80),
                 con = output)
      writeLines(c("", "% First order conditions endogenous variables:",
                   ""), con = output)
      writeLines(strwrap(fit_cond$endo_equations, width = 80, exdent = 4),
                 con = output)
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
