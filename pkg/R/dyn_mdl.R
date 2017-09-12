#' Creates a \code{\link{DynMdl}} or  \code{\link{FitMdl}} object from a mod file
#'
#' Creates a \code{\link{DynMdl}} object from a mod file. If the mod file
#' contains a fit block, then this function returns a \code{\link{FitMdl}} 
#' object, which is an extension of a \code{DynMdl} object.
#'
#' @param mod_file the name of the model file (including extension .mod)
#' @param period a \code{\link[regts]{period_range}} object
#' @param data the model data as a  \code{\link[regts]{regts}} object with column
#' names
#' @param bytecode If \code{TRUE}, then the functions used to calculate the
#' residuals and Jacobian are byte compiled
#' @param  use_dll if \code{TRUE}, then the  functions used to calculate the
#' residuals and Jacobian are converted to C code that is subsequently
#' converted to a dynamically linked library.
#' @param fit_mod_file the name of the generated fit mod file. If not specified,
#' then the fit mod file is destroyed after the model has been parsed.
#' @param debug If \code{TRUE}, then some print statements
#' are executed.
#' @param dll_dir the directory where the dynamically linked library is stored.
#' Primarily used for testing.
#' Only used if argument \code{use_dll} is \code{TRUE}.
#' @return an \code{DynMdl} object or, if the mod file contains a
#' fit block, a \code{\link{FitMdl}} object.
#' @export
#' @importFrom Rcpp sourceCpp
#' @importFrom tools file_path_sans_ext
dyn_mdl <- function(mod_file, period, data, bytecode = FALSE, use_dll = FALSE,
                       fit_mod_file, debug = FALSE, dll_dir) {
  
  if (!file.exists(mod_file)) {
    stop(paste("ERROR: Could not open file:", mod_file))
  }
  
  if (use_dll) {
    if (missing(dll_dir)) {
      dll_dir <- tempfile(pattern = "dynmdl_dll_")
    } else if (dir.exists(dll_dir)) {
      unlink(dll_dir, recursive = TRUE)
    }
    dir.create(dll_dir)
    if (.Platform$OS.type == "windows")  {
      # on Windows, tempdir creates a filename with 
      # backslashes. This should be replaced by a forward
      # slash
      dll_dir <- gsub("\\\\", .Platform$file.sep, dll_dir)
    }
  } else {
    dll_dir <- NA_character_
  }
  
  if (has_fit_block(mod_file)) {
    if (missing(fit_mod_file)) {
      fit_mod_file <- tempfile()
    }
    fit_info   <- create_fit_mod(mod_file, fit_mod_file, debug)
    model_info <- compile_model_(fit_mod_file, use_dll, dll_dir)
    params <- model_info$params
    model_info$params <- NULL
    if (missing(fit_mod_file)) {
      unlink(fit_mod_file)
    } 
    if (use_dll) {
      dll_file <- compile_c_functions(dll_dir)
    } else {
      dll_file <- NA_character_
    }
    mdl <- FitMdl$new(model_info, fit_info, params, bytecode, use_dll,
                       dll_dir, dll_file, debug)
  } else {
    if (!missing(fit_mod_file)) {
      warning("fit_mod_file specified, but no fit block in mod file found")
    }
    model_info <- compile_model_(mod_file, use_dll, dll_dir)
    params <- model_info$params
    model_info$params <- NULL
    if (use_dll) {
      dll_file <- compile_c_functions(dll_dir)
    } else {
      dll_file <- NA_character_
    }
    
    mdl <- DynMdl$new(model_info, params, bytecode, use_dll, dll_dir, dll_file)
  }
  
  if (!missing(data)) {
    data_period <- get_period_range(data)
    if (!missing(period)) {
      # data_period should be the union of the period_range of data
      # and the supplied period extended with a lag and lead period.
      data_period_2 <- period_range(
        start_period(period) - mdl$get_maxlag(),
        end_period(period)   + mdl$get_maxlead())
      data_period <- range_union(data_period, data_period_2)
    }
    if (is.null(colnames(data))) {
      stop("data has no column names")
    } else {
      mdl$init_data(data_period = data_period, data = data)
    }
  }
  
  if (!missing(period)) {
    period <- as.period_range(period)
    mdl$set_period(period)
  }
  
  return(mdl)
}

# Returns true if model mod_file contains a fit block
# Note that the fit block should be in the main mod file.
has_fit_block <- function(mod_file) {
  # TODO: fit_command is also used in create_fit_mod. Is there a way to store
  # this data? Otherwise we could create a function get_fit_command().
  fit_command <- "%$fit$"
  fit <- FALSE
  con <- file(mod_file, "r")
  while (TRUE) {
    line <- readLines(con, n = 1)
    if (length(line) == 0) {
      break
    }
    if (startsWith(trimws(line, "left"), fit_command)) {
      fit <- TRUE
      break
    }
  }
  close(con)
  return (fit)
}


