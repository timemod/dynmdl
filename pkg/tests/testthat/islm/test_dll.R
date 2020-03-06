library(dynmdl)
library(testthat)
rm(list = ls())

context("ISLM model with dll option")

source("../tools/read_dynare_result.R")
source("utils.R")

mod_name <- "islm"

mdl <- make_mdl(mod_name, calc = "dll")
model_period <- mdl$get_period()
lag_per <- mdl$get_lag_period()

dynare_result <- read_dynare_result("islm", mdl)

test_that("solve", {
  mdl2 <- mdl$clone()
  expect_true(isTRUE(all.equal(mdl, mdl2)))
  mdl2 <- simul_islm(mdl2)
  expect_false(isTRUE(all.equal(mdl, mdl2)))
  expect_equal(dynare_result$endo, mdl2$get_endo_data(period = model_period))
  expect_error(mdl2$solve_perturbation(),
               paste("The perturbation approach currently only allows shocks",
                     "in the first period"))
})

test_that("solve_perturb", {
  mdl2 <- mdl$clone()
  mdl2$set_data(regts(1200, period = lag_per), names = "y")
  mdl2$set_data(regts(245, period = start_period(model_period)), names = "g")
  mdl2$solve(silent = TRUE)
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
  mdl2$put_static_endos()
  mdl2$set_endo_values(1200, names = "y", period = lag_per)
  # use a large shock, this should not matter if the model
  # is exactly linear
  mdl2$set_exo_values(280, period = start_period(model_period), names = "g")
  mdl2$solve(silent = TRUE)
  mdl3 <- mdl2$clone()
  mdl3$solve_perturbation()
  expect_equal(mdl2$get_endo_data(), mdl3$get_endo_data())
})

test_that("get_static_jacob and get_jacob", {
  mdl2 <- mdl$clone()
  mdl2$set_period("2015Q3/2015Q4")
  stat_jac <- mdl2$get_static_jacob()
  jac <- mdl2$get_jacob()
  expect_known_value(stat_jac,  "expected_output/islm_static_jac.rds")
  expect_known_value(jac,  "expected_output/islm_jac.rds")
})

test_that("steady state and eigenvalues", {
  
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
  check_report <- capture_output(mdl$check())
  
  eigvals <- mdl$get_eigval()
  expect_equal(eigvals[1:3], dynare_result$eigval[1:3, 1])
  expect_equal(is.finite(eigvals[4]), FALSE)
  
})



