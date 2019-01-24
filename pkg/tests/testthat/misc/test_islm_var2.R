library(dynmdl)
library(testthat)
rm(list = ls())

source("../tools/read_dynare_result.R")

context("ISLM variant 2")

model <- "islm_var2"

mod_file <- file.path("mod", paste0(model, ".mod"))

expected_equations_file <- "expected_output/expected_equations_islm_var2.rds"

# compile the model 
report <- capture_output(mdl <- dyn_mdl(mod_file, period = "2015/2032",
              fit_mod_file = file.path("mod_out", paste0(model, "_fit.mod"))))

dynare_result <- read_dynare_result("islm_var2", mdl)

create_solve_mdl <- function(mdl) {
  mdl2 <- mdl$clone()
  mdl2$put_static_endos()
  p1 <- start_period(mdl2$get_period())
  mdl2$set_exo_values(c(245, 250, 260), names = "g", 
                      period = period_range(p1, p1 + 2))
  mdl2$set_endo_values(6000, names = "y", period = mdl$get_lag_period())
  mdl2$set_endo_values(6000, names = "y", period = mdl$get_lead_period())
  mdl2$set_fit_values(6000, names = "c", period = "2015")
  mdl2$set_param(c(sigma_uc = 1))
  return(mdl2)
}

test_that("solve_steady and set_static_endos", {
  mdl$solve_steady(control = list(trace = FALSE, silent = TRUE))
  mdl$set_static_endos(c(y = 6000))
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
})

test_that("solve", {
  mdl2 <- create_solve_mdl(mdl)
  mdl2$solve(control = list(silent = TRUE, trace = FALSE))
  expect_equal(mdl2$get_endo_data(period = mdl2$get_period()), 
               dynare_result$endo)
})

test_that("check", {
  msg <- paste("Function solve_first_order does not work for models with",
               "max_lag > 1 or max_lead > 1.\n Tip: call function dyn_mdl",
              "with option max_laglead = TRUE.")
  capture_output(expect_error(mdl$check(), msg))
})

# now compile the model with option max_laglead_1
report <- capture_output(mdl_new <- dyn_mdl(mod_file, period = "2015/2032",
                                            max_laglead_1 = TRUE))

test_that("solve_steady with max_laglead_1", {
  mdl_new$solve_steady(control = list(trace = FALSE, silent = TRUE))
  expect_error(mdl_new$set_static_endos(c(y = 6000)),
                          "FitMdl cannot handle auxiliary variables yet")
})

test_that("solve with max_laglead_1", {
  mdl2 <- create_solve_mdl(mdl)
  p1 <- start_period(mdl2$get_period())
  mdl2$set_exo_values(c(245, 250, 260), names = "g", 
                      period = period_range(p1, p1 + 2))
  mdl2$solve(control = list(silent = TRUE, trace = FALSE))
  expect_equal(mdl2$get_endo_data(period = mdl2$get_period()), 
               dynare_result$endo)
 
  # residual check 
  res_check <- mdl2$residual_check()
  neq <- length(mdl$get_endo_names())
  expected_res_check <- regts(matrix(0, ncol = neq), period = mdl2$get_period(),
                              names = paste0("eq_", 1:neq))
  expect_equal(res_check, expected_res_check)
})

test_that("eigenvalues", {
  capture_output(mdl_new$check())
  eigval <- mdl_new$get_eigval()
  
  expect_identical(length(eigval), nrow(dynare_result$eigval))
 
  dynare_eigval_abs <- with(dynare_result, {
    sqrt(eigval[[1]]**2 + eigval[[2]]**2)
  })
  
  expect_equal(abs(eigval)[1:18], dynare_eigval_abs[1:18], tol = 1e-5)
})

test_that("get_equations", {
  eqs <- mdl_new$get_equations()
  if (.Platform$OS.type == "windows") {
    eqs_tmp <- gsub("\r\n", "\n", eqs)
  } else {
    eqs_tmp <- eqs
  }
  #print(eqs)
  expect_equal_to_reference(eqs_tmp, expected_equations_file)
})
