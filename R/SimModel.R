#' "regperiod_range" class
#' $name regperiod_range-class
#' $exportClass regperiod_range
#' $importFrom methods setOldClass
setOldClass("regperiod_range")

#' "regts" class
#' $name regts-class
#' $exportClass regts
setOldClass("regts")

#' An R6 class for running simulations with the stacked-time Newton method
#'
#' @docType class
#' @importFrom R6 R6Class
#' @export
#' @field endo_count the number of endogenous variables
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
#' @importFrom regts start_period
#' @importFrom regts end_period
#' @importFrom regts as.regperiod_range
#' @importFrom regts lensub
#' @importFrom regts regts
#' @importFrom methods new
#' @importFrom methods as
#' @importFrom Matrix Matrix
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

        # functions

        initialize = function(mod_file, bytecode) {

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
                self$endos              <- endos
                self$exos               <- exos
                self$params             <- params
                self$max_endo_lag       <- dynamic_model$max_endo_lag
                self$max_endo_lead      <- dynamic_model$max_endo_lead
                self$max_exo_lag        <- dynamic_model$max_exo_lag
                self$max_exo_lead       <- dynamic_model$max_exo_lead
                self$lead_lag_incidence <- dynamic_model$lead_lag_incidence
            })
        },

        solve_steady = function() {
            f <- function(x) {
                return (self$f_static(x, self$exos, self$params))
            }
            jac <- function(x) {
                return (self$f_static(x, self$exos, self$params, jac = TRUE))
            }
            # todo: print output / give error if the commamd was not
            # succesfuill
            out <- nleqslv::nleqslv(self$endos, fn = f, jac = jac)
            self$endos <- out$x
            return (invisible(self))
        },

        set_period = function(period) {
            period <- as.regperiod_range(period)
            self$model_period <-  period
            self$endo_period <- regperiod_range(
                start_period(period) - self$max_endo_lag,
                end_period(period) + self$max_endo_lead)
            self$exo_period <- regperiod_range(
                start_period(period) - self$max_exo_lag,
                end_period(period) + self$max_exo_lead)

            nper <- lensub(self$endo_period)
            endo_mat <- matrix(rep(self$endos, each = nper), nrow = nper)
            self$endo_data <- regts(endo_mat, start = start_period(self$endo_period),
                                   names = names(self$endos))
            if (self$exo_count > 0) {
                nper <- lensub(self$exo_period)
                exo_mat <- matrix(rep(self$exos, each = nper), nrow = nper)
                self$exo_data <- regts(exo_mat, start = start_period(self$exo_period),
                                      names = names(self$exos))
            }
            return (invisible(self))
        },

        solve = function(solver = c("sparse_newton", "nleqslv"), numjac = FALSE,
                         ...) {
            solver <- match.arg(solver)
            lags <- private$get_lags()
            leads <- private$get_leads()
            nper <- lensub(self$model_period)
            x <- private$get_solve_endo()
            if (solver == "sparse_newton") {
                return (private$solve_sparse_newton(x, lags, leads, nper,
                                                    numjac, ...))
            } else if (solver == "nleqslv") {
                return (private$solve_nleqslv(x, lags, leads, nper,
                                              numjac, ...))
            }

        }
    ),

    private = list(
        get_lags = function() {
            lag_per <- regperiod_range(start_period(self$endo_period),
                                       start_period(self$model_period) - 1)
            return (as.numeric(t(self$endo_data[lag_per, ])))
        },
        get_leads = function() {
            lead_per <- regperiod_range(end_period(self$model_period) + 1,
                                        end_period(self$endo_period))
            return (as.numeric(t(self$endo_data[lead_per, ])))
        },
        # returns a vector with endogenous variables in the solution period
        get_solve_endo = function() {
            return (as.numeric(t(self$endo_data[self$model_period, ])))
        },
        # returns the residual of the stacked-time system
        # x is vector of endogenous variables in the solution period
        get_residuals = function(x, lags, leads, nper) {
            endos <- c(lags, x, leads)
            nper <- lensub(self$model_period)
            return (get_residuals_(endos,
                                   which(self$lead_lag_incidence != 0) - 1,
                                   self$exo_data, self$params,
                                   self$f_dynamic, mdl$endo_count,
                                   nper, self$max_exo_lag))
        },
        get_jac = function(x, lags, leads, nper, sparse = TRUE) {
            endos <- c(private$get_lags(), x, private$get_leads())
            nper <- lensub(self$model_period)
            mat_info <- get_triplet_jac(endos, self$lead_lag_incidence,
                                        self$exo_data, self$params,
                                        self$f_dynamic, mdl$endo_count,
                                        nper, self$max_exo_lag)
            n <- nper * self$endo_count
            jac <- new("dgTMatrix", i = mat_info$rows, j = mat_info$columns,
                       x = mat_info$values, Dim = as.integer(rep(n, 2)))

            if (sparse) {
                jac <- as(jac, "dgCMatrix")
            } else {
                jac <- as(jac, "matrix")
            }
            return (jac)
        },
        solve_sparse_newton = function(x, lags, leads, nper, numjac,
                                        control = list()) {

            control_ <- list(ftol = 1e-8, maxiter = 20, trace = FALSE)
            control_[names(control)] <- control

            solved <- FALSE
            for (iter in 0:control_$maxiter) {
                res <- private$get_residuals(x, lags, leads, nper)
                err <- max(abs(res))
                if (control_$trace) {
                    cat(sprintf("Iteration: %d Largest |f| %g\n", iter, err))
                }
                if (err < control_$ftol) {
                    solved <- TRUE
                    break
                } else {
                    jac <- private$get_jac(x, lags, leads, nper)
                    ret <- Matrix::solve(jac, res)
                    x <- x - as.numeric(ret)
                }
            }

            # TODO: line searching?

            self$solve_out <- list(solved = solved, iter = iter, residual = res)
            self$endo_data[self$model_period, ] <- t(matrix(x, nrow = self$endo_count))

            return (invisible(self))
        },
        solve_nleqslv = function(x, lags, leads, nper, numjac, ...) {
            if (!numjac) {
                jacfun <- function(...) {
                    return (private$get_jac(...,  sparse = FALSE))
                }
            } else {
                jacfun <- NULL
            }
            self$solve_out <- nleqslv::nleqslv(x, fn = private$get_residuals,
                                              jac = jacfun, lags = lags,
                                              leads = leads, nper = nper,
                                              ...)
            self$endo_data[self$model_period, ] <- t(matrix(self$solve_out$x,
                                                          nrow = self$endo_count))
            return (invisible(self))
        }
    )

)
