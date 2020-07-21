library(dynmdl)
library(testthat)
rm(list = ls())
context("ISLM model with trends")

source("../tools/read_file.R")

model_name <- "islm_fit"

fit_steady <- c(y = 1300, i = 300)

model_name <- "islm_trend"
mod_file <- file.path("mod", paste0(model_name, ".mod"))



test_that("check_static_eqs = TRUE", {
  expect_error(mdl <- dyn_mdl(mod_file, silent = TRUE, fit_mod_file = "aap",
                              check_static_eqs = FALSE),
               "For models with trends,")
  expect_warning(
    messages <- capture.output(mdl <- dyn_mdl(mod_file, silent = TRUE,  
                                              check_static_eqs = TRUE, 
                                              debug = TRUE), 
                               type = "message")
  )
  fit_mod_file <- tempfile()
  expect_true(file.copy("fitmod.mod", fit_mod_file))
  expect_true(file.remove("fitmod.mod"))
  expect_true(file.remove("preprocessed.mod"))
  mdl$set_fit_steady(fit_steady)
  mdl$solve_steady(silent = TRUE)
  expect_equal(mdl$get_solve_status(), "OK")
  txt <- read_file(fit_mod_file)
  expect_known_output(cat(txt), 
                      file = "expected_output/islm_trend_fmod1.txt")
  
  mdl$set_period("2020")
  mdl$init_data()
  expect_equal(ncol(mdl$residual_check(tol = 1e-8)), 0)
  expect_equal(colnames(mdl$residual_check(tol = 1e-8, 
                                                    include_fit_eqs = TRUE)),
               "eq_19")
})
test_that("fit_fixed_period = TRUE", {
  expect_warning(
    messages <- capture.output(mdl <- dyn_mdl(mod_file, silent = TRUE,  
                                              check_static_eqs = TRUE,
                                              fit_fixed_period = TRUE,
                                              debug = TRUE), 
                               type = "message")
  )
  fit_mod_file <- tempfile()
  expect_true(file.copy("fitmod.mod", fit_mod_file))
  expect_true(file.remove("fitmod.mod"))
  expect_true(file.remove("preprocessed.mod"))
  mdl$set_fit_steady(fit_steady)
  mdl$solve_steady(silent = TRUE)
  expect_equal(mdl$get_solve_status(), "OK")
  txt <- read_file(fit_mod_file)
  expect_known_output(cat(txt), 
                      file = "expected_output/islm_trend_fmod2.txt")
  
  mdl$set_period("2020")
  mdl$init_data()
  expect_equal(ncol(mdl$residual_check(tol = 1e-8, include_fit_eqs = TRUE)), 0)
})

