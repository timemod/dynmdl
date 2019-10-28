write_mod_file_internal <- function(mod_file, mdldef, equations, model_options) {
  
  
  if (is.null(equations)) {
    stop(paste("Methods solve_steady_dynare and solve_dynare cannot be used",
               "for DynMdl object created with dynmdl version < 1.0."))
  }
  
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
  if (missing(model_options) || length(model_options) == 0) {
    writeLines("\nmodel;", con = output)
  } else {
    writeLines(paste0("\nmodel(", get_dynare_option_string(model_options), 
                      ");"), con = output)
  }
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