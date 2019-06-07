library(dynmdl)
library(testthat)

rm(list = ls())

context("linlog2")

model <- "linlog2"

mod_file <- file.path("mod", paste0(model, ".mod"))
#x <- seq(0, 4, length.out = 100)[-1]
#plot(x, log(x), type = "l")
#lines(x,  0.5 * ( x - 1), type = "l", col = "red")
#lines(x,  2   * ( x - 1), type = "l", col = "blue")

report <- capture_output({
  mdl <- dyn_mdl(mod_file, period = "2018/2018", calc = "R")
  mdl_internal <-  dyn_mdl(mod_file, period = "2018/2018", calc = "internal")
})

correct_result <- c(y1 = 1, y2 = 1)

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

test_that("easy starting values (2)", {

  mdl$set_static_endos(c(y1 = 2, y2 = 1.1))
  msg <- paste0("Solving the steady state not succesful.\n",
                 "The Jacobian is \\(nearly\\) singular at iteration 1.",
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

# test_that("fit procedure", {
#   mdl$set_static_endos(c(y1 = 1.8, y2 = 0.8))
#   mdl$set_param_values(1, names = "sigma_uy1")
#   rep1 <- capture_output(mdl$solve_steady())
#   expect_equal(mdl$get_solve_status(), "OK")
#   mdl$init_data(data_period = "2018/2020")
#   mdl$set_period("2018/2020")
#   mdl$set_static_endos(c(y1 = 1.8, y2 = 0.8))
#   mdl$set_endo_values(names = "y1", value = 1.8)
#   mdl$set_fit_values(names = "y1", value = 1.25, period = "2018")
#   mdl$solve(control = list(trace = TRUE))
#   expect_known_value(mdl$get_endo_data(),
#                      "expected_output/linlog2_fit_result.rds")
#   
#   print(mdl$get_endo_data())
#   print(mdl$get_fit())
#   print(mdl$get_fit_instruments())
#   
#   mdl$set_static_endos(c(y1 = 2))
#   mdl$solve_steady((control = list(silent = FALSE, trace = TRUE, 
#                                                        allow_singular = TRUE)))
#   expect_equal(mdl$get_solve_status(), "OK")
#   expect_equal(mdl$get_static_endos(), c(y1 = 2, y2 = 1))
#   
#   # TODO: waarom is het resultaat anders na onderstaande opdracht:
#   # set endo_values mag geen effect hebben op resultaat. Of komt dit door
#   # de niet-lineariteit?
#   mdl$set_endo_values(2, names = "y1")
#   
#   mdl$solve(control = list(silent = FALSE, trace = TRUE, 
#                            allow_singular = TRUE), force_stacked_time = TRUE)
#   
#   #
#   # hier gebeuren hele rare dingen....
#   # 
#   # expect_equal(mdl$get_solve_status(), "OK")
#   print(mdl$get_endo_data())
#   print(mdl$get_fit())
#   print(mdl$get_fit_instruments())
#   
#   # TODO: hoe zit het met de trace van backward looking modellen.
# })
# 
