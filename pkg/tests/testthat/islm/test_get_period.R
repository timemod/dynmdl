library(dynmdl)
library(testthat)
rm(list = ls())

context("ISLM model steady state")

library(utils)
library(dynmdl)
library(testthat)

context("get_period-methods for the ISLM model")

capture_output(mdl <- read_mdl("islm_model.rds"))

test_that("get_period_methods", {
  datap <- period_range("1997Q1/2022Q4")
  modelp <- period_range("2017Q4/2022Q3")
  mdl$init_data(datap)
  mdl$set_period(modelp)
  expect_equal(mdl$get_period() , modelp)
  expect_equal(mdl$get_data_period() ,datap)
  expect_equal(mdl$get_lag_period(),  as.period_range(start_period(modelp) - 1))
  expect_equal(mdl$get_lead_period(), as.period_range(end_period(modelp) + 1))
})