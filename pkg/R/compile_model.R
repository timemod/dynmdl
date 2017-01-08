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
#' @useDynLib dynr
compile_model <- function(mod_file, bytecode = TRUE,
                          fit_mod_file) {
    if (!file.exists(mod_file)) {
        stop(paste("ERROR: Could not open file:", mod_file))
    }
    if (has_fit_block(mod_file)) {
        return (FitMod$new(mod_file, bytecode, fit_mod_file))
    } else {
        if (!missing(fit_mod_file)) {
            warning("fit_mod_file specified, but no fit block in mod file")
        }
        return (DynMod$new(mod_file, bytecode))
    }
}

# Returns true if model mod_file contains a fit block
has_fit_block <- function(mod_file) {
    fit_command <- "fit;"
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


