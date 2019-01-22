library(dynmdl)
library(testthat)

rm(list = ls())

context("ISLM model get_equations")

report <- capture_output(mdl <- read_mdl("islm_model.rds"))
report <- capture_output(mdl_fit <- read_mdl("islm_model_fit.rds"))

test_that("get_equations works correctly", {
  
  eqs <- mdl$get_equations()
  expect_known_output(eqs, "expected_output/eqs.txt", print = TRUE)
  
  eqs_fit <- mdl_fit$get_equations()
  
  if (.Platform$OS.type == "windows") {
    eqs_fit_tmp <- gsub("\r\n", "\n", eqs_fit)
  } else {
    eqs_fit_tmp <- eqs_fit
  }
  expect_known_output(eqs_fit, "expected_output/eqs_fit.txt", print = TRUE)
  
  expect_equal(eqs[3], mdl$get_equations(3))
  expect_equal(eqs_fit[c(3,16)], mdl_fit$get_equations(i = c(3,16)))
})


