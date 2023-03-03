library(dynmdl)
library(testthat)

mod_file <- "mod/islm_error1.mod"

test_that("dyn_mdl gives an error", {
  msg <- paste("ERROR: mod/islm_error1.mod: line 16, col 1: variable x is not",
               "a declared parameter or variable.")
  capture_output(expect_error(dyn_mdl(mod_file), msg))
})
