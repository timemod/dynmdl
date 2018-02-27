library(testthat)
library(dynmdl)
rm(list = ls())

context("ISLM model with fit procedure and external functions and calc = \"internal\"")

source("../tools/read_dynare_result.R")

nperiods <- 18
mod_file <- "mod/islm_fit_extfunc2.mod"
dynare_dir     <- "dynare/output"

p1 <- period("2016Q1")
model_period <- period_range(p1, p1 + nperiods - 1)

square <<- function(x) {
  return(x * x)
}

square_d1 <<- function(x) {
  return(2*x);
}

square_d1_d1 <<- function(x) {
  return(2)
}


multiply <<- function(x, y) {
  return(x * y)
}

multiply_d1 <<- function(x, y) {
  return(y);
}

multiply_d2 <<- function(x, y) {
  return(x);
}

multiply_d1_d1 <<- function(x, y) {
  return(0);
}

report <- capture_output(mdl <- dyn_mdl(mod_file, calc = "internal"))
report2 <- capture_output(mdl$solve_steady())

mdl$set_period(model_period)
mdl$set_fit(regts(c(1250, 1255, 1260), start = "2016Q1"), names = "y")
mdl$set_fit(regts(c(250, 255), start = "2016Q1"), names = "t")
mdl$set_param(c(sigma_ut = 7, sigma_uc = 5, sigma_ui = 21, sigma_umd = 2))

mdl$solve(control = list(silent = TRUE))

dynare_result <- read_dynare_result("islm_fit", mdl)

test_that("dynare result equal to islm result", {
  p <- mdl$get_period()
  expect_equal(dynare_result$endo, mdl$get_endo_data(period = p))
})