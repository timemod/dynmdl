library(dynmdl)
library(testthat)
rm(list = ls())
source("../tools/read_dynare_result.R")

context("ISLM variant 1")

model <- "islm_var1"

mod_file <- file.path("mod", paste0(model, ".mod"))

expected_equations_file <- "expected_output/expected_equations_islm_var1.rds"

# compile the model 
report <- capture_output(mdl <- dyn_mdl(mod_file, period = "2015/2032"))

dynare_result <- read_dynare_result("islm_var1", mdl)

create_solve_mdl <- function(mdl) {
  mdl2 <- mdl$copy()
 
  p1 <- start_period(mdl2$get_period())
  mdl2$set_exo_values(c(245, 250, 260), names = "g", 
                      period = period_range(p1, p1 + 2))
  mdl2$set_endo_values(4800, names = "yd", 
                       period = mdl2$get_lead_period())
  return(mdl2)
}

test_that("get_period-methods", {
  expect_equal(mdl$get_period() , as.period_range("2015/2032"))
  expect_equal(mdl$get_data_period(), as.period_range("2011/2035"))
  expect_equal(mdl$get_lag_period(), as.period_range("2011/2014"))
  expect_equal(mdl$get_lead_period(), as.period_range("2033/2035"))
})

test_that("solve_steady and set_static_endos", {
  mdl$solve_steady(control = list(trace = FALSE, silent = TRUE))
  mdl$put_static_endos()
  mdl$set_static_endos(c(yd = 4800))
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

test_that("get_period-methods with max_laglead_1", {
  expect_equal(mdl_new$get_period() , as.period_range("2015/2032"))
  expect_equal(mdl_new$get_data_period(), as.period_range("2011/2035"))
  expect_equal(mdl_new$get_lag_period(), as.period_range("2011/2014"))
  expect_equal(mdl_new$get_lead_period(), as.period_range("2033/2035"))
})

test_that("solve_steady with max_laglead_1", {
  mdl_new$solve_steady(control = list(trace = FALSE, silent = TRUE))
  mdl_new$put_static_endos()
  mdl_new$set_static_endos(c(yd = 4800))
  expect_equal(mdl_new$get_static_endos(), dynare_result$steady)
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
 
  # the last eigenvalues is Inf or almost infinite
  expect_equal(Re(eigval)[1:10], dynare_result$eigval[1:10, 1], 
               tolerance = 1e-7)
  expect_equal(Im(eigval)[1:10], dynare_result$eigval[1:10, 2],
               tolerance = 1e-7)
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

#
# now with dll option
#

report <- capture_output(mdl_dll <- dyn_mdl(mod_file, period = "2015/2032",
                                            max_laglead_1 = TRUE, 
                                            calc = "dll"))

test_that("solve_steady with max_laglead_1, dll", {
  mdl_dll$solve_steady(control = list(trace = FALSE, silent = TRUE))
  mdl_dll$put_static_endos()
  mdl_dll$set_static_endos(c(yd = 4800))
  expect_equal(mdl_dll$get_static_endos(), dynare_result$steady)
})

test_that("solve with max_laglead_1 and dll", {
  mdl2 <- create_solve_mdl(mdl_dll)
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

test_that("eigenvalues with dll", {
  capture_output(mdl_dll$check())
  eigval <- mdl_dll$get_eigval()
  
  # the last eigenvalues is Inf or almost infinite
  expect_equal(Re(eigval)[1:10], dynare_result$eigval[1:10, 1], 
               tolerance = 1e-7)
  expect_equal(Im(eigval)[1:10], dynare_result$eigval[1:10, 2],
               tolerance = 1e-7)
})

test_that("put_static_endos", {
  mdl2 <- mdl$copy()
  mdl2$set_static_exos(c(ms = 220))
  mdl2$solve_steady(control = list(silent = TRUE))
  mdl2$put_static_endos("2030/")
  
  expect_equal(mdl2$get_endo_data(period = "/2029"),
               mdl$get_endo_data(period = "/2029"))
  expect_false(isTRUE(all.equal(mdl2$get_endo_data(period = "2030/"),
                                mdl$get_endo_data(period = "2030/"))))
})

test_that("get_jacob", {
  mdl2 <- mdl$copy()
  mdl2$set_period("2015/2020")
  
  jac <- mdl2$get_jacob()
  expect_known_value(jac,  "expected_output/islm_var1_jac.rds")
})

test_that("get_data also works with aux vars", {
  
  endo_data <- mdl_new$get_endo_data()
  exo_data <- mdl_new$get_exo_data()
  expect_identical(colnames(exo_data), c("g", "ms"))
  data <- cbind(endo_data, exo_data)
  data <- data[ , order(colnames(data))]
  
  expect_equal(data, mdl_new$get_data())
  
  expect_equal(select_columns(data, regex = ".."),
               mdl_new$get_data(pattern = ".."))
})


