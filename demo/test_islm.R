library(dynparse)

mod_dir <- system.file("extdata", package = "dynparse")
mod_file <- file.path(mod_dir, "islm.mod")
ret <- compile_model(mod_file)
print(ret$symbols)
print(ret$dynamic_model$lead_lag_incidence)
print(ret$dynamic_model$maximum_endo_lag)

f_dynamic <- function(y, x, params, it_, jac = FALSE) {}
body(f_dynamic) <- parse(text = paste0("{",
                                       ret$dynamic_model$dynamic_function_body, "}"))
print(f_dynamic)

f_static <- function(y, x, params, jac = FALSE) {}
body(f_static) <- parse(text = paste0("{",
                                       ret$static_function_body, "}"))
print(f_static);
