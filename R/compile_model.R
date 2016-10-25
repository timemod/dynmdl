#' Compile a Dynare model and return a \code{\link{SimModel}}
#'
#' @param mod_file the name of the model file (including extension .mod)
#' @return an \code{SimModel} object
#' @export
#' @importFrom Rcpp sourceCpp
#' @useDynLib dynr
compile_model <- function(mod_file) {
    model_info <- compile_model_(mod_file)

    f_static <- function(y, x, params, jac = FALSE) {}
    body(f_static) <- parse(text = paste0("{",
                                    model_info$static_function_body, "}"))

    f_dynamic <- function(y, x, params, it_, jac = FALSE) {}
    body(f_dynamic) <- parse(text = paste0("{",
                    model_info$dynamic_model$dynamic_function_body, "}"))

    exo_count <- length(model_info$exos)
    endo_count <- length(model_info$endos)
    return (with(model_info, {
        methods::new("SimModel", exo_count = exo_count,
                              endo_count = endo_count,
                              exos = exos,
                              endos = endos,
                              params = params,
                              max_endo_lag  = dynamic_model$max_endo_lag,
                              max_endo_lead = dynamic_model$max_endo_lead,
                              max_exo_lag   = dynamic_model$max_exo_lag,
                              max_exo_lead  = dynamic_model$max_exo_lead,
                              lead_lag_incidence = dynamic_model$lead_lag_incidence,
                              f_static = f_static,
                              f_dynamic = f_dynamic)

    }))
}
