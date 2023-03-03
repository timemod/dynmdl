library(dynmdl)
library(testthat)
rm(list = ls())

mod_name <- "mod/islm.mod"
update_expected_output <- FALSE

rep <- capture_output(mdl <- dyn_mdl(mod_name, period = "2018Q1/2019Q1"))

test_that("get_solve_status", {
  expect_identical(mdl$get_solve_status(), NA_character_)
  mdl$solve(silent = TRUE)
  expect_identical(mdl$get_solve_status(), "OK")
  mdl$set_endo_values(NA, names = "y", period = "2018Q1")
  msg <- "Initial value of function contains non-finite values \\(starting at index=1\\)"
  expect_known_output(expect_warning(mdl$solve(silent = TRUE, homotopy = FALSE),
                 msg), file = "expected_output/solve_status1.txt",
                 update = update_expected_output)
  expect_identical(mdl$get_solve_status(), "ERROR")
  
  # with homotopy the model wil be solved
  expect_silent(mdl$solve(silent = TRUE))
  expect_identical(mdl$get_solve_status(), "OK")
})
