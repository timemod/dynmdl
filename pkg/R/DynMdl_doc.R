#' \code{\link{DynMdl}} method: initializes the model data.
#' @name init_data
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}} sets the model data period and 
#' initializes the model variables with static values
#' of the exogenous and endogenous model variables.
#'
#' If the model period has not yet been specified (in function 
#' \code{\link{dyn_mdl}} or method \code{\link{set_period}}), then 
#' this method also sets the model period, the standard period
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
#' \code{\link[regts]{period_range}}. If not specified, then the data period
#' is based on the period range of argument \code{data} (if this argument 
#' has been specified) and  the model period.}
#' \item{\code{data}}{a \code{\link[stats]{ts}} or \code{\link[regts]{regts}}
#' object with values for endogogenous and exogenous model variables, 
#' including fit instruments and Lagrange multipliers used in the fit method.
#' If \code{data} has labels, then these labels are used to update the model 
#' labels. If the model has trends, then the timeseries in \code{data} should 
#' include the trends.}
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
#' @aliases get_period get_data_period get_lag_period get_lead_period get_base_period
#'
#' @description
#' These methods of R6 class \code{\link{DynMdl}} return the model period,
#' data period, lag period, lead period, or base period respectively.
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
#' The \emph{base_period} is used when the model has trend variables.
#' All trend variables will be equal to 1 at the base period.
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
#' mdl$get_base_period()
#' 
#' }
#'
#' \code{mdl} is a \code{DynMdl} object
#' 
#' @section Methods:
#' \itemize{
#' \item \code{get_period}: Returns the model period
#' \item \code{get_data_period}: Returns the data period
#' \item \code{get_lag_period}: Returns the lag period, or \code{NULL} if the
#' model has no lags
#' \item \code{get_lead_period}: Returns the lead period or \code{NULL} if the
#' model has no leads
#' \item \code{get_base_period}: Returns the base period.
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
#' @aliases get_data get_endo_data get_exo_data get_trend_data, get_all_endo_data
#' get_all_exo_data
#' @description
#' These methods of R6 class \code{\link{DynMdl}} 
#' can be used to retrieve timeseries from the model data.
#'
#' If the \code{DynMdl} object is also a \code{\link{DynMdl}} object, then
#' \code{get_data} also returns the fit instruments. In contrast,
#' \code{get_endo_data} does not return these fit instruments.
#' Both \code{get_data} and \code{get_endo_data} do not return
#' the Lagrange multipliers used in the fit method. Use method  
#' \code{\link{get_lagrange}} to obtain these Lagrange multipliers. 
#' \code{\link{get_all_endo_data}} returns all endogenous variables, 
#' fit instruments and Lagrange multipliers, for the complete data period.
#' This function is useful to save the complete solution of a model that
#' be used as initial values for the endogenopus variables in another
#' model.
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
#' 
#' mdl$get_all_endo_data()
#' 
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object
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
#' variables, trends variables, and fit instruments for \code{\link{DynMdl}}
#' objects
#' \item \code{get_endo_data}: Endogenous model variables, excluding
#' fit instruments.
#' \item \code{get_exo_data}: Exogenous model variables
#' \item \code{get_trend_data}: Trend variables (variables declared with
#' \code{trend_var} in the mod file).
#' \item \code{get_all_endo_data}: All endogenous variables, including
#' fit instruments and lagrange multipliers.
#' }
#'
#' @seealso \code{\link{get_fit-methods}}, \code{\link{get_fit}}, 
#' \code{\link{get_fit_instruments}}, \code{\link{get_lagrange}} and 
#' \code{\link{get_vars_pars}}.
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
#' (both endogenous and exogenous). If the model implements the fit method,
#' then \code{set_data} can also be used to modify fit instruments and the  
#' Lagrange multipliers.
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
#' the labels of the corresponding model variables. 
#' If the model has trends, then the timeseries in \code{data} should 
#' include the trends.}
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
#' can be used to set the values of the model data.
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
#' \code{mdl} is a \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{value}}{a numeric vector of length 1 or with the same length
#' as the length of the range of \code{period}. 
#' If the model has trends, then the values should 
#' include the trends.}
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
#' @aliases change_data change_endo_data change_exo_data
#' @description
#' These methods of R6 class \code{\link{DynMdl}} changes endogenous and/or 
#' exogenous model data by applying a function.
#' If the model has trends, then the change is applied to the trended
#' model variables.
#'
#' @section Usage:
#' \preformatted{
#' mdl$change_endo_data(fun, names, pattern, period = mdl$get_data_period(), ...)
#'
#' mdl$change_exo_data(fun names, pattern, period = mdl$get_data_period(), ...)
#' 
#' mdl$change_data(fun, names, pattern, period = mdl$get_data_period(), ...)
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{fun}}{a function applied each model variable specified with 
#'  argument \code{names} or \code{pattern}. See Details.}
#' \item{\code{names}}{a character vector with variable names}
#' \item{\code{pattern}}{a regular expression}
#' \item{\code{period}}{an \code{\link[regts]{period_range}} object or an
#' object that can be coerced to a \code{period_range}: the period 
#' for which the function will be applied}
#' \item{\code{...}}{arguments passed to \code{fun}}
#' }
#' If neither \code{names} nor \code{pattern} have been specified,
#' then the function is applied to all endogenous or exogenous variables.
#' 
#' @section Details:
#' 
#' The function specified with argument `fun` should be a function
#' with at least one argument, for example `fun = function(x) {x + 0.1}`.
#' The first argument (named `x` in the example) will be the model
#' variable. The function is evaluated for each model variable separately. 
#' The values of the model variables for period range `period` are passed as a 
#' normal numeric vector (not a timeseries) to the first argument.
#' 
#' An example may help to clarify this. Consider the following statement
#'  ```
#'  mdl$change_endo_data(fun = myfun, names = c("c", "y"), 
#'                       period = "2017q1/2017q2"),
#'  ```
#'  
#'  where `mdl` is a `DynMdl` object and `myfun` some function whose details
#'  are not relevant here. Method  \code{change_endo_data} evaluates this as
#'  ```
#'  data <- mdl$get_endo_data(names = c("c", "y"), period = "2017q1/2017q2")
#'  data[, "c"] <- myfun(as.numeric(data[, "c"]))
#'  data[, "y"] <- myfun(as.numeric(data[, "y"]))
#'  mdl$set_data(data)
#'  ```
#' 
#'  The function result must be a vector (or timeseries) of length one or with
#'  the same length as the number of periods in the period range \code{period}.
#' 
#' 
#' @section Methods:
#' \describe{
#' \item{\code{changes_endo_data}}{Changes endogenous model variables}
#' \item{\code{change_exo_data}}{Changes exogenous model variables}
#' \item{\code{change_data}}{Changes endogenous and/or exogenous model variables,
#' including fit instruments and Lagrange multipliers used in the fit method 
#' (if present).}
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
#' returns a deep copy of a \code{DynMdl} object
#' @section Usage:
#' \preformatted{
#' mdl$copy()
#'
#' }
#' \code{mdl} is a \code{\link{DynMdl}} object
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
#' \code{mdl} is a \code{\link{DynMdl}} object
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
#' \code{mdl} is a \code{\link{DynMdl}} object
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
#' \code{mdl} is a \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{tol}}{the tolerance parameter.
#' If specified, then the return value does not include columns for the equations
#' whose residuals are smaller than \code{tol}}
#'  \item{\code{include_all_eqs}}{a logical value (default \code{FALSE}).  
#' If \code{TRUE}, then the all equations, including fit equations and 
#' auxiliary equations (if present),  are included in the residual check.
#' The auxiliary equations are extra equations created when the model
#' has lags or leads greater than 1 and if \code{dynmdl} was called
#' with \code{max_laglead_1 = TRUE}.}
#' \item{\code{include_fit_eqs}}{a logical value (default \code{FALSE}).  
#' If \code{TRUE}, then fit equations (if present) are included in the residual 
#' check. Ignored if \code{include_all_eqs} is \code{TRUE}.}
#' \item{\code{debug_eqs}}{Debug equations (default \code{FALSE}). Only used
#' for the internal calculation mode (\code{calc == "internal"},
#' see \code{\link{dyn_mdl}}). If
#' \code{TRUE} then numerical problems in evaluation
#' of mathematical functions or operators such a \code{log} are reported.}
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
#' \code{mdl} is a \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{tol}}{the tolerance parameter. 
#' If specified, then return value does not include equations whose residuals 
#' are smaller than \code{tol}.}
#'  \item{\code{include_all_eqs}}{a logical value (default \code{FALSE}).  
#' If \code{TRUE}, then the all equations, including fit equations and 
#' auxiliary equations (if present),  are included in the residual check.
#' The auxiliary equations are extra equations created when the model
#' has lags or leads greater than 1 and if \code{dynmdl} was called
#' with \code{max_laglead_1 = TRUE}.}
#' \item{\code{include_fit_eqs}}{a logical value (default \code{FALSE}).  
#' If \code{TRUE}, then fit equations (if present) are included in the residual 
#' check. Ignored if \code{include_all_eqs} is \code{TRUE}.}
#' \item{\code{debug_eqs}}{Debug equations (default \code{FALSE}). Only used
#' for the internal calculation mode (\code{calc == "internal"},
#' see \code{\link{dyn_mdl}}). If
#' \code{TRUE} then numerical problems in evaluation
#' of mathematical functions or operators such a \code{log} are reported.}
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
#' mdl$solve_steady(control = list(), solver = c("umfpackr", "nleqslv"), 
#'                 debug_eqs = FALSE, ...)
#'
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{control}}{A named list of control parameters passed to function
#' \code{\link[umfpackr]{umf_solve_nl}} or \code{\link[nleqslv]{nleqslv}},
#' depending on argument \code{solver}. If control parameter \code{trace} has 
#' not been specified, then that parameter is set to \code{TRUE}.}
#' \item{\code{solver}}{Specifies the solver employed to solve the model:
#' \code{umfpackr} (sparse linear algebra) or \code{nleqslv} (dense linear algebra).
#' For large model, the \code{umfpackr} solve can be much faster.}
#' \item{\code{debug_eqs}}{Debug equations (default \code{FALSE}). Only used
#' for the internal calculation mode (\code{calc == "internal"},
#' see \code{\link{dyn_mdl}}). If
#' \code{TRUE} then numerical problems in evaluation
#' of mathematical functions or operators such a \code{log} are reported.}
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
#' \code{mdl} is a \code{\link{DynMdl}} object
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
#' \code{solve} does \emph{not} raise an error when the solve was
#' not successful. In that case a warning may be issued. 
#' Method \code{\link{get_solve_status}} can be used to check
#' whether the solve was successfully terminated or not.
#'
#' 
#' @section Usage:
#' \code{DynMdl} method:
#' \preformatted{
#'  md$solve(control = list(), mode, solver = c("umfpackr", "nleqslv"), 
#'           start = c("current", "previous"), debug_eqs = FALSE,
#'           homotopy = FALSE, silent = FALSE,  ...)
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{control}}{A named list of control parameters passed to function
#' \code{\link[umfpackr]{umf_solve_nl}} or \code{\link[nleqslv]{nleqslv}},
#' depending on argument \code{solver}. If control parameter \code{trace} has 
#' not been specified, then that parameter is set to \code{TRUE} when the model
#' is solved using the stacked time method and  \code{FALSE} when the model
#' is solved using the backwards method (see also argument \code{mode}).}
#' \item{\code{mode}}{A character specifying the solve mode. Possible values
#' are \code{"stacked_time"} and \code{"backwards"}. By default, models
#' with leads are solved with the stacked time method and models without leads
#' are solved backwards.}
#' \item{\code{solver}}{Specifies the solver employed to solve the model:
#' \code{"umfpackr"} (sparse linear algebra) or \code{"nleqslv"} (dense linear algebra).
#' For large models, the \code{umfpackr} solve can be much faster.}
#' \item{\code{start}}{Method used to initialize starting values when solving
#' the model backwards. For \code{"current"} (the default) the current values 
#' of the endogenous variables are used as starting values. For 
#' \code{"previous"} the solution of the previous period is used to create 
#' starting values (except for the first period when the model is solved). 
#' This argument is ignored if the model if solved with the stacked time Newton 
#' method}
#' \item{\code{debug_eqs}}{Debug equations (default \code{FALSE}). Only used
#' for the internal calculation mode (\code{calc == "internal"},
#' see \code{\link{dyn_mdl}}). If
#' \code{TRUE} then numerical problems in evaluation
#' of mathematical functions or operators such a \code{log} are reported.}
#' \item{\code{homotopy}}{A logical. If \code{TRUE} (the default), then the 
#' homotopy approach is used when directly solving the model fails.
#' Consult the documentation of Dynare for more information about the homotopy aproach.}
#' \item{\code{silent}}{A logical. If \code{TRUE} then all output is suppressed.
#' In that case control parameters \code{silent} and \code{trace} 
#' (see argument \code{control}) are ignored.} 
#' \item{\code{...}}{Other arguments passed to the solver function (\code{\link{umf_solve_nl}}
#' when the solver is`"umfpackr"`), Useful arguments for `umf_solve_nl` are 
#' `global` (select a global strategy) and
#' `umf_control` (this option can be used to specify the UMFPACK ordering
#' method, see the example below). See the documentation of 
#' \code{\link[umfpackr]{umf_solve_nl}} for more details.}
#' }
#' @seealso \code{\link{solve_steady}} and \code{\link{get_solve_status}}
#' @examples
#' islm <- islm_mdl(period = "2018Q1/2023Q3")
#' islm$set_exo_values(260, period = "2018q1", names = "g")
#' islm$solve(control = list(trace = TRUE))
#' 
#' # use the METIS ordering method of UMFACK. This method can handle
#' # larger matrices than the standard AMD ordering, and is therefore
#' # suitable for larghe models. 
#' # WARNING: The METIS ordering is not available on Windows.
#' \dontrun{
#' islm$solve(control = list(trace = TRUE), 
#'            umf_control = list(ordering = "METIS"))
#' }
NULL

#' \code{\link{DynMdl}} method: Returns a character vector with the model 
#' equations.
#'
#' @name get_equations
#' @aliases get_original_equations
#'
#' @description
#' These method of R6 class \code{\link{DynMdl}} returns a character vector 
#' with the model equations (excluding local equations). \code{get_equations}
#' returned the parsed equations, where trends (if present) have been removed.
#' \code{get_original_equations} returns the equations as defined in the mod 
#' file. 
#' @section Usage:
#' \code{DynMdl} method:
#' \preformatted{
#'  md$get_equations(i)
#'  mdl$get_original_equations(i)
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object
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

#' \code{\link{DynMdl}} methods: Returns the maximum lag or lead
#'
#' @name get_max_lag/get_max_lead
#' @aliases get_max_lag get_max_lead
#'
#' @description
#' Methods \code{get_max_lag} and \code{get_max_lead} of R6 class 
#' \code{\link{DynMdl}} return the maximum lag and lead of the original model, 
#' respectively. These are the maximum lag and lead in the equations
#' specified in the mod file. The actual  maximum lag or lead will be different 
#' if \code{max_laglead_1 == TRUE}  and if there are endogenous lags or 
#' leads greater than 1.
#' @section Usage:
#' \code{DynMdl} methods:
#' \preformatted{
#'  mdl$get_max_lag()
#'  mdl$get_max_lead()
#'  
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object
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
#' \code{mdl} is a \code{\link{DynMdl}} object
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
#' \code{mdl} is a \code{\link{DynMdl}} object
#'
#' @seealso \code{\link{check}} 
NULL

#' \code{\link{DynMdl}} methods: set and get the static values of the
#' model variables
#' @name set/get_static_endos/exos
#' @aliases set_static_exos set_static_exo_values, set_static_endos 
#'          set_static_data 
#'          get_static_endos get_static_exos
#'          set_static_exo_values get_static_data
#'
#' @description
#' 
#' \code{set_static_exos}, \code{set_static_exo_values}, 
#' \code{set_static_endos} and  \code{set_static_data} can be used to set one or 
#' more static values of the endogenous and/or exogenous model variables.
#' The corresponding \code{get} methods can be used to retrieve them.
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
#' mdl$set_static_endos(endos, names = names(endos), name_err = c("stop", "warn", "silent"))
#' mdl$set_static_exos(exos, names = names(endos), name_err = c("stop", "warn", "silent"))
#' mdl$set_static_exo_values(value, names, pattern)
#' mdl$set_static_data(data, names = names(data), name_err = c("stop", "warn", "silent"))
#' mdl$get_static_endos(pattern, names)
#' mdl$get_static_endos(pattern, names)
#' mdl$get_static_data(pattern, names)
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object
#'
#' @section Arguments:
#' \describe{
#' \item{\code{endos}}{A (named) numerical vector with new static values of the
#' endogenous variables. If the vector has no names, than argument
#' \code{names} must be specified.}
#' \item{\code{exos}}{A (named) numerical vector with new static values of the
#' exogenous variables. If the vector has no names, than argument
#' \code{names} must be specified.}
#'  \item{\code{data}}{A (named) numerical vector with new static values of 
#'  both endogenous and exogenous variables.  If the vector has no names, than argument
#' \code{names} must be specified.}
#' \item{\code{value}}{a numeric vector of length 1}
#' \item{\code{names}}{a character vector with names of model variables}
#' \item{\code{pattern}}{a regular expression}
#' \item{\code{name_err}}{this option specifies the action that should be taken 
#' when a variable name is not a model variable.
#' For \code{"stop"} (the default), the execution of this function is stopped.
#' For \code{"warn"} and \code{"silent"} the names that are no model
#' variables are skipped. \code{"warn"} does however give a warning.}
#' }
#' @section Methods:
#' \itemize{
#' \item \code{set_static_endos}: Set the static values of one or more 
#' endogenous variables (excluding fit instruments for \code{\link{DynMdl}} objects).
#' \item \code{set_static_exos}: Set the static values of one or more 
#' exogenous variables.
#' \item \code{set_static_exo_values}: Give more than one exogenous variable 
#' the same static value.
#' \item \code{set_static_data}: Set the static values of one or more 
#' endogenous or exogenous variable  
#' (excluding fit instruments for \code{\link{DynMdl}} objects).
#' \item \code{get_static_endos}: Returns the static values of one or more 
#' endogenous variables. For \code{\link{DynMdl}} objects the static values
#' of the fit instruments are not included (they are always zero). 
#' \item \code{get_static_exos}: Returns the static values of one or more 
#' exogenous variables.
#' \item \code{get_static_data}: Returns the static values of the model 
#' variables  (excluding fit instruments for \code{\link{DynMdl}} objects).
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
#' If the \code{DynMdl} object is also a \code{\link{DynMdl}} object, then
#' \code{get_endo_names} and \code{get_exo_names} do not include the names of 
#' the auxiliary endogenous and exogenous variables used in the fit method.
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
#' \code{mdl} is a \code{\link{DynMdl}} object
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
#' mdl$set_param(p, name_err = c("stop", "warn", "silent"))
#'
#' }
#' \code{mdl} is a \code{\link{DynMdl}} object
#' @section Arguments:
#'
#' \describe{
#' \item{\code{p}}{a named numeric vector with parameter values.
#' The names are the names of the parameters}
#' \item{\code{name_err}}{this option specifies the action that should be taken 
#' when a variable name is not a model variable.
#' For \code{"stop"} (the default), the execution of this function is stopped.
#' For \code{"warn"} and \code{"silent"} the names imeseries that are no model
#' parameters are skipped. \code{"warn"} does however give a warning.}
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
#' \code{mdl} is a \code{\link{DynMdl}} object
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
#' \code{mdl} is a \code{\link{DynMdl}} object
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
#' \code{mdl} is a \code{\link{DynMdl}} object
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
#' \code{mdl} is a \code{\link{DynMdl}} object
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
#' If the \code{DynMdl} object is also a \code{\link{DynMdl}} object, then
#' the variables do not include the the auxiliary endogenous and
#' exogenous variables used in the fit method.
#'
#' @section Usage:
#' \preformatted{
#'
#' mdl$get_vars_pars(period = mdl$get_data_period(), trend = TRUE)
#'
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object
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

#' Writes the model data to a Dynare initval file
#' @name write_initval_file
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}}
#' writes all endogous and exogenous model variables
#' to a so called "initval file" that can be read by Dynare.
#' An initval_file contains the paths of all model variables.
#' @section Arguments:
#'
#' \describe{
#' \item{\code{file}}{the name of the initval file}
#' }
#' @examples
#' mdl <- islm_mdl("2017Q1/2019Q2")
#' 
#' # write initval file as matlab file
#' mdl$write_initval_file("dynare_input/islm_initval.xlsx")
#' 
#' # write initval file in xlsx format
#' mdl$write_initval_file("dynare_input/islm_initval.xlsx")
NULL

