library(dynmdl)
library(testthat)

rm(list = ls())

source("../tools/read_dynare_result.R")

context("ISLM fit and exogenous lag")

mod_file <- "mod/islm_fit_exolag1.mod"
fit_mod_file <- "mod_out/islm_fit_exolag1.mod"
fit_target_csv <- "input/islm_fit_targets.csv"

# prepare model
dum <- capture_output(
  mdl <- dyn_mdl(mod_file, fit_mod_file = fit_mod_file, 
                 period = "2017Q1/2021Q2"))

mdl$set_exo_values(250, names = "g", period = "2017Q1")
fit_targets <- read_ts_csv(fit_target_csv)
mdl$set_fit(fit_targets)

dynare_result <- read_dynare_result("islm_fit_exolag1", mdl)

test_that("solve_steady", {
  mdl$solve_steady(control = list(trace = FALSE, silent = TRUE))
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
})

mdl$put_static_endos()

test_that("eigenvalues", {
  dum <- capture_output(mdl$check())
  eigval <- mdl$get_eigval()
  
  # the last two eigenvalues are Inf or almost infinite
  sel <- -c(7, 8)
  expect_equal(Re(eigval[sel]), dynare_result$eigval[sel , 1], 
               tolerance = 1e-5)
  expect_equal(abs(Im(eigval)), abs(dynare_result$eigval[ , 2]),
               tolerance = 1e-5)
})

test_that("solve", {
  mdl$solve(control = list(silent = TRUE, trace = FALSE))
  expect_equal(mdl$get_endo_data(period = mdl$get_period()), 
               dynare_result$endo, fun = cvgdif, tol = 1e-8)
})


test_that("error when there are fit instruments with lags and leads", {
  
  mod_file <- "mod/islm_fit_exolag2.mod"
  msg <- "There are fit instruments with lags or leads: uc."
  dum <- capture_output(expect_error(mdl2 <- dyn_mdl(mod_file), msg))
  
  mod_file <- "mod/islm_fit_exolag3.mod"
  msg <- "There are fit instruments with lags or leads: ut, umd."
  dum <- capture_output(expect_error(mdl2 <- dyn_mdl(mod_file), msg))
})