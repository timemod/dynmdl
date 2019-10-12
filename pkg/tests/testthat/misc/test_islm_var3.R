library(dynmdl)
library(testthat)
rm(list = ls())

source("../tools/read_dynare_result.R")

context("ISLM variant 3")

model <- "islm_var3"

mod_file <- file.path("mod", paste0(model, ".mod"))

solve_period <- "2015/2032"

# compile the model 
report <- capture_output(mdl <- dyn_mdl(mod_file, period = solve_period,
                                        max_laglead_1 = TRUE))

dynare_result <- read_dynare_result("islm_var3", mdl)
dynare_result_with_aux <- read_dynare_result("islm_var3", mdl, all_vars = TRUE)


create_solve_mdl <- function(mdl) {
  mdl2 <- mdl$clone()
  mdl2$put_static_endos(period = mdl2$get_lag_period())
  p1 <- start_period(mdl2$get_period())
  mdl2$set_exo_values(c(245, 250, 260), names = "g", 
                      period = period_range(p1, p1 + 2))
  return(mdl2)
}

test_that("get_period-methods", {
  expect_equal(mdl$get_period() , as.period_range("2015/2032"))
  expect_equal(mdl$get_data_period(), as.period_range("2011/2032"))
  expect_equal(mdl$get_lag_period(), as.period_range("2011/2014"))
  expect_null(mdl$get_lead_period())
})


test_that("solve_steady", {
  mdl$solve_steady(control = list(trace = FALSE, silent = TRUE))
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
})

test_that("solve", {
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
  
  # check write_initval_file
  
  initval_file <- tempfile()
  expect_silent(mdl2$write_initval_file(initval_file))
  initval_data <- readxl::read_excel(initval_file)
  period <- mdl2$get_period()
  initval_period <- period_range(start_period(period) -
                                   mdl2$get_max_lag(data = FALSE),
                                 end_period(period) +
                                   mdl2$get_max_lag(data = FALSE))
  initval_data <- regts(initval_data, period = initval_period)
  initval_data <- initval_data[solve_period]
  
  dynare_data <- cbind(dynare_result_with_aux$endo,
                       dynare_result_with_aux$exo)
  
  expect_true(tsdif(initval_data, dynare_data, fun = cvgdif, tol = 1e-7)$equal)
  
})

test_that("eigenvalues", {
  capture_output(mdl$check())
  eigval <- mdl$get_eigval()

  expect_equal(abs(Re(eigval)), abs(dynare_result$eigval[ , 1]), 
               tolerance = 1e-5)
  expect_equal(abs(Im(eigval)), abs(dynare_result$eigval[ , 2]),
               tolerance = 1e-5)
})
