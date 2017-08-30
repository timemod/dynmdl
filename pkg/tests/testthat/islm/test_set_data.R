library(utils)
library(dynmdl)
library(testthat)

context("set_data for the ISLM model")

capture_output(mdl <- read_mdl("islm_model.rds"))

new_data <- mdl$get_endo_data()
new_data["2015Q3", "y"] <- NA
new_data["2016Q2", "yd"] <- NA

test_that("set_data update mode upd", {
  mdl2 <- mdl$copy()
  mdl2$set_data(new_data)
  expect_equal(mdl2$get_endo_data(), new_data)

  mdl3 <- mdl$copy()
  mdl3$set_data(new_data, upd_mode = "upd")
  expect_equal(mdl3$get_endo_data(), new_data)
})

test_that("set_data update mode updval", {
  mdl2 <- mdl$copy()
  mdl2$set_data(new_data, upd_mode = "updval")
  expect_equal(mdl2$get_endo_data(), mdl$get_endo_data())
})

test_that("errors", {
  ydat <- regts(matrix(0, ncol = 2, nrow =2), names = c("i", "c"),
                 period = "2017/2018")
  msg <- paste("The frequency of data does not agree with the data period",
               "2015Q1/2016Q4.")
  expect_error(mdl$set_data(ydat), msg)
  msg <- "Argument data is not a timeseries object"
  expect_error(mdl$set_data(3), msg)
})
