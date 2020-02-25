#' \code{\link{DynMdl}} method: transfers data from a timeseries
#' object to the fit targets.
#' @name set_fit
#' @description
#' The method \code{set_fit} of R6 class \code{\link{DynMdl}}
#' transfers data from a timeseries object to the fit targets.
#' 
#' @section Usage:
#' \preformatted{
#'
#' mdl$set_fit(data, names = colnames(data), 
#'             name_err = c("stop", "warn", "silent"))
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object implementing the fit method.
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{data}}{a \code{\link[stats]{ts}} or \code{\link[regts]{regts}}
#'  timeseries object}
#' \item{\code{names}}{a character vector with variable names, with the
#' same length as the number of timeseries in \code{data}. Defaults to the
#' column names of \code{data}. If \code{data} does not have column names,
#' then argument \code{names} is mandatory}
#' \item{\code{name_err}}{this option specifies the action that should be taken 
#' when a variable name is not an endogenous model variable.
#' For \code{"stop"} (the default), the execution of this function is stopped.
#' For \code{"warn"} and \code{"silent"} the timeseries that are no endogenous 
#' model variables are skipped. \code{"warn"} does however give a warning.}
#' }

#' @section Details:
#'
#' Method \code{set_fit} transfers data from a timeseries object to the
#' fit targets. It works similarly as method  \code{\link{set_data}}.
#' If \code{data} is a multivariate timeseries object, then
#' each column is used to update the fit target with the same
#' name as the column name. If \code{data} does not have column names,
#' or if the column names do not correspond to the model variable names,
#' then argument \code{names} should be specified.
#' 
#' If \code{data} contains  \code{NA} values, then the variable is not a fit 
#' target for the corresponding periods, which implies that the variable
#' will be calculated according to the equations of the model.
#' 
#' @section Warning:
#' Method \code{\link{init_data}} removes all fit targets.
#'
#' @examples
#'
#' mdl <- islm_mdl(period = "2016Q1/2017Q3", fit = TRUE)
#'
#' # create a regts with fit targets
#' y <- regts(c(1250, 1255, 1260), start = "2016Q1")
#' t <- regts(c(250, 255), start = "2016Q1")
#' fit_targets <- cbind(y, t)
#' 
#' # register the fit targets in the DynMdl object
#' mdl$set_fit(fit_targets)
#' 
#' print(mdl$get_fit())
#
#' @seealso \code{\link{get_fit}}, \code{\link{set_fit_steady}}, 
#' and \code{\link{clear_fit}}
NULL

#' \code{\link{DynMdl}} method: Sets the values of the fit targets
#' @name set_fit_values
#' @description
#' This method of R6 class \code{\link{DynMdl}} 
#' can be used to set the values of the fit targets. See the documentation
#' of function \code{\link{set_fit}} for more information about fit targets.
#'
#' @section Usage:
#' \preformatted{
#'
#' mdl$set_fit_values(value, names, pattern, period = mdl$get_data_period())
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object implementing the fit method.
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
#' @examples
#'
#' mdl <- islm_mdl(period = "2017Q1/2018Q3", fit = TRUE)
#'
#' # set the values of ms in 2017Q1 and 2017Q2
#' mdl$set_fit_values(c(190, 195), names = "i", period = "2017Q1/2017Q2")
#'
#' print(mdl$get_fit())
#' @seealso \code{\link{set_fit}} and \code{\link{clear_fit}}
NULL

#' \code{\link{DynMdl}} methods: Retrieve the names of the fit instruments
#' or sigma parameters used in the fit method.
#' @name get_instrument_names/get_sigma_names
#' @aliases get_instrument_names get_sigma_names
#' @description
#' These methods of R6 class \code{\link{DynMdl}} 
#' return the names of the fit instruments or sigma parameters
#' used in the fit method.
#'
#' @section Usage:
#' \preformatted{
#' mdl$get_instrument_names()
#'
#' mdl$get_sigma_names()
#'
#' }
#' \code{mdl} is a \code{\link{DynMdl}} object implementing the fit method.
#' @examples
#'
#' mdl <- islm_mdl(period = "2017Q1/2018Q3", fit = TRUE)
#' print(mdl$get_instrument_names())
#' print(mdl$get_sigma_names())
#'
#' @seealso \code{\link{get_fit_instruments}}
NULL

#' \code{\link{DynMdl}} methods: get variables used in the fit method.
#' @name get_fit-methods
#' @aliases get_fit get_fit_instruments get_lagrange

#' @description
#' These methods of R6 class \code{DynMdl} can be used
#' to retrieve the variables used in the fit method:
#' the fit targets, fit instruments or Lagrange multipliers.
#' \cr\cr
#' By default, function `get_fit` only returns fit targets with 
#' any non-`NA` value for the period range with any non-`NA` value.
#' Thus columns with only `NA` values and leading and trailing rows with 
#' only `NA` values are removed.
#' If all values are `NA`, then the function returns `NULL`.
#' If argument `period` has been specified, then the function always returns 
#' a  timeseries with the specified period range.
#' If `names` or `pattern` has been specified, it always returns a timeseries
#' with the specified variables, except if all values are `NA`.
#' \cr\cr
#' For method \code{get_fit} there are corresponding \code{\link{set_fit}} and
#' \code{\link{set_fit_values}} methods. There are currently no special
#' methods to set or change the fit instruments and Lagrange multipliers.
#' However, since they are internally implemented as endogenous variables
#' you can use methods \code{\link{set_data}}, \code{\link{set_endo_values}},
#' and \code{\link{change_endo_data}} to change the fit instruments
#' or Lagrange multipliers.
#' 
#' @section Usage:
#' \preformatted{
#' 
#' mdl$get_fit(pattern, names, period) # fit targets
#' 
#' mdl$get_fit_instruments(pattern, names, period = mdl$get_period())
#' 
#' mdl$get_lagrange(names, period = mdl$get_period())
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object implementing the fit method.
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{pattern}}{a regular expression}
#' \item{\code{names}}{a character vector with variable names}
#' \item{\code{period}}{an \code{\link[regts]{period_range}} object or an
#' object that can be coerced to a \code{period_range}}
#' }
#'
#' @examples
#'
#' mdl <- islm_mdl(period = "2016Q1/2017Q3", fit = TRUE)
#'
#' # create a regts with fit targets
#' y <- regts(c(1250, 1255, 1260), start = "2016Q1")
#' t <- regts(c(250, 255), start = "2016Q1")
#' fit_targets <- cbind(y, t)
#' 
#' # register the fit targets in the DynMdl object
#' mdl$set_fit(fit_targets)
#' 
#' mdl$solve()
#' 
#' print(mdl$get_fit())
#' print(mdl$get_fit_instruments())
#' print(mdl$get_lagrange())
#' 
#' @seealso \code{\link{get_data-methods}}, \code{\link{set_fit}},
#' \code{\link{set_fit_values}} and \code{\link{clear_fit}}.
NULL

