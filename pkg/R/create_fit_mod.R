# Constructs a mod file for the fit procedure based on a mod file with
# special #FIT tags.
# @param mod_file the filename of the mod file with #FIT tags
# @param fit_mod the name of the file used for the fit procedure
# @return a list with the names of the auxiliary variables
#' @useDynLib dynr
#' @importFrom stringi stri_split_fixed
create_fitmod <- function(mod_file, fit_mod, debug = FALSE) {
    
    if (file.exists(fit_mod)) {
        unlink(fit_mod)
    }

    if (debug) {
        tmp_mod          <- "tmp.mod"
        fit_control_file <- "fit_control_file.mod"
        expanded_file    <- "expanded.mod"
        if (file.exists(tmp_mod)) {
            unlink(tmp_mod)
        }
        if (file.exists(fit_control_file)) {
            unlink(fit_control_file)
        }
        if (file.exists(expanded_file)) {
            unlink(expanded_file)
        }
    } else {
        tmp_mod          <- tempfile()
        fit_control_file <- tempfile()
        expanded_file    <- tempfile()
    }

    convert_mod(mod_file, tmp_mod, step1 = TRUE,
                       fit_control_file = fit_control_file)
    
    run_macro(fit_control_file, expanded_file)

    # analyse #FIT line to find a list of residuals
    fit_txt <- paste(readLines(expanded_file), collapse = " ")
    m <- gregexpr("residuals([^;]+)", fit_txt, perl = TRUE)
    ma <- regmatches(fit_txt, m)
    residuals <- strsplit(ma[[1]], split = " ")
    residuals <- setdiff(unlist(residuals), "residuals")

    if (!debug) {
        unlink(expanded_file)
    }

    # run the Dynare parser to obtain the first order 
    # conditions for the fit procedure
    fit_cond <- get_fit_conditions(tmp_mod, residuals)
    
    if (!debug) {
        unlink(tmp_mod)
    }

    # finally, create the mod file for the fit procedure
    convert_mod(mod_file, fit_mod, step1 = FALSE, fit_cond = fit_cond)

    # return information about the fit variables
    with (fit_cond, {
        return (list(orig_endos = vars, orig_exos = orig_exos, 
                     l_vars = l_vars, fit_vars = fit_vars,
                     exo_vars = exo_vars, residuals = residuals, 
                     sigmas = sigmas))
    })
}


convert_mod <- function(input_file, output_file, step1, 
                        fit_control_file = NULL,
                        fit_cond = NULL) {

    # read the original model file, and process the fit block.
    # if step1 = TRUE, then the output file will be used
    # to compute the first order conditions

    # in the first step, the residuals are exogenous, in the second step
    # endogenous
    if (step1) {
        res_var = "varexo"
    } else {
        res_var = "var      "
    }

    fit_tag <- "fit;"

    input <- file(input_file, "r")
    output <- file(output_file, open = "a")
    if (step1) {
        fit_control_output <- file(fit_control_file, open = "a")
    }

    # initialisation
    fit_block_found <- FALSE
    model_block_found <- FALSE
    in_model <- FALSE

    while (TRUE) {
        line <- readLines(input, n = 1)
        if (length(line) == 0 ) {
            break
        }
        if (step1 && startsWith(trimws(line, "left"), "@#define")) {
            writeLines(line, con = fit_control_output)
        }
        if (!fit_block_found && startsWith(trimws(line, "left"), fit_tag)) {
            if (!step1) {
                writeLines(c("",
             "% Parameters for the standard deviation for the fit procedure:"),
                           con = output)
                param_lines <- paste("parameters", paste(fit_cond$sigmas,
                                    collapse = " "), ";", "")
                writeLines(strwrap(param_lines, width = 80), con = output)
                writeLines("", con = output)
            }
            fit_line <- gsub(fit_tag, "", line)
            ready <- FALSE
            while (!ready) {
                if (endsWith(trimws(fit_line, "right"), "end;")) {
                   fit_line <- gsub("end;", "", fit_line)
                   ready <- TRUE
                } 
                if (nchar(fit_line) > 0) {
                    parts <- stri_split_fixed(fit_line, "%", n = 2)[[1]]
                    fit_statement <- parts[1]
                    tmp <- gsub("residuals", res_var, fit_statement)
                    if (length(parts) == 2) {
                        tmp <- paste(tmp, "%", parts[2])
                    }
                    writeLines(tmp, con = output)
                    if (step1) {
                        writeLines(fit_statement, con = fit_control_output)
                    }
                }
                if (!ready) {
                   fit_line <- readLines(input, n = 1)
                   if (length(fit_line) == 0 ) {
                       break
                   }
               }
            }
            fit_block_found <- TRUE
        } else if (step1) {
            writeLines(line, con = output)
        } else if (!model_block_found && startsWith(line, "model")) {
            in_model <- TRUE
            lambda_lines <- paste("var", 
                              paste(fit_cond$l_vars, collapse = " "), ";", "")
            writeLines(strwrap(lambda_lines, width = 80), con = output)
            fit_lines <- paste("varexo", 
                         paste(fit_cond$fit_vars, collapse = " "), ";", "")
            writeLines(strwrap(fit_lines, width = 80), con = output)
            exo_lines <- paste("varexo", 
                          paste(fit_cond$exo_vars, collapse = " "), ";", "")
            writeLines(strwrap(exo_lines, width = 80), con = output)
            writeLines(c("", line, ""), con = output)
            writeLines(c("% Model equations", ""), con = output)
            model_found <- TRUE
        } else if (in_model && endsWith(trimws(line, "right"), "end;")) {
            writeLines(gsub("end;", "", line), con = output)
            writeLines(c("% First order condition the resisuals:", ""),
                       con = output)
            writeLines(strwrap(fit_cond$res_equations, width = 80),
                       con = output)
            writeLines(c("", "% First order conditions endogenous variables:",
                         ""), con = output)
            writeLines(strwrap(fit_cond$endo_equations, width = 80, exdent = 4),
                       con = output)
            writeLines("end;", con = output)
            in_model <- FALSE
        } else {
            writeLines(line, con = output)
        }
    }
    close(input)
    close(output)
    if (step1) {
        close(fit_control_output)
    }

    return(invisible(NULL))
}
