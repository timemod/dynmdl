# Internal function: Run Dynare with Matkab or Octave
#' @importFrom tools file_path_as_absolute
#' @importFrom tictoc tic
#' @importFrom tictoc toc
#' @importFrom utils read.csv
run_dynare_internal  <- function(model_name, mod_file,  mdl, period, data, 
                                 steady, check, perfect_foresight, scratch_dir, 
                                 dynare_path, steady_options,
                                 perfect_foresight_solver_options,
                                 rename_aux_vars = TRUE,
                                 mod_file_in_scratch_dir = FALSE,
                                 initval_type = "m",
                                 use_octave, exit_matlab) {
  
  # if DynMdl is running on CPB, set the appropriate Dynare path
  dynare_path_cpb <- "m:/p_dynare/dynare/4.5.7_optim_only"
  if (is.null(dynare_path) && .Platform$OS.type == "windows" &&
      file.exists(dynare_path_cpb)) {
    dynare_path <- dynare_path_cpb
  }
  
  write_header <- function(text) {
    line <- paste(rep("=", 80), collapse = "")
    cat(paste0("\n", line, "\n"))
    cat(paste0(text, "\n"))
    cat(paste0(line, "\n\n"))
    return()
  }

  if (perfect_foresight) {
    
    if (missing(mdl)) {
      #
      # create a model object, needed to obtain information about the model.
      #
      
      period <- as.period_range(period)
      
      write_header("Parsing model with dynmdl to check lags/leads/aux. vars")
     
      mdl <- dyn_mdl(mod_file, period = period, max_laglead_1 = TRUE, 
                     strict = FALSE, fit = FALSE)
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
      initval_file <- file.path(scratch_dir, paste0(model_name, "_initval.",
                                                    initval_type))
      write_initval_file_internal(initval_file, mdldef, period, 
                                  mdl$get_all_endo_data_dynare(), 
                                  mdl$get_all_exo_data_dynare(),
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
  }
  
  if (check) writeLines("check;", con = output)


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
    writeLines(sprintf("dlmwrite('output/%s_steady.csv', oo_.steady_state, 'precision', 16)",
                       model_name), con = output)
  }
  if (check) {
    writeLines("eigval = [real(oo_.dr.eigval), imag(oo_.dr.eigval)];", 
               con = output)
    writeLines(sprintf("dlmwrite('output/%s_eigval.csv', eigval, 'precision', 16)",
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
    write_header("Running Octave:")
    system2("octave", args =  sprintf("run_%s.m", model_name))
    write_header("Octave job finished.")
  } else {
    write_header("Running Matlab:")
    matlab_command <- sprintf("\"run('run_%s.m');\"", model_name)
    if (exit_matlab) matlab_command <- paste0(matlab_command, "exit;")
    system2("matlab", args = c("-nosplash", "-nodesktop", "-wait", "-r",
                                matlab_command))
    write_header("Matlab job finished.")
  }
    
  setwd(cwd)
  
  #
  # read the result
  #
  output_dir <- file.path(scratch_dir, "output")
  endo_name_file <- file.path(output_dir, paste0(model_name, "_endo_names.txt"))
 
  if (!file.exists(endo_name_file)) {
    stop("Dynare job did not succced. Check output.")
  }
  
  endo_names_dynare  <- read.csv(endo_name_file, stringsAsFactors = FALSE,
                                 header = FALSE, sep = "")[[1]]
  
  result <- list()
  
  if (steady) {
    steady_file <- file.path(output_dir, paste0(model_name, "_steady.csv"))
    steady <- read.csv(steady_file, header = FALSE, sep = "")[[1]]
    names(steady) <- endo_names_dynare
    result$steady_endos <- steady
  }
  
  if (check) {
    eigval_file <- file.path(output_dir, paste0(model_name, "_eigval.csv"))
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
