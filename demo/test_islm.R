library(dynparse)

mod_dir <- system.file("extdata", package = "dynparse")
mod_file <- file.path(mod_dir, "islm.mod")
ret <- compile_model(mod_file)
print(ret)
