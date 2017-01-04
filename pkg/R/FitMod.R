#' An R6 class for a Dynare model with Fit targets
#' This class is a subclass of a \code{\link{DynMod}} objects. It contains
#' special methods for the fit procedure.
#'
#' @docType class
#' @importFrom R6 R6Class
#' @importFrom Rcpp sourceCpp
#' @useDynLib dynr
#' @importFrom regts start_period
#' @importFrom regts regperiod_range
#' @importFrom regts regts
#' @importFrom tools file_path_sans_ext
#' @export
#' @keywords data
#' @return Object of \code{\link{R6Class}} containing a macro-economic model,
#' @format \code{\link{R6Class}} object.
#'
#' @section Methods:
#' \describe{
#'
#' \item{\code{get_endo_names()}}{Returns the names of the endogenous variables
#' of the model (excluding the residuals and Lagrange multipliers used in the
#' fit procedure).}
#'
#' \item{\code{get_exo_names()}}{Returns the names of the exogenous variables
#' of the model (excluding the fit control variables).}
#'
#' \item{\code{set_fit_targets(data, names = colnames(data))}}{
#' Sets the targets for the fit procedure. \code{data} is a
#' \code{regts} or \code{ts}. With argument \code{names} the names of the
#' timeseries in \code{data} can be specified. This argument
#' is mandatory if \code{data} does not have column names.
#' Only non \code{NA} values are registered as fit target values. 
#' A fit target can be removed by specifying a \code{NA}.}
#'
#' \item{\code{get_fit_targets())}}{Returns the fit targets
#' used in the fit procedure.}
#'
#' \item{\code{get_residuals())}}{Returns the residuals used in the 
#' fit procedure.}
#' 
#' \item{\code{get_lagrange())}}{Returns the Lagrange multipliers
#' used in the fit procedure.}
#'
#' \item{\code{get_exo_data(names, period = self$get_data_period()}}{Returns
#' the exogenous data excluding the control variables of the
#' fit procedure.}
#'
#' \item{\code{get_endo_data(names, period = self$get_data_period()}}{Returns
#' the endogenous data excluding the auxiliary endogenous variables
#'  for the fit procedure (the residuals and the Lagrange multipliers).}
#'
#' }

FitMod <- R6Class("FitMod",
    inherit = DynMod,
    public = list(
        initialize = function(mod_file, bytecode, fit_mod_file) {
            if (missing(fit_mod_file)) {
                fit_mod_file <- tempfile()
            }
            private$fit_info <- create_fitmod(mod_file, fit_mod_file)
            super$initialize(fit_mod_file, bytecode)
            unlink(fit_mod_file)
        }, 
        print = function(short = TRUE) {
            cat("FitMod object\n")
            cat("Information about the original model:\n")
            exo_count_orig  <- length(private$fit_info$orig_exos)
            endo_count_orig <- length(private$fit_info$orig_endos)
            cat(sprintf("%-60s%d\n", "Number of endogenous variables:",
                        endo_count_orig))
            cat(sprintf("%-60s%d\n", "Number of exogenous variables:",
                        exo_count_orig))
            # TODO: print maximum and minimum lags / leads of the original
            # model
            cat("Information about the expanded model for the fit procedure:\n")
            private$print_info(short)
            return (invisible(NULL))
        },
        get_endo_names = function() {
            return (private$fit_info$orig_endos)
        },
        get_exo_names = function() {
            return (private$fit_info$orig_exos)
        },
        set_fit_targets = function(data, names = colnames(data)) {
            names <- intersect(names, private$fit_info$orig_endos)

            data <- data[private$model_period, names]

            # update endogenous variables
            super$set_data_(data, names, missing(names), type = "endo",
                            update_mode = "updval")

            cols <- which(private$fit_info$orig_endos %in% names)
    
            # set exogenous variables
            super$set_data_(data, private$fit_info$exo_vars[cols], FALSE,
                            type = "exo", update_mode = "updval")

            # create fit vars
            data[] <- ifelse(is.na(data), 0, 1)
            super$set_data_(data, private$fit_info$fit_vars[cols], FALSE, 
                            type = "exo")
        },
        get_endo_data = function(names = private$fit_info$orig_endos, 
                                 period = private$data_period) {
            if (! missing(names)) {
                names <- intersect(names, private$fit_info$orig_endos)
            }
            return (private$endo_data[period, names, drop = FALSE])
        },
        get_fit_targets = function() {
            fit_vars <- private$exo_data[private$model_period, private$fit_info$fit_vars]
            fit_exos <- private$exo_data[private$model_period, private$fit_info$exo_vars]
            rows <- !apply(fit_vars == 0, 1, all)
            if (!any(rows)) {
                # no fit targets
                return (NULL)
            }
            rowsel <- min(which(rows)) : max(which(rows))
            cols <- !apply(fit_vars == 0, 2, all)
            fit_vars <- fit_vars[rowsel, cols]
            fit_exos <- fit_exos[rowsel, cols]
            fit_exos <- ifelse(fit_vars == 1, fit_exos, NA)
            ps <- start_period(private$model_period) + min(which(rows)) - 1
            return (regts(fit_exos, start = ps))
        },
        get_residuals = function(names = private$fit_info$residuals, 
                                 period = private$model_period) {
            if (!missing(names)) {
                names <- intersect(names, private$fit_info$residuals)
            }
            return (private$endo_data[period, names, drop = FALSE])
        },
        get_lagrange = function(names = private$fit_info$l_vars,
                                period = private$model_period) {
            if (! missing(names)) {
                names <- intersect(names, private$fit_info$l_vars)
            }
            return (private$endo_data[period, names, drop = FALSE])
        },
        get_exo_data = function(names = private$fit_info$orig_exos, 
                                period = private$data_period) {
            if (!missing(names)) {
                names <- intersect(names, private$fit_info$orig_exos)
            }
            return (private$exo_data[period, names, drop = FALSE])
        }
    ), 
    private = list(
        fit_info = NULL
    )
)
