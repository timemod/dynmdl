get_trend_vars_internal <- function(names, pattern, period, base_period, mdldef, 
                                    exo_data, endo_data) {
  #
  # calculate trend variables based on the current values of the endogenous
  # and exogenous variables
  #
  trend_var_info <- mdldef$trend_info$trend_vars
  
  if (missing(names) && missing(pattern)) {
    names <- trend_var_info$names
  } else {
    stop("dynmdl cannot handle this situation yet")
  }
  
  growth_factors <- trend_var_info$growth_factors[names %in% trend_var_info$names]
  
  growth_vars <- mdldef$trend_info$growth_factor_vars[unique(growth_factors)]
 
  gr_endos <- unname(unlist(lapply(growth_vars, FUN = function(x) x$endo)))
  gr_exos <- unname(unlist(lapply(growth_vars, FUN = function(x) x$exo)))
  
  if (length(gr_exos) > 0) {
    exo_data <- as.list(exo_data[ , gr_exos, drop = FALSE]) 
  } else {
    exo_data <- list()
  }
  if (length(gr_endos) > 0) {
    endo_data <- as.list(endo_data[ , gr_endos, drop = FALSE])
  } else { 
    endo_data <- list()
  }
 
  data <- c(exo_data, endo_data)

  # TODO: this part could be more efficient is more than one variable
  # shares the same growth factor, then we do not have to transform twice.
  expressions  <- lapply(growth_factors, FUN = function(x) {
    parse(text = x)})
  
  retval <- lapply(expressions, FUN = function(x) {eval(x, envir = data)})
  names(retval) <- names
  
  retval <- (do.call(cbind, retval))
  
  retval <- rel2index(retval - 1, base = base_period, scale = 1)
  
  if (!is.matrix(retval)) {
     dim(retval) <- c(length(retval), 1)
     colnames(retval) <- names
  }

  return(retval)
}