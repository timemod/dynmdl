#' @importFrom Rcpp sourceCpp
#' @useDynLib dynparse
# we need to create a dummy function and export is, otherwise the

# statements above are not processed
#' @export
dummy <- function(x) {
    return (2*x)
}
