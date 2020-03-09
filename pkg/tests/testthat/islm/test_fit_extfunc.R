library(testthat)
library(dynmdl)
rm(list = ls())

context("ISLM model with fit procedure and external functions")

source("../tools/read_dynare_result.R")

nperiods <- 18
mod_file <- "mod/islm_fit_extfunc.mod"
dynare_dir     <- "dynare/output"

p1 <- period("2016Q1")
model_period <- period_range(p1, p1 + nperiods - 1)

square <<- function(x) {
  return(list(x * x, 2 * x))
}

square_d1 <<- function(x) {
  return(square(x)[[2]])
}

square_d1_jac <<- function(x) {
  return(2)
}

multiply <<- function(x, y) {
  return(list(x * y, c(y, x)))
}

multiply_d1 <<- function(x, y) {
  return(list(y, c(0, 1)))
}

multiply_d2 <<- function(x, y) {
  return(x)
}

report <- capture_output(mdl <- dyn_mdl(mod_file))
report2 <- capture_output(mdl$solve_steady())

mdl$set_period(model_period)
mdl$set_fit(regts(c(1250, 1255, 1260), start = "2016Q1"), names = "y")
mdl$set_fit(regts(c(250, 255), start = "2016Q1"), names = "t")

test_that("set_param", {
  expect_silent(
    mdl$set_param(c(sigma_ut = 7, sigma_uc = 5, sigma_ui = 21, sigma_umd = 2)))

  expected_result <- c(ut = 7, uc = 5, umd = 2, ui = 21)
  names(expected_result) <- paste0("sigma_",  names(expected_result))
  expect_equal(mdl$get_sigmas(), expected_result)
})

mdl$solve(silent = TRUE)

dynare_result <- read_dynare_result("islm_fit", mdl)

test_that("dynare result equal to islm result", {
  p <- mdl$get_period()
  expect_equal(dynare_result$endo, mdl$get_endo_data(period = p))
})

test_that("steady state and eigenvalues", {
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
  report <- capture_output(mdl$check())
  expect_equal(mdl$get_eigval()[1:6], dynare_result$eigval[1:6, 1])
  expect_equal(is.finite(mdl$get_eigval()[7:8]), c(FALSE, FALSE))
})
