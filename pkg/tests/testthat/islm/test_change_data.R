library(utils)
library(dynmdl)
library(testthat)

context("change_endo_data and change_exo_data for the ISLM model")

capture_output(mdl <- read_mdl("islm_model.rds"))

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
  mdl2$change_exo_data(function(x) {x + ms_g_ts}, names = c("ms", "g"),
                   period = "2015Q3/2016Q2")
  mdl2$change_endo_data(function(x) {x * 1.1}, pattern = "^y", 
                        period = "2016Q2")
  expect_equal(mdl2$get_endo_data(), new_endo_data)
  expect_equal(mdl2$get_exo_data(), new_exo_data)
})

test_that("change_data handles errors correctly", {
  f <- function(x) {x}
  mdl2 <- mdl$clone(deep = TRUE)
  msg <- "xxx is not an endogenous model variable"
  expect_error(mdl2$change_endo_data(f, names = c("y", "xxx")), msg)
  msg <- "The variables p xxx are no endogenous model variables"
  expect_error(mdl2$change_endo_data(f, names = c("p", "xxx")), msg)
  msg <- paste("Period 2012 has a different frequency than the model",
               "period 2015Q2/2016Q3.")
  expect_error(mdl2$change_endo_data(f, names = "c", period = "2012Y"), msg)
  msg <- "argument fun is not a function"
  expect_error(mdl2$change_endo_data(2, names), msg)
})