#' \code{\link{DynMdl}} method: Solves the steady state with Dynare
#' @name solve_steady_dynare
#' 
#' @description
#' Solve the steady state and calculate the eigenvalues 
#' with Dynare using Matlab or Octave.
#' 
#' @section Usage:
#' \code{DynMdl} method:
#' \preformatted{
#' mdl$solve_steady_dynare(scratch_dir = tempfile(), dynare_path = NULL,
#'                         model_options = list(), 
#'                         solve_options = list(tolf = 1e-8),
#'                         use_octave = Sys.which("matlab") == "",
#'                         exit_matlab = FALSE)
#' }
#' 
#' \code{mdl} is a \code{\link{DynMdl}} object
#' 
#' @section Arguments:
#' \describe{
#' \item{\code{scratch_dir}}{Directory where the Matlablab and Dynare scripts are 
#' created.  By default this is a temporary directory that is automatically
#' deleted when the R session terminates.}
#' \item{\code{dynare_path}}{Character string specifying the name of the 
#' directory of the Dynare installation. On Linux it is usually not necessary 
#' to the specify this argument. On Windows it is necessary to specify the path 
#' of the Dynare installation. In you are running R in the  CPB 
#' environment the path to Dynare is set automatically.}
#' \item{\code{model_options}}{Options passed to the \code{model} command of
#' Dynare. This should be a named list, which names corresponding to the Dynare
#' options. Specify a \code{NULL} value if the option has no value.
#' Consult the documentation of  Dynare for a list of available options.
#' Example: \code{model_options = list(block = NULL, mfs = 2)}}
#' \item{\code{solve_options}}{Options passed to the 
#' \code{steady} command of Dynare. This should be a named list, which names 
#' corresponding to the Dynare options. Specify a \code{NULL} value if the 
#' option has no value. Consult the documentation of  Dynare for a list of 
#' available options.
#' Example: \code{steady_options = list(tolf = 1e-7, no_homotopy = NULL)}.
#' The default is \code{list(tolf = 1e-8)}}
#' \item{\code{use_octave}}{A logical. If \code{TRUE}, then
#' Dynare is envoked with Octave, otherwise Matlab is used. By default 
#' Matlab is used if available.}
#' \item{\code{exit_matlab}}{A logical specifying if Matlab
#' should immediately  exit when the calcultions have finished 
#' Matlab writes the output to a separate console. If \code{exit_matlab} is 
#' \code{FALSE} (the default), then the R job waits until the user has closed 
#' this console, or entered \code{exit} in the console. Otherwise the console 
#' is automatically closed at the end of the calculation and all output is lost.
#' This argument is ignored if Dynare is run with Octave. Octave does not 
#' open a seperate console: all output appears in the same console used by R.}
#' }
#' 
#' @section Value:
#'  The eigenvalues of the steady state.
#' @importFrom tools file_path_sans_ext
#' @examples
#' \dontrun{
#' islm <- islm_mdl()
#' islm$solve_steady_dynare(solve_options = list(tolf = 1e-8))
#' }
NULL

