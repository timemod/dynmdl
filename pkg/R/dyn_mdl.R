#' Creates a \code{\link{DynMdl}} object from a mod file
#'
#' Creates a \code{\link{DynMdl}} object from a mod file. If the mod file
#' contains a fit block, then the \code{DynMdl} object implements the fit 
#' procedure (except if argument \code{fit} is \code{FALSE}).
#' 
#' \subsection{Initialization of the model data}{
#' 
#' If argument `period` and/or `data` have been specified, then the model data
#' is initialized with the static values for a certain period range, the
#' so called "model data period". The 
#' model data period is determined from arguments `period`, `data` and 
#' `base_period`. If all three arguments are specified, then the data period
#' is the union of three period ranges: 
#' \describe{
#' \item{1}{the model period (`period`) extended with a lag and lead period.}
#' \item{2}{the period range of `data`.}
#' \item{3}{the base period `base_period`.}
#' }
#' If not all three arguments are specified, then the model data period is set
#' of the union of the period ranges corresponding to the the arguments that
#' have been specified. For example, if only `data` and `base_period` have been
#' specified, then the data period is the union of the period range of `data`
#' and the base period. Note that for models without trends argument `base_period`
#' is ignored.
#' }
#' 
#' \subsection{Evaluation of model equations}{
#' 
#' There are several methods available for evaluating the model equations and 
#' the Jacobian. These methods can be specified with argument `calc`.  
#' The possible methods are
#' \describe{
#' \item{`R`}{the model equations and Jacobian are evaluated using R functions . 
#' This is very slow for large models. This method should therefore only be 
#' used for small models.}
#' \item{`bytcode`}{the same as `R`, except that the R function is turned into byte code.
#' This is usually only slightly faster than using the `R` method}
#' \item{`dll`}{The model equations and Jacobian are evaluated using a 
#' shared library created for this specific model.
#' Function `dyn_mdl` generates C code for evaluating the equations and the Jacobian,
#' and subsequently compiles the C code to create a shared library. The
#' evaluation of the equations and Jacobian is much faster than for 
#' the `R` and `bytecode` methods. However, the compilation of the
#' C code can take a considerable amount time for large models.}
#' \item{`internal`}{This methods converts
#' the equations to internal byte code using reverse Polish notation.
#' The internal byte code is evaluated using compiled C++ code that is part
#' of package `dynmdl`.
#' For this method the evaluation of the equations and Jacobian
#' is as fast as for the `dll` method, but the compilation time 
#' is much faster. However, the `internal` method does not yet support 
#' all features of Dynare models. For example, it cannot handle 
#' model-local variables and some built-in functions (the only supported
#' built-in functions are currently  `exp`, `log`, `sqrt`, `abs` and `sign`).}
#' }
#' 
#' If possible, use the `internal` method, because this method is faster than
#' the other methods for both compiling the model and for evaluating the equations
#' and Jacobian. The `internal` method is therefore the default method.
#' However, as explained above, the mod file may contain features not 
#' yet supported for the `internal` method, in which case another 
#' method must be selected.
#' }
#' 
#' \subsection{Latex options}{
#' When the mod file contains a \code{write_latex_static_model},
#' \code{write_latex_dynamic_model} or \code{write_latex_oiriginal_model} 
#' statement, then the Dynare parser of package \code{dynmdl} generates
#' LaTeX files in directory \code{latex}. Argument \code{latex_options} can be
#' used to change the filenames of the LaTeX file or
#' the format of the LaTeX files. It should be a named list containing one or 
#' more of the following components:
#' \describe{
#' \item{\code{dir}}{A character specifying the directory where the LaTeX
#' files are created. The default is `"latex/<basename>"`,
#' where `<basename>` is the basename of the mod file excluding the file 
#' extension. For example, if the specified mod file is `mod/islm.mod`, then the
#' default LaTeX directory is `latex/islm`.}
#' \item{\code{prefix}}{A character vector specifying a prefix for the 
#' Latex files. By default no prefix is added. If specified, then
#' the LaTeX filenames start with the prefix followed by an underscore. 
#' For example, if `prefix = "islm"`, then name of the LaTeX file with 
#' dynamic equations is `islm_dynamic_content.tex`.
#' If `prefix` has not been specified, then the filename is 
#' `dynamic_fit_content.tex`. The prefix is also added to the name of the
#' directory for the single equations.}
#' \item{\code{par_as_num}}{A logical. If \code{TRUE}, then the parameters
#' are written as numerical constants to the LaTeX file, using the numerical
#' values as specified in the mod file. The default is \code{FALSE}.}
#' \item{\code{ndigits}}{The number of significant digits used when parameters
#' as written as numerical values (default 4). This argument is only used 
#' if \code{par_as_num} is \code{TRUE}. For example, if \code{ndigits} is 4,
#' then the number \eqn{\pi} is printed as \code{3.142},
#' the number 120.25 as \code{120.2}, and the number
#' 10.1234 as \code{1.012e+05}}
#' }}
#'
#' @param mod_file the name of the model file (including extension .mod)
#' @param period a \code{\link[regts]{period_range}} object specifying the
#' model period, i.e. the period range for which the model will be solved. Thus
#' this period range excludes the lag and lead period.  If this argument has
#' not been specified while `data` has been specified, then the model period
#' is set to the dat aperiod exlcluding a lag and lead period. See also section
#' "Initialization of the Model Data".
#' @param data the model data as a  \code{\link[regts]{regts}} object with column
#' names. See also section "Initialization of the Model Data".
#' @param base_period a \code{\link[regts]{period}} object specifying
#' the base period for the trends. This is used if the model has trend variables.
#' All trend variables will be equal to 1 at the base period. This argument is
#' ignored for models without trend. If not specified, `base_period` is
#' set to the start period of the model period
#' @param calc Method used to evaluate the model equations. 
#' Possible values are `"internal"`,  \code{"R"}, \code{"bytecode"} and \code{"dll"}.
#' See Details.
#' @param fit_mod_file the name of the generated fit mod file. If not specified,
#' then the fit mod file is destroyed after the model has been parsed.
#' This argument should not be specified if the model contains
#' trends, since in that case the fit mod file cannot be used a input mod file 
#' for function \code{dyn_mdl} or for Dynare. If wou want to check the 
#' equations in the fit mod file, use argument \code{DEBUG} (see below).
#' @param debug If logical (default \code{FALSE}), only used when the 
#' model is a fit model. If \code{TRUE}, then intermediate files created when
#' preparing the fit model are written to the current directory. By default
#' these files are written in a temporary directory and deleted when the 
#' R session terminates.
#' @param dll_dir the directory where the dynamically linked library is stored.
#' Primarily used for testing.
#' Only used if argument \code{use_dll} is \code{TRUE}.
#' @param max_laglead_1 a logical indicating whether the model should be 
#' transformed internally to a model with a maximum lag and lead of 1.
#' The default is \code{FALSE}. This option has no effect if the maximum lag
#' and lead of the original model is 1. Set this argument to
#' \code{TRUE} if you want to analyse the stability of the steady state with 
#' method \code{\link{check}} for models with a maximum lag or lead larger than 1.
#' @param strict A logical. If `TRUE` (the default), then an error
#' is given when endogenous or exogenous variables are not used in the model block 
#' or when an undeclared symbol is assigned in the initval block. If
#' `FALSE`, then only a warning is issued,  unused endogenous variables
#' are removed, and the assignments of undeclared symbols in the initval block 
#' are ignored.
#' @param warn_uninit_param A logical. If \code{TRUE} (the default) then
#' a warning is given for each parameter that has not been initialized in the
#' mod file. Uninitialized parameters are set to zero or `NA`, depending
#' on argument `init_param_na`.
#' @param init_param_na A logical (default `FALSE`). If `TRUE`, then
#' the parameters that have not been initialized in the
#' mod file are set to `NA`. Otherwise these parameters are initialised
#' with zero.
#' @param fit a logical (default \code{TRUE}) indicating if the \code{DynMdl} 
#' object returned by this function should implement the fit procedure if the 
#' mod file contains a fit block. Specify \code{FALSE} if the mod file  has a fit
#' block while you do not want to use the fit procedure.
#' @param fit_fixed_period a logical. If \code{TRUE}, then the fit conditions are
#' derived for a fixed period, treating lags and leads as exogenous variables.
#' If \code{FALSE} (the default), the fit conditions are derived from the
#' stacked-time equations. This option is particularly useful for backward 
#' looking models (models without leads but with lags). 
#' If `fit_fixed_period` is `TRUE`, then the fit equations do not contain
#' leads, so the full model is stil backward looking. If `fit_fixed_period` is 
#' `FALSE`, then some fit equations will contain leads.
#' @param check_static_eqs a logical. If \code{TRUE} (the default), then 
#' `dyn_mdl` checks if the mod file contains separate static and dynamic equations (i.e. 
#' equations tagged with `static` and `dynamic`). If this is the case,
#' separate static and dynamic fit equations are generated when necessary
#' (separate equations are not generated if the static version is simply
#' equal to the dynamic version when lags and leads are removed).
#' @param latex A logical. If \code{TRUE} (the default), then LaTeX files
#' are created if the model block contains a \code{write_latex_static_model},
#' \code{write_latex_dynamic_model} or \code{write_latex_original_model} statement.
#' @param latex_options a list with options for writing LaTeX files.
#' See Details.
#' @param nostrict Obsolete: the logical negation of argument  `strict`. This 
#' argument should not be used in new code: use argument `strict` instead.
#' @param silent A logical (default \code{FALSE}). If \code{TRUE}, then
#' output of the Dynare parser is suppressed except for warnings.
#' @return A \code{DynMdl} object.
#' @export
#' @importFrom Rcpp sourceCpp
#' @importFrom regts as.period
#' @importFrom regts as.period_range
#' @importFrom stats frequency
#' @importFrom tools file_path_sans_ext
#' @importFrom regts range_union
#' @importFrom regts as.regts
#' @importFrom tools file_path_sans_ext
#' @importFrom utils capture.output
dyn_mdl <- function(mod_file, period, data, base_period,
                    calc = c("internal", "R", "bytecode", "dll"),
                    fit_mod_file, debug = FALSE, dll_dir, 
                    max_laglead_1 = FALSE, strict = TRUE,
                    warn_uninit_param = TRUE, init_param_na = FALSE,
                    fit = TRUE, fit_fixed_period = FALSE, 
                    check_static_eqs = TRUE, latex = TRUE,
                    latex_options, nostrict, silent = FALSE) {
  
  calc <- match.arg(calc)
  
  latex_options_ <- list(dir = file.path("latex",
                                         file_path_sans_ext(basename(mod_file))),
                         prefix = "",  par_as_num = FALSE, ndigits = 4)
  
  if (!missing(latex_options)) {
    if (!is.list(latex_options) || is.null(names(latex_options))) {
      stop("Argument latex_options should be named list.")
    }
    if (length(invalid_options <- setdiff(names(latex_options), 
                                    names(latex_options_))) > 0) {
      stop(paste("Invalid latex option(s)", 
                 paste(paste0("\"", invalid_options, "\""), collapse = ", "), 
                 "specified."))
    }
    
    if (!is.null(dir <- latex_options$dir)) {
      if (!is.character(dir) || length(dir) != 1 || trimws(dir) == "") {
        stop("Latex option 'dir' should be a single non-empty character string.")
      } 
    }
    
    if (!is.null(prefix <- latex_options$prefix)) { 
        if (!is.character(prefix) || length(prefix) != 1 || 
            trimws(prefix) == "") {
          stop("Latex option 'prefix' should be a single non-empty character ",
               "string.")
        } else if (grepl("(\\\\|/)", prefix)) {
          stop("Latex option prefix should not contain a directory separator")
        }
    }
    
    latex_options_[names(latex_options)] <- latex_options
  }

  # check strict and nostrict
  if (!missing(strict)) {
    if (!is.logical(strict) || length(strict) != 1) {
      stop("Argument `strict` should be TRUE or FALSE.")
    }
    if (!missing(nostrict)) {
      warning(paste("Obsolete argument 'nostrict' is ignored because argument",
                    "'strict' has been specified."))
    }
  } else if (!missing(nostrict)) {
    if (!is.logical(nostrict) || length(nostrict) != 1) {
      stop("Argument `nostrict` should be TRUE or FALSE.")
    }
    warning(paste("Argument 'nostrict' is obsolete. Use argument 'strict'",
                  "instead."))
    strict <- !nostrict
  }

  use_dll <- calc == "dll"
  internal_calc <- calc == "internal"
  
  # check argument period, base_period and data
  period_present <- !missing(period) && !is.null(period)
  data_present <- !missing(data) && !is.null(data)
  base_period_present <- !missing(base_period) && !is.null(base_period)
  if (period_present) period <- as.period_range(period)
  if (base_period_present) base_period <- as.period(base_period)
  if (data_present) data <- as.regts(data)
  
  if (base_period_present && period_present &&
      frequency(base_period) != frequency(period)) {
      stop("Argument 'base_period' has a different frequency",
           " than argument 'period'.")
  } else if (period_present && data_present && 
             frequency(period) != frequency(data)) {
      stop("Argument 'data' has a different frequency",
           " than argument 'period'.")
  } else if (base_period_present && data_present && 
      frequency(base_period) != frequency(data)) {
      stop("Argument 'data' has a different frequency",
           " than argument 'base_period'.")
  }
  
  #
  # check mod file
  #
  if (!is.character(mod_file) | length(mod_file) > 1) {
    stop("Argument 'mod_file' must be a character vector of length 1.")
  }
  if (dir.exists(mod_file)) stop(sprintf("'%s' is a directory", mod_file))
  if (!file.exists(mod_file)) stop(sprintf("File '%s' does not exist", mod_file))
  if (.Platform$OS.type == "unix" && startsWith(mod_file, "~")) {
    mod_file <- normalizePath(mod_file)
  }

  if (calc == "dll") {
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
    preprocessed_mod_file <- tempfile("preproc", fileext = ".mod")
  }

  output <- capture.output({
    run_macro(mod_file, preprocessed_mod_file)
  })
  
  mod_text <- read_file(preprocessed_mod_file)
  
  if (fit) instruments <- get_fit_instruments(mod_text)
  
  if (fit && is.null(instruments)) {
    if (!missing(fit)) {
      stop("No fit block in model file, fit procedure not possible")
    }
    fit <- FALSE
  }
  
  
  if (fit)  {
    
    # FIT PROCEDURE
    
    if (missing(fit_mod_file)) {
      fit_mod_file <- if (debug) "fitmod.mod" else 
                       tempfile(pattern = "fit", fileext = ".mod")
    } else {
      if (!is.character(fit_mod_file) | length(fit_mod_file) > 1) {
        stop("Argument 'fit_mod_file' must be a character vector of length 1.")
      }
      if (regexpr("trend_var\\(.+\\)", mod_text) != -1) {
        if (file.exists(fit_mod_file)) unlink(fit_mod_file)
        stop(paste("For models with trends, it is not possible to create a fit",
                   "mod file that\ncan be used as input mod file for dyn_mdl or",
                   "Dynare."))
      }
      if (dir.exists(fit_mod_file)) stop(sprintf("'%s' is a directory", 
                                                 fit_mod_file))
      if (.Platform$OS.type == "unix" && startsWith(fit_mod_file, "~")) {
         fit_mod_file <- sub("~", Sys.getenv("HOME"), fit_mod_file)
      }
      
    }
    
    fit_info <- create_fit_mod(mod_file, preprocessed_mod_file, fit_mod_file, 
                               instruments, fixed_period = fit_fixed_period, 
                               check_static_eqs = check_static_eqs,
                               latex = latex, latex_options = latex_options_,
                               silent = silent)
   
    n_fit_derivatives <- length(fit_info$orig_endos) + length(fit_info$sigmas)
  
    mod_file_compile <- fit_mod_file
    
  } else {
    
    # NO FIT
    
    if (!missing(fit_mod_file)) {
      warning("fit_mod_file specified, but no fit block in mod file found")
    }
    
    fit_info <- NULL
    n_fit_derivatives <- 0L
    mod_file_compile <- mod_file
  }
  
  #
  # Call C++ function compile_model_
  #
  call_compile_model_  <- function() {
    return(compile_model_(mod_file_compile, use_dll, dll_dir, max_laglead_1, 
                          strict, internal_calc, n_fit_derivatives, 
                          warn_uninit_param, init_param_na, latex, 
                          latex_options_))
  }
   
  if (silent) {
    output <- capture.output({
      model_info <- call_compile_model_()
    })
  } else {
    model_info <- call_compile_model_()
    cat("\n")
  }
  
  if (fit && missing(fit_mod_file)) {
    unlink(fit_mod_file)
  } 
  
  #
  # construct a vector with  original equations
  #
  if (fit) {
    fit_mod_text <- read_file(fit_mod_file)
    equations_orig <- get_equations_orig(fit_mod_text, model_info)
  } else {
    equations_orig <- get_equations_orig(mod_text, model_info) 
  }
  
  #
  # Create an object that defines the structure of the model
  #
  mdldef <- create_mdldef(model_info, equations_orig, fit_info)
  
  #
  # check if all endogenous variables appear as current period variables
  #
  problem_endo_indices <- which(mdldef$lead_lag_incidence[ , "0"] == 0)
  if (length(problem_endo_indices) > 0) {
    problem_endos <- mdldef$endo_names[problem_endo_indices]
    problem_endos <- paste0("'", sort(problem_endos), "'")
    stop("The following endogenous variable(s) only appear(s) with lags/leads\n",
         "in the model equations and not as current period variables:\n",
         paste(problem_endos, collapse = ", "), ".")
  }
  
  #
  # create the dll file
  #
  if (calc == "dll") {
    dll_file <- compile_c_functions(dll_dir)
  } else {
    dll_file <- NA_character_
  }
  
  model_index <- model_info$model_index
  
  if (base_period_present) {
    if (!mdldef$trend_info$has_deflated_endos) {
      warning("Argument 'base_period' is ignored because the model does ",
              "not have trends.")
      base_period_present <- FALSE
      base_period <- NULL
    } 
  } 
  
  mdl <- DynMdl$new(model_index, mdldef, base_period, calc,  dll_dir, dll_file)

  if (!debug) {
    unlink(preprocessed_mod_file)
  }
  
  #  initialize data if argument period and/or data have been specified
  if (period_present || data_present) {
    data_period <- get_data_period(data, period, base_period, mdldef) 
    mdl$init_data(data_period = data_period, data = data)
  }
  
  if (period_present) mdl$set_period(period)

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

  if (length(instruments) == 0) return(NULL)
  return(instruments)
}

