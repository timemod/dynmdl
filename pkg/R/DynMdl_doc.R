#' \code{\link{DynMdl}} method: initializes the model data.
#' @name init_data
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}} initializes the
#' model data.
#' 
#' This method sets the model data period and initializes
#' the model variables with static values
#' of the exogenous and endogenous model variables.
#'
#' This methods also sets the model period, the standard period
#' for which the model will be solved. The model period
#' is obtained from the data period by subtracting the lag and lead periods.
#' @section Usage:
#' \preformatted{
#' mdl$init_data(data_period = NULL, data = NULL, upd_mode = c("upd", "updval"))
#'
#' }
#'
#' \code{mdl} is a \code{DynMdl} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{data_period}}{\code{\link[regts]{period_range}}
#' object, or an object that can be coerced to 
#' \code{\link[regts]{period_range}},}
#' \item{\code{data}}{a \code{\link[stats]{ts}} or \code{\link[regts]{regts}}
#' object with values for endogogenous and exogenous model variables.
#' If \code{data} has labels, then these labels are used to update the model 
#' labels.}
#'  \item{\code{upd_mode}}{the update mode, a character string specifying
#' how the timeseries in object \code{data} are transferred to the 
#' model data. For  \code{"upd"} (standard update, default), the timseseries
#' in \code{data} are used to replace the steady state values of the 
#' exogenous and endogenous model variables.
#' For \code{"updval"}, the static model variables are only replaced
#' by valid (i.e. non-\code{NA}) values in \code{data}). }
#' }
#' If neither \code{data_period} nor \code{data} have been specified,
#' then the data period is determined from the model period (which in that
#' case must have been specified before \code{init_data} is called).
#' @examples
#' mdl <- islm_mdl()
#' mdl$init_data("2017Q2/2021Q3")
NULL

#' \code{\link{DynMdl}} method: sets the model period
#' @name set_period
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}} sets the model period.
#' This is the default period used when solving the model.
#' 
#' If the model data has not already been initialized with method
#' \code{\link{init_data}}, then \code{set_period} also initializes
#' the model data. In that case the model data period is set to the 
#' specified model period extended with a lag and lead period.
#' Model timeseries are initialized with 
#' with the static values of the exogenous and endogenous model variables.
#'
#' If the model data has already been initialized with  method
#' \code{\link{init_data}}, then the new model period
#' should be compatible with the model data period. 
#' In particular, the new model period extended with a lag and lead period
#' should not contain periods outside the model data period.
#' @section Usage:
#' \preformatted{
#' mdl$set_period(period)
#'
#' }
#'
#' \code{mdl} is a \code{DynMdl} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{period}}{\code{\link[regts]{period_range}}
#' object, or an object that can be coerced to 
#' \code{\link[regts]{period_range}}}
#' }
#'
#' @examples
#' mdl <- islm_mdl()
#' mdl$set_period("2017Q2/2021Q3")
NULL

#' \code{\link{DynMdl}} method: return the model, data, lead or lag period
#' @name get_period-methods
#' @aliases get_period get_data_period get_lag_period get_lead_period
#'
#' @description
#' These methods of R6 class \code{\link{DynMdl}} return the model period,
#' data period, lag period and lead period, respectively.
#' 
#' The \emph{model period} is the default period for which the model will be 
#' solved. The \emph{data period} is the period for which the model contains
#' the values for the endogenous and exogenous variables. If a model has lags,
#' then the data period always include the \emph{lag period}: the period
#' before the model period where the lags needed to solve the model in the
#' model period are stored. For a model with leads the model
#' data period also includes a \emph{lead_period}. Thus, the data period
#' always contains the lag period, model period and lead period, but it may
#' also be longer. See the example below.
#'
#' @section Usage:
#' \preformatted{
#' 
#' mdl$get_period()
#'
#' mdl$get_data_period()
#' 
#' mdl$get_lag_period()
#' 
#' mdl$get_lead_period()
#' 
#' }
#'
#' \code{mdl} is a \code{DynMdl} object
#' 
#' @section Methods:
#' \itemize{
#' \item \code{get_period}: Returns the model period
#' \item \code{get_data_period}: Returns the data period
#' \item \code{get_lag_period}: Returns the lag period, or \code{NULL} is the
#' model has no lags
#' \item \code{get_lead_period}: Returns the lead period or \code{NULL} is the
#' model has no leads
#' }
#' 
#' @examples
#'
#' # For this example we first create a model with a data period 
#' # starting many periods before the model period.
#' mdl <- islm_mdl()
#' mdl$init_data("1997Q1/2022Q4")
#' mdl$set_period("2017Q4/2022Q3")
#' 
#' print(mdl$get_period())        # result: "2017Q1/2022Q3"
#' print(mdl$get_data_period())   # result: "1997Q1/2022Q4"
#' 
#' # This model has a maximum lag and lead of 1, so the lag
#' # and lag period are simple the period before and after the model period.
#' print(mdl$get_lag_period())    # result: "2017Q3"
#' print(mdl$get_lead_period())   # result: "2022Q4"
#'
#' @seealso
#' \code{\link{set_period}} and \code{\link{init_data}}
NULL

