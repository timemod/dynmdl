library(utils)
library(dynmdl)
library(testthat)

context("set_values-methods for the ISLM model")

capture_output(mdl <- read_mdl("islm_model.rds"))

test_that("set_values works correctly (1)", {
  
  new_endo_data <- mdl$get_endo_data()
  new_endo_data[ , "c" ] <- 600
  new_endo_data["2016Q2", c("y", "yd")] <- 990
  
  new_exo_data <- mdl$get_exo_data()
  new_exo_data["2015Q3/2016Q2", c("ms", "g")] <- c(200, 210, 215, 220)
  
  mdl2 <- mdl$copy()
  mdl2$set_endo_values(600, names = "c")
  mdl2$set_exo_values(c(200, 210, 215, 220), names = c("ms", "g"),
                  period = "2015Q3/2016Q2")
  mdl2$set_endo_values(990, pattern = "^y", period = "2016Q2")
  expect_equal(mdl2$get_endo_data(), new_endo_data)
  expect_equal(mdl2$get_exo_data(), new_exo_data)
})


test_that("set_values works correctly (2)", {
  
  new_endo_data <- mdl$get_endo_data()
  new_endo_data["2016", c("y", "yd")] <- 990
  new_exo_data <- mdl$get_exo_data()
  new_exo_data["2015", c("ms", "g")] <- c(200, 210, 215, 220)
  
  mdl2 <- mdl$copy()
  mdl2$set_exo_values(c(200, 210, 215, 220), names = c("ms", "g"),
                      period = "2015")
  mdl2$set_endo_values(990, pattern = "^y", period = "2016")
  expect_equal(mdl2$get_endo_data(), new_endo_data)
  expect_equal(mdl2$get_exo_data(), new_exo_data)
})


test_that("set_values handles errors correctly", {
  mdl2 <- mdl$copy()
  msg <- "xxx is not an endogenous model variable"
  expect_error(mdl2$set_endo_values(1, names = c("y", "xxx")), msg)
  msg <- "The variables p xxx are no exogenous model variables"
  expect_error(mdl2$set_exo_values(1, names = c("p", "xxx")), msg)
})
