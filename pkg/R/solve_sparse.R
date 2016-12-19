# solve a non-linear system using the Matrix package
# param x: initial guess
# param fun: a function of x return a vector of functional values
# param jacfun: a funtion that return the Jacobian of the systems of equations,
#               typically as one of the  matrix classes of package Matrix
solve_sparse <- function(x, fun, jacfun, ... , control) {
    solved <- FALSE
    for (iter in 0:control$maxiter) {
        fval <- fun(x, ...)
        err <- max(abs(fval))
        if (control$trace) {
            cat(sprintf("Iteration: %d Largest |f| %g\n", iter, err))
        }
        if (err < control$ftol) {
            solved <- TRUE
            break
        } else {
            jac <- jacfun(x, ...)
            ret <- Matrix::solve(jac, fval)
            x <- x - as.numeric(ret)
        }
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