#' \code{\link{DynMdl}} methods: Retrieve timeseries from the model data
#' @name get_data-methods
#' @aliases get_data get_endo_data get_exo_data get_trend_data
#' @description
#' These methods of R6 class \code{\link{DynMdl}} 
#' can be used to retrieve timeseries from the model data.
#'
#' If the \code{DynMdl} object is also a \code{\link{FitMdl}} object, then
#' \code{get_data} also returns the fit instruments. In contrast,
#' \code{get_endo_data} does not return these fit instruments.
#' Both \code{get_data} and \code{get_endo_data} do not return
#' the Lagrange multipliers used in the fit procedure. Use method  
#' \code{\link{get_lagrange}} to obtain these Lagrange multipliers.
#'
#' @section Usage:
#' \preformatted{
#' 
#' mdl$get_data(pattern, names, period = mdl$get_data_period(), 
#'              trend = TRUE)
#' 
#' mdl$get_endo_data(pattern, names, period = mdl$get_data_period(),
#'                   trend = TRUE)
#'
#' mdl$get_exo_data(pattern, names, period = mdl$get_data_period())
#' 
#' mdl$get_trend_data(pattern, names, period = mdl$get_data_period())
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{pattern}}{a regular expression}
#' \item{\code{names}}{a character vector with variable names}
#' \item{\code{period}}{an \code{\link[regts]{period_range}} object or an
#' object that can be coerced to a \code{period_range}}
#' \item{\code{trend}}{a logical. This argument is used for model with
#' trend variables. If \code{TRUE} (the default), then the
#' endogenous variables are multiplied with their trends (called deflators
#' in the mod file)}
#' }
#' 
#' If neither \code{names} nor \code{pattern} have been specified,
#' then all variables with the specific type are returned.
#' @section Methods:
#' \itemize{
#' 
#' \item \code{get_data}: All model variables: exogenous and endogenous model
#' variables, trends variables, and fit instruments for \code{\link{FitMdl}}
#' objects
#' \item \code{get_endo_data}: Endogenous model variables, excluding
#' fit instruments.
#' \item \code{get_exo_data}: Exogenous model variables
#' \item \code{get_trend_data}: Trend variables (variables declared with
#' \code{trend_var} in the mod file).
#' }
#'
#' @seealso \code{\link{get_fit-methods}}, \code{\link{get_fit}}, \code{\link{get_fit_instruments}},
#' \code{\link{get_lagrange}} and \code{\link{get_vars_pars}}.
#' @examples
#' mdl <- islm_mdl(period = "2017Q1/2017Q3")
#' 
#' mdl$get_data(names = "c", pattern  = "y.", period = "2017Q1/2017Q2")
NULL

