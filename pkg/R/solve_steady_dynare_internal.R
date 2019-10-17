solve_steady_dynare_internal <- function(model_name, mdl, scratch_dir, 
                                         dynare_path, model_options, 
                                         solve_options, use_octave) {

  solve_options_ = list(tolf = 1e-8)
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

  ret <- run_dynare_internal(model_name, mod_file, scratch_dir = scratch_dir, 
                             steady = TRUE, perfect_foresight = FALSE,
                             dynare_path = dynare_path,
                             steady_options = solve_options,
                             use_octave = use_octave,
                             mod_file_in_scratch_dir = TRUE) 

  endo_names <- names(mdldef$endos)
  ret$steady_endos <- ret$steady_endos[endo_names]

  return(ret)
}