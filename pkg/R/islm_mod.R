#' Returns an example ISLM model
#'
#' This function returns an example ISLM model, If argument \code{period} has
#' been specified, then this function also initializes the model data
#' with the steady state values.
#' @param period the model period for the ISLM model
#' @return a \code{\link{DynMod}} object
#' @examples
#' mdl <- islm_mod("2017Q1/2019Q4")
#' @export
islm_mod  <- function(period = NULL) {
    mod_file <- tempfile(fileext = ".mod")
    copy_example_mod("islm", mod_file)
    mdl <- create_mod(mod_file)
    unlink(mod_file)

    mdl$solve_steady(control = list(trace = FALSE))

    if (!is.null(period)) {
        period <- as.regperiod_range(period)
        mdl$set_period(period)
    }
    return(mdl)
}
