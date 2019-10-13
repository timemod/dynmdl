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
                          data = cbind(mdl$get_exo_data_raw(),
                                       mdl$get_endo_data_raw()),
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