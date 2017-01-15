# Solve a non-linear system using the Matrix package
# param x: initial guess
# param fun: a function of x returning a vector of functional values
# param jacfun: a function that returns the Jacobian of the systems of
#               equations, yypically as one of the  matrix classes of package Matrix
# param ...    arguments passed to fun and jacfun
# param control control parameters
solve_sparse <- function(x, fun, jacfun, ... , control) {
    solved <- FALSE
    cond <- NA
    if (control$trace) {
        cat(sprintf("\nIteration report\n"))
        cat(sprintf("----------------\n"))
        cat(sprintf("%5s%20s%20s%20s\n", "Iter", "inv. cond. jac.",
                    "Largest |f|", "Index largest |f|"))
    }
    for (iter in 0:control$maxiter) {
        fval <- fun(x, ...)
        fval_abs <- abs(fval)
        err <- max(fval_abs)
        if (is.na(err)) {
            i <- which(is.na(fval))[1]
            if (iter == 0) {
                stop(sprintf(paste("Initial value of function contains",
                    "non-finite values (starting at index=%d)\n"), i))
            } else {
                stop(sprintf(paste("Function value contains",
                    "non-finite values (starting at index=%d)\n"), i))
            }
        }
        if (control$trace) {
            i <- which.max(fval_abs)
            if (iter == 0) {
                cat(sprintf("%5d%20s%20.3e%20d\n", iter, "", err, i))
            } else  {
                cat(sprintf("%5d%20.2e%20.3e%20d\n", iter, cond, err, i))
            }
        }
        if (iter > 0 && cond < control$cndtol) {
            stop(sprintf("The inverse condition of the matrix is less than %g\n", 
                         control$cndtol))
        }
        if (err < control$ftol) {
            solved <- TRUE
            break
        } else {
            jac <- jacfun(x, ...)
            cond <- 1 / Matrix::condest(jac)$est
            ret <- Matrix::solve(jac, fval)
            x <- x - as.numeric(ret)
        }
    }
    if (control$trace) {
        cat("\n")
    }

    # TODO: line search for bad convergence

    if (!control$silent) {
        if (solved) {
            cat(sprintf("Convergence after %d iterations\n", iter))
        } else {
            cat(sprintf("No convergence after %d iterations\n", iter))
        }
    }

    return (list(solved = solved, iter = iter, x = x, fval = fval))
}
