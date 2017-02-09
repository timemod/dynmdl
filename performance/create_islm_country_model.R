create_islm_country_model <-  function(input_file, output_file, nextra) {

    input <- file(input_file)
    output <- file(output_file, open = 'w')

    countries <- paste("co", as.character(1:nextra), sep = "_")
    countries <- paste0("\"", countries, "\"")
    country_line <- paste0("@#define countries = [",
                           paste(countries, collapse = ", "), "]")
    mod_lines <- readLines(input)
    mod_lines <- c(country_line, mod_lines)
    writeLines(mod_lines, con = output)

    close(output)
    close(input)

    return(invisible(NULL))
}
