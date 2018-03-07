#' @importFrom methods setOldClass
setOldClass("period_range")
setOldClass("regts")

#' An R6 class for a Dynare model
#'
#' @docType class
#' @importFrom R6 R6Class
#' @importFrom Rcpp sourceCpp
#' @useDynLib dynmdl, .registration = TRUE
#' @importFrom regts start_period
#' @importFrom regts end_period
#' @importFrom regts as.period_range
#' @importFrom regts nperiod
#' @importFrom regts period_range
#' @importFrom regts range_intersect
#' @importFrom regts regts
#' @importFrom Matrix Matrix
#' @importFrom Matrix sparseMatrix
#' @importFrom nleqslv nleqslv
#' @importFrom umfpackr umf_solve_nl
#' @importFrom compiler compile
#' @importFrom utils zip
#' @importFrom utils compareVersion
#' @export
#' @keywords data
#' @return Object of \code{\link{R6Class}} containing a macro-economic model,
#' @format \code{\link{R6Class}} object.
#'
#' @section Methods:
#' \describe{
#'
#' \item{\code{\link{get_max_lag}}}{Returns the maximum lag}
#'
#' \item{\code{\link{get_max_lead}}}{Returns the maximum lead}
#'
#' \item{\code{\link{get_endo_names}}}{Returns the names of the endogenous variables.}
#'
#' \item{\code{\link{get_exo_names}}}{Returns the names of the exogenous variables.}
#'
#' \item{\code{\link{set_labels}}}{Set labels for the model variables}
#'
#' \item{\code{\link{get_labels}}}{Returns the labels of the model variables and
#' parameters}
#'
#' \item{\code{\link{get_tex_names}}}{Returns the LaTeX names of the model 
#' variables and parameters}
#'
#' \item{\code{\link{get_par_names}}}{Returns the names of the parameters.}
#'
#' \item{\code{\link{set_param}}}{Sets the parameters of the model.}
#'
#' \item{\code{\link{get_param}}}{Returns the parameters of the model.}
#'
#' \item{\code{\link{set_static_exos}}}{Sets the static values of
#' the exogenous variables used to compute the steady state.}
#'
#' \item{\code{\link{get_static_exos}}}{Returns the static values of
#' the exogenous variables.}
#'
#' \item{\code{\link{set_static_endos}}}{Sets the static values of
#' the endogenous variables.}
#'
#' \item{\code{\link{get_static_endos}}}{Returns the static values of
#' the endogenous variables.} 
#'
#' \item{\code{\link{init_data}}}{Initializes the model data}
#'
#' \item{\code{\link{set_period}}}{Sets the model period}
#'
#' \item{\code{\link{get_period}}}{Returns the model period}
#'
#' \item{\code{\link{get_data_period}}}{Returns the model data period.}
#'
#' \item{\code{get_lag_period}}{Returns the lag period.}
#'
#' \item{\code{get_lead_period}}{Returns the lead period}
#'
#' \item{\code{\link{set_endo_values}}}{Sets the values of endogenous model 
#' variables}
#'
#' \item{\code{\link{set_exo_values}}}{Sets the values of exogenous model 
#' variables}
#'
#' \item{\code{\link{set_data}}}{Transfer timeseries to the model data}
#'
#' \item{\code{\link{change_endo_data}}}{Changes the values of endogenous model 
#' variables by applying a function}
#'
#' \item{\code{\link{change_exo_data}}}{Changes the values of exogenous model 
#' variables by applying a function}
#'
#' \item{\code{\link{get_endo_data}}}{Returns the endogenous model data}
#'
#' \item{\code{\link{get_exo_data}}}{Returns the exogenous model data}
#'
#' \item{\code{\link{solve_steady}}}{Solves the steady state}
#'
#' \item{\code{\link{solve}}}{Solves the model}
#' 
#' \item{\code{\link{check}}}{Compute the eigenvalues of the linear
#' system and check if the Blachard and Kahn conditions are satisfied.}
#'
#' \item{\code{\link{residual_check}}}{Calculates the residuals of the equation
#' and report the differences larger than a tolerance parameters}
#'
#' \item{\code{solve_perturbation}}{Solves the model using the perturbation
#' theory used in the Dynare function stoch_simul. Only shocks in the first
#' solution period are allowed.}
#'
#' \item{\code{\link{get_jacob}}}{Returns the Jacobian for the dynamic model}
#'
#' \item{\code{\link{get_static_jacob}}}{Returns the Jacobian for the
#' static version of the model}
#' 
#' \item{\code{\link{get_back_jacob}}}{Returns the Jacobian for a
#' backward looking model at a specific period}
#'
#' \item{\code{\link{get_eigval}}}{Returns the eigenvalues computed with 
#' method \code{\link{check}} or \code{solve_perturbation}}
#' 
#' \item{\code{\link{get_equations}}}{Returns a character vector with the 
#' equations of the model.}
#' 
#' \item{\code{\link{copy}}}{Returns a deep copy of the \code{\link{DynMdl}} 
#' object}
#' }
DynMdl <- R6Class("DynMdl",
  public = list(
    initialize = function(mdldef, equations, calc, dll_dir, dll_file) {

      # no arguments supplied
      if (nargs() == 0) return()
      
      private$set_mdldef(mdldef)
      
      private$equations <- equations
      private$calc <- calc
      private$dll_dir <- dll_dir
      private$dll_file <- dll_file

      # now create the functions for evaluating the model
      private$make_functions()
    },
    print = function(short = TRUE) {
      cat("DynMdl object\n")
      private$print_info(short)
      return (invisible(NULL))
    },
    get_max_lag = function() {
      return(private$mdldef$max_lag)
    },
    get_max_lead = function() {
      return(private$mdldef$max_lead)
    },
    get_endo_names = function(type = c("all", "leads", "lags")) {
      type <- match.arg(type)
      if (type == "leads" || type == "lags") {
        lli <- private$mdldef$lead_lag_incidence
        if (type == "leads") {
            lli <- lli[, as.integer(colnames(lli)) > 0, drop = FALSE]
        } else {
            lli <- lli[, as.integer(colnames(lli)) < 0, drop = FALSE]
        }
        lli <- rowSums(lli)
        names <- names(lli[lli > 0])
        if (private$mdldef$aux_vars$aux_count > 0) {
          aux_endo_names <- private$endo_names[private$mdldef$aux_vars$endos]
          names <- setdiff(names, aux_endo_names)
        }
      } else {
        names <- private$endo_names
        if (private$mdldef$aux_vars$aux_count > 0) {
            names <- names[-private$mdldef$aux_vars$endos]
        }
      }
      return(names)
    },
    get_exo_names = function() {
      return(private$exo_names)
    },
    set_labels = function(labels) {
      private$update_labels(labels)
    },
    get_labels = function() {
      return(private$mdldef$labels)
    },
    get_tex_names = function() {
      return(private$mdldef$tex_names)
    },
    get_par_names = function(pattern = ".*") {
      names <- private$param_names
      if (!missing(pattern)) {
        sel <- grep(pattern, names)
        names <- names[sel]
      }
      return(names)
    },
    set_param = function(params) {
      private$mdldef$params[names(params)] <- params
      return(invisible(self))
    },
    get_param = function(pattern, names) {
      if (missing(pattern) && missing(names)) {
        names <- self$get_par_names()
      } else if (missing(names)) {
        names <- self$get_par_names(pattern)
      } else if (!missing(pattern)) {
        names <- union(names, self$get_par_names(pattern))
      }
      return(private$mdldef$params[names])
    },
    set_static_exos = function(exos) {
      exo_names <- intersect(private$exo_names, names(exos))
      private$mdldef$exos[exo_names] <- exos[exo_names]
      return(invisible(self))
    },
    get_static_exos = function() {
      return(private$mdldef$exos)
    },
    set_static_endos = function(endos) {
      endo_names <- intersect(private$endo_names, names(endos))
      private$mdldef$endos[endo_names] <- endos[endo_names]
      return(invisible(self))
    },
    get_static_endos = function() {
      if (private$mdldef$aux_vars$aux_count > 0) {
        return(private$mdldef$endos[-private$mdldef$aux_vars$endos])
      } else {
        return(private$mdldef$endos)
      }
    },
    init_data = function(data_period, data)  {
      if (missing(data_period)) {
        if (!missing(data)) {
          data_period <- get_period_range(data)
        } else {
          stop(paste("Argument data_period is mandatory if",
                     "argument data has not been specified"))
        }
      } else {
        data_period <- as.period_range(data_period)
        if (is.na(data_period[1]) || is.na(data_period[2])) {
          stop("data_period should have a lower and upper bound")
        }
      }
      
      private$data_period <- data_period
      nper <- nperiod(data_period)
      endo_mat <- matrix(rep(private$mdldef$endos, each = nper), nrow = nper)
      private$endo_data <- regts(endo_mat, start = start_period(data_period),
                                 names = names(private$mdldef$endos))
      
      if (private$mdldef$exo_count > 0) {
        exo_mat <- matrix(rep(private$mdldef$exos, each = nper), nrow = nper)
        colnames(exo_mat) <- private$exo_names
      } else {
        exo_mat <- matrix(NA_real_, nrow = nper, ncol = 0)
      }
      private$exo_data <- regts(exo_mat, start = start_period(data_period))
      
      # update the model period
      startp <- start_period(data_period) + private$mdldef$max_lag
      endp <- end_period(data_period) - private$mdldef$max_lead
      if (endp >= startp) {
        private$model_period <- period_range(startp, endp)
        private$period_shift <- start_period(private$model_period) - 
                                start_period(private$data_period)
      } else {
        stop(paste("The data period is too short. It should contain at least",
                   private$mdldef$max_lag + private$mdldef$max_lead + 1, "periods"))
      }
      
      if (!missing(data)) {
        self$set_data(data)
      }
    },
    set_period = function(period) {
      period <- as.period_range(period)
      if (is.na(period[1]) || is.na(period[2])) {
        stop("period should have a lower and upper bound")
      }
      if (is.null(private$data_period)) {
        data_period <- period_range(
          start_period(period) - private$mdldef$max_lag,
          end_period(period)   + private$mdldef$max_lead)
        self$init_data(data_period)
      } else  {
        private$check_model_period(period) 
      }
      private$model_period <-  period
      private$period_shift <- start_period(private$model_period) -
                              start_period(private$data_period)
      return(invisible(self))
    },
    get_period = function() {
      return (private$model_period)
    },
    get_data_period = function() {
      return (private$data_period)
    },
    get_lag_period = function() {
      if (private$mdldef$max_lag > 0) {
        p <- start_period(private$model_period) - private$mdldef$max_lag
        return(period_range(p, p + private$mdldef$max_lag - 1))
      } else {
        return(NULL)
      }
    },
    get_lead_period = function() {
      if (private$mdldef$max_lead > 0) {
        p <- end_period(private$model_period) + 1
        return(period_range(p, p + private$mdldef$max_lead - 1))
      } else {
        return(NULL)
      }
    },
    get_exo_data = function(pattern = NULL, names = NULL, 
                            period = private$data_period) {
      period <- private$convert_period_arg(period)
      if (private$mdldef$exo_count == 0) {
        return(private$exo_data[period, ])
      }
      if (missing(pattern) && missing(names)) {
        ret <- private$exo_data[period, ]
      } else {
        names <- private$get_names_("exo", names, pattern)
        if (length(names) == 0) {
          return(NULL)
        }
        ret <- private$exo_data[period, names, drop = FALSE]
      }
      return(update_ts_labels(ret, private$mdldef$labels))
    },
    set_endo_values = function(value, names = NULL, pattern = NULL,
                               period = private$data_period) {
      private$set_values_(value, names, pattern, period, type = "endo")
      return(invisible(self))
    },
    set_exo_values = function(value, names = NULL, pattern = NULL,
                              period = private$data_period) {
      private$set_values_(value, names, pattern, period, type = "exo")
      return(invisible(self))
    },
    set_data = function(data, names = colnames(data), 
                        upd_mode = c("upd", "updval"), fun) {
      upd_mode <- match.arg(upd_mode)
      private$set_data_(data, names, names_missing = missing(names),
                        type = "exo", upd_mode = upd_mode, fun)
      private$set_data_(data, names, names_missing = missing(names),
                        type = "endo", upd_mode = upd_mode, fun)
      return(invisible(self))
    },
    get_endo_data = function(pattern = NULL, names = NULL, 
                             period = private$data_period) {
      period <- private$convert_period_arg(period)
      if (missing(pattern) && missing(names) && 
          !private$mdldef$aux_vars$aux_count > 0) {
        ret <- private$endo_data[period, ]
      } else {
        names <- private$get_names_("endo", names, pattern)
        if (length(names) == 0) {
          return(NULL)
        }
        ret <- private$endo_data[period, names, drop = FALSE]
      }
      return(update_ts_labels(ret, private$mdldef$labels))
    },
    change_endo_data = function(fun, names= NULL, pattern = NULL, 
                                period = private$data_period , ...) {
      return(private$change_data_(fun, names, pattern, period, "endo", ...))
    },
    change_exo_data = function(fun, names= NULL, pattern = NULL, 
                               period = private$data_period , ...) {
      return(private$change_data_(fun, names, pattern, period, "exo", ...))
    },
    solve_steady = function(control = NULL, solver = c("umfpackr", "nleqslv"),
                            ...) {

      solver <- match.arg(solver)
      
      private$prepare_static_model()
      
      start <- private$mdldef$endos
      if (private$mdldef$aux_vars$aux_count > 0) {
        # make sure that they are ok
        aux_endos <- private$mdldef$endos[private$mdldef$aux_vars$orig_endos]
        start[private$mdldef$aux_vars$endos]  <- aux_endos
      }
      
      if (private$calc == "internal") {
        f_res <- function(endos) {
          return(get_residuals_stat(private$mdldef$model_index, endos))
        }
      } else {
        f_res <- function(endos) {
          return(private$f_static(endos, private$mdldef$exos, private$mdldef$params))
        }
      }
      
      if (solver == "umfpackr") {
        out <- umf_solve_nl(start, fn = f_res, jac = private$get_static_jac, 
                            control = control, ...)
        error <- !out$solved
      } else {
        jacf <- function(endos) {
          j <- private$get_static_jac(endos)
          return(as(j, "matrix"))
        }
        out <- nleqslv(start, fn = f_res, jac = jacf, method = "Newton",
                       control = control)
        error <- out$termcd != 1
      }
      private$clean_static_model()
      private$mdldef$endos <- out$x

      if (error) {
        stop(paste0("Error solving the steady state.\n", out$message))
      }
      return (invisible(self))
    },
    put_static_endos = function(period = private$data_period) {
      # copy the static endogenous variables to the endogenous model data
      if (is.null(private$model_period)) stop(private$period_error_msg)
      period <- private$convert_period_arg(period)
      nper <- nperiod(period)
      private$endo_data[period, ] <- 
              matrix(rep(private$mdldef$endos, each = nper), nrow = nper)
      return(invisible(self))
    },
    check = function() {

      self$solve_steady(control = list(silent = TRUE))
      
      private$prepare_dynamic_model()
      private$ss  <- solve_first_order(private$ss,
                                       private$mdldef$lead_lag_incidence,
                                       private$mdldef$exos, private$mdldef$endos,
                                       private$mdldef$params,
                                       private$jac_dynamic,
                                       private$mdldef$endo_count,
                                       private$mdldef$njac_cols,
                                       check_only = TRUE, debug = FALSE)
      private$clean_dynamic_model()
      return(invisible(self))
    },
    residual_check = function(tol = 0) {
      if (is.null(private$model_period)) stop(private$period_error_msg)
      private$prepare_dynamic_model()
      
      nper <- nperiod(private$model_period)
      lags <- private$get_endo_lags()
      leads <- private$get_endo_leads()
      x <- private$get_solve_endo()
      
      private$prepare_dynamic_model()
      residuals <- private$get_residuals(x, lags, leads, nper)
      private$clean_dynamic_model()
      
      dim(residuals) <- c(private$mdldef$endo_count, nper)
      residuals <- t(residuals)
      colnames(residuals) <- paste0("eq_",  1 : (private$mdldef$endo_count))
      
      if (private$mdldef$aux_vars$aux_count > 0) {
        # remove the residuals for the auxiliary equations
        residuals <- residuals[, -private$mdldef$aux_vars$endos]
      }

      p_start <- start_period(private$model_period)
      p_end <- end_period(private$model_period)
      
      if (tol != 0) {
        col_sel <- apply(residuals, MARGIN = 2, 
                         FUN = function(x) max(abs(x)) > tol)
        residuals <- residuals[ , col_sel, drop = FALSE]
        if (ncol(residuals) > 0) {
          row_sel <-  which(apply(residuals, MARGIN = 1, 
                            FUN = function(x) max(abs(x)) > tol))
          imin <- min(row_sel)
          imax <- max(row_sel)
          if (imax >= imin) {
            residuals <- residuals[imin : imax, , drop = FALSE]
          }
          p_start <- p_start + (imin - 1)
          p_end <- p_end - (nper - imax)
        }
      }
      return(regts(residuals, start = p_start, end = p_end))
    },
    solve = function(control = list(), force_stacked_time = FALSE,
                     solver = c("umfpackr", "nleqslv"), ...) {
      
      if (is.null(private$model_period)) stop(private$period_error_msg)
      solver <- match.arg(solver)
      
      control_ <- list(ftol = 1e-8, trace = FALSE, cndtol = 1e-12, 
                       silent = FALSE)
      if (solver == "umfpackr")  {
        control_$maxiter <- 20
      } else {
        control_$maxit <- 20
      }
      control_[names(control)] <- control
      
      private$prepare_dynamic_model()
   
      if (private$mdldef$max_endo_lead > 0 || force_stacked_time ) {
        # preparations
        if (solver != "umfpackr") {
          stop(paste("For forward looking models only the umfpackr",
                     "solver is allowed"))
        }
        nper <- nperiod(private$model_period)
        lags <- private$get_endo_lags()
        leads <- private$get_endo_leads()
        x <- private$get_solve_endo()
        ret <- umf_solve_nl(x, private$get_residuals,
                            private$get_jac, lags = lags,
                            leads = leads, nper = nper,
                            control = control_, ...)
        if (!control_$silent) {
          cat(sprintf("Total time function eval. : %g\n", ret$t_f))
          cat(sprintf("Total time Jacobian.      : %g\n", ret$t_jac))
          cat(sprintf("Total time LU fact.       : %g\n", ret$t_lu))
          cat(sprintf("Total time solve          : %g\n", ret$t_solve))
        }
      } else {
        ret <- solve_backward_model(private$mdldef$model_index, 
                                    private$calc,
                                    private$model_period,
                                    private$period_shift,
                                    private$endo_data,
                                    private$exo_data, private$mdldef$params,
                                    private$mdldef$lead_lag_incidence,
                                    private$mdldef$njac_cols,
                                    private$f_dynamic,
                                    private$get_back_jac,
                                    control = control_,
                                    solver = solver)
      }
      
      private$clean_dynamic_model()
      
      private$endo_data[private$model_period, ] <-
                      t(matrix(ret$x, nrow = private$mdldef$endo_count))
      
      if (!ret$solved) {
        stop(paste("Model solving not succesfull.\n", ret$message))
      }
      return(invisible(self))
    },
    solve_perturbation = function() {

      if (is.null(private$model_period)) stop(private$period_error_msg)

      self$solve_steady(control = list(silent = TRUE))
      
      # solve_perturbation does not works for exogenous lags and leads.
      # For perturbation approaches, Dynare substitutes
      # these lags and leads by creating auxiliary variables and
      # equations. dynmdl does not do that.
      if (private$mdldef$max_exo_lag > 0 || private$mdldef$max_exo_lead > 0) {
        stop(paste("Method solve_perturbation does not work for models",
                   "with exogenous lags or leads"))
      }
      
      private$prepare_dynamic_model()
      
      private$ss <- solve_first_order(private$ss, private$mdldef$lead_lag_incidence,
                                      private$mdldef$exos, private$mdldef$endos,
                                      private$mdldef$params, private$jac_dynamic,
                                      private$mdldef$endo_count, 
                                      private$mdldef$njac_cols,
                                      check_only = FALSE, debug = FALSE)
      
      private$endo_data <- solve_perturbation_(private$ss,
                                               private$mdldef$max_endo_lag,
                                               private$exo_data, private$endo_data,
                                               private$mdldef$exos, private$mdldef$endos)
      
      private$clean_dynamic_model()
      return(invisible(self))
    },
    get_jacob = function(sparse = FALSE) {
      if (is.null(private$model_period)) stop(private$period_error_msg)
      lags  <- private$get_endo_lags()
      leads <- private$get_endo_leads()
      nper <- nperiod(private$model_period)
      x <- private$get_solve_endo()
      
      private$prepare_dynamic_model()
      jac <- private$get_jac(x, lags, leads, nper)
      private$clean_dynamic_model()
      
      if (!sparse) {
        jac <- as(jac, "matrix")
      }
      colnames(jac) <- as.character(outer(private$endo_names, 1:nper, 
                                          FUN = "paste", sep ="_t"))
      rownames(jac) <- as.character(outer(paste0("eq_", 1:private$mdldef$endo_count), 
                                          1:nper, FUN = "paste", sep ="_t"))
      return(jac)
    },
    get_static_jacob = function(sparse = FALSE) {
      private$prepare_static_model()
      jac <- private$get_static_jac(private$mdldef$endos)
      private$clean_static_model()
      if (!sparse) {
        jac <- as(jac, "matrix")
      }
      colnames(jac) <- private$endo_names
      return(jac)
    },
    get_back_jacob = function(period, sparse = FALSE) {
      # returns the Jacobian for the backward looking model
      if (private$mdldef$max_endo_lead > 0) {
        stop("Method get_back_jacob can only be used for backward looking models")
      }
      if (is.null(private$model_period)) {
        stop(private$period_error_msg)
      }
      period <- as.period(period)
      if (frequency(period) != frequency(private$model_period)) {
        stop(paste0("The frequency of period (", period, ") does not agree",
                    "with the model period (", private$model_period, ")"))
      }
      # check period
      allowed_range <- period_range(start_period(private$data_period) + 
                                    private$mdldef$max_lag,
                                    end_period(private$data_period))
      if (period < start_period(allowed_range)  ||
          period > end_period(allowed_range)) { 
        stop(paste0("The specified period (", period, 
                    ") should lie within the range ",
                    allowed_range, "."))
      }
      
      iper <- period - start_period(private$data_period)
      
      nendo <- private$mdldef$endo_count
      
      max_lag <- abs(as.numeric(colnames(private$mdldef$lead_lag_incidence)[1]))
      lag_indices <- which(private$mdldef$lead_lag_incidence[, 1 : max_lag] != 0) + 
                                (private$period_shift - max_lag) * nendo
      data <- t(private$endo_data)
      lags <- data[lag_indices + (iper - 1) * nendo]
      cur_indices <- (1:nendo) + (iper - 1 + private$period_shift) * nendo
      x <- data[cur_indices]
      
      private$prepare_dynamic_model()
      jac <- private$get_back_jac(x, lags, iper)
      private$clean_dynamic_model()
      if (!sparse) {
        jac <- as(jac, "matrix")
      }
      colnames(jac) <- private$endo_names
      return(jac)
    },
    get_equations = function(i = 1:private$mdldef$endo_count) {
      if (!is.numeric(i)) {
        stop("Argument i should be a numeric")
      }
      return(private$equations[i])
    },
    get_eigval = function() {
      if (!is.null(private$ss) && !is.null(private$ss$eigval)) {
        i <- order(abs(private$ss$eigval))
        return(private$ss$eigval[i])
      } else {
        stop(paste("Eigen values not available. Calculate the eigenvalues",
                   "with method check()."))
      }
    },
    time_functions = function() {
      private$prepare_dynamic_model()
      time_functions(private$model_period, private$endo_data,
                     private$exo_data, private$mdldef$params,
                     private$mdldef$lead_lag_incidence,
                     private$f_dynamic, private$jac_dynamic)
      private$clean_dynamic_model()
      return(invisible(NULL))
    },
    write_mdl = function(file) {
      cat(paste("Writing model to", file, " ...\n"))
      saveRDS(self$serialize(), file)
      cat("Done\n")
      return (invisible(self))
    },
    copy = function() {
      return(self$clone(deep = TRUE))
    },
    serialize = function() {
      
      os_type <- .Platform$OS.type
      
      if (private$calc == "dll") {
        zip_file <- tempfile(pattern = "dynmdl_dll_", fileext = ".zip")
        zip(zipfile = zip_file, files = private$dll_dir, extra = "-q")
        size <- file.info(zip_file)$size
        bin_data <- readBin(zip_file, what = "raw", n = size)
        unlink(zip_file)
      } else if (private$calc == "internal") {
        bin_data <- serialize_polish_models(private$mdldef$model_index)
      } else {
        bin_data <- NULL
      }
        
      serialized_mdl <- list(version = packageVersion("dynmdl"),
                             mdldef = private$mdldef,
                             equations = private$equations,
                             calc = private$calc,
                             bin_data = bin_data,
                             dll_basename = basename(private$dll_file),
                             os_type = os_type,
                             model_period = private$model_period,
                             endo_data = private$endo_data,
                             exo_data = private$exo_data)
      return(structure(serialized_mdl, class = "serialized_dynmdl"))
    },
    deserialize = function(ser, dll_dir) {
      
      # for the time being we will not make the serialized model file
      # backwards compatible
      minimal_version <- as.character(packageVersion("dynmdl"))
      if (compareVersion(as.character(ser$version), minimal_version)) {
        stop(paste("It is not possible to read model files",
                   "created with dynmdl versions prior to",
                  minimal_version, "\nPlease regenerate the model with function",
                  "dynmdl"))
      } 
      
      private$set_mdldef(ser$mdldef)
      
      if (ser$calc == "dll") {
        
        # check operating system. If the model is generated on a different
        # platform, then we should recompile the model!
        if (ser$os_type != .Platform$OS.type) {
          # TODO: simply recompile the model
          stop("The model functions have been compiled on a different platform")
        }
        
        if (missing(dll_dir)) {
          private$dll_dir <- tempfile(pattern = "dynmdl_dll_")
        } else {
          private$dll_dir <- dll_dir
          if (dir.exists(dll_dir)) unlink(dll_dir, recursive = TRUE)
        }
        dir.create(private$dll_dir)
        private$dll_file <- file.path(private$dll_dir, ser$dll_basename)
        zip_file <- tempfile(pattern = "dynmdl_dll_", fileext = ".zip")
        writeBin(ser$bin_data, con = zip_file)
        unzip(zipfile = zip_file, exdir = private$dll_dir, junkpaths = TRUE)
        unlink(zip_file)
      } else if (ser$calc == "internal") {
        private$mdldef$model_index <- deserialize_polish_models(ser$bin_data)
      }
      
      # we don't need these elements anymore
      ser$bin_data <- NULL
      ser$version <- NULL
      ser$dll_basename <- NULL
      ser$os_type <- NULL
      ser$mdldef <- NULL

      # copy remaining elements to the private environment
      list2env(ser, private)
      
      private$make_functions()
      
      # compute derived object members
      if (!is.null(ser$endo_data)) {
        private$data_period <- get_period_range(ser$endo_data)
        private$period_shift <- start_period(private$model_period) - 
                                start_period(private$data_period)
      }
      
      return(invisible(self))
  }),
  private = list(
    mdldef = NULL,
    model_index = NA_integer_,
    equations = NULL,
    exo_names = NULL,
    endo_names = NULL,
    param_names = NULL,
    f_static = NULL,
    jac_static = NULL,
    f_dynamic = NULL,
    jac_dynamic = NULL,
    model_period = NULL,
    data_period =  NULL,
    period_shift =  NA,
    endo_data = NULL,
    exo_data = NULL,
    ss = NULL,
    calc = NA_character_,
    dll_dir = NA_character_,
    dll_file = NA_character_,
    period_error_msg = paste("The model period is not set.",
                             "Set the model period with set_period()."),
    nrow_exo = NA_integer_,
    jac = NULL,
    jac_steady = NULL,
    get_names_ = function(type, names, pattern) {
      if (type == "endo") {
        vnames <- private$endo_names
        if (private$mdldef$aux_vars$aux_count > 0) {
          vnames <- vnames[-private$mdldef$aux_vars$endos]
        }
      } else {
        vnames <- private$exo_names
      }
      if (!is.null(names)) {
        error_vars <- setdiff(names, vnames)
        if (length(error_vars) > 0) {
          if (type == "endo") {
            type_txt <- "endogenous "
          } else {
            type_txt <- "exogenous "
          }
          if (length(error_vars) == 1) {
            stop(paste0(error_vars, " is not an ", type_txt, "model variable"))
          } else {
            stop(paste0("The variables ", paste(error_vars, collapse = " "),
                        " are no ", type_txt, "model variables"))
          }
        }
      }
      if (is.null(pattern) && is.null(names)) {
        names <- vnames
      } else if (!is.null(pattern)) {
        sel <- grep(pattern, vnames)
        pattern_names <- vnames[sel]
        if (!is.null(names)) {
          names <- union(pattern_names, names)
        } else {
          names <- pattern_names
        }
      }
      return(names)
    },
    set_data_ = function(data, names, names_missing, type, upd_mode = "upd", 
                        fun) {
      # generic function to set or update the endogenous or exogenous
      # variables
      
      if (is.null(private$model_period)) stop(private$period_error_msg)
      if (!inherits(data, "ts")) {
        # we use inherits and not is.ts, because is.ts returns FALSE if
        # length(x) == 0
        stop("Argument data is not a timeseries object")
      }
      if (frequency(data) != frequency(private$data_period)) {
        stop(paste0("The frequency of data does not agree with the data",
                    " period ", as.character(private$data_period), "."))
      }
      
      per <- range_intersect(get_period_range(data), private$data_period)
      if (NCOL(data) == 0) {
        return(invisible(NULL))
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
      
      # handle labels
      lbls <- ts_labels(data)
      if (!is.null(lbls)) {
        names(lbls) <- names
        private$update_labels(lbls)
      }
      
      if (type == "endo") {
        names <- intersect(names, private$endo_names)
      } else  {
        names <- intersect(names, private$exo_names)
      }
      
      if (length(names) == 0) {
        return(invisible(self))
      }
      
      data <- data[per, names, drop = FALSE]
      
      apply_fun <- !missing(fun)
      if (upd_mode != "upd" || apply_fun) {
        if (type == "endo") {
          old_data <- private$endo_data[per, names, drop = FALSE]
        } else {
          old_data <- private$exo_data[per, names, drop = FALSE]
        }
      }

      if (apply_fun) {
        new_data <- fun(old_data, data)
      } else {
        new_data <- data
      }
      
      if (upd_mode == "updval") {
        # restore old values when data is false
        sel <- is.na(data)
        new_data[sel] <- old_data[sel]
      }
      
      if (type == "endo") {
        private$endo_data[per, names] <- new_data
      } else {
        private$exo_data[per, names] <- new_data
      }
      return (invisible(self))
    },
    set_values_ = function(value, names, pattern, period, type) {
      value <- as.numeric(value)
      period <- private$convert_period_arg(period)
      nper <- nperiod(period)
      vlen <- length(value)
      if (vlen != 1 && vlen < nper) {
        stop(paste("Argument value should have length 1 or",
                   "length ", nper))
      }
      period <- range_intersect(period, private$data_period)
      names <- private$get_names_(type, names, pattern)
      if (length(names) > 0) {
        if (vlen > 1) {
          value <- value[1:nperiod(period)]
        }
        if (type == "endo") {
          private$endo_data[period, names] <- value
        } else {
          private$exo_data[period, names]  <- value
        }
      }
      return(invisible(NULL))
    },
    change_data_ = function(fun, names, pattern, period, type, ...) {
      period <- private$convert_period_arg(period)
      if (!is.function(fun)) {
        stop("argument fun is not a function")
      }
      nper <- nperiod(period)
      names <- private$get_names_(type, names, pattern)
      if (type == "endo") {
        data <- self$get_endo_data(names = names, period = period)
      } else  { 
        data <- self$get_exo_data(names = names, period = period)
      }
      for (c in seq_len(ncol(data))) {
        data[, c] <- fun(data[, c], ...)
      }
      private$set_data_(data, names = names, names_missing = FALSE, 
                        type = type)
    },
    get_endo_lags = function() {
      if (private$mdldef$max_endo_lag > 0) {
        p <- start_period(private$model_period)
        lag_per <- period_range(p - private$mdldef$max_endo_lag, p - 1)
        return(t(private$endo_data[lag_per, ]))
      } else {
        return(NULL)
      }
    },
    get_endo_leads = function() {
      if (private$mdldef$max_endo_lead > 0) {
        p <- end_period(private$model_period)
        lead_per <- period_range(p + 1, p + private$mdldef$max_endo_lead)
        return(t(private$endo_data[lead_per, ]))
      } else {
        return(NULL)
      }
    },
    # returns a vector with endogenous variables in the solution period
    get_solve_endo = function() {
      return (t(private$endo_data[private$model_period, ]))
    },
    # returns the residual of the stacked-time system
    # x is vector of endogenous variables in the solution period
    get_residuals = function(x, lags, leads, nper) {
      endos <- c(lags, x, leads)
      nper <- nperiod(private$model_period)
      if (private$calc == "internal") {
        # for the time begin, assume that the model index is 0
        return(get_residuals_dyn(private$mdldef$model_index, endos,
                                 which(private$mdldef$lead_lag_incidence != 0) - 1,
                                 private$mdldef$endo_count, nper,
                                private$period_shift))
      } else {
        return(get_residuals_(endos,
                              which(private$mdldef$lead_lag_incidence != 0) - 1,
                              private$exo_data, private$mdldef$params,
                              private$f_dynamic, private$mdldef$endo_count,
                              nper, private$period_shift))
      }
    },
    get_jac = function(x, lags, leads, nper) {
      endos <- c(lags, x, leads)
      nper <- nperiod(private$model_period)
      tshift  <- -private$mdldef$max_endo_lag : private$mdldef$max_endo_lead
      if (private$calc == "internal") {
        # for the time begin, assume that the model index is 0
        mat_info <- get_triplet_jac_dyn(private$mdldef$model_index, endos, 
                          private$mdldef$lead_lag_incidence, tshift, 
                          private$mdldef$endo_count, nper, private$period_shift)
      } else {
        mat_info <- get_triplet_jac(endos, private$mdldef$lead_lag_incidence,
                                    tshift, private$exo_data,
                                    private$mdldef$params, private$jac_dynamic,
                                    private$mdldef$endo_count, nper,
                                    private$period_shift)
      }
      n <- nper * private$mdldef$endo_count
      # NOTE: the function sparseMatrix of the Matrix package
      # only works correctly when package methods has been attached.
      # Therefore "methods" is added to Depends in the DESCRIPTION file.
      # Possibly, in the Matrix package one of functions of methods is
      # not imported from.
      return(sparseMatrix(i = mat_info$rows, j = mat_info$cols,
                          x = mat_info$values,
                          dims = as.integer(rep(n, 2))))
    },
    get_static_jac = function(x) {
      if (private$calc == "internal") {
        mat_info <- get_triplet_jac_stat(private$mdldef$model_index, 
                                         private$mdldef$endos)
      } else {
        mat_info <- private$jac_static(x, private$mdldef$exos, 
                                       private$mdldef$params)
      }
      return(sparseMatrix(i = mat_info$rows, j = mat_info$cols,
                          x = mat_info$values, 
                          dims = as.integer(rep(private$mdldef$endo_count, 2))))
    },
    get_back_jac = function(x, lags, iper) {
      # private function to obtain the backward jacobian at period iper
      jac_cols <- private$mdldef$lead_lag_incidence[, "0"]
      if (private$calc == "internal") {
        mat_info <- get_jac_back_dyn(private$mdldef$model_index, x, lags, 
                                     jac_cols, iper)
      } else {
        mat_info <- get_jac_backwards(x, lags, jac_cols, private$exo_data, 
                                      private$mdldef$params, 
                                      private$jac_dynamic, iper)
      }
      return(sparseMatrix(i = mat_info$rows, j = mat_info$cols,
                          x = mat_info$values, 
                          dims = as.integer(rep(private$mdldef$endo_count, 2))))
    },
    prepare_dynamic_model = function() {
      #
      # prepare dll calculations or the internal calculator
      #
      if (private$calc == "dll") {
        private$nrow_exo <- nrow(private$exo_data)
        private$jac  <- list(rows   = integer(private$mdldef$jac_dynamic_size),
                           cols   = integer(private$mdldef$jac_dynamic_size),
                           values = numeric(private$mdldef$jac_dynamic_size))
        dyn.load(private$dll_file)
        # NOTE: the basename of the dll_file is always "mdl_functions".
        # Therefore we cannot solve two DynMdl objects simultaneously.
        # This will always never occur, except when the model contains
        # a function that calls another function.
        #
      } else if (private$calc == "internal") {
        prepare_internal_dyn(private$mdldef$model_index, private$exo_data,
                              nrow(private$exo_data), private$mdldef$params)
      }
      
      # prepare the auxiliary variables
      if (private$mdldef$aux_vars$aux_count > 0) {
        private$prepare_aux_vars()
      }
      
      return(invisible(NULL))
    },
    clean_dynamic_model = function() {
      if (private$calc == "dll") {
        private$nrow_exo <- NA_integer_
        private$jac <- NULL
        dyn.unload(private$dll_file)
      }
      return(invisible(NULL))
    },
    prepare_static_model = function() {
      if (private$calc == "dll") {
        private$jac_steady <- list(rows   = integer(private$mdldef$jac_static_size),
                                   cols   = integer(private$mdldef$jac_static_size),
                                   values = numeric(private$mdldef$jac_static_size))
        dyn.load(private$dll_file)
      } else if (private$calc == "internal") {
        prepare_internal_stat(private$mdldef$model_index, private$mdldef$exos,
                              private$mdldef$params)
      }
      return(invisible(NULL))
    },
    clean_static_model = function() {
      if (private$calc == "dll") {
        private$jac_steady <- NULL
        dyn.unload(private$dll_file)
      }
      return(invisible(NULL))
    },
    prepare_aux_vars = function() {
      # calculate the auxiliary auxiliary variables before solving
      if (private$mdldef$aux_vars$aux_count == 0) {
        return(invisible(NULL))
      }
      nper <- nrow(private$endo_data)
      with(private$mdldef$aux_vars, {
        for (i in seq_len(aux_count)) {
          if (orig_leads[i] > 0) {
            sel_orig <- (1 + orig_leads[i]) : nper
          } else {
            sel_orig <- 1 : (nper + orig_leads[i])
          }
          sel_endo <- sel_orig - orig_leads[i]
          private$endo_data[sel_endo , endos[i]] <- 
                        private$endo_data[sel_orig , orig_endos[i]]
        }
      })
      return(invisible(NULL))
    },
    check_model_period = function(period) {
      
      if (frequency(period) != frequency(private$data_period)) {
        stop(paste0("The specified period (", period, 
                    ") has a different frequency than the data period (",
                    private$data_period, ")."))
      }
      
      ps <- start_period(private$data_period) + private$mdldef$max_lag
      pe <- end_period(private$data_period)   - private$mdldef$max_lead
      
      if ((start_period(period) < ps)  || (end_period(period)   > pe)) { 
        stop(paste0("The specified period (", period, 
                    ") is not compatible with the data period (",
                    private$data_period, "). The period",
                    " should lie within the range ",
                    period_range(ps, pe), "."))
      }
      return(invisible(NULL))
    },
    update_labels = function(labels) {
      if (is.null(labels)) {
        private$mdldef$labels <- NULL
      } else {
        names <- intersect(names(labels), union(private$endo_names, 
                                                private$exo_names))
        if (is.null(private$mdldef$labels)) {
          private$mdldef$labels <-character(0)
        }
        private$mdldef$labels[names] <- labels[names]
        if (length(private$mdldef$labels) > 0) {
          private$mdldef$labels <- private$mdldef$labels[order(
                                              names(private$mdldef$labels))]
        }
      }
      return(invisible(NULL))
    },
    set_mdldef = function(mdldef) {
      private$mdldef <- mdldef
      private$endo_names <- names(private$mdldef$endos)
      private$exo_names <- names(private$mdldef$exos)
      private$param_names <- names(private$mdldef$params)
    },
    make_functions = function() {
      
      if (private$calc == "R" || private$calc == "bytecode") {
        
        # no dll, functions implemented in R
        eval(parse(text = private$mdldef$static_functions))
        eval(parse(text = private$mdldef$dynamic_functions))
        private$f_static    <- f_static
        private$jac_static  <- jac_static
        private$f_dynamic   <- f_dynamic
        private$jac_dynamic <- jac_dynamic
        
        if (private$calc == "bytecode") {
          private$f_static < - compiler::cmpfun(private$f_static)
          private$f_dynamic <- compiler::cmpfun(private$f_dynamic)
        }
        
      } else if (private$calc == "dll") {    # dll option
        
        private$f_static <- function(y, x, params) {
          res <- numeric(private$mdldef$endo_count)
          .Call("f_static_", y, x, params, res, PACKAGE = "mdl_functions")
          return(res)
        }
        
        private$jac_static <- function(y, x, params) {
          # NOTE: creating a new jac_steady every function call is
          # inefficient, therefore use private$jac_steady that is
          # created just before solve_steady is called.
          .Call("jac_static_", y, x, params, private$jac_steady$rows,
                private$jac_steady$cols, private$jac_steady$values,
                PACKAGE = "mdl_functions")
          return(private$jac_steady)
        }
        
        private$f_dynamic <- function(y, x, params, it) {
          res <- numeric(private$mdldef$endo_count)
          .Call("f_dynamic_", y, x, params, it - 1, private$nrow_exo,
                res, PACKAGE = "mdl_functions")
          return(res)
        }
        
        private$jac_dynamic <- function(y, x, params, it) {
          # NOTE: creating a new jac every function call is
          # inefficient, therefore use private$jac that is
          # created just before solve is called.
          .Call("jac_dynamic_", y, x, params, it - 1, private$nrow_exo,
                private$jac$rows, private$jac$cols, private$jac$values,
                PACKAGE = "mdl_functions")
          return(private$jac)
        }
        
      } else if (private$calc == "internal") {
        
        private$jac_dynamic <- function(y, x, params, it) {
          # note: x and params set by prepare_dynamic_model
          return(get_jac_dyn(private$mdldef$model_index, y, it - 1))
        }
      }
    },
    print_info = function(short) {
      cat(sprintf("%-60s%s\n", "Calc method:", private$calc))
      if (private$calc == "internal") {
        cat(sprintf("%-60s%d\n", "Model index:",
                    private$mdldef$model_index))
      }
      cat(sprintf("%-60s%d\n", "Number of endogenous variables:",
                  private$mdldef$endo_count))
      cat(sprintf("%-60s%d\n", "Number of exogenous variables:",
                  private$mdldef$exo_count))
      cat(sprintf("%-60s%d\n", "Maximum endogenous lead:",
                  private$mdldef$max_endo_lead))
      cat(sprintf("%-60s%d\n", "Maximum endogenous lag:",
                  private$mdldef$max_endo_lag))
      cat(sprintf("%-60s%d\n", "Maximum exogenous lead:",
                  private$mdldef$max_exo_lead))
      cat(sprintf("%-60s%d\n", "Maximum exogenous lag:",
                  private$mdldef$max_exo_lag))
      cat(sprintf("%-60s%d\n", "Number of nonzeros static. jac:",
                  private$mdldef$jac_static_size))
      cat(sprintf("%-60s%d\n", "Number of nonzeros dyn. jac:",
                  private$mdldef$jac_dynamic_size))
      if (!is.null(private$model_period)) {
        cat(sprintf("%-60s%s\n", "Model period:",
                    as.character(private$model_period)))
        cat(sprintf("%-60s%s\n", "Data period:",
                    as.character(private$data_period)))
      }
      if (!short) {
        cat("Names of the endogenous variables:\n")
        print(private$endo_names)
        cat("Names of the exogenous variables:\n")
        print(private$exo_names)
        cat("Names of the parameters:\n")
        print(private$param_names)
        cat("Lead lag incidence matrix:\n")
        print(private$mdldef$lead_lag_incidence)
        cat("\nstatic function:\n")
        print(private$f_static)
        cat("\nstatic Jacobian:\n")
        print(private$jac_static)
        cat("\ndynamic function:\n")
        print(private$f_dynamic)
        cat("\ndynamic jacobian:\n")
        print(private$jac_dynamic)
      }
    },
    convert_period_arg = function(period, data_period = TRUE) {
      if (is.null(private$model_period)) {
        stop(private$period_error_msg)
      }
      period <- as.period_range(period)
      period <- change_frequency(period, frequency(private$data_period))
      if (frequency(period) != frequency(private$data_period)) {
        stop(paste0("Period ", period, " has a different frequency than ",
                    "the model period ", private$model_period, "."))
      }
      if (data_period) {
        defaultp <- private$data_period
      } else {
        defaultp <- private$model_period
      }
      startp <- start_period(period)
      if (is.null(startp)) {
        startp <- start_period(defaultp)
      }
      endp <- end_period(period)
      if (is.null(endp)) {
        endp <- end_period(defaultp)
      }
      return(period_range(startp, endp))
    }
  )
)
