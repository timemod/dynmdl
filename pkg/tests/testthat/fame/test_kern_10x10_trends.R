library(dynmdl)
library(testthat)
rm(list = ls())

model_name <- "kern_10x10_trends"

context(paste("model", model_name))

source("../tools/read_dynare_result.R")

mod_file <- file.path("mod", paste0(model_name, ".mod"))

period <- period_range("2010Q2/2011Q1")

warnings <- capture_warnings(
  dum <- capture_output({
    mdl <- dyn_mdl(mod_file, period = period, calc  = "internal")
  })
)

expect_known_output(warnings, 
                    file = file.path("expected_output", 
                                     paste0(model_name, "_warnings.,txt")),
                    print = TRUE)

dynare_result <- read_dynare_result(model_name, mdl)

test_that("steady state", {
  
  mdl$solve_steady(control = list(silent = TRUE))
  
  expect_equal(mdl$get_solve_status(), "OK")
  
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
  
  # check that the steady state solution is consistent with the
  # dynamic model
  mdl_tmp <- mdl$copy()
  mdl_tmp$put_static_endos()
  res <- mdl_tmp$residual_check()
  expect_true(all(abs(res) < 1e-8))
})

test_that("check and eigenvalues", {
  
  check_report <- capture_output(mdl$check())

  eigvals <- mdl$get_eigval()
  expect_equal(Re(eigvals[1:26]), dynare_result$eigval[1:26, 1], 
               tolerance = 1e-7)
  expect_equal(abs(Im(eigvals[1:26])), abs(dynare_result$eigval[1:26, 2]), 
               tolerance = 1e-7)
  
  expect_true(all(Mod(eigvals[27:34]) > 1e5))
})