#' \code{\link{DynMdl}} method: get fit targets used in the steady state 
#' calculation
#' @name get_fit_steady

#' @description
#' This methods of R6 class \code{DynMdl} returns the static fit targets,
#' i.e. the fit targets used when the steady state is solved.
#' \cr\cr
#' By default, function `get_fit` only returns fit targets with 
#' any non-`NA` value.
#' If all values are `NA`, then the function returns `NULL`.
#' If `names` or `pattern` has been specified, it always returns a timeseries
#' with the specified variables.
#' \cr\cr
#' For method \code{get_fit_syteady} the is a corresponding \code{\link{set_fit}_steady}
#' method. There are currently no special
#' methods to set or change the fit instruments and Lagrange multipliers.
#' However, since they are internally implemented as endogenous variables
#' you can use methods \code{\link{set_static_data}}  to change the static 
#' fit instruments or Lagrange multipliers.
#' 
#' @section Usage:
#' \preformatted{
#' 
#' mdl$get_fit_steady(pattern, names) # fit targets
#'
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object implementing the fit method.
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{pattern}}{a regular expression}
#' \item{\code{names}}{a character vector with variable names}
#' }
#'
#' @examples
#'
#' mdl <- islm_mdl(fit = TRUE)
#'
#' fit_targets <- c(y = 1250, t = 255)
#' 
#' # register the fit targets in the DynMdl object
#' mdl$set_fit_steady(fit_targets)
#' 
#' mdl$solve_steady()
#' 
#' print(mdl$get_fit_steady())
#' 
#' @seealso \code{\link{set/get_static_endos/exos}}, 
#' \code{\link{set_fit_steady}},
#' and \code{\link{clear_fit}}.
NULL


#' \code{\link{DynMdl}} method: removes fit targets and turns off fit
#' instruments.
#' @name clear_fit

