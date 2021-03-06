solve_steady_dynare_internal <- function(model_name, mdl, scratch_dir, 
                                         dynare_path, model_options, 
                                         solve_options, use_octave, 
                                         exit_matlab) {

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
  if (is.null(stat_eqs <- mdl$get_static_equations())) {
    stop("Method solve_steady_dynare cannot be used",
         " for DynMdl object created with dynmdl version < 1.4.")
  }
  mod_file <- file.path(scratch_dir, paste0(model_name, ".mod"))
  write_mod_file_internal(mod_file, mdldef, stat_eqs, model_options)

  ret <- run_dynare_internal(model_name, mod_file, scratch_dir = scratch_dir, 
                             steady = TRUE, check = FALSE, 
                             perfect_foresight = FALSE,
                             dynare_path = dynare_path,
                             steady_options = solve_options,
                             mod_file_in_scratch_dir = TRUE,
                             initval_type = "m",
                             use_octave = use_octave,
                             exit_matlab = exit_matlab,) 

  endo_names <- names(mdldef$endos)
  ret$steady_endos <- ret$steady_endos[endo_names]

  return(ret)
}