#' \code{\link{DynMdl}} method: transfers data from a timeseries 
#' object to the model data
#' @name set_data
#' @description
#' This method of R6 class \code{\link{DynMdl}} 
#' transfers data from a timeseries object to the model data
#' (both endogenous and exogenous)
#'
#' @section Usage:
#' \preformatted{
#' mdl$set_data(data, names = colnames(data), 
#'              upd_mode = c("update", "updval"), fun,
#'              name_err = c("stop", "warn", "silent"))
#' 
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object
#' 
#' @section Arguments:
#'
#' \describe{
#' \item{\code{data}}{a \code{\link[stats]{ts}} or \code{\link[regts]{regts}}
#'  object. If \code{data} has labels, then \code{set_data} will also update
#' the labels of the corresponding model variables}
#' \item{\code{names}}{a character vector with variable names. Defaults to the
#' column names of \code{data}. If \code{data} does not have column names,
#' then argument \code{names} is mandatory}
#' \item{\code{upd_mode}}{the update mode, a character string specifying
#' how the timeseries are updated: \code{"upd"} (standard update, default) or
#' \code{"updval"} (update only with valid numbers). See details.}
#' \item{\code{fun}}{a function used to update the model data. This should
#' be a function with two arguments. The original model data is passed to 
#' the first argument of the function and \code{data} to the second argument.
#' See the examples.}
#' \item{\code{name_err}}{this option specifies the action that should be taken 
#' when a variable name is not a model variable.
#' For \code{"stop"} (the default), the execution of this function is stopped.
#' For \code{"warn"} and \code{"silent"} the timeseries that are no model
#' variables are skipped. \code{"warn"} does however give a warning.}
#' }
#'
#' @section Details:
#'
#' Method \code{set_data} transfers data from a timeseries object to the
#' model data. If \code{data} is a multivariate timeseries object, then
#' each column is used to update the model variable with the same
#' name as the column name. If \code{data} does not have column names,
#' or if the column names do not correspond to the model variable names,
#' then argument \code{names} should be specified.
#'
#' By default, all values in \code{data} are used to update the corresponding
#' model variable. Sometimes it is desirable to skip the \code{NA} values
#' in \code{data}. This can be achieved by selecting \code{"updval"} for argument
#' \code{upd_mode}. Other non finite numbers (\code{NaN}, \code{Inf}, and
#' \code{-Inf}) are also disregarded for this update mode.
#' The argument \code{upd_mode} controls how the timeseries are updated:
#' \describe{
#' \item{\code{"update"}}{Model variables are updated with the 
#' timeseries in \code{data}}
#' \item{\code{"updval"}}{Model variables are updated with the non \code{NA}
#' values in \code{data}}
#' }
#' 
#' @examples
#'
#' mdl <- islm_mdl(period = "2017Q1/2017Q3")
#'
#' # create a multivariate regts object for exogenous variables g and md
#' exo <- regts(matrix(c(200, 210, 220, 250, 260, 270), ncol = 2),
#'              start = "2017Q1", names = c("g", "ms"))
#'
#' # set and print data
#' mdl$set_data(exo)
#' print(mdl$get_exo_data())
#'
#' # create a univariate regts object for exogenous variable ms,
#' # with a missing value in 2017Q2
#' ms <- regts(c(255, NA, 273), start = "2017Q1")
#'
#' # update with update mode updval (ignore NA)
#' # note that here we have to specify argument names,
#' # because ms does not have column names
#' mdl$set_data(ms, names = "ms", upd_mode = "updval")
#' print(mdl$get_exo_data())
#'
#' # in the next example, we use argument fun to apply an additive shock to the
#' # exogenous variables g and ms.
#' shock <- regts(matrix(c(-5, -10, -15, 3 , 6, 6), ncol = 2),
#'              start = "2017Q1", names = c("g", "ms"))
#' mdl$set_data(shock, fun = function(x1, x2) {x1 + x2})
#'
#' # the statement above can be more concisely written as
#' mdl$set_data(shock, fun = `+`)
#' #`+` is a primitive function that adds its two arguments.
#'
#' @seealso \code{\link{get_data-methods}}, 
#' \code{\link{set_values-methods}} and
#' \code{\link{change_data-methods}}
NULL

#' \code{\link{DynMdl}} methods: Sets the values of the model data
#' @name set_values-methods
#' @aliases set_endo_values set_exo_values
#' @description
#' This method of R6 class \code{\link{DynMdl}} 
#' can be used to set the values of the model data
#'
#' @section Usage:
#' \preformatted{
#'
#' mdl$set_endo_values(value, names, pattern, period = mdl$get_data_period())
#'
#' mdl$set_exo_values(value, names, pattern, period = mdl$get_data_period())
#'
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{value}}{a numeric vector of length 1 or with the same length
#' as the length of the range of \code{period}}
#' \item{\code{names}}{a character vector with variable names}
#' \item{\code{pattern}}{a regular expression}
#' \item{\code{period}}{a \code{\link[regts]{period_range}} object or an
#' object that can be coerced to a \code{period_range}}
#' 
#' If neither \code{names} nor \code{pattern} have been specified,
#' then all endogenous or exogenous variables are set to the specified value.
#' }
#' @section Methods:
#' \itemize{
#' \item \code{set_endo_values}: Endogenous model variables
#'
#' \item \code{set_exo_values}: Exogenous model variables
#'
#' }
#'
#' @seealso \code{\link{change_data-methods}} and  \code{\link{set_data}}
#' @examples
#'
#' mdl <- islm_mdl(period = "2017Q1/2018Q3")
#'
#' # set the values of ms in 2017Q1 and 2017Q2
#' mdl$set_exo_values(c(205, 206), names = "ms", period = "2017Q1/2017Q2")
#' 
#' # set the values for y and yd to 1000 for  the full data period
#' mdl$set_endo_values(1000, pattern = "^yd?$")
NULL

#' \code{\link{DynMdl}} methods: changes the endogenous or exogenous
#' model data by applying a function.
#' @name change_data-methods
#' @aliases change_endo_data change_exo_data
#' @description
#' These methods of R6 class \code{\link{DynMdl}}
#' changes the endogenous or exogenous
#' model data by applying a function.
#'
#' @section Usage:
#' \preformatted{
#' mdl$change_endo_data(fun, names, pattern, period = mdl$get_data_period(), ...)
#'
#' mdl$change_exo_data(fun names, pattern, period = mdl$get_data_period(), ...)
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{fun}}{a function applied each model timeseries specified with 
#'  argument \code{names} or \code{pattern}}
#' \item{\code{names}}{a character vector with variable names}
#' \item{\code{pattern}}{a regular expression}
#' \item{\code{period}}{an \code{\link[regts]{period_range}} object or an
#' object that can be coerced to a \code{period_range}}
#' \item{\code{...}}{arguments passed to \code{fun}}
#' }
#' If neither \code{names} nor \code{pattern} have been specified,
#' then the function is applied to all endogenous or exogenous variables.
#' 
#' @section Methods:
#' \describe{
#' \item{\code{changes_endo_data}}{Changes the endogenous model variables}
#' \item{\code{change_exo_data}}{Changes the exogenous model variables}
#' }
#' @examples
#' mdl <- islm_mdl(period = "2017Q1/2017Q3")
#'
#' # increase y and yd with 10% for the full data period
#' mdl$change_endo_data(pattern = "^y.?$", fun = function(x) {x * 1.1})
#' print(mdl$get_endo_data())
#'
#' # increase ms in 2017Q1 and 2017Q2 with 10 and 20, resp.
#' mdl$change_exo_data(names = "ms", fun = function(x, dx) {x + dx},
#'                 dx = c(10, 20), period = "2017Q1/2017Q2")
#' print(mdl$get_exo_data())
#'
#' @seealso \code{\link{get_data-methods}}, \code{\link{set_data}} and
#' \code{\link{set_values-methods}}
#'
NULL


#' Writes the model to an RDS file
#' @name write_mdl
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}}
#' serializes the model object and writes it
#' to an RDS file. The model can be read back by function
#' \code{\link{read_mdl}}.
#' @section Arguments:
#'
#' \describe{
#' \item{\code{file}}{the name of the RDS file}
#' }
#' @examples
#' mdl <- islm_mdl("2017Q1/2019Q2")
#' mdl$write_mdl("islm_mdl.rds")
#' @seealso \code{\link{read_mdl}} 
NULL

