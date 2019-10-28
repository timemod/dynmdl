library(dynmdl)
library(testthat)

rm(list = ls())

context("linlog2")

source("../tools/read_file.R")

model <- "linlog2"

mod_file <- file.path("mod", paste0(model, ".mod"))
fit_mod_file <- file.path("mod_out", paste0(model, ".mod"))

#x <- seq(0, 4, length.out = 100)[-1]
#plot(x, log(x), type = "l")
#lines(x,  0.5 * ( x - 1), type = "l", col = "red")
#lines(x,  2   * ( x - 1), type = "l", col = "blue")

report <- capture_output({
  mdl <- dyn_mdl(mod_file, period = "2018/2018", calc = "R")
  mdl_internal <-  dyn_mdl(mod_file, period = "2018/2018", calc = "internal",
                           fit_mod_file = fit_mod_file)
})

correct_result <- c(y1 = 1, y2 = 1)

test_that("check fit_mod_file", {
  fit_mod_txt <- read_file(fit_mod_file)
  expect_known_output(cat(fit_mod_txt), 
                      "expected_output/linlog2_fit_mod_file.txt")
})

test_that("easy starting values (1)", {
  mdl$set_static_endos(c(y1 = -0.1, y2 = 0.8))
  mdl$solve_steady(control = list(silent = TRUE, trace = TRUE))
  expect_equal(mdl$get_solve_status(), "OK")
  expect_equal(mdl$get_static_endos(), correct_result)
})

test_that("easy starting values (1) /internal", {
  mdl_internal$set_static_endos(c(y1 = -0.1, y2 = 0.8))
  mdl_internal$solve_steady(control = list(silent = TRUE, trace = TRUE))
  expect_equal(mdl_internal$get_solve_status(), "OK")
  expect_equal(mdl_internal$get_static_endos(), correct_result)
})

test_that("easy starting values (2)", {
  mdl$set_static_endos(c(y1 = 1.8, y2 = 0.8))
  mdl$solve_steady(control = list(silent = TRUE, trace = TRUE))
  expect_equal(mdl$get_solve_status(), "OK")
  expect_equal(mdl$get_static_endos(), correct_result)
})

test_that("problematic starting values", {

  mdl$set_static_endos(c(y1 = 2, y2 = 1.1))
  msg <- paste0("Solving the steady state not succesful.\n",
                 "The Jacobian is singular at iteration 1.",
                 " The inverse condition is 0.")
  expect_warning({
    mdl$solve_steady(control = list(silent = TRUE, trace = TRUE))
  }, msg)
  
  expect_equal(mdl$get_solve_status(), "ERROR")
  
  msg <- paste0("Solving the steady state not succesful.\n",
                "Relative step size smaller than xtol \\(1e-08\\)")
  expect_warning({
    mdl$solve_steady((control = list(silent = TRUE, trace = TRUE, 
                                   allow_singular = TRUE)))
  })              
  expect_equal(mdl$get_solve_status(), "ERROR")
  expect_equal(mdl$get_static_endos(), c(y1 = 2, y2 = 1))
})

test_that("disable linlog for the first equation", {
  mdl_no_linlog_y1 <- mdl$copy()
  mdl_no_linlog_y1$set_param(c(eps = -Inf))
  mdl_no_linlog_y1$set_static_endos(c(y1 = 1.8, y2 = 0.8))
  warnings <- capture_warnings(
    mdl_no_linlog_y1$solve_steady(control = list(silent = TRUE, trace = TRUE))
  )
  # TODO: compare warnings with reference output
  expect_equal(mdl$get_solve_status(), "ERROR")
  expect_equal(mdl$get_static_endos(), c(y1 = 2, y2 = 1))
})

test_that("sigma_uy1 > 0", {
  
  # turn on fit procedure
  mdl$set_param_values(1, names = "sigma_uy1")
  
  # if sigma_uy1 > 1, there are two solutions:
  #  1)  (y1, y2) = (1, 1)
  #  2)  (y1, y2) = (2, 1)
  
  # first attempt: find solution (2)
  # this solution is no valid soluiton, since the steady state
  # values of the fit instruments and lagrange multiplier
  # are signifiucantly differently from 0
  mdl$set_static_endos(c(y1 = 2, y2 = 0.8))
  expect_warning(
    mdl$solve_steady(control = list(silent = TRUE, trace = TRUE, 
                                    allow_singular = TRUE)),
    paste("The steady state values for the fit instruments and lagrange",
          "multipliers are significantly different from 0."))
  expect_equal(mdl$get_solve_status(), "OK")
  expect_equal(mdl$get_static_endos(), c(y1 = 2, y2 = 1))
  expect_known_value(mdl$get_static_jacob(),  
                     "expected_output/linlog2_steady_sol2.rds")
  
  # second attempt: find solution (1)
  mdl$set_static_endos(c(y1 = 1, y2 = 0.8))
  mdl$solve_steady(control = list(silent = TRUE, trace = TRUE))
  expect_equal(mdl$get_solve_status(), "OK")
  expect_equal(mdl$get_static_endos(), c(y1 = 1, y2 = 1))
  expect_known_value(mdl$get_static_jacob(),  
                     "expected_output/linlog2_steady_sol1.rds")
})

test_that("fit procedure", {
  
  per <- period_range("2018/2020")
  mdl$init_data(data_period = per)
  mdl$set_period(per)

  mdl$set_static_endos(c(y1 = 1.8, y2 = 0.8))
  mdl$set_endo_values(names = "y1", value = 1.8)
  mdl$set_fit_values(names = "y1", value = 1.25, period = "2018")
  mdl$solve(control = list(silent = TRUE, trace = TRUE))
  expect_equal(mdl$get_solve_status(), "OK")
  #print(mdl$get_endo_data())
  #print(mdl$get_fit_instruments())
  expect_known_value(mdl$get_endo_data(),
                      "expected_output/linlog2_fit_result1.rds")
    
  expect_equal(mdl$get_fit_instruments(),
               regts(matrix(c(1/8 - log(5/4), 0, 0)), period =  per, names = "uy1",
                     labels = "uy1"))
  
  # now other solution
  mdl$set_endo_values(2, names = "y1")
   
  mdl$solve(control = list(silent = TRUE, trace = TRUE,
                            allow_singular = TRUE), 
                      mode = "stacked_time")
  
  expect_equal(mdl$get_solve_status(), "OK")
  #print(mdl$get_endo_data())
  expect_known_value(mdl$get_endo_data(),
                     "expected_output/linlog2_fit_result2.rds")
  
  #print(mdl$get_fit_instruments())
  expect_equal(mdl$get_fit_instruments(),
               regts(matrix(c(1/8 - log(5/4), rep(0.5 - log(2), 2))), 
                     period =  per, names = "uy1", labels = "uy1"))
})

