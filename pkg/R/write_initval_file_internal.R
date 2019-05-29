#'@importFrom openxlsx write.xlsx
write_initval_file_internal <- function(file, mdldef, endo_data, exo_data) {
  
  #
  # first check that there are no endogenous lags/leads > 1
  #
  lead_lag_incidence <- mdldef$lead_lag_incidence
  # max_lag and max_lead computed in the following way are not the same
  # as mdldef$max_lag or mdldef$max_lead when max_laglead_1 = TRUE:
  max_lag <- -as.integer(colnames(lead_lag_incidence)[1])
  max_lead <- as.integer(colnames(lead_lag_incidence)[
    ncol(lead_lag_incidence)])
  # write_initval_file does not works for endogenous
  # lags or leads > 1. 
  if (max_lag > 1 || max_lead > 1) {
    stop(paste("Method write_initval_file does not work for models",
               "with max_lag > 1 or max_lead > 1.\n",
               "Tip: call function dyn_mdl with option",
               "max_laglead_1 = TRUE."))
  }
  

  aux_vars <- mdldef$aux_vars
  if (aux_vars$aux_count > 0) {
    if (is.null(aux_vars$orig_expr_index)) {
      stop(paste("write_initval_file does not work for DynMdl objects",
                 "created with dynmdl version < 0.9.0.",
                 "Create a new model object"))
    }
    # rename auxiliary lags and leads
    with(aux_vars, {
      is_lead <- orig_leads > 0
      if (any(is_lead)) {
        lead_aux_vars <- endos[is_lead]
        lead_aux_var_names <- paste0("AUX_ENDO_LEAD_", 
                                     orig_expr_index[is_lead])
        colnames(endo_data)[lead_aux_vars] <<- lead_aux_var_names
      }
      is_lag <- orig_leads < 0
      if (any(is_lag)) {
        lag_aux_vars <- endos[is_lag]
        lag_aux_var_names <- paste("AUX_ENDO_LAG_", orig_endos[is_lead],
                                   -orig_leads, sep = "_")
        colnames(endo_data)[lag_aux_vars] <<- lag_aux_var_names
      }
    })
  }
  
  data <- cbind(endo_data, exo_data)
  data <- data[ , order(colnames(data)), drop = FALSE]
  
  write.xlsx(data, file = file, firstRow = TRUE, colWidths = "auto")
  return(invisible(NULL))
}