#' \code{\link{DynMdl}} method: Returns a copy of this \code{DynMdl} object
#' @name copy
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}}
#' returns a deep copy of an \code{DynMdl} object
#' @section Usage:
#' \preformatted{
#' mdl$copy()
#'
#' }
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Details:
#' \code{mdl$copy()} is  equivalent to \code{mdl$clone(deep = TRUE)}
#'
#' @examples
#' mdl <- islm_mdl("2017Q1/2019Q2")
#' mdl2 <- mdl$copy()
NULL

#' \code{\link{DynMdl}} method: Sets labels for the model variables.
#' @name set_labels
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}} sets labels
#' for the model variables.
#' @section Usage:
#' \preformatted{
#' mdl$set_labels(labels)
#'
#' }
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{labels}}{a named character vector.
#' The names are the names of the model variables}
#' }
#' @examples
#' mdl <- islm_mdl()
#' mdl$set_labels(c(c = "Consumption", i = "investments"))
#' @seealso 
#' \code{\link{get_labels}}
NULL

#' \code{\link{DynMdl}} method: Returns the labels or LaTeX names 
#' of the model variables and parameters
#' @name get_labels/get_tex_names
#' @aliases get_labels get_tex_names
#'
#' @description
#' These methods of R6 class \code{\link{DynMdl}}
#' return the labels (long names) or LaTeX names of the model variables and 
#' parameters. The return value is a named character vector.
#' 
#' The labels and LaTeX names are defined in the mod file (consult the documentation
#' of Dynare, in Dynare labels are called 'long names'). Method \code{\link{set_labels}}
#' can be used to modify these labels. By default the labels are equal to the variable names.
#' @section Usage:
#' \preformatted{
#' mdl$get_labels()
#'
#' mdl$get_tex_names()
#' 
#' }
#' \code{mdl} is an \code{\link{DynMdl}} object
#' @section Methods:
#' \itemize{
#' \item \code{get_labels}: Returns the labels (long names), 
#' e.g. \code{"Disposable income"}
#' \item \code{get_tex_names}: Returns the LaTeX names (e.g. \code{"Y_d"})
#' }
#' @seealso
#' \code{\link{set_labels}}
NULL

#' \code{\link{DynMdl}} method: Calculates the residuals of the equations
#' @name residual_check
#' @description
#' This method of R6 class \code{\link{DynMdl}} calculates the 
#' residuals for the full model period and returns the 
#' result  as a \code{\link[regts]{regts}} timeseries object.
#'
#' @section Usage:
#' \preformatted{
#' mdl$residual_check(tol, include_fit_eqs = FALSE)
#'
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{tol}}{the tolerance parameter.
#' If specified, then the return value does not include columns for the equations
#' whose residuals are smaller than \code{tol}}
#' \item{\code{include_fit_eqs}}{a logical value (default \code{FALSE}).  
#' This argument is only used if \code{mdl} is a \code{\link{FitMdl}} object. 
#' If \code{TRUE}, then the fit equations are included in the residual check.}
#' }
#' @seealso \code{\link{static_residual_check}}
NULL

#' \code{\link{DynMdl}} method: Calculates the residuals of the equations
#' of the static model
#' @name static_residual_check
#' @description
#' This method of R6 class \code{\link{DynMdl}} calculates the 
#' residuals for the static version of the model. The result is a named numeric
#' vector, where the names are the equation numbers.
#' @section Usage:
#' \preformatted{
#' mdl$static_residual_check(tol, include_fit_eqs = FALSE)
#'
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{tol}}{the tolerance parameter. 
#' If specified, then return value does not include equations whose residuals 
#' are smaller than \code{tol}}
#'  \item{\code{include_fit_eqs}}{a logical value (default \code{FALSE}).  
#' This argument is only used if \code{mdl} is a \code{\link{FitMdl}} object. 
#' If \code{TRUE}, then the fit equations are included in the residual check.}
#' }
#' @seealso \code{\link{residual_check}}
NULL


#' \code{\link{DynMdl}} method: Solves the steady state.
#' @name solve_steady
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}} solves the steady state.
#' 
#' This function uses the static exogenous and endogenous variables
#' stored in the \code{DynMdl} object. The static endogenous variables
#' are used as an initial guess for solving the steady state.
#' After creating a \code{DynMdl} object, the static exogenous and endogenous
#' variables are initialized to the values specified in the initval block of 
#' the mod file, or to zero if they are not specified in the initval block.
#' The static variables can be modified with methods
#' \code{\link{set_static_exos}} and \code{\link{set_static_endos}}.
#' 
#' The function \code{\link{get_static_endos}} can be used to retrieve the
#' steady state solution.
#'
#' \code{solve_steady} does \emph{not} raise an error when the solve was
#' not successful. In that case a warning may be issued. 
#' Method \code{\link{get_solve_status}} can be used to check
#' whether the solve was successfully terminated or not.
#'
#' @section Usage:
#' \code{DynMdl} method:
#' \preformatted{
#' mdl$solve_steady(control, solver = c("umfpackr", "nleqslv"), ...)
#'
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{control}}{A named list of control parameters passed to function
#' \code{\link[umfpackr]{umf_solve_nl}} or \code{\link[nleqslv]{nleqslv}},
#' depending on argument \code{solver}}
#' \item{\code{solver}}{Specifies the solver employed to solve the model:
#' \code{umfpackr} (sparse linear algebra) or \code{nleqslv} (dense linear algebra).
#' For large model, the \code{umfpackr} solve can be much faster.}
#' \item{\code{...}}{Other arguments passed to the solver}
#' }
#' @seealso \code{\link{set_static_endos}}, \code{\link{set_static_exos}},
#' \code{\link{get_static_endos}}, \code{\link{get_static_exos}},
#' \code{\link{put_static_endos}} and \code{\link{get_solve_status}}
#' @examples
#' mdl <- islm_mdl(period = "2018Q1/2080Q1")
#' mdl$solve_steady(control = list(trace = 1))
#'
#' # print the solution
#' print(mdl$get_static_endos())
#' 
#' # update the model data with steady state values of endogenous variables
#' mdl$put_static_endos()
NULL

#' \code{\link{DynMdl}} method: Transfers the static endogenous
#' variables to the model data.
#' @name put_static_endos
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}} transfers the static endogenous
#' variables to the model data.
#' 
#'
#' @section Usage:
#' \code{DynMdl} method:
#' \preformatted{
#' mdl$put_static_endos(period = mdl$get_data_period())
#'
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{period}}{
#' A \code{\link[regts]{period_range}} object or an object that can be 
#' coerced to a \code{period_range}, specifying the period for which the 
#' endogenous model data will be updated with the static endogenous variables.}
#' }
#' @seealso \code{\link{solve_steady}}, \code{\link{set_static_endos}} 
#' and \code{\link{get_static_endos}}.
#' @examples
#' mdl <- islm_mdl(period = "2018Q1/2040Q3")
#' 
#' # transfer static endogenous variables for the full data period 
#' mdl$put_static_endos()
#' 
#' # now only for the lead period
#' mdl$put_static_endos(period = mdl$get_lead_period())
NULL

#' \code{\link{DynMdl}} method: Solves the model
#' @name solve
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}} solves
#' the model.
#' 
#' \code{solve_steady} does \emph{not} raise an error when the solve was
#' not successful. In that case a warning may be issued. 
#' Method \code{\link{get_solve_status}} can be used to check
#' whether the solve was successfully terminated or not.
#'
#' 
#' @section Usage:
#' \code{DynMdl} method:
#' \preformatted{
#'  md$solve(control = list(), force_stacked_time = FALSE,
#'           solver = c("umfpackr", "nleqslv"), 
#'           start = c("current", "previous"), ...)
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{control}}{A named list of control parameters passed to function
#' \code{\link[umfpackr]{umf_solve_nl}} or \code{\link[nleqslv]{nleqslv}},
#' depending on argument \code{solver}}
#' \item{\code{force_stacked_time}}{a logical. If \code{TRUE}, the the 
#' model is solved using the stacked time Newton method, also for 
#' purely backward looking models.}
#' \item{\code{solver}}{Specifies the solver employed to solve the model:
#' \code{umfpackr} (sparse linear algebra) or \code{nleqslv} (dense linear algebra).
#' For large model, the \code{umfpackr} solve can be much faster.}
#' \item{\code{start}}{Method used to initialize starting values when solving
#' the model backwards. For \code{"current"} (the default) the current values 
#' of the endogenous variables are used as starting values. For 
#' \code{"previous"} the solution of the previous period is used to create 
#' starting values (except for the first period when the model is solved). 
#' This argument is ignored if the model if solved with the stacked time Newton 
#' method}
#' \item{\code{...}}{Other arguments passed to the solver}
#' }
#' @seealso \code{\link{solve_steady}} and \code{\link{get_solve_status}}
#' @examples
#' mdl <- islm_mdl(period = "2018Q1/2023Q3")
#' mdl$solve(control = list(trace = TRUE))
NULL

#' \code{\link{DynMdl}} method: Returns a character vector with the model 
#' equations.
#'
#' @name get_equations
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}} returns a character vector 
#' with the model equations (excluding local equations). 
#' 
#' @section Usage:
#' \code{DynMdl} method:
#' \preformatted{
#'  md$get_equations(i = NULL)
#'  
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{i}}{A numeric vector with the indices of the non-local equations.
#' If not specified, then the function returns all equations}
#' }
#' @examples
#' mdl <- islm_mdl(period = "2018Q1/2023Q3")
#' 
#' # print the 4th equation nicely to the screen
#' cat(mdl$get_equations(4))
#' 
#' # print all equations
#' print(mdl$get_equations())
NULL

#' \code{\link{DynMdl}} methods: Returns the maximum lag or lead of the model
#'
#' @name get_max_lag/get_max_lead
#' @aliases get_max_lag get_max_lead
#'
#' @description
#' Methods \code{get_max_lag} and \code{get_max_lead} of R6 class 
#' \code{\link{DynMdl}} return the maximum lag and lead, respectively.
#'  the maximum a character vector 
#' 
#' @section Usage:
#' \code{DynMdl} methods:
#' \preformatted{
#'  mdl$get_max_lag()
#'  mdl$get_max_lead()
#'  
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
NULL

#' \code{\link{DynMdl}} method: Compute the eigenvalues of the linearized model 
#' around the steady state.
#' @name check
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}} computes the steady state,
#' constructs a linear model around the state steady and finally
#' computes the eigenvalues of the linearized model around the steady state. It 
#' also checks if the Blachard and  Kahn conditions are satisfied. 
#'
#' @section Usage:
#' \code{DynMdl} method:
#' \preformatted{
#' mdl$check()
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @examples
#' mdl <- islm_mdl()
#' mdl$check()
#' print(mdl$get_eigval())
#' @seealso \code{\link{solve_steady}} and \code{\link{get_eigval}}
NULL

