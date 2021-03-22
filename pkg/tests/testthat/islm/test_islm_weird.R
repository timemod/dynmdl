library(utils)
library(dynmdl)
library(testthat)

rm(list = ls())

context("islm model with weird mod files")

mdl_base <- read_mdl("islm_model.rds", silent = TRUE)

test_that("unused endos", {
  
  mod_file <- "mod/islm_unused_endos.mod"
  
  emsg <- paste("ERROR: the following endogenous variable\\(s\\) not used in",
                "model block\n\\(to bypass this error, use argument",
                "strict = FALSE\\):\n \"a\" \"abcdefgh\"\\.")
  expect_error(capture.output(dyn_mdl(mod_file)), emsg)
  
  expect_warning(
    msg <- capture.output(
      mdl <- dyn_mdl(mod_file, strict = FALSE, silent = TRUE),
      type = "message"),
    "1 warnings encountered in the preprocessor. Check the output")
  expect_equal(msg, paste("WARNING: the following endogenous variable(s) not",
                          "used in model block are removed because",
                          "strict = FALSE: \"a\" \"abcdefgh\"."))
  mdl$init_data(data = mdl_base$get_data())
  expect_output(mdl$solve(), "Convergence after 0 iterations")
  expect_equal(mdl$get_endo_data(), mdl_base$get_endo_data())
})


test_that("unused exos", {
  
  mod_file <- "mod/islm_unused_exos.mod"
  
  emsg <- paste("ERROR: the following exogenous variable\\(s\\) not used in",
                "model block\n\\(to bypass this error, use argument",
                "strict = FALSE\\):\n \"a\" \"abcdefgh\"\\.")
  expect_error(capture.output(dyn_mdl(mod_file)), emsg)
  
  expect_warning(
    msg <- capture.output(
      outp <- capture.output(mdl <- dyn_mdl(mod_file, strict = FALSE)),
      type = "message"),
    "1 warnings encountered in the preprocessor. Check the output")
  expect_equal(msg, paste("WARNING: the following exogenous variable(s) not",
                          "used in model block: \"a\" \"abcdefgh\"."))
  mdl$init_data(data = mdl_base$get_data())
  expect_output(mdl$solve(), "Convergence after 0 iterations")
  expect_equal(mdl$get_endo_data(), mdl_base$get_endo_data())
  
  warnings <- capture_warnings(
    msg <- capture.output(
      outp <- capture.output(mdl2 <- dyn_mdl(mod_file, nostrict = TRUE)),
      type = "message")
  )
  expect_equal(warnings, 
               c("Argument 'nostrict' is obsolete. Use argument 'strict' instead.",
                 "1 warnings encountered in the preprocessor. Check the output"))
  expect_equal(msg, paste("WARNING: the following exogenous variable(s) not",
                          "used in model block: \"a\" \"abcdefgh\"."))
  mdl2$init_data(data = mdl_base$get_data())
  expect_output(mdl2$solve(), "Convergence after 0 iterations")
  expect_equal(mdl2$get_endo_data(), mdl_base$get_endo_data())
})

test_that("unknown initval", {
  mod_file <- "mod/islm_unknown_initval.mod"

  emsg <- paste("ERROR: mod/islm_unknown_initval.mod: line 40, cols 1-6:",
                "Unknown symbol: a")
  expect_error(capture.output(dyn_mdl(mod_file)), emsg)
  
  expect_warning(
    msg <- capture.output(
      outp <- capture.output(mdl <- dyn_mdl(mod_file, strict = FALSE)),
      type = "message"),
    "2 warnings encountered in the preprocessor. Check the output")
  expect_equal(msg, 
               c(paste("WARNING: mod/islm_unknown_initval.mod:40.1-6: discarding 'a'",
                       "as it was not recognized in the initval or endval statement"),
                 paste("WARNING: mod/islm_unknown_initval.mod:41.1-14: discarding 'abcdefgh'",
                       "as it was not recognized in the initval or endval statement")))
             
  mdl$init_data(data = mdl_base$get_data())
  expect_output(mdl$solve(), "Convergence after 0 iterations")
  expect_equal(mdl$get_endo_data(), mdl_base$get_endo_data())
  expect_error(capture.output(dyn_mdl(mod_file)), emsg)
})


