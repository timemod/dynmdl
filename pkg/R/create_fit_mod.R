# Constructs a mod file for the fit procedure based on a mod file with
# special #FIT tags.
# @param mod_file the filename of the mod file with #FIT tags
# @return a list with the names of several auxiliary variables
create_fitmod <- function(mod_file, fit_mod) {

    tmp_mod <- tempfile()

    fit_tag <- "#FIT"
    ntag <- nchar(fit_tag)

    # collect all fit lines
    # create a model for the first step
    # (computation of model equations)
    con <- file(mod_file, "r")
    fit_lines <- character(0)
    sink(file = tmp_mod)
    while (TRUE) {
         line <- readLines(con, n = 1)
         if (length(line) == 0 ) {
             break
         }
         if (startsWith(line, fit_tag)) {
             fit_line <- trimws(substr(line, ntag + 1, nchar(line)))
             writeLines(gsub("residuals", "varexo", fit_line))
             fit_line <- strsplit(fit_line, "%")[[1]][1] # remove comment
             fit_lines <- c(fit_lines, fit_line)
         } else {
             writeLines(line)
         }
    }
    close(con)
    sink()

    # analyse #FIT line to find a list of residuals
    fit_txt <- paste(fit_lines, collapse = " ")
    cat("fit_txt\n")
    print(fit_txt)
    m <- gregexpr("residuals([^;]+)", fit_txt, perl = TRUE)
    ma <- regmatches(fit_txt, m)
    residuals <- strsplit(ma[[1]], split = " ")
    residuals <- setdiff(unlist(residuals), "residuals")

    cond <- get_fit_conditions(tmp_mod, residuals)

    # create the fit model
    sink(fit_mod)
    con <- file(mod_file, "r")
    in_model <- FALSE
    params_written <- FALSE
    while (TRUE) {
        line <- trimws(readLines(con, n = 1))
        if (length(line) == 0 ) {
            break
        }
        if (startsWith(line, fit_tag)) {
            if (!params_written) {
                writeLines(c("",
             "% Parameters for the standard deviation for the fit procedure:"))
                param_lines <- paste("parameters", paste(cond$sigmas, collapse = " "), ";", "")
                writeLines(strwrap(param_lines, width = 80))
                writeLines("")
                params_written <- TRUE
            }
            fit_line <- trimws(substr(line, ntag + 1, nchar(line)))
            writeLines(gsub("residuals", "var", fit_line))
            fit_line <- strsplit(fit_line, "%")[[1]][1] # remove comment
            fit_lines <- c(fit_lines, fit_line)
        } else {
            if (startsWith(line, "model")) {
                in_model <- TRUE
                lambda_lines <- paste("var", paste(cond$l_vars, collapse = " "), ";", "")
                writeLines(strwrap(lambda_lines, width = 80))
                fit_lines <- paste("varexo", paste(cond$fit_vars, collapse = " "), ";", "")
                writeLines(strwrap(fit_lines, width = 80))
                exo_lines <- paste("varexo", paste(cond$exo_vars, collapse = " "), ";", "")
                writeLines(strwrap(exo_lines, width = 80))
                writeLines("")
                writeLines(line)
                writeLines(c("", "% Model equations", ""))
            } else if (in_model && endsWith(line, "end;")) {
                writeLines(gsub("end;", "", line))
                writeLines(c("% First order condition the resisuals:", ""))
                writeLines(strwrap(cond$res_equations, width = 80))
                writeLines("")
                writeLines(c("", "% First order conditions endogenous variables:", ""))
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
        return (list(l_vars = l_vars, fit_vars = fit_vars,
                          exo_vars = exo_vars, sigmas = sigmas))
    })
}
