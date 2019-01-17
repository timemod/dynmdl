library(utils)
library(dynmdl)
library(testthat)

context("set/get parameters")

x <- capture_output(mdl <- read_mdl("islm_model.rds"))

pars <- mdl$get_param()

test_that("set_param", {
  
  par <- c(i3 = 999)
  mdl$set_param(par)
  expect_identical(mdl$get_param(names = "i3"), par)
  
  # errors
  expect_error(mdl$set_param(c(aap = 9999)),
               "aap is/are no model parameter\\(s\\)")
  
  expect_error(mdl$set_param(c(i3 = 999, aap = 999, jan = 999)),
               "aap, jan is/are no model parameter\\(s\\)")
  
  expect_error(mdl$set_param(2), "params is not a named numeric vector")
})

test_that("get_param", {
  
  x1 <- mdl$get_param(pattern = "^c", names = "i1")
  expect_identical(x1, pars[c("i1", paste0("c", 0:5))])
  
  x2 <- mdl$get_param(pattern = "^aap", names = "i1")
  expect_identical(x2, pars["i1"])
  
  expect_identical(unname(mdl$get_param(pattern = "jan")), numeric(0))
  
  # error
  expect_error(mdl$get_param(names = "aap"),
               "aap is/are no model parameter\\(s\\)")
  
  expect_error(mdl$get_param(names = "aap", pattern = "^i"),
               "aap is/are no model parameter\\(s\\)")
})

test_that("set_param_values", {
  
  mdl$set_param_values(333, pattern = "^i")
  
  expected_result1 <- rep(333, 6)
  names(expected_result1) <- paste0("i", 0:5)
  expect_equal(mdl$get_param(pattern = "^i"), expected_result1)
  
  mdl$set_param_values(222, pattern = "^t", names = "m1")
  
  expected_result2 <- rep(222, 3)
  names(expected_result2) <- c("m1", "t0", "t1")
  expect_equal(mdl$get_param(pattern = "^t", names = "m1"), expected_result2)
})