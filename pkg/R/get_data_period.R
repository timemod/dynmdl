# Internal function used by function dyn_mdl and DynMdl method init_data:
# determine the data period from a data, period and base_period.
#' @importFrom regts range_union
get_data_period <- function(data, period, base_period, mdldef) {
  data_present <- !missing(data) && !is.null(data)
  period_present <- !missing(period) && !is.null(period)
  base_period_present <- !missing(base_period) && !is.null(base_period)
 
  if (data_present) data_period_data <- get_period_range(data)
  if (period_present)  {
    data_period_solve <- period_range(
      start_period(period) - mdldef$max_lag_orig, 
      end_period(period)   + mdldef$max_lead_orig)
  }
  if (data_present && period_present) {
    data_period <- range_union(data_period_data, data_period_solve)
  } else if (data_present && !period_present) {
    data_period <- data_period_data  
  } else {
    data_period <- data_period_solve
  }
  if (base_period_present) {
    data_period <- range_union(data_period,
                               period_range(base_period, base_period))
  }
  return(data_period)
}