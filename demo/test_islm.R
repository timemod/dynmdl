library(dynparse)

mod_file <-"demo/islm.mod"
mod_dir <- system.file("extdata", package = "dynparse")
mod_file_org <- file.path(mod_dir, "islm.mod")
file.copy(mod_file_org, mod_file)
ret <- compile_model(mod_file)
print(ret)
