library(utils)
library(dynmdl)
library(testthat)

rm(list = ls())


mdl <- read_mdl("islm_model.rds", silent = TRUE)

c_multipliers <- seq(0.8, 1.0, length.out = nperiod(mdl$get_data_period()))
ms_g_additions <- seq(10, 40, length.out = 4)

new_endo_data <- mdl$get_endo_data()
new_endo_data[ , "c" ] <- new_endo_data[, "c"] * c_multipliers
new_endo_data["2016Q2", c("y", "yd")] <- new_endo_data["2016Q2", c("y", "yd")] * 1.1

new_exo_data <- mdl$get_exo_data()
new_exo_data["2015Q3/2016Q2", c("ms", "g")] <-
  new_exo_data["2015Q3/2016Q2", c("ms", "g")] + ms_g_additions


test_that("change_data works correctly", {
  mdl2 <- mdl$copy()
  mdl2$change_endo_data(function(x, fac) {x * fac}, names = "c", 
                        fac = c_multipliers)
  mdl2$change_exo_data(function(x) {x + ms_g_additions}, names = c("ms", "g"),
                     period = "2015Q3/2016Q2")
  mdl2$change_endo_data(function(x) {x * 1.1}, pattern = "^y", period = "2016Q2")
  expect_equal(mdl2$get_endo_data(), new_endo_data)
  expect_equal(mdl2$get_exo_data(), new_exo_data)
})

test_that("change_data works correctly with timeseries input", {
  mdl2 <- mdl$copy()
  mdl2$change_endo_data(function(x, fac) {x * fac}, names = "c", fac = c_multipliers)
  ms_g_ts <- regts(ms_g_additions, period = "2015Q3/2016Q2")
  mdl2$change_exo_data(function(x) {x + ms_g_ts}, names = c("ms", "g"),
                   period = "2015Q3/2016Q2")
  mdl2$change_endo_data(function(x) {x * 1.1}, pattern = "^y", period = "2016Q2")
  expect_equal(mdl2$get_endo_data(), new_endo_data)
  expect_equal(mdl2$get_exo_data(), new_exo_data)
})

test_that("change_data works correctly with timeseries input (2)", {
  
  mdl2 <- mdl$copy()
  mdl2$change_endo_data(function(x, fac) {x * fac}, names = "c", 
                        fac = c_multipliers)
  ms_g_ts <- regts(c(-999, ms_g_additions, 999), period = "2015Q2/2016Q3")
  
  expect_error(
    expect_warning(
    mdl2$change_exo_data(function(x) {x + ms_g_ts}, names = c("ms", "g"),
                       period = "2015Q3/2016Q2")),
    "The function result has length 6 but should have length 1 or 4.")
  
  mdl2$change_exo_data(function(x) {x + ms_g_ts["2015q3/2016q2"]}, 
                       names = c("ms", "g"),
                       period = "2015Q3/2016Q2")
  
  mdl2$change_endo_data(function(x) {x * 1.1}, pattern = "^y", 
                        period = "2016Q2")
  expect_equal(mdl2$get_endo_data(), new_endo_data)
  expect_equal(mdl2$get_exo_data(), new_exo_data)
})

test_that("change_data works correctly with timeseries input (3)", {
  mdl2 <- mdl$copy()
  mdl2$change_data(function(x, fac) {x * fac}, names = "c", fac = c_multipliers,
                   period = "2015/")
  ms_g_ts <- regts(c(-999, ms_g_additions, 999), period = "2015Q2/2016Q3")
  
  expect_error(mdl2$change_data(function(x) {x + ms_g_ts["2015q3"]},
                                names = c("ms", "g"),
                                period = "2015Q3/2016Q3"),
               "time-series/vector length mismatch")
  for (per in as.list(seq(period("2015q3"), period("2016q2")))) {
    mdl2$change_data(function(x) {x + ms_g_ts[per]}, names = c("ms", "g"),
                     period = per)
  }
  
  mdl2$change_data(function(x) {x * 1.1}, pattern = "^y", period = "2016Q2")
  
  
  msg <- paste("Specified period \\(11Q1/11Q4\\) is completely outside the",
               "data period \\(2015Q1/2016Q4\\)\\.")
  expect_warning(mdl2$change_data(function(x) {x * 1.1}, pattern = "^y",
                                  period = "11"),
                 msg)
  
  expect_equal(mdl2$get_endo_data(), new_endo_data)

  expect_equal(mdl2$get_exo_data(), new_exo_data)
})

test_that("change_data handles errors correctly", {
  mdl2 <- mdl$clone(deep = TRUE)
  msg <- "\"xxx\" is not an endogenous variable."
  expect_error(mdl2$change_endo_data(identity, names = c("y", "xxx")), msg)
  msg <-  "The following names are no endogenous variables: \"p\", \"xxx\"."
  expect_error(mdl2$change_endo_data(identity, names = c("p", "xxx")), msg)
  msg <- "Argument 'fun' is not a function\\."
  expect_error(mdl2$change_endo_data(2, names = "y"), msg)
})

test_that("change_data works correctly (with endo and exo)", {
  names <-  c("c", "ms", "g")
  mdl2 <- mdl$copy()
  mdl2$change_data(function(x, fac) {x * fac}, names = names, 
                             fac = c_multipliers)
  new_data <- mdl$get_data()
  new_data[ , names] <- new_data[ ,  names] * c_multipliers
  
  expect_equal(mdl2$get_data(), new_data)
})

test_that("test with period partially outside period range", {
  mdl2 <- mdl$copy()
  old_endos <- mdl2$get_endo_data(period = "2016q3/", names = c("c", "y"))
  mdl2$change_data(function(x) x + 1:3, names = c("c", "y"),
                   period = "2016q3/2017q1")
  new_endos <- mdl2$get_endo_data(period = "2016q3/", names = c("c", "y"))
  expect_equal(new_endos, old_endos + 1:2)
})

test_that("fit", {
  
  mdl_fit <- read_mdl("islm_model_fit.rds", silent = TRUE)
  mdl_fit$set_period("2019q1")
  mdl_fit$init_data(data_period = c("2018q4/2019q2"))

  data <- mdl_fit$get_all_data()
  mdl_fit$change_endo_data(pattern = "i$", fun = function(x) {x + 10})
  mdl_fit$change_data(names = c("l_3", "g", "c"), fun = function(x) {x + 100})
  expected_result <- data
  expected_result[ , "i"] <- expected_result[ , "i"] + 10
  expected_result[ , "ui"] <- expected_result[ ,  "ui"] + 10
  expected_result[ , "l_3"] <- expected_result[ , "l_3"] + 100
  expected_result[ , "g"] <- expected_result[ , "g"] + 100
  expected_result[ , "c"] <- expected_result[ , "c"] + 100
  expect_equal(expected_result, mdl_fit$get_all_data())
  
  # errors
  expect_error(mdl_fit$change_exo_data(names = "fit_c", fun = identity),
               "\"fit_c\" is not an exogenous variable\\.")
})  
