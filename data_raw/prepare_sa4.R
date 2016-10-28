library(dynr)

mod_file <- system.file("extdata", "sa4.mod", package = "dynr")
print(system.time(sa4_mdl <- compile_model(mod_file)))

devtools::use_data(sa4_mdl, overwrite = TRUE)
