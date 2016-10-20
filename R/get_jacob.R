#' Returns the dense stacked-time Jacobian
#'
#' This function returns the stacked-time Jacobian for the complete
#' solve period as a \code{\link{Matrix}} or \code{\link{matrix}}
#' (depending on argument \code{sparse})
#' @param mdl a \code{\link{SimModel}}
#' @param sparse If \code{TRUE} then the function returns a dense Jacobiab,
#' otherwise a sparse Jacobian created with the  a \code{\link{Matrix}}
#' package
#' @return the stacked-time Jacobian
#' @export
setGeneric("get_jacob", function(mdl, sparse = TRUE) {
    standardGeneric("get_jacob")
}, signature = "mdl")


#' @describeIn get_jacob Returns the dense stacked-time Jacobian
#' for the solution period
#' @export
setMethod("get_jacob", signature = "SimModel",
          definition = function(mdl, sparse = TRUE) {
              lags <- get_lags(mdl)
              leads <- get_leads(mdl)
              exo <- get_exo(mdl)
              nper <- regts::lensub(mdl@model_period)
              x <- get_solve_endo(mdl)
              return (get_jac(x, mdl, lags, leads, exo, nper, sparse = sparse))
          }
)
