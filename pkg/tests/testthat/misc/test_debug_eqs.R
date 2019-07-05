library(dynmdl)
library(testthat)

context("test debug equations")

mod_file <- "mod/test_debug_eqs.mod"

model_period <- period_range("2018q1", "2019q1")

report <- capture_output(mdl <- dyn_mdl(mod_file, period = model_period, 
                                        calc = "internal"))

test_that("solve and residual check", {
  mdl$set_exo_values(c(-1.123e23, -1, -0.12e-18, 0, 1), period = model_period, 
                     names = "x")
  
  expect_warning(
    messages <- capture.output(mdl$solve(control = list(silent = TRUE), 
                                         debug_eqs = TRUE, 
                                         force_stacked_time = TRUE,
                                         homotopy = FALSE),
                        type = "message"))
  
  
  # On some platforms (e.g. Windows) numbers in scientific notation are printed
  # with a leading zero after the exponent, on other platforms not. Therefore 
  # remove the 0. Therefore remove a zero.
  messages <- sub("[eE]([+-]?)0+", "e\\1", messages)
  
  expect_known_output(messages, print = TRUE,
                      file = "expected_output/test_debug_eqs_solve.txt")
  
  expect_silent(
    messages <- capture.output(dum <- mdl$residual_check(debug_eqs = TRUE),
                               type = "message"))
  

  messages <- sub("[eE]([+-]?)0+", "e\\1", messages)
  expect_known_output(messages, print = TRUE,  
                      file = "expected_output/test_debug_eqs_solve.txt")
  
})



test_that("solve_steady", {
  
  expect_warning(
    messages <- capture.output(mdl$solve_steady(debug = TRUE, 
                                              control = list(silent = TRUE)),
                             type = "message"))
  
  expect_known_output(messages, print = TRUE, 
                             file = "expected_output/test_debug_eqs_solve_steady.txt")
  
})