#' \code{\link{DynMdl}} method: Return the eigenvalues computed with method
#' \code{check}
#' @name get_eigval
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}} returns the eigenvalues 
#' computed with method \code{\link{check}}, ordered with increasing absolute 
#' value
#' 
#' @section Usage:
#' \code{DynMdl} method:
#' \preformatted{
#' mdl$get_eigval()
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @seealso \code{\link{check}} 
NULL

#' \code{\link{DynMdl}} methods: set and get the static values of the
#' model variables
#' @name set/get_static_endos/exos
#' @aliases set_static_exos set_static_endos get_static_endos get_static_exos
#'          set_static_exo_values
#'
#' @description
#' 
#' \code{\link{set_static_exos}},   \code{\link{set_static_exo_values}}
#' and \code{\link{set_static_endos}} can be used to set one or 
#' more static values of the endogenous or exogenous model variables, 
#' respectively. The correspondig \code{get} methods can be used to retrieve 
#' them.
#' 
#' Each \code{\link{DynMdl}} object contains a set of static values
#' for the exogenous and endogenous model variables.
#' The static exogenous values are used to compute the steady state
#' with function methode \code{\link{solve_steady}}.
#' The static endogenous values are both input and output of 
#' \code{solve_steady}: they are used as an initial guess
#' for the steady state, and replaced by the steady 
#' state solution.
#' 
#' The static values are initialized to the values specified in the initval block of 
#' the mod file, or to zero if they are not specified in the initval block.
#' The static values can be modified with methods
#' 
#' @section Usage:
#' \code{DynMdl} method:
#' \preformatted{
#' mdl$set_static_endos(endos)
#' mdl$set_static_exos(exos)
#' mdl$set_static_exo_values(value, names, pattern)
#' mdl$get_static_endos()
#' mdl$get_static_endos()
#' mdl$get_static_endos()
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#' \describe{
#' \item{\code{endos}}{A named numerical vector with new static values of the
#' endogenous variables}
#' \item{\code{exos}}{A named numerical vector with new static values of the
#' exogenous variables}
#' \item{\code{value}}{a numeric vector of length 1}
#' \item{\code{names}}{a character vector with names of model variables}
#' \item{\code{pattern}}{a regular expression}
#' }
#' @examples
#' mdl <- islm_mdl()
#' mdl$set_static_endos(c(y = 1250))
#'
#' #  set static values of all exogenous variables starting with m 
#' # (for this model only "ms") to zero. 
#' mdl$set_static_exo_values(333, pattern = "^m")
#' 
#' print(mdl$get_static_endos())
#' @seealso \code{\link{solve_steady}}, \code{\link{check}}
NULL

