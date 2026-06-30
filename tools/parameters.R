#
# This script is used to check the dependencies for source files in
# directory pkg/src on the include files in pkg/src and pkg/src/macro.
# A dependency list is written file deps/deps.rds.

src_dir <- "pkg/src"
dep_rds <- "deps/deps.rds"
dep_file <- "pkg/src/makedeps"
dep_file_macro <- "pkg/src/macro/makedeps"
src_ext <- c("cc", "cpp") # possible extensions for source files
header_ext <- "hh" # possible extensions for header files
