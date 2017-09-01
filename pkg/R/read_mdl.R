#' Reads a model from a RDS file
#'
#' This function reads a model from an RDS file that has been written
#' by method \code{\link{write_mdl}} of an \code{\link{DynMdl}} or
#' \code{\link{FitMdl}} object.
#' @param file the name of the RDS file
#' @param dll_dir the directory where the dynamically linked library is stored.
#' Primarily used for testing. Only used if the model
#' was created with the dll option (see function  \code{\link{dyn_mdl}}). 
#' @return a \code{\link{DynMdl}} or \code{\link{FitMdl}} object
#' @examples
#' mdl <- islm_mdl("2017Q1/2019Q2")
#' mdl$write_mdl("islm_mod.rds")
#' mdl2 <- read_mdl("islm_mod.rds")
#' @seealso \code{\link{write_mdl}} 
#' @importFrom utils unzip
#' @export
read_mdl <- function(file, dll_dir) {
  cat(paste("Reading model from", file, "\n"))
  ser <- readRDS(file)
  if (ser$use_dll) {
    if (missing(dll_dir)) {
      dll_dir <- tempfile(pattern = "dynmdl_dll_")
    } else if (dir.exists(dll_dir)) {
      unlink(dll_dir, recursive = TRUE)
    }
    dir.create(dll_dir)
    dll_file <- file.path(dll_dir, ser$dll_basename)
    zip_file <- tempfile(pattern = "dynmdl_dll_", fileext = ".zip")
    writeBin(ser$dll_data, con = zip_file)
    unzip(zipfile = zip_file, exdir = dll_dir, junkpaths = TRUE)
    unlink(zip_file)
  } else {
    dll_dir <- NA_character_
    dll_file <- NA_character_
  }
  
  if (ser$class == "FitMdl") {
    mdl <- FitMdl$new(ser$model_info, ser$fit_info, ser$params, 
                      ser$bytecode, ser$use_dll, dll_dir, dll_file)
  } else {
    mdl <- DynMdl$new(ser$model_info, ser$params, ser$bytecode, ser$use_dll, 
                      dll_dir, dll_file)
  }
  mdl$set_static_endos(ser$endos)
  mdl$set_static_exos(ser$exos)
  if (!is.null(ser$endo_data)) {
    mdl$init_data(data_period = get_period_range(ser$endo_data))
    mdl$set_period(ser$period)
    mdl$set_data(ser$endo_data)
    mdl$set_data(ser$exo_data)
  }
  if (!is.null(ser$labels)) {
    mdl$set_labels(ser$labels)
  }
  cat("Done\n")
  return(mdl)
}