#' \code{\link{DynMdl}} methods: Retrieve the names of model variables or
#' parameters
#' @name get_name-methods
#' @aliases get_endo_names get_exo_names get_par_names
#' @description
#' These methods of R6 class \code{\link{DynMdl}} 
#' return the names of the model variables or parameters
#'
#' If the \code{DynMdl} object is also a \code{\link{FitMdl}} object, then
#' \code{get_endo_names} and \code{get_exo_names} do not include the names of 
#' the auxiliary endogenous and exogenous variables used in the fit procedure.
#' Use \code{\link{get_instrument_names}} to obtain the names of the fit 
#' instruments.
#' 
#' @section Usage:
#' \preformatted{
#' mdl$get_endo_names(type = c("all", "lags", "leads")
#'
#' mdl$get_exo_names()
#'
#' mdl$get_par_names()
#'
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{type}}{a character describing the type of the endogenous variables:
#'  \code{"lags"} or \code{"leads"} for endogenous variables with lags or leads,
#' respectively. The default is \code{"all"} (all endogenous variables).}
#' }
#' @section Methods:
#' \itemize{
#' \item \code{get_endo_names}: Names of the endogenous model variables
#'
#' \item \code{get_exo_names}: Names of the endogenous model variables
#'
#' \item \code{get_par_names}: Names of the model parameters
#'
#' }
#'
#' @seealso \code{\link{get_instrument_names}} and \code{\link{get_sigma_names}}
NULL

#' \code{\link{DynMdl}} method: Sets the model parameters
#' @name set_param
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}}
#' sets the model parameters
#' @section Usage:
#' \preformatted{
#' mdl$set_param(p)
#'
#' }
#' \code{mdl} is an \code{\link{DynMdl}} object
#' @section Arguments:
#'
#' \describe{
#' \item{\code{p}}{a named numeric vector with parameter values.
#' The names are the names of the parameter}
#' }
#' @examples
#' mdl <- islm_mdl()
#' mdl$set_param(c(i0 = 101))
#' @seealso \code{\link{set_param_values}} and \code{\link{get_param}}
NULL


