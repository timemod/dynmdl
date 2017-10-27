library(dynmdl)
library(testthat)

context("get_equations")

report <- capture_output(mdl <- read_mdl("islm_model.rds"))
report <- capture_output(mdl_fit <- read_mdl("islm_model_fit.rds"))

test_that("get_equations works correctly", {
  eqs <- mdl$get_equations()
  eqs_fit <- mdl_fit$get_equations()
  
  expect_equal_to_reference(eqs, "expected_output/eqs.rds")

  if (.Platform$OS.type == "windows") {
    eqs_fit_tmp <- gsub("\r\n", "\n", eqs_fit)
  }
  expect_equal_to_reference(eqs_fit_tmp, "expected_output/eqs_fit.rds")
  
  expect_equal(eqs[3], mdl$get_equations(3))
  expect_equal(eqs_fit[c(3,16)], mdl_fit$get_equations(i = c(3,16)))
})


