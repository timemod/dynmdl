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
#' mdl$init_data(data_period)
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
#' \code{\link[regts]{period_range}}}
#' }
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

#' \code{\link{DynMdl}} method: returns the model period
#' @name get_period
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}} returns the model period.
#'
#' @section Usage:
#' \preformatted{
#' mdl$get_period()
#'
#' }
#'
#' \code{mdl} is a \code{DynMdl} object
#' @seealso
#' \code{\link{set_period}}
NULL

#' \code{\link{DynMdl}} method: returns the model data period
#' @name get_data_period
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}} returns the model data period.
#'
#' @section Usage:
#' \preformatted{
#' mdl$get_data_period()
#'
#' }
#'
#' \code{mdl} is a \code{DynMdl} object
#' @seealso
#' \code{\link{set_period}}
NULL

#' \code{\link{DynMdl}} methods: Retrieve timeseries from the model data
#' @name get_data-methods
#' @aliases get_endo_data get_exo_data
#' @description
#' These methods of R6 class \code{\link{DynMdl}} 
#' can be used to retrieve timeseries from the model data.
#'
#' @section Usage:
#' \preformatted{
#' mdl$get_endo_data(pattern, names, period = mdl$get_data_period())
#'
#' mdl$get_exo_data(pattern, names, period = mdl$get_data_period())
#'
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{names}}{a character vector with variable names}
#' \item{\code{pattern}}{a regular expression}
#' \item{\code{period}}{an \code{\link[regts]{period_range}} object or an
#' object that can be coerced to a \code{period_range}}
#' }
#' @section Methods:
#' \itemize{
#' \item \code{get_endo_data}: Endogenous model variables
#'
#' \item \code{get_exo_data}: Exogenous model variables
#' }
#'
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
#'              upd_mode = c("update", "updval"), fun)
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
#' }
#' @section Methods:
#' \itemize{
#' \item \code{set_endo_values}: Endogenous model variables
#'
#' \item \code{set_exo_values}: Exogenous model variables
#'
#' }
#'
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

#' \code{\link{DynMdl}} method: Returns the labels of the model variables.
#' @name get_labels
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}}
#' returns the labels of the model variables.
#' @section Usage:
#' \preformatted{
#' mdl$get_labels()
#'
#' }
#' \code{mdl} is an \code{\link{DynMdl}} object
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
#' mdl$residual_check(tol = 0)
#'
#' }
#'
#' \code{mdl} is an \code{\link{DynMdl}} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{tol}}{the tolerance parameter. 
#' The return value does not include columns for the euqations
#' whose residuals are smaller than \code{tol}}}
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
#' @section Usage:
#' \code{DynMdl} method:
#' \preformatted{
#' mdl$solve_steady(control, solver = c("umfpackr", "nleqslv"))
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
#' }
#' @seealso \code{\link{set_static_endos}}, \code{\link{set_static_exos}},
#' \code{\link{get_static_endos}}, \code{\link{get_static_exos}}
#' and \code{\link{put_static_endos}}
#' @examples
#' mdl <- islm_mdl()
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
#' coerced to a \code{period_range}}, specifying the period for which the 
#' endogenous model data will be updated with the computed steady state values.
#' }
#' @seealso \code{\link{solve_steady}}, \code{\link{set_static_endsos}} 
#' and \code{\link{get_static_endos}}.
#' @examples
#' mdl <- islm_mdl()
#' 
#' # transfer static endogenous variables for the full data period 
#' mdl$put_static_endos()
#' 
#' # now only for the lead period
#' mdl$put_static_endos(period = mdl$get_lead_period()))
NULL

#' \code{\link{DynMdl}} method: Solves the model
#' @name solve
#'
#' @description
#' This method of R6 class \code{\link{DynMdl}} solves
#' the model.
#' 
#' @section Usage:
#' \code{DynMdl} method:
#' \preformatted{
#'  md$solve(control = list(), force_stacked_time = FALSE,
#'             solver = c("umfpackr", "nleqslv"))
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
#' }
#' @seealso \code{\link{solve_steady}}
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
#' around thesteady state.
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
#'
#' @description
#' 
#' \code{\link{set_static_exos}} and \code{\link{set_static_endos}}
#' can be used to set one or more static values of the endogenous
#' or exogenous model variables, respectively. The correspondig
#' \code{get} method can be used to retrieve them.
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
#' }
#' @examples
#' mdl <- islm_mdl(period = "2018Q1/2023Q3")
#' mdl$set_static_endos(c(y = 1250))
#' @seealso \code{\link{solve_steady}}and \code{\link{check}}
NULL


