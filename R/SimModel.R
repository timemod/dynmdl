#' "regperiod_range" class
#' @name regperiod_range-class
#' @exportClass regperiod_range
#' @importFrom methods setOldClass
setOldClass("regperiod_range")

#' "regts" class
#' @name regts-class
#' @exportClass regts
setOldClass("regts")

#' @importFrom methods setClassUnion
#' @exportClass regperiod_range_or_NULL
#' @exportClass regts_or_NULL
#' @exportClass list_or_NULL
setClassUnion("regperiod_range_or_NULL", c("NULL", "regperiod_range"))
setClassUnion("regts_or_NULL", c("NULL", "regts"))
setClassUnion("list_or_NULL", c("NULL", "list"))

#' An S4 class for running simulations with the stacked-time Newton method
#'
#' @export
#' @slot exo_count the number of exogeneous variables
#' @slot endo_count the number of endogenous variables
#' @slot exos the names and initial values of the exogenous variables
#' @slot endos the names and initial values of the endogenous variables
#' @slot params the names and values of the parameters
#' @slot max_endo_lag   maximum lag for endogenous variables
#' @slot max_endo_lead   maximum lead for endogenous variables
#' @slot max_exo_lag   maximum lag for exogenous variables
#' @slot max_exo_lead   maximum lead for exogenous variables
#' @slot lead_lag_incidence see documentation Dynare
#' @slot f_static function for the residuals and Jacobian for the static version
#' of the model
#' @slot f_dynamic function for the residuals and Jacobian for the dynamic version
#' of the model
#' @slot model_period the model period as a \code{\link[regts]{regperiod_range}}
#' @slot endo_period the data period for the endogenous variables
#' @slot exo_period the data period for the exogenous variables
#' @slot endo_data a \code{\link[regts]{regts}} with the values of the
#' endogenous variables
#' @slot exo_data a \code{\link[regts]{regts}} with the values of the
#' exogenous variables
#' @slot solve_out the output of the solver (e.g. \code{\link[nleqslv]{nleqslv}}
#' used to solve the model
#' @importFrom methods new
SimModel <- setClass("SimModel",
    representation = representation(exo_count = "numeric",
                                    endo_count = "numeric",
                                    exos = "numeric",
                                    endos = "numeric",
                                    params = "numeric",
                                    max_endo_lag = "numeric",
                                    max_endo_lead = "numeric",
                                    max_exo_lag = "numeric",
                                    max_exo_lead = "numeric",
                                    lead_lag_incidence = "matrix",
                                    f_static = "function",
                                    f_dynamic = "function",
                                    model_period = "regperiod_range_or_NULL",
                                    endo_period = "regperiod_range_or_NULL",
                                    exo_period = "regperiod_range_or_NULL",
                                    endo_data = "regts_or_NULL",
                                    exo_data = "regts_or_NULL",
                                    solve_out = "list_or_NULL"),

    # Set the default values for the slots. (optional)
    prototype=list(
        model_period = NULL,
        endo_period  = NULL,
        exo_period   = NULL,
        endo_data    = NULL,
        exo_data     = NULL,
        solve_out    = NULL
    )
)
