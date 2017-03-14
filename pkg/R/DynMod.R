#' @importFrom methods setOldClass
setOldClass("regperiod_range")
setOldClass("regts")

#' An R6 class for a Dynare model
#'
#' @docType class
#' @importFrom R6 R6Class
#' @importFrom Rcpp sourceCpp
#' @useDynLib dynmod
#' @importFrom regts start_period
#' @importFrom regts end_period
#' @importFrom regts as.regperiod_range
#' @importFrom regts length_range
#' @importFrom regts regperiod_range
#' @importFrom regts regrange_intersect
#' @importFrom regts regts
#' @importFrom Matrix Matrix
#' @importFrom Matrix sparseMatrix
#' @importFrom nleqslv nleqslv
#' @importFrom umfpackr umf_solve_nl
#' @export
#' @keywords data
#' @return Object of \code{\link{R6Class}} containing a macro-economic model,
#' @format \code{\link{R6Class}} object.
#'
#' @section Methods:
#' \describe{
#'
#' \item{\code{get_endo_names()}}{Returns the names of the endogenous variables.}
#
#' \item{\code{get_exo_names()}}{Returns the names of the exogenous variables.}
#'
#' \item{\code{get_param_names()}}{Returns the names of the parameters.}
#'
#' \item{\code{set_params()}}{Sets the parameters of the model.}
#'
#' \item{\code{get_params()}}{Returns the parameters of the model.}
#'
#' \item{\code{set_static_exos(exos)}}{Sets the static values of
#' the exogenous variables. These values are used to compute the steady state.}
#'
#' \item{\code{get_static_exos()}}{Returns the static values of
#' the exogenous variables}
#'
#' \item{\code{set_static_endos(endos)}}{Sets the static values of
#' the endos variables. These values are used to compute the steady state.}
#'
#' \item{\code{get_static_endos()}}{Returns the static values of
#' the endogenous variables, i.e. the values that are supposed to be
#' the steady state values. Function \code{solve_steady} can be used
#' to compute them. After compiling the model, the
#' static endos are initialized with zeros and the values in the \code{initval}
#' block in the  \code{mod} file. There is no setter for the static values:
#' you can only modify them by calling function \code{solve_steady}}
#'
#' \item{\code{set_period(period)}}{Sets the model period. \code{period}
#' is a \code{\link{regperiod_range}} object or an object that can be coerced
#' to a \code{regperiod_range}. The model period is the longest period for which
#' the model may be solved. This method also allocates storage for
#' all model timeseries.  Model timeseries are
#' available for the so called 'model data period', which is
#' the model period extended with a lag and lead period. This method
#' also initialises all model timeseries with static values
#' of the exogenous and endogenous model variables.}
#'
#' \item{\code{get_period()}}{Returns the model period}
#'
#' \item{\code{get_data_period()}}{Returns the data period, i.e. the model period
#'  extended with the lag end lead period}
#'
#' \item{\code{get_lag_period()}}{Returns the lag period}
#'
#' \item{\code{get_lead_period()}}{Returns the lead period}
#'
#' \item{\code{set_exo_data(data, names = colnames(data), update_mode = c("update", "updval"))}}{
#' Sets the values of the exogenous variables. \code{data} is a
#' \code{regts} or \code{ts}. With argument \code{names} the names of the
#' timeseries in \code{data} can be specified. This argument
#' is mandatary if \code{data} does not have column names.
#' If \code{update_mode} is
#' \code{"updval"}, then the values are only replaced by non NA values in
#' \code{data}}
#'
#' \item{\code{set_exo_values(value, names = NULL, period = self$get_data_period())}}{Sets the value(s)
#' of one more exogenous variables. \code{value} can be any R object
#' that can be coerced to a numeric. \code{period} is the period
#' for which endogenous variable is modified. If argument \code{period}
#' is missing the exo period is used.}
#'
#' \item{\code{get_exo_data(names, period = self$get_data_period()}}{
#' Returns the exogenous data.
#' \code{pattern} is a regular expression,  \code{names} a list of variables
#'  and \code{period} an \code{\link[regts]{regperiod_range}} object
#'  or an object that can be coerced to \code{regperiod_range}.}

