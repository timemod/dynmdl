solve_dynare_internal <- function(scratch_dir, model_name, model_period) {
  
  #
  # create main mod file
  #
  main_mod_file <- file.path(scratch_dir, paste0("simul_", model_name, ".mod"))
   
  output <-  file(main_mod_file, open = "w")
  
  writeLines(sprintf("@#include \"%s.mod\"", model_name), con = output)
  writeLines(sprintf("initval_file(filename = %s_initval);", model_name), 
             con = output)
  writeLines(sprintf("simul(periods = %d);", nperiod(model_period)),
             con = output)
  close(output)
  
  #
  # create main matlab file
  #
  matlab_file <- file.path(scratch_dir, paste0("run_simul_", model_name, ".m"))
  output <-  file(matlab_file, open = "w")
  writeLines(c("if is_octave", "    pkg load io", "end", ""), con = output)
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
  cat("======================================================================")
  cat("\n\nRunning Octave\n\n")
  cat("======================================================================\n")
  system2("octave", args =  sprintf("run_simul_%s.m", model_name))
  setwd(cwd)
  return()
}