#' @description
#' This method of R6 class \code{DynMdl} removes all fit targets, sets 
#' the sigma-parameters of the fit-instruments to \code{-1} and sets
#' all Lagrange multipliers to 0, for both the dynamic and static version
#' of the model.
#' 
#' By removing the fit targets (which is equivalent to setting all fit targets to
#' \code{NA}), all endogenous variables are calculated according to the equations
#' of the model, while the fit instruments stay fixed at their current value, 
#' and are efficitively exogenous (even though they are still implemented
#' as endogenous variables).
#' 
#' If the model had been solved before \code{clear_fit} was called, then the
#' model is still solved after \code{clear_fit} has been called.
#' 
#' @section Usage:
#' \preformatted{
#' 
#' mdl$clear_fit()
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object implementing the fit method.
#''
#' @examples
#'
#' mdl <- islm_mdl(period = "2016Q1/2017Q3", fit = TRUE)
#'
#' # create a regts with fit targets
#' y <- regts(c(1250, 1255, 1260), start = "2016Q1")
#' t <- regts(c(250, 255), start = "2016Q1")
#' fit_targets <- cbind(y, t)
#' 
#' # register the fit targets in the DynMdl object
#' mdl$set_fit(fit_targets)
#' 
#' mdl$solve()
#' mdl$clear_fit()
#' 
#' # the next statements gives 0 iterations.
#' mdl$solve()
#' @seealso \code{\link{get_data-methods}}, \code{\link{set_fit}},
#' \code{\link{set_fit_steady}}, \code{\link{set_fit_values}} and 
#' \code{\link{clear_fit}}.
NULL

#' \code{\link{DynMdl}} methods: Retrieve the 
#' sigma parameters used in the fit method.
#' @name get_sigmas
#' @description
#' This method of R6 class \code{\link{DynMdl}} 
#' return all sigma parameters for the fit method larger than or 
#' equal to zero. The fit instruments for which the corresponding
#' sigma-parameter is \eqn{\ge 0} are used as instruments in the 
#' fit method. Instruments which a sigma-parameter smaller than 0 are 
#' fixed at their original value. 
#' 
#' The sigma-parameters can be modified with methods
#' \code{\link{set_param}} and \code{\link{set_param_values}}.
#'
#' @section Usage:
#' \preformatted{
#' mdl$get_sigmas()
#' 
#' \code{mdl} is a \code{\link{DynMdl}} object implementing the fit method.
#' }
#' @examples
#'
#' mdl <- islm_mdl(period = "2016Q1/2017Q3", fit = TRUE)
#' mdl$get_sigmas()
#' 
#' # disable ui as fit instrument by setting sigma_ui to -1:
#' mdl$set_param(c(sigma_ui = -1))
#' mdl$get_sigmas()
NULL


#' \code{\link{DynMdl}} method: set fit targets for the steady state
#' @name set_fit_steady
#' @description
#' This method  of R6 class \code{\link{DynMdl}} sets the static
#' fit targets, i.e. the fit targets used in the steady state calculation.
#' 
#' @section Usage:
#' \preformatted{
#'
#' mdl$set_fit_steady(data, names = names(data), 
#' name_err = c("stop", "warn", "silent"))
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object implementing the fit method.
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{data}}{a named numeric vector with the fit target values. The
#' names coresspond to the names of the endogenous model variables.}
#' \item{\code{names}}{a character vector with variable names, with the
#' same length as the vector  \code{data}. Defaults to the
#' cnames of \code{data}. If \code{data} does not have  names,
#' then argument \code{names} is mandatory}
#' \item{\code{name_err}}{this option specifies the action that should be taken 
#' when a variable name is not an endogenous model variable.
#' For \code{"stop"} (the default), the execution of this function is stopped.
#' For \code{"warn"} and \code{"silent"} the timeseries that are no endogenous 
#' model variables are skipped. \code{"warn"} does however give a warning.}
#' }

#' @section Details:
#'
#' If \code{data} contains  \code{NA} values, then the corresponding model 
#' variable is not a fit target.
#' 
#' @section Warning:
#' Method \code{\link{init_data}} removes all fit targets.
#'
#' @examples
#'
#' mdl <- islm_mdl(fit = TRUE)
#'
#' # create a regts with fit targets
#' y <- regts(c(1250, 1255, 1260), start = "2016Q1")
#' t <- regts(c(250, 255), start = "2016Q1")
#' fit_targets <- c(y = 1250, t = 250)
#' 
#' # register the static fit targets in the DynMdl object
#' mdl$set_fit_steady(fit_targets)
#' 
#' print(mdl$get_fit_steady())
#' 
#' mdl$solve_steady()
#' 
#' print(mdl$get_static_endos())
#
#' @seealso \code{\link{get_fit_steady}} and \code{\link{clear_fit}}
NULL