#' \code{\link{DynMdl}} method: Solves the model with Dynare
#' @name solve_dynare
#' 
#' @description
#' Solve the model with Dynare using Matlab or Octave.
#' 
#' @section Usage:
#' \code{DynMdl} method:
#' \preformatted{
#' mdl$solve_dynare(scratch_dir = tempfile(), 
#'                  dynarere_path = NULL, model_options = list(), 
#'                  solve_options = list(tolf = 1e-8, tolx = 1e-8)),
#'                  use_octave = Sys.which("matlab") == "",
#'                  exit_matlab = FALSE) 
#' }
#' 
#' \code{mdl} is a \code{\link{DynMdl}} object
#' 
#' @section Arguments:
#' \describe{
#' \item{\code{scratch_dir}}{Directory where the Matlablab and Dynare scripts are 
#' created.  By default this is a temporary directory that is automatically
#' deleted when the R session terminates.}
#' \item{\code{dynare_path}}{Character string specifying the name of the 
#' directory of the Dynare installation. On Linux it is usually not necessary 
#' to the specify this argument. On Windows it is necessary to specify the path 
#' of the Dynare installation. In you are running R in the CPB 
#' environment the path to Dynare is set automatically.}
#' \item{\code{model_options}}{Options passed to the \code{model} command of
#' Dynare. This should be a named list, which names corresponding to the Dynare
#' options. Specify a \code{NULL} value if the option has no value.
#' Consult the documentation of  Dynare for a list of available options.
#' Example: \code{model_options = list(block = NULL, mfs = 2)}}
#' \item{\code{solve_options}}{Options passed to the 
#' \code{perfect_foresight_solver} command of
#' Dynare. This should be a named list, which names corresponding to the Dynare
#' options. Specify a \code{NULL} value if the option has no value.
#' Consult the documentation of  Dynare for a list of available options.
#' Example: \code{steady_options = list(tolf = 1e-7, no_homotopy = NULL)}.
#' The default options are list(tolf = 1e-8, tolx = 1e-8)}
#' #' \item{\code{use_octave}}{A logical. If \code{TRUE}, then
#' Dynare is envoked with Octave, otherwise Matlab is used. By default 
#' Matlab is used if available.}
#'  \item{\code{exit_matlab}}{A logical specifying if Matlab
#' should immediately  exit when the calcultions have finished 
#' Matlab writes the output to a separate console. If \code{exit_matlab} is 
#' \code{FALSE} (the default), then the R job waits until the user has closed 
#' this console, or entered \code{exit} in the console. Otherwise the console 
#' is automatically closed at the end of the calculation and all output is lost.
#' This argument is ignored if Dynare is run with Octave. Octave does not 
#' open a seperate console: all output appears in the same console used by R.}
#' }
#' @importFrom tools file_path_sans_ext
#' @examples
#' \dontrun{
#'  islm <- islm_mdl(period = "2018Q1/2023Q3")
#'  islm$set_exo_values(260, period = "2018q1", names = "g")
#'  islm$solve_dynare()
#' }
NULL


#' \code{\link{DynMdl}} method: Returns technical details about the model.
#' @name get_mdldef
#' 
#' @description
#' 
#' This function returns a list with various components containing technical
#' details of the model, such as the names of the variables,
#' the lead-lag incidence matrix, etc.
#' 
#' @section Usage:
#' \code{DynMdl} method:
#' \preformatted{
#' mdl$sget_mdldef()
#' }
#' 
#' \code{mdl} is a \code{\link{DynMdl}} object
#' 
NULL

