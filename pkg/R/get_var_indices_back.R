# Returns the indices of the lags, leads and current variables in t(endo_data)
# (the transpose of the endo data, so the columns corrspond to different periods,
# this can also be the elment mat of endo_data_solve object), for a specific 
# period specified with argument period_index. 
# Used in methods solve_backward_model and get_back_jacob.
#
# INPUT:
#  mdldef       : a list with the model definitions as used in the DynMdl object.
#  period_index : the index relative to the first column of t(endo_data)
#                 Thus a period_index of 1 corresponds to the first period
#                 in the data period
# RETURN:
#   a list with the indices of the lags, leads and current variables

get_var_indices_back <- function(mdldef, period_index) {
  
  nendo <- mdldef$endo_count
  max_lag <- mdldef$max_endo_lag
  max_lead <- mdldef$max_endo_lead

  lags <- which(mdldef$lead_lag_incidence[ , seq_len(max_lag)] != 0) + 
          (period_index - 1 - max_lag) * nendo
  
  if (max_lead > 0) {
      lead_cols <- seq_len(max_lead) + max_lag + 1
      leads <- which(mdldef$lead_lag_incidence[ , lead_cols] != 0) + 
               period_index * nendo
  } else {
    leads <- integer(0)
  }

  curvars <- seq_len(nendo) + (period_index - 1) * nendo

  return(list(lags = lags, leads = leads, curvars = curvars))
}
