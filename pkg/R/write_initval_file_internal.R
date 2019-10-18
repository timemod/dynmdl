#' @importFrom openxlsx write.xlsx
#' @importFrom tools file_ext
write_initval_file_internal <- function(file, mdldef, model_period, 
                                        endo_data, exo_data, 
                                        rename_aux_vars = TRUE) {
  
  type <- file_ext(file)
  if (!type %in% c("m", "xlsx")) {
    stop(paste("The extension of the initval file should be either '.m'",
               "or '.xlsx'."))
  }
                                      
  # write_initval_file does not works for endogenous
  # lags or leads > 1. 
  if (mdldef$max_endo_lag > 1 || mdldef$max_endo_lead > 1) {
    stop(paste("Method write_initval_file does not work for models",
               "with max_lag > 1 or max_lead > 1.\n",
               "Tip: call function dyn_mdl with option",
               "max_laglead_1 = TRUE."))
  }
  
  #
  # rename auxiliary variables
  #
 
  aux_vars <- mdldef$aux_vars
  if (rename_aux_vars && aux_vars$aux_count > 0) {
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
        lag_aux_var_names <- paste("AUX_ENDO_LAG", orig_symb_ids[is_lag] - 1,
                                   -orig_leads[is_lag], sep = "_")
        colnames(endo_data)[lag_aux_vars] <<- lag_aux_var_names
      }
    })
  } 
    
  max_lag <- max(mdldef$max_endo_lag, mdldef$max_exo_lag)
  max_lead <- max(mdldef$max_endo_lead, mdldef$max_exo_lead)
  dyn_data_period <- period_range(start_period(model_period) - max_lag,
                                  end_period(model_period) + max_lead)
  data <- cbind(endo_data, exo_data)
  data <- data[dyn_data_period, order(colnames(data)), drop = FALSE]
 
  if (type == "m") {
    output <- file(file, open = "w")
    data_list <- as.list(data)
    write_statement <- function(name, data) {
      values <- paste(as.numeric(data), collapse = " ")
      statement <- paste0(name, " = [", values, "];")
      lines <- strwrap(statement, width = 80, exdent = 4)
      if (length(lines) > 1) {
        lines[1:(length(lines) - 1)] <- paste(lines[1:(length(lines) - 1)], "...")
      }
      writeLines(lines, con = output)
      return()
    }
    mapply(FUN = write_statement, names(data_list), data_list)
    
    close(output)
    
  } else {
    write.xlsx(data, file = file, firstRow = TRUE, colWidths = "auto")
  }
  return(invisible(NULL))
}