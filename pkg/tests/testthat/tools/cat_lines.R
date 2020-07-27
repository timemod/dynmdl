# Output a number of lines  the screen with cat.
cat_lines <- function(lines) {
  if (.Platform$OS.type == "windows") {
    lines <- gsub("\r\n", "\n", lines)
  } 
  return(cat(paste(lines, collapse = "\n")))
}
