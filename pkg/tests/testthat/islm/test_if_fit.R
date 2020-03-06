library(dynmdl)
library(testthat)
rm(list = ls())
context("ISLM model with fit procedure and if statements")

source("../tools/read_dynare_result.R")

ifelse_jac <<- function(x, y, z) {
  if (x) {
    return(c(0, 1, 0))
  } else {
    return(c(0, 0, 1))
  }
}

ifelse_d1 <<- function(x, y, z) {
  return(list(0, c(0, 0, 0)))
}

ifelse_d2 <<- function(x, y, z) {
  val <- if (x) {
    1
  } else {
    0
  }
  return(list(val, c(0, 0, 0)))  
}

ifelse_d3 <<- function(x, y, z) {
  val <- if (x) {
    0
  } else {
    1
  }
  return(list(val, c(0, 0, 0)))  
}

nperiods <- 18
model_name <- "islm_if_fit"
mod_file <- file.path("mod", paste0(model_name, ".mod"))
p1 <- period("2016Q1")
model_period <- period_range(p1, p1 + nperiods - 1)

report <- capture_output(mdl <- dyn_mdl(mod_file))
report2 <- capture_output(mdl$solve_steady())
mdl$set_period(model_period)
mdl$set_fit(regts(c(1250, 1255, 1260), start = "2016Q1"), names = "y")
mdl$set_fit(regts(c(250, 255), start = "2016Q1"), names = "t")
mdl$set_param(c(sigma_ut = 7, sigma_uc = 5, sigma_ui = 21, sigma_umd = 2))

mdl$solve(silent = TRUE)

dynare_result <- read_dynare_result(model_name, mdl)

test_that("dynare result equal to islm result", {
  p <- mdl$get_period()
  expect_equal(dynare_result$endo, mdl$get_endo_data(period = p))
})
