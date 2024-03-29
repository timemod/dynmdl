library(dynmdl)
library(testthat)

rm(list = ls())


mdl <- read_mdl("islm_model.rds", silent = TRUE)

test_that("change_static_endos", {
  
  static_endos <- mdl$get_static_endos()
  static_exos <- mdl$get_static_exos()
  
  f_add <- function(x, dx) {
    return(x[1] + dx)
  }
  
  mdl2 <- mdl$copy()
  mdl3 <- mdl$copy()
  
  expected_endos <- static_endos
  expected_exos <- static_exos
  
  mdl2$change_static_endos(names = "md", fun = f_add, dx = 2)
  mdl2$change_static_exos(names = "ms", fun = f_add, dx = 2)
  mdl3$change_static_data(pattern = "^m", fun = f_add, dx = 2)
  
  expected_endos["md"] <-  expected_endos["md"] + 2
  expected_exos["ms"] <-  expected_exos["ms"] + 2
  
  expect_equal(mdl2$get_static_endos(), expected_endos)
  expect_equal(mdl2$get_static_exos(), expected_exos)
  expect_equal(mdl3$get_static_endos(), expected_endos)
  expect_equal(mdl3$get_static_exos(), expected_exos)
  
  
  mdl2$change_static_endos(pattern = "^y", names = "i", fun = f_add, dx = 3)
  mdl2$change_static_exos(pattern = "^g$", fun = f_add, dx = 6)
  mdl3$change_static_data(pattern = "^(y|i)", names = "g", fun = f_add, dx = 3)
  mdl3$change_static_data(names = "g", fun = f_add, dx = 3)
  
  expected_endos["y"] <-  expected_endos["y"] + 3
  expected_endos["yd"] <-  expected_endos["yd"] + 3
  expected_endos["i"] <-  expected_endos["i"] + 3
  expected_exos["g"] <-  expected_exos["g"] + 6
  
  expect_equal(mdl2$get_static_endos(), expected_endos)
  expect_equal(mdl2$get_static_exos(), expected_exos)
  expect_equal(mdl3$get_static_endos(), expected_endos)
  expect_equal(mdl3$get_static_exos(), expected_exos)
  
  mdl2$change_static_endos(fun = function(x) {x * 100})
  mdl2$change_static_exos(fun = function(x) {x * 100})
  mdl3$change_static_data(fun = function(x) {x * 100})
  
  expect_equal(mdl2$get_static_endos(), 100 * expected_endos)
  expect_equal(mdl2$get_static_exos(), 100 * expected_exos)
  expect_equal(mdl3$get_static_endos(), 100 * expected_endos)
  expect_equal(mdl3$get_static_exos(), 100 * expected_exos)
})


test_that("errors", {
  expect_error(mdl$change_static_endos(names = "i", fun = function(x) {x + 1:2}),
               "'fun' should be a function that returns a numeric vector of length 1.")
  
  expect_error(mdl$change_static_endos(names = "i", fun = 2),
               "Argument 'fun' is not a function")
  
  expect_error(mdl$change_static_exos(names = "g", fun = function(x) {x + 1:2}),
               "'fun' should be a function that returns a numeric vector of length 1.")
  
  expect_error(mdl$change_exo_data(names = "yd"), 
               "\"yd\" is not an exogenous variable.")
  expect_error(mdl$change_endo_data(names = "g"), 
               "\"g\" is not an endogenous variable.")
  expect_error(mdl$change_static_data(names = "gg"), 
               "\"gg\" is not a model variable.")
  
  expect_warning(mdl$change_static_data(pattern = "^aaa"),
                 "No model variables match pattern \"\\^aaa\"\\.")
}) 

test_that("fit", {
  
  mdl_fit <- read_mdl("islm_model_fit.rds", silent = TRUE)
  static_data <- mdl_fit$get_all_static_data()
  mdl_fit$change_static_endos(pattern = "i$", fun = function(x) {x + 10})
  mdl_fit$change_static_data(names = c("l_3", "g", "c"), fun = function(x) {x + 100})
  expected_result <- static_data
  expected_result["i"] <- expected_result["i"] + 10
  expected_result["ui"] <- expected_result["ui"] + 10
  expected_result["l_3"] <- expected_result["l_3"] + 100
  expected_result["g"] <- expected_result["g"] + 100
  expected_result["c"] <- expected_result["c"] + 100
  expect_equal(expected_result, mdl_fit$get_all_static_data())
  
  # errors
  expect_error(mdl_fit$change_static_exos(names = "fit_c", fun = identity),
               "\"fit_c\" is not an exogenous variable\\.")
  
})
