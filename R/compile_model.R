#' Compile a Dynare model and return a \code{\link{SimModel}}
#'
#' @param mod_file the name of the model file (including extension .mod)
#' @param bytecode If \code{TRUE}, then the functions used to calculate the
#' residuals and jacobian are compiled.
#' @return an \code{SimModel} object
#' @export
#' @importFrom Rcpp sourceCpp
#' @useDynLib dynr
compile_model <- function(mod_file, bytecode = TRUE) {
    return (SimModel$new(mod_file, bytecode))
}
