#' Solve the steady state of a \code{\link{SimModel}} object
#'
#' The steady state system is solved with the package \code{\link[nleqslv]{nleqslv}}
#'
#' @param mdl a \code{SimModel}
#' @return the return a \code{SimModel} object with the \code{endos} slot set to
#' the steady state values
#' @export
setGeneric("solve_steady", function(mdl) {
    standardGeneric("solve_steady")
})

#' @describeIn solve_steady Solve the steady state of a \code{\link{SimModel}} object
#' @export
setMethod("solve_steady", signature = c("SimModel"),
          definition = function(mdl) {
              f <- function(x) {
                  return (mdl@f_static(x, mdl@exos, mdl@params))
              }
              jac <- function(x) {
                  return (mdl@f_static(x, mdl@exos, mdl@params, jac = TRUE))
              }
              # todo: print output / give error if the commamd was not
              # succesfuill
              out <- nleqslv::nleqslv(mdl@endos, fn = f, jac = jac)
              mdl@endos <- out$x
              return (invisible(mdl))
          }
)
