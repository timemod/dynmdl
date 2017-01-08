# Constructs a mod file for the fit procedure based on a mod file with
# special #FIT tags.
# @param mod_file the filename of the mod file with #FIT tags
# @param fit_mod the name of the file used for the fit procedure
# @return a list with the names of the auxiliary variables
#' @useDynLib dynr
create_fitmod <- function(mod_file, fit_mod) {

    tmp_mod          <- tempfile()
    fit_control_file <- tempfile()
    expanded_file    <- tempfile()

    fit_tag <- "fit;"
    write("% fit info", file = fit_control_file)

    # find the fit block
    con <- file(mod_file, "r")
    fit_lines <- character(0)
    sink(file = tmp_mod)
    fit_block_found <- FALSE
    ready <- FALSE
    while (TRUE) {
        line <- readLines(con, n = 1)
        if (length(line) == 0 ) {
            break
        }
        if (startsWith(trimws(line, "left"), "@#define")) {
            write(line, file = fit_control_file, append = TRUE)
        }
        if (!fit_block_found && startsWith(trimws(line, "left"), fit_tag)) {
            fit_line <- gsub(fit_tag, "", line)
            while (!ready) {
                if (endsWith(trimws(fit_line, "right"), "end;")) {
                   fit_line <- gsub("end;", "", fit_line)
                   ready <- TRUE
                } 
                # TODO: handle comment correctly (do not substitute 
                # residuals in the comment
                writeLines(gsub("residuals", "varexo   ", fit_line))
                # remove comment
                fit_line <- strsplit(fit_line, "%")[[1]][1] # remove comment
                write(fit_line, file = fit_control_file, append = TRUE)
                if (!ready) {
                   fit_line <- readLines(con, n = 1)
                   if (length(fit_line) == 0 ) {
                       break
                   }
               }
            }
            fit_block_found <- TRUE
        } else {
            writeLines(line)
        }
    }
    close(con)
    sink()

    run_macro(fit_control_file, expanded_file)

    # analyse #FIT line to find a list of residuals
    fit_txt <- paste(readLines(expanded_file), collapse = " ")
    m <- gregexpr("residuals([^;]+)", fit_txt, perl = TRUE)
    ma <- regmatches(fit_txt, m)
    residuals <- strsplit(ma[[1]], split = " ")
    residuals <- setdiff(unlist(residuals), "residuals")


    cond <- get_fit_conditions(tmp_mod, residuals)


    unlink(expanded_file)
    unlink(tmp_mod)

    # create the fit model
    sink(fit_mod)
    con <- file(mod_file, "r")
    in_model <- FALSE
    params_written <- FALSE
    fit_block_found <- FALSE
    ready <- FALSE
    while (TRUE) {
        line <- readLines(con, n = 1)
        if (length(line) == 0 ) {
            break
        }
        if (!fit_block_found && startsWith(trimws(line, "left"), fit_tag)) {
            if (!params_written) {
                writeLines(c("",
             "% Parameters for the standard deviation for the fit procedure:"))
                param_lines <- paste("parameters", paste(cond$sigmas,
                                         collapse = " "), ";", "")
                writeLines(strwrap(param_lines, width = 80))
                writeLines("")
                params_written <- TRUE
            }
            fit_line <- gsub(fit_tag, "", line)
            while (!ready) {
                if (endsWith(trimws(fit_line, "right"), "end;")) {
                   fit_line <- gsub("end;", "", fit_line)
                   ready <- TRUE
                } 
                # TODO: handle comment correctly (do not substitute 
                # residuals in the comment
                writeLines(gsub("residuals", "var   ", fit_line))
                if (!ready) {
                   fit_line <- readLines(con, n = 1)
                   if (length(fit_line) == 0 ) {
                       break
                   }
               }
            }
        } else {
            if (startsWith(line, "model")) {
                in_model <- TRUE
                lambda_lines <- paste("var", 
                            paste(cond$l_vars, collapse = " "), ";", "")
                writeLines(strwrap(lambda_lines, width = 80))
                fit_lines <- paste("varexo", 
                            paste(cond$fit_vars, collapse = " "), ";", "")
                writeLines(strwrap(fit_lines, width = 80))
                exo_lines <- paste("varexo", 
                            paste(cond$exo_vars, collapse = " "), ";", "")
                writeLines(strwrap(exo_lines, width = 80))
                writeLines("")
                writeLines(line)
                writeLines(c("", "% Model equations", ""))
            } else if (in_model && endsWith(trimws(line, "right"), "end;")) {
                writeLines(gsub("end;", "", line))
                writeLines(c("% First order condition the resisuals:", ""))
                writeLines(strwrap(cond$res_equations, width = 80))
                writeLines("")
                writeLines(c("", 
                    "% First order conditions endogenous variables:", ""))
                writeLines(strwrap(cond$endo_equations, width = 80, exdent = 4))
                writeLines("end;")
                in_model <- FALSE
            } else {
                writeLines(line)
            }
        }
    }
    close(con)
    sink()

    # return information about the fit variables
    with (cond, {
        return (list(orig_endos = vars, orig_exos = orig_exos, 
                     l_vars = l_vars, fit_vars = fit_vars,
                     exo_vars = exo_vars, residuals = residuals, 
                     sigmas = sigmas))
    })
}
