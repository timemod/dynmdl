check_dynare_internal <- function(model_name, mdl, scratch_dir, 
                                  dynare_path, model_options, 
                                  use_octave, exit_matlab) {

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
  write_mod_file_internal(mod_file, mdldef, mdl$get_equations(), 
                          model_options)

  ret <- run_dynare_internal(model_name, mod_file, scratch_dir = scratch_dir, 
                             steady = FALSE, check = TRUE, 
                             perfect_foresight = FALSE,
                             dynare_path = dynare_path,
                             mod_file_in_scratch_dir = TRUE,
                             initval_type = "m",
                             use_octave = use_octave,
                             exit_matlab = exit_matlab,) 

  return(ret)
}