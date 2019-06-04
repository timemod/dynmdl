#' @export
linlog <- function(x, eps) {
  if (x > eps || eps < 0) {
    return(log(x))
  } else {
    return(log(eps) + (x - eps) / eps)
  }
}