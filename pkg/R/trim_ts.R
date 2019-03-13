# This function selects columns from a timeseries with absolute values smaller 
# than tol, and also removes leading and trailing rows with absolute values 
# smaller than tol. This used to simplify a residual check result.

# INPUT:  
#   tsx      : a timeseries
#   period : the period range of x
#   tol    : the selection tolerance
trim_ts <- function(x, period, tol) {
  
  x_abs <- abs(x)
  
  sel_fun <- function(x) {any(is.na(x) | x > tol)}
  
  # first select columns with values > tol, or NA values
  col_sel <- apply(x_abs, MARGIN = 2,  FUN = sel_fun)
  
  x <- x[ , col_sel, drop = FALSE]
  
  if (ncol(x) > 0) {
    # remove leading / trailing rows with values smaller than tol
    sel <- apply(x_abs, MARGIN = 1, FUN = sel_fun)
    elem <- which(sel)
    sel <- min(elem) : max(elem)
    per <- start_period(period) + sel[1] - 1
    period <- period_range(per, per + length(sel) - 1)
    return(x[period, , drop = FALSE])
  } else {
    return(x)
  }
}