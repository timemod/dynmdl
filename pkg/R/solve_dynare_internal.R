#'@importFrom openxlsx write.xlsx
solve_dynare_internal <- function(scratch_dir, model_name, equations, mdldef, 
                                  model_period, endo_data, exo_data, 
                                  use_octave, dynare_path) {
  
  # TODO: can we not simply use mdldef$max_endo_lead and mdldef$max_endo_lag here?
  #  check this!
  lead_lag_incidence <- mdldef$lead_lag_incidence
  # max_lag and max_lead computed in the following way are not the same
  # as mdldef$max_lag or mdldef$max_lead when max_laglead_1 = TRUE:
  max_endo_lag <- -as.integer(colnames(lead_lag_incidence)[1])
  max_endo_lead <- as.integer(colnames(lead_lag_incidence)[
                                                   ncol(lead_lag_incidence)])
  if (max_endo_lag > 1 || max_endo_lead > 1) {
    stop(paste("Method solve_dynare does not work for models",
               "with max_endo_lag > 1 or max_endo_lead > 1.\n",
               "Tip: call function dyn_mdl with option",
               "max_laglead_1 = TRUE."))
  }
  

  #
  # create main mod file
  #
  main_mod_file <- file.path(scratch_dir, paste0("simul_", model_name, ".mod"))
   
  output <-  file(main_mod_file, open = "w")
  
  writeLines(sprintf("@#include \"%s.mod\"", model_name), con = output)
  writeLines(sprintf("initval_file(filename = %s_initval);", model_name), 
             con = output)
  writeLines(sprintf("simul(periods = %d, tolf = 1e-8, tolx = 1e-8);", 
                     nperiod(model_period)),
             con = output)
  close(output)
  
  # write mod file
  mod_file <- file.path(scratch_dir, paste0(model_name, ".mod"))
  write_mod_file_internal(mod_file, mdldef, equations)
  
  #
  # write initval file
  #
  # data period of Dynare
  # NOTE: in Dynare, max_endo_lag and max_endo_lead are always <= 1.
  # Currently we assume that DynMdl is called with max_lagleead_1 = TRUE.
  # so this should also be the case for Dynare.
  max_lag <- max(mdldef$max_endo_lag, mdldef$max_exo_lag)
  max_lead <- max(mdldef$max_endo_lead, mdldef$max_exo_lead)
  dyn_data_period <- period_range(start_period(model_period) - max_lag,
                                  end_period(model_period) + max_lead)
  
  initval_file <- file.path(scratch_dir, paste0(model_name, "_initval.xlsx"))
  data <- cbind(endo_data, exo_data)
  data <- data[dyn_data_period, order(colnames(data)), drop = FALSE]
  write.xlsx(data, file = initval_file, firstRow = TRUE, colWidths = "auto")
  
  #
  # create main matlab file
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
    
    
    cat("======================================================================")
    cat("\n\nRunning Octave\n\n")
    cat("======================================================================\n")
     
    system2("octave", args =  sprintf("run_simul_%s.m", model_name))
    
  } else {
    
    cat("======================================================================")
    cat("\n\nRunning Matlab\n\n")
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
  
  #
  # endogenous variables: return dynare result for the model period
  #
  if (nperiod(dyn_data_period) != nrow(endo_data)) {
    stop("Error: length endo_data is not equal to the number of periods")
  }

  endo <- regts(endo_data, period = dyn_data_period, names = endo_names_dynare,
                labels = endo_names_dynare)
  
  endo_names <- names(mdldef$endos)
  return(endo[model_period, endo_names, drop = FALSE])
}