# This function creates a vector with original equations. mod_text is 
# a character vector holding the text of the mod file (for fit models
# this is the text of the generated fit mod file). 
# model_info is the model information returned by C++ function compile_model_.
get_equations_orig <- function(mod_text, model_info) {
  
  # the code below may fail when there are model variables named "model" or
  # "end". Therefore check the names
  if (any(c("model", "end") %in% c(names(model_info$endos), 
                                   names(model_info$exos),
                                   names(model_info$params)))) {
    stop(paste("\"model\" or \"end\" should not be used as names for model",
               "variables or parameters."))
  }
  
  # remove C-style comments, regexpr cannot handle this
  mod_text <- gsub("/\\*[\\s\\S]*?\\*/", "", mod_text, perl = TRUE, 
                   useBytes = TRUE)
  
  # NOTE: do not use the regular expression in the commented code below. 
  # It works, but there are memory problems for large models.
  # m <- regexpr("model.*?;([\\s\\S]+?)end;", mod_text, perl = TRUE, 
  #             useBytes = TRUE)
  

  m <- regexpr("\\smodel(\\(.+?\\))?;", mod_text)
  if (is.null(m)) {
    stop("Could not find the model block")
  }
  start_pos <- as.numeric(m) + attr(m, "match.length")
  model_block <- substring(mod_text, start_pos, nchar(mod_text))
  m <- regexpr("\\send;", model_block)
  if (is.null(m)) {
    stop("Could not find the end of the model block")
  }
  end_pos <- as.numeric(m) - 1
  model_block <- substr(model_block, 1,  end_pos)
  model_block <- trimws(model_block)
  
  # remove comments
  model_block <- gsub("\\s*%.*\n", "\n", model_block, perl = TRUE, useBytes = TRUE)
  model_block  <- gsub("//.*\n", "\n", model_block, perl = TRUE, useBytes = TRUE)
  
  # split equations
  equations <- strsplit(model_block, ";")[[1]]
  equations <- unlist(lapply(equations, FUN = trimws))
  
  # skip equations tagged with static.
  equations <- grep("\\[(.+,)?\\s*static\\s*(,.+)?\\]", equations, 
                    invert = TRUE, value = TRUE)
  
  # skip local equations
  equations <- equations[!startsWith(equations, "#")]
  
  return(equations)
}

