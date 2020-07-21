library(dynmdl)
library(testthat)
rm(list = ls())
context("ISLM model fit with static equations (1)")

source("../tools/read_file.R")
rds_file <- "islm_model_fit.rds"
model_name <- "islm_fit"

mdl_ref <- read_mdl(rds_file, silent = TRUE)

fit_steady <- c(y = 1300, i = 300)
mdl_ref$set_fit_steady(fit_steady)
mdl_ref$solve_steady(control = list(trace = TRUE, silent = TRUE))

model_name <- "islm_fit_static_eqs1"
mod_file <- file.path("mod", paste0(model_name, ".mod"))

fit_mod_file <- tempfile()

test_that("check_static_eqs = FALSE", {
  mdl <- dyn_mdl(mod_file, silent = TRUE, fit_mod_file = fit_mod_file,
                          check_static_eqs = FALSE)
  mdl$set_fit_steady(fit_steady)
  msg <- paste0("Solving the steady state not succesful\\.\n",
                "The Jacobian is singular at iteration 1\\.",
                " The inverse condition is 0\\.")
  expect_warning(mdl$solve_steady(silent = TRUE), msg)
  expect_equal(mdl$get_solve_status(), "ERROR")
  txt <- read_file(fit_mod_file)
  expect_known_output(cat(txt), 
                      file = "expected_output/fit_static_eqs1_fmod1.txt")
})

test_that("check_static_eqs = TRUE", {
  mdl <- dyn_mdl(mod_file, silent = TRUE, fit_mod_file = fit_mod_file)
  mdl$set_fit_steady(fit_steady)
  mdl$solve_steady(silent = TRUE)
  expect_equal(mdl$get_solve_status(), "OK")
  expected_result <- mdl_ref$get_all_static_data()
  expect_equal(mdl$get_all_static_data()[names(expected_result)], 
               expected_result)
  txt <- read_file(fit_mod_file)
  expect_known_output(cat(txt), 
                      file = "expected_output/fit_static_eqs1_fmod2.txt")
  
  mdl$set_period("2020")
  mdl$init_data()
  expect_equal(ncol(mdl$residual_check(tol = 1e-8)), 0)
  expect_equal(colnames(mdl$residual_check(tol = 1e-8, 
                                                    include_fit_eqs = TRUE)),
               "eq_19")
})

test_that("fit_fixed_period = TRUE", {
  mdl1 <- dyn_mdl(mod_file, silent = TRUE, check_static_eqs = FALSE,
                          fit_fixed_period = TRUE, fit_mod_file = fit_mod_file)
  mdl2 <- dyn_mdl(mod_file, silent = TRUE, check_static_eqs = TRUE,
                          fit_fixed_period = TRUE)
  expect_equal(mdl1$get_equations(), mdl2$get_equations())
  txt <- read_file(fit_mod_file)
  expect_known_output(cat(txt), 
                      file = "expected_output/fit_static_eqs1_fmod3.txt")
  mdl2$set_fit_steady(fit_steady)
  mdl2$solve_steady(silent = TRUE)
  expect_equal(mdl2$get_solve_status(), "OK")
  mdl2$set_period("2020")
  mdl2$init_data()
  expect_equal(ncol(mdl2$residual_check(tol = 1e-8, 
                                                include_fit_eqs = TRUE)), 0)
})