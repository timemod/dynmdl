#' Computes the first order conditions of a model file
#'
#' @param mod_file the filename of the mod file
#' @return the derivative matrix
#' @export
compute_first_order <- function(mod_file) {
    model_info <- compute_derivatives(mod_file)
    print(model_info)
    
    lli <- model_info$dynamic_model$lead_lag_incidence
    sel <- lli != 0
    rows <- row(lli)[sel]
    cols <- col(lli)[sel]
    lags <- cols - model_info$dynamic_model$max_endo_lag - 1
    names <- model_info$endo_names[rows]
    names <- paste0(names, paste0("(", lags, ")"))

    # add the names of the exogenous variables.
    # TODO: what about exogenous variables with lags/leads?
    names <- c(names, model_info$exo_names)
    derivatives <- model_info$dynamic_model$derivatives
    colnames(derivatives) <- names
    return (derivatives)
}
