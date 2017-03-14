#' \code{\link{DynMod}} method: initializes the model data.
#' @name init_data
#'
#' @description
#' This method of R6 class \code{\link{DynMod}} initializes the
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
#' \code{mdl} is an \code{DynMdl} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{data_period}}{\code{\link[regts]{regperiod_range}}
#' object, or an object that can be coerced to 
#' \code{\link[regts]{regperiod_range}}}
#' }
NULL

#' \code{\link{DynMod}} method: sets the model period
#' @name set_period
#'
#' @description
#' This method of R6 class \code{\link{DynMod}} sets the model period.
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
#' \code{mdl} is an \code{DynMod} object
#'
#' @section Arguments:
#'
#' \describe{
#' \item{\code{period}}{\code{\link[regts]{regperiod_range}}
#' object, or an object that can be coerced to 
#' \code{\link[regts]{regperiod_range}}}
#' }
#'
#' @examples
#' mdl <- islm_mod()
#' mdl$set_period("2017Q2/2021Q3")
NULL

#' \code{\link{DynMod}} method: returns the model period
#' @name get_period
#'
#' @description
#' This method of R6 class \code{\link{DynMod}} returns the model period.
#'
#' @section Usage:
#' \preformatted{
#' mdl$get_period()
#'
#' }
#'
#' \code{mdl} is an \code{DynMod} object
#' @seealso
#' \code{\link{set_period}}
NULL

#' \code{\link{DynMod}} method: returns the model data period
#' @name get_data_period
#'
#' @description
#' This method of R6 class \code{\link{DynMod}} returns the model data period.
#'
#' @section Usage:
#' \preformatted{
#' mdl$get_data_period()
#'
#' }
#'
#' \code{mdl} is an \code{DynMod} object
#' @seealso
#' \code{\link{set_period}}
NULL
