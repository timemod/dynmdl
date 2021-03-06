#' Run a mod file Dynare with Matlab or Octave.
#' 
#' This function runs a mod file with Dynare using either Matlab or Octave.
#' The input files for Dynare and Octave/Matlab are generated automatically.
#' The command \code{octave} or \code{matlab} should be in the search path.
#' @param mod_file The name of a Dynare mod file. For models with trends,
#' this can also be a fit mod file created with function \code{dyn_mdl}
#' when argument \code{fit_mod_file} was specified. However, for model
#' with trends the fit mod file is not a correct Dynare mod file, because
#' the fit equations are already detrended while the original equations
#' still contain trends.
#' @param period A \code{\link[regts]{period_range}} object or object that
#' can be coerced to a \code{period_range}. This argument must be specified
#' when the perfect foresight solver is called.
#' @param data a \code{\link[stats]{ts}} or \code{\link[regts]{regts}}
#' object with values for endogogenous and exogenous model variables used in
#' the perfect foresight solver. If the model has trends, then the timeseries 
#' in \code{data} should include the trends.
#' @param steady A logical, indicating whether the steady state should be 
#' calculated (default is \code{TRUE}). 
#' @param check A logical (default `TRUE`), indicating whether the eigenvalues
#' should also be calculated.
#' @param perfect_foresight A logical, indicating wether the perfect foresight
#' solver should be called.  The default is \code{TRUE} if argument 
#' \code{period} or \code{data} have been specified and \code{FALSE} otherwise.
#' @param scratch_dir Directory where the Matlablab and Dynare scripts are 
#' created.  By default this is a temporary directory that is automatically
#' deleted when the R session terminates.
#' @param dynare_path Character string specifying the name of the 
#' directory of the Dynare installation. On Linux it is usually not necessary 
#' to the specify this argument. On Windows it is necessary to specify the path 
#' of the Dynare installation. In you are running R in the  CPB 
#' environment the path to Dynare is set automatically.
#' @param steady_options Options passed to the \code{steady} command of
#' Dynare. This should be a named list, which names corresponding to the Dynare
#' options. Specify a \code{NULL} value if the option has no value.
#' Consult the documentation of  Dynare for a list of available options.
#' Example: \code{steady_options = list(tolf = 1e-7, nocheck = NULL)}
#' @param perfect_foresight_solver_options Options passed to the 
#' \code{perfect_foresight_solver} command of
#' Dynare. This should be a named list, which names corresponding to the Dynare
#' options. Specify a \code{NULL} value if the option has no value.
#' Consult the documentation of  Dynare for a list of available options.
#' Example: \code{steady_options = list(tolf = 1e-7, no_homotopy = NULL)}.
#' @param initval_type A character specifying the type of initval file used
#' in the Matlab/Octave job: \code{"m"} for a Matlab file and \code{"xlsx"}
#' for an xlsx-file. 
#' @param use_octave A logical. If \code{TRUE}, then
#' Dynare is envoked with Octave, otherwise Matlab is used. By default 
#' Matlab is used if available.
#' @param exit_matlab A logical specifying if Matlab
#' should immediately  exit when the calcultions have finished 
#' Matlab writes the output to a separate console. If \code{exit_matlab} is 
#' \code{FALSE} (the default), then the R job waits until the user has closed 
#' this console, or entered \code{exit} in the console. Otherwise the console 
#' is automatically closed at the end of the calculation and all output is lost.
#' This argument is ignored if Dynare is run with Octave. Octave does not 
#' open a seperate console: all output appears in the same console used by R.
#' @return A list with the following components
#' \item{steady_endos}{(only if \code{steady == TRUE}): a steady state 
#' endogenous variables} 
#' \item{eigval}{(only if \code{check == TRUE}): the eigenvalues of  the steady 
#' state} 
#' \item{endo_data}{(only if \code{perfect_foresight_solver == TRUE}): the 
#' endogenous variables for the solution of the perfect foresight solver}
#' @importFrom tools file_path_sans_ext
#' @examples
#' \dontrun{
#' data <- regts(matrix(280, nrow = 1, ncol = 1), names = "g", period = "2017Q1")
#'
#' result <- run_dynare("mod/islm.mod", period = "2017q1/2019q3", data = data,
#'                       steady_options = list(tolf = 1e-8),
#'                       perfect_foresight_solver_options = list(tolf = 1e-8, 
#'                                                               tolx = 1e-8,
#'                                                          no_homotopy = NULL))
#'
#' }
#' @export
run_dynare <- function(mod_file, period, data, steady = TRUE, check = TRUE,
                       perfect_foresight = !missing(period) || !missing(data),
                       scratch_dir = tempfile(), dynare_path = NULL, 
                       steady_options,
                       perfect_foresight_solver_options,
                       initval_type = c("m", "xlsx"),
                       use_octave = Sys.which("matlab") == "",
                       exit_matlab = FALSE) {
  
  if (!steady && !perfect_foresight) {
    warning("run_dynare has nothing to do ...")
    return(NULL)
  }
  
  model_name <- file_path_sans_ext(basename(mod_file))
  #
  # create scratch directory
  #
  if (dir.exists(scratch_dir)) {
    if (unlink(scratch_dir, recursive = TRUE, force = TRUE)  == 1) {
      stop(sprintf("Not possible to delete directory %s.", scratch_dir))
    }
  }
  dir.create(scratch_dir)
  
  return(run_dynare_internal(model_name, mod_file, period = period, data = data, 
                             steady = steady, check = check,
                             perfect_foresight = perfect_foresight,
                             scratch_dir = scratch_dir, 
                             dynare_path = dynare_path,
                             steady_options = steady_options,
                             perfect_foresight_solver_options = 
                                      perfect_foresight_solver_options,
                             use_octave = use_octave, 
                             exit_matlab = exit_matlab))
}