#' \code{\link{DynMdl}} method: Returns model parameters
#' @name get_param
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}}
#' returns model parameters
#' @section Usage:
#' \preformatted{
#' mdl$get_param(pattern, names)
#'
#' }
#' \code{mdl} is an \code{\link{DynMdl}} object
#' @section Arguments:
#'
#' \describe{
#' \item{\code{pattern}}{a regular expression specifying parameter names}
#' \item{\code{names}}{a character vector with parameter names}
#' }
#' @examples
#' mdl <- islm_mdl()
#'
#' # print all model parameters
#' print(mdl$get_param())
#'
#' # print parameters c0, c1, c2 and c3
#' print(mdl$get_param(pattern = "^c.*"))
#' @seealso \code{\link{set_param}}, \code{\link{set_param_values}} 
#' and \code{\link{get_vars_pars}}
NULL


#' \code{\link{DynMdl}} methods: Return the Jacobian for the static or 
#' dynamic model
#' @name get_jacob
#' @aliases get_static_jacob get_back_jacob
#' @description
#' These methods of R6 class \code{\link{DynMdl}} 
#' can be used to retrieve the Jacobian for the static or dynamic model.
#' 
#' The methods return a \code{matrix} object which can be further 
#' analysed using standard linear algebra functions.
#' This is particularly useful when method \code{\link{solve}} complains
#' about (nearly) singular Jacobians.
#' For example, an SVD decomposition using function 
#' \code{\link[base]{svd}} can be used to identify linearly
#' dependent rows or columns.
#'  
#' @section Usage:
#' \preformatted{
#' mdl$get_static_jacob(sparse = FALSE)
#' 
#' mdl$get_jacob(sparse = FALSE)
#'
#' mdl$get_back_jacob(period, sparse = FALSE)
#'
#' }
#' \code{mdl} is an \code{\link{DynMdl}} object
#' 
#' @section Arguments:
#'
#' \describe{
#' \item{\code{sparse}}{a logical. If \code{TRUE}, then the matrix is
#' returned as a sparse matrix}
#' \item{\code{period}}{an \code{\link[regts]{period}} object or an
#' object that can be coerced to a \code{period}}
#' }
#' @section Methods:
#' \itemize{
#' \item \code{get_jacob}: The Jacobian for the dynamic model
#' This is the Jacobian used
#' when solving the model with the stacked-time Newton method.
#' \item \code{get_static_jacob}: The Jacobian for the static 
#' version of the model. This Jacobian  is used when solving the steady state.
#' \item \code{get_back_jacob}: The Jacobian at a specific period
#' for backward looking models, treating the lags as exogenous.
#' This Jacobian is used to solve backward looking models.
#' }
#' @examples
#' mdl <- islm_mdl("2018Q1/2019Q4")
#' print(mdl$get_static_jacob())
#' print(mdl$get_jacob())
#' 
#' \dontrun{
#' # print the Jacobian for a backward looking model at period 2018Q3
#' print(backwards_mdl$get_back_jacob("2018Q3"))
#' }
NULL

