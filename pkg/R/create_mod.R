#' Creates a \code{\link{DynMod}} object from a mod file
#'
#' @param mod_file the name of the model file (including extension .mod)
#' @param bytecode If \code{TRUE}, then the functions used to calculate the
#' residuals and Jacobian are byte compiled
#' @param  use_dll if \code{TRUE}, then the  functions used to calculate the
#' residuals and Jacobian are converted to C code that is subsequently
#' converted to a dynamically linked library.
#' @param fit_mod_file the name of the generated fit mod file. If not specified,
#' then the fit mod file is destroyed after the model has been parsed.
#' @param debug If \code{TRUE}, then some print statements
#' are executed.
#' @return an \code{DynMod} object or, if the mod file contains a
#' fit block, a \code{\link{FitMod}} object.
#' @export
#' @importFrom Rcpp sourceCpp
#' @importFrom tools file_path_sans_ext
#' @useDynLib dynmod
create_mod <- function(mod_file, bytecode = FALSE, use_dll = FALSE,
                       fit_mod_file, debug = FALSE) {

    if (!file.exists(mod_file)) {
        stop(paste("ERROR: Could not open file:", mod_file))
    }
    
    if (use_dll) {
        dll_dir <- tempdir()
    } else {
        dll_dir <- NA_character_
    }

    if (has_fit_block(mod_file)) {
        if (missing(fit_mod_file)) {
            fit_mod_file <- tempfile()
        }
        fit_info   <- create_fitmod(mod_file, fit_mod_file, debug)
        model_info <- compile_model_(fit_mod_file, use_dll, dll_dir)
        if (missing(fit_mod_file)) {
            unlink(fit_mod_file)
        } 
        if (use_dll) {
            dll_file <- compile_c_functions(dll_dir)
        } else {
            dll_file <- NA_character_
        }
        return(FitMod$new(model_info, fit_info, bytecode, use_dll, dll_dir,
                          dll_file, debug))
    } else {
        if (!missing(fit_mod_file)) {
            warning("fit_mod_file specified, but no fit block in mod file found")
        }
        model_info <- compile_model_(mod_file, use_dll, dll_dir)
        if (use_dll) {
            dll_file <- compile_c_functions(dll_dir)
        } else {
            dll_file <- NA_character_
        }
        return(DynMod$new(model_info, bytecode, use_dll, dll_dir, dll_file))
    }
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


