library(dynmdl)
library(testthat)
rm(list = ls())
context("ISLM model with local variables and the dll option")

source("../tools/read_dynare_result.R")
source("utils.R")

mod_name <- "islm_local"

mdl <- make_mdl(mod_name, use_dll = TRUE)
model_period <- mdl$get_period()
lag_per <- mdl$get_lag_period()

dynare_result <- read_dynare_result("islm", mdl)

test_that("solve", {
  mdl2 <- simul_islm(mdl)
  expect_equal(dynare_result$endo, mdl2$get_endo_data(period = model_period))
  expect_error(mdl2$solve_perturbation(),
               paste("The perturbation approach currently only allows shocks",
                     "in the first period"))
})

test_that("solve_perturb", {
  mdl2 <- mdl$clone()
  mdl2$set_data(regts(1200, period = lag_per), names = "y")
  mdl2$set_data(regts(245, start = start_period(model_period)), names = "g")
  mdl2$solve(control = list(silent = TRUE))
  mdl3 <- mdl2$clone()
  mdl3$solve_perturbation()
  # note that the results are not exactly equal because of nonlinear terms
  expect_equal(mdl2$get_endo_data(), mdl3$get_endo_data(), tolerance = 1e-6)
})

test_that("solve_perturb linear model", {
  mdl2 <- mdl$clone()
  # set all non-linear parameters to 0
  mdl2$set_param(c(c5 = 0, i5 = 0, m3 = 0))
  mdl2$solve_steady(control = list(silent = TRUE))
  mdl2$set_data(regts(1200, period = lag_per), names = "y")
  # use a large shock, this should not matter if the model
  # is exactly linear
  mdl2$set_data(regts(280, start = start_period(model_period)), names = "g")
  mdl2$solve(control = list(silent = TRUE))
  mdl3 <- mdl2$clone()
  mdl3$solve_perturbation()
  expect_equal(mdl2$get_endo_data(), mdl3$get_endo_data())
})


