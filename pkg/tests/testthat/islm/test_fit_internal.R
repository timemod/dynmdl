library(dynmdl)
library(testthat)
rm(list = ls())
context("ISLM model with fit procedure and calc = \"internal\"")

source("../tools/read_dynare_result.R")
source("utils.R")

model_name <- "islm_fit"

mod_file <- file.path("mod", paste0(model_name, ".mod"))
mdl <- dyn_mdl("mod/islm_fit.mod", calc = "internal",
                              period = "2016Q1/2020Q2", silent = TRUE)
mdl$solve_steady(control = list(trace = FALSE, silent = TRUE))
mdl$put_static_endos()

mdl$set_sigma(c(ut = 7, uc = 5, ui = 21, umd = 2))


mdl_old <- mdl$copy()

test_that("all.equal works correctly for fit models", {
  expect_true(isTRUE(all.equal(mdl, mdl_old)))
})

mdl$set_fit(regts(c(1250, 1255, 1260), start = "2016Q1"), names = "y")
mdl$set_fit(regts(c(250, 255), start = "2016Q1"), names = "t")

test_that("all.equal works correctly for fit models", {
  expect_false(isTRUE(all.equal(mdl, mdl_old)))
})

mdl$solve(silent = TRUE)

dynare_result <- read_dynare_result(model_name, mdl)
dynare_endo <- update_ts_labels(dynare_result$endo, mdl$get_labels())

test_that("dynare result equal to islm result", {
  p <- mdl$get_period()
  expect_equal(dynare_endo, mdl$get_endo_data(period = p))
})

test_that("steady state and eigenvalues", {
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
  report <- capture_output(mdl$check())
  expect_equal(mdl$get_eigval()[1:6], dynare_result$eigval[1:6, 1])
  expect_equal(is.finite(mdl$get_eigval()[7:8]), c(FALSE, FALSE))
})

test_that("static_residual_check", {
  
  mdl2 <- mdl$copy()
  
  res1 <- mdl2$static_residual_check()
  expect_equal(abs(unname(res1)) < 1e-12, rep(TRUE, 7))
  expect_equal(names(res1), paste0("eq_", 1:7))
  
  mdl2$set_static_exos(c(g = 250))
  res2a <- mdl2$static_residual_check()
  
  expected_res2 <- res1
  expected_res2[2] <- -10
  expect_equal(res2a, expected_res2)
  
  res2b <- mdl2$static_residual_check(tol = 1e-8)
  expect_equal(res2b, expected_res2[2])
  
  expected_result <- expected_res2
  
  mdl2$set_static_exos(c(g = 0/0, ms = 230.11))
  expected_result <- expected_res2
  expected_result[c("eq_2", "eq_7")] <- c(NaN, -0.11)
  
  expect_equal(mdl2$static_residual_check(), expected_result)
  expect_equal(mdl2$static_residual_check(tol = 0.1), expected_result[c(2, 7)])
  
  mdl2$set_static_exos(c(g = 1/0))
  expected_result["eq_2"] <- -Inf      
  expect_equal(mdl2$static_residual_check(), expected_result)
  expect_equal(mdl2$static_residual_check(tol = 0.1), expected_result[c(2, 7)])
  
  mdl2$set_static_exos(c(g = -1/0))
  expected_result["eq_2"] <- Inf      
  expect_equal(mdl2$static_residual_check(), expected_result)
  expect_equal(mdl2$static_residual_check(tol = 0.1), expected_result[c(2, 7)])
  
  mdl2$set_static_exos(c(g = NA_real_))
  expected_result["eq_2"] <- NA      
  expect_equal(mdl2$static_residual_check(), expected_result)
  expect_equal(mdl2$static_residual_check(tol = 0.1), expected_result[c(2, 7)])
  expect_equal(mdl2$static_residual_check(tol = 100), expected_result[2])
 
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
  
  p <- period_range("2016q1/2016q2")
  
  mdl2$set_exo_values(c(250, 260), names = "g", period = p)
  mdl2$set_endo_values(111, names = "l_1")
  
  res2a <- mdl2$residual_check()
  
  expected_res2 <- res1a_ref
  expected_res2[p, 2] <- c(-10, -20)
  expect_equal(res2a, expected_res2)
  
  res2b <- mdl2$residual_check(tol = 1e-8)
  expect_equal(res2b, expected_res2[p, 2, drop = FALSE])
})
