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
#' @param max_laglead_1 a logical indicating whether the model should be 
#' transformed internally to a model with a maximum lag and lead of 1.
#' The default is \code{FALSE}. This option has no effect if the maximum lag
#' and lead of the original model is 1. Set this argument to
#' \code{TRUE} if you want to analyse the stability of the steady state with 
#' method \code{\link{check}} for models with a maximum lag or lead larger than 1.
#' @return an \code{DynMdl} object or, if the mod file contains a
#' fit block, a \code{\link{FitMdl}} object.
#' @export
#' @importFrom Rcpp sourceCpp
#' @importFrom tools file_path_sans_ext
#' @importFrom readr read_file
#' @importFrom regts range_union
dyn_mdl <- function(mod_file, period, data, bytecode = FALSE, use_dll = FALSE,
                    fit_mod_file, debug = FALSE, dll_dir,
                    max_laglead_1 = FALSE) {
  
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
  
  # run macropreprocessor to preprocess the file, this is necessary
  # for get_equations()
  if (debug) {
    preprocessed_mod_file <- "preprocessed.mod"
    if (file.exists(preprocessed_mod_file)) {
      unlink(preprocessed_mod_file)
    }
  } else {
    preprocessed_mod_file <- tempfile()
  }
  run_macro(mod_file, preprocessed_mod_file)
  
  mod_text <- read_file(preprocessed_mod_file)
  
  instruments <- get_fit_instruments(mod_text)

  if (!is.null(instruments))  {
    
    if (missing(fit_mod_file)) {
      fit_mod_file <- tempfile()
    }
    
    fit_info   <- create_fit_mod(preprocessed_mod_file, fit_mod_file, 
                                 instruments, debug)
    model_info <- compile_model_(fit_mod_file, use_dll, dll_dir, max_laglead_1)
    
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
    fit_mod_text <- read_file(fit_mod_file)
    equations <- get_equations(fit_mod_text)
    mdl <- FitMdl$new(model_info, fit_info, params, equations, 
                      bytecode, use_dll, dll_dir, dll_file, debug)
  } else {
    if (!missing(fit_mod_file)) {
      warning("fit_mod_file specified, but no fit block in mod file found")
    }
    model_info <- compile_model_(mod_file, use_dll, dll_dir, max_laglead_1)
    params <- model_info$params
    model_info$params <- NULL
    if (use_dll) {
      dll_file <- compile_c_functions(dll_dir)
    } else {
      dll_file <- NA_character_
    }
    equations <- get_equations(mod_text)
    mdl <- DynMdl$new(model_info, params, equations, 
                      bytecode, use_dll, dll_dir, dll_file)
  }
  
  if (!debug) {
    unlink(preprocessed_mod_file)
  }
  
  if (!missing(period)) {
    period <- as.period_range(period)
  }
  
  if (!missing(data)) {
    data_period <- get_period_range(data)
    if (!missing(period)) {
      # data_period should be the union of the period_range of data
      # and the supplied period extended with a lag and lead period.
      data_period_2 <- period_range(
        start_period(period) - mdl$get_max_lag(),
        end_period(period)   + mdl$get_max_lead())
      data_period <- range_union(data_period, data_period_2)
    }
    if (is.null(colnames(data))) {
      stop("data has no column names")
    } else {
      mdl$init_data(data_period = data_period, data = data)
    }
  }
  
  if (!missing(period)) {
    mdl$set_period(period)
  }
  
  return(mdl)
}

get_fit_instruments <- function(mod_text) {
  # analyse expanded file line to find a list of instruments
  
  # remove C-style comments, regexpr cannot handle this
  mod_text <- gsub("/\\*[\\s\\S]*?\\*/", "", mod_text, perl = TRUE, 
                   useBytes = TRUE)
  
  fit_command <- "%$fit$"
  fit_end     <- "%$endfit$"
  # get fit block
  m <- regexpr("%\\$fit\\$[\\n\\r]+?([\\s\\S]+?)[\\n\\r]+?%\\$endfit\\$", 
               mod_text, perl = TRUE,  useBytes = TRUE)
  startpos <- attr(m, "capture.start")[1]
  endpos   <- startpos + attr(m, "capture.length")[1] - 1
  fit_block <- substr(mod_text, startpos, endpos)
  fit_block <- trimws(fit_block)
  fit_block <- gsub("\\$.+?\\$", "", fit_block) # remove latex names
  fit_block <- gsub("\\(.+?\\)", "", fit_block) # remove long names
  # remove comments
  fit_block <- gsub("%.*\n", "\n", fit_block, perl = TRUE, useBytes = TRUE)
  fit_block  <- gsub("//.*\n", "\n", fit_block, perl = TRUE, useBytes = TRUE)
  
  m <- gregexpr("varexo([^;]+)", fit_block, perl = TRUE, useBytes = TRUE)
  ma <- regmatches(fit_block, m)
  instruments <- strsplit(ma[[1]], split = "\\s+")
  instruments <- setdiff(unlist(instruments), "varexo")
  return(instruments)
}

# this function read the mod file and creates a vector with equations
get_equations <- function(mod_text) {
  
  # remove C-style comments, regexpr cannot handle this
  mod_text <- gsub("/\\*[\\s\\S]*?\\*/", "", mod_text, perl = TRUE, 
                   useBytes = TRUE)
  
  m <- regexpr("model.*?;([\\s\\S]+?)end;", mod_text, perl = TRUE, 
               useBytes = TRUE)
  startpos <- attr(m, "capture.start")[1]
  endpos <- startpos + attr(m, "capture.length")[1] - 1
  model_block <- substr(mod_text, startpos, endpos)
  model_block <- trimws(model_block)
  
  # remove comments
  model_block <- gsub("%.*\n", "\n", model_block, perl = TRUE, useBytes = TRUE)
  model_block  <- gsub("//.*\n", "\n", model_block, perl = TRUE, useBytes = TRUE)
  
  # split equations
  equations <- strsplit(model_block, ";")[[1]]
  equations <- unlist(lapply(equations, FUN = trimws))
  
  return(equations)
}


