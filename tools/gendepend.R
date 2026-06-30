#
# This script is used to check the dependencies for source files in
# directory pkg/src on the include files in pkg/src and pkg/src/macro.
# A dependency list is written file deps/deps.rds.

library(igraph)
library(stringr)
library(tictoc)

rm(list = ls())

source("tools/parameters.R")

#' Returns included header files in a C-file or another header file.
#'
#' @param filename Character of length 1: the relative path of the file (relative
#' to `src_dir`).
#' @param src_dir The directory with source files (pkg_src_dir) 
#'
#' @return A character vector with the names of the included header files 
#' (the relative path with respect to `src_dir`), or `NULL` if the files not
#' have any dependencies.
#' 
#' @noRd
read_includes <- function(filename, src_dir) {
  src_path <- file.path(src_dir, filename)
  
  lines <- readLines(src_path, warn = FALSE)
  if (length(lines) == 0L) return(NULL)
  
  # Lines that look like include directives (quick filter)
  inc_lines <- grep("^\\s*#\\s*include\\s+", lines, value = TRUE, perl = TRUE)
  if (length(inc_lines) == 0L) return(NULL)
  
  # Quoted includes: #include "some/path.h"
  quoted <- grep('^\\s*#\\s*include\\s+"([^"]+)"', inc_lines, value = TRUE,
                 perl = TRUE) 
  if (length(quoted) > 0) {
    quoted <- sub('^\\s*#\\s*include\\s+"([^"]+)".*$', '\\1',
                  quoted, perl = TRUE)
  }
  
  # Special-case FlexLexer.h in angle brackets: #include <FlexLexer.h>
  flex_mask <- grepl('<\\s*FlexLexer\\.h\\s*>', inc_lines, perl = TRUE)
  flex <- if (any(flex_mask)) "FlexLexer.h" else character(0)
  
  # If the source file is inside macro/, prefix quoted includes that are not already prefixed
  if (startsWith(filename, "macro/") && length(quoted) > 0L) {
    pref_mask <- startsWith(quoted, "macro/")
    quoted[!pref_mask] <- paste0("macro/", quoted[!pref_mask])
  }
  
  # Keep quoted includes only if they exist under src_dir (preserve original behavior)
  if (length(quoted) > 0L) {
    exists_mask <- file.exists(file.path(src_dir, quoted))
    quoted <- quoted[exists_mask]
  }
  
  # Combine and return unique includes in encounter order
  includes <- c(quoted, flex)
  if (length(includes) == 0L) return(NULL)
  includes <- unique(includes)
  return(includes)
}

update_deps <- function(deps, filenames, src_dir) {
  
  deps_new <- lapply(filenames, FUN = read_includes, src_dir = src_dir)
  names(deps_new) <- filenames
  
  deps[names(deps_new)] <- deps_new

  # remove files wiithout dependencies
  is_null <- sapply(deps, FUN = is.null)
  return(deps[!is_null])
}

if (interactive() || !file.exists(dep_rds)) {

  #
  # This script is run from RStudio or the dep_rds file
  # does not exist.
  #

  pattern <- paste0("\\.(",
                    paste(c(src_ext, header_ext), collapse = "|"),
                    ")$")
  filenames <- list.files(src_dir, pattern = pattern, recursive = TRUE)

  cat("\nAnalyzing dependencies of c++ files on header files\n\n")

  deps <- list()

} else {

  # This script is called from the makefile Makedeps,
  # The command line arguments are the names of the files
  # that are newer than the dep_rds file.


  filenames <- commandArgs(trailingOnly = TRUE)
  pattern <- paste0("^", src_dir, "/")
  pattern <- sub("/", "(/|\\\\\\\\)", pattern)
  filenames <- sub(pattern, "", filenames)

  cat("\nUpdating dependencies of C++ files on header files:\n",
      paste(filenames, collapse = "\n"), "\n\n")

  deps <- readRDS(dep_rds)
}

tic("Analyzing dependencies")
deps <- update_deps(deps, filenames, src_dir = src_dir)
toc()

saveRDS(deps, dep_rds)
