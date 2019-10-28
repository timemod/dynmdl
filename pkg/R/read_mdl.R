#' Reads a model from a RDS file
#'
#' This function reads a model from an RDS file that has been written
#' by method \code{\link{write_mdl}} of an \code{\link{DynMdl}} object.
#' @param file the name of the RDS file
#' @param dll_dir the directory where the dynamically linked library is stored.
#' Primarily used for testing. Only used if the model
#' was created with the dll option (see function  \code{\link{dyn_mdl}}). 
#' @return a \code{\link{DynMdl}} object.
#' @examples
#' mdl <- islm_mdl("2017Q1/2019Q2")
#' mdl$write_mdl("islm_mod.rds")
#' mdl2 <- read_mdl("islm_mod.rds")
#' @seealso \code{\link{write_mdl}} 
#' @importFrom utils unzip
#' @export
read_mdl <- function(file, dll_dir) {
  
  if (!file.exists(file)) {
    stop(sprintf("File %s does not exist.", file))
  }
  
  cat(paste("Reading model from", file, "\n"))
  
  ser <- readRDS(file)
  
  # Check class of ser. Since version 1.0, write_mdl always generates an
  # object of class serialized_dynmdl. However, for earlier version
  # the class was serialized_fitmdl for fit model.
  if (!(inherits(ser, "serialized_fitmdl") || 
        inherits(ser, "serialized_dynmdl"))) {
    stop(paste("File", file, "does not contain a serialized DynMdl object."))
  }
  
  mdl <- DynMdl$new()$deserialize(ser, dll_dir)

  cat("Done\n")
  return(mdl)
}
