library(dynmdl)
library(testthat)
rm(list = ls())

context("ISLM model")

source("../tools/read_dynare_result.R")
source("utils.R")

nperiods <- 18
model_name <- "islm"
mod_file <- file.path("mod", paste0(model_name, ".mod"))

p1 <- period("2011Q3")
model_period <- period_range(p1, p1 + nperiods - 1)

report <- capture_output(mdl <- islm_mdl(period = model_period))
labels <- mdl$get_labels()
lag_per <- mdl$get_lag_period()
dynare_result <- read_dynare_result(model_name, mdl)
dynare_endo <- update_ts_labels(dynare_result$endo, labels)

test_that("solve", {
  mdl2 <- simul_islm(mdl)
  expect_equal(dynare_endo, mdl2$get_endo_data(period = model_period))
  expect_error(mdl2$solve_perturbation(),
               paste("The perturbation approach currently only allows shocks",
                     "in the first period"))
  
  # set_exo_values / set_data with strange period", 
  p <- period_range("2007q3/2007q4")
  mdl2$set_exo_values(c(2500, 2600), names = "g", period = p)
  data <- regts(matrix(999,  ncol = 2), names = c("g", "y"),
                period = "2005q1")
  mdl2$set_data(data)
  
  expect_warning(mdl2$solve(control = list(silent = TRUE)), NA)
  expect_equal(mdl2$get_solve_status(), "OK")
  expect_equal(dynare_endo, mdl2$get_endo_data(period = model_period))
})

test_that("solve_perturb", {
  mdl2 <- mdl$clone()
  mdl2$set_data(regts(1200, period = lag_per), names = "y")
  mdl2$set_data(regts(245, period = start_period(model_period)), names = "g")
  report <- capture_output(mdl2$solve(control = list(trace = FALSE), 
                                      solver = "nleqslv"))
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
  mdl2$solve(control = list(silent = TRUE))
  mdl3 <- mdl2$clone()
  mdl3$solve_perturbation()
  expect_equal(mdl2$get_endo_data(), mdl3$get_endo_data())
})

test_that("steady state and eigenvalues", {
  
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
  check_report <- capture_output(mdl$check())
  
  eigvals <- mdl$get_eigval()
  expect_equal(eigvals[1:3], dynare_result$eigval[1:3, 1])
  expect_equal(is.finite(eigvals[4]), FALSE)
  
  eigval_data <- read.table(text = check_report, skip = 1, nrow = 4, 
                            header = TRUE)
  expect_equal(eigval_data$Real, Re(eigvals), tolerance = 1e-6)
  expect_equal(eigval_data$Imaginary, Im(eigvals), tolerance = 1e-6)
})

test_that("static_residual_check", {

  mdl2 <- mdl$copy()  
  res1a <- mdl2$static_residual_check()
  expect_equal(abs(unname(res1a)) < 1e-12, rep(TRUE, 7))
  expect_equal(names(res1a), paste0("eq_", 1:7))
  
  res1b <- mdl2$static_residual_check(tol = 1e-8)
  expect_equal(unname(res1b) , numeric(0))

  mdl2$set_static_exos(c(g = 250))
  res2a <- mdl2$static_residual_check()
  
  expected_res2 <- res1a
  expected_res2[1] <- -10
  expect_equal(res2a, expected_res2)
  
  res2b <- mdl2$static_residual_check(tol = 1e-8)
  expect_equal(res2b, expected_res2[1])

  mdl2$set_static_exos(c(g = 0/0, ms = 230.11))
  expected_result <- expected_res2
  expected_result[c("eq_1", "eq_7")] <- c(NaN, -0.11)
  
  expect_equal(mdl2$static_residual_check(), expected_result)
  expect_equal(mdl2$static_residual_check(tol = 0.1), expected_result[c(1, 7)])
  
  mdl2$set_static_exos(c(g = 1/0))
  expected_result["eq_1"] <- -Inf      
  expect_equal(mdl2$static_residual_check(), expected_result)
  expect_equal(mdl2$static_residual_check(tol = 0.1), expected_result[c(1, 7)])
  
  mdl2$set_static_exos(c(g = -1/0))
  expected_result["eq_1"] <- Inf      
  expect_equal(mdl2$static_residual_check(), expected_result)
  expect_equal(mdl2$static_residual_check(tol = 0.1), expected_result[c(1, 7)])
  
  mdl2$set_static_exos(c(g = NA))
  expected_result["eq_1"] <- NA      
  expect_equal(mdl2$static_residual_check(), expected_result)
  expect_equal(mdl2$static_residual_check(tol = 0.1), expected_result[c(1, 7)])
  expect_equal(mdl2$static_residual_check(tol = 100), expected_result[1])
})


test_that("residual_check", {
  
  mdl2 <- mdl$copy()  
  mp <- mdl2$get_period()
  
  res1a <- mdl2$residual_check()
  res1a_check <- res1a
  res1a_check[abs(res1a) < 1e-12] <- 0
  res1a_ref <- regts(matrix(0, ncol = 7), names = paste0("eq_", 1:7),
                     period = mp)
  
  expect_identical(res1a_check, res1a_ref)
  
  res1b <- mdl2$residual_check(tol = 1e-8)
  expect_equal(ncol(res1b), 0)
  expect_equal(get_period_range(res1b), mp)
  
  p <- period_range("2011q3/2011q4")
  mdl2$set_exo_values(c(250, 260), names = "g", period = p)

  res2a <- mdl2$residual_check()
  
  expected_res2 <- res1a_ref
  expected_res2[p, 1] <- c(-10, -20)
  expect_equal(res2a, expected_res2)
  
  res2b <- mdl2$residual_check(tol = 1e-8)
  expect_equal(res2b, expected_res2[p, 1, drop = FALSE])
})

