rm(list = ls())

src_dir <- "pkg/src"
dep_rds <- "deps/deps.rds"

if (file.exists(dep_rds)) {
  deps <- readRDS(dep_rds)
  filenames <- list.files(src_dir, pattern = "\\.(cc|h|hh)$",
                          recursive = TRUE)
  if (!all(names(deps) %in% filenames)) {
    file.remove(dep_rds)
  }
}