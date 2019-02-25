retrend_endo_data <- function(endo_data, base_period, mdldef, 
                              all_exo_data, all_endo_data) {
  
  defl_endos <- intersect(colnames(endo_data), 
                          mdldef$trend_info$deflated_endos$names)
  
  if (length(defl_endos) == 0) {
    return(endo_data)
  }
  
  sel <- mdldef$trend_info$deflated_endos$names %in% defl_endos
  deflators <- mdldef$trend_info$deflated_endos$deflators[sel]
  deflators <- unique(deflators)
  
  deflator_vars <- mdldef$trend_info$deflator_vars[deflators]
  deflator_vars <- unique(unlist(deflator_vars, use.names = FALSE))
  
  # TODO: period may be smaller than model_data_period, but should always
  # include base_period. For the time being we use the complete model data
  # period.
  trend_data <- get_trend_vars_internal(names = deflator_vars,
                                        period = get_period_range(all_endo_data),
                                        base_period = base_period,
                                        mdldef = mdldef, 
                                        exo_data = all_exo_data,
                                        endo_data = all_endo_data
                                        )
  
  trend_data <- as.list(trend_data)
  
  # the expressions could already have been credted in dyn_mdl.
  expressions  <- lapply(deflators, FUN = function(x) {
    parse(text = x)})
  
  deflator_data <- lapply(expressions, FUN = function(x) {
    eval(x, envir = trend_data)})
  names(deflator_data) <- deflators
 
  sel <- match(defl_endos, mdldef$trend_info$deflated_endos$names)
  deflators <- mdldef$trend_info$deflated_endos$deflators[sel]
  
  defl_data <- deflator_data[deflators]
  names(defl_data) <- defl_endos
  
  defl_data <- do.call(cbind, defl_data)
  
  endo_data[ , defl_endos] <- endo_data[, defl_endos] * defl_data
  return(endo_data)
}