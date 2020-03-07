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
#' @importFrom tictoc tic
#' @importFrom tictoc toc
#' @importFrom regts na_trim
#' @importFrom regts remove_na_columns
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
#' \item{\code{\link{set_param_values}}}{Sets the values of one or more model parameters.}
#'
#' \item{\code{\link{get_param}}}{Returns the parameters of the model.}
#'
#' \item{\code{\link{set_static_exos}}}{Sets the static values of
#' the exogenous variables used to compute the steady state.}
#' 
#' \item{\code{\link{set_static_exo_values}}}{Sets the values of one or more
#' static exogenous variables}
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
#'  \item{\code{\link{set_static_data}}}{Sets the static values of
#' the model variables.}
#'
#' \item{\code{\link{get_static_data}}}{Returns the static values of
#' the model variables.} 
#' 
#' \item{\code{\link{get_all_static_endos}}}{Returns the static values of
#' the endogenous model variables, including fit instruments and
#' lagrange multupliers.} 
#' 
#' #\item{\code{\link{get_all_static_data}}}{Returns the static values of
#' the exogenous and endogenous model variables, including fit instruments and
#' lagrange multupliers.} 
#'
#' \item{\code{\link{init_data}}}{Initializes the model data}
#'
#' \item{\code{\link{set_period}}}{Sets the model period}
#'
#' \item{\code{\link{get_period}}}{Returns the model period}
#'
#' \item{\code{\link{get_data_period}}}{Returns the model data period.}
#'
#' \item{\code{\link{get_lag_period}}}{Returns the lag period.}
#'
#' \item{\code{\link{get_lead_period}}}{Returns the lead period}
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
#' \item{\code{\link{change_data}}}{Changes the values of endogenous and 
#' exogenous model variables by applying a function.}
#' 
#' \item{\code{\link{get_data}}}{Returns the model data, including exogenous end exogenous
#' variables, fit instruments and trend variables (but excluding Lagrange multipliers).}
#' 
#' \item{\code{\link{get_all_endo_data}}}{Returns all endogenous model variables,
#' including exogenous end exogenous
#' variables, fit instruments and trend variables (but excluding Lagrange multipliers).}
#' 
#'
#' \item{\code{\link{get_all_data}}}{Returns all endogenous end exogenous model varieables,
#' including fit instruments and Lagrange multipliers}
#'
#' \item{\code{\link{get_endo_data}}}{Returns the endogenous model data}
#'
#' \item{\code{\link{get_exo_data}}}{Returns the exogenous model data}
#' 
#' \item{\code{\link{get_vars_pars}}}{Returns a list with model variables and 
#'                                    parameters}
#'
#' \item{\code{\link{solve_steady}}}{Solves the steady state}
#'
#' \item{\code{\link{solve}}}{Solves the model}
#' 
#' \item{\code{\link{solve_steady_dynare}}}{Solves the steady state and eigenvalues with
#' Dynare (emplpying Matlab or Octave)}
#'
#' \item{\code{\link{solve_dynare}}}{Solves the model with Dynare (employing Octave or Matlab)}
#' 
#' \item{\code{\link{check}}}{Compute the eigenvalues of the linear
#' system and check if the Blachard and Kahn conditions are satisfied.}
#'
#' \item{\code{\link{residual_check}}}{Calculates the residuals of the equations
#' and reports the differences larger than a tolerance parameters}
#' 
#' \item{\code{\link{static_residual_check}}}{Calculates the residuals of the 
#' static model equations and reports the differences larger than a tolerance parameters}
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
#' parsed equations of the model.}

