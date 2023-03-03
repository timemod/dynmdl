library(dynmdl)
library(testthat)
rm(list = ls())

source("../tools/read_file.R")
rds_file <- "islm_model_fit.rds"

mdl_ref <- read_mdl(rds_file, silent = TRUE)

fit_steady <- c(y = 1300, i = 300)
mdl_ref$set_fit_steady(fit_steady)
mdl_ref$solve_steady(control = list(trace = TRUE, silent = TRUE))

model_name <- "islm_fit_static_eqs3"
mod_file <- file.path("mod", paste0(model_name, ".mod"))


mdl <- dyn_mdl(mod_file, silent = TRUE)
mdl_fixper <- dyn_mdl(mod_file, silent = TRUE, check_static_eqs = TRUE,
                     fit_fixed_period = TRUE)

test_that("two models are equivalent", {
  mdl$set_fit_steady(fit_steady)
  mdl$solve_steady(silent = TRUE)
  mdl_fixper$set_fit_steady(fit_steady)
  mdl_fixper$solve_steady(silent = TRUE)
  expect_equal(mdl$get_all_static_data(), mdl_fixper$get_all_static_data())
})

test_that("error", {
  
  model_name <- "islm_fit_static_eqs3_err"
  mod_file <- file.path("mod", paste0(model_name, ".mod"))
  
  expect_silent(mdl <- dyn_mdl(mod_file, silent = TRUE, check_static_eqs = FALSE))
  
  expect_error(mdl <- dyn_mdl(mod_file, silent = TRUE, check_static_eqs = TRUE),
               "The following fit instruments do not occur in the static model equations: uc, ui.")
})