# This function creates a mdldef object, which contains all information
# about the model that can be extracted from the mod file.
# model_info is the object returned by C++ function compile_model_.
# original_equations is a character vector holding the original equations.
# fit_info contains information about the fit procedure returned by function
# create_fit_mod
create_mdldef <- function(model_info, equations_orig, fit_info) {
  
  static_model  <- model_info$static_model
  dynamic_model <- model_info$dynamic_model
  
  mdldef <- list(fit                   = !is.null(fit_info),
                 has_aux_vars          = model_info$aux_vars$aux_count > 0,
                 endos                 = model_info$endos,
                 exos                  = model_info$exos,
                 params                = model_info$params,
                 aux_vars              = model_info$aux_vars,
                 max_endo_lag          = dynamic_model$max_endo_lag,
                 max_endo_lead         = dynamic_model$max_endo_lead,
                 max_exo_lag           = dynamic_model$max_exo_lag,
                 max_exo_lead          = dynamic_model$max_exo_lead,
                 lead_lag_incidence    = dynamic_model$lead_lag_incidence,
                 jac_static_size       = static_model$jac_size,
                 jac_dynamic_size      = dynamic_model$jac_size,
                 jac_dynamic_size_endo = dynamic_model$jac_size_endo,
                 static_functions      = static_model$static_functions,
                 dynamic_functions     = dynamic_model$dynamic_functions,
                 initval               = model_info$initval)
  
  #
  # set row and column names for the lead_lag_incidence
  #
  colnames(mdldef$lead_lag_incidence) <- as.character(
                                  - mdldef$max_endo_lag : mdldef$max_endo_lead)
  rownames(mdldef$lead_lag_incidence) <- names(mdldef$endos)
  
  #      
  # endo and exo_count
  #
  mdldef$exo_count  <- length(mdldef$exos)
  mdldef$endo_count <- length(mdldef$endos)
  
  mdldef <- install_name_admin(mdldef, fit_info)
  mdldef <- install_laglead_admin(mdldef)
  
  #
  # information about trends
  #
  mdldef$trend_info <- convert_trend_info(model_info$trend_info, 
                                          names(mdldef$exos), 
                                          names(mdldef$endos))
  
  #
  # labels and tex names
  #
  names <- c(names(mdldef$endos), names(mdldef$exos), names(mdldef$params))
  labels <- c(model_info$endo_long_names, model_info$exo_long_names, 
              model_info$param_long_names)
  tex_names <- c(model_info$endo_tex_names, model_info$exo_tex_names, 
                 model_info$param_tex_names)
  names(labels) <- names
  names(tex_names) <- names
  ord <- order(names)
  mdldef$labels <- labels[ord]
  mdldef$tex_names <- tex_names[ord]
  
  #
  # equations and original equations
  #
        # split equations over multiple lines if necessary:
  split_lines <- function(eq) {
      paste(strwrap(eq, width = 80, exdent = 4), collapse = "\n")}
  mdldef$stat_equations <- sapply(model_info$stat_equations, 
                             FUN = split_lines, USE.NAMES = FALSE)
  mdldef$equations <- sapply(model_info$equations, 
                            FUN = split_lines, USE.NAMES = FALSE)
  mdldef$equations_orig <- equations_orig
  
  #
  # information about the fit procedure
  #
  if (mdldef$fit) mdldef$fit_info <- convert_fit_info(fit_info, mdldef)

  return(mdldef)
}

