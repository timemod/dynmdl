#' Creates a \code{\link{DynMdl}} or  \code{\link{FitMdl}} object from a mod file
#'
#' Creates a \code{\link{DynMdl}} object from a mod file. If the mod file
#' contains a fit block, then this function returns a \code{\link{FitMdl}} 
#' object, which is an extension of a \code{DynMdl} object.
#'
#' @param mod_file the name of the model file (including extension .mod)
#' @param period a \code{\link[regts]{period_range}} object specifying the
#' model period, i.e. the period range for which the model will be solved. Thus
#' this period range excludes the lag and lead period.
#' @param data the model data as a  \code{\link[regts]{regts}} object with column
#' names
#' @param base_period a \code{\link[regts]{period}} object specifying
#' the base period for the trends. This is used if the model has trend variables.
#' All trend variables will be equal to 1 at the base period.
#' @param calc Method used to evaluate the model equations. 
#' Possible values are \code{"R"}, \code{"bytecode"}, \code{"dll"} and 
#' \code{"internal"}. See details.
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
#' @param nostrict Allows Dynare to issue a warning and continue processing when
#' there are more endogenous variables than equations,
#' an undeclared symbol is assigned in initval or endval,
#' or exogenous variables were declared but not used in the model block.
#' @param warn_uninit_param A logical. If \code{TRUE} (the default) then
#' a warning is given for each parameter that has not been initialized in the
#' mod file. Uninitialized parameters are always set to zero.
#' @param fit a logical. If \code{TRUE}, then the function returns
#' a  \code{FitMdl} object if a fit block has been found in the mod file.
#' If \code{FALSE} then this function does not return a \code{FitMdl} object.
#' @param fit_fixed_period a logical. If \code{TRUE}, then the fit conditions are
#' derived for a fixed period, treating lags and leads as exogenous variables.
#' If \code{FALSE} (the default), the fit conditions are derived from the
#' stacked-time equations.
#' @return an \code{DynMdl} object or, if the mod file contains a
#' fit block, a \code{\link{FitMdl}} object.
#' @export
#' @importFrom Rcpp sourceCpp
#' @importFrom tools file_path_sans_ext
#' @importFrom regts range_union
#' @importFrom regts as.regts
#' @importFrom tools file_path_sans_ext
dyn_mdl <- function(mod_file, period, data, base_period = NULL, 
                    calc = c("R", "bytecode", "dll", "internal"),
                    fit_mod_file, debug = FALSE, dll_dir, 
                    max_laglead_1 = FALSE, nostrict = FALSE,
                    warn_uninit_param = TRUE, fit = TRUE, 
                    fit_fixed_period = FALSE) {
  
  calc <- match.arg(calc)
  
  use_dll <- calc == "dll"
  internal_calc <- calc == "internal"
  
  # if (calc == "internal") {
  #   warning("The internal calc method is still experimental.")
  # }
  
  if (!file.exists(mod_file)) {
    stop(paste("ERROR: Could not open file:", mod_file))
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
  
  # basename for latex files, only used if the mod file contains a 
  # write_latex_dynamic_model etc.
  latex_basename <- file_path_sans_ext(basename(mod_file))
  
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

  run_macro(mod_file, preprocessed_mod_file)

  mod_text <- read_file(preprocessed_mod_file)
  
  instruments <- get_fit_instruments(mod_text)
  
  if (!missing(fit) && fit && is.null(instruments)) {
    stop("No fit block in model file, fit procedure not possible")
  }
  
  
  if (!is.null(instruments) && fit)  {
    
    # FIT PROCEDURE
    
    if (missing(fit_mod_file)) {
      fit_mod_file <- if (debug) "fitmod.mod" else 
                       tempfile(pattern = "fit", fileext = ".mod")
    } else if (regexpr("trend_var\\(.+\\)", mod_text) != -1) {
      if (file.exists(fit_mod_file)) unlink(fit_mod_file)
      stop(paste("For models with trends, it is not possible to create a fit",
                 "mod file that\ncan be used as input mod file for dyn_mdl or",
                 "Dynare."))
    }
    
    fit_info <- create_fit_mod(preprocessed_mod_file, fit_mod_file, 
                               instruments, latex_basename, 
                               fixed_period = fit_fixed_period)
   
    n_fit_derivatives <- length(fit_info$orig_endos) + length(fit_info$sigmas)
 
    mdldef <- compile_model(fit_mod_file, latex_basename, use_dll, dll_dir, 
                            max_laglead_1, nostrict, internal_calc,
                            n_fit_derivatives, warn_uninit_param)
    
    if (missing(fit_mod_file)) {
      unlink(fit_mod_file)
    } 
    if (calc == "dll") {
      dll_file <- compile_c_functions(dll_dir)
    } else {
      dll_file <- NA_character_
    }
    fit_mod_text <- read_file(fit_mod_file)
    equations <- get_equations(fit_mod_text)
    mdl <- FitMdl$new(mdldef, fit_info, equations, base_period, calc, 
                      dll_dir, dll_file, debug)
  } else {
    
    # NO FIT 
    
    if (!missing(fit_mod_file)) {
      warning("fit_mod_file specified, but no fit block in mod file found")
    }
    mdldef <- compile_model(mod_file, latex_basename, use_dll, dll_dir, 
                            max_laglead_1, nostrict, internal_calc, 0L,
                            warn_uninit_param)
    
    if (calc == "dll") {
      dll_file <- compile_c_functions(dll_dir)
    } else {
      dll_file <- NA_character_
    }
    equations <- get_equations(mod_text)
    mdl <- DynMdl$new(mdldef, equations, base_period, calc, dll_dir, dll_file)
  }
  
  if (!debug) {
    unlink(preprocessed_mod_file)
  }
  
  if (!missing(data)) {
    data <- as.regts(data)
    if (is.null(colnames(data))) {
      stop("data has no column names")
    }
    data_period <- get_period_range(data)
    
    if (!missing(period)) {
      # data_period should be the union of the period_range of data
      # and the supplied period extended with a lag and lead period.
      period <- as.period_range(period)
      data_period_2 <- period_range(
        start_period(period) - mdl$get_max_lag(),
        end_period(period)   + mdl$get_max_lead())
      data_period <- range_union(data_period, data_period_2)
    }
  
    mdl$init_data(data_period = data_period, data = data)
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

# extract a mdldef object from the model_info data returned by compile_model_
compile_model <- function(...) {
  
  model_info <- compile_model_(...)
  
  retval <- list()
  with(model_info, {
    retval$endos              <<- endos
    retval$exos               <<- exos
    retval$params             <<- params
    retval$model_index        <<- model_index
    retval$aux_vars           <<- aux_vars
    retval$max_endo_lag       <<- dynamic_model$max_endo_lag
    retval$max_endo_lead      <<- dynamic_model$max_endo_lead
    retval$max_exo_lag        <<- dynamic_model$max_exo_lag
    retval$max_exo_lead       <<- dynamic_model$max_exo_lead
    retval$lead_lag_incidence <<- dynamic_model$lead_lag_incidence
    retval$jac_static_size    <<- static_model$jac_size
    retval$jac_dynamic_size   <<- dynamic_model$jac_size
    retval$static_functions   <<- static_model$static_functions
    retval$dynamic_functions  <<- dynamic_model$dynamic_functions
  })
  
  # endo and exo_count
  retval$exo_count  <- length(retval$exos)
  retval$endo_count <- length(retval$endos)
  
  #
  # row and column names for the lead_lag_incidence
  #
  colnames(retval$lead_lag_incidence) <- as.character(
    - retval$max_endo_lag : retval$max_endo_lead)
  rownames(retval$lead_lag_incidence) <- names(retval$endos)
  
  #
  # labels and tex names
  #
  names <- c(names(retval$endos), names(retval$exos), names(retval$params))
  labels <- c(model_info$endo_long_names, model_info$exo_long_names, 
              model_info$param_long_names)
  tex_names <- c(model_info$endo_tex_names, model_info$exo_tex_names, 
                 model_info$param_tex_names)
  names(labels) <- names
  names(tex_names) <- names
  ord <- order(names)
  retval$labels <- labels[ord]
  retval$tex_names <- tex_names[ord]
  
  #
  # maximum lag and lead, taking auxiliary variables into account
  #
  retval$max_lag    <- max(retval$max_endo_lag,  retval$max_exo_lag)
  retval$max_lead   <- max(retval$max_endo_lead, retval$max_exo_lead)
  if (retval$aux_vars$aux_count > 0) {
    max_aux_lag <-  max(max(-retval$aux_vars$orig_leads), 0)
    max_aux_lead <- max(max(retval$aux_vars$orig_leads), 0)
    if (max_aux_lag > 0) {
      retval$max_lag <- max(retval$max_lag, max_aux_lag + 1)
    }
    if (max_aux_lead > 0) {
      retval$max_lead <- max(retval$max_lead, max_aux_lead + 1)
    }
  }
  
  retval$njac_cols <- length(which(retval$lead_lag_incidence != 0)) +
                             retval$exo_count
  
  
  retval$trend_info <- convert_trend_info(model_info$trend_info, 
                                          names(retval$exos), 
                                          names(retval$endos))
  
  return(retval)
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
  
  trend_info$has_deflated_endos <- nrow(trend_info$deflated_endo) > 0
  
  return(trend_info)
}
  

# read the text of a file into a single character string
read_file <- function(filename) {
  text <- readChar(filename, nchars = file.size(filename), useBytes = TRUE)
  Encoding(text) <- "latin1"
  return(text)
}



