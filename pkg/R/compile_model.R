#' Compile a Dynare model and return a \code{\link{DynMod}}
#'
#' @param mod_file the name of the model file (including extension .mod)
#' @param bytecode If \code{TRUE}, then the functions used to calculate the
#' residuals and jacobian are compiled
#' @param fit_mod_file the name of the fit mode file. If not specified,
#' then the fit mod file is destroyed after the model has been parsed.
#' @return an \code{DynMod} object
#' @export
#' @importFrom Rcpp sourceCpp
#' @importFrom tools file_path_sans_ext
#' @useDynLib dynmod
compile_model <- function(mod_file, bytecode = FALSE, use_dll = FALSE,
                          dll_dir = file_path_sans_ext(basename(mod_file)), 
                          fit_mod_file, debug = FALSE) {


    if (!file.exists(mod_file)) {
        stop(paste("ERROR: Could not open file:", mod_file))
    }
    if (use_dll) {
        dir.create(dll_dir, showWarnings = FALSE)
    }
    if (has_fit_block(mod_file)) {
        return (FitMod$new(mod_file, bytecode, use_dll, dll_dir, fit_mod_file, debug))
    } else {
        if (!missing(fit_mod_file)) {
            warning("fit_mod_file specified, but no fit block in mod file found")
        }
        return (DynMod$new(mod_file, bytecode, use_dll, dll_dir))
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