install_name_admin <- function(mdldef, fit_info) {
  #
  #  endo and exo names
  #
  mdldef$endo_names <- names(mdldef$endos)
  mdldef$exo_names  <- names(mdldef$exos)
  mdldef$param_names <- names(mdldef$params)
  
  # endogenous variables excl. aux. vars
  if (mdldef$has_aux_vars) {
    mdldef$endo_names_no_aux <- mdldef$endo_names[-mdldef$aux_vars$endos]
  } else {
    mdldef$endo_names_no_aux <- mdldef$endo_names
  } 
  
  # endos and exos of original model (excl. auxiliary variables and 
  # endos and exos generated for the fit procedure.):
  if (mdldef$fit) {
    mdldef$endo_names_orig <- fit_info$orig_endos
    mdldef$exo_names_orig <- fit_info$orig_exos
  } else {
    mdldef$endo_names_orig <- mdldef$endo_names_no_aux
    mdldef$exo_names_orig <- mdldef$exo_names
  }
  mdldef$endo_indices_orig <- match(mdldef$endo_names_orig, mdldef$endo_names)
  mdldef$exo_indices_orig <- match(mdldef$exo_names_orig, mdldef$exo_names)
  
  return(mdldef)
}

install_laglead_admin <- function(mdldef) {
  #
  # total maximum lag and lead 
  #
  mdldef$max_lag <- max(mdldef$max_endo_lag,  mdldef$max_exo_lag)
  mdldef$max_lead <- max(mdldef$max_endo_lead,  mdldef$max_exo_lead)
  
  #
  # maximum and minimum lag of the original model.
  #
  # If the original model has lags or leads greater than 1, this is different
  # from the values of the actual model.
  mdldef$max_endo_lag_orig  <- mdldef$max_endo_lag
  mdldef$max_endo_lead_orig <- mdldef$max_endo_lead
  if (mdldef$aux_vars$aux_count > 0) {
    max_aux_lag <-  max(max(-mdldef$aux_vars$orig_leads), 0)
    max_aux_lead <- max(max(mdldef$aux_vars$orig_leads), 0)
    if (max_aux_lag > 0) {
      mdldef$max_endo_lag_orig <- max(mdldef$max_endo_lag_orig, max_aux_lag + 1)
    }
    if (max_aux_lead > 0) {
      mdldef$max_endo_lead_orig <- max(mdldef$max_endo_lead_orig, max_aux_lead +
                                         1)
    }
  }
  mdldef$max_lag_orig <- max(mdldef$max_endo_lag_orig,  mdldef$max_exo_lag)
  mdldef$max_lead_orig <- max(mdldef$max_endo_lead_orig,  mdldef$max_exo_lead)
  return(mdldef)
}

