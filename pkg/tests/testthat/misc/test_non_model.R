library(dynmdl)
library(testthat)
context("non existing mod file")

test_that("create_mod gives an error", {
  capture_output(expect_error(dyn_mdl("non_existing.mod"),
                              "ERROR: Could not open file: non_existing.mod"))
  
  msg <- paste("ERROR: test_ifn.R: line 1, cols 1-7: variable library is not",
               "a declared parameter or variable.")
  capture_output(expect_error(dyn_mdl("test_ifn.R"), msg))
})
