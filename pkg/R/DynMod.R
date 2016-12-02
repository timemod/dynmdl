#' @importFrom methods setOldClass
setOldClass("regperiod_range")
setOldClass("regts")

#' An R6 class for a Dynare model
#'
#' @docType class
#' @importFrom R6 R6Class
#' @importFrom Rcpp sourceCpp
#' @useDynLib dynr
#' @importFrom regts start_period
#' @importFrom regts end_period
#' @importFrom regts as.regperiod_range
#' @importFrom regts length_range
#' @importFrom regts regts
#' @importFrom methods new
#' @importFrom methods as
#' @importFrom Matrix Matrix
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
#' Returns the exogenous data}
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
#' \item{\code{get_endo_data(names, period = self$get_data_period()}}{
#' Returns the endgenous data}
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
        initialize = function(mod_file, bytecode) {
            model_info <- compile_model_(mod_file)
            private$f_static <- function(y, x, params, jac = FALSE) {}
            body(private$f_static) <- parse(text = paste0("{",
                                model_info$static_function_body, "}"))

            private$f_dynamic <- function(y, x, params, it_, jac = FALSE) {}
            body(private$f_dynamic) <- parse(text = paste0("{",
                        model_info$dynamic_model$dynamic_function_body, "}"))

            if (bytecode) {
                private$f_static <- compiler::cmpfun(private$f_static)
                private$f_dynamic <- compiler::cmpfun(private$f_dynamic)
            }
            private$exo_count <- length(model_info$exos)
            private$endo_count <- length(model_info$endos)
            with(model_info, {
                private$exo_names <- names(exos)
                private$endo_names <- names(endos)
                private$param_names <- names(params)
                private$endos              <- endos
                private$exos               <- exos
                private$params             <- params
                private$max_endo_lag       <- dynamic_model$max_endo_lag
                private$max_endo_lead      <- dynamic_model$max_endo_lead
                private$max_exo_lag        <- dynamic_model$max_exo_lag
                private$max_exo_lead       <- dynamic_model$max_exo_lead
                private$lead_lag_incidence <- dynamic_model$lead_lag_incidence
                private$nstatic            <- dynamic_model$nstatic
                private$nfwrd              <- dynamic_model$nfwrd
                private$npred              <- dynamic_model$npred
                private$nboth              <- dynamic_model$nboth
            })
            private$ndynamic               <- private$npred + private$nboth +
                                              private$nfwrd
            private$nsfwrd                 <- private$nfwrd + private$nboth
            private$max_lag  <- max(private$max_endo_lag,  private$max_exo_lag)
            private$max_lead <- max(private$max_endo_lead, private$max_exo_lead)

            if (private$max_lag > 1) {
                stop("dynr cannot yet handle models with max. lag > 1")
            }
            if (private$max_lead > 1) {
                stop("dynr cannot yet handle models with max. lead > 1")
            }
        },
        print = function(...) {
            cat("DynMod object\n")
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
            cat(sprintf("%-60s%d\n", "Number of endogenous variables with only lags:",
                        private$npred))
            cat(sprintf("%-60s%d\n", "Number of endogenous variables with only leads:",
                        private$nfwrd))
            cat(sprintf("%-60s%d\n", "Number of endogenous variables with both lags and leads:",
                        private$nboth))
            cat(sprintf("%-60s%d\n", "Number of static endogenous variables:",
                        private$nstatic))
            if (!is.null(private$model_period)) {
                cat(sprintf("%-60s%s\n", "Model period:",
                            as.character(private$model_period)))
            }
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
                per <- regts:::regrange_intersect(period, private$data_period)
            } else {
                per <- period
            }
            private$exo_data[period, names] <- value
            return (invisible(self))
        },
        get_exo_data = function(names, period = private$data_period) {
            if (missing(names)) {
                return (private$exo_data[period, ])
            } else {
                names <- intersect(names, private$endo_names)
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
                per <- regts:::regrange_intersect(period, private$data_period)
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
        get_endo_data = function(names, period = private$data_period) {
            if (missing(names)) {
                return (private$endo_data[period, ])
            } else {
                names <- intersect(names, private$endo_names)
                return (private$endo_data[period, names, drop = FALSE])
            }
        },
        solve_steady = function(start = self$get_static_endos(),
                                init_data = TRUE, control = NULL) {
            f <- function(x) {
                return (private$f_static(x, private$exos, private$params))
            }
            jac <- function(x) {
                return (private$f_static(x, private$exos, private$params, jac = TRUE))
            }
            # todo: print output / give error if the commamd was not
            # succesfull
            out <- nleqslv::nleqslv(start, fn = f, jac = jac,
                                    method = "Newton", control = control)
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
            if (is.null(private$rules)) {
                private$init_rules()
            }
            eigvalues <- private$solve_first_order(only_eigval = TRUE)
            cat("EIGENVALUES:\n")
            cat(sprintf("%16s%16s%16s\n", "Modulus", "Real", "Imaginary"))
            for (eigval in eigvalues) {
                cat(sprintf("%16g%16g%16g\n", Mod(eigval), Re(eigval),
                            Im(eigval)))
            }
            cat("\n")
            return (invisible(self))
        },
        solve = function(control = list()) {
            control_ <- list(ftol = 1e-8, maxiter = 20, trace = FALSE)
            control_[names(control)] <- control

            # preparations
            lags <- private$get_lags()
            leads <- private$get_leads()
            nper <- length_range(private$model_period)
            x <- private$get_solve_endo()

            if (control_$trace) {
                cat(sprintf("\nIteration report:\n"))
            }
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

            private$solve_out <- list(solved = solved, iter = iter,
                                      residual = res)
            private$endo_data[private$model_period, ] <-
                                t(matrix(x, nrow = private$endo_count))

            return (invisible(self))
        },
        solve_perturbation = function() {
            rules <- private$solve_first_order()
            private$rules <- rules

            sel <-  which(rules$kstate[, 2, drop = FALSE] <= private$max_lag + 1)
            k2 <- rules$kstate[sel, c(1,2), drop = FALSE]
            k2 <- k2[, 1, drop = FALSE] +
                (private$max_lag + 1 - k2[, 2, drop = FALSE]) * private$endo_count

            private$endo_data[1, ] <- private$endo_data[1, ] - private$endos

            ex_ <- private$exo_data[ , ] -
                      rep(private$exos, each = nrow(private$exo_data))

            check_per <- regperiod_range(start_period(private$model_period) + 1,
                                         end_period(private$data_period))
            if (sum(abs(ex_[check_per])) > .Machine$double.eps) {
                # The dynare command stoch_simul only allows for shocks in the first
                # period. An analytical solution in a Taylor approximation requires
                # so called deterministic exogenoeous variables. I do not known
                # yet how this works.
                stop(paste("The perturbation approach currently only allows shocks",
                           "in the first period"))
            }

            if (length(rules$ghu) == 0) {
                # purely backward?
                stop("Situation where length(ghu) == 0 not yet supported")
            } else if (length(rules$ghx) == 0) {
                # purely forward
                stop("Situation where length(ghx) == 0 not yet supported")
            } else {
                epsilon <- rules$ghu %*% t(ex_)
                for (i in 2 : length_range(private$data_period)) {
                    yhat <- t(private$endo_data[i - 1, rules$order_var[k2],
                                                drop = FALSE])
                    private$endo_data[i, rules$order_var] <-
                        rules$ghx %*% yhat  + epsilon[ , i, drop = FALSE]
                }

                # add steady state values
                private$endo_data[ , ] <- private$endo_data[ , ]  +
                              rep(private$endos, each = nrow(private$endo_data))
            }
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
            if (!is.null(private$rules)) {
                i <- order(abs(private$rules$eigval))
                return (private$rules$eigval[i])
            } else {
                stop(paste("Eigen values not available. Calculate the eigenvalues",
                           "with method check()."))
            }
        }
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
        nstatic =  NA_integer_,
        nfwrd =  NA_integer_,
        npred =  NA_integer_,
        nboth =  NA_integer_,
        ndynamic = NA_integer_,
        nsfwrd = NA_integer_,

        lead_lag_incidence = NULL,
        f_static = NULL,
        f_dynamic = NULL,
        model_period = NULL,
        data_period =  NULL,
        endo_data = NULL,
        exo_data = NULL,
        solve_out = NULL,
        rules = NULL,
        period_error_msg = paste("The model period is not set.",
                            "Set the model period with set_period()."),

        set_data_= function(data, names, names_missing, type = c("endo", "exo"),
                            update_mode = c("update", "updval")) {
            # generic function to set or update the endogenous or exogenous
            # variables

            if (is.null(private$model_period)) stop(private$period_error_msg)
            update_mode <- match.arg(update_mode)

            per <- regts:::regrange_intersect(get_regperiod_range(data),
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
            lag_per <- regperiod_range(start_period(private$data_period),
                                       start_period(private$model_period) - 1)
            return (as.numeric(t(private$endo_data[lag_per, ])))
        },
        get_leads = function() {
            lead_per <- regperiod_range(end_period(private$model_period) + 1,
                                        end_period(private$data_period))
            return (as.numeric(t(private$endo_data[lead_per, ])))
        },
        # returns a vector with endogenous variables in the solution period
        get_solve_endo = function() {
            return (as.numeric(t(private$endo_data[private$model_period, ])))
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
            endos <- c(private$get_lags(), x, private$get_leads())
            nper <- length_range(private$model_period)
            mat_info <- get_triplet_jac(endos, private$lead_lag_incidence,
                                        private$exo_data, private$params,
                                        private$f_dynamic, private$endo_count,
                                        nper, private$max_lag)
            n <- nper * private$endo_count
            jac <- new("dgTMatrix", i = mat_info$rows, j = mat_info$columns,
                       x = mat_info$values, Dim = as.integer(rep(n, 2)))
            return (as(jac, "dgCMatrix"))
        },
        init_rules = function(debug = FALSE) {

            rules <- list()

            # make local copies of the fields of the DynMod object
            exo_count <- private$exo_count
            endo_count <- private$endo_count
            npred <- private$npred
            nboth <- private$nboth
            nfwrd <- private$nfwrd
            nstatic <- private$nstatic
            ndynamic <- private$ndynamic
            nsfwrd <- private$nsfwrd
            lead_lag_incidence <- private$lead_lag_incidence
            max_lag <- private$max_endo_lag
            max_lead <- private$max_endo_lead
            klen <- max_lag + max_lead + 1

            lead_var <- which(lead_lag_incidence[, max_lag + 2] != 0)
            if (max_lag > 0) {
                lag_var <- which(lead_lag_incidence[, 1] != 0)
                stat_var <- setdiff(1:endo_count, union(lag_var, lead_var))
                both_var <- intersect(lead_var, lag_var)
                pred_var <- setdiff(lag_var, both_var)
                fwrd_var <- setdiff(lead_var, both_var)
            } else {
                pred_var <- numeric(0)
                both_var <- numeric(0)
                stat_var <- setdiff(1:endo_count, lead_var)
                fwrd_var <- lead_var
            }
            rules$order_var <- c(stat_var, pred_var, both_var, fwrd_var)
            rules$inv_order_var <- numeric(endo_count)
            rules$inv_order_var[rules$order_var] <- seq_len(endo_count)

            # building kmask for z state vector in t+1
            if (max_lag > 0) {
                kmask <- numeric(0)
                if (max_lead > 0) {
                    kmask <- lead_lag_incidence[rules$order_var, max_lag + 2,
                                                drop = FALSE]
                }
                kmask <- rbind(kmask, lead_lag_incidence[rules$order_var, 1,
                                                         drop = FALSE])
            } else {
                if (max_lead == 0) {
                    # in this case lead_lag_incidence has no entry max_lag+2
                    error(paste('Dynare currently does not allow to solve"),
                                "purely static models in a stochastic context.'))
                }
                kmask <- lead_lag_incidence[rules$order_var, max_lag + 2,
                                            drop = FALSE]
                }
            i_kmask <- which(kmask != 0)

            # composition of state vector
            # col 1: variable;           col 2: lead/lag in z(t+1);
            # col 3: A cols for t+1 (D); col 4: A cols for t (E)
            rules$kstate <- matrix(0, nrow = endo_count * (klen - 1), ncol = 4)
            rules$kstate[, 1] <- rep(seq_len(endo_count), klen - 1)
            rules$kstate[, 2] <- t(kronecker(matrix(klen: 2, ncol = 1),
                                             matrix(1, ncol = endo_count)))

            kiy <- as.numeric(t(t(lead_lag_incidence[rules$order_var, , drop = FALSE])
                                [klen:1, , drop = FALSE]))
            if (max_lead > 0) {
                rules$kstate[1 : endo_count, 3] <- kiy[1 : endo_count] -
                    nnz(lead_lag_incidence[, max_lag+ 1 ])
                rules$kstate[rules$kstate[ , 3] < 0, 3] <- 0
                rules$kstate[(endo_count + 1): nrow(rules$kstate), 4] <-
                    kiy[(2 * endo_count + 1) : length(kiy)];
            } else {
                rules$kstate[, 4] <- kiy[endo_count + 1 : length(kiy)]
            }
            rules$kstate <- rules$kstate[i_kmask, ]

            rules$nd <- nrow(rules$kstate)

            rules$k1 <- seq_len(npred + nboth)
            rules$k2 <- seq_len(nfwrd + nboth)

            nz <- nnz(lead_lag_incidence)
            lead_id <- which(lead_lag_incidence[, max_lag + 2] != 0)
            lead_idx <- lead_lag_incidence[lead_id, max_lag + 2]
            if (max_lag) {
                lag_id <- which(lead_lag_incidence[, 1] != 0)
                lag_idx <- lead_lag_incidence[lag_id, 1]
            } else {
                lag_id  <- numeric(0)
                lag_idx <- numeric(0)
            }
            both_id <- intersect(lead_id, lag_id)
            if (max_lag) {
                no_both_lag_id <- setdiff(lag_id, both_id)
            } else {
                no_both_lag_id <- lag_id
            }
            rules$innovations_idx <- nz + (1:exo_count)
            rules$state_var <- c(no_both_lag_id, both_id)

            # indices of the endogenous variables at time t
            rules$index_c <- nonzeros(lead_lag_incidence[, max_lag + 1])
            rules$n_current <- length(rules$index_c)

            rules$index_s <- npred + nboth + seq_len(nstatic)
            indexi_0 <- npred + nboth
            npred0 <- nnz(lead_lag_incidence[no_both_lag_id, max_lag + 1])
            rules$index_0m <- indexi_0 + nstatic  + seq_len(npred0)
            nfwrd0 <- nnz(lead_lag_incidence[lead_id, 2])
            rules$index_0p <- indexi_0 + nstatic + npred0 + seq_len(nfwrd0)
            rules$index_m <- seq_len(npred + nboth)
            rules$index_p <- npred + nboth + rules$n_current + seq_len(nfwrd + nboth)
            rules$row_indx_de_1 <- seq_len(ndynamic)
            rules$row_indx_de_2 <- ndynamic + seq_len(nboth)
            rules$row_indx <- nstatic + rules$row_indx_de_1
            rules$index_d <- c(rules$index_0m, rules$index_p)
            llx <- lead_lag_incidence[rules$order_var, , drop = FALSE]
            rules$index_d1 <- c(which(llx[nstatic + seq_len(npred), max_lag + 1] != 0),
                                npred + nboth + seq_len(nsfwrd))
            rules$index_d2 <- npred + seq_len(nboth)
            rules$index_e <- c(rules$index_m, rules$index_0p);
            rules$index_e1 <- c(seq_len(npred + nboth), npred + nboth +
                                    which(llx[nstatic + npred +
                                                  seq_len(nsfwrd), max_lag + 1] != 0)
            )
            rules$index_e2 <- npred + nboth + seq_len(nboth)

            rules$cols_b <- which(lead_lag_incidence[, max_lag + 1, drop = FALSE] != 0,
                                  arr.in = TRUE)[, 1]

            vec <- llx[llx != 0]
            rules$reorder_jacobian_columns <- c(vec, nz + seq_len(exo_count))
            return (rules)
        },
        solve_first_order = function(only_eigval = FALSE, debug = FALSE) {
            self$solve_steady(init_data = FALSE)
            if (is.null(private$rules)) {
                rules <- private$init_rules()
            } else {
                rules <- private$rules
            }

            # calculate the Jacobian
            nper <- private$max_lag + private$max_lead + 1
            exos <- matrix(rep(private$exos, each = nper), nrow = nper)
            endos <- rep(private$endos, nper)
            y <- endos[which(private$lead_lag_incidence != 0)]
            it <- private$max_lag + 1
            jacobia <- private$f_dynamic(y, exos, private$params, it, jac = TRUE)
            jacobia <- jacobia[, rules$reorder_jacobian_columns, drop = FALSE]

            if (private$nstatic) {
                ret <- qr(jacobia[, rules$index_s, drop = FALSE])
                Q <- qr.Q(ret, complete = TRUE)
                aa <- t(Q) %*% jacobia
            } else {
                aa <- jacobia
            }
            if (debug) {
                printobj(jacobia)
                printobj(aa)
            }

            # compute D and E matrix
            # The linearized model has the form
            # D * (z_t+1,  y_t+1)' = E * (z_t, y_t)'
            # where z_t = y_t-1
            n <- private$nboth + private$ndynamic
            D <- matrix(0, nrow = n, ncol = n)
            E <- matrix(0, nrow = n, ncol = n)
            D[rules$row_indx_de_1, rules$index_d1] <- aa[rules$row_indx,
                                                             rules$index_d]
            D[rules$row_indx_de_2, rules$index_d2] <- diag(private$nboth)
            E[rules$row_indx_de_1, rules$index_e1] <- -aa[rules$row_indx,
                                                              rules$index_e]
            E[rules$row_indx_de_2, rules$index_e2] <- diag(private$nboth)
            if (only_eigval) {
                rules$eigval <- geigen::geigen(E, D, only.values = TRUE)$values
            } else {
                qz_result <- geigen::gqz(E, D, sort = 'S')
                rules$eigval <- geigen::gevalues(qz_result)
            }
            if (debug) {
                printobj(D)
                printobj(E)
                printobj(qz_result)
            }

            sdim <- sum(abs(rules$eigval) <= 1)
            nba <- rules$nd - sdim
            if (nba > private$nsfwrd) {
                stop("Blanchard & Kahn conditions are not satisfied: no stable equilibrium")
            } else if (nba < private$nsfwrd) {
                stop("Blanchard & Kahn conditions are not satisfied: indeterminacy")
            }

            if (only_eigval) {
                i <- order(abs(rules$eigval))
                private$rules <- rules
                return (rules$eigval[i])
            }

            A <- aa[, rules$index_m, drop = FALSE]  # Jacobian matrix for lagged endogeneous variables
            B <- matrix(NA, nrow = nrow(aa), ncol = length(rules$index_c))
            B[, rules$cols_b] <- aa[, rules$index_c, drop = FALSE] # Jacobian matrix for contemporaneous
            # endogenous variables
            C <- aa[, rules$index_p, drop = FALSE] # Jacobian matrix for lead endogeneous variables

            indx_stable_root <- 1: (rules$nd - private$nsfwrd)             # %=> index of stable roots
            indx_explosive_root <- (private$npred + private$nboth + 1) : rules$nd  # => index of explosive roots
            #derivatives with respect to dynamic state variables
            #forward variables

            # TODO: what to do if there are no explosive roots or no stable roots?
            Z <- t(qz_result$Z)
            Z11 <- Z[indx_stable_root,    indx_stable_root, drop = FALSE]
            Z21 <- Z[indx_explosive_root, indx_stable_root, drop = FALSE]
            Z22 <- Z[indx_explosive_root, indx_explosive_root, drop = FALSE]
            rules$gx <- -solve(Z22, Z21)
            # TODO: error if Z22 is new singular (see Matlab code)
            hx1 <- t(backsolve(qz_result$T[indx_stable_root, indx_stable_root, drop =
                                               FALSE], Z11, transpose = TRUE))
            hx2 <- t(solve(Z11, t(qz_result$S[indx_stable_root, indx_stable_root, drop =
                                                  FALSE])))
            hx <- hx1 %*% hx2
            rules$ghx <- hx[rules$k1, , drop = FALSE]
            if (debug) {
                printobj(hx1)
                printobj(hx2)
                printobj(rules$k2)
            }
            if (private$nboth + 1 <= length(rules$k2)) {
                rules$ghx <- rbind(rules$ghx,
                                  rules$gx[rules$k2[(private$nboth + 1) :
                                                         length(rules$k2)], , drop = FALSE])
            }
            if (private$nstatic) {
                B_static <- B[, 1:private$nstatic, drop = FALSE]
            } else {
                B_static <- matrix(nrow = nrow(B), ncol = 0)
            }

            # static variables, backward variables, mixed variables and forward variables
            B_pred <- B[, (private$nstatic + 1) : (private$nstatic + private$npred + private$nboth)]
            if (private$nstatic + private$npred + private$nboth + 1 <= ncol(B)) {
                B_fyd <- B[, (private$nstatic + private$npred + private$nboth + 1) : ncol(B)]
            } else  {
                B_fyd <- matrix(nrow = nrow(B), ncol = 0)
            }

            if (private$nstatic) {
                temp <- - C[1:private$nstatic, , drop = FALSE] %*% rules$gx %*% hx
                b <- matrix(nrow = nrow(aa), ncol = length(rules$index_c))
                b[, rules$cols_b] <- aa[ , rules$index_c, drop = FALSE]
                b10 <- b[1:private$nstatic, 1:private$nstatic, drop = FALSE]
                b11 <- b[1:private$nstatic, (private$nstatic + 1) : ncol(b),
                         drop = FALSE]
                temp[, rules$index_m] <- temp[, rules$index_m, drop = FALSE] -
                    A[1:private$nstatic, , drop = FALSE]
                temp <- solve(b10, temp - b11 %*% rules$ghx)
                rules$ghx <- rbind(temp, rules$ghx)
            }
            A_ <- cbind(B_static, C %*% rules$gx + B_pred, B_fyd)

            if (private$exo_count) {
                if (private$nstatic) {
                    fu <- t(Q) %*% jacobia[,  rules$innovations_idx, drop = FALSE]
                } else {
                    fu <- jacobia[, rules$innovations_idx, drop = FALSE]
                }
                rules$ghu <- - solve(A_, fu)
            } else {
                rules$ghu <- matrix(nrow = 0, ncol = 0)
            }
            rules$Gy <- hx

            return (rules)
        }
    )
)
