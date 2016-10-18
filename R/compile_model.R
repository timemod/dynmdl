#' Compile a model
#'
#' @param mod_file the name of the model file
#' @return an integer
#' @export
#' @importFrom Rcpp sourceCpp
#' @useDynLib dynparse
compile_model <- function(mod_file) {
    return (compile_model_(mod_file))
}
