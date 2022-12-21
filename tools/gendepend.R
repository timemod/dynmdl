library(igraph)
library(stringr)
library(tictoc)

rm(list = ls())

src_dir <- "pkg/src"
dep_rds <- "deps/deps.rds"

read_includes <- function(filename, is_macro_dir = FALSE) {
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

get_dep_list <- function(filenames, is_macro_dir = FALSE) {
  if (is_macro_dir) filenames <- paste0("macro/", filenames)
  retval <- lapply(filenames, FUN = read_includes,
                   is_macro_dir = is_macro_dir)
  names(retval) <- filenames
  return(retval)
}

# create dependency structure from scratch
create_deps <- function() {
  
  # get dependencies of data in directory pkg/src
  src_files <- list.files(src_dir, pattern = "\\.cc$")
  header_files <- list.files(src_dir, pattern = "\\.hh$")
  all_files <- c(src_files, header_files)
  deps <- get_dep_list(all_files)
  
  # also get dependencies of macro header files
  macro_header_files <- list.files(file.path(src_dir, "macro"), 
                                   pattern = "\\.hh$")
  macro_header_deps <- get_dep_list(macro_header_files, is_macro_dir = TRUE)
  
  deps <- c(deps, macro_header_deps)

  # remove unnessary dependencies 
  is_null <- sapply(deps, FUN = is.null)
  return(deps[!is_null])
}

tic("creating dependency information")
deps <- create_deps()
toc()

saveRDS(deps, dep_rds)