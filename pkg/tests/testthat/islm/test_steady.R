library(dynmdl)
library(testthat)
rm(list = ls())

context("ISLM model steady state")

period = "2017/2022"

report <- capture_output(mdl <- islm_mdl())

mdl$set_static_exos(c(g = 250))
mdl_period <- mdl$copy()$set_period(period)

mdl_steady1 <- mdl$copy()$solve_steady(control = list(silent = TRUE))
mdl_steady1$set_period(period)

mdl_steady2 <- mdl_period$copy()$solve_steady(control = list(silent = TRUE))

test_that("steady state result is correct", {

  expect_false(isTRUE(all.equal(mdl_steady1$get_endo_data(), 
                                mdl_period$get_endo_data())))
  
  expected_diff <- mdl_period$get_endo_data(period = "2017/")
  expected_diff[] <- 0
  expect_equal(diff(mdl_steady1$get_endo_data()), expected_diff)
  
  expect_equal(as.numeric(mdl_steady1$get_endo_data(period = "2017")),
               as.numeric(mdl_steady1$get_static_endos()))
  
  # after solving the model the result should not change
  mdl_solve <- mdl_steady1$copy()$solve(control = list(silent = TRUE))
  expect_equal(mdl_solve$get_endo_data(), mdl_steady1$get_endo_data())
  
  expect_equal(mdl_steady2$get_endo_data(), mdl_period$get_endo_data())
})

test_that("put_static_endos", {
  
  mdl_steady3 <- mdl_steady2$copy()$put_static_endos()

  expect_equal(mdl_steady3$get_endo_data(), mdl_steady1$get_endo_data())
  expect_false(isTRUE(all.equal(mdl_steady3$get_endo_data(), 
                                mdl_steady2$get_endo_data())))
})

test_that("put_static_endos with period", {
  mdl_steady3 <- mdl_steady2$copy()
  period <- period_range("2022/")
  mdl_steady3$put_static_endos(period)
  
  expect_false(isTRUE(all.equal(mdl_steady3$get_endo_data(), 
                                mdl_steady2$get_endo_data())))
  expect_equal(mdl_steady3$get_endo_data(period = period),
               mdl_steady1$get_endo_data(period = period))
  expect_equal(mdl_steady3$get_endo_data(period = "/2021"),
               mdl_steady2$get_endo_data(period = "/2021"))
  
  mdl_steady3 <- mdl_steady2$copy()
  period <- period_range("2018", "2018")
  mdl_steady3$put_static_endos(period)
  
  expect_false(isTRUE(all.equal(mdl_steady3$get_endo_data(), 
                                mdl_steady2$get_endo_data())))
  expect_equal(mdl_steady3$get_endo_data(period = period),
               mdl_steady1$get_endo_data(period = period))
  expect_equal(mdl_steady3$get_endo_data(period = "/2017"),
               mdl_steady2$get_endo_data(period = "/2017"))
  expect_equal(mdl_steady3$get_endo_data(period = "2019/"),
               mdl_steady2$get_endo_data(period = "2019/"))
  
  #
  # errors
  #
  msg <- "The start period \\(2040\\) is after the end period \\(2023\\)"
  expect_error(mdl_steady3$put_static_endos("2040/"), msg)
})

test_that("non-finite values", {
  mdl_2 <- mdl$copy()
  mdl_2$set_static_endos(c(t  = NaN))
  mdl_2$set_static_exos(c(g = Inf))
  expect_known_output(expect_warning(mdl_2$solve_steady(control = list(silent = TRUE)),
                                     "Solving the steady state not succesful"),
                      file = "expected_output/steady_non_finite_1.txt")
  expect_known_output(expect_warning(mdl_2$solve_steady(control = list(silent = TRUE)),
                                     "Solving the steady state not succesful"),
                      file = "expected_output/steady_non_finite_1.txt")
})

test_that("errors", {
  expect_error(mdl$set_static_endos(c(c = 12, xxx = 3)),
               "\"xxx\" is not an endogenous model variable")
  expect_error(mdl$set_static_exos(c(c = 12, xxx = 3, g = 12)),
               "\"c\", \"xxx\" are no exogenous model variables")
})