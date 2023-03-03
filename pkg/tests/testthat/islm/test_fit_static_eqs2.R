library(dynmdl)
library(testthat)
rm(list = ls())

source("../tools/read_file.R")
rds_file <- "islm_model_fit.rds"
update_expected_output <- FALSE

mdl_ref <- read_mdl(rds_file, silent = TRUE)

fit_steady <- c(y = 1300, i = 300)
mdl_ref$set_fit_steady(fit_steady)
mdl_ref$solve_steady(control = list(trace = TRUE, silent = TRUE))

model_name <- "islm_fit_static_eqs2"
mod_file <- file.path("mod", paste0(model_name, ".mod"))

fit_mod_file <- tempfile()

test_that("fit_fixed_period = TRUE", {
  mdl <- dyn_mdl(mod_file, silent = TRUE, check_static_eqs = TRUE,
                          fit_fixed_period = TRUE, fit_mod_file = fit_mod_file)
  txt <- read_file(fit_mod_file)
  expect_known_output(cat(txt), 
                      file = "expected_output/fit_static_eqs2_fmod2.txt",
                      update = update_expected_output)
  mdl$set_fit_steady(fit_steady)
  mdl$solve_steady(silent = TRUE)
  expect_equal(mdl$get_solve_status(), "OK")
  mdl$set_period("2020")
  mdl$init_data()
  expect_null(mdl$residual_check(tol = 1e-8))
  expect_equal(colnames(mdl$residual_check(tol = 1e-8, 
                                           include_fit_eqs = TRUE)),
               "eq_14")
})
