nonzeros <- function(x) {
  return(x[x != 0])
}

nnz <- function(x) {
  return(length(nonzeros(x)))
}

# This function checks argument value of function set_rms_values or 
# set_param_values
check_value <- function(value) {
  err_msg <- "Argument 'value' should be a scalar numeric."
  if (length(value) != 1) stop(err_msg)
  if (is.integer(value) || (is.logical(value) && is.na(value))) {
    return(as.numeric(value))
  } else if (!is.numeric(value)) {
    stop(err_msg)
  } else {
    return(value)
  }
}
