#' @export
linlog <- function(x, eps) {
  if (x > eps) {
    return(log(x))
  } else {
    return(log(eps) + (x - eps) / eps)
  }
}