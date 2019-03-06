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
    initialize = function(mdldef, fit_info, equations, calc, dll_dir, dll_file,
                          debug = FALSE) {

      # no arguments supplied
      if (nargs() == 0) return()
      
      super$initialize(mdldef, equations, calc, dll_dir,  dll_file)
      
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
    set_fit = function(data, names, upd_mode = c("upd", "updval"),
                       name_err = "stop") {
      
      if (is.null(private$model_period)) stop(private$period_error_msg)
      if (!inherits(data, "ts")) {
        # we use inherits and not is.ts, because is.ts returns FALSE if
        # length(x) == 0
        stop("Argument data is not a timeseries object")
      }
      data <- as.regts(data)
      if (frequency(data) != frequency(private$data_period)) {
        stop(paste0("The frequency of data does not agree with the data",
                    " period ", as.character(private$data_period), "."))
      }
      
      upd_mode <- match.arg(upd_mode)
      period <- range_intersect(get_period_range(data), private$data_period)
      if (upd_mode == "updval") {
        stop("upd_mode updval has not yet implemented")
      }
      if (missing(names)) {
        if (!is.null(colnames(data))) {
          names <- colnames(data)
        } else {
          stop(paste("Argument data has no colnames.",
                     "In that case, argument names should be specified"))
        }
      }
      names <- private$get_names_fitmdl_("endo", names, name_err = name_err)
      if (!is.matrix(data)) {
        dim(data) <- c(length(data), 1)
        colnames(data) <- names
      } 
      data <- data[period, names, drop = FALSE]
      
      if (is.null(private$fit_targets)) {
        private$fit_targets <- data
      } else {
        private$fit_targets[period, names] <- data
      }

      # clean fit fit_targets
      private$fit_targets <- na_trim(private$fit_targets)
      if (!is.null(private$fit_targets) && nrow(private$fit_targets) > 0) {
        private$fit_targets <- remove_na_columns(private$fit_targets)
      }
      
      return(invisible(self))
    },
    set_fit_values = function(value, names, pattern, 
                              period = private$data_period) {
      value <- as.numeric(value)
      period <- private$convert_period_arg(period)
      nper <- nperiod(period)
      vlen <- length(value)
      if (vlen != 1 && vlen < nper) {
        stop(paste("Argument value should have length 1 or length ", nper))
      }
      period <- range_intersect(period, private$data_period)
      names <- private$get_names_fitmdl_("endo", names, pattern)
      nvar <- length(names)
      if (nvar > 0) {
        if (vlen > 1) {
          value <- value[1:nperiod(period)]
        }
        data <- matrix(rep(value, nvar), ncol = nvar)
        data <- regts(data, period = period, names = names)
        self$set_fit(data)
      }
      return(invisible(self))
    },
    get_data = function(pattern, names, period = private$data_period,
                        detrended = FALSE) {
      names <- private$get_names_fitmdl_("all", names, pattern)
      return(super$get_data(period = period, names = names, 
                            detrended = detrended))
    },
    get_endo_data = function(pattern, names, period = private$data_period, 
                             detrended = FALSE) {
      names <- private$get_names_fitmdl_("endo", names, pattern)
      return(super$get_endo_data(period = period, names = names, 
                                 detrended = detrended))
    },
    get_exo_data = function(pattern, names, period = private$data_period) {
      names <- private$get_names_fitmdl_("exo", names, pattern)
      return(super$get_exo_data(period = period, names = names))
    },
    get_fit = function() {
      fit <- private$fit_targets
      if (!is.null(fit)) {
        fit <- fit[, order(colnames(fit)), drop = FALSE]
        fit <- update_ts_labels(fit, private$mdldef$labels)
      }
      return(fit)
    },
    get_fit_instruments = function(names = private$fit_info$instruments, 
                             period = private$model_period) {
      if (!missing(names)) {
        names <- intersect(names, sort(private$fit_info$instruments))
      }
      ret <- private$endo_data[period, names, drop = FALSE]
      cols <- !apply(ret == 0, 2, all)
      if (!any(cols)) {
        # no fit instruments
        return(NULL)
      } else {
        return(zero_trim(ret[, cols, drop = FALSE]))
      }
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
    get_static_exos = function() {
      return(super$get_static_exos()[private$fit_info$orig_exos])
    },
    serialize = function() {
      ser <- as.list(super$serialize())
      ret <- c(ser, list(fit_info = private$fit_info, 
                         fit_targets = private$fit_targets))
      return(structure(ret, class = "serialized_fitmdl"))
    },
    deserialize = function(ser, dll_dir) {
      private$fit_info <- ser$fit_info
      private$fit_targets <- ser$fit_targets
      ser$fit_info <- NULL
      ser$fit_targets <- NULL
      return(super$deserialize(ser, dll_dir))
    },
    solve = function(...) {
      
      # clean fit targets for the solution period
      if (!is.null(private$fit_targets) && length(private$fit_targets) > 0) {
        fit_targets <- private$fit_targets
        p <- range_intersect(get_period_range(fit_targets), 
                             private$model_period)
        fit_targets <- na_trim(fit_targets[p, ])
        if (!is.null(fit_targets) && nrow(fit_targets) > 0) {
          fit_targets <- remove_na_columns(fit_targets)
        }
      } else {
        fit_targets <- NULL
      }
      
      
      if (!is.null(fit_targets) && length(fit_targets) > 0) {
     
        # prepare fit procedure
        
        # check if we have sufficient fit instruments
        n_fit_targets <- ncol(fit_targets)
        n_sigmas <- length(self$get_sigmas())
        if (n_sigmas < n_fit_targets) {
          stop(sprintf(paste("The number of fit targets (%d) exceeds the",
                             "number of fit instruments (%d)\n."),
                       n_fit_targets, n_sigmas))
        }
        
        # detrend fit targets
        if (private$mdldef$trend_info$has_deflated_endos) {
          if (length(private$trend_info$growth_factor_vars$endo) > 0) {
            stop(paste("The fit procedure is only possible if the growth",
                       "factors of all endogenous variables are exogenous"))
          }
          # TODO: method detrend_endo_data calculates the trend variables
          # again, while they have also been calculated in DynMdl$solve().
          # This is not efficient (this point is not very important).
          fit_targets <- private$detrend_endo_data(fit_targets)
        } 
        
        
        # update the exogenous data for the fit procedure
        names_idx <- match(colnames(fit_targets), private$fit_info$orig_endos)
        
        # set exo_vars, first initialize with NA
        super$set_data_(fit_targets, 
                        names = private$fit_info$exo_vars[names_idx], 
                        type = "exo", upd_mode = "updval")
        
        # set fit_vars (switches), first initialise with 0
        super$set_exo_values(0, names = private$fit_info$fit_vars)
        data_mat <- ifelse(is.na(fit_targets), 0, 1)
        fit_switches <- regts(data_mat, names = colnames(fit_targets),
                              period = get_period_range(fit_targets))
        
        super$set_data_(fit_switches, private$fit_info$fit_vars[names_idx], 
                        type = "exo", upd_mode = "update")
        
        # also update endogenous data, for a faster convergence
        super$set_data_(fit_targets, type = "endo", upd_mode = "updval")
      } else {
        
        # no fit targets
        super$set_exo_values(0, names = private$fit_info$fit_vars)
      }
      
      # set old_instruments, these will be used for deactivated 
      # fit instruments (instrumnets with sigma < 0)
      private$exo_data[, private$fit_info$old_instruments] <-
         private$endo_data[, private$fit_info$instruments] 

      return(super$solve(...))
    },
    residual_check = function(...) {
      ret <- super$residual_check(...)
      return(ret[, seq_along(private$fit_info$orig_endos), drop = FALSE])
    }
  ), 
  private = list(
    fit_info = NULL,
    fit_targets = NULL,
    
    get_names_fitmdl_ = function(type, names, pattern,
                                 name_err = c("stop", "warn", "silent")) {
      
      name_err <- match.arg(name_err)
      
      if (private$mdldef$aux_vars$aux_count > 0) {
        stop("FitMdl cannot handle auxiliary variables yet")
      }
      
      endo_names <- private$fit_info$orig_endos
      exo_names <- private$fit_info$orig_exos
    
      if (type == "all") {
        vnames <- union(endo_names, exo_names)
      } else if (type == "endo") {
        vnames <- endo_names
      } else {
        vnames <- exo_names
      }
      
      if (!missing(names)) {
        error_vars <- setdiff(names, vnames)
        if (length(error_vars) > 0) {
          if (name_err != "silent") {
            error_vars <- paste0("\"", error_vars, "\"")
            type_texts <- c(all = "", endo = "endogenous ", exo = "exogenous ")
            type_text <- type_texts[[type]]
            error_fun <- if (name_err == "warn") warning else stop
            if (length(error_vars) == 1) {
              a_word <- if (type == "all") "a " else "an "
              error_fun(paste0(error_vars, " is not ", a_word, type_text, 
                          "model variable"))
            } else {
              error_fun(paste0(paste(error_vars, collapse = ", "),
                          " are no ", type_text, "model variables"))
            }
          }
          names <- intersect(names, vnames)
        }
      }
      
      if (missing(pattern) && missing(names)) {
        names <- vnames
      } else if (!missing(pattern)) {
        sel <- grep(pattern, vnames)
        pattern_names <- vnames[sel]
        if (!missing(names)) {
          names <- union(pattern_names, names)
        } else {
          names <- pattern_names
        }
      }
      return(names)
     
      return(names)
    }
  )
)
