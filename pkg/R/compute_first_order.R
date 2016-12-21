#' Computes the first order conditions of a model file
#'
#' @param mod_file the filename of the mod file
#' @return the derivative matrix
#' @export
compute_first_order <- function(mod_file) {
    model_info <- compute_derivatives(mod_file)
    print(model_info)

    with(model_info, {
        # a problem will occur if the fit instruments occur with 
        # lags or leads. When computing derivatives with respect to the
        # exogenous variables, the dynare preprocessor ignores 
        # leads and leads. For other variables a lag or lead > 1
        # would not result in an error
        # TODO: maybe we could search for lags and leads of fit instruments
        # in tbe mod file, and given an error only if the fit instruments
        # occur with this leads.
        if (dynamic_model$max_exo_lag > 0 ||  dynamic_model$max_exo_lead > 1) {
            stop("compute_first_order cannot handle exogenous lags and leads > 0")
        }
    })
    lli <- model_info$dynamic_model$lead_lag_incidence
    sel <- lli != 0
    rows <- row(lli)[sel]
    cols <- col(lli)[sel]
    endo_lags <- cols - model_info$dynamic_model$max_endo_lag - 1
    endo_names <- model_info$endo_names[rows]
    endo_deriv <- model_info$dynamic_model$derivatives[, 1:length(endo_names)]
    colnames(endo_deriv) <- paste0(endo_names, paste0("(", endo_lags, ")"))

    exo_deriv <- model_info$dynamic_model$derivatives[, -(1:length(endo_names))]
    colnames(exo_deriv) <- model_info$exo_names
    printobj(endo_deriv)
    printobj(exo_deriv)
    return (endo_deriv)
}