convert_fit_info <- function(fit_info, mdldef) {
  # convert names in fit_info to indices
  return(within(fit_info, {
    instrument_names <- instruments
    sigma_names <- sigmas
    l_var_names <- l_vars
    orig_endos <- match(orig_endos, mdldef$endo_names)
    orig_exos <- match(orig_exos, mdldef$exo_names)
    l_vars <- match(l_vars, mdldef$endo_names)
    fit_vars <- match(fit_vars, mdldef$exo_names)
    exo_vars <- match(exo_vars, mdldef$exo_names)
    instruments <- match(instruments, mdldef$endo_names)
    old_instruments <- match(old_instruments, mdldef$exo_names)
    sigmas <- match(sigmas, mdldef$param_names)
  }))
}

get_var_names <- function(expr_string) {
  # returns the variable names from a string with an R expression
  
  get_var_names_ <- function(x)
    if (class(x) == "name") {
      return(as.character(x))
    } else if ((class(x) == "(") || (class(x) == "{")) {
      return(get_var_names_(x[[2]]))
    } else if (class(x) == "call") {
      if (! deparse(x[[1]]) %in% c("*", "+", "-", "/", "^")) {
        stop(paste("dynmdl cannot handle expression", deparse(x), "yet"))
      }
      # currently only unary and binary operators are supported
      arguments <- as.list(x[-1])
      variables <- lapply(arguments, FUN = get_var_names_)
      return(sort(unique(do.call(c, variables))))
    } else if (class(x) == "if") {
      stop(paste("dynmdl cannot handle expression", deparse(x), "yet"))
    } else if (is.numeric(x)) {
      return(character(0))
    } else {
      stop(paste("dynmdl cannot handle expression", deparse(x), "yet"))
    }
  
  expr <- parse(text = expr_string)
  return(unique(get_var_names_(expr[[1]])))
}


