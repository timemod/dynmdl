solve_steady_dynare_internal <- function(model_name, mdl, scratch_dir, 
                                         use_octave, dynare_path, model_options, 
                                         solve_options) {
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

  ret <- run_dynare_internal(model_name, mod_file, scratch_dir, 
                             steady = TRUE, perfect_foresight = FALSE,
                             use_octave = use_octave,
                             dynare_path = dynare_path,
                             mod_file_in_scratch_dir = TRUE,
                             steady_options = solve_options) 

  
  
  endo_names <- names(mdldef$endos)
  ret$steady_endos <- ret$steady_endos[endo_names]

  return(ret)
}