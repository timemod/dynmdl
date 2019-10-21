check_serialized_mdl <- function(ser) {
  
  # Check class of ser. Since version 1.0, write_mdl always generates an
  # object of class serialized_dynmdl. However, for earlier version
  # the class was serialized_fitmdl for fit model.
  if (!(inherits(ser, "serialized_fitmdl") || 
        inherits(ser, "serialized_dynmdl"))) {
    stop(paste("File", file, "does not contain a serialized DynMdl object."))
  }
  
  
  minimal_version <- "0.7"
  if (compareVersion(as.character(ser$version), minimal_version) < 0) {
    stop(paste("It is not possible to read model files",
               "created with dynmdl versions prior to",
               minimal_version, "\nPlease regenerate the model with function",
               "dyn_mdl"))
  }
  
  if (compareVersion(as.character(ser$version), "0.9") < 0 && 
      !is.null(ser$fit_info)) {
    
    ser$fit_info$fixed_period <- FALSE
  }
  
  if (compareVersion(as.character(ser$version), "1.0") < 0) {
  
      #
      # update ser
      # 
      ser$mdldef$endo_names <- names(ser$mdldef$endos)
      ser$mdldef$exo_names <- names(ser$mdldef$exos)
    
      #
      # now calculate the maximum and minimum lag of the data. This is different from
      # the maximum and minimum lag in the model if max_laglead_1 = TRUE.
      #
      ser$max_endo_lag_data  <- ser$max_endo_lag
      set$max_endo_lead_data <- ser$max_endo_lead
      if (ser$aux_vars$aux_count > 0) {
        max_aux_lag <-  max(max(-ser$aux_vars$orig_leads), 0)
        max_aux_lead <- max(max(ser$aux_vars$orig_leads), 0)
        if (max_aux_lag > 0) {
          ser$max_endo_lag_data <- max(ser$max_endo_lag_data, max_aux_lag + 1)
        }
        if (max_aux_lead > 0) {
          ser$max_endo_lead_data <- max(ser$max_endo_lead_data, max_aux_lead +
                                             1)
        }
      }
      
      ser$max_lag_data <- max(ser$max_endo_lag_data,  ser$max_exo_lag)
      ser$max_lead_data <- max(ser$max_endo_lead_data,  ser$max_exo_lead)
  }
  
  
  if (ser$calc == "dll" && ser$os_type != .Platform$OS.type) {
    # TODO: simply recompile the model
    stop("The model functions have been compiled on a different platform")
  }
  
  return(ser)
}