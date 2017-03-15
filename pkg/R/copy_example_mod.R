#' Creates a copy of an example model file
#'
#' The package \code{dynmdl} includes a number of example model files
#' that can be used to get started with this package. These files are
#' located in the directory \code{models} of the package directory. This
#' function can be used to copy the model file from this directory to
#' a specified directory
#' @param model_name the name of the mod file (currently \code{"islm"} 
#' and \code{"ifn"} are supported)
#' @param filename the file name of the copy model file. By default, this
#' is \code{model_name} suffixed with extension \code{.mdl}.
#' @return \code{TRUE} is the copy was succesful
#' @examples
#' copy_example_mod("islm")
#' \dontshow{
#' dir.create("mod")
#' }
#' copy_example_mod("islm", filename = "mod/islm.mod")
#' \dontshow{
#' unlink("islm.*")
#' unlink("mod", recursive = TRUE)
#' }
#' @seealso \code{\link{create_mdl}} and \code{\link{DynMdl}}
#' @export
copy_example_mod <- function(model_name,
                             filename = paste(model_name, "mod", sep = ".")) {
    if (!model_name %in% c("islm", "ifn")) {
        stop(paste("Model", model_name, "is not an example model file"))
    }
    mdl_file <- system.file("models", paste(model_name, "mod", sep = "."),
                            package = "dynmdl")
    file.copy(mdl_file, filename, overwrite = TRUE)
}
