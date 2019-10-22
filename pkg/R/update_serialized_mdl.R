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
    
    mdldef <- install_name_admin(mdldef, ser$fit_info)
    mdldef <- install_laglead_admin(mdldef)
    
    # prior to version 1.0, the set$equation contained the original
    # equations.
    mdldef$equations_orig <- ser$equations
    mdldef["equations"] <- list(NULL)
    
    #
    # information about fit
    #
    if (mdldef$fit) {
      mdldef$fit_info <- install_fit_indices(ser$fit_info, mdldef)
    } else {
      mdldef$fit_info <- NULL
    }
    
    ser$mdldef <- mdldef
   
    # remove fields that do no longer exist
    ser$fit_info <- NULL
    ser$equations  <- NULL
    ser$njac_cols <- NULL
  }
  
  
 
  
  return(ser)
}