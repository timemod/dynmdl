library(igraph)
library(stringr)
library(tictoc)

rm(list = ls())

src_dir <- "pkg/src"
dep_rds <- "deps/deps.rds"

read_includes <- function(filename, src_dir, is_macro_dir = FALSE) {
  include_pattern <- "^#\\s*include\\s+\"(.+)\""
  lines <- readLines(file.path(src_dir, filename))
  includes <- character(0)
  for (line in lines) {
    ma <- str_match(line, include_pattern)
    include <- ma[, 2]
    if (!is.na(include)) {
      if (is_macro_dir) include <- paste0("macro/", include)
      if (file.exists(file.path(src_dir, include))) {
        includes <- c(includes, include)
      }
    }
  }
  if (length(includes) == 0) {
    return(NULL) 
  } else {
    return(includes)
  }
  return(includes)
}

get_dep_list <- function(filenames, src_dir, is_macro_dir = FALSE) {
  retval <- lapply(filenames, FUN = read_includes,
                   src_dir = src_dir, is_macro_dir = is_macro_dir)
  names(retval) <- filenames
  return(retval)
}

update_deps <- function(deps, filenames, src_dir) {
  
  is_macro_file <- grepl("^macro/", filenames)
  
  macro_files <- filenames[is_macro_file]
  other_files <- filenames[!is_macro_file]
  
  # for macrk-files we only need header files
  macro_files <-grep("\\.(h|hh)$", macro_files, value = TRUE)
 
  if (length(macro_files) > 0) {
    macro_deps <- get_dep_list(macro_files, src_dir = src_dir,
                               is_macro_dir = TRUE)
    deps[names(macro_deps)] <- macro_deps
  }
  if (length(other_files) > 0) {
    other_deps <- get_dep_list(other_files, src_dir = src_dir,
                               is_macro_dir = FALSE)
    deps[names(other_deps)] <- other_deps
  }
  
  # remove unnessary dependencies 
  is_null <- sapply(deps, FUN = is.null)
  return(deps[!is_null])
}

if (interactive() || !file.exists(dep_rds)) {
  
  filenames <- list.files(src_dir, pattern = "\\.(cc|cpp|h|hh)$",
                          recursive = TRUE)
  
  cat("\nAnalyzing dependencies of c++ files on header files\n\n")
  
  deps <- list()
  
} else {
  
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