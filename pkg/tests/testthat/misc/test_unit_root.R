library(dynmdl)
library(testthat)

rm(list = ls())

context("model non_finite")

mod_file <- "mod/unit_root.mod"

model_period <- period_range("2018q1", "2018q1")

mdl <- dyn_mdl(mod_file, period = model_period, silent = TRUE)

test_that("solve_steady", {
  wmsg <- "The Jacobian is singular at iteration 1. The inverse condition is 0."
  expect_output(
    expect_warning(
      mdl$solve_steady(), 
      wmsg),
    wmsg)
  
  emsg <- paste("No steady state ... checking model is not possible.\nTo",
                "suppress this error, specify argument solve_steady = FALSE\\.")
  expect_warning(expect_error(mdl$check(), emsg), wmsg)
  expect_equal(mdl$get_solve_status(), "ERROR")
})

test_that("check with solve_steady = FALSE", {
  
  expect_output(
    expect_warning(expect_error(mdl$check(solve_steady = FALSE), NA), NA),
    "There are 0 eigenvalue")
  
  expect_equal(mdl$get_eigval(), c(0.25, 0.5, 1.0))
})