#' Solve a \code{\link{SimModel}} object using the dense linear algebra.
#'
#'The method is using various solvers (e.g. \code{\link[nleqslv]{nleqslv}}
#'for a dense linear algebra method).
#'
#' @param mdl a \code{SimModel}

#' @param ... arguments passed to the solver (TODO: add documentation about these
#' arguments, in particular for the sparse newton solver)
#' @return a new \code{SimModel} with the solved model
#' @export
setGeneric("solve_model", function(mdl, solver = c("sparse_newton", "nleqslv"),
                                   ...) {
    standardGeneric("solve_model")
}, signature = "mdl")

#' @describeIn solve_model Solve a  \code{\link{SimModel}}  model
#' using the dense linear algebra
#' @param solver the solve method
#' @param numjac If true, then the Jacobian will be calculated
#' numerically. Only used for the \code{nleqslv} solver
#' @export
setMethod("solve_model", signature = "SimModel",
          definition = function(mdl, solver = c("sparse_newton", "nleqslv",
                                                "dfsane", "BBsolve"),
                                numjac = FALSE, ...) {
              solver <- match.arg(solver)
              lags <- get_lags(mdl)
              leads <- get_leads(mdl)
              nper <- lensub(mdl@model_period)
              x <- get_solve_endo(mdl)
              if (solver == "sparse_newton") {
                  return (solve_sparse_newton(mdl, x, lags, leads, nper,
                                        numjac, ...))
              } else if (solver == "nleqslv") {
                  return (solve_nleqslv(mdl, x, lags, leads, nper,
                                        numjac, ...))
              } else if (solver == "dfsane") {
                  return (solve_dfsane(mdl, x, lags, leads, nper, ...))
              } else if (solver == "BBsolve") {
                  return (solve_BBsolve(mdl, x, lags, leads, nper, ...))
              }
          }
)

# us the sparse Newton method
solve_sparse_newton <- function(mdl, x, lags, leads, nper, numjac,
                          control = list()) {

    control_ <- list(ftol = 1e-8, maxiter = 20, trace = FALSE)
    control_[names(control)] <- control

    solved <- FALSE
    for (iter in 0:control_$maxiter) {
        res <- get_residuals(x, mdl, lags, leads, nper)
        err <- max(abs(res))
        if (control_$trace) {
            cat(sprintf("Iteration: %d Largest |f| %g\n", iter, err))
        }
        if (err < control_$ftol) {
            solved <- TRUE
            break
        } else {
            jac <- get_jac(x, mdl, lags, leads, nper)
            ret <- Matrix::solve(jac, res)
            x <- x - as.numeric(ret)
        }
    }

    # TODO: line searching?

    mdl@solve_out <- list(solved = solved, iter = iter, residual = res)
    mdl@endo_data[mdl@model_period, ] <- t(matrix(x, nrow = mdl@endo_count))
    return (invisible(mdl))
}

solve_nleqslv <- function(mdl, x, lags, leads, nper, numjac, ...) {
    if (!numjac) {
        jacfun <- function(...) {
            return (get_jac(...,  sparse = FALSE))
        }
    } else {
        jacfun <- NULL
    }
    mdl@solve_out <- nleqslv::nleqslv(x, fn = get_residuals,
                                      jac = jacfun, mdl = mdl,
                                      lags = lags, leads = leads, nper = nper,
                                      ...)
    mdl@endo_data[mdl@model_period, ] <- t(matrix(mdl@solve_out$x,
                                                  nrow = mdl@endo_count))
    return (invisible(mdl))
}

