library(utils)
library(dynmdl)
library(testthat)


rm(list = ls())

rep <- capture.output(mdl <- islm_mdl())

test_that("errors", {
  msg <-  "Argument 'period' should have a lower and upper bound"
  expect_error(mdl$set_period("2030/"), msg)
  expect_error(mdl$set_period("/2030"), msg)
  
  mdl$init_data(data_period = "2011/2015")
  msg <- paste("The specified period \\(2030\\) is not compatible with the",
              "data period \\(2011/2015\\)\\. The period should lie within",
              "the range 2012/2014\\.")  
  expect_error(mdl$set_period("2030"), msg)
})