#' \code{\link{DynMdl}} method: Returns the solve status of the last model solve.
#' @name get_solve_status
#' @md
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}} returns the status
#' of the last model solve as a text string. If the last model solve
#' was succesfull, it returns the string \code{"OK"}.
#'
#' @section Usage:
#' \code{DynMdl} method:
#' \preformatted{
#' mdl$get_solve_status()
#'
#' }
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Details:
#'
#' The possible return values are:
#'  * \code{NA_character_} (method solve has not yet been called)
#'  * \code{"OK"}
#'  * \code{"ERROR"} (an error has occurred, check the warnings).
#'
#' @seealso \code{\link{solve}} and \code{\link{solve_steady}}
#' @examples
#' \dontrun{
#' mdl <- islm_mdl(period = "2017Q1/2018Q4")
#' mdl$set_endo_values(NA, names = "y", period = "2017Q1")
#' mdl$solve()
#' if (mdl$get_solve_status() != "OK") {
#'    stop("Error solving the model. Check the warnings!")
#' }
#' }
NULL

#' \code{\link{DynMdl}} methods: Sets the values of the model parameters
#' @name set_param_values
#' @description
#' This method of R6 class \code{\link{DynMdl}} 
#' can be used to set the values of the model data
#'
#' @section Usage:
#' \preformatted{
#'
#' mdl$set_param_values(value, names, pattern)
#'
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{value}}{a numeric vector of length 1}
#' \item{\code{names}}{a character vector with parameter names}
#' \item{\code{pattern}}{a regular expression}
#' }
#' 
#' If neither \code{names} nor \code{pattern} have been specified,
#' then all model parameters are set to the specified value.
#'
#' @seealso \code{\link{set_param}} and \code{\link{get_param}} 
#' @examples
#'
#' mdl <- islm_mdl()
#' 
#' # set parameters i4 and i5 to zero
#' mdl$set_param_values(0, names = c("i4", "c5"))
#'
#' # set the values all parameters starting with "i" 
#' # (i0, i1, i2, i3, i4 and i5) to 0
#' mdl$set_param_values(0, pattern = "^i")
#' 
#' # set all parameters to zero
#' mdl$set_param_values(0)
NULL

#' \code{\link{DynMdl}} methods: Returns a list of all model variables and 
#' parameters
#' @name get_vars_pars
#' @description
#' This method of R6 class \code{\link{DynMdl}} 
#' returns a list of all model variables and parameters. This makes it easy
#' to directly evaluate expressions involving both model variables
#' and parameters.
#'
#' If the \code{DynMdl} object is also a \code{\link{FitMdl}} object, then
#' the variables do not include the the auxiliary endogenous and
#' exogenous variables used in the fit procedure.
#'
#' @section Usage:
#' \preformatted{
#'
#' mdl$get_vars_pars(period = mdl$get_data_period(), trend = TRUE)
#'
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
##' \item{\code{period}}{an \code{\link[regts]{period_range}} object or an
#' object that can be coerced to a \code{period_range}}
#' #' \item{\code{trend}}{a logical. This argument is used for model with
#' trend variables. If \code{TRUE} (the default), then the
#' endogenous variables are multiplied with their trends (called deflators
#' in the mod file)}
#' }
#' 
#'
#' @seealso \code{\link{get_data-methods}}, \code{\link{get_param}}, 
#' \code{\link{get_fit}}, \code{\link{get_fit_instruments}} and 
#' \code{\link{get_lagrange}}
#' @examples
#' mdl <- islm_mdl(period = "2017Q1/2017Q3")
#' 
#' # create a list of all parameters and model variables for 
#' # period 2017q1/2017q2 
#' vars_pars <- mdl$get_vars_pars(period = "2017Q1/2017Q2")
#' print(vars_pars)
#' 
#' # evaluate an expression within list vars_pars
#' with(vars_pars, print(t0 + t1 * y))
#'
#' # copy all parameters to the global environment, and evaluate
#' # an expresions in the global environment:
#' list2env(vars_pars, .GlobalEnv)
#' print(md - ms)
#' 
NULL

