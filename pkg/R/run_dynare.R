# Internal function: Run Dynare with Matkab or Octave
#' @importFrom tools file_path_as_absolute
run_dynare  <- function(model_name, mod_file, scratch_dir, 
                        mdl, period, data, rename_aux_vars = TRUE,
                        mod_file_in_scratch_dir = FALSE,
                        tasks, use_octave, dynare_path) {
  
  #
  # create a model object, needed to obtain information about the model.
  #
  if (missing(mdl)) {
    cat("======================================================================\n")
    cat("Parsing model with dynmdl to obtain information about the model\n")
    cat("======================================================================\n")
    mdl <- dyn_mdl(mod_file, period = period, max_laglead_1 = TRUE, 
                   nostrict = TRUE, fit = FALSE)
    if (!missing(data)) {
      mdl$init_data(data = data)
    }
  } else {
    if (!missing(period)) {
      stop(paste("Internal error: in run_dynare only one of arguments mdl and",
                 "period should be specified."))
    }  
    if (!missing(data)) {
      stop(paste("Internal error: in run_dynare only one of arguments mdl and",
                 "exo_data should be specified."))
    }
    period <- mdl$get_period()
  }
  
  #
  # write initval file (only when eiter mdl or data have  been specified)
  #
  use_initval_file <- !missing(data) || !missing(mdl)
  if (use_initval_file) {
    initval_file <- file.path(scratch_dir, paste0(model_name, "_initval.xlsx"))
    write_initval_file_internal(initval_file, mdl$get_mdldef(), period, 
                                mdl$get_endo_data_raw(), mdl$get_exo_data_raw(),
                                rename_aux_vars = rename_aux_vars)
  }
  
  #
  # create main mod file
  #
  main_mod_file <- file.path(scratch_dir, paste0("simul_", model_name, ".mod"))
  
  output <-  file(main_mod_file, open = "w")
  
  if (!mod_file_in_scratch_dir) {
    writeLines(sprintf("@#include \"%s\"", file_path_as_absolute(mod_file)), 
               con = output)
  } else {
    writeLines(sprintf("@#include \"%s.mod\"", model_name), con = output)
  }
  writeLines(sprintf("initval_file(filename = %s_initval);", model_name), 
             con = output)
  writeLines(sprintf("simul(periods = %d, tolf = 1e-8, tolx = 1e-8);", 
                     nperiod(period)),
             con = output)
  close(output)
  
  #
  # create main matlab/octave file
  #
  matlab_file <- file.path(scratch_dir, paste0("run_simul_", model_name, ".m"))
  output <-  file(matlab_file, open = "w")
  writeLines(c("if is_octave", "    pkg load io", "end", ""), con = output)
  if (!missing(dynare_path)) {
    writeLines(paste("addpath", dynare_path), con = output)
  }
  writeLines(sprintf("dynare simul_%s", model_name), con = output)
  writeLines("")
  writeLines(sprintf("dlmwrite('output/simul_%s_endo_names.txt', M_.endo_names, 'delimiter', '')",
                     model_name), con = output)
  writeLines(sprintf("dlmwrite('output/simul_%s_endo.csv', oo_.endo_simul, 'precision', 16)",
                     model_name), con = output)
  
  close(output)
  
  file_name <- system.file("dynare_templates", "is_octave.m", package = "dynmdl")
  file.copy(file_name, file.path(scratch_dir, "is_octave.m"), overwrite = TRUE)
  
  cwd <- getwd()
  setwd(scratch_dir)
  dir.create("output", showWarnings = FALSE)
  
  if (use_octave) {
    
    
    cat("======================================================================\n")
    cat("Running Octave\n")
    cat("======================================================================\n")
    
    system2("octave", args =  sprintf("run_simul_%s.m", model_name))
    
  } else {
    
    cat("======================================================================\n")
    cat("Running Matlab\n")
    cat("======================================================================\n")
    
    system2("matlab", args =  c("-r", sprintf("\"run('run_simul_%s.m');exit;\"", 
                                              model_name)))
    
  }
  
  setwd(cwd)
  
  #
  # read the result
  #
  output_dir <- file.path(scratch_dir, "output")
  endo_name_file <- file.path(output_dir, paste0("simul_", model_name, 
                                                 "_endo_names.txt"))
  endo_data_file <- file.path(output_dir, paste0("simul_", model_name, 
                                                 "_endo.csv"))
  
  endo_names_dynare  <- read.csv(endo_name_file, stringsAsFactors = FALSE,
                                 header = FALSE, sep = "")[[1]]
  
  endo_data <- t(as.matrix(read.csv(endo_data_file, header = FALSE)))
  
  
  # NOTE: mdl$get_max_endo_lag() is always <=1 . mdl$get_max_lag() returns
  # the maximum lag in the original model (without lags/leads > 1 removed)
  max_lag <- mdl$get_max_lag(data = FALSE)
  max_lead <- mdl$get_max_lead(data = FALSE)
  dyn_data_period <- period_range(start_period(period) - max_lag,
                                  end_period(period)   + max_lead)
  
  #
  # endogenous variables: return dynare result for the model period
  #
  if (nperiod(dyn_data_period) != nrow(endo_data)) {
    stop("Error: length endo_data is not equal to the number of periods")
  }
  
  endo <- regts(endo_data, period = dyn_data_period, names = endo_names_dynare,
                labels = endo_names_dynare)
  
  return(endo[period])
}