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
    set_fit = function(data, names = colnames(data), 
                       upd_mode = c("upd", "updval")) {
      
      if (is.null(private$model_period)) stop(private$period_error_msg)
      if (!inherits(data, "ts")) {
        # we use inherits and not is.ts, because is.ts returns FALSE if
        # length(x) == 0
        stop("Argument data is not a timeseries object")
      }
      
      upd_mode <- match.arg(upd_mode)
      period <- range_intersect(get_period_range(data), private$data_period)
      if (upd_mode == "updval") {
        stop("upd_mode updval is not yet implemented")
      }
      names <- intersect(names, private$fit_info$orig_endos)
      if (!is.matrix(data)) {
        dim(data) <- c(length(data), 1)
        colnames(data) <- names
      } 
      data <- data[period, names, drop = FALSE]
      
      cols <- match(names, private$fit_info$orig_endos)
      
      # set exogenous variables
      super$set_data_(data, private$fit_info$exo_vars[cols], FALSE,
                      type = "exo", upd_mode = "updval")
      
      # create fit vars
      data[] <- ifelse(is.na(data), 0, 1)
      super$set_data_(data, private$fit_info$fit_vars[cols], FALSE, 
                      type = "exo", upd_mode = "update")
    },
    set_fit_values = function(value, names = NULL, pattern = NULL, 
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
      return(invisible(NULL))
    },
    get_data = function(pattern = NULL, names = NULL, 
                        period = private$data_period) {
      names <- private$get_names_fitmdl_("all", names, pattern)
      return(super$get_data(period = period, names = names))
    },
    get_endo_data = function(pattern = NULL, names = NULL, 
                             period = private$data_period) {
      names <- private$get_names_fitmdl_("endo", names, pattern)
      return(super$get_endo_data(period = period, names = names))
    },
    get_exo_data = function(pattern = NULL, names = NULL, 
                            period = private$data_period) {
      names <- private$get_names_fitmdl_("exo", names, pattern)
      return(super$get_exo_data(period = period, names = names))
    },
    get_fit = function() {
      fit_vars <- private$exo_data[private$data_period, 
                                   private$fit_info$fit_vars, drop = FALSE]
      fit_exos <- private$exo_data[private$data_period, 
                                   private$fit_info$exo_vars, drop = FALSE]
      rows <- !apply(fit_vars == 0, 1, all)
      if (!any(rows)) {
        # no fit targets
        return (NULL)
      }
      rowsel <- min(which(rows)) : max(which(rows))
      cols <- !apply(fit_vars == 0, 2, all)
      fit_vars <- fit_vars[rowsel, cols, drop = FALSE]
      fit_exos <- fit_exos[rowsel, cols, drop = FALSE]
      fit_exos <- ifelse(fit_vars == 1, fit_exos, NA)
      ps <- start_period(private$data_period) + min(which(rows)) - 1
      ret <- regts(fit_exos, start = ps)
      colnames(ret) <- gsub("^fit_", "", colnames(ret))
      ret <- ret[, order(colnames(ret)), drop = FALSE]
      ret <- update_ts_labels(ret, self$get_labels())
      return(ret)
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
    get_static_endos = function() {
      return(super$get_static_endos()[private$fit_info$orig_endos])
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
      
      # check if we have sufficient fit instruments
      fit_targets <- self$get_fit()
      if (is.null(fit_targets)) {
        n_fit_targets <- 0
      } else {
        n_fit_targets <- ncol(fit_targets)
      }
      if (n_fit_targets > 0) {
        n_sigmas <- length(self$get_sigmas())
        if (n_sigmas < n_fit_targets) {
          stop(sprintf(paste("The number of fit targets (%d) exceeds the",
                             "number of fit instruments (%d)\n."),
                        n_fit_targets, n_sigmas))
        }
      }
      
      private$exo_data[, private$fit_info$old_instruments] <-
               private$endo_data[, private$fit_info$instruments] 
      ret <- super$solve(...)
    },
    residual_check = function(...) {
      ret <- super$residual_check(...)
      return(ret[, seq_along(private$fit_info$orig_endos), drop = FALSE])
    }
  ), 
  private = list(
    fit_info = NULL,
    
    get_names_fitmdl_ = function(type, names, pattern) {
      
      if (private$mdldef$aux_vars$aux_count > 0) {
        stop("FitMdl cannot handle auxiliarry variable yet")
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
      
      if (!is.null(names)) {
        error_vars <- setdiff(names, vnames)
        if (length(error_vars) > 0) {
          error_vars <- paste0("\"", error_vars, "\"")
          type_texts <- c(all = "", endo = "endogenous ", exo = "exogenous ")
          type_text <- type_texts[[type]]
          if (length(error_vars) == 1) {
            a_word <- if (type == "all") "a " else "an "
            stop(paste0(error_vars, " is not ", a_word, type_text, 
                        "model variable"))
          } else {
            stop(paste0(paste(error_vars, collapse = ", "),
                        " are no ", type_text, "model variables"))
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
     
      return(names)
    }
  )
)
