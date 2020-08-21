library(utils)
library(dynmdl)
library(testthat)

rm(list = ls())

context("set/get parameters")

x <- mdl <- read_mdl("islm_model.rds", silent = TRUE)

pars <- mdl$get_param()

test_that("set_param", {
  
  mdl2 <- mdl$copy()
  
  par <- c(i3 = -999)
  mdl2$set_param(par)
  expect_identical(mdl2$get_param(names = "i3"), par)
  
  par <- 999
  mdl2$set_param(par, names = "i3")
  expect_identical(mdl2$get_param(names = "i3"), c(i3 = par))
  
  # errors
  expect_error(mdl2$set_param(c(aap = 9999)), "'aap' is not a parameter.")
  
  msg <-  "The following names are no parameters: 'aap', 'jan'."
  expect_error(mdl2$set_param(c(i3 = 999, aap = 999, jan = 999)), msg)
  expect_warning(mdl2$set_param(c(i3 = 9999, aap = 999, jan = 999), 
                               name_err = "warn"), msg)
  expect_equal(mdl2$get_param(names = "i3"), c(i3 = 9999))
 
  expect_silent(mdl2$set_param(c(i3 = 9999, aap = 999, jan = 999), 
                               name_err = "silent"))
  expect_error(mdl2$set_param(2), 
               "If argument params has no names, than argument names must be specified.")
  
  # duplicate names
  par <- c(i3  = -999, i3 = 666)
  expect_warning(mdl2$set_param(par),
                 paste("Values contains duplicate names. The first value is",
                       "used.\nThe duplicated names are: i3."))
  expect_identical(mdl2$get_param(names = "i3"), par[1])
  
  par <- c(i3  = -999, i3 = 666, i1 = 222,  i1 = 111)
  expect_warning(mdl2$set_param(par),
                 paste("Values contains duplicate names. The first value is",
                       "used.\nThe duplicated names are: i3, i1."))
  expect_identical(mdl2$get_param(names = c("i1", "i3")), par[c(3, 1)])
  
})

test_that("get_param", {
  
  x1 <- mdl$get_param(pattern = "^c", names = "i1")
  expect_identical(x1, pars[c("i1", paste0("c", 0:5))])
  
  expect_warning(
    x2 <- mdl$get_param(pattern = "^aap", names = "i1"),
    "No parameters match pattern \"\\^aap\"\\.")
  
  expect_identical(x2, pars["i1"])
  
  expect_warning(
    expect_identical(unname(mdl$get_param(pattern = "jan")), numeric(0)),
    "No parameters match pattern \"jan\"\\.")
  
  # error
  msg <- "'aap' is not a parameter."
  expect_error(mdl$get_param(names = "aap"), msg)
  
  expect_error(mdl$get_param(names = "aap", pattern = "^i"),  msg)

})

test_that("set_param_values", {
  
  mdl$set_param_values(333, pattern = "^i")
  
  expected_result1 <- rep(333, 6)
  names(expected_result1) <- paste0("i", 0:5)
  expect_equal(mdl$get_param(pattern = "^i"), expected_result1)
  
  mdl$set_param_values(222L, pattern = "^t", names = "m1")
  
  expected_result2 <- rep(222, 3)
  names(expected_result2) <- c("m1", "t0", "t1")
  expect_equal(mdl$get_param(pattern = "^t", names = "m1"), expected_result2)
  
  mdl$set_param_values(NA)
  expect_true(all(is.na(mdl$get_param())))
  
  msg <- "Argument 'value' should be a scalar numeric."
  expect_error(mdl$set_param_values("xxx", names = "m1"), msg)
  expect_error(mdl$set_param_values(1:2, names = "m1"), msg)
})

