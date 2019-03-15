#' An R6 class for a Dynare model with Fit targets
#' 
#' This class is a subclass of a \code{\link{DynMdl}} objects. It contains
#' special methods for the fit procedure.
#'
#' @docType class
#' @importFrom R6 R6Class
#' @importFrom Rcpp sourceCpp
#' @importFrom regts start_period
#' @importFrom regts period_range
#' @importFrom regts regts
#' @importFrom regts zero_trim
#' @importFrom regts na_trim
#' @importFrom regts remove_na_columns
#' @importFrom tools file_path_sans_ext
#' @export
#' @keywords data
#' @return Object of \code{\link{R6Class}} containing a macro-economic model,
#' @format \code{\link{R6Class}} object.
#'
#' @section Methods:
#' \describe{
#'
#' \item{\code{\link{get_endo_names}}}{Returns the names of the endogenous variables
#' of the model (excluding the instruments and Lagrange multipliers used in the
#' fit procedure).}
#'
#' \item{\code{\link{get_exo_names}}}{Returns the names of the exogenous variables
#' of the model (excluding the fit control variables).}
#'
#' \item{\code{\link{get_instrument_names}}}{Returns the names of the fit 
#' instruments.}
#' 
#' \item{\code{\link{get_sigma_names}}}{Returns the names of the sigma
#' parameters used in the fit procedure.} 
#'
#' \item{\code{\link{set_fit_values}}}{Sets the values of the fit targets}
#'
#' \item{\code{\link{set_fit}}}{Sets the targets for the fit procedure} 
#'
#' \item{\code{\link{get_fit}}}{Returns the fit targets
#' used in the fit procedure}
#'
#' \item{\code{\link{get_fit_instruments}}}{Returns all non-zero fit instruments
#' used in the fit procedure}
#' 
#' \item{\code{get_sigmas}}{Returns all sigma parameters >= 0 (rms values)
#' used in the fit procedure. If a sigma parameter is negative, then the 
#' corresponding fit instrument is not included}
#' 
#' \item{\code{\link{get_lagrange}}}{Returns the Lagrange multipliers
#' used in the fit procedure.}
#' }
FitMdl <- R6Class("FitMdl",
  inherit = DynMdl,
  public = list(
    initialize = function(mdldef, fit_info, equations, base_period, 
                          calc, dll_dir, dll_file, debug = FALSE) {

      # no arguments supplied
      if (nargs() == 0) return()
      
      super$initialize(mdldef, equations, base_period, calc, dll_dir,  
                       dll_file)
      
      private$fit_info <- fit_info
    }, 
    print = function(short = TRUE) {
      cat("FitMdl object\n")
      cat("Information about the original model:\n")
      exo_count_orig  <- length(private$fit_info$orig_exos)
      endo_count_orig <- length(private$fit_info$orig_endos)
      cat(sprintf("%-60s%d\n", "Number of endogenous variables:",
                  endo_count_orig))
      cat(sprintf("%-60s%d\n", "Number of exogenous variables:",
                  exo_count_orig))
      cat("Information about the fit procedure:\n")
      cat(sprintf("%-60s%d\n", "Number of potential fit instruments:",
                  length(private$fit_info$sigmas)))
      cat("Information about the expanded model for the fit procedure:\n")
      private$print_info(short)
      return (invisible(NULL))
    },
    get_endo_names = function(type = c("all", "lag", "lead")) {
      type <- match.arg(type)
      if (type != "all") {
        names <- super$get_endo_names(type)
        return(intersect(private$fit_info$orig_endos, names))
      } else {
        return(private$fit_info$orig_endos)
      }
    },
    get_exo_names = function() {
      return(private$fit_info$orig_exos)
    },
    get_instrument_names = function() {
      return(private$fit_info$instruments)
    },
    get_sigma_names = function() {
      return(private$fit_info$sigmas)
    },
    set_fit = function(data, names, name_err = c("stop", "warn", "silent")) {
      
      if (!inherits(data, "ts")) {
        # we use inherits and not is.ts, because is.ts returns FALSE if
        # length(x) == 0
        stop("Argument data is not a timeseries object")
      }
    
      # TODO: combine this code with set_data()?
      if (missing(names)) {
        if (!is.null(colnames(data))) {
          names <- colnames(data)
        } else {
          stop(paste("Argument data has no colnames.",
                     "In that case, argument names should be specified"))
        }
      } else {
        # check if specified argument names is o.k.
        if (is.null(names)) {
          stop("names is null")
        } else if (length(names) < NCOL(data)) {
          stop(paste("The length of arument names is less than the number of",
                     "columns of data"))
        }
      }
      
      names <- private$get_names_fitmdl_("endo", names, name_err = name_err)
      if (length(names) == 0) return(invisible(self))
      
      if (!is.matrix(data)) {
        dim(data) <- c(length(data), 1)
        colnames(data) <- names
      }
      
      data <- data[ , names, drop = FALSE]
      
      return(private$set_fit_internal(data, get_period_range(data)))
    },
    set_fit_values = function(value, names, pattern, 
                              period = private$data_period) {
      value <- as.numeric(value)
      period <- private$convert_period_arg(period)
      nper <- nperiod(period)
      vlen <- length(value)
      if (vlen != 1 && vlen < nper) {
        stop(paste("Argument value should have length 1 or length", nper))
      }
      
      names <- private$get_names_fitmdl_("endo", names, pattern)
      nvar <- length(names)
      if (nvar == 0) return(invisible(self))
      
      data <- matrix(rep(value, nvar), ncol = nvar)
      data <- regts(data, period = period, names = names)
      return(private$set_fit_internal(data, period))
    },
    get_data = function(pattern, names, period = private$data_period,
                        trend = TRUE) {
      names <- private$get_names_fitmdl_("all", names, pattern)
      if (length(names) == 0) {
        return(NULL)
      }
      inst_names <- intersect(names, private$fit_info$instruments)
      no_inst_names <- setdiff(names, inst_names)
    
      # NOTE: we cannot simply use super$get_data(names = names,...),
      # because this method calls method get_endo_data() of FitMdl and this 
      # method does not return fit instruments.
      no_inst_data <- super$get_data(names = no_inst_names, period = period, 
                                     trend = trend)
      if (length(inst_names) > 0) {
        inst_data <- self$get_fit_instruments(names = inst_names, 
                                              period = period)
        inst_data <- update_ts_labels(inst_data, private$mdldef$labels)
        data <- cbind(no_inst_data, inst_data)
        data <- data[ , order(colnames(data)), drop = FALSE]
      } else {
        data <- no_inst_data
      }
      return(data)
    },
    get_endo_data = function(pattern, names, period = private$data_period, 
                             trend = TRUE) {
      names <- private$get_names_fitmdl_("endo", names, pattern)
      return(super$get_endo_data(period = period, names = names, trend = trend))
    },
    get_exo_data = function(pattern, names, period = private$data_period) {
      names <- private$get_names_fitmdl_("exo", names, pattern)
      return(super$get_exo_data(period = period, names = names))
    },
    get_fit = function() {
      
      fit_switches <- private$exo_data[ , private$fit_info$fit_vars, 
                                       drop = FALSE]
      fit <- private$exo_data[ , private$fit_info$exo_vars, drop = FALSE]
      fit[fit_switches == 0] <- NA
      colnames(fit) <- private$fit_info$orig_endos
      
      # remove NA columns and leading/trailing NA rows
      fit <- remove_na_columns(fit)
      if (is.null(fit)) {
        return(NULL) 
      } else {
        fit <- na_trim(fit)
        if (private$mdldef$trend_info$has_deflated_endos) {
          fit <- private$trend_endo_data(fit)
        }
        fit <- fit[ , order(colnames(fit)), drop = FALSE]
        fit <- update_ts_labels(fit, private$mdldef$labels)
        return(fit)
      }
    },
    get_fit_instruments = function(pattern, names, 
                                   period = private$model_period) {
      period <- super$convert_period_arg(period)
      names <- private$get_names_fitmdl_("inst", names, pattern)
      if (length(names) == 0) {
        return(NULL)
      }
      data <- private$endo_data[period, names, drop = FALSE]
      return(update_ts_labels(data, private$mdldef$labels))
    },
    get_lagrange = function(names = private$fit_info$l_vars,
                            period = private$model_period) {
      if (! missing(names)) {
        names <- intersect(names, sort(private$fit_info$l_vars))
      }
      return (private$endo_data[period, names, drop = FALSE])
    },
    get_sigmas = function() {
      ret <- self$get_param(names = private$fit_info$sigmas)
      return(ret[ret >= 0])
    },
    set_static_endos = function(endos) {
      endo_names <- private$get_names_fitmdl_("endo", names = names(endos))
      private$mdldef$endos[endo_names] <- endos[endo_names]
      return(invisible(self))
    },
    get_static_endos = function() {
      return(super$get_static_endos()[private$fit_info$orig_endos])
    },
    set_static_exos = function(exos) {
      exo_names <- private$get_names_fitmdl_("exo", names = names(exos))
      private$mdldef$exos[exo_names] <- exos[exo_names]
      return(invisible(self))
    },
    set_static_exo_values = function(value, names, pattern) {
      exo_names <- private$get_names_fitmdl_("exo", names, pattern)
      return(super$set_static_exo_values(value, names = exo_names))
    },
    get_static_exos = function() {
      return(super$get_static_exos()[private$fit_info$orig_exos])
    },
    serialize = function() {
      ser <- as.list(super$serialize())
      ret <- c(ser, list(fit_info = private$fit_info))
      return(structure(ret, class = "serialized_fitmdl"))
    },
    deserialize = function(ser, dll_dir) {
      private$fit_info <- ser$fit_info
      ser$fit_info <- NULL
      return(super$deserialize(ser, dll_dir))
    },
    solve = function(...) {
      
      mp <- private$model_period
      
      fit_switches <- private$exo_data[mp, private$fit_info$fit_vars, 
                                       drop = FALSE]
      fit_sel <- fit_switches == 1
     
      is_fit_var <- apply(fit_sel, MARGIN = 2, FUN = any)
      n_fit_targets <- sum(is_fit_var)
      
      if (n_fit_targets > 0) {
        
        # check if there are sufficient fit instruments
        n_sigmas <- length(self$get_sigmas())
        if (n_sigmas < n_fit_targets) {
          stop(sprintf(paste("The number of fit targets (%d) exceeds the",
                             "number of fit instruments (%d)\n."),
                       n_fit_targets, n_sigmas))
        }
        
        private$endo_data[mp, private$fit_info$orig_endos][fit_sel] <-
          private$exo_data[mp, private$fit_info$exo_vars][fit_sel]
      }
      
      # set old_instruments, these will be used for deactivated 
      # fit instruments (instruments with sigma < 0), so that the
      # sigmas do not change.
      private$exo_data[ , private$fit_info$old_instruments] <-
         private$endo_data[ , private$fit_info$instruments] 
      

      return(super$solve(...))
    },
    residual_check = function(tol, include_fit_eqs = FALSE) {
      
      # set old_instruments, these will be used for deactivated 
      # fit instruments (instruments with sigma < 0), so that the
      # sigmas do not change.
      private$exo_data[ , private$fit_info$old_instruments] <-
        private$endo_data[ , private$fit_info$instruments] 
      
      residuals <- super$residual_check()
      if (!include_fit_eqs) {
        residuals <- residuals[ , seq_along(private$fit_info$orig_endos), 
                              drop = FALSE]
      }
      if (!missing(tol)) {
        residuals <- trim_ts(residuals, private$model_period, tol)
      }
      return(residuals)
    },
    static_residual_check = function(tol, include_fit_eqs = FALSE) {
      residuals <- super$static_residual_check()
      if (!include_fit_eqs) {
        residuals <- residuals[seq_along(private$fit_info$orig_endos)]
      }
      if (!missing(tol)) {
        residuals <- residuals[abs(residuals) > tol]
      }
      return(residuals)
    },
    solve_steady = function(control = list(), ...) {

      super$solve_steady(control, ...)
    
      if (private$solve_status == "OK") {
        # For the steady state model, the fit instruments and lagrange 
        # multipliers should be exactly 0. However, they are sometimes small
        # because of numerical inaccuracies. Therefore set then to zero and 
        # check the maximum static residual
        names <- c(private$fit_info$instruments, private$fit_info$l_vars)
        fmax <- max(abs(super$static_residual_check()))
        ftol <- if (is.null(control$ftol)) {
                  1e-8 
                } else { 
                  control$ftol
                }
        if (fmax > ftol) {
          stop(paste("The steady state values for the fit instruments",
                     "and lagrange multipliers are significantly different",
                     "from 0."))
        }
      }
      
      return(invisible(self)) 
    }
  ), 
  private = list(
    fit_info = NULL,
   
    get_names_fitmdl_ = function(type, names, pattern,
                                 name_err = c("stop", "warn", "silent")) {
      
      name_err <- match.arg(name_err)
      
      if (private$mdldef$aux_vars$aux_count > 0) {
        stop("FitMdl cannot handle auxiliary variables yet")
      }
      
      endo_names <- private$fit_info$orig_endos
      exo_names <- private$fit_info$orig_exos
      inst_names <- private$fit_info$instruments

      if (type == "all") {
        vnames <- union(union(endo_names, exo_names), inst_names)
        trend_names <- private$mdldef$trend_info$trend_vars$names
        vnames <- union(vnames, trend_names)
      } else if (type == "endo") {
        vnames <- endo_names
      } else if (type == "inst") {
        vnames <- inst_names
      } else {
        vnames <- exo_names
      }
      
      if (!missing(names)) {
        error_vars <- setdiff(names, vnames)
        if (length(error_vars) > 0) {
          if (name_err != "silent") {
            error_vars <- paste0("\"", error_vars, "\"")
            error_var_txt <- paste(error_vars, collapse = ", ")
            error_fun <- if (name_err == "warn") warning else stop
            if (type == "inst") {
              if (length(error_vars) == 1) {
                msg <- "is not a fit instrument" 
              } else {
                msg <-  "are no fit instruments"
              }
            } else {
              type_texts <- c(all = "", endo = "endogenous ", 
                              exo = "exogenous ")
              type_text <- type_texts[[type]]
              if (length(error_vars) == 1) {
                a_word <- if (type == "all") "a " else "an "
                msg <- paste0("is not ", a_word, type_text, "model variable")
              } else {
                msg <- paste0("are no ", type_text, "model variables")
              }
            }
            error_fun(paste(error_var_txt, msg)) 
          }
          names <- intersect(names, vnames)
        }
      }
      
      return(super$select_names(vnames, names, pattern))
    },
    set_fit_internal = function(data, period) {
     
      # internal version of set_fit which does not need to check names
      # and the number of columns of data.
      
      if (is.null(private$model_period)) stop(private$period_error_msg)
      
      if (frequency(data) != frequency(private$data_period)) {
        stop(paste0("The frequency of data does not agree with the data",
                    " period ", as.character(private$data_period), "."))
      }
      
      period <- range_intersect(period, private$data_period)
      if (is.null(period)) return(invisible(NULL))
      
      # select period from data
      data <- data[period]
      
      if (private$mdldef$trend_info$has_deflated_endos) {
        data <- private$detrend_endo_data(data)
      }
      
      fit_names <- colnames(data)
      fit_names_idx <- match(fit_names, private$fit_info$orig_endos)
      
      data_na <- is.na(data)
      
      # set fit switches
      exo_names <- private$fit_info$fit_vars[fit_names_idx]
      private$exo_data[period, exo_names] <- ifelse(data_na, 0, 1)
      
      # Set fit exo values. Note: when the fit target is NA, the value
      # of the fit exo value is irrelevant and can be set to 0.
      data[data_na] <- 0
      exo_names <- private$fit_info$exo_vars[fit_names_idx]
      private$exo_data[period, exo_names] <- data
      
      return(invisible(self))
    }
  )
)
