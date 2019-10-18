solve_dynare_internal <- function(model_name, mdl, scratch_dir, dynare_path, 
                                  model_options, solve_options, use_octave) {
  
  solve_options_ = list(tolf = 1e-8, tolx = 1e-8)
  if (!missing(solve_options)) {
    solve_options_[names(solve_options)] <- solve_options
  }
  
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
  write_mod_file_internal(mod_file, mdldef, mdl$get_equations(), model_options)
  
  if (mdldef$max_endo_lag > 1 || mdldef$max_endo_lead > 1) {
    # NOTE: to data we pass all endogenous and exogenous variables.
    # This we do because of fit procedure.
    sol  <- run_dynare_internal(model_name, mod_file, 
                                period = mdl$get_period(), 
                                data = cbind(mdl$get_all_endo_data(),
                                             mdl$get_all_exo_data()),
                                steady = FALSE, perfect_foresight = TRUE,
                                scratch_dir = scratch_dir, 
                                dynare_path = dynare_path,
                                perfect_foresight_solver_options = 
                                                            solve_options,
                                use_octave = use_octave,
                                mod_file_in_scratch_dir = TRUE)$endo_data
  } else {
    sol <- run_dynare_internal(model_name, mod_file, mdl = mdl,
                               steady = FALSE, perfect_foresight = TRUE,
                               scratch_dir = scratch_dir, 
                               dynare_path = dynare_path,
                               perfect_foresight_solver_options = 
                                                            solve_options,
                               use_octave = use_octave, rename_aux_vars = FALSE,
                               mod_file_in_scratch_dir = TRUE)$endo_data
  } 
  

  endo_names <- names(mdldef$endos)
  
  return(sol[ , endo_names, drop = FALSE])
}