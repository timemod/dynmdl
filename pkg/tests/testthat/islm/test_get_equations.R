library(dynmdl)
library(testthat)

rm(list = ls())


update_expected_output <- FALSE

source("../tools/cat_lines.R")

mdl <- read_mdl("islm_model.rds", silent = TRUE)
mdl_fit <- read_mdl("islm_model_fit.rds", silent = TRUE)

test_that("get_equations works correctly", {
  
  eqs <- mdl$get_equations()
  expect_known_output(cat_lines(eqs), "expected_output/eqs.txt",
                      update = update_expected_output)
  
  eqs_fit <- mdl_fit$get_equations()
  expect_known_output(cat_lines(eqs_fit), "expected_output/eqs_fit.txt",
                      update = update_expected_output)
  expect_equal(eqs[3], mdl$get_equations(3))
  expect_equal(eqs_fit[c(3,16)], mdl_fit$get_equations(i = c(3,16)))
})

test_that("example with static and dynamic tags", {
  mdl <- dyn_mdl("mod/islm_static_eqs.mod", silent = TRUE)
  expect_known_output(cat_lines(mdl$get_equations()), 
                      "expected_output/eqs_static_tags.txt",
                      update = update_expected_output)
  expect_known_output(cat_lines(mdl$get_original_equations()), 
                      "expected_output/eqs_orig_static_tags.txt",
                      update = update_expected_output)
  
  stat_eqs <- mdl$get_static_equations()
  expect_known_output(cat_lines(stat_eqs), 
                      "expected_output/static_eqs.txt",
                      update = update_expected_output)
  expect_equal(stat_eqs[3], mdl$get_static_equations(3))
})


