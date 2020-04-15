library(dynmdl)
library(testthat)

rm(list = ls())

context("ISLM model get_equations")

source("utils.R")

mdl <- read_mdl("islm_model.rds", silent = TRUE)
mdl_fit <- read_mdl("islm_model_fit.rds", silent = TRUE)

test_that("get_equations works correctly", {
  
  eqs <- mdl$get_equations()
  expect_known_output(cat_lines(eqs), "expected_output/eqs.txt")
  
  eqs_fit <- mdl_fit$get_equations()
  expect_known_output(cat_lines(eqs_fit), "expected_output/eqs_fit.txt")
  expect_equal(eqs[3], mdl$get_equations(3))
  expect_equal(eqs_fit[c(3,16)], mdl_fit$get_equations(i = c(3,16)))
})

test_that("example with static and dynamic tags", {
  mdl <- dyn_mdl("mod/islm_static_eqs.mod", silent = TRUE)
  expect_known_output(cat_lines(mdl$get_equations()), 
                      "expected_output/eqs_static_tags.txt")
  expect_known_output(cat_lines(mdl$get_original_equations()), 
                      "expected_output/eqs_orig_static_tags.txt")
})