#' \item{\code{\link{get_original_equations}}}{Returns a character vector with the 
#' equations of the original model.}
#' 
#' \item{\code{\link{copy}}}{Returns a deep copy of the \code{\link{DynMdl}} 
#' object}
#' 
#' \item{\code{\link{get_solve_status}}}{Returns the status of the last model
#' solve attempt}
#' 
#' \item{\code{\link{get_mdldef}}}{Returns a list with technical details of the 
#' model.}
#' }
#' 
#' @section Methods for the fit method:
#' \describe{
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
#' \item{\code{\link{set_fit_steady}}}{Sets the targets for the fit procedure 
#' for the steady state.} 
#'
#' \item{\code{\link{get_fit}}}{Returns the fit targets
#' used in the fit procedure}
#' 
#' \item{\code{\link{get_fit}_steady}}{Returns the fit targets
#' used in the fit procedure for the steady state.}
#'
#' \item{\code{\link{get_fit_instruments}}}{Returns all non-zero fit instruments
#' used in the fit procedure}
#' 
#' \item{\code{\link{get_sigmas}}}{Returns all sigma parameters >= 0 used in 
#' the fit procedure. If a sigma parameter is negative, then the 
#' corresponding fit instrument is not included}
#' 
#' \item{\code{\link{get_lagrange}}}{Returns the Lagrange multipliers
#' used in the fit procedure.}
#' 
#' \item{\code{\link{run_initval}}}{Run the initval equations to obtain
#' new values for endogenous and exogenous static variables for the current
#' values or parameters.}
#' }
DynMdl <- R6Class("DynMdl",
  public = list(
    initialize = function(model_index, mdldef, base_period, calc, dll_dir, 
                          dll_file) {

      # no arguments supplied
      if (nargs() == 0) return()
      
      private$model_index <- model_index
      private$mdldef <- mdldef
      private$base_period <- base_period
      private$calc <- calc
      private$dll_dir <- dll_dir
      private$dll_file <- dll_file
      
      # now create the functions for evaluating the model
      private$make_functions()
    },
    print = function(short = TRUE) {
      cat(paste(class(self)[1], "object\n"))
      cat(sprintf("%-60s%s\n", "Fit:", as.character(private$mdldef$fit)))
      cat(sprintf("%-60s%s\n", "Calc method:", private$calc))
      if (private$calc == "internal") {
        cat(sprintf("%-60s%d\n", "Model index:", private$model_index))
      }
      if (private$mdldef$fit || private$mdldef$has_aux_vars) {
        cat(sprintf("%-60s%d\n", "Total number of endogenous variables:",
                     private$mdldef$endo_count))
        cat(sprintf("%-60s%d\n", "Number of normal endogenous variables:",
                    length(private$mdldef$endo_names_orig)))
        if (private$mdldef$fit) {
          cat(sprintf("%-60s%d\n", "Number of fit instruments:",
                      length(private$mdldef$fit_info$instruments)))
        }
        if (private$mdldef$has_aux_vars) {
          cat(sprintf("%-60s%d\n", "Number of auxiliary endogenous variables:",
                      private$mdldef$aux_vars$aux_count))
        }
      } else {
        cat(sprintf("%-60s%d\n", "Number of endogenous variables:", 
                    private$mdldef$endo_count))
      }
      if (private$mdldef$fit || private$mdldef$has_aux_vars) {
        cat(sprintf("%-60s%d\n", "Total number of exogenous variables:",
                     private$mdldef$exo_count))
        cat(sprintf("%-60s%d\n", "Number of normal exogenous variables:",
                    length(private$mdldef$exo_names_orig)))
      } else {
        cat(sprintf("%-60s%d\n", "Number of exogenous variables:",
                  private$mdldef$exo_count))
      }
      cat(sprintf("%-60s%d\n", "Maximum exogenous lead:",
                  private$mdldef$max_exo_lead))
      cat(sprintf("%-60s%d\n", "Maximum exogenous lag:",
                  private$mdldef$max_exo_lag))
      cat(sprintf("%-60s%d\n", "Maximum endogenous lead:",
                  private$mdldef$max_endo_lead))
      cat(sprintf("%-60s%d\n", "Maximum endogenous lag:",
                  private$mdldef$max_endo_lag))
      if (private$mdldef$has_aux_vars) {
        cat(sprintf("%-60s%d\n", "Maximum endogenous lead original model:",
                    private$mdldef$max_endo_lead_orig))
        cat(sprintf("%-60s%d\n", "Maximum endogenous lag original model:",
                    private$mdldef$max_endo_lag_orig))
      }
      cat(sprintf("%-60s%d\n", "Number of nonzeros static. jac:",
                  private$mdldef$jac_static_size))
      cat(sprintf("%-60s%d\n", "Number of nonzeros dyn. jac:",
                  private$mdldef$jac_dynamic_size_endo))
      if (!is.null(private$model_period)) {
        cat(sprintf("%-60s%s\n", "Model period:",
                    as.character(private$model_period)))
        cat(sprintf("%-60s%s\n", "Data period:",
                    as.character(private$data_period)))
        if (private$mdldef$trend_info$has_deflated_endos) {
          cat(sprintf("%-60s%s\n", "Base period for trends:",
                      as.character(private$base_period)))
        }
      }
      return(invisible(self))
    },
    get_max_lag = function() {
      return(private$mdldef$max_lag_orig)
    },
    get_max_lead = function() {
      return(private$mdldef$max_lead_orig)
    },
    get_endo_names = function(type = c("all", "leads", "lags")) {
      type <- match.arg(type)
      if (type == "leads" || type == "lags") {
        lli <- private$mdldef$lead_lag_incidence
        lli <- lli[private$mdldef$endo_indices_orig, , drop = FALSE]
        if (type == "leads") {
            lli <- lli[ , as.integer(colnames(lli)) > 0, drop = FALSE]
        } else {
            lli <- lli[ , as.integer(colnames(lli)) < 0, drop = FALSE]
        }
        lli <- rowSums(lli)
        return(names(lli[lli > 0]))
      } else {
        return(private$mdldef$endo_names_orig)
      }
    },
    get_exo_names = function() {
      return(private$mdldef$exo_names_orig)
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
      names <- private$mdldef$param_names
      if (!missing(pattern)) {
        sel <- grep(pattern, names)
        names <- names[sel]
      }
      return(names)
    },
    set_param = function(params, names, name_err = "stop") {
      params <- private$convert_values_internal(params, names, "params")
      names <- private$check_param_names(base::names(params), 
                                         name_err = name_err)
      private$mdldef$params[names] <- params[names]
      return(invisible(self))
    },
    set_param_values = function(value, names, pattern) {
      if (!is.numeric(value) && length(value) != 1) {
        stop("Argument value should be a scalar numeric")
      }
      names <- private$get_param_names_(pattern, names)
      private$mdldef$params[names] <- value
      return(invisible(self))
    },
    get_param = function(pattern, names) {
      names <- private$get_param_names_(pattern, names)
      return(private$mdldef$params[names])
    },
    set_static_exos = function(exos, names, name_err = "stop") {
      exos <- private$convert_values_internal(exos, names, "exos")
      exo_names <- private$get_names_("exo", names = base::names(exos), 
                                      name_err = name_err)
      private$mdldef$exos[exo_names] <- exos[exo_names]
      return(invisible(self))
    },
    set_static_exo_values = function(value, names, pattern) {
      if (!is.numeric(value) && length(value) != 1) {
        stop("Argument value should be a scalar numeric")
      }
      names <- private$get_names_("exo", names, pattern)
      private$mdldef$exos[names] <- value
      return(invisible(self))
    },
    get_static_exos = function(pattern, names) {
      if (missing(pattern) && missing(names)) {
        if (private$mdldef$fit) {
          return(private$mdldef$exos[private$mdldef$exo_indices_orig])
        } else {
          return(private$mdldef$exos)
        }
      } else {
        names <- private$get_names_("exo", names, pattern)
        return(private$mdldef$exos[names])
      }
    },
    set_static_endos = function(endos, names, name_err = "stop") {
      endos <- private$convert_values_internal(endos, names, "endos")
      endo_names <- private$get_names_("endo", names = base::names(endos), 
                                       name_err = name_err)
      private$mdldef$endos[endo_names] <- endos[endo_names]
      return(invisible(self))
    },
    get_static_endos = function(pattern, names) {
      if (missing(pattern) && missing(names)) {
        return(private$get_static_endos_internal())
      } else {
        names <- private$get_names_("endo", names, pattern)
        return(private$mdldef$endos[names])
      }
    },
    get_static_data = function(pattern, names) {
      
      static_exos <- numeric(0)
      
      if (missing(pattern) && missing(names)) {
        
        # endogenous variables
        static_endos <- private$get_static_endos_internal(incl_instr = TRUE)
                                                        
        # exogenous variables
        if (private$mdldef$exo_count > 0) {
          if (private$mdldef$fit) {
            static_exos <- private$mdldef$exos[private$mdldef$exo_indices_orig]
          } else {
            static_exos <- private$mdldef$exos
          }
        }
        
        ret <- c(static_endos, static_exos)
        if (length(ret) > 0) ret <- ret[order(base::names(ret))]
        
      } else {
        
        names <- private$get_names_("all", names, pattern, steady = TRUE,
                                    sort_pattern_names = TRUE)
        if (length(names) == 0) {
          return(numeric(0))
        }
        
        # endogenous variables:
        endo_names <- intersect(names, private$mdldef$endo_names)
        static_endos <- private$mdldef$endos[endo_names]
        
        # exogenous variables
        if (private$mdldef$exo_count > 0) {
          exo_names <- intersect(names, private$mdldef$exo_names_orig)
          static_exos <- private$mdldef$exos[exo_names]
        }
        
        ret <- c(static_endos, static_exos)
        if (length(ret) > 0) ret <- ret[names]
      }
     
      return(ret)
    },
    get_all_static_endos = function() {
      return(private$get_static_endos_internal(incl_inst = TRUE,
                                               incl_l_vars = TRUE))
    },
    get_all_static_data = function() {
      static_endos <- private$get_static_endos_internal(incl_inst = TRUE,
                                                        incl_l_vars = TRUE)
      if (private$mdldef$exo_count > 0) {
        static_exos <- private$mdldef$exos[private$mdldef$exo_names_orig]
      } else {
        static_exos <- numeric(0)
      }
      ret <- c(static_endos, static_exos)
      if (length(ret) > 0) ret <- ret[order(base::names(ret))]
      return(ret)
    },
    set_static_data = function(data, names, name_err = "stop") {
      data <- private$convert_values_internal(data, names, "data")
      names <- private$get_names_("all_endo_exo", names = base::names(data), 
                                  name_err = name_err)
      endo_names <- intersect(names, private$mdldef$endo_names)
      exo_names <- intersect(names, private$mdldef$exo_names_orig)
      if (length(endo_names) > 0) {
        private$mdldef$endos[endo_names] <- data[endo_names]
      }
      if (length(exo_names) > 0) {
        private$mdldef$exos[exo_names] <- data[exo_names]
      }
      return(invisible(self))
    },
    init_data = function(data_period, data, upd_mode = c("upd", "updval"))  {
      
      upd_mode <- match.arg(upd_mode)

      if (missing(data_period)) {
        # data_period not specified: determine data_period from data and 
        # model_period
        if (missing(data)) {
          if (is.null(private$model_period)) {
            stop(paste("If neither data_period nor data have been specified", 
                       "then model_period should be known"))
          } else {
            p <- private$model_period
            data_period <- period_range(
              start_period(p) - private$mdldef$max_lag_orig,
              end_period(p)   + private$mdldef$max_lead_orig)
          }
        } else if (is.null(private$model_period)) {
          data_period <- get_period_range(data)
        } else {
          p <- private$model_period
          p_data <- get_period_range(data)
          data_period <- period_range(
            min(start_period(p) - private$mdldef$max_lag_orig, 
                start_period(p_data)),
            max(end_period(p) + private$mdldef$max_lead_orig, 
                end_period(p_data)))
        }
      } else {
        # data period specified
        data_period <- as.period_range(data_period)
        if (!is.null(private$model_period)) {
          mp <- private$model_period
          startp <- start_period(mp) - private$mdldef$max_lag_orig
          endp <- end_period(mp) + private$mdldef$max_lead_orig
          if (start_period(data_period) > startp || 
              end_period(data_period)  < endp) {
            stop(paste("The data period should include the range", 
                      as.character(mp), "."))
          }
        }
      }
    
      # if the model period has not been set, then determine the model
      # period from the data period
      if (is.null(private$model_period)) {
        startp <- start_period(data_period) + private$mdldef$max_lag_orig
        endp <- end_period(data_period) - private$mdldef$max_lead_orig
        if (endp < startp) {
          stop(paste("The data period is too short. It should contain at least",
               private$mdldef$max_lag + private$mdldef$max_lead + 1, 
               "periods"))
        }
        private$model_period <- period_range(startp, endp)
      }
      
      private$data_period <- data_period
      private$period_shift <- start_period(private$model_period) - 
                              start_period(data_period)
      if (is.null(private$base_period)) {
        private$base_period <- start_period(private$model_period)
      } 
      
      #
      # Initialise private$exo and private$endo with steady state values
      # for the complete data period.
      #
      nper <- nperiod(data_period)
      if (private$mdldef$exo_count > 0) {
        exo_mat <- matrix(rep(private$mdldef$exos, each = nper), nrow = nper)
        colnames(exo_mat) <- private$mdldef$exo_names
      } else {
        exo_mat <- matrix(NA_real_, nrow = nper, ncol = 0)
      }
      private$exo_data <- regts(exo_mat, period = data_period)
      private$endo_data <- regts(matrix(rep(private$mdldef$endos, each = nper), 
                                        nrow = nper), 
                                 names = private$mdldef$endo_names,
                                 period = data_period)
  
      # First update exo_data with data, because the actual values of the 
      # growth variables are needed in method get_trend_data_internal() called 
      # below. endo_data can only updated with values in data when the trends 
      # are known.
      if (!missing(data) && !is.null(data)) {
        if (is.null(colnames(data))) {
          stop("data should be a timeseries with colnames")
        }
        data <- private$convert_data_internal(data)
        private$set_data_(data, type = "exo", upd_mode = upd_mode, 
                          init_data = TRUE)
      }
      
      #
      # The exogenous variables have been set -> now build trend timeseries.
      #
      private$trend_data <- private$get_trend_data_internal()
      private$deflator_data <- private$get_deflator_data_internal()
      
      #
      # Now update endogenous variables with values in data.
      # Variables with trends will be detrended with the calculated trends.
      #
      if (!missing(data) && !is.null(data)) {
        private$set_data_(data, type = "endo", upd_mode = upd_mode,
                         init_data = TRUE)
      }
      
      # call prepare_aux_vars, this is actually only needed when 
      # init_data is called in function solve_dynare.
      private$prepare_aux_vars()
    
      return(invisible(self))
    },
    set_period = function(period) {
      period <- as.period_range(period)
      if (is.na(period[1]) || is.na(period[2])) {
        stop("period should have a lower and upper bound")
      }
     
      if (is.null(private$data_period)) {
        data_period <- period_range(
          start_period(period) - private$mdldef$max_lag_orig,
          end_period(period)   + private$mdldef$max_lead_orig)
        private$model_period <- period
        self$init_data(data_period)
      } else  {
        private$check_model_period(period) 
        private$model_period <- period
      }
      
      private$period_shift <- start_period(private$model_period) -
                              start_period(private$data_period)
      
     return(invisible(self))
    },
    get_period = function() {
      return (private$model_period)
    },
    get_base_period = function() {
      return (private$base_period)
    },
    get_data_period = function() {
      return (private$data_period)
    },
    get_lag_period = function() {
      if (private$mdldef$max_lag > 0) {
        p <- start_period(private$model_period) - private$mdldef$max_lag_orig
        return(period_range(p, p + private$mdldef$max_lag_orig - 1))
      } else {
        return(NULL)
      }
    },
    get_lead_period = function() {
      if (private$mdldef$max_lead_orig > 0) {
        p <- end_period(private$model_period) + 1
        return(period_range(p, p + private$mdldef$max_lead_orig - 1))
      } else {
        return(NULL)
      }
    },
    get_exo_data = function(pattern, names, period) {
      period <- private$check_period_arg(period)
      if (private$mdldef$exo_count == 0) {
        return(private$exo_data[period])
      }
      if (missing(pattern) && missing(names)) {
        if (private$mdldef$fit) {
          ret <- private$exo_data[period, private$mdldef$exo_indices_orig]
        } else {
          ret <- private$exo_data[period]
        }
      } else {
        names <- private$get_names_("exo", names, pattern)
        if (length(names) == 0) {
          return(NULL)
        }
        ret <- private$exo_data[period, names, drop = FALSE]
      }
      return(update_ts_labels(ret, private$mdldef$labels))
    },
    set_endo_values = function(value, names, pattern, period) {
      return(private$set_values_(value, names, pattern, period, type = "endo"))
    },
    set_exo_values = function(value, names, pattern, period) {
      return(private$set_values_(value, names, pattern, period, type = "exo"))
    },
    set_data = function(data, names, upd_mode = c("upd", "updval"), fun,
                        name_err = "stop") {
      upd_mode <- match.arg(upd_mode)
      data <- private$convert_data_internal(data, names)
      if (is.null(data)) return(invisible(self))
      names <- private$get_names_("all_endo_exo", names = colnames(data), 
                                  name_err = name_err)
      if (length(names) == 0) return(invisible(self))
      
      private$set_data_(data, type = "exo", upd_mode = upd_mode, fun = fun)
      private$set_data_(data, type = "endo", upd_mode = upd_mode, fun = fun)
      return(invisible(self))
    },
    get_all_endo_data = function(trend = TRUE) {
      if (is.null(private$model_period)) stop(private$period_error_msg)
      data <- private$endo_data
      if (private$mdldef$has_aux_vars) {
        data <- data[ , -private$mdldef$aux_vars$endos, drop = FALSE]
      }
      if (trend && private$mdldef$trend_info$has_deflated_endos) {
        data <- private$trend_endo_data(data)
      }
      # only use labels for the original variables
      lbls <- private$mdldef$labels
      if (private$mdldef$fit) {
        # no labels for Lagrange multipliers
        l_sel <- match(private$mdldef$fit_info$l_var_names, names(lbls))
        lbls <- lbls[-l_sel]
      }
      return(update_ts_labels(data, lbls))
    },
    get_all_data = function(trend = TRUE) {
      if (is.null(private$model_period)) stop(private$period_error_msg)
      ret <- cbind(self$get_all_endo_data(trend = trend), self$get_exo_data())
      ret <- ret[ , order(colnames(ret)), drop = FALSE]
      return(ret)
    },
    get_all_endo_data_dynare = function() {
      # Return all endogenous variables, including auxiliary variables,
      # fit instruments and lagrange multipliers, without trend.
      # This function is used in package dynmdl to prepare input for Dynare,
      # but is not useful outside of package dyndml. The function should 
      # therefore not be documented.
      if (is.null(private$model_period)) stop(private$period_error_msg)
      if (private$mdldef$has_aux_vars) private$prepare_aux_vars()
      return(private$endo_data)
    },
    get_all_exo_data_dynare = function() {
      # Return all exgenous variables, including exogenous variables
      # used in the fit procedure.
      if (is.null(private$model_period)) stop(private$period_error_msg)
      if (private$mdldef$fit) private$set_old_fit_instruments()
      return(private$exo_data)
    },
    get_data = function(pattern, names, period = private$data_period,
                        trend = TRUE) {
      
      period <- private$check_period_arg(period)

      exo_data <- NULL
      trend_data <- NULL
      
      if (missing(pattern) && missing(names)) {
        
        endo_data <- private$get_endo_data_internal(period = period, 
                                                    trend = trend,
                                                    incl_instr = TRUE)
        if (private$mdldef$exo_count > 0) {
          if (private$mdldef$fit) {
            exo_data <- private$exo_data[period, private$mdldef$exo_indices_orig, 
                                         drop = FALSE]
          } else {
            exo_data <- private$exo_data[period]
          }
        }
        if (!is.null(private$trend_data)) {
          trend_data <- private$trend_data[period]
        }
        
        data <- cbind(endo_data, exo_data, trend_data)
        data <- data[ , order(colnames(data)), drop = FALSE]
         
      } else {
        
        names <- private$get_names_("all", names, pattern, 
                                    sort_pattern_names = TRUE)
        if (length(names) == 0) {
          return(NULL)
        }
        endo_names <- intersect(names, private$mdldef$endo_names)
        endo_data <- private$get_endo_data_internal(names = endo_names, 
                                                    period = period, 
                                                    trend = trend)
        if (private$mdldef$exo_count > 0) {
          exo_names <- intersect(names, private$mdldef$exo_names_orig)
          exo_data <- private$exo_data[period, exo_names, drop = FALSE]
        }
        if (length(private$mdldef$trend_info$trend_vars$names) > 0) {
          trend_names <- intersect(names, 
                                   private$mdldef$trend_info$trend_vars$names)
          trend_data <- private$trend_data[period, trend_names]
        }
        
        data <- cbind(endo_data, exo_data, trend_data)
        data <- data[ , names, drop = FALSE]
      }
      return(update_ts_labels(data, private$mdldef$labels))
    },
    get_endo_data = function(pattern, names, period, trend = TRUE) {
      period <- private$check_period_arg(period)
      if (missing(pattern) && missing(names)) {
        endo_data <- private$get_endo_data_internal(period = period, 
                                                    trend = trend)
      } else {
        names <- private$get_names_("endo", names, pattern)
        if (length(names) == 0) {
          return(NULL)
        }  
        endo_data <- private$get_endo_data_internal(names = names, 
                                                    period = period, 
                                                    trend = trend)
        
      }
      return(update_ts_labels(endo_data, private$mdldef$labels))
    },
    change_endo_data = function(fun, names, pattern, 
                                period = private$data_period, ...) {
      names <- private$get_names_("all_endo", names, pattern)
      return(private$change_data_(fun, names, period, "endo", ...))
    },
    change_exo_data = function(fun, names, pattern, 
                               period = private$data_period , ...) {
      names <- private$get_names_("exo", names, pattern)
      return(private$change_data_(fun, names, period, "exo", ...))
    },
    change_data = function(fun, names, pattern, period = private$data_period, 
                           ...) {
      names <- private$get_names_("all_endo_exo", names, pattern)
      exo_names <- intersect(names, private$mdldef$exo_names_orig)
      if (length(exo_names) > 0) {
        private$change_data_(fun, exo_names, period, "exo", ...)
      }
      endo_names <- intersect(names, private$mdldef$endo_names_no_aux)
      if (length(endo_names) > 0) {
        private$change_data_(fun, endo_names, period, "endo", ...)
      }
      return(invisible(self))
    },
    get_trend_data = function(names, pattern, period) {
      period <- private$check_period_arg(period)
      if (missing(pattern) && missing(names)) {
        return(private$trend_data[period, ])
      } else {
        names <- private$get_names_("trend", names, pattern)
        if (length(names) == 0) {
          return(NULL)
        }
        return(private$trend_data[period, names, drop = FALSE])
      }
    },
    get_vars_pars = function(period = private$data_period, trend = TRUE) {
        data_list <- as.list(self$get_data(period = period, trend = trend))
        trend_data_list <- as.list(self$get_trend_data(period = period))
        param_list <- as.list(self$get_param())
        ret <- c(data_list, trend_data_list, param_list)
        ret <- ret[order(names(ret))]
        return(ret)
    },
    solve_steady = function(control = list(), solver = c("umfpackr", "nleqslv"),
                            debug_eqs = FALSE, silent = FALSE, ...) {
    
      solver <- match.arg(solver)
      
      if (solver == "nleqslv") control$trace <- as.integer(control$trace)
      
      if (private$mdldef$fit) {
        fit_info <- private$prepare_fit_steady()
        n_fit <- fit_info$n_fit
        instruments <- fit_info$instruments
      }

      if (silent) {
        if (!is.null(control$silent) && !control$silent) {
          warning(paste("Control parameter 'silent' overruled",
                        "by argument 'silent = TRUE'."))
        }
        if (silent && !is.null(control$trace) && control$trace) {
          warning(paste("Control parameter 'trace' overruled",
                        "by argument 'silent = TRUE'."))
        }
        if (solver == "umfpackr") {
          control$silent <- TRUE
          control$trace <- FALSE
        } else {
          control$trace <- 0
        }
      } else if (is.null(control$trace)) {
        control$trace <- TRUE
        if (solver == "umfpackr") control$trace <- as.integer(control$trace)
      }
    
      private$prepare_static_model()

      start <- private$mdldef$endos
      if (private$mdldef$has_aux_vars > 0) {
        # make sure that they are ok
        aux_endos <- private$mdldef$endos[private$mdldef$aux_vars$orig_endos]
        start[private$mdldef$aux_vars$endos]  <- aux_endos
      }
      
      if (solver == "umfpackr") {
        out <- umf_solve_nl(start, fn = private$get_static_residuals, 
                            jac = private$get_static_jac, control = control, 
                            debug_eqs = debug_eqs, ...)
        error <- !out$solved
      } else {
        jacf <- function(endos, debug_eqs) {
          j <- private$get_static_jac(endos, debug_eqs)
          return(as(j, "matrix"))
        }
        out <- nleqslv(start, fn = private$get_static_residuals, jac = jacf, 
                       method = "Newton", control = control, 
                       debug_eqs = debug_eqs, ...)
        error <- out$termcd != 1
      }
      private$clean_static_model()
      private$mdldef$endos <- out$x
      
      if (error) {
        if (!silent && 
            grepl("[Ff]unction.*contains non-finite value", out$message)) {
          res <- private$get_static_residuals(out$x, FALSE)
          names(res) <- paste("eq", seq_along(res))
          res <- res[!is.finite(res)]
          cat("Non-finite values in residuals for the following equations:\n")
          print(res)
        }
        private$solve_status <- "ERROR"
        warning(paste0("Solving the steady state not succesful.\n", out$message))
      } else {
        private$solve_status <- "OK"
      }
      
      if (private$mdldef$fit && private$solve_status == "OK" && n_fit == 0) {
        # If there are no fit targets, then the steady state solution for
        # all fit instruments must be exactly 0, and all Lagrange multipliers
        # should be zero. However, the values are not exactly equal to zero
        # because of numerical inaccuracies.  This may cause numerical problems.
        # Therefore set then to zero and check the maximum static residual
        indices <- c(private$mdldef$fit_info$l_vars, instruments)
        old_endos <- private$mdldef$endos[indices]
        private$mdldef$endos[indices] <- 0
        
        fmax <- max(abs(self$static_residual_check(include_all_eqs = TRUE,
                                                   debug_eqs = FALSE)))
        ftol <- if (is.null(control$ftol)) {
          1e-8 
        } else { 
          control$ftol
        }
        if (fmax > ftol) {
          # restore old solution
          private$mdldef$endos[indices] <- old_endos
          warning(paste("The steady state values for the fit instruments",
                        "and Lagrange multipliers are significantly different",
                        "from 0."))
        }
        
        # make static _exo variables equal to the corresponding static 
        # endogenous variables
        exo_idx <- private$mdldef$fit_info$exo_vars
        endo_idx <- private$mdldef$fit_info$orig_endos
        private$mdldef$exos[exo_idx] <- private$mdldef$endos[endo_idx]
      }
      
      return (invisible(self))
    },
    put_static_endos = function(period) {
      # copy the static endogenous variables to the endogenous model data
      period_specified <- !missing(period)
      period <- private$check_period_arg(period)
      nper <- nperiod(period)
      endo_data <- regts(matrix(rep(private$mdldef$endos, each = nper), 
                                nrow = nper), names = private$mdldef$endo_names,
                         period = period)
      if (period_specified) {
        private$endo_data[period, ] <- endo_data
      } else {
        private$endo_data <- endo_data
      }
      return(invisible(self))
    },
    check = function() {

      self$solve_steady(control = list(silent = TRUE))
      
      if (private$solve_status != "OK") {
        stop("No steady state ... checking model is not possible")
      }
      
      private$prepare_dynamic_model(solve_first_order = TRUE)
      private$ss <- solve_first_order(private$ss, private$calc, 
                                      private$model_index, private$mdldef, 
                                      private$jac_dynamic, 
                                      check_only = TRUE, debug = FALSE,
                                      debug_eqs = FALSE)
      private$clean_dynamic_model()
      return(invisible(self))
    },
    static_residual_check = function(tol, debug_eqs = FALSE, 
                                     include_fit_eqs = FALSE,
                                     include_all_eqs = FALSE) {
      private$check_debug_eqs(debug_eqs)
      private$prepare_static_model()
      residuals <- private$get_static_residuals(private$mdldef$endos, debug_eqs)
      private$clean_static_model()
      names(residuals) <- paste0("eq_",  1 : (private$mdldef$endo_count))
      if (!include_all_eqs) {
        if (private$mdldef$fit && !include_fit_eqs) {
          residuals <- residuals[seq_along(private$mdldef$endo_names_orig)]
        } else {
          residuals <- residuals[seq_along(private$mdldef$endo_names_no_aux)]
        }
      }
      if (!missing(tol)) {
        residuals <- residuals[is.na(residuals) | abs(residuals) > tol]
      }
      return(residuals)
    },
    residual_check = function(tol, debug_eqs = FALSE, include_fit_eqs = FALSE,
                              include_all_eqs = FALSE) {
      
      if (is.null(private$model_period)) stop(private$period_error_msg)
      private$check_debug_eqs(debug_eqs)

      private$prepare_dynamic_model()
      
      endo_data <- endo_data_solve(private$endo_data,
                                   private$model_period,
                                   maxlag = private$mdldef$max_endo_lag,
                                   maxlead = private$mdldef$max_endo_lead)
      
      x <- cur_endos(endo_data)
      lags <- lag_endos(endo_data)
      leads <- lead_endos(endo_data)
      nper <- endo_data$nper_cur
      
      residuals <- private$get_residuals(x, lags, leads, private$exo_data, 
                                         nper, debug_eqs)
      
      private$clean_dynamic_model()
      
      dim(residuals) <- c(private$mdldef$endo_count, nper)
      residuals <- t(residuals)
      colnames(residuals) <- paste0("eq_",  1 : (private$mdldef$endo_count))
      
      if (!include_all_eqs) {
        if (private$mdldef$fit && !include_fit_eqs) {
          residuals <- residuals[ , seq_along(private$mdldef$endo_names_orig), 
                                  drop = FALSE]
        } else {
          residuals <- residuals[ , seq_along(private$mdldef$endo_names_no_aux),
                                  drop = FALSE]
        }
      }
      residuals <- regts(residuals, period = private$model_period)
      if (!missing(tol)) {
        residuals <- trim_ts(residuals, private$model_period, tol)
      }
      return(residuals)
    },
    
    solve = function(control = list(), mode , solver = c("umfpackr", "nleqslv"),  
                     start = c("current", "previous"), debug_eqs = FALSE, 
                     homotopy = TRUE, silent = FALSE, 
                     backrep = c("period", "total"), ...) {
      
      if (is.null(private$model_period)) stop(private$period_error_msg)
      backrep <- match.arg(backrep)
      
      private$check_debug_eqs(debug_eqs)
      
      if (!missing(mode)) {
        mode <- match.arg(mode, c("stacked_time", "backwards"))
        stacked_time <- mode == "stacked_time"
      } else {
        stacked_time <- private$mdldef$max_endo_lead > 0
      }
    
      if (private$mdldef$fit) {
        fit_info <- private$prepare_fit()
        n_fit <- fit_info$n_fit
        instruments <- fit_info$instruments
      }
     
      solver <- match.arg(solver)
      start <- match.arg(start)
      
      if (silent) {
        if (!is.null(control$silent) && !control$silent) {
          warning(paste("Control parameter 'silent' overruled",
                        "by argument 'silent = TRUE'."))
        }
        if (silent && !is.null(control$trace) && control$trace) {
          warning(paste("Control parameter 'trace' overruled",
                        "by argument 'silent = TRUE'."))
        }
        if (solver == "umfpackr") {
          control$silent <- TRUE
          control$trace <- FALSE
        } else {
          control$trace <- 0
        }
      }  else if (is.null(control$trace)) {
          # if control$trace has not been specified, then make it equal
          # to true when the stacked time method is used and equal to false
          # when the model is solve using the backwards method
          control$trace <- stacked_time
          if (solver == "nleqslv") control$trace <- as.integer(control$trace)
      }
      
      if (!stacked_time && solver == "umfpackr" && !control$trace) {
        # Do not print "Convergence after X iterations" in this case
        control$silent <- TRUE
      }
      
      private$prepare_dynamic_model()
      
      # prepare endo data for solving
      endo_data <- endo_data_solve(private$endo_data,
                                   private$model_period,
                                   maxlag = private$mdldef$max_endo_lag,
                                   maxlead = private$mdldef$max_endo_lead)
    
      if (stacked_time) {
        
        if (!silent) {
          cat(sprintf("\nSolving with stacked time method for period %s\n",
                      as.character(private$model_period)))
        }
        
        solve_fun <- private$solve_stacked_time
        
      } else {
        
        if (!silent) {
          cat(sprintf("\nSolving backwards for period %s\n",
                      as.character(private$model_period)))
        }
        
        solve_fun <- private$solve_backward_model
      }
      
      ret <- solve_fun(endo_data, private$exo_data, solver = solver,
                       silent = silent, control = control, 
                       start_option = start, backrep = backrep, 
                       debug_eqs = debug_eqs, ...)
     
      result <- ret$x
      solved <- ret$solved
      message <- ret$message

      if (!solved && homotopy) {
        
        ret <- private$homotopy(endo_data, private$exo_data, 
                                solve_fun = solve_fun, silent = silent,
                                # the next arguments are only passed to 
                                # solve_fun:
                                solver = solver, control = control,
                                start_option = start,
                                backrep = backrep, debug_eqs = debug_eqs, ...)
        
        
        if (ret$solved) {
          solved <- TRUE
          message <- "ok"
          result <- ret$solution
        }
      }
        
      private$clean_dynamic_model()
      
      # update data with new iterate
      endo_data <- regts(t(matrix(result, 
                                  nrow = private$mdldef$endo_count)),
                                  period = private$model_period, 
                                  names = private$mdldef$endo_names)
      private$endo_data[private$model_period, ] <- endo_data
      
      if (!solved) {
        if (stacked_time && !silent &&  
            grepl("[Ff]unction.*contains non-finite value", message)) {
          report_non_finite_residuals(self)
        }
        private$solve_status <- "ERROR"
        warning(paste0("Model solving not succesful.\n", message))
      } else {
        private$solve_status <- "OK"
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
      
      private$prepare_dynamic_model(solve_first_order = TRUE)
      
      private$ss <- solve_first_order(private$ss, private$calc, 
                                      private$model_index, private$mdldef, 
                                      private$jac_dynamic, 
                                      check_only = FALSE, debug = FALSE,
                                      debug_eqs = FALSE)
      
      private$endo_data <- solve_perturbation_(private$ss,
                                               private$mdldef$max_endo_lag,
                                               private$exo_data, 
                                               private$endo_data,
                                               private$mdldef$exos, 
                                               private$mdldef$endos)
      
      private$clean_dynamic_model()
      return(invisible(self))
    },
    get_jacob = function(sparse = FALSE) {
      if (is.null(private$model_period)) stop(private$period_error_msg)
      
      private$prepare_dynamic_model()
      
      endo_data <- endo_data_solve(private$endo_data,
                                   private$model_period,
                                   maxlag = private$mdldef$max_endo_lag,
                                   maxlead = private$mdldef$max_endo_lead)
      x <- cur_endos(endo_data)
      lags <- lag_endos(endo_data)
      leads <- lead_endos(endo_data)
      nper <- endo_data$nper_cur
      
      jac <- private$get_jac(x, lags, leads, private$exo_data, nper, 
                             debug_eqs = FALSE)
      
      private$clean_dynamic_model()
      
      if (!sparse) {
        jac <- as(jac, "matrix")
      }
      colnames(jac) <- as.character(outer(private$mdldef$endo_names, 1:nper, 
                                          FUN = "paste", sep ="_t"))
      rownames(jac) <- as.character(outer(paste0("eq_", 1:private$mdldef$endo_count), 
                                          1:nper, FUN = "paste", sep ="_t"))
      return(jac)
    },
    get_static_jacob = function(sparse = FALSE) {
      private$prepare_static_model()
      jac <- private$get_static_jac(private$mdldef$endos, debug_eqs = FALSE)
      private$clean_static_model()
      if (!sparse) {
        jac <- as(jac, "matrix")
      }
      colnames(jac) <- private$mdldef$endo_names
      return(jac)
    },
    get_back_jacob = function(period, sparse = FALSE) {
      # returns the Jacobian for the backward looking model
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
      
      period_index <- period - start_period(private$data_period) + 1
      var_indices <- get_var_indices_back(private$mdldef,  period_index)
      
      endo_data <- private$endo_data
      
      data <- t(endo_data)
      lags <- data[var_indices$lags]
      leads <- data[var_indices$leads]
      x    <- data[var_indices$curvars]
      
      private$prepare_dynamic_model()
      jac <- private$get_back_jac(x, lags, leads, private$exo_data, 
                                  period_index, debug_eqs = FALSE)
      private$clean_dynamic_model()
      if (!sparse) {
        jac <- as(jac, "matrix")
      }
      colnames(jac) <- private$mdldef$endo_names
      return(jac)
    },
    get_equations = function(i) {
      if (missing(i)) {
        return(private$mdldef$equations)
      } else {
        if (!is.numeric(i)) {
          stop("Argument i should be a numeric")
        }
        return(private$mdldef$equations[i])
      }
    },
    get_original_equations = function(i) {
      if (missing(i)) {
        return(private$mdldef$equations_orig)
      } else {
        if (!is.numeric(i)) {
          stop("Argument i should be a numeric")
        }
        return(private$mdldef$equations_orig[i])
      }
    },
    get_eigval = function() {
      if (!is.null(private$ss) && !is.null(private$ss$eigval)) {
        return(private$ss$eigval)
      } else {
        stop(paste("Eigenvalues not available. Calculate the eigenvalues",
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
    write_mdl = function(file, silent = FALSE) {
      if (!silent) cat(paste("Writing model to", file, " ...\n"))
      saveRDS(self$serialize(), file)
      if (!silent) cat("Done\n")
      return(invisible(self))
    },
    write_initval_file = function(file) {
      private$prepare_aux_vars()
      write_initval_file_internal(file, private$mdldef, private$model_period, 
                                  private$endo_data, private$exo_data)
      return(invisible(self))
    },
    solve_steady_dynare = function(scratch_dir = tempfile(),  dynare_path = NULL,
                                   model_options, solve_options,
                                   use_octave = Sys.which("matlab") == "",
                                   exit_matlab = FALSE) {
      
      # create mode name based on the name of the DynMdl object
      z <- sys.call()[[1]]
      if (z[[1]] == "$") {
        model_name <- as.character(z[[2]])
      } else {
        model_name <- "mdl"
      }
      
      solve_options_ = list(tolf = 1e-8)
      if (!missing(solve_options)) {
        solve_options_[names(solve_options)] <- solve_options
      }
      
      ret <- solve_steady_dynare_internal(model_name, self, scratch_dir,
                                          dynare_path, model_options, 
                                          solve_options_, use_octave,
                                          exit_matlab)
      
      private$mdldef$endos[names(ret$steady_endos)] <- ret$steady_endos
      
      if (private$mdldef$fit) {
        # make static _exo variables equal to the corresponding static 
        # endogenous variables
        exo_idx <- private$mdldef$fit_info$exo_vars
        endo_idx <- private$mdldef$fit_info$orig_endos
        private$mdldef$exos[exo_idx] <- private$mdldef$endos[endo_idx]
      }
      
      # check solution:
      fmax <- max(abs(self$static_residual_check(include_all_eqs = TRUE)))
      if (is.na(fmax) || fmax > 2 * solve_options_$tolf) {
        warning("Dynare did not find a solution.")
      }
      
      return(ret$eigval)
    },
    solve_dynare = function(scratch_dir = tempfile(), dynare_path = NULL, 
                            model_options, solve_options,
                            initval_type = c("m", "xlsx"),
                            use_octave = Sys.which("matlab") == "",
                            exit_matlab = FALSE) {

      # create mode name based on the name of the DynMdl object
      z <- sys.call()[[1]]
      if (z[[1]] == "$") {
        model_name <- as.character(z[[2]])
      } else {
        model_name <- "mdl"
      }
      
      solve_options_ = list(tolf = 1e-8, tolx = 1e-8)
      if (!missing(solve_options)) {
        solve_options_[names(solve_options)] <- solve_options
      }
      
      initval_type <- match.arg(initval_type)
      
      if (private$mdldef$fit) {
        private$set_old_fit_instruments()
        private$prepare_fit()
      }
      
      solution <- solve_dynare_internal(model_name, self, scratch_dir,
                                        dynare_path, model_options, 
                                        solve_options_, initval_type,
                                        use_octave, exit_matlab)
      
      private$endo_data[private$model_period, colnames(solution)] <- solution
      
      # check solution:
      fmax <- max(abs(self$residual_check(include_all_eqs = TRUE)))
      if (is.na(fmax) || fmax > 2 * solve_options_$tolf) {
        warning("Dynare did not find a solution.")
      }
      return(invisible(self))
    },
    run_initval = function(update_endos = TRUE) {

      if (is.null(private$mdldef$initval)) {
	      stop(paste("Method 'run_initval' not possible because the model file",
                   "has been created with an old version of dynmdl."))
      }
      data <- as.list(c(private$mdldef$endos,
                        private$mdldef$exos,
                        private$mdldef$params))
      expr <- parse(text = private$mdldef$initval)
      result <- unlist(within(data, eval(expr)))
         
      exo_names <- intersect(names(result), private$mdldef$exo_names)
      if (length(exo_names) > 0) { 
        private$mdldef$exos[exo_names] <- result[exo_names]
      }
     
      if (update_endos) {
          endo_names <- intersect(names(result), private$mdldef$endo_names)
          if (length(endo_names) > 0) { 
              private$mdldef$endos[endo_names] <- result[endo_names]
          }
      }
      
      return(invisible(self))
    },
    copy = function() {
      ret <- self$clone(deep = TRUE)
      # We no longer create a new PolishModel object. This is not necessary.
      #if (private$calc == "internal") {
        # Also create a new PolishModel in memory. This is probably not
        # necessary. I once thought that this is necessary for parallization
        # with forking (on Linux and other non-Windows OS), but this is probably
        # not necessary because forking creates a subprocess with its own 
        # virtual memory space. This point should be examined later.
        # See the parallel examples in directory examples.
      #  bin_data <- serialize_polish_models(private$model_index)
      #  ret$model_index <- deserialize_polish_models(bin_data)
      #}
      return(ret)
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
        bin_data <- serialize_polish_models(private$model_index)
      } else {
        bin_data <- NULL
      }
        
      serialized_mdl <- list(version = packageVersion("dynmdl"),
                             mdldef = private$mdldef,
                             calc = private$calc,
                             bin_data = bin_data,
                             dll_basename = basename(private$dll_file),
                             os_type = os_type,
                             model_period = private$model_period,
                             base_period = private$base_period,
                             endo_data = private$endo_data,
                             exo_data = private$exo_data,
                             trend_data = private$trend_data,
                             deflator_data = private$deflator_data)
      return(structure(serialized_mdl, class = "serialized_dynmdl"))
    },
    deserialize = function(ser, dll_dir) {
      
      ser <- update_serialized_mdl(ser)
      
      if (ser$calc == "dll") {
        if (ser$os_type != .Platform$OS.type) {
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
        private$model_index <- deserialize_polish_models(ser$bin_data)
      }
      
      # we don't need these elements anymore
      ser$bin_data <- NULL
      ser$version <- NULL
      ser$dll_basename <- NULL
      ser$os_type <- NULL
      
      # copy remaining elements to the private environment
      if (length(problem_fields <- setdiff(names(ser), names(private))) > 0) {
        problem_fields <- paste0('"', problem_fields, '"')
        stop(sprintf("Corrupt serialized DynMdl. Unknown fields found:\n%s.",
                     paste(problem_fields, collapse = "")))
      }
      list2env(ser, private)
       
      private$make_functions()
      
      # compute derived object members
      if (!is.null(ser$endo_data)) {
        private$data_period <- get_period_range(ser$endo_data)
        private$period_shift <- start_period(private$model_period) - 
                                start_period(private$data_period)
      }
      
      return(invisible(self))
  },
  get_solve_status = function() {
    return(private$solve_status)
  },
  get_aux_vars = function() {
    return(private$mdldef$aux_vars)
  },

  get_exo_data_raw = function() {
    return(private$exo_data)
  },
  get_mdldef = function() {
    return(private$mdldef)
  },
  #####################################################
  # public methods for the fit procedure
  ##################################################
  get_instrument_names = function() {
    private$check_fit()
    return(private$mdldef$fit_info$instruments)
  },
  get_sigma_names = function() {
    private$check_fit()
    return(private$mdldef$fit_info$sigma_names)
  },
  set_fit = function(data, names, name_err = "stop") {
    private$check_fit()
    data <- private$convert_data_internal(data, names)
    names <- private$get_names_("endo", names = colnames(data), 
                                name_err = name_err)
    if (length(names) == 0) return(invisible(self))
    data <- data[ , names, drop = FALSE]
    return(private$set_fit_internal(data, get_period_range(data)))
  },
  set_fit_values = function(value, names, pattern, period) {
    private$check_fit()
    period <- private$check_period_arg(period)
    value <- as.numeric(value)
    nper <- nperiod(period)
    vlen <- length(value)
    if (vlen != 1 && vlen < nper) {
      stop(paste("Argument value should have length 1 or length", nper))
    }
    
    names <- private$get_names_("endo", names, pattern)
    nvar <- length(names)
    if (nvar == 0) return(invisible(self))
    
    data <- matrix(rep(value, nvar), ncol = nvar)
    data <- regts(data, period = period, names = names)
    
    per <- range_intersect(period, private$data_period)
    if (is.null(per)) return(invisible(self))
    return(private$set_fit_internal(data[per], per))
  },
  clear_fit = function() {
    
    private$check_fit()
    self$set_param_values(-1, names = private$mdldef$fit_info$sigma_names)
    
    # static fit targets and lagrange multipliers
    endo_names <-  private$mdldef$endo_names_orig
    fit_targets_steady <- rep(NA_real_, length(endo_names))
    names(fit_targets_steady) <- endo_names
    self$set_fit_steady(fit_targets_steady)
    private$mdldef$endos[private$mdldef$fit_info$l_var_names] <- 0
    
    # dynamic fit targets and lagrange multipliers
    if (!is.null(private$model_period)) {
      self$set_fit_values(NA)
      self$set_endo_values(0, names = private$mdldef$fit_info$l_var_names)
    }
  },
  get_fit = function(pattern, names, period = private$data_period) {
    private$check_fit()
    period_specified <- !missing(period)
    period <- private$check_period_arg(period)
    fit_target_names <- private$mdldef$endo_names_orig
    fit_switch_names <-  private$mdldef$fit_info$fit_vars
    exo_names <- private$mdldef$fit_info$exo_vars
    names_specified <- !missing(pattern) || !missing(names)
    if (names_specified) {
      endo_names <- private$get_names_("endo", names, pattern)
      if (length(endo_names) == 0) return(NULL)
      idx <- match(endo_names, fit_target_names)
      fit_switch_names <- fit_switch_names[idx]
      exo_names <- exo_names[idx]
      fit_target_names <- endo_names
    }
    fit_switches <- private$exo_data[period , fit_switch_names, drop = FALSE]
    fit <- private$exo_data[period, exo_names, drop = FALSE]
    fit[fit_switches == 0] <- NA
    colnames(fit) <- fit_target_names
    
    # remove NA columns and leading/trailing NA rows
    if (!names_specified) {
      fit <- remove_na_columns(fit)
      if (is.null(fit)) {
        if (period_specified) {
          # always return a timeseries with the specified period
          return(regts(matrix(nrow = nperiod(period), ncol = 0), 
                       period = period))
        } else {
          return(NULL)
        }
      }
    }
      
    # remove trailing/leading rows with only NA values 
    # if the period has not been specified
    if (!period_specified) {
      fit <- na_trim(fit)
      if (is.null(fit)) return(NULL)
    }
    
    if (private$mdldef$trend_info$has_deflated_endos) {
      fit <- private$trend_endo_data(fit)
    }
    fit <- update_ts_labels(fit, private$mdldef$labels)
    return(fit)
  },
  get_fit_steady = function(pattern, names) {
    private$check_fit()
    fit_target_names <- private$mdldef$endo_names_orig
    fit_switch_names <-  private$mdldef$fit_info$fit_vars
    exo_names <- private$mdldef$fit_info$exo_vars
    names_specified <- !missing(pattern) || !missing(names)
    if (names_specified) {
      endo_names <- private$get_names_("endo", names, pattern)
      if (length(endo_names) == 0) return(NULL)
      idx <- match(endo_names, fit_target_names)
      fit_switch_names <- fit_switch_names[idx]
      exo_names <- exo_names[idx]
      fit_target_names <- endo_names
    }
    fit_switches <- private$mdldef$exos[fit_switch_names]
    fit <- private$mdldef$exos[exo_names]
    fit[fit_switches == 0] <- NA
    names(fit) <- fit_target_names
    
    # remove NA columns and leading/trailing NA rows
    if (!names_specified) {
      fit <- fit[!is.na(fit)]
      if (length(fit) == 0) fit <- NULL
    }
    return(fit)
  },
  get_fit_instruments = function(pattern, names, period) {
    private$check_fit()
    period <- private$check_period_arg(period, data_period = FALSE)
    if (missing(names) && missing(pattern)) {
      colsel <- private$mdldef$fit_info$instruments
    } else {
      colsel <- private$get_names_("inst", names, pattern)
      if (length(colsel) == 0) return(NULL)
    }
    data <- private$endo_data[period, colsel, drop = FALSE]
    return(update_ts_labels(data, private$mdldef$labels))
  },
  get_lagrange = function(names, period) {
    private$check_fit()
    period <- private$check_period_arg(period, data_period = FALSE)
    if (missing(names)) {
      colsel <- private$mdldef$fit_info$l_vars
    } else {
      colsel <- intersect(names, sort(private$mdldef$fit_info$l_var_names))
      if (length(colsel) == 0) return(NULL)
    }
    return(private$endo_data[period, colsel, drop = FALSE])
  },
  get_sigmas = function() {
    private$check_fit()
    ret <- private$mdldef$params[private$mdldef$fit_info$sigmas]
    return(ret[ret >= 0])
  },
  set_fit_steady = function(data, names, name_err = "stop") {
    private$check_fit()
    data <- private$convert_values_internal(data, names, "data")
    names <- private$get_names_("endo", names = base::names(data), 
                                name_err = name_err)
    if (length(names) == 0) return(invisible(self))
    data <- data[names]
    return(private$set_fit_steady_internal(data))
  }
  ),
  private = list(
    model_index = NA_integer_,  # model index, only used for internal calc.
    mdldef = NULL,
    f_static = NULL,
    jac_static = NULL,
    f_dynamic = NULL,
    jac_dynamic = NULL,
    model_period = NULL,
    data_period =  NULL,
    base_period = NULL,     # base period for computing trends
    period_shift =  NA,
    endo_data = NULL,
    exo_data = NULL,
    trend_data = NULL,
    deflator_data = NULL,
    ss = NULL,
    calc = NA_character_,
    dll_dir = NA_character_,
    dll_file = NA_character_,
    period_error_msg = paste("The model period has not been set.",
                             "Set the model period with set_period()."),
    jac = NULL,
    jac_steady = NULL,
    res = numeric(),
    solve_status = NA_character_,
    get_names_ = function(type, names, pattern,
                          name_err = c("stop", "warn", "silent"),
                          steady = FALSE, sort_pattern_names = FALSE) {
      
      # This function selects model variable names from names and pattern.
      # Tt gives an error if names contain any invalid name for the 
      # specified type of model variable.
      
      #   type
      #   endo             normal endos (endos defined in original mod file)
      #   exo              normal exos (exos defined in original mod file)
      #   endo_exo         normal endos, normal exos
      #   all              normal endos, normal exos, fit instruments and trends.
      #                    trends are included only if steady == FALSE.
      #   all_endo         normal endos, fit instruments, lagrange-multipliers
      #   all_endo_exo     normal endos, fit instruments, lagrange-multipliers,
      #                    normal exos
      #  inst              fit instruments
      #  trend             trend variables
      
      name_err <- match.arg(name_err)
      
      
      get_type_text <- function(type) {
        # this function returns a text describing a variable typr 
        # for the error messages
        type_texts <- c(endo = "endogenous variable",
                        exo = "exogenous variable", 
                        endo_exo = "endogenous or exogenous variable",
                        all = "model variable", 
                        all_endo = "endogenous variable",
                        all_endo_exo = "model variable",
                        inst = "fit instrument",
                        trend = "trend variable")
        
        return(type_texts[type])
      }
      
      if (type == "trend" || (type == "all" && !steady)) {
        trend_names <- private$mdldef$trend_info$trend_vars$names
      } else if (type == "all" && steady) {
        trend_names <- character(0)
      }
      
      if (private$mdldef$fit && type %in% c("all", "inst")) {
        inst_names <- private$mdldef$fit_info$instrument_names
      }
      
      if (type == "endo") {
        vnames <- private$mdldef$endo_names_orig
      } else if (type == "exo") {
        vnames <- private$mdldef$exo_names_orig
      } else if (type == "endo_exo") {
        vnames <- union(private$mdldef$endo_names_orig, 
                        private$mdldef$exo_names_orig)
      } else if (type == "all") {
        vnames <- union(union(private$mdldef$endo_names_orig, 
                              private$mdldef$exo_names_orig), 
                        trend_names)
        if (private$mdldef$fit) vnames <- union(vnames, inst_names)
      } else if (type == "all_endo") {
        vnames <- private$mdldef$endo_names_no_aux
      } else if (type == "all_endo_exo") {
        vnames <- union(private$mdldef$endo_names_no_aux, 
                        private$mdldef$exo_names_orig)
      } else if (type == "inst") {
        vnames <- inst_names
      } else if (type == "trend") {
        vnames <- trend_names
      } else {
        stop(sprintf("Internal error: unknown name type %s\n", type))
      }
      
      if (!missing(names)) {
        error_vars <- setdiff(names, vnames)
        if (length(error_vars) > 0) {
          if (name_err != "silent") {
            error_vars <- paste0("\"", error_vars, "\"")
            type_text <- get_type_text(type)
            if (length(error_vars) == 1) {
              a_word <- if (type %in% c("endo", "exo", "endo_exo", "all_endo"))
                                                   "an" else "a"
              msg <- paste0(error_vars, " is not ", a_word, " ", type_text, ".")
            } else { 
              msg <- paste0("The following names are no ", type_text, 
                           "s: ", 
                           paste(error_vars, collapse = ", "), ".")
            }
            if (name_err == "warn") {
              warning(msg)
            } else {
              stop(msg)
            }
          }
          names <- intersect(names, vnames)
        }
      }
      
      if (missing(pattern) && missing(names)) {
        names <- vnames
      } else if (!missing(pattern)) {
        pattern_names <- grep(pattern, vnames, value = TRUE)
        if (length(pattern_names) == 0) {
          type_text <- get_type_text(type)
          warning(sprintf("No %ss match pattern \"%s\".\n", type_text, pattern))
        }
        if (sort_pattern_names) pattern_names <- sort(pattern_names)
        if (!missing(names)) {
          names <- union(names, pattern_names)
        } else {
          names <- pattern_names
        }
      }
      return(names)
    },
    convert_values_internal = function(data, names, arg_name) {
      # Handle the input of function set_param, set_static_endos, 
      # set_static_exos and set_static_data.
      if (!is.numeric(data)) {
        stop(sprintf("Argument %s must be a numeric vector.", arg_name))
      }
      if (!missing(names)) {
        if (length(names) != length(data)) {
          stop(sprintf(paste("The length of argument names (%d) should be",
                             "equal to the length of argument %s (%d)."),
                       length(names), arg_name, length(data)))
        }
        base::names(data) <- names
      } else if (is.null(base::names(data))) {
        stop(sprintf(paste("If argument %s has no names, than argument",
                           "names must be specified."), arg_name))
      } else {
        names <- base::names(data)
      }
      
      # check for duplicate names
      if (anyDuplicated(names)) {
        dupl <- duplicated(names)
        data <- data[!dupl]
        warning(sprintf(paste("Values contains duplicate names. The first value",
                              "is used.\nThe duplicated names are: %s."),
                        paste(names[dupl], collapse = ", ")))
      }
      return(data)
    },
    convert_data_internal = function(data, names) {
      # Used by set_data and set_fit: checks the period range of data and 
      # selects the appropriate period. Also converts data to a matrix ts with 
      # colnames if necessary.

      if (is.null(private$model_period)) stop(private$period_error_msg)
      
      if (!inherits(data, "ts")) {
        # we use inherits and not is.ts, because is.ts returns FALSE if
        # length(x) == 0
        stop("Argument data is not a timeseries object")
      }
      
      if (NCOL(data) == 0) return(NULL)
      
      data <- as.regts(data)
      
      if (frequency(data) != frequency(private$data_period)) {
        stop(paste0("The frequency of data does not agree with the data",
                    " period ", as.character(private$data_period), "."))
      }
      
      per <- range_intersect(get_period_range(data), private$data_period)
      if (is.null(per)) return(NULL)
      data <- data[per]
   
      # convert data to a matrix if necessary
      if (!is.matrix(data)) {
        dim(data) <- c(length(data), 1)
      }
      
      if (!missing(names)) {
        if (is.null(names)) {
          stop("names is null")
        } else if (length(names) < NCOL(data)) {
          stop(paste("The length of argument names is less than the number of",
                     "columns of data"))
        }
        colnames(data) <- names
      } else if (is.null(colnames(data))) { 
          stop(paste("Argument data has no colnames.",
                   "In that case, argument names should be specified"))
      } else {
        names <- colnames(data)
      }
      
      # check for duplicate names
      if (anyDuplicated(names)) {
        dupl <- duplicated(names)
        data <- data[  , !dupl, drop = FALSE]
        warning(sprintf(paste("Data contains duplicate names. The first column",
                              "is used.\nThe duplicated names are: %s."),
                        paste(unique(names[dupl]), collapse = ", ")))
      }
      
      return(data)
    },
    get_endo_data_internal = function(names, period, trend, 
                                      incl_instr = FALSE) {
      #  Internal function that returns endo data (without labels).
      #  Argument names (if specified) and period are assumed to be correct.
      #  If names has not been specified, all "normal" endos (i.e. the original
      # endogenous variables in the mod file) are returned. If incl_instr,
      # then fit instruments (if present) all included.
      if (missing(names)) {
        if (private$mdldef$has_aux_vars || private$mdldef$fit) {
          colsel <- private$mdldef$endo_indices_orig
          if (private$mdldef$fit && incl_instr) {
            colsel <- c(colsel, private$mdldef$fit_info$instruments)
          }
          data <- private$endo_data[period, colsel, drop = FALSE]
        } else {
          data <- private$endo_data[period]
        }
      } else {
        data <- private$endo_data[period, names, drop = FALSE]
      }
      if (trend && private$mdldef$trend_info$has_deflated_endos) {
        # NOTE: period may include period outside the data_period. The results
        # for these periods are NA, so we do not have to trend this data.
        p <- range_intersect(period, private$data_period)
        data[p] <- private$trend_endo_data(data[p])
      }
      return(data)
    },
    get_static_endos_internal = function(incl_instr = FALSE, 
                                         incl_l_vars = FALSE) {
      #  Internal function that returns the static endo data (without labels).
      #  If incl_instr, then fit instruments (if present) all included.
      #  If incl_l_vars, then Lagrange multiplier (if present) all included.
      if (private$mdldef$has_aux_vars || private$mdldef$fit) {
        sel <- private$mdldef$endo_indices_orig
        if (private$mdldef$fit) {
          if (incl_instr) {
            sel <- c(sel, private$mdldef$fit_info$instruments)
          }
          if (incl_l_vars) {
            sel <- c(sel, private$mdldef$fit_info$l_vars)
          }
        }
        static_endos <- private$mdldef$endos[sel]
      } else {
        static_endos <- private$mdldef$endos
      }
      return(static_endos)
    },
    set_data_ = function(data, type, upd_mode = "upd", fun, init_data = FALSE) {
      # generic function to set or update the endogenous or exogenous
      # variables
  
      names <- colnames(data)
      
      if (!init_data && private$mdldef$trend_info$has_deflated_endos 
          && type == "exo") {
        private$check_change_growth_exos(names)
      }
      
      if (type == "endo") {
        names <- intersect(names, private$mdldef$endo_names_no_aux)
      } else  {
        names <- intersect(names, private$mdldef$exo_names_orig)
      }
      
      if (length(names) == 0) {
        return(invisible(self))
      }
      
      data <- data[ , names, drop = FALSE]
      per <- get_period_range(data)
      
      # handle labels
      lbls <- ts_labels(data)
      if (!is.null(lbls)) {
        names(lbls) <- names
        private$update_labels(lbls)
      }
      
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
        if (private$mdldef$trend_info$has_deflated_endos) {
          new_data <- private$detrend_endo_data(new_data)
        }
        private$endo_data[per, names] <- new_data
      } else {
        private$exo_data[per, names] <- new_data
      }
      return(invisible(self))
    },
    set_values_ = function(value, names, pattern, period, type) {
      value <- as.numeric(value)
      period <- private$check_period_arg(period)
      nper <- nperiod(period)
      vlen <- length(value)
      if (vlen != 1 && vlen < nper) {
        stop(paste("Argument value should have length 1 or",
                   "length", nper))
      }
      
      upd_per <- range_intersect(period, private$data_period)
      if (is.null(upd_per)) {
        warning(sprintf(paste("Specified period (%s) is completely outside the",
                              "data period (%s)."), period, private$data_period))
        return(invisible(self))
      }
      
      get_name_type <- if (type == "endo") {
                          "all_endo"
                        } else {
                          "exo"
                        }
  
      names <- private$get_names_(get_name_type, names, pattern)
      if (length(names) == 0) return(invisible(self))
      if (type == "exo" && private$mdldef$trend_info$has_deflated_endos) {
        private$check_change_growth_exos(names)
      }
                
      # convert value to ts, to that we can select the period                     
      value_ts <- regts(value, period = period)
      
      # finally transfer value_ts to private$endo_data or private$exo_data
      value_ts <- value_ts[upd_per]
      if (type == "endo") {
        private$endo_data[upd_per, names] <- value_ts
        if (private$mdldef$trend_info$has_deflated_endos) {
          private$endo_data[upd_per, names] <- 
            private$detrend_endo_data(private$endo_data[upd_per, names, 
                                                        drop = FALSE])
        }
      } else {
        private$exo_data[upd_per, names] <- value_ts
      }
      return(invisible(self))
    },
    change_data_ = function(fun, names, period, type, ...) {
      period <- private$check_period_arg(period)
      upd_per <- range_intersect(period, private$data_period)
      if (is.null(upd_per)) {
        warning(sprintf(paste("Specified period (%s) is completely outside the",
                              "data period (%s)."), period, 
                        private$data_period))
        return(invisible(self))
      }
      if (!is.function(fun)) {
        stop("Argument 'fun' is not a function.")
      }
      
      # remove duplicated names
      names <- unique(names)
      
      nper <- nperiod(period)
      if (length(names) == 0) return(invisible(self))
      if (type == "endo") {
        data <- private$get_endo_data_internal(names, period, trend = TRUE)
      } else  { 
        if (private$mdldef$trend_info$has_deflated_endos) {
          private$check_change_growth_exos(names)
        }
        data <- private$exo_data[period, names, drop = FALSE]
      }
      
      # now apply function to each timeseries independently
      for (c in seq_len(ncol(data))) {
        fun_result <- fun(as.numeric(data[ , c]), ...)
        result_len <- length(fun_result)
        if (result_len != 1 && result_len != nper) {
          stop(sprintf(paste("The function result has length %d but should have",
                             "length 1 or %d."), result_len, nper))
        }
        data[ , c] <- fun_result
      }
      
      data <- data[upd_per]
      
      if (type == "endo") {
        if (private$mdldef$trend_info$has_deflated_endos) {
          data <- private$detrend_endo_data(data)
        }
        private$endo_data[upd_per, names] <- data
      } else {
        private$exo_data[upd_per, names] <- data
      }
      return(invisible(self))
    },
    solve_stacked_time = function(endo_data, exo_data, solver, silent,
                                  start_option, backrep, ...) { 
      # Arguments start_option, silent and backrep are not used here,
      # but solve_stacked_time can be called with these arguments by methods
      # solve or homotopy.
      endos <- cur_endos(endo_data)
      lags <- lag_endos(endo_data)
      leads <- lead_endos(endo_data)
      nper <- endo_data$nper_cur
      if (solver == "umfpackr") {
        ret <- umf_solve_nl(endos, private$get_residuals, private$get_jac, 
                            lags = lags, leads = leads, exo_data = exo_data, 
                            nper = nper, ...)
      } else if (solver == "nleqslv") {
        nper <- ncol(endos)
        jac_fun <- function(...) {
          return(as(private$get_jac(...), "matrix"))
        }
        ret <- nleqslv(endos, fn = private$get_residuals, jac = jac_fun, 
                       lags = lags, leads = leads, exo_data = exo_data, 
                       nper = nper, method = "Newton", ...)
        ret$solved <- ret$termcd == 1
      }
      return(ret)
    },
    solve_backward_model = function(endo_data, exo_data, solver, silent,
                                    start_option, backrep, ...) {
     
      if (solver == "nleqslv") {
        jac_fun  <- function(...) {
          return(as(private$get_back_jac(...), "matrix"))
        }
      } else {
        jac_fun <- private$get_back_jac
      }
     
      nper <- endo_data$nper_cur
      start_per <- start_period(private$model_period)
      start_per_index_exo <- start_per - start_period(private$data_period) + 1
      
      var_indices <- get_var_indices_back(private$mdldef, 
                                          period_index = endo_data$cur_cols[1])
      
      nendo <- private$mdldef$endo_count
      
      itr_tot <- 0
      error   <- FALSE
      message <- "ok"
      for (iper in 1:nper) {
        period_index_exo <- start_per_index_exo + iper - 1
        per_txt <- as.character(start_per + (iper - 1))
        shift <- (iper - 1) * nendo
        lags <- endo_data$mat[var_indices$lags + shift]
        leads <- endo_data$mat[var_indices$leads + shift]
        curvar_indices <- var_indices$curvars + shift
        if (start_option == "current" || iper == 1) {
          start <- endo_data$mat[curvar_indices]
        }
        if (solver == "nleqslv") {
          out <- nleqslv(start, fn = private$get_back_res, jac = jac_fun, 
                         method = "Newton", lags = lags, leads = leads, 
                         exo_data = exo_data, period_index = period_index_exo, 
                         ...)
          error <- out$termcd != 1
        } else {
          out <- umf_solve_nl(start, fn = private$get_back_res, jac = jac_fun, 
                              lags = lags, leads = leads, exo_data = exo_data, 
                              period_index = period_index_exo, ...)
          error <- !out$solved
        }
        
        if (error && !silent) {
          if (grepl("[Ff]unction.*contains non-finite value", out$message)) {
            res <- private$get_back_res(out$x, lags = lags, leads = leads, 
                                       exo_data = exo_data, 
                                       period_index = period_index_exo, 
                                       debug_eqs = FALSE)
            names(res) <- paste("eq", seq_along(res))
            res <- res[!is.finite(res)]
            cat(sprintf(paste("Non-finite values in residuals in period %s",
                              "for the following equations:\n"), per_txt))
            n_max <- 50
            n_res <- length(res)
            print(res[1:min(n_res, n_max)])
            if (n_res > n_max) cat("[ -- omitted", n_res - n_max,
                                   "equations -- ]\n")
            cat("\n")
          } else {
            cat(paste0(sprintf("Error solving model in period %s:\n", per_txt),
                       out$message))
          }
        }
        
        if (!silent && !error && backrep == "period") {
          cat(sprintf("Convergence for %s in %d iterations\n", per_txt,
                      out$iter))
        }
        
        # update data
        endo_data$mat[curvar_indices] <- out$x
        
        if (start_option == "previous") start <- out$x
        
        itr_tot <- itr_tot + out$iter
        
        if (error) {
          message <- out$message
          break
        }
      }
      
      if (!silent && backrep == "total") {
        if (error) {
          cat(sprintf(paste("Backwards solve failed at period %s.",
                            "Total number of iterations: %d.\n"),
                      per_txt, itr_tot))
        } else {
          cat(sprintf(paste("Backwards solve succesfull. Total number of",
                            "iterations: %d.\n"), itr_tot))
        }
      }
      
      return(list(solved = !error, message = message, x = cur_endos(endo_data)))
    },
    homotopy = function(endo_data, exo_data, solve_fun, silent, ...) {
      
      #
      # now prepare steady values of exogenous variables
      #
      mdldef <- private$mdldef
      fit <- mdldef$fit
      has_exos <- mdldef$exo_count > 0
      maxlag <- mdldef$max_endo_lag
      maxlead <- mdldef$max_endo_lead
      
      if (has_exos) {
        nper_exo <- nrow(exo_data)
        if (fit) {
          exo_indices <- c(mdldef$fit_info$orig_exos, mdldef$fit_info$exo_vars)
          exo_data_steady <- matrix(rep(mdldef$exos[exo_indices], each = nper_exo), 
                                    nrow = nper_exo)
          #colnames(exo_data_steady) <- mdldef$exo_names[exo_indices]
        } else {
          exo_data_steady <- matrix(rep(mdldef$exos, each = nper_exo), 
                                    nrow = nper_exo)
          #colnames(exo_data_steady) <- mdldef$exo_names
        }
      }
      
      if (has_exos) {
        # save the actual values of exogenous variables that we need
        # in the simulation
        if (fit) {
          exo_sim <- exo_data[ , exo_indices, drop = FALSE]
        } else {
          exo_sim <- exo_data
        }
      }
      if (endo_data$has_lags) {
        lags_sim <- lag_endos(endo_data)
        lags_steady <- matrix(rep(mdldef$endos, maxlag), ncol = maxlag)
      }
      if (endo_data$has_leads) {
        leads_sim <- lead_endos(endo_data)
        leads_steady <- matrix(rep(mdldef$endos, maxlead), ncol = maxlead)
      }
      
      cur_endos(endo_data) <- mdldef$endos
      
      if (!silent) {
        cat_header <- function(txt) {
          pre <- paste(rep("+", 10), collapse = "")
          post <- paste(rep("+", 80 - 10 - nchar(txt) - 2), collapse = "")
          cat(paste0("\n", pre, " ", txt, " ", post, "\n\n"))
          return()
        }
        cat("\n")
        cat_header("HOMOTOPY")
      }
      
      step <- 0.5
      LAMBDA_MIN <- 0.1
      lambda_prev <- 0
      iteration <- 0
      success_counter <- 0
      solved <- FALSE
      solution <- NULL
      
      while (TRUE) {
        if (step < LAMBDA_MIN) {
          # minimum homotopy step size of 0.1 seems reasonable
          if (!silent) {
            cat_header(sprintf("HOMOTOPY FAILED (step < %g, final lambda = %g)", 
                               LAMBDA_MIN, lambda))
          }
          break
        }
        iteration <- iteration + 1
        lambda <- lambda_prev + step
        if (lambda >= 1) {
          # make sure that lambda does not exceed the target
          lambda <- 1
          step <- lambda - lambda_prev
        }
        if (!silent) {
          if (iteration > 1) {
            cat("\n")
          }
          cat(sprintf("-------> HOMOTOPY iteration = %d, lambda = %g <------\n\n",
                      iteration, lambda))
        }
        
        #
        # calculate new exogenous variables and lags/leads for tge given value
        # of lambda.
        #
        if (has_exos) {
          if (fit) {
            exo_data[ , exo_indices] <- exo_sim * lambda + 
              exo_data_steady * (1 - lambda)
            
          } else {
            exo_data <- exo_sim * lambda + exo_data_steady * (1 - lambda)
          }
        }
        if (private$calc == "internal") {
          internal_dyn_set_exo(private$model_index, exo_data, nrow(exo_data))
        }
        
        if (endo_data$has_lags) {
          lag_endos(endo_data) <- lags_sim * lambda + 
                                                lags_steady * (1 - lambda)
        }
        if (endo_data$has_leads) {
          lead_endos(endo_data) <- leads_sim * lambda + 
            leads_steady * (1 - lambda)
        }
        
        ret <- solve_fun(endo_data, exo_data, silent = silent, ...)
        
        if (ret$solved) {
          if (lambda == 1) {
            if (!silent) {
              cat_header(sprintf("HOMOTOPY SUCCESFUL after %d iterations", 
                                 iteration))
            }
            solution <- ret$x
            solved <- TRUE
            break
          }
          lambda_prev <- lambda
          succes_counter <- success_counter + 1
          if (success_counter >= 3) {
            step <- step * 2
            success_counter <- 0
          }
          # update endogenous variables with new solution
          cur_endos(endo_data) <- ret$x
          
        } else {
          # failure, step back
          success_counter <- 0
          step <- step / 2
        }
      }
      
      return(list(solved = solved, solution = solution))
    },
    check_change_growth_exos = function(names) {
      growth_exos <- intersect(names, private$mdldef$trend_info$growth_exos)
      if (length(growth_exos) > 0) {
        stop(paste0("It is not allowed to modify growth exos ",
                    paste(growth_exos, collapse = ", "),
                    "\nwith functions set_values, set_data or change_data.\n",
                    "Growth exos can only be set with function init_data."))
      }
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
    get_residuals = function(x, lags, leads, exo_data, nper, debug_eqs) {
      endos <- c(lags, x, leads)
      if (private$calc == "internal") {
        # NOTE: parameters and exo_data should be set in the C++ version of the 
        # model using C++ function prepare_internal_dyn or internal_dyn_set_exo.
        return(get_residuals_dyn(private$model_index, endos,
                                 which(private$mdldef$lead_lag_incidence != 0) - 1,
                                 private$mdldef$endo_count, nper,
                                 private$period_shift, debug_eqs))
      } else {
        return(get_residuals_(endos,
                              which(private$mdldef$lead_lag_incidence != 0) - 1,
                              exo_data, private$mdldef$params,
                              private$f_dynamic, private$mdldef$endo_count,
                              nper, private$period_shift))
      }
    },
    get_static_residuals  = function(endos, debug_eqs) {
      if (private$calc == "internal") {
        return(get_residuals_stat(private$model_index, endos, debug_eqs))
      } else {
        return(private$f_static(endos, private$mdldef$exos, 
                                private$mdldef$params))
      }
    },
    get_jac = function(x, lags, leads, exo_data, nper, debug_eqs) {
      endos <- c(lags, x, leads)
      tshift  <- -private$mdldef$max_endo_lag : private$mdldef$max_endo_lead
      if (private$calc == "internal") {
        # NOTE: parameters and exo_data should be set in the C++ version of the 
        # model using C++ function prepare_internal_dyn or internal_dyn_set_exo.
        mat_info <- get_triplet_jac_dyn(private$model_index, endos, 
                          private$mdldef$lead_lag_incidence, tshift, 
                          private$mdldef$endo_count, nper, private$period_shift,
                          debug_eqs)
      } else {
        mat_info <- get_triplet_jac(endos, private$mdldef$lead_lag_incidence,
                                    tshift, exo_data,
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
    get_static_jac = function(x, debug_eqs) {
      # private function to obtain the jacobian for the static model
      if (private$calc == "internal") {
        mat_info <- get_triplet_jac_stat(private$model_index, x, 
                                         debug_eqs)
      } else {
        mat_info <- private$jac_static(x, private$mdldef$exos, 
                                       private$mdldef$params)
      }
      return(sparseMatrix(i = mat_info$rows, j = mat_info$cols,
                          x = mat_info$values, 
                          dims = as.integer(rep(private$mdldef$endo_count, 2))))
    },
    get_back_res = function(x, lags, leads, exo_data, period_index, debug_eqs) {
      # private function to obtain the backward residuals at period period_index
      if (private$calc == "internal") {
        # NOTE: parameters and exo_data should be set in the C++ version of the 
        # model using C++ function prepare_internal_dyn or internal_dyn_set_exo.
        return(get_res_back_dyn(private$model_index, x, lags, leads, 
                                period_index, debug_eqs))
      } else {
        return(private$f_dynamic(c(lags, x, leads), exo_data, 
                                 private$mdldef$params, period_index))
      }
    },
    get_back_jac = function(x, lags, leads, exo_data, period_index, debug_eqs) {
      # private function to obtain the backward jacobian at period period_index
      jac_cols <- private$mdldef$lead_lag_incidence[, "0"]
      if (private$calc == "internal") {
        # NOTE: parameters and exo_data should be set in the C++ version of the 
        # model using C++ function prepare_internal_dyn or internal_dyn_set_exo.
        mat_info <- get_jac_back_dyn(private$model_index, x, lags, 
                                     leads, jac_cols, period_index, debug_eqs)
      } else {
        mat_info <- get_jac_backwards(x, lags, leads, jac_cols, 
                                      exo_data, private$mdldef$params, 
                                      private$jac_dynamic, period_index)
      }
      return(sparseMatrix(i = mat_info$rows, j = mat_info$cols,
                          x = mat_info$values, 
                          dims = as.integer(rep(private$mdldef$endo_count, 2))))
    },
    prepare_dynamic_model = function(solve_first_order =  FALSE) {
      
      if (!solve_first_order) {
        # prepare the auxiliary variables
        if (private$mdldef$has_aux_vars) private$prepare_aux_vars()
        # prepare old fit instruments
        if (private$mdldef$fit) private$set_old_fit_instruments()
      }

      #
      # prepare dll calculations or the internal calculator
      #
      
      if (private$calc == "dll") {
        dyn.load(private$dll_file)
        # NOTE: the basename of the dll_file is always "mdl_functions".
        # Therefore we cannot solve two DynMdl objects simultaneously.
        # This will always never occur, except when the model contains
        # a function that calls another function.
        #
      } else if (private$calc == "internal") {
        
        if (solve_first_order) {
          # for method check or solve_perturbation, we should use the static 
          # exos for computing the Jacobian
          nper_exo <- private$mdldef$max_exo_lag + 
                      private$mdldef$max_exo_lead + 1 
          exo_data <- matrix(rep(private$mdldef$exos, each = nper_exo), 
                             nrow = nper_exo)
          per_freq <- -1
          first_per_subp_count <- -1
        } else {
          exo_data <- private$exo_data
          per_freq <- frequency(private$data_period)
          first_per_subp_count <- as.numeric(start_period(private$data_period))
        }
        
        prepare_internal_dyn(private$model_index, exo_data,
                              nrow(exo_data), private$mdldef$params,
                              per_freq, first_per_subp_count)
      }
      
     
      
      return(invisible(NULL))
    },
    clean_dynamic_model = function() {
      if (private$calc == "dll") {
        dyn.unload(private$dll_file)
      }
      return(invisible(NULL))
    },
    prepare_static_model = function() {
      # prepare old fit instruments
      if (private$mdldef$fit) private$set_old_fit_instruments_steady()
      if (private$calc == "dll") {
        dyn.load(private$dll_file)
      } else if (private$calc == "internal") {
        prepare_internal_stat(private$model_index, private$mdldef$exos,
                              private$mdldef$params)
      }
      return(invisible(NULL))
    },
    clean_static_model = function() {
      if (private$calc == "dll") {
        dyn.unload(private$dll_file)
      }
      return(invisible(NULL))
    },
    prepare_aux_vars = function() {
      # calculate the auxiliary auxiliary variables before solving
      if (!private$mdldef$has_aux_vars) {
        return()
      }
      
      aux_vars <- private$mdldef$aux_vars
      orig_endo_data <- private$endo_data[ , aux_vars$orig_endos, drop = FALSE]

      nper <- nrow(private$endo_data)

      orig_endo_data <- private$endo_data[ , aux_vars$orig_endos, drop = FALSE]
      orig_leads <- aux_vars$orig_leads
      endo_index <- aux_vars$endos
      for (i in seq_len(aux_vars$aux_count)) {
        sel <- if (orig_leads[i] > 0) {
                    1 : (nper - orig_leads[i])
               } else {
                   (-orig_leads[i] + 1) : nper
               }
        sel2 <- sel + orig_leads[i]
        private$endo_data[sel , endo_index[i]] <- orig_endo_data[sel2 , i] 
      }
      return()
    },
    check_model_period = function(period) {
      
      if (frequency(period) != frequency(private$data_period)) {
        stop(paste0("The specified period (", period, 
                    ") has a different frequency than the data period (",
                    private$data_period, ")."))
      }
      
      ps <- start_period(private$data_period) + private$mdldef$max_lag_orig
      pe <- end_period(private$data_period)   - private$mdldef$max_lead_orig
      
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
        names <- intersect(names(labels), union(private$mdldef$endo_names_orig, 
                                                private$mdldef$exo_names_orig))
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
          private$f_static <- compiler::cmpfun(private$f_static)
          private$f_dynamic <- compiler::cmpfun(private$f_dynamic)
        }
        
      } else if (private$calc == "dll") {    # dll option
        
        # allocate memory for function f_static, f_dynamic, 
        # jac_static and jac_dynamic. It is more efficient to
        # allocate the memory once.
    
        private$res <- numeric(private$mdldef$endo_count)
        
        private$jac  <- list(
          rows   = integer(private$mdldef$jac_dynamic_size),
          cols   = integer(private$mdldef$jac_dynamic_size),
          values = numeric(private$mdldef$jac_dynamic_size))
        
        
        private$jac_steady <- list(
          rows   = integer(private$mdldef$jac_static_size),
          cols   = integer(private$mdldef$jac_static_size),
          values = numeric(private$mdldef$jac_static_size))
        
        private$f_static <- function(y, x, params) {
          # NOTE: creating a new res array every function call is
          # inefficient, therefore use private$res.
          .Call("f_static_", y, x, params, private$res, 
                PACKAGE = "mdl_functions")
          return(private$res)
        }
        
        private$jac_static <- function(y, x, params) {
          # NOTE: creating a new jac_steady every function call is
          # inefficient, therefore use private$jac_steady.
          .Call("jac_static_", y, x, params, private$jac_steady$rows,
                private$jac_steady$cols, private$jac_steady$values,
                PACKAGE = "mdl_functions")
          return(private$jac_steady)
        }
        
        private$f_dynamic <- function(y, x, params, it) {
          # NOTE: creating a new res array every function call is
          # inefficient, therefore use private$res.
          .Call("f_dynamic_", y, x, params, it - 1, 
                nrow(x), private$res, PACKAGE = "mdl_functions")
          return(private$res)
        }
        
        private$jac_dynamic <- function(y, x, params, it) {
          # NOTE: creating a new jac every function call is
          # inefficient, therefore use private$jac
          .Call("jac_dynamic_", y, x, params, it - 1, nrow(x),
                private$jac$rows, private$jac$cols, private$jac$values,
                PACKAGE = "mdl_functions")
          return(private$jac)
        }
      }
    },
    check_period_arg = function(period, data_period = TRUE) {
      if (is.null(private$model_period)) stop(private$period_error_msg)
      defaultp <- if (data_period) private$data_period else private$model_period
      if (missing(period)) {
        return(defaultp)
      } else {
        period <- as.period_range(period)
        f_mdl <- frequency(private$data_period)
        f_per <- frequency(period)
        if (f_per > f_mdl) {
          stop(paste0("Period ", period, " has a higher frequency than ",
                      "the model period ", private$model_period, "."))
        } else if (f_per < f_mdl)  {
          period <- change_frequency(period, f_mdl)
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
    },
    check_param_names = function(names, 
                                 name_err = c("stop", "warn", "silent")) {
      name_err <- match.arg(name_err)
      # check if names are parameter names
      no_params <- setdiff(names, private$mdldef$param_names)
      if (length(no_params) > 0) {
        if (name_err != "silent") {
          no_params <- paste0("\"", no_params, "\"")
          if (length(no_params) == 1) {
            msg <- paste0(no_params, " is not a parameter.")
          } else { 
            msg <- paste0("The following names are no parameters: ",
                          paste(no_params, collapse = ", "), ".")
          }
          fun <- if (name_err == "stop") stop else warning
          fun(msg)
        }
        return(intersect(names, private$mdldef$param_names))
      } else {
        return(names)
      }
    },
    get_param_names_ = function(pattern, names) {
      if (!missing(names)) {
        names <- private$check_param_names(names)
      }
      if (missing(pattern) && missing(names)) {
        return(private$mdldef$param_names)
      } else if (missing(names)) {
        return(self$get_par_names(pattern))
      } else if (!missing(pattern)) {
        return(union(names, self$get_par_names(pattern)))
      } else {
        return(names)
      }
    },
    get_trend_data_internal = function() {
      #
      # calculate trend variables
      #
      mdldef <- private$mdldef
      trend_info <- mdldef$trend_info
      trend_var_info <- trend_info$trend_vars
      
      if (length(trend_info$growth_exos) > 0) {
        exo_data <- as.list(private$exo_data[ , trend_info$growth_exos, 
                                              drop = FALSE]) 
      } else {
        exo_data <- list()
      }
      
      growth_factor_data <- sapply(trend_info$growth_factors, FUN = function(x) 
                 {eval(parse(text = x), envir = exo_data)}, simplify = FALSE)
      
      trend_data <- growth_factor_data[trend_var_info$growth_factors]
      names(trend_data) <- trend_var_info$names
      
      trend_data <- do.call(cbind, trend_data)
  
      if (is.null(trend_data)) {
        return(NULL)
      }
  
      trend_data <- rel2index(trend_data - 1, base = private$base_period, 
                                         scale = 1)
      
      if (!is.matrix(trend_data)) {
        dim(trend_data) <- c(length(trend_data), 1)
        colnames(trend_data) <- trend_var_info$names
      }
      
      return(trend_data)
    },
    get_deflator_data_internal = function() {
      #
      # calculate trend variables
      #
      mdldef <- private$mdldef
      trend_info <- mdldef$trend_info
      
      if (!trend_info$has_deflated_endos) {
        return(NULL)
      }
      
      data <- as.list(private$trend_data)
      deflator_data <- sapply(trend_info$deflators, FUN = function(x) 
            {eval(parse(text = x), envir = data)}, simplify = FALSE)
      
      deflator_data <- do.call(cbind, deflator_data)
      if (!is.matrix(deflator_data)) {
        dim(deflator_data) <- c(length(deflator_data), 1)
        colnames(deflator_data) <- trend_info$deflators
      }
      
      return(deflator_data)
    },
    trend_endo_data = function(endo_data) {
      return(private$trend_detrend_endo_data(endo_data, TRUE))
    },
    detrend_endo_data = function(endo_data) {
      return(private$trend_detrend_endo_data(endo_data, FALSE))
    },
    trend_detrend_endo_data = function(endo_data, trend) {                                
      
      defl_endos <- subset(private$mdldef$trend_info$deflated_endos,
                           names %in% colnames(endo_data))
      if (nrow(defl_endos) == 0) {
        return(endo_data)
      }
  
      dp <- get_period_range(endo_data)
      if (range_intersect(dp, private$data_period) != dp) {
        stop(paste("Internal error in trend_detrend_endo_data:",
                   "Period range of endo_data not within data period."))
      }    
      
      defl_data <- private$deflator_data[ , defl_endos$deflators]

      sel <- match(defl_endos$names, colnames(endo_data))
      if (trend) {
        endo_data[ , sel] <- endo_data[ , sel] * defl_data
      } else {
        endo_data[ , sel] <- endo_data[ , sel] / defl_data
      }  
      return(endo_data)
    },
    check_debug_eqs = function(debug_eqs) {
      if (debug_eqs && private$calc != "internal") {
        warning("Argument debug_eqs is only used if calc = \"internal\"")
      }
      return()
    },
    ######################################################################
    # private methods for the fit procedure
    ######################################################################
    check_fit = function() {
      if (!private$mdldef$fit) {
        stop("This DynMdl object is not a fit model.")
      }
      return()
    },
    set_fit_internal = function(data, period) {
      
      # internal version of set_fit which does not need to check names
      # and the number of columns of data.
      
      if (private$mdldef$trend_info$has_deflated_endos) {
        data <- private$detrend_endo_data(data)
      }
      
      fit_names <- colnames(data)
      fit_names_idx <- match(fit_names, private$mdldef$endo_names_orig)
      
      data_na <- is.na(data)
      
      # set fit switches
      exo_names <- private$mdldef$fit_info$fit_vars[fit_names_idx]
      private$exo_data[period, exo_names] <- ifelse(data_na, 0, 1)
      
      # Set fit exo values. Note: when the fit target is NA, the value
      # of the fit exo value is irrelevant and can be set to 0.
      data[data_na] <- 0
      colsel <- private$mdldef$fit_info$exo_vars[fit_names_idx]
      private$exo_data[period, colsel] <- data
      return(invisible(self))
    },
    prepare_fit = function() {
      #
      # prepare the model for the fit procedure, called by method solve
      #
      mp <- private$model_period
      
      fit_switches <- private$exo_data[mp, private$mdldef$fit_info$fit_vars, 
                                       drop = FALSE]
      fit_sel <- fit_switches == 1
      
      is_fit_var <- apply(fit_sel, MARGIN = 2, FUN = any)
      n_fit <- sum(is_fit_var)
      
      # get all instruments actually used (the sigmas are > 0)
      sigmas <- private$mdldef$params[private$mdldef$fit_info$sigmas]
      sel <- sigmas > 0
      instruments <- private$mdldef$fit_info$instruments[sel]
      
      if (n_fit > 0) {
        
        n_instruments <- length(instruments)
        
        # check if there are sufficient fit instruments
        if (n_instruments < n_fit) {
          stop(sprintf(paste("The number of fit targets (%d) exceeds the",
                             "number of fit instruments (%d)\n."),
                       n_fit, n_instruments))
        }
        
        # make endo data equal to fit result.
        private$endo_data[mp, private$mdldef$endo_indices_orig][fit_sel] <-
          private$exo_data[mp, private$mdldef$fit_info$exo_vars][fit_sel]
      }
      return(list(n_fit = n_fit, instruments = instruments))
    },
    set_old_fit_instruments = function() {
      # set old_instruments, these will be used for deactivated 
      # fit instruments (instruments with sigma < 0), so that the
      # sigmas do not change.
      private$exo_data[ , private$mdldef$fit_info$old_instruments] <-
                private$endo_data[ , private$mdldef$fit_info$instruments]
      return()
    },
    set_fit_steady_internal = function(data) {
      
      # internal version of set_fit which does not need to check names
      # and the number of columns of data.
      
      fit_names <- names(data)
      fit_names_idx <- match(fit_names, private$mdldef$endo_names_orig)
      
      data_na <- is.na(data)
      
      # set fit switches
      exo_names <- private$mdldef$fit_info$fit_vars[fit_names_idx]
      
      private$mdldef$exos[exo_names] <- ifelse(data_na, 0, 1)
      
      # Set fit exo values. Note: when the fit target is NA, the value
      # of the fit exo value is irrelevant and can be set to 0.
      data[data_na] <- 0
      sel <- private$mdldef$fit_info$exo_vars[fit_names_idx]
      private$mdldef$exos[sel] <- data
      
      return(invisible(self))
    },
    prepare_fit_steady = function() {
      #
      # prepare the model for the fit procedure, called by method solve
      #
      fit_switches <- private$mdldef$exos[private$mdldef$fit_info$fit_vars]
      is_fit_var <- fit_switches == 1
     
      n_fit <- sum(is_fit_var)
      
      # get all instruments actually used (the sigmas are > 0)
      sigmas <- private$mdldef$params[private$mdldef$fit_info$sigmas]
      sel <- sigmas > 0
      instruments <- private$mdldef$fit_info$instruments[sel]
      
       if (n_fit > 0) {
        
        n_instruments <- length(instruments)
        
        # check if there are sufficient fit instruments
        if (n_instruments < n_fit) {
          stop(sprintf(paste("The number of fit targets (%d) exceeds the",
                             "number of fit instruments (%d)\n."),
                       n_fit, n_instruments))
        }
        
        # make endo data equal to fit result.
        private$mdldef$endos[private$mdldef$endo_indices_orig][is_fit_var] <-
            private$mdldef$exos[private$mdldef$fit_info$exo_vars][is_fit_var]
      }
      return(list(n_fit = n_fit, instruments = instruments))
    },
    set_old_fit_instruments_steady = function() {
      # set old_instruments, these will be used for deactivated 
      # fit instruments (instruments with sigma < 0), so that the
      # sigmas do not change.
      private$mdldef$exos[private$mdldef$fit_info$old_instruments] <-
        private$mdldef$endos[private$mdldef$fit_info$instruments]
      return()
    }
  )
)
