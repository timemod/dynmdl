#' This function computes the eigenvalues of the linearized model around the
#' steady state.
#'
#' The function first attemts to calculate the steady state,
#' then linearizes the model around the steady state and finally calculates the
#' eigenvalues. This function also works for models with lags or 
#' leads greater than 1, in contrast to the \code{\link{check}} method of the 
#' \code{DynMdl} class.
#' @param mod_file the model file (the text file specifying the model
#' equations)
#' @param endos a named numerical vector with an initial guess for the 
#' steady state values of the endogenous variables
#' @param exos a named numerical vector with the static exogenous variables
#' used to compute the steady state
#' @export
check_mdl <- function(mod_file, endos, exos) {

  ret <- create_check_mdl(mod_file)
  mdl <- ret$mdl
  aux_vars <- ret$aux_vars

  if (!missing(endos)) {
    if (aux_vars$aux_count > 0) {
      orig <- intersect(aux_vars$orig_endos, names(endos))
      if (length(orig) > 0) {
        aux_endos <- endos[orig];
        orig_index <- match(orig, aux_vars$orig_endos)
        names(aux_endos) <- aux_vars$endos[orig_index]
        endos <- c(endos, aux_endos)
      }
    }
    mdl$set_static_endos(endos)
  }

  if (!missing(exos)) {
    mdl$set_static_exos(exos)
  }

  cat("solving the steady state...\n")
  mdl$solve_steady()

  # TODO: error if solve_steady was not succeful
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

  return(list(mdl = mdl, aux_vars = model_info$aux_vars))
}
