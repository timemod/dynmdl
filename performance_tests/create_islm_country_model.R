create_islm_country_model <-  function(input_file, output_file, nextra) {

    basis_countries <- c("nl", "uk", "be", "ge", "fr", "es", "dk", "us", "it",
                         "ch", "se", "no", "fi", "ir", "in", "jp", "ru", "pt",
                         "po", "au")

    input <- file(input_file)
    output <- file(output_file, open = 'w')

    extra_countries <- paste("co", as.character(1:nextra), sep = "_")
    countries <- c(basis_countries, extra_countries)

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
