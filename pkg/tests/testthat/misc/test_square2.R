library(dynmdl)
library(testthat)


rm(list = ls())

mod_file <- "mod/square2.mod"

# compile the model
report <- capture_output(mdl <- dyn_mdl(mod_file))

data_per <- period_range("2010/2025")
mdl_per <- period_range("2018/2022")
mdl$init_data(data_period = data_per)
mdl$set_period(mdl_per)

x <- regts(seq_len(nperiod(data_per)), period = data_per)
mdl$set_data(x, names = "x")
mdl$solve_steady(control = list(silent = TRUE))
mdl$solve(silent = TRUE, control = list(silent = TRUE), global = "no")

compute_back_jacob <- function(period) {
  y <- mdl$get_endo_data(names = "y", period = period)
  jac <- diag(2)
  jac[2, 1] <- - 2 * as.numeric(y)
  colnames(jac) <- c("y", "z")
  return(jac)
}

test_that("solve result is correct", {
  res <- mdl$get_endo_data(names = "z", per = mdl_per)[, 1]
  ts_labels(res) <- NULL
  expect_equal(res, ((lag(x, 3) + lag(x, -1))[mdl_per])**2)
})

test_that("get_back_jacob correct", {
 
  p <- period("2013")
  expect_equal(mdl$get_back_jacob(p), compute_back_jacob(p))
  
  p <- period("2017")
  expect_equal(mdl$get_back_jacob(p), compute_back_jacob(p))
  
  p <- period("2018")
  expect_equal(mdl$get_back_jacob(p), compute_back_jacob(p))
  
  p <- period("2019")
  expect_equal(mdl$get_back_jacob(p), compute_back_jacob(p))
  
  p <- period("2023")
  expect_equal(mdl$get_back_jacob(p), compute_back_jacob(p))

  expect_error(mdl$get_back_jacob("2010"),
               "The specified period \\(2010\\) should lie within the range 2011/2025.")

})

test_that("get_jacob", {
  expect_known_value(mdl$get_jacob(), "expected_output/square2_jac.rds")
})

test_that("get_static_jacob", {
  expected_result <- diag(2)
  expected_result[2, 1] <- - 12
  colnames(expected_result) <- c("y", "z")
  expect_equal(mdl$get_static_jacob(), expected_result)
})


