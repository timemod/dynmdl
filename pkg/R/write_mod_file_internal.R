write_mod_file_internal <- function(mod_file, mdldef, equations) {
  
  #
  # local functions
  #
  write_declarations <- function(type, names) {
    
    text <- paste0(type, " ", paste(names, collapse = " "), ";")
    text <- strwrap(text, width = 80, exdent = nchar(type) + 1)
    writeLines(text, con = output)
    return()
  }
  
  write_initialisations <- function(values) {
    statements <- paste0(names(values), " = ", values, ";")
    statements <- paste(statements, collapse = " ")
    statements <- strwrap(statements, width = 80)
    writeLines(statements, con = output)
    return()
  }
  
  output <- file(mod_file, open = "w")
  
  #
  #
  write_declarations("parameters", names(mdldef$params))
  writeLines("", con = output)
  write_initialisations(mdldef$params)
  
  #
  # exo declarations
  #
  
  writeLines("", con = output)  
  write_declarations("varexo", names(mdldef$exos))
  
  # 
  # endo declarations
  #
  
  writeLines("", con = output)
  write_declarations("var", names(mdldef$endos))
  
  #
  # model
  #
  writeLines("\nmodel;", con = output)
  for (eq in equations) {
    eq <- paste0(eq, ";")
    eq_lines <- strsplit(eq, "(\\\\r)?\\\\n")[[1]]
    writeLines(eq_lines, con = output)
  }
  writeLines("end;", con = output)
  
  #
  # initval
  #
  writeLines("\ninitval;", con = output)
  values <- c(mdldef$endos, mdldef$exos)
  values <- values[order(names(values))]
  write_initialisations(values)
  writeLines("end;", con = output)
  
  close(output)
  

  return()
}