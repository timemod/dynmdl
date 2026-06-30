#
# Generate makedeps file in directory pkg/src and pkg/src/macro.
#

library(igraph)
library(stringr)
library(tictoc)

rm(list = ls())

source("tools/parameters.R")
source("tools/create_makedeps_functions.R")

pattern <- paste0("\\.(",
                  paste(c(src_ext, header_ext), collapse = "|"),
                  ")$")
filenames <- list.files(src_dir, pattern = pattern, recursive = TRUE)

cat("===========================================================\n")
cat("Analyzing dependencies of c++ files on header files\n")
cat("===========================================================\n\n")

tic("Analyzing dependencies")
deps <- get_dep_list(deps, filenames, src_dir = src_dir)
toc()

tic("construct depenency graph")
# build flat edge lists:
to <- rep(names(deps), lengths(deps))
from   <- unlist(deps, use.names = FALSE)
edges_df <- unique(data.frame(from = from, to = to, stringsAsFactors = FALSE))
g <- graph_from_data_frame(edges_df, directed = TRUE)
toc()

tic("writing dep_file")

src_pattern <- paste0("\\.(",  paste(src_ext, collapse = "|"), ")$")
src_files <- grep(src_pattern, names(deps), value = TRUE)
src_files <- sort(src_files)

is_macro_file <- startsWith(src_files, "macro/")

write_dep_file(
  src_files = src_files[!is_macro_file],
  dep_file = dep_file,
  g = g
)
write_dep_file(
  src_files = src_files[is_macro_file],
  dep_file = dep_file_macro,
  g = g,
  is_macro = TRUE
)

toc()

cat("===========================================================\n\n")