convert_trend_info <- function(trend_info, exo_names, endo_names) {
  
  trend_info$trend_vars <- as.data.frame(trend_info$trend_vars, 
                                         stringsAsFactors = FALSE)
  trend_info$deflated_endos <- as.data.frame(trend_info$deflated_endos,
                                             stringsAsFactors = FALSE)
  
  trend_info$growth_factors <- unique(trend_info$trend_vars$growth_factors)
  trend_info$deflators <- unique(trend_info$deflated_endos$deflators)
  
  growth_factor_vars <- unique(unlist(lapply(trend_info$growth_factors, 
                                      FUN = get_var_names)))
  if (length(setdiff(growth_factor_vars, exo_names)) > 0) {
    # TODO: improve error message
    stop(paste("dynmdl expects that all variables in growth",
               "expressions are exogenous model variables"))
  }
  
  trend_info$growth_exos <- growth_factor_vars

  
  deflator_vars <- unique(unlist(lapply(trend_info$deflators, 
                                        FUN = get_var_names)))

  if (length(setdiff(deflator_vars, trend_info$trend_vars$names)) > 0) {
    # TODO: improve error message
    stop(paste("dynmdl expects that all variables in deflator",
               "expressions are trend variables"))
  }
  
  # TODO: check that all trend variables are used in deflators, otherwise
  # give a warning
  trend_info$has_deflated_endos <- nrow(trend_info$deflated_endos) > 0
  
  return(trend_info)
}
  

# read the text of a file into a single character string
read_file <- function(filename) {
  text <- readChar(filename, nchars = file.size(filename), useBytes = TRUE)
  Encoding(text) <- "latin1"
  return(text)
}
