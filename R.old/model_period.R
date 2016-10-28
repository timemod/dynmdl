#' Get or set the solve period of model object
#'
#' @param mdl the model
#' @param value a \code{\link[regts]{regperiod_range}} representing the solve period

#' @export
setGeneric("model_period", function(mdl) standardGeneric("model_period"))

#' @rdname model_period
#' @export
setGeneric("model_period<-", function(mdl, value) standardGeneric("model_period<-"))

#' @describeIn model_period Returns the solve period
#' @return a \code{\link[regts]{regperiod_range}} representing the solve period
#' @export
setMethod("model_period", "SimModel",
    function(mdl) {
        mdl@model_period
    }
)

#' @describeIn model_period Sets the solve period of a  \code{\link{SimModel}} object
#'
#' @importFrom regts start_period
#' @importFrom regts end_period
#' @importFrom regts as.regperiod_range
#' @importFrom regts lensub
#' @importFrom regts regts
#' @export
setMethod("model_period<-", "SimModel",
    function(mdl, value) {
        period <- as.regperiod_range(value)
        mdl@model_period <-  period
        mdl@endo_period <- regperiod_range(
                        start_period(period) - mdl@max_endo_lag,
                        end_period(period) + mdl@max_endo_lead)
        mdl@exo_period <- regperiod_range(
            start_period(period) - mdl@max_exo_lag,
            end_period(period) + mdl@max_exo_lead)

        nper <- lensub(mdl@endo_period)
        endo_mat <- matrix(rep(mdl@endos, each = nper), nrow = nper)
        mdl@endo_data <- regts(endo_mat, start = start_period(mdl@endo_period),
                               names = names(mdl@endos))
        if (mdl@exo_count > 0) {
            nper <- lensub(mdl@exo_period)
            exo_mat <- matrix(rep(mdl@exos, each = nper), nrow = nper)
            mdl@exo_data <- regts(exo_mat, start = start_period(mdl@exo_period),
                                  names = names(mdl@exos))
        }
        return (invisible(mdl))
    }
)
