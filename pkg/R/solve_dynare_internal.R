solve_dynare_internal <- function(model_name, mdl, scratch_dir, use_octave, 
                                  dynare_path) {
  #
  # create scratch directory
  #
  if (dir.exists(scratch_dir)) {
    if (unlink(scratch_dir, recursive = TRUE, force = TRUE)  == 1) {
      stop(sprintf("Not possible to delete directory %s.", scratch_dir))
    }
  }
  dir.create(scratch_dir)
  
  mdldef <- mdl$get_mdldef()
  
  #
  # write mod file
  #
  mod_file <- file.path(scratch_dir, paste0(model_name, ".mod"))
  write_mod_file_internal(mod_file, mdldef, mdl$get_equations())
  
  
  if (mdldef$max_endo_lag > 1 || mdldef$max_endo_lead > 1) {
    # NOTE: to data we pass all endogenous and exogenous variables.
    # This we do because of fit procedure.
    solution <- run_dynare(model_name, mod_file, scratch_dir, 
                          period = mdl$get_period(), 
                          data = mdl$get_data(),
                          tasks = "simul", use_octave = use_octave,
                          dynare_path = dynare_path,
                          mod_file_in_scratch_dir = TRUE)
  } else {
    solution <- run_dynare(model_name, mod_file, scratch_dir, 
                           mdl = mdl, rename_aux_vars = FALSE, 
                           tasks = "simul", use_octave = use_octave,
                           dynare_path = dynare_path,
                           mod_file_in_scratch_dir = TRUE)
  } 
  
  endo_names <- names(mdldef$endos)
  return(solution[ , endo_names, drop = FALSE])
}
    

  # #
  # # Create auxiliary varibales for Dynare
  # #
  # if (mdldef$max_endo_lag > 1 || mdldef$max_endo_lead > 1) {
  #   
  #   cat("======================================================================")
  #   cat("\n\nParsing model to obtain names auxiliary variables for Dynare\n\n")
  #   cat("======================================================================\n")
  #   mdl <- dyn_mdl(mod_file, max_laglead_1 = TRUE)
  #   aux_vars <- mdl$get_aux_vars()
  #   
  #   aux_vars$names_dyn <- ifelse(aux_vars$orig_lead > 0,
  #                                paste0("AUX_ENDO_LEAD_", aux_vars$orig_expr_index),
  #                                paste("AUX_ENDO_LAG", aux_vars$orig_symb_ids - 1,
  #                                      -aux_vars$orig_leads, sep = "_"))
  #  
  #   per <- get_period_range(endo_data)
  #   nper <- nperiod(per)
  #   # TODO: can this be programmed more efficiently (check also
  #   # DynMdl:;prepareAuxvars): create a function for this
  #   f <- function(orig_endo_index, orig_lead) {
  #     ret <- regts(rep(mdldef$endos[orig_endo_index], nper), period = per)
  #     tmp <- lag(endo_data[ , orig_endo_index], orig_lead)[per]
  #     sel <-  if (orig_lead > 0) {
  #                  1 : (nper - orig_lead)
  #             } else {
  #                 (-orig_lead + 1) : nper
  #             }
  #     ret[sel] <- tmp[sel]
  #     return(ret)
  #   }
  #   aux_ts_list <- mapply(FUN = f, aux_vars$orig_endos, aux_vars$orig_leads,
  #                          SIMPLIFY = FALSE)
  #   names(aux_ts_list) <- aux_vars$names_dyn
  #   aux_ts <- do.call(cbind, aux_ts_list)
  #   endo_data <- cbind(aux_ts, endo_data)
  # }
  # 
  # 
  # #
  # # create main mod file
  # #
  # main_mod_file <- file.path(scratch_dir, paste0("simul_", model_name, ".mod"))
  #  
  # output <-  file(main_mod_file, open = "w")
  # 
  # writeLines(sprintf("@#include \"%s.mod\"", model_name), con = output)
  # writeLines(sprintf("initval_file(filename = %s_initval);", model_name), 
  #            con = output)
  # writeLines(sprintf("simul(periods = %d, tolf = 1e-8, tolx = 1e-8);", 
  #                    nperiod(model_period)),
  #            con = output)
  # close(output)
  # 
  # #
  # # write initval file
  # #
  # # data period of Dynare
  # # NOTE: in Dynare, max_endo_lag and max_endo_lead are always <= 1.
  # # Currently we assume that DynMdl is called with max_lagleead_1 = TRUE.
  # # so this should also be the case for Dynare.
  # max_endo_lag_dyn <- min(mdldef$max_endo_lag, 1)
  # max_endo_lead_dyn <- min(mdldef$max_endo_lead, 1)
  # max_lag <- max(max_endo_lag_dyn, mdldef$max_exo_lag)
  # max_lead <- max(max_endo_lead_dyn, mdldef$max_exo_lead)
  # dyn_data_period <- period_range(start_period(model_period) - max_lag,
  #                                 end_period(model_period) + max_lead)
  # 
  # initval_file <- file.path(scratch_dir, paste0(model_name, "_initval.xlsx"))
  # data <- cbind(endo_data, exo_data)
  # data <- data[dyn_data_period, order(colnames(data)), drop = FALSE]
  # write.xlsx(data, file = initval_file, firstRow = TRUE, colWidths = "auto")
  # 
  # #
  # # create main matlab file
  # #
  # matlab_file <- file.path(scratch_dir, paste0("run_simul_", model_name, ".m"))
  # output <-  file(matlab_file, open = "w")
  # writeLines(c("if is_octave", "    pkg load io", "end", ""), con = output)
  # if (!missing(dynare_path)) {
  #   writeLines(paste("addpath", dynare_path), con = output)
  # }
  # writeLines(sprintf("dynare simul_%s", model_name), con = output)
  # writeLines("")
  # writeLines(sprintf("dlmwrite('output/simul_%s_endo_names.txt', M_.endo_names, 'delimiter', '')",
  #                    model_name), con = output)
  # writeLines(sprintf("dlmwrite('output/simul_%s_endo.csv', oo_.endo_simul, 'precision', 16)",
  #            model_name), con = output)
  # 
  # close(output)
  # 
  # file_name <- system.file("dynare_templates", "is_octave.m", package = "dynmdl")
  # file.copy(file_name, file.path(scratch_dir, "is_octave.m"), overwrite = TRUE)
  # 
  # cwd <- getwd()
  # setwd(scratch_dir)
  # dir.create("output", showWarnings = FALSE)
  # 
  # if (use_octave) {
  #   
  #   
  #   cat("======================================================================")
  #   cat("\n\nRunning Octave\n\n")
  #   cat("======================================================================\n")
  #    
  #   system2("octave", args =  sprintf("run_simul_%s.m", model_name))
  #   
  # } else {
  #   
  #   cat("======================================================================")
  #   cat("\n\nRunning Matlab\n\n")
  #   cat("======================================================================\n")
  #   
  #   system2("matlab", args =  c("-r", sprintf("\"run('run_simul_%s.m');exit;\"", 
  #                                             model_name)))
  #   
  # }
  #   
  # setwd(cwd)
  # 
  # #
  # # read the result
  # #
  # output_dir <- file.path(scratch_dir, "output")
  # endo_name_file <- file.path(output_dir, paste0("simul_", model_name, 
  #                                                "_endo_names.txt"))
  # endo_data_file <- file.path(output_dir, paste0("simul_", model_name, 
  #                                                "_endo.csv"))
  # 
  # endo_names_dynare  <- read.csv(endo_name_file, stringsAsFactors = FALSE,
  #                                header = FALSE, sep = "")[[1]]
  # 
  # endo_data <- t(as.matrix(read.csv(endo_data_file, header = FALSE)))
  # 
  # #
  # # endogenous variables: return dynare result for the model period
  # #
  # if (nperiod(dyn_data_period) != nrow(endo_data)) {
  #   stop("Error: length endo_data is not equal to the number of periods")
  # }
  # 
  # endo <- regts(endo_data, period = dyn_data_period, names = endo_names_dynare,
  #               labels = endo_names_dynare)
  # 
  # endo_names <- names(mdldef$endos)
  # return(endo[model_period, endo_names, drop = FALSE])
#}