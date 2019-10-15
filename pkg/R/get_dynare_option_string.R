get_dynare_option_string <- function(options) {
  return(paste(names(options), ifelse(lapply(options, FUN = is.null), "", 
                                       paste("=", options)), collapse = ", "))
}