library(dynmdl)
library(testthat)
rm(list = ls())
context("ISLM model with fit procedure")

source("../tools/read_dynare_result.R")

rds_file <- "islm_model_fit.rds"
model_name <- "islm_fit"

report <- capture_output(mdl <- read_mdl(rds_file))
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
