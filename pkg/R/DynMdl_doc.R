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
#' \item{\code{data_period}}{\code{\link[regts]{regperiod_range}}
#' object, or an object that can be coerced to 
#' \code{\link[regts]{regperiod_range}}}
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
#' \item{\code{period}}{\code{\link[regts]{regperiod_range}}
#' object, or an object that can be coerced to 
#' \code{\link[regts]{regperiod_range}}}
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
#' \item{\code{period}}{an \code{\link[regts]{regperiod_range}} object or an
#' object that can be coerced to a \code{regperiod_range}}
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
#'              update_mode = c("update", "updval")
#' 
#' }
#'
#' \code{mdl} is a \code{\link{DynMdl}} object
#' 
#' @section Arguments:
#'
#' \describe{
#' \item{\code{data}}{a \code{\link[stats]{ts}} or \code{\link[regts]{regts}}
#'  object}
#' \item{\code{names}}{a character vector with variable names. Defaults to the
#' column names of \code{data}. If \code{data} does not have column names,
#' then argument \code{names} is mandatory}
#' \item{\code{update_mode}}{the update mode. See details.}
#' }
#'
#' @section Details:
#'
#' The argument \code{update_mode} controls how the timeseries are updated:
#' \describe{
#' \item{\code{"update"}}{Model variables are updated with the 
#' timeseries in \code{data}}
#' \item{\code{"updval"}}{Model variables are updated with the non \code{NA}
#' values in \code{data}}
#' }
#'
NULL

#' \code{\link{DynMdl}} methods: Sets the values of the model data
#' @name set_values
#' @description
#' This method of R6 class \code{\link{DynMdl}} 
#' can be used to set the values of the model dataents
#' (both endogenous and exogenous)
#'
#' @section Usage:
#' \preformatted{
#' mdl$set_values(value, names, pattern, period = mdl$get_data_period())
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
#' \item{\code{period}}{a \code{\link[regts]{regperiod_range}} object or an
#' object that can be coerced to a \code{regperiod_range}}
#' }
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
