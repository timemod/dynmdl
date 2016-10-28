#' "regperiod_range" class
#' @name regperiod_range-class
#' @exportClass regperiod_range
#' @importFrom methods setOldClass
setOldClass("regperiod_range")

#' "regts" class
#' @name regts-class
#' @exportClass regts
setOldClass("regts")

#' An R6 class for running simulations with the stacked-time Newton method
#'
#' @docType class
#' @importFrom R6 R6Class
#' @export
#' @field exo_count the number of exogeneous variables
#' @field endo_count the number of endogenous variables
#' @field exos the names and initial values of the exogenous variables
#' @field endos the names and initial values of the endogenous variables
#' @field params the names and values of the parameters
#' @field max_endo_lag   maximum lag for endogenous variables
#' @field max_endo_lead   maximum lead for endogenous variables
#' @field max_exo_lag   maximum lag for exogenous variables
#' @field max_exo_lead   maximum lead for exogenous variables
#' @field lead_lag_incidence see documentation Dynare
#' of the model
#' @field f_dynamic function for the residuals and Jacobian for the dynamic version
#' of the model
#' @field model_period the model period as a \code{\link[regts]{regperiod_range}}
#' @field endo_period the data period for the endogenous variables
#' @field exo_period the data period for the exogenous variables
#' @field endo_data a \code{\link[regts]{regts}} with the values of the
#' endogenous variables
#' @field exo_data a \code{\link[regts]{regts}} with the values of the
#' exogenous variables
#' @field solve_out the output of the solver (e.g. \code{\link[nleqslv]{nleqslv}}
#' used to solve the model
#' @importFrom Rcpp sourceCpp
#' @useDynLib dynr
SimModel <- R6Class("SimModel",
    public = list(
        exo_count = NA_integer_,
        endo_count = NA_integer_,
        exos = NULL,
        endos = NULL,
        params = NULL,
        max_endo_lag = NA_integer_,
        max_endo_lead = NA_integer_,
        max_exo_lag =  NA_integer_,
        max_exo_lead =  NA_integer_,
        lead_lag_incidence = NULL,
        f_static = NULL,
        f_dynamic = NULL,
        model_period = NULL,
        endo_period =  NULL,
        exo_period = NULL,
        endo_data = NULL,
        exo_data = NULL,
        solve_out = NULL,

        initialize = function(mod_file) {

            model_info <- compile_model_(mod_file)

            self$f_static <- function(y, x, params, jac = FALSE) {}
            body(self$f_static) <- parse(text = paste0("{",
                                model_info$static_function_body, "}"))

            self$f_dynamic <- function(y, x, params, it_, jac = FALSE) {}
            body(self$f_dynamic) <- parse(text = paste0("{",
                        model_info$dynamic_model$dynamic_function_body, "}"))

            if (bytecode) {
                self$f_static <- compiler::cmpfun(self$f_static)
                self$f_dynamic <- compiler::cmpfun(self$f_dynamic)
            }
            self$exo_count <- length(model_info$exos)
            self$endo_count <- length(model_info$endos)
            with(model_info, {
                self$params             <- params
                self$max_endo_lag       <- endo_lag
                self$max_endo_lag       <- dynamic_model$max_endo_lag
                self$max_endo_lead      <- dynamic_model$max_endo_lead
                self$max_exo_lag        <- dynamic_model$max_exo_lag
                self$max_exo_lead       <- dynamic_model$max_exo_lead
                self$lead_lag_incidence <- dynamic_model$lead_lag_incidence
            })
        }
    )
)
