#' Perform an SVD analysis of a jacobian matrix.
#' 
#' Find linear combinations of rows and columns of the jacobian
#' using an Singular Value Decomposition (SVD) of the jacobian.
#' 
#' @param jac a square matrix, for example the matrix returned
#' by \code{\link{DynMdl}} methods \code{\link{get_static_jacob}}, 
#' \code{\link{get_jacob}} or \code{\link{get_back_jacob}}.
#' @param sd_tol singular value tolerance. Singular values smaller
#' than this tolerance are ignored.
#' @param coef_tol coefficient tolerance. The returned 
#' singular vector matrices do no include rows for which all elements are smaller than 
#' \code{coef_tol}.
#' @return a list with class \code{svd_analysis}, 
#' containing the following components
#' \item{d}{a vector with singular values smaller than \code{sd_tol},
#' in decreasing order.}
#' \item{u}{a matrix with the left singular vectors corresponding to the 
#' singular values \code{d}. Rows for which all elements are smaller
#' than \code{coef_tol} have been removed. The columns of this matrix
#' can be interpreted as the (near) linear relations between the rows 
#' of the jacobian.}
#' \item{v}{a matrix with the right singular vectors corresponding to the 
#' singular values \code{d}. Rows for which all elements are smaller
#' than \code{coef_tol} have been removed. The columns of this matrix
#' can be interpreted as the (near) linear relations between the columns
#' of the jacobian.}
#' \item{svd}{the result of the SVD decomposition as returned by function
#' \code{\link[base]{svd}}.}
#' \item{sd_tol}{the value of argument \code{sd_tol}}
#' \item{coef_tol}{the value of argument \code{coef_tol}}
#' 
#' @seealso \code{\link[base]{svd}} and function 
#' \code{\link[caret]{findLinearCombos}} in package \code{caret}.
#' @examples 
#' # create a singular matrix with linearly dependend rows
#' set.seed(123)
#' x1 <- rnorm(4)
#' x2 <- rnorm(4)
#' x3 <- rnorm(4)
#' mat1 <- rbind(x1, x2, x3, x4 = x2 + x3)
#' mat1
#' 
#' svd_analysis(mat1)
#' 
#' # function findLinearCombos in package caret is also useful.
#' # this function resolves linear relations between the columns 
#' # of matrix (therefore we pass the transpose of mat1)
#' caret::findLinearCombos(t(mat1))
#' 
#' # now example with linearly dependent columns
#' x1 <- rnorm(4)
#' x2 <- rnorm(4)
#' mat2 <- cbind(x1, x2, x3 = x2)
#' svd_analysis(mat2) 
#' @export
svd_analysis <- function(jac, sd_tol = 1e-12, coef_tol = 1e-12) {
  
  jac_svd <- svd(jac)
  
  jac_idx <- jac_svd$d <= sd_tol
  
  eq_names <- paste0("eq_", seq_len(NROW(jac)))
  endo_names <- colnames(jac)
  
  select_non_zero_rows <- function(m) {
    sel <- apply(m, FUN = function(x) {any(abs(x) > coef_tol)}, 
                 MARGIN = 1)
    return(m[sel, , drop = FALSE])
  }
  
  u <- jac_svd$u[ , jac_idx, drop = FALSE]
  rownames(u) <- eq_names
  u <- select_non_zero_rows(u)
  
  v <- jac_svd$v[, jac_idx, drop = FALSE]
  rownames(v) <- endo_names
  v <- select_non_zero_rows(v)
  
  d <- jac_svd$d[jac_idx]
  
  return(structure(list(d = jac_svd$d[jac_idx], u = u, v = v, 
                        svd = jac_svd, sd_tol = sd_tol, coef_tol = coef_tol), 
                        class = "svd_analysis"))
}

#' @export
print.svd_analysis <- function(x, ...) {
  if (length(x$d) == 0) {
    cat(sprintf("No singular values < %g.\n" , x$sd_tol))
    return()
  }
  cat(sprintf("Singular values < %g:\n" , x$sd_tol))
  print(x$d)
  cat("\nLinear combinations of rows (equations):\n")
  print(x$u)
  cat("\nLinear combinations of columns (endos):\n")
  print(x$v)
}