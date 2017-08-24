#' @importFrom numDeriv grad
jacob_element <- function(fun, index, args) {
  names(args) <- NULL
  f <- function(x) {
    args[index] <- x
    return(do.call(fun, as.list(args)))
  }
  return(numDeriv::grad(f, args[index]))
}

# hypot <- function(x, y) {
#   return(x**2+y**2)
# }
# 
# print(jacob_element(hypot, 1, c(2, 3)))
# print(jacob_element(hypot, 2, c(2, 3)))