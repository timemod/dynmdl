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
#' \item{\code{\link{set_fit_values}}}{Sets the values of the fit targets}
#'
#' \item{\code{\link{set_fit}}}{Sets the targets for the fit procedure} 
#'
#' \item{\code{\link{get_fit}}}{Returns the fit targets
#' used in the fit procedure}
#'
#' \item{\code{\link{clear_fit}}}{Remove allfit targets}
#'
#' \item{\code{get_residuals())}}{Returns the residuals used in the 
#' fit procedure.}
#' 
#' \item{\code{get_lagrange())}}{Returns the Lagrange multipliers
#' used in the fit procedure.}
#'
#' \item{\code{get_exo_data(names, period = self$get_data_period()}}{Returns
#' the exogenous data excluding the control variables of the
#' fit procedure.
#' \code{pattern} is a regular expression,  \code{names} a list of variables
#'  and \code{period} an \code{\link[regts]{period_range}} object
#'  or an object that can be coerced to \code{period_range}.}
#'
#' \item{\code{get_endo_data(pattern, names, period = self$get_data_period()}}{Returns
#' the endogenous data excluding the auxiliary endogenous variables
#'  for the fit procedure (the residuals and the Lagrange multipliers).
#' \code{pattern} is a regular expression,  \code{names} a list of variables
#'  and \code{period} an \code{\link[regts]{period_range}} object
#'  or an object that can be coerced to \code{period_range}.}
#' }

FitMdl <- R6Class("FitMdl",
  inherit = DynMdl,
  public = list(
    initialize = function(model_info, fit_info, params, bytecode, use_dll, 
                          dll_dir, dll_file, debug = FALSE) {
      super$initialize(model_info, params, bytecode, use_dll, dll_dir, 
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
        stop(paste("Argument value should have length 1 or",
                   "length ", nper))
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
    clear_fit = function() {
      super$set_exo_values(0, names = private$fit_info$fit_vars)
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
    get_residuals = function(names = private$fit_info$residuals, 
                             period = private$model_period) {
      if (!missing(names)) {
        names <- intersect(names, sort(private$fit_info$residuals))
      }
      return (private$endo_data[period, names, drop = FALSE])
    },
    get_lagrange = function(names = private$fit_info$l_vars,
                            period = private$model_period) {
      if (! missing(names)) {
        names <- intersect(names, sort(private$fit_info$l_vars))
      }
      return (private$endo_data[period, names, drop = FALSE])
    },
    serialize = function() {
      ser <- as.list(super$serialize())
      ret <- c(ser, list(fit_info = private$fit_info))
      return(structure(ret, class = "serialized_fitmdl"))
    }
  ), 
  private = list(
    fit_info = NULL,
    get_names_fitmdl_ = function(type, names, pattern) {
      if (type == "endo") {
        vnames <- sort(private$fit_info$orig_endos)
      } else {
        vnames <- sort(private$fit_info$orig_exos)
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
      } else if (is.null(names)) {
          names <- vnames[grep(pattern, vnames)]
      } else if (!is.null(pattern)) {
          names <- union(names, vnames[grep(pattern, vnames)])
      }
      return(names)
    }
  )
)
