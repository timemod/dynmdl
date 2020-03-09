library(dynmdl)
library(testthat)
rm(list = ls())
context("ISLM model with fit procedure with fit_fixed_period = TRUE")

rds_file <- "islm_model_fit.rds"
model_name <- "islm_fit"
fit_mod_file <- "mod_out/islm_fit_fixed_period.mod"

source("../tools/read_file.R")

# create two version of a FitMDl, one with and one without fit_fixed_period
report <- capture_output({
  mdl <- read_mdl(rds_file)
  mdl_fixed_per <- dyn_mdl(file.path("mod", paste0(model_name, ".mod")),
                           period = "2016Q1/2020Q2", calc = "internal",
                           fit_fixed_period = TRUE, fit_mod_file = fit_mod_file)
  mdl_fixed_per$solve_steady()
  mdl_fixed_per$put_static_endos()
})

test_that("generated fit mod file equal to reference ", {
  txt <- read_file(fit_mod_file)
  expect_known_output(cat(txt), 
                      file = "expected_output/fit_fixed_period_fmod_file.txt")
})

test_that("single fit target", {
  fit_per <- period_range("2016q1/2016q2")
  mdl_fixed_per$set_sigma(c(ut = 7, uc = 5, ui = -1, umd = -1))
  mdl_fixed_per$set_fit_values(1250, "y", period = fit_per)
  mdl_fixed_per$solve(silent = TRUE)
  expect_equal(mdl_fixed_per$get_endo_data(names = "y", period = fit_per),
               regts(rep(1250, 2), period = fit_per), check.attributes = FALSE)
  mdl_fixed_per$get_fit_instruments()
  # for the fixed model the fit instruments should be zero outside the
  # fit period
  expect_true(
    max(abs(mdl_fixed_per$get_fit_instruments(period = "2016q3/2020q3"))) < 
      1e-12)
})


test_that("2 targets and 2 instruments for all periods", {
  
  #
  # If the the number of fit instruments is equal to the number of fit targets
  # and the period range of all fit targets is equal to the model period,
  # the fix_fit_period should have no effect.
  # 
  
  fit_per <- mdl$get_period()
  sigmas <- c(sigma_uc = 5, sigma_umd = 1, sigma_ut = -1, sigma_ui = -1)
  
  mdl$init_data()
  expect_warning(mdl$set_param(sigmas))
  mdl$set_fit_values(1250, "y", period = fit_per)
  mdl$set_fit_values(3.5, "r", period = fit_per)
  mdl$solve(control = list(silent = TRUE))
  
  mdl_fixed_per$init_data()
  expect_warning(mdl_fixed_per$set_param(sigmas))
  mdl_fixed_per$set_fit(mdl$get_fit())
  mdl_fixed_per$solve(control = list(silent = TRUE))
  
  expect_equal(mdl$get_fit_instruments(), mdl_fixed_per$get_fit_instruments())
})

