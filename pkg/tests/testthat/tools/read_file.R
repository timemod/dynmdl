read_file <- function(filename) {
  text <- readChar(filename, nchars = file.size(filename), useBytes = TRUE)
  Encoding(text) <- "latin1"
  # remove carriage return
  text <- gsub("\\r", "", text)
  return(text)
}

  
  
  