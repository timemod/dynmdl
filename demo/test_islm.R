library(dynparse)

mod_dir <- system.file("extdata", package = "dynparse")
mod_file <- file.path(mod_dir, "islm.mod")
ret <- compile_model(mod_file)
print(ret$symbols)
print(ret$dynmod$lead_lag_incidence)

f_dynamic <- function(y, x, params, it_, jac = FALSE) {}
body(f_dynamic) <- parse(text = paste0("{",
                                       ret$dynmod$dynamic_function_body, "}"))
print(f_dynamic)
