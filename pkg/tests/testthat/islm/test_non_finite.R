library(dynmdl)
library(testthat)

rm(list = ls())

context("ISLM model with non finite residuals")

rep <- capture_output(mdl <- read_mdl("islm_model.rds"))

test_that("single period", {
  mdl$set_exo_values(NA, names = "g", period = "2015q1/2015Q2")
  mdl$set_endo_values(NaN, names = "t", period = "2015Q2")
 
  msg <- paste("Initial value of function contains non-finite values",
              "\\(starting at index=1\\)")
  expect_silent(expect_warning(mdl$solve(silent = TRUE), msg))
  expect_known_output(expect_warning(mdl$solve(control = list(silent = FALSE), 
                                               homotopy = FALSE), 
                               msg),
                      file = "expected_output/non_finite1.txt")
})

test_that("multiple periods", {
  mdl$set_exo_values(-Inf, names = "g", period = "2015q2/2015Q3")
  mdl$set_endo_values(Inf, names = "t", period = "2016Q3")
  mdl$set_endo_values(Inf, names = "y", period = "2016Q3")
  
  msg <- paste("Initial value of function contains non-finite values",
               "\\(starting at index=1\\)")
  expect_known_output(expect_warning(mdl$solve(control = list(silent = FALSE)), 
                                     msg), 
                      file = "expected_output/non_finite2.txt")
})