#'
#' \item{\code{set_endo_data(data, names = colnames(data), update_mode = c("update", "updval"))}}{
#' Sets the values of the endogenous variables. \code{data} is a
#' \code{regts} or \code{ts}. With argument \code{names} the names of the
#' timeseries in \code{data} can be specified. This argument
#' is mandatary if \code{data} does not have column names.
#' If \code{update_mode} is
#' \code{"updval"}, then the values are only replaced by non NA values in
#' \code{data}}
#'
#' \item{\code{set_endo_values(value, names = NULL,  period = self$get_data_period())}}{
#' Sets the value(s) of one more endogenous variables. \code{value} can be any R object
#' that can be coerced to a numeric. \code{period} is the period
#' for which endogenous variable is modified. If argument \code{period}
#' is missing then the data period is used.}
#'
#' \item{\code{set_data(data, names, update_mode = c("update", "updval"))}}{
#' Sets the values of the all model variables (both endogenous and exogenouys).
#' \code{data} is a
#' \code{regts} or \code{ts}. With argument \code{names} the names of the
#' timeseries in \code{data} can be specified. This argument
#' is mandatary if \code{data} does not have column names.
#' If \code{update_mode} is
#' \code{"updval"}, then the values are only replaced by non NA values in
#' \code{data}}
#'
#' \item{\code{get_endo_data(pattern, names, period = self$get_data_period()}}{
#' Returns the endogenous data.
#' \code{pattern} is a regular expression,  \code{names} a list of variables
#'  and \code{period} an \code{\link[regts]{regperiod_range}} object
#'  or an object that can be coerced to \code{regperiod_range}.}

#'
#' \item{\code{solve_steady(start = self$get_static_endos(), init_data = TRUE,
#' control = NULL)}}{
#' Solve the steady state of the model.
#' This methods solves the steady state problem. Argument \code{start}
#' can be used to specify an initial guess for the steady state values.
#' By default, the initial guess is either based on the \code{initval}
#' block of the mode file or the result of a previous call of \code{solve_steady}.
#' If \code{init_data} is true, then the computed steady state values
#' are used to initialise the endogenous model variables
#' \code{control} is a list of control options passed to
#' \code{\link[nleqslv]{nleqslv}}.}
#'
#' \item{\code{check()}}{Compute the eigenvalues of the linear
#' system and check if the Blachard and Kahn conditions are satisfied.}
#'
#' \item{\code{solve(control = list())}}{Solves the model using a stacked-time
#' Newton method for the whole model period.
#' Argument \code{control} is a list with solve options (TODO: describe these
#' options somewhere).}
#'
#' \item{\code{solve_perturbation()}}{Solves the model using the perturbation
#' theory used in the Dynare function stoch_simul. Only shocks in the first
#' solution period are allowed.}
#'
#' \item{\code{get_jacob(sparse = TRUE)}}{Returns the Jacobian for the
#' stacked-time Newton problem either as a sparse matrix
#' (a \code{\link[Matrix]{Matrix}} object) or normal \code{\link{matrix}}.}
#'
#' \item{\code{get_eigval(}}{Returns the eigenvalues of the linearized model.
#' computed with functiomn \code{check()} of \code{solve_perturbation()},
#' ordered with increasing absolute value}
#'
#' }

