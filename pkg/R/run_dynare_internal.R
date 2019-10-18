# Internal function: Run Dynare with Matkab or Octave
#' @importFrom tools file_path_as_absolute
#' @importFrom tictoc tic
#' @importFrom tictoc toc
run_dynare_internal  <- function(model_name, mod_file,  mdl, period, data, 
                                 steady, perfect_foresight, scratch_dir, 
                                 dynare_path, steady_options,
                                 perfect_foresight_solver_options,
                                 use_octave, rename_aux_vars = TRUE,
                                 mod_file_in_scratch_dir = FALSE) {
  

  if (perfect_foresight) {
    
    if (missing(mdl)) {
      #
      # create a model object, needed to obtain information about the model.
      #
      
      period <- as.period_range(period)
      
      cat("\n======================================================================\n")
      cat("Parsing model with dynmdl to obtain information about the model\n")
      cat("======================================================================\n\n")
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
    
    mdldef <- mdl$get_mdldef()

    #
    # write initval file (only when eiter mdl or data have  been specified)
    #
    tic("writing initval")
    use_initval_file <- !missing(data) || !missing(mdl)
    if (use_initval_file) {
      initval_file <- file.path(scratch_dir, paste0(model_name, "_initval.m"))
      write_initval_file_internal(initval_file, mdldef, period, 
                                  mdl$get_all_endo_data(), 
                                  mdl$get_all_exo_data(),
                                  rename_aux_vars = rename_aux_vars)
    }
    toc()
  }
  
  #
  # create main mod file
  #
  main_mod_file <- file.path(scratch_dir, paste0(model_name, "_dynare.mod"))
  
  output <-  file(main_mod_file, open = "w")
  
  if (!mod_file_in_scratch_dir) {
    writeLines(sprintf("@#include \"%s\"", file_path_as_absolute(mod_file)), 
               con = output)
  } else {
    writeLines(sprintf("@#include \"%s.mod\"", model_name), con = output)
  }
  
  if (steady) {
    if (missing(steady_options) ||  length(steady_options) == 0) {
      writeLines("steady;", con = output)
    } else {
      writeLines(paste0("steady(",  get_dynare_option_string(steady_options), 
                        ");"), con = output)
    }
    writeLines("check;", con = output)
  }
  
  
  if (perfect_foresight) {
    writeLines(sprintf("initval_file(filename = %s_initval);", model_name), 
               con = output)
    writeLines(sprintf("perfect_foresight_setup(periods = %d);", nperiod(period)),
               con = output)
    if (missing(perfect_foresight_solver_options) || 
        length(perfect_foresight_solver_options) == 0) {
      writeLines("perfect_foresight_solver;", con = output)
    } else {
      writeLines(paste0("perfect_foresight_solver(", 
                        get_dynare_option_string(perfect_foresight_solver_options), 
                        ");"), con = output)
    }
  }
  close(output)
  
  #
  # create main matlab/octave file
  #
  matlab_file <- file.path(scratch_dir, paste0("run_", model_name, ".m"))
  output <-  file(matlab_file, open = "w")
  writeLines(c("if is_octave", "    pkg load io", "end", ""), con = output)
  if (!is.null(dynare_path)) {
    writeLines(paste("addpath", file.path(dynare_path, "matlab")), con = output)
  }
  writeLines(sprintf("dynare %s_dynare", model_name), con = output)
  writeLines("")
  writeLines(sprintf("dlmwrite('output/%s_endo_names.txt', M_.endo_names, 'delimiter', '')",
                     model_name), con = output)
  if (steady) {
    writeLines("eigval = [real(oo_.dr.eigval), imag(oo_.dr.eigval)];", 
               con = output)
    
    writeLines(sprintf("dlmwrite('output/%s_eigval.csv', eigval, 'precision', 16)",
                     model_name), con = output)
    writeLines(sprintf("dlmwrite('output/%s_steady.csv', oo_.steady_state, 'precision', 16)",
                       model_name), con = output)
  }
  if (perfect_foresight) {
    writeLines(sprintf("dlmwrite('output/%s_endo.csv', oo_.endo_simul, 'precision', 16)",
                       model_name), con = output)
  }
  close(output)
  
  file_name <- system.file("dynare_templates", "is_octave.m", package = "dynmdl")
  file.copy(file_name, file.path(scratch_dir, "is_octave.m"), overwrite = TRUE)
  
  cwd <- getwd()
  setwd(scratch_dir)
  dir.create("output", showWarnings = FALSE)
  
  if (use_octave) {
    
    
    cat("\n====================================================================\n")
    cat("Running Octave\n")
    cat("====================================================================\n")
    
    
    system2("octave", args =  sprintf("run_%s.m", model_name))
    
  } else {
    
    cat("=====================================================================\n")
    cat("Running Matlab\n")
    cat("=====================================================================\n")
    
    system2("matlab", args =  c("-r", "-nosplash", "-nodesktop", "-wait",
                                sprintf("\"run('run_%s.m');exit;\"", 
                                              model_name)))
    
  }
  
  setwd(cwd)
  
  #
  # read the result
  #
  output_dir <- file.path(scratch_dir, "output")
  endo_name_file <- file.path(output_dir, paste0(model_name, "_endo_names.txt"))
 
  
  endo_names_dynare  <- read.csv(endo_name_file, stringsAsFactors = FALSE,
                                 header = FALSE, sep = "")[[1]]
  
  result <- list()
  
  if (steady) {
    
    steady_file <- file.path(output_dir, paste0(model_name, "_steady.csv"))
    eigval_file <- file.path(output_dir, paste0(model_name, "_eigval.csv"))
    
    steady <- read.csv(steady_file, header = FALSE, sep = "")[[1]]
    names(steady) <- endo_names_dynare
    result$steady_endos <- steady
    
    eigval_data <- read.csv(eigval_file, header = FALSE, sep = ",")
    eigval <- complex(real = eigval_data[, 1], imaginary = eigval_data[ , 2])
    result$eigval <- order_eigval(eigval) 
  }
  
  if (perfect_foresight) {
    
    endo_data_file <- file.path(output_dir, paste0(model_name, "_endo.csv"))
    
    endo_data <- t(as.matrix(read.csv(endo_data_file, header = FALSE)))
    
  
    dyn_data_period <- period_range(start_period(period) - mdldef$max_lag,
                                    end_period(period)   + mdldef$max_lead)
    
    #
    # endogenous variables: return dynare result for the model period
    #
    if (nperiod(dyn_data_period) != nrow(endo_data)) {
      stop("Error: length endo_data is not equal to the number of periods")
    }
    
    result$endo_data <- regts(endo_data, period = dyn_data_period,
                              names = endo_names_dynare,
                              labels = endo_names_dynare)[period]
  }
  
  return(result)
}
