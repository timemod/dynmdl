#' \code{\link{FitMdl}} method: transfers data from a timeseries
#' object to the fit targets.
#' @name set_fit
#' @aliases get_fit

#' @description
#' The method \code{set_fit} of R6 class \code{\link{FitMdl}}
#' transfers data from a timeseries object to the fit targets.
#' 
#' Method \code{get_fit} can be used to retrieve the fit targets.
#' 
#' @section Usage:
#' \preformatted{
#'
#' mdl$set_fit(data, names = colnames(data), upd_mode = c("upd", "updval"))
#' 
#' mdl$get_fit()
#' 
#' }
#'
#' \code{mdl} is an \code{\link{FitMdl}} object
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
#' \item{\code{upd_mode}}{the update mode, a character string specifying
#' how the timeseries are updated: \code{"upd"} (standard update, default) or
#' \code{"updval"} (update only with valid numbers). NOTE: currently
#' \code{"updval"} is not yet supported. See details.}
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
#' By default, all values in \code{data} are used to update the corresponding
#' model variable. Sometimes it is desirable to skip the \code{NA} values
#' in \code{data}. This can be achieved by selecting \code{"updval"} for argument
#' \code{upd_mode}. Other non finite numbers (\code{NaN}, \code{Inf}, and
#' \code{-Inf}) are also disregarded for this update mode.
#' NOTE: currently, update mode \code{"updval"} has not yet been implemented.
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
#' @seealso \code{\link{clear_fit}} and \code{\link{set_data}}.
NULL

#' \code{\link{FitMdl}} method: Sets the values of the fit targets
#' @name set_fit_values
#' @description
#' This method of R6 class \code{\link{DynMdl}} 
#' can be used to set the values of the fit targets.
#'
#' @section Usage:
#' \preformatted{
#'
#' mdl$set_fit_values(value, names, pattern, period = mdl$get_data_period())
#'
#' }
#'
#' \code{mdl} is an \code{\link{FitMdl}} object
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
NULL

#' \code{\link{FitMdl}} method: deletes all fit targets
#' @name clear_fit
#' @description
#' This methods of R6 class \code{\link{FitMdl}}
#' deletes all fit targets for the fit procedure.
#'
#' @section Usage:
#' \preformatted{
#' mdl$clear_fit()
#' }
#' \code{mdl} is an \code{\link{FitMdl}} object
#' @seealso \code{\link{set_fit}} and \code{\link{get_fit}}
NULL


#' \code{\link{FitMdl}} methods: Retrieve the names of the fit instruments
#' or sigma parameters used in the fit procedure.
#' @name get_instrument_names/get_sigma_names
#' @aliases get_instrument_names get_sigma_names
#' @description
#' These methods of R6 class \code{\link{FitMdl}} 
#' return the names of the fit instruments or sigma parameters
#' used in the fit procedure.
#'
#' @section Usage:
#' \preformatted{
#' mdl$get_instrument_names()
#'
#' mdl$get_sigma_names()
#'
#' }
#' \code{mdl} is an \code{\link{FitMdl}} object
#' @examples
#'
#' mdl <- islm_mdl(period = "2017Q1/2018Q3", fit = TRUE)
#' print(mdl$get_instrument_names())
#' print(mdl$get_sigma_names())
#'
#' @seealso \code{\link{get_fit_instruments}} and \code{\link{get_sigmas}}
NULL
