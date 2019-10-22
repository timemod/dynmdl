# this function updates serialized models created with older versions of 
# package dynmdl.
update_serialized_mdl <- function(ser) {
  
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
    #  update mdldef
    #
    mdldef <- ser$mdldef
    
    mdldef$fit <- !is.null(ser$fit_info)
    mdldef$has_aux_vars <- mdldef$aux_vars$aux_count > 0 
    
    mdldef$endo_names <- names(mdldef$endos)
    mdldef$exo_names <- names(mdldef$exos)
    mdldef$param_names <- names(mdldef$params)
    
    # endogenous variables excl. aux. vars
    if (mdldef$has_aux_vars) {
      mdldef$endo_names_no_aux <- mdldef$endo_names[-mdldef$aux_vars$endos]
    } else {
      mdldef$endo_names_no_aux <- mdldef$endo_names
    } 
    
    # endos and exos of original model (excl. auxiliary variables and 
    # endos and exos generated for the fit procedure.):
    if (mdldef$fit) {
      mdldef$endo_names_orig <- ser$fit_info$orig_endos
      mdldef$exo_names_orig <- ser$fit_info$orig_exos
    } else {
      mdldef$endo_names_orig <- mdldef$endo_names_no_aux
      mdldef$exo_names_orig <- mdldef$exo_names
    }
    mdldef$endo_indices_orig <- match(mdldef$endo_names_orig, mdldef$endo_names)
    mdldef$exo_indices_orig <- match(mdldef$exo_names_orig, mdldef$exo_names)
    
    #
    # total maximum lag and lead 
    #
    mdldef$max_lag <- max(mdldef$max_endo_lag, mdldef$max_exo_lag)
    mdldef$max_lead <- max(mdldef$max_endo_lead,  mdldef$max_exo_lead)
    
    #
    # now calculate the maximum and minimum lag of the data. This is different from
    # the maximum and minimum lag in the model if max_laglead_1 = TRUE.
    #
    mdldef$max_endo_lag_orig  <- mdldef$max_endo_lag
    mdldef$max_endo_lead_orig <- mdldef$max_endo_lead
    if (mdldef$aux_vars$aux_count > 0) {
      max_aux_lag <-  max(max(-mdldef$aux_vars$orig_leads), 0)
      max_aux_lead <- max(max(mdldef$aux_vars$orig_leads), 0)
      if (max_aux_lag > 0) {
        mdldef$max_endo_lag_orig <- max(mdldef$max_endo_lag_orig, 
                                        max_aux_lag + 1)
      }
      if (max_aux_lead > 0) {
        mdldef$max_endo_lead_orig <- max(mdldef$max_endo_lead_orig, 
                                             max_aux_lead + 1)
      }
    }
    
    mdldef$max_lag_orig <- max(mdldef$max_endo_lag_orig, mdldef$max_exo_lag)
    mdldef$max_lead_orig <- max(mdldef$max_endo_lead_orig,  mdldef$max_exo_lead)
    
    ser$mdldef <- mdldef
    
    #
    # move fields
    #
    ser$mdldef$equations_orig <- ser$equations
    ser[["equations"]] <- NULL
    ser$mdldef$equations <- NULL
    
    #
    # information about fit
    #
    fit_info <- ser$fit_info
    if (mdldef$has_fit) {
      # calculate indices
      fit_info$l_vars_idx <- match(fit_info$l_vars, mdldef$endo_names)
      fit_info$fit_vars_idx <- match(fit_info$fit_vars, mdldef$exo_names)
      fit_info$exo_vars_idx <- match(fit_info$exo_vars, mdldef$exo_names)
    
      fit_info$instruments_idx <- match(fit_info$instruments, mdldef$endo_names)
      fit_info$old_instruments_idx <- match(fit_info$old_instruments, 
                                            mdldef$exo_names)
      fit_info$sigmas_idx <- match(fit_info$sigmas, mdldef$param_names)
    }
    
    ser$mdldef$fit_info <- ser$fit_info
    ser$fit_info <- NULL
  }
  
  
  if (ser$calc == "dll" && ser$os_type != .Platform$OS.type) {
    # TODO: simply recompile the model
    stop("The model functions have been compiled on a different platform")
  }
  
  return(ser)
}