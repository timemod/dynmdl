library(dynmdl)
library(testthat)
rm(list = ls())
context("solve_status")

mod_name <- "mod/islm.mod"

rep <- capture_output(mdl <- dyn_mdl(mod_name, period = "2018Q1/2019Q1"))

test_that("get_solve_status", {
  expect_identical(mdl$get_solve_status(), NA_character_)
  mdl$solve(control = list(silent = TRUE))
  expect_identical(mdl$get_solve_status(), "OK")
  mdl$set_endo_values(NA, names = "y", period = "2018Q1")
  msg <- "Initial value of function contains non-finite values \\(starting at index=1\\)"
  expect_known_output(expect_warning(mdl$solve(control = list(silent = TRUE), 
                                               homotopy = FALSE),
                 msg), file = "expected_output/solve_status1.txt")
  expect_identical(mdl$get_solve_status(), "ERROR")
  
  # with homotopy the model wil be solved
  expect_silent(mdl$solve(control = list(silent = TRUE)))
  expect_identical(mdl$get_solve_status(), "OK")
})