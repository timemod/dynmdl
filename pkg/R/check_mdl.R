#' This function computes the eigenvaues of the linearized model around the
#' steady state.
#' @param mod_file the model file
#' @export
check_mdl <- function(mod_file) {

  # TODO: add argumemts static_endos and static_exos.
  # When argument static_endos has been specified, then also take auxiliary 
  # variables into account, and no exos.
  
  mdl <- create_check_mdl(mod_file)

  cat("solving the steady state...\n")
  mdl$solve_steady()
  cat("done\n")
  mdl$check()

  return(mdl$get_eigval());
}

create_check_mdl <- function(mod_file) {

  if (!file.exists(mod_file)) {
    stop(paste("ERROR: Could not open file:", mod_file))
  }

  use_dll <- FALSE
  dll_dir <- ""
  dll_file <- NA_character_
  bytecode <- FALSE
  
  model_info <- compile_model_(mod_file, use_dll, dll_dir, TRUE)
  params <- model_info$params
  model_info$params <- NULL
  equations <- NULL
  mdl <- DynMdl$new(model_info, params, equations, 
                      bytecode, use_dll, dll_dir, dll_file)

  return(mdl)
}
