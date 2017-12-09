#' Returns an example ISLM model
#'
#' This function returns an example ISLM model, If argument \code{period} has
#' been specified, then this function also initializes the model data
#' with the steady state values.
#' @param period the model period for the ISLM model
#' @param fit a logical indicating whether the dynamical fit procedure
#' should be used
#' @return a \code{\link{DynMdl}} object or a \code{\link{FitMdl}} 
#' object is argument \code{fit} is \code{TRUE}
#' @examples
#' mdl <- islm_mdl("2017Q1/2019Q4")
#' @export
islm_mdl <- function(period, fit = FALSE) {
  
  mod_file <- tempfile(fileext = ".mod")
  if (fit) {
    mdl_name <- "islm_fit.mod"
  } else {
    mdl_name <- "islm.mod"
  }
  mdl_file <- system.file("models", mdl_name, package = "dynmdl")
  file.copy(mdl_file, mod_file, overwrite = TRUE)
  mdl <- dyn_mdl(mod_file, period = period)
  unlink(mod_file)
  
  mdl$set_labels(c(i = "investment", c = "consumption", md = "money demand",
                   t = "tax", r = "interest rate", y = "income", 
                   yd = "disposable income",  g = "government spending",
                   ms = "money supply"))
  
  mdl$solve_steady(control = list(trace = FALSE))
  if (!missing(period)) {
    mdl$put_static_endos()
  }
  return(mdl)
}