DynMod <- R6Class("DynMod",
    public = list(
        initialize = function(mod_file, bytecode, use_dll, dll_dir) {

            model_info <- compile_model_(mod_file, use_dll, dll_dir)

            private$use_dll <- use_dll

            with(model_info, {
                private$endo_names         <- names(endos)
                private$exo_names          <- names(exos)
                private$param_names        <- names(params)
                private$endos              <- endos
                private$exos               <- exos
                private$params             <- params
                private$max_endo_lag       <- dynamic_model$max_endo_lag
                private$max_endo_lead      <- dynamic_model$max_endo_lead
                private$max_exo_lag        <- dynamic_model$max_exo_lag
                private$max_exo_lead       <- dynamic_model$max_exo_lead
                private$lead_lag_incidence <- dynamic_model$lead_lag_incidence
                private$jac_dynamic_size   <- dynamic_model$jac_size
            })

            private$exo_count  <- length(private$exos)
            private$endo_count <- length(private$endo_names)
            private$max_lag    <- max(private$max_endo_lag,  private$max_exo_lag)
            private$max_lead   <- max(private$max_endo_lead, private$max_exo_lead)

            # add column names and row names to the lead lag incidence matrix
            colnames(private$lead_lag_incidence) <- as.character(
                   -private$max_endo_lag : private$max_endo_lead)
            rownames(private$lead_lag_incidence) <- names(model_info$endos)

            private$njac_cols <- length(which(private$lead_lag_incidence != 0)) +
                                        private$exo_count

            if (use_dll) {
                private$dll_file <- compile_c_functions (dll_dir)
                private$f_static <- function(y, x, params) {
                    res <- numeric(private$endo_count)
                    .Call("f_static_", y, x, params, res)
                    return(res)
                }
                private$jac_static <- function(y, x, params) {
                    # NOTE: creating a new jac_steady every function call is
                    # inefficient, therefore use private$jac_static that is
                    # created just before solve_steady is called.
                    .Call("jac_static_", y, x, params, private$jac_steady)
                    return(private$jac_steady)
                }
                private$f_dynamic <- function(y, x, params, it) {
                    res <- numeric(private$endo_count)
                    .Call("f_dynamic_", y, x, params, it - 1, private$nrow_exo,
                          res)
                    return(res)
                }
                private$jac_dynamic <- function(y, x, params, it) {
                    # NOTE: creating a new jac every function call is
                    # inefficient, therefore use private$jac that is
                    # created just before solve is called.
                    .Call("jac_dynamic_", y, x, params, it - 1, private$nrow_exo,
                       private$jac$rows, private$jac$cols, private$jac$values)
                    return(private$jac)
                }
            } else {
                eval(parse(text = model_info$static_functions))
                eval(parse(text = model_info$dynamic_model$dynamic_functions))
                private$f_static    <- f_static
                private$jac_static  <- jac_static
                private$f_dynamic   <- f_dynamic
                private$jac_dynamic <- jac_dynamic

                if (bytecode) {
                    private$f_static <- compiler::cmpfun(private$f_static)
                    private$f_dynamic <- compiler::cmpfun(private$f_dynamic)
                }
            }
        },
        print = function(short = TRUE) {
            cat("DynMod object\n")
            private$print_info(short)
            return (invisible(NULL))
        },
        get_endo_names = function() {
            return (private$endo_names)
        },
        get_exo_names = function() {
            return (private$exo_names)
        },
        get_param_names = function() {
            return (private$param_names)
        },
        set_params = function(params) {
            private$params[names(params)] <- params
            return (invisible(self))
        },
        get_params = function(names = NULL) {
            if (missing(names)) {
                return (private$params)
            } else {
                return (private$params[names])
            }
        },
        set_static_exos = function(exos) {
            private$exos[names(exos)] <- exos
            return (invisible(self))
        },
        get_static_exos = function() {
            return (private$exos)
        },
        set_static_endos = function(endos) {
            private$endos[names(endos)] <- endos
            return (invisible(self))
        },
        get_static_endos = function() {
            return (private$endos)
        },
        set_period = function(period) {
            period <- as.regperiod_range(period)
            private$model_period <-  period
            private$data_period <- regperiod_range(
                                       start_period(period) - private$max_lag,
                                       end_period(period) + private$max_lead)
            nper <- length_range(private$data_period)
            endo_mat <- matrix(rep(private$endos, each = nper), nrow = nper)
            private$endo_data <- regts(endo_mat,
                                       start = start_period(private$data_period),
                                       names = names(private$endos))
            if (private$exo_count > 0) {
                exo_mat <- matrix(rep(private$exos, each = nper), nrow = nper)
                private$exo_data <- regts(exo_mat,
                                          start = start_period(private$data_period),
                                          names = names(private$exos))
            }
            return (invisible(self))
        },
        get_period = function() {
            return (private$model_period)
        },
        get_data_period = function() {
            return (private$data_period)
        },
        get_lag_period = function() {
            if (private$max_lag > 0) {
                p <- start_period(private$data_period)
                return (regperiod_range(p, p + private$max_lag - 1))
            } else {
                return (NULL)
            }
        },
        get_lead_period = function() {
            if (private$max_lead > 0) {
                p <- end_period(private$data_period)
                return (regperiod_range(p - private$max_lead + 1, p))
            } else {
                return (NULL)
            }
        },
        set_exo_data = function(data, names = colnames(data),
                                update_mode = "update") {
            return (private$set_data_(data, names, names_missing = missing(names),
                              type = "exo", update_mode = update_mode))
        },
        set_exo_values = function(value, names = private$exo_names,
                                  period = private$data_period) {
            names <- intersect(names, private$exo_names)
            if (!missing(period)) {
                period <- as.regperiod_range(period)
                per <- regrange_intersect(period, private$data_period)
            } else {
                per <- period
            }
            private$exo_data[period, names] <- value
            return (invisible(self))
        },
        get_exo_data = function(pattern, names, period = private$data_period) {
            if (missing(pattern) && missing(names)) {
                return (private$exo_data[period, ])
            } else {
                if (missing(names)) {
                    names <- grep(pattern, private$exo_names)
                } else {
                    names <- intersect(names, private$exo_names)
                    if (!missing(pattern)) {
                        names <- union(names, grep(pattern, private$exo_names))
                    }
                }
                return (private$exo_data[period, names, drop = FALSE])
            }
        },
        set_endo_data = function(data, names = colnames(data), update_mode = "update") {
            return (private$set_data_(data, names, names_missing = missing(names),
                              type = "endo", update_mode = update_mode))
        },
        set_endo_values = function(value, names = private$endo_names,
                                   period = private$data_period) {
            names <- intersect(names, private$endo_names)
            if (!missing(period)) {
                period <- as.regperiod_range(period)
                per <- regrange_intersect(period, private$data_period)
            } else {
                per <- period
            }
            private$endo_data[period, names] <- value
            return (invisible(self))
        },
        set_data = function(data, names = colnames(data), update_mode = "update")  {
            private$set_data_(data, names, names_missing = missing(names),
                              type = "exo", update_mode = update_mode)
            private$set_data_(data, names, names_missing = missing(names),
                              type = "endo", update_mode = update_mode)
            return (invisible(self))
        },
        get_endo_data = function(pattern, names, period = private$data_period) {
            if (missing(pattern) && missing(names)) {
                return (private$endo_data[period, ])
            } else {
                if (missing(names)) {
                    names <- grep(pattern, private$endo_names)
                } else {
                    names <- intersect(names, private$endo_names)
                    if (!missing(pattern)) {
                        names <- union(names, grep(pattern, private$endo_names))
                    }
                }
                return (private$endo_data[period, names, drop = FALSE])
            }
        },
        solve_steady = function(start = self$get_static_endos(),
                                init_data = TRUE, control = NULL) {


            f <- function(endos) {
                return(private$f_static(endos, private$exos, private$params))
            }
            jac <- function(endos) {
                return(private$jac_static(endos, private$exos, private$params))
            }

            if (private$use_dll) private$prepare_solve_steady()
            # ToDO: use umfpackr?
            out <- nleqslv(start, fn = f, jac = jac, method = "Newton",
                           control = control)
            if (private$use_dll) private$clean_after_solve_steady()

            if (out$termcd != 1) {
                stop(paste("Error solving the steady state.\n",
                           out$message))
            }

            private$endos <- out$x
            if (init_data && !is.null(private$endo_data)) {
                # update the model data
                nper <- length_range(private$data_period)
                private$endo_data[ , ] <- matrix(rep(private$endos, each = nper),
                                                nrow = nper)
            }


            return (invisible(self))
        },
        check = function() {

            self$solve_steady(init_data = FALSE)

            if (private$use_dll) private$prepare_solve()
            private$ss  <- solve_first_order(private$ss,
                                             private$lead_lag_incidence,
                                             private$exos, private$endos,
                                             private$params,
                                             private$jac_dynamic,
                                             private$endo_count,
                                             private$njac_cols,
                                             only_eigval = TRUE, debug = FALSE)
            cat("EIGENVALUES:\n")
            cat(sprintf("%16s%16s%16s\n", "Modulus", "Real", "Imaginary"))
            for (eigv in private$ss$eigval) {
                cat(sprintf("%16g%16g%16g\n", Mod(eigv), Re(eigv), Im(eigv)))
            }
            cat("\n")
            if (private$use_dll) private$clean_after_solve()
            return (invisible(self))
        },
        solve = function(control = list(), force_stacked_time = FALSE,
                         solver = c("umfpackr", "nleqslv")) {

            solver <- match.arg(solver)
            control_ <- list(ftol = 1e-8, maxiter = 20, trace = FALSE,
                             cndtol = 1e-12, silent = FALSE)
            control_[names(control)] <- control

            if (private$use_dll) private$prepare_solve()

            if (private$max_endo_lead > 0 || force_stacked_time ) {
                # preparations
                if (solver != "umfpackr") {
                    stop(paste("For forward looking models only the umfpackr",
                               "solver is allowed"))
                }
                nper <- length_range(private$model_period)
                lags <- private$get_lags()
                leads <- private$get_leads()
                x <- private$get_solve_endo()
                ret <- umf_solve_nl(x, private$get_residuals,
                                    private$get_jac, lags = lags,
                                    leads = leads, nper = nper,
                                   control = control_)
                if (!control_$silent) {
                    cat(sprintf("Total time function eval. : %g\n", ret$t_f))
                    cat(sprintf("Total time Jacobian.      : %g\n", ret$t_jac))
                    cat(sprintf("Total time LU fact.       : %g\n", ret$t_lu))
                    cat(sprintf("Total time solve          : %g\n", ret$t_solve))
                }
            } else {
                ret <- solve_backward_model(private$model_period,
                                            private$endo_data,
                                            private$exo_data, private$params,
                                            private$lead_lag_incidence,
                                            private$njac_cols,
                                            private$f_dynamic,
                                            private$jac_dynamic,
                                            control = control_,
                                            solver = solver)
            }

            if (private$use_dll) private$clean_after_solve()
            private$endo_data[private$model_period, ] <-
                    t(matrix(ret$x, nrow = private$endo_count))


            self$solve_out <- ret
            return (invisible(self))
        },
        solve_perturbation = function() {

            self$solve_steady(init_data = FALSE)

            if (private$use_dll) private$prepare_solve()

            # solve_perturbation does not works for exogenous lags and leads.
            # For perturbation approaches, Dynare substitutes
            # these lags and leads by creating auxiliary variables and
            # equations. dynmod does not do that.
            if (private$max_exo_lag > 0 || private$max_exo_lead > 0) {
                stop(paste("Method solve_perturbation does not work for models",
                           "with exogenous lags or leads"))
            }

            private$ss <- solve_first_order(private$ss, private$lead_lag_incidence,
                                    private$exos, private$endos,
                                    private$params, private$jac_dynamic,
                                    private$endo_count, private$njac_cols,
                                    only_eigval = FALSE, debug = FALSE)

            private$endo_data <- solve_perturbation_(private$ss,
                                            private$max_endo_lag,
                                            private$exo_data, private$endo_data,
                                            private$exos, private$endos)

            if (private$use_dll) private$clean_after_solve()
            return (invisible(self))
        },
        get_jacob = function(sparse = TRUE) {
            lags  <- private$get_lags()
            leads <- private$get_leads()
            nper <-length_range(private$model_period)
            x <- private$get_solve_endo()
            jac <- private$get_jac(x, lags, leads, nper)
            if (!sparse) {
                jac <- as(jac, "matrix")
            }
            return (jac)
        },
        get_eigval = function() {
            if (!is.null(private$ss) && !is.null(private$ss$eigval)) {
                i <- order(abs(private$ss$eigval))
                return (private$ss$eigval[i])
            } else {
                stop(paste("Eigen values not available. Calculate the eigenvalues",
                           "with method check()."))
            }
        },
        time_functions = function() {
            if (private$use_dll) private$prepare_solve()
            time_functions(private$model_period, private$endo_data,
                           private$exo_data, private$params,
                           private$lead_lag_incidence,
                           private$f_dynamic, private$jac_dynamic)
            self$solve_out <- NULL
            return(invisible(NULL))
        },
        solve_out = NULL
    ),
    private = list(
        exo_count = NA_integer_,
        endo_count = NA_integer_,
        exo_names = NULL,
        endo_names = NULL,
        param_names = NULL,
        exos = NULL,
        endos = NULL,
        params = NULL,
        max_endo_lag = NA_integer_,
        max_endo_lead = NA_integer_,
        max_lead = NA_integer_,
        max_exo_lag =  NA_integer_,
        max_exo_lead =  NA_integer_,
        max_lag  = NA_integer_,
        lead_lag_incidence = NULL,
        njac_cols = NA_integer_,
        f_static = NULL,
        jac_static = NULL,
        f_dynamic = NULL,
        jac_dynamic = NULL,
        jac_dynamic_size = NA_integer_,
        model_period = NULL,
        data_period =  NULL,
        endo_data = NULL,
        exo_data = NULL,
        ss = NULL,
        use_dll = FALSE,
        dll_file = NA_character_,
        period_error_msg = paste("The model period is not set.",
                            "Set the model period with set_period()."),
        nrow_exo = NA_integer_,
        jac = NULL,
        jac_steady = NULL,
        set_data_= function(data, names, names_missing, type = c("endo", "exo"),
                            update_mode = c("update", "updval")) {
            # generic function to set or update the endogenous or exogenous
            # variables

            if (is.null(private$model_period)) stop(private$period_error_msg)
            update_mode <- match.arg(update_mode)

            per <- regrange_intersect(get_regperiod_range(data),
                                      private$data_period)
            if (NCOL(data) == 0) {
                # TODO: warning?
                return (invisible(NULL))
            }
            if (is.null(names)) {
                if (names_missing) {
                    stop(paste("Argument data has no colnames.",
                                "In that case, argument names should be specified"))
                } else {
                    stop("names is null")
                }
            }  else {
                if (length(names) < NCOL(data)) {
                    stop("The length of arument names is less than the number of columns of data")
                }
            }

            if (!is.matrix(data)) {
                dim(data) <- c(length(data), 1)
                colnames(data) <- names
            } else if (!names_missing) {
                colnames(data) <- names
            }

            if (type == "endo") {
                names <- intersect(names, private$endo_names)
            } else  {
                names <- intersect(names, private$exo_names)
            }

            if (update_mode == "update") {
                new_data <- data[per, names]
            } else if (update_mode == "updval") {
                data <- data[per, names, drop = FALSE]
                if (type == "endo") {
                    new_data <- private$endo_data[per, names, drop = FALSE]
                } else {
                    new_data <- private$exo_data[per, names, drop = FALSE]
                }
                sel <- !is.na(data)
                new_data[sel] <- data[sel]
            }
            if (type == "endo") {
                private$endo_data[per, names] <- new_data
            } else {
                private$exo_data[per, names] <- new_data
            }
            return (invisible(self))
        },
        get_lags = function() {
            lag_per <- self$get_lag_period()
            return (t(private$endo_data[lag_per, ]))
        },
        get_leads = function() {
            lead_per <- self$get_lead_period()
            return (t(private$endo_data[lead_per, ]))
        },
        # returns a vector with endogenous variables in the solution period
        get_solve_endo = function() {
            return (t(private$endo_data[private$model_period, ]))
        },
        # returns the residual of the stacked-time system
        # x is vector of endogenous variables in the solution period
        get_residuals = function(x, lags, leads, nper) {
            endos <- c(lags, x, leads)
            nper <- length_range(private$model_period)
            return (get_residuals_(endos,
                                   which(private$lead_lag_incidence != 0) - 1,
                                   private$exo_data, private$params,
                                   private$f_dynamic, private$endo_count,
                                   nper, private$max_lag))
        },
        get_jac = function(x, lags, leads, nper) {
            endos <- c(lags, x, leads)
            nper <- length_range(private$model_period)
            tshift  <- -private$max_endo_lag : private$max_endo_lead
            mat_info <- get_triplet_jac(endos, private$lead_lag_incidence,
                                        tshift, private$exo_data,
                                        private$params, private$jac_dynamic,
                                        private$endo_count, nper,
                                        private$max_lag)
            n <- nper * private$endo_count
            # NOTE: the function sparseMatrix of the Matrix package
            # only works correctly when package methods has been attached.
            # Therefore "methods" is added to Depends in the DESCRIPTION file.
            # Possibly, in the Matrix package one of functions of methods is
            # not imported from.
            return(sparseMatrix(i = mat_info$rows, j = mat_info$columns,
                                x = mat_info$values,
                                dims = as.integer(rep(n, 2))))
        },
        prepare_solve = function() {
            private$nrow_exo <- nrow(private$exo_data)
            private$jac  <- list(rows   = integer(private$jac_dynamic_size),
                                 cols   = integer(private$jac_dynamic_size),
                                 values = numeric(private$jac_dynamic_size))
            dyn.load(private$dll_file)
            return(invisible(NULL))
        },
        clean_after_solve = function() {
            private$nrow_exo <- NULL
            private$jac <- NULL
            dyn.unload(private$dll_file)
            return(invisible(NULL))
        },
        prepare_solve_steady = function() {
            private$jac_steady <- matrix(0, nrow = private$endo_count,
                                         ncol = private$endo_count)
            dyn.load(private$dll_file)
            return(invisible(NULL))
        },
        clean_after_solve_steady = function() {
            private$jac_steady <- NULL
            dyn.unload(private$dll_file)
            return(invisible(NULL))
        },
        print_info = function(short) {
            cat(sprintf("%-60s%d\n", "Number of endogenous variables:",
                        private$endo_count))
            cat(sprintf("%-60s%d\n", "Number of exogenous variables:",
                        private$exo_count))
            cat(sprintf("%-60s%d\n", "Maximum endogenous lead:",
                        private$max_endo_lead))
            cat(sprintf("%-60s%d\n", "Maximum endogenous lag:",
                        private$max_endo_lag))
            cat(sprintf("%-60s%d\n", "Maximum exogenous lead:",
                        private$max_exo_lead))
            cat(sprintf("%-60s%d\n", "Maximum exogenous lag:",
                        private$max_exo_lag))
            cat(sprintf("%-60s%d\n", "Number of nonzeros dyn. jac:",
                        private$jac_dynamic_size))
            if (!is.null(private$model_period)) {
                cat(sprintf("%-60s%s\n", "Model period:",
                            as.character(private$model_period)))
            }
            if (!short) {
                cat("Names of the endogenous variables:\n")
                print(private$endo_names)
                cat("Names of the exogenous variables:\n")
                print(private$exo_names)
                cat("Names of the parameters:\n")
                print(private$param_names)
                cat("Lead lag incidence matrix:\n")
                print(private$lead_lag_incidence)
                cat("\nstatic function:\n")
                print(private$f_static)
                cat("\nstatic Jacobian:\n")
                print(private$jac_static)
                cat("\ndynamic function:\n")
                print(private$f_dynamic)
                cat("\ndynamic jacobian:\n")
                print(private$jac_dynamic)
            }
        }
    )
)
