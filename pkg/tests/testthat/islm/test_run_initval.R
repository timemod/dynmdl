library(testthat)
library(dynmdl)
rm(list = ls())


initval_data_correct <- c(c =500, g = 240, i = 240,  md = 230, ms = 230, r = 3.5, 
                          t = 100, y = 980, yd = 880)

initval_data_fit_correct <- c(c =500, g = 240, i = 240,  md = 230, ms = 230, r = 3.5, 
                             t  = 100, uc = 0, ui = 0, umd = 0, ut = 0,
                             y = 980, yd = 880)

test_that("compiling model silent", {
  expect_silent(mdl <<- dyn_mdl("mod/islm.mod", silent = TRUE))
  expect_silent(mdl_fit <<- dyn_mdl("mod/islm_fit.mod", silent = TRUE))
})

test_that("get_static_data correct", {
  expect_equal(mdl$get_static_data(), initval_data_correct)
  expect_equal(mdl_fit$get_static_data(), initval_data_fit_correct)
})
        
test_that("run_initval for model without fit", {
  mdl2 <- mdl$copy()
  mdl2$set_static_data(c(g = 100, c = 999, yd = 5555,  t = 111))
  mdl2$run_initval()
  expect_equal(mdl2$get_static_data(), initval_data_correct)
})

test_that("run_initval for model with fit", {
  
  # first test: only modify normal endogenous and exogenous variables
  mdl2 <- mdl_fit$copy()
  mdl2$run_initval()
  expect_equal(mdl2$get_static_data(), initval_data_fit_correct)
  
  # run_initval does not modify variables that do not occur in the 
  # left hand side of an equation of the initval block. 
  # There are not set to zero.
  mdl2$set_static_data(c(g = 100, c = 999, yd = 5555,  t = 111, ui = 100))
  mdl2$run_initval()
  expect_equal(mdl2$get_static_data(names = "ui"), c(ui = 100))
  expect_equal(mdl2$get_static_endos(), 
               initval_data_fit_correct[mdl2$get_endo_names()])
  expect_equal(mdl2$get_static_exos(), 
               initval_data_fit_correct[mdl2$get_exo_names()])

  # nu met update_endos = false
  mdl2$set_static_data(c(g = 100, c = 999, yd = 5555,  t = 111, ui = 100))
  new_static_endos <- mdl2$get_static_endos()
  mdl2$run_initval(update_endos = FALSE)
  expect_equal(mdl2$get_static_data(names = "ui"), c(ui = 100))
  expect_equal(mdl2$get_static_endos(), new_static_endos)
  expect_equal(mdl2$get_static_exos(), 
               initval_data_fit_correct[mdl2$get_exo_names()])
})
