library(dynmdl)
library(testthat)
rm(list = ls())

update_expected_output <- FALSE

source("../tools/read_dynare_result.R")
source("../tools/cat_lines.R")

mod_name <- "islm_init_param"
mod_file <- file.path("mod", paste0(mod_name, ".mod"))

test_that("uninitialized parameters are set to zero", {
  expect_warning(
    warnings <- capture.output(
      mdl <- dyn_mdl(mod_file, silent = TRUE), type = "message"),
    "2 warnings encountered in the preprocessor. Check the output")
  expect_silent(dyn_mdl(mod_file, silent = TRUE, warn_uninit_param = FALSE))
  
  expect_known_output(cat_lines(warnings), 
                      "expected_output/init_param_zero.txt",
                      update = update_expected_output)
  
  expect_equal(mdl$get_param(names = c("c0", "t1")),
               c(c0 = 0, t1 = 0))
  
  expect_equal(mdl$get_static_endos(names = "i"), c(i = 0))
})

test_that("uninitialized parameters are set to NA", {
  expect_warning(
    warnings <- capture.output(
      mdl <- dyn_mdl(mod_file, silent = TRUE, init_param_na = TRUE), 
      type = "message"),
    "2 warnings encountered in the preprocessor. Check the output")
  expect_silent(dyn_mdl(mod_file, silent = TRUE, warn_uninit_param = FALSE,
                        init_param_na = TRUE))
  
  expect_known_output(cat_lines(warnings), "expected_output/init_param_na.txt",
                      update = update_expected_output)
  
  expect_equal(mdl$get_param(names = c("c0", "t1")),
               c(c0 = NA_real_, t1 = NA_real_))
})
