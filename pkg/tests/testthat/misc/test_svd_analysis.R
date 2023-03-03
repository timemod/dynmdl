library(testthat)
library(dynmdl)

rm(list = ls())


set.seed(123)

test_that("no singular matrix", {
  x1 <- rnorm(4)
  x2 <- rnorm(4)
  x3 <- rnorm(4)
  mat0 <- rbind(x1, x2, x3)
  svd_result <- svd_analysis(mat0)
  expect_output(print(svd_result), "No singular values < 1e-12.")
  expect_equal(dim(svd_result$u), c(0, 0))
  expect_equal(dim(svd_result$v), c(0, 0))
})

test_that("linearly dependend columns", {
  x1 <- rnorm(4)
  x2 <- rnorm(4)
  x3 <- rnorm(4)
  mat1 <- rbind(x1, x2, x3, x4 = x2 + x3)
  svd_result1 <- svd_analysis(mat1)
  expect_equal(length(svd_result1$d), 1)
  expect_equal(unname(abs(svd_result1$u[, 1])), rep(1/sqrt(3), 3))
  expect_equal(dim(svd_result1$v), c(4, 1))
  
  svd_result1a <- svd_analysis(mat1, coef_tol = 0.6)
  expect_equal(NROW(svd_result1a$u), 0)
})

test_that("linearly dependend rows", {
  x1 <- rnorm(4)
  x2 <- rnorm(4)
  mat2 <- cbind(x1, x2, x3 = x2 + 1e-14)
  svd_result2 <- svd_analysis(mat2)
  expect_equal(length(svd_result2$d), 1)
  expect_equal(unname(abs(svd_result2$v[, 1])), rep(1/sqrt(2), 2))
  expect_equal(dim(svd_result2$u), c(4, 1))
  
  mat2a <- cbind(x1, x2, x3 = x2 + 1e-9)
  svd_result2a <- svd_analysis(mat2a)
  expect_output(print(svd_result2a), "No singular values < 1e-12.")
  expect_equal(dim(svd_result2a$u), c(0, 0))
  expect_equal(dim(svd_result2a$v), c(0, 0))
  
  svd_result2a <- svd_analysis(mat2a, sd_tol = 1e-8, coef_tol = 1e-8)
  expect_equal(length(svd_result2a$d), 1)
  expect_equal(unname(abs(svd_result2a$v[, 1])), rep(1/sqrt(2), 2))
  expect_equal(dim(svd_result2a$u), c(4, 1))
})



















