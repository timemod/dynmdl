library(dynmdl)
library(testthat)
rm(list = ls())
context("ISLM model with fit procedure and calc = \"internal\"")

source("../tools/read_dynare_result.R")
source("utils.R")

model_name <- "islm_fit"

mod_file <- file.path("mod", paste0(model_name, ".mod"))
rep <- capture_output(mdl <- dyn_mdl("mod/islm_fit.mod", calc = "internal",
                              period = "2016Q1/2020Q2"))
mdl$solve_steady(control = list(trace = FALSE, silent = TRUE))
mdl$put_static_endos()

mdl$set_param(c(sigma_ut = 7, sigma_uc = 5, sigma_ui = 21, sigma_umd = 2))


mdl_old <- mdl$copy()

test_that("all.equal works correctly for fit models", {
  expect_true(isTRUE(all.equal(mdl, mdl_old)))
})

mdl$set_fit(regts(c(1250, 1255, 1260), start = "2016Q1"), names = "y")
mdl$set_fit(regts(c(250, 255), start = "2016Q1"), names = "t")

test_that("all.equal works correctly for fit models", {
  expect_false(isTRUE(all.equal(mdl, mdl_old)))
})

mdl$solve(control = list(silent = TRUE))

dynare_result <- read_dynare_result(model_name, mdl)
dynare_endo <- update_ts_labels(dynare_result$endo, mdl$get_labels())

test_that("dynare result equal to islm result", {
  p <- mdl$get_period()
  expect_equal(dynare_endo, mdl$get_endo_data(period = p))
})

test_that("steady state and eigenvalues", {
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
  report <- capture_output(mdl$check())
  expect_equal(mdl$get_eigval()[1:6], dynare_result$eigval[1:6, 1])
  expect_equal(is.finite(mdl$get_eigval()[7:8]), c(FALSE, FALSE))
})