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
#' \item{\code{get_endo_names()}}{Returns the names of the endogenous variables.}
#
#' \item{\code{get_exo_names()}}{Returns the names of the exogenous variables.}
#'
#' \item{\code{\link{set_labels}}}{Set labels for the model variables}
#'
#' \item{\code{\link{get_labels}}}{Returns the labels of the model variables.}
#'
#' \item{\code{get_par_names()}}{Returns the names of the parameters.}
#'
#' \item{\code{set_param()}}{Sets the parameters of the model.}
#'
#' \item{\code{get_param()}}{Returns the parameters of the model.}
#'
#' \item{\code{set_static_exos(exos)}}{Sets the static values of
#' the exogenous variables. These values are used to compute the steady state.}
#'
#' \item{\code{get_static_exos()}}{Returns the static values of
#' the exogenous variables}
#'
#' \item{\code{set_static_endos}}{Sets the static values of
#' the endos variables. These values are used to compute the steady state.}
#'
#' \item{\code{get_static_endos}}{Returns the static values of
#' the endogenous variables, i.e. the values that are supposed to be
#' the steady state values. Function \code{solve_steady} can be used
#' to compute them. After compiling the model, the
#' static endos are initialized with zeros and the values in the \code{initval}
#' block in the  \code{mdl} file. There is no setter for the static values:
#' you can only modify them by calling function \code{solve_steady}}
#'
#' \item{\code{\link{init_data}}}{Initializes the model data}
#'
#' \item{\code{\link{set_period}}}{Sets the model period}
#'
#' \item{\code{\link{get_period}}}{Returns the model period}
#'
#' \item{\code{\link{get_data_period}}}{Returns the model data period}
#'
#' \item{\code{get_lag_period}}{Returns the lag period}
#'
#' \item{\code{get_lead_period}}{Returns the lead period}
#'
#' \item{\code{\link{set_endo_values}}}{Sets the values of endogenous model variables}
#'
#' \item{\code{\link{set_exo_values}}}{Sets the values of exogenous model variables}
#'
#' \item{\code{\link{set_data}}}{Transfer timeseries to the model data}
#'
#' \item{\code{\link{change_endo_data}}}{Changes the values of endogenous model variables
#' by applying a function}
#'
#' \item{\code{\link{change_exo_data}}}{Changes the values of exogenous model variables
#' by applying a function}
#'
#' \item{\code{\link{get_endo_data}}}{Returns the endogenous model data}
#'
#' \item{\code{\link{get_exo_data}}}{Returns the exogenous model data}
#'
#' \item{\code{\link{solve_steady}}}{Solves the steady state}
#'
#' \item{\code{\link{solve}}}{Solves the model}
#' 
#' \item{\code{check()}}{Compute the eigenvalues of the linear
#' system and check if the Blachard and Kahn conditions are satisfied.}
#'
#' \item{\code{solve(control = list())}}{Solves the model using a stacked-time
#' Newton method for the whole model period.
#' Argument \code{control} is a list with solve options (TODO: describe these
#' options somewhere).}
#'
#' \item{\code{\link{residual_check}}}{Calculates the residuals of the equation
#' and report the differences larger than a tolerance parameters}
#'
#' \item{\code{solve_perturbation()}}{Solves the model using the perturbation
#' theory used in the Dynare function stoch_simul. Only shocks in the first
#' solution period are allowed.}
#'
#' \item{\code{get_jacob}}{Returns the Jacobian for the static problem}
#'
#' \item{\code{get_static_jacob}}{Returns the Jacobian for the
#' stacked-time Newton problem}
#'
#' \item{\code{get_eigval(}}{Returns the eigenvalues of the linearized model.
#' computed with functiomn \code{check()} of \code{solve_perturbation()},
#' ordered with increasing absolute value}
#' 
#' \item{\code{\link{get_equations}}}{Returns a character vector with the 
#' equations of the model.}
#' 
#' \item{\code{\link{copy}}}{Returns a deep copy of the \code{\link{DynMdl}} object}
#'
#' }
DynMdl <- R6Class("DynMdl",
  public = list(
    initialize = function(model_info, params, equations, 
                          bytecode, use_dll, dll_dir, dll_file) {
      
      private$model_info <- model_info
      private$equations <- equations
      
      if (use_dll) {
        reg.finalizer(self,
                      function(e) {
                        #unlink(private$dll_dir, recursive = TRUE)
                      },
                      onexit = TRUE)
      } 
      
      private$bytecode <- bytecode
      private$use_dll <- use_dll
      private$dll_dir <- dll_dir
      private$dll_file <- dll_file
      
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
        private$jac_static_size    <- static_model$jac_size
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
        private$f_static <- function(y, x, params) {
          res <- numeric(private$endo_count)
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
          res <- numeric(private$endo_count)
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
      } else {
        # no dll, functions implemented in R
        eval(parse(text = model_info$static_model$static_functions))
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
      cat("DynMdl object\n")
      private$print_info(short)
      return (invisible(NULL))
    },
    get_max_lag = function() {
      return(private$max_lag)
    },
    get_max_lead = function() {
      return(private$max_lead)
    },
    get_endo_names = function(pattern) {
      return(private$endo_names)
    },
    get_exo_names = function(pattern) {
      return(private$exo_names)
    },
    set_labels = function(labels) {
      private$update_labels(labels)
    },
    get_labels = function() {
      return(private$labels)
    },
    get_par_names = function(pattern = ".*") {
      names <- private$param_names
      if (!missing(pattern)) {
        sel <- grep(pattern, names)
        names <- names[sel]
      }
      return(sort(names))
    },
    set_param = function(params) {
      private$params[names(params)] <- params
      return (invisible(self))
    },
    get_param = function(pattern, names) {
      if (missing(pattern) && missing(names)) {
        names <- self$get_par_names()
      } else if (missing(names)) {
        names <- self$get_par_names(pattern)
      } else if (!missing(pattern)) {
        names <- union(names, self$get_par_names(pattern))
      }
      return(private$params[names])
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
      endo_mat <- matrix(rep(private$endos, each = nper), nrow = nper)
      private$endo_data <- regts(endo_mat, start = start_period(data_period),
                                 names = names(private$endos))
      if (private$exo_count > 0) {
        exo_mat <- matrix(rep(private$exos, each = nper), nrow = nper)
        colnames(exo_mat) <- private$exo_names
      } else {
        exo_mat <- matrix(NA_real_, nrow = nper, ncol = 0)
      }
      private$exo_data <- regts(exo_mat, start = start_period(data_period))
      
      # update the model period
      startp <- start_period(data_period) + private$max_lag
      endp <- end_period(data_period) - private$max_lead
      if (endp >= startp) {
        private$model_period <- period_range(startp, endp)
        private$period_shift <- start_period(private$model_period) - 
                                start_period(private$data_period)
      } else {
        stop(paste("The data period is too short. It should contain at least",
                   private$max_lag + private$max_lead + 1, "periods"))
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
          start_period(period) - private$max_lag,
          end_period(period)   + private$max_lead)
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
      if (private$max_lag > 0) {
        p <- start_period(private$data_period)
        return (period_range(p, p + private$max_lag - 1))
      } else {
        return (NULL)
      }
    },
    get_lead_period = function() {
      if (private$max_lead > 0) {
        p <- end_period(private$data_period)
        return (period_range(p - private$max_lead + 1, p))
      } else {
        return (NULL)
      }
    },
    get_exo_data = function(pattern = NULL, names = NULL, 
                            period = private$data_period) {
      period <- private$convert_period_arg(period)
      if (private$exo_count == 0) {
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
      return(update_ts_labels(ret, private$labels))
    },
    set_endo_values = function(value, names = NULL, pattern = NULL,
                               period = private$data_period) {
      private$set_values_(value, names, pattern, period, type = "endo")
      return (invisible(self))
    },
    set_exo_values = function(value, names = NULL, pattern = NULL,
                              period = private$data_period) {
      private$set_values_(value, names, pattern, period, type = "exo")
      return (invisible(self))
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
      if (missing(pattern) && missing(names)) {
        ret <- private$endo_data[period, ]
      } else {
        names <- private$get_names_("endo", names, pattern)
        if (length(names) == 0) {
          return(NULL)
        }
        ret <- private$endo_data[period, names, drop = FALSE]
      }
      return(update_ts_labels(ret, private$labels))
    },
    change_endo_data = function(fun, names= NULL, pattern = NULL, 
                                period = private$data_period , ...) {
      return(private$change_data_(fun, names, pattern, period, "endo", ...))
    },
    change_exo_data = function(fun, names= NULL, pattern = NULL, 
                               period = private$data_period , ...) {
      return(private$change_data_(fun, names, pattern, period, "exo", ...))
    },
    solve_steady = function(start = self$get_static_endos(),
                            init_data = TRUE, control = NULL,
                            solver = c("umfpackr", "nleqslv")) {

      solver <- match.arg(solver)
      
      f <- function(endos) {
        return(private$f_static(endos, private$exos, private$params))
      }
      
      if (private$use_dll) private$prepare_solve_steady()

      if (solver == "umfpackr") {
        out <- umf_solve_nl(start, fn = f, jac = private$get_static_jac, 
                            control = control)
        error <- !out$solved
      } else {
        jacf <- function(endos) {
          j <- private$get_static_jac(endos)
          return(as(j, "matrix"))
        }
        out <- nleqslv(start, fn = f, jac = jacf, method = "Newton",
                       control = control)
        error <- out$termcd != 1
      }
      if (private$use_dll) private$clean_after_solve_steady()

      private$endos <- out$x

      if (error) {
        stop(paste("Error solving the steady state.\n", out$message))
      }
      
      if (init_data && !is.null(private$endo_data)) {
        # update the model data
        nper <- nperiod(private$data_period)
        private$endo_data[ , ] <- matrix(rep(private$endos, each = nper),
                                         nrow = nper)
      }
      
      
      return (invisible(self))
    },
    check = function() {
  
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
    residual_check = function(tol = 0) {
      if (is.null(private$model_period)) stop(private$period_error_msg)
      if (private$use_dll) private$prepare_solve()
      
      nper <- nperiod(private$model_period)
      lags <- private$get_endo_lags()
      leads <- private$get_endo_leads()
      x <- private$get_solve_endo()
      
      residuals <- private$get_residuals(x, lags, leads, nper)
      dim(residuals) <- c(private$endo_count, nper)
      residuals <- t(residuals)
      colnames(residuals) <- paste0("eq_", 1 : private$endo_count)
      p_start <- start_period(private$model_period)
      p_end <- end_period(private$model_period)
      if (tol != 0) {
        col_sel <- apply(residuals, MARGIN = 2, FUN = function(x) max(abs(x)) > tol)
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
                     solver = c("umfpackr", "nleqslv")) {
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
      
      if (private$use_dll) private$prepare_solve()
      
      if (private$max_endo_lead > 0 || force_stacked_time ) {
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
                            control = control_)
        if (!control_$silent) {
          cat(sprintf("Total time function eval. : %g\n", ret$t_f))
          cat(sprintf("Total time Jacobian.      : %g\n", ret$t_jac))
          cat(sprintf("Total time LU fact.       : %g\n", ret$t_lu))
          cat(sprintf("Total time solve          : %g\n", ret$t_solve))
        }
      } else {
        ret <- solve_backward_model(private$model_period,
                                    private$period_shift,
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
      
      if (!ret$solved) {
        stop(paste("Model solving not succesfull.\n", ret$message))
      }
      return(invisible(self))
    },
    solve_perturbation = function() {

      if (is.null(private$model_period)) stop(private$period_error_msg)
      
      if (private$use_dll) private$prepare_solve()
      
      # solve_perturbation does not works for exogenous lags and leads.
      # For perturbation approaches, Dynare substitutes
      # these lags and leads by creating auxiliary variables and
      # equations. dynmdl does not do that.
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
      if (is.null(private$model_period)) stop(private$period_error_msg)
      lags  <- private$get_endo_lags()
      leads <- private$get_endo_leads()
      nper <- nperiod(private$model_period)
      x <- private$get_solve_endo()
      if (private$use_dll) private$prepare_solve()
      jac <- private$get_jac(x, lags, leads, nper)
      if (private$use_dll) private$clean_after_solve()
      if (!sparse) {
        jac <- as(jac, "matrix")
      }
      colnames(jac) <- as.character(outer(private$endo_names, 1:nper, 
                                          FUN = "paste", sep ="_t"))
      rownames(jac) <- as.character(outer(paste0("eq_", 1:private$endo_count), 
                                          1:nper, FUN = "paste", sep ="_t"))
      return(jac)
    },
    get_static_jacob = function(sparse = TRUE) {
      if (private$use_dll) private$prepare_solve_steady()
      jac <- private$get_static_jac(private$endos)
      if (!sparse) {
        jac <- as(jac, "matrix")
      }
      colnames(jac) <- private$endo_names
      if (private$use_dll) private$clean_after_solve_steady()
      return(jac)
    },
    get_equations = function(i = 1:private$endo_count) {
      if (!is.numeric(i)) {
        stop("Argument i should be a numeric")
      }
      return(private$equations[i])
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
      if (private$use_dll) {
        zip_file <- tempfile(pattern = "dynmdl_dll_", fileext = ".zip")
        zip(zipfile = zip_file, files = private$dll_dir, extra = "-q")
        size <- file.info(zip_file)$size
        dll_data <- readBin(zip_file, what = "raw", n = size)
        unlink(zip_file)
      } else {
        dll_data <- NULL
      }
      
      if (private$use_dll) {
        os_type <- .Platform$OS.type
      } else {
        # if we do not use dll, then we don't care about the 
        # operating system type
        os_type <- NULL
      }
      serialized_mdl <- list(version = packageVersion("dynmdl"),
                             model_info = private$model_info, 
                             equations = private$equations,
                             bytecode = private$bytecode,
                             use_dll = private$use_dll, dll_data = dll_data,
                             dll_basename = basename(private$dll_file),
                             os_type = .Platform$OS.type,
                             params = private$params,
                             endos = private$endos,
                             exos = private$exos,
                             labels = private$labels,
                             period = private$model_period,
                             endo_data = private$endo_data,
                             exo_data = private$exo_data)
      return(structure(serialized_mdl, class = "serialized_dynmdl"))
    }
  ),
  private = list(
    model_info = NULL,
    equations = NULL,
    exo_count = NA_integer_,
    endo_count = NA_integer_,
    exo_names = NULL,
    endo_names = NULL,
    labels = NULL,
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
    jac_static_size = NA_integer_,
    jac_dynamic_size = NA_integer_,
    model_period = NULL,
    data_period =  NULL,
    period_shift =  NA,
    endo_data = NULL,
    exo_data = NULL,
    ss = NULL,
    bytecode = FALSE,
    use_dll = FALSE,
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
    set_data_= function(data, names, names_missing, type, upd_mode = "upd", 
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
      
      per <- range_intersect(get_period_range(data),
                             private$data_period)
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
      if (private$max_endo_lag > 0) {
        p <- start_period(private$model_period)
        lag_per <- period_range(p - private$max_endo_lag, p - 1)
        return(t(private$endo_data[lag_per, ]))
      } else {
        return(NULL)
      }
    },
    get_endo_leads = function() {
      if (private$max_endo_lead > 0) {
        p <- end_period(private$model_period)
        lead_per <- period_range(p + 1, p + private$max_endo_lead)
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
      return(get_residuals_(endos,
                            which(private$lead_lag_incidence != 0) - 1,
                            private$exo_data, private$params,
                            private$f_dynamic, private$endo_count,
                            nper, private$period_shift))
    },
    get_jac = function(x, lags, leads, nper) {
      endos <- c(lags, x, leads)
      nper <- nperiod(private$model_period)
      tshift  <- -private$max_endo_lag : private$max_endo_lead
      mat_info <- get_triplet_jac(endos, private$lead_lag_incidence,
                                  tshift, private$exo_data,
                                  private$params, private$jac_dynamic,
                                  private$endo_count, nper,
                                  private$period_shift)
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
    get_static_jac = function(x) {
      mat_info <- private$jac_static(x, private$exos, private$params)
      return(sparseMatrix(i = mat_info$rows, j = mat_info$cols,
                          x = mat_info$values, 
                          dims = as.integer(rep(private$endo_count, 2))))
    },
    prepare_solve = function() {
      private$nrow_exo <- nrow(private$exo_data)
      private$jac  <- list(rows   = integer(private$jac_dynamic_size),
                           cols   = integer(private$jac_dynamic_size),
                           values = numeric(private$jac_dynamic_size))
      dyn.load(private$dll_file)
      #
      # NOTE: the basename of the dll_file is always "mdl_functions".
      # Therefore we cannot solve two DynMdl objects simultaneously.
      # This will always never occur, except when the model contains
      # a function that calls another function.
      #
      return(invisible(NULL))
    },
    clean_after_solve = function() {
      private$nrow_exo <- NA_integer_
      private$jac <- NULL
      dyn.unload(private$dll_file)
      return(invisible(NULL))
    },
    prepare_solve_steady = function() {
      private$jac_steady <- list(rows   = integer(private$jac_static_size),
                                 cols   = integer(private$jac_static_size),
                                 values = numeric(private$jac_static_size))
      dyn.load(private$dll_file)
      return(invisible(NULL))
    },
    clean_after_solve_steady = function() {
      private$jac_steady <- NULL
      dyn.unload(private$dll_file)
      return(invisible(NULL))
    },
    check_model_period = function(period) {
      
      ps <- start_period(private$data_period) + private$max_lag
      pe <- end_period(private$data_period)   - private$max_lead
      
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
        private$labels <- NULL
      } else {
        names <- intersect(names(labels), union(private$endo_names, 
                                                private$exo_names))
        if (is.null(private$labels)) {
          private$labels <-character(0)
        }
        private$labels[names] <- labels[names]
        if (length(private$labels) > 0) {
          private$labels <- private$labels[order(names(private$labels))]
        }
      }
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
      cat(sprintf("%-60s%d\n", "Number of nonzeros static. jac:",
                  private$jac_static_size))
      cat(sprintf("%-60s%d\n", "Number of nonzeros dyn. jac:",
                  private$jac_dynamic_size))
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
    },
    convert_period_arg = function(period, data_period = TRUE) {
      if (is.null(private$model_period)) {
        stop(private$period_error_msg)
      }
      period <- as.period_range(period)
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
