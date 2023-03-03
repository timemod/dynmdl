library(dynmdl)
library(testthat)
rm(list = ls())


mod_file <- "mod/check2.mod"
update_expected_output <- FALSE

mdl <- dyn_mdl(mod_file, silent = TRUE)

mdl$solve_steady(silent = TRUE)

params <- as.list(mdl$get_param())

BB_msgs <- c("", "Blanchard & Kahn conditions are not satisfied: no stable equilibrium",
            "")

test_that("steady state", {
  # calculate analytial steady state
  expect_equal(mdl$get_static_endos(), c(c = 0, d = 0))
})

run_check <- function(...) {
  messages <- capture.output(
    output <- capture_output(mdl$check(...)),
    type = "message")
  return(list(output = output, messages = messages))
}

test_that("eigenvalues", {
  ret <- run_check()
  expect_equal(ret$messages, BB_msgs)
  expect_known_output(cat(ret$output), "expected_output/check2_1.txt",
                      update = update_expected_output)
  eigvals <- mdl$get_eigval()
  expect_equal(eigvals, c(1, 4))
})

test_that("parameter close to 1", {
  eps <- 1.0e-10
  mdl$set_param(c(c1 = 1 + eps))
  ret1 <- run_check()
  expect_equal(ret1$messages, character(0))
  expect_known_output(cat(ret1$output), "expected_output/check2_2.txt",
                      update = update_expected_output)
  
  ret2 <- run_check(tol = eps / 2)
  expect_equal(ret2$messages, BB_msgs)
  expect_known_output(cat(ret2$output), "expected_output/check2_3.txt",
                      update = update_expected_output)
  
  ret3 <- run_check(tol = 1e-12)
  expect_equal(ret2$messages, BB_msgs)
  expect_known_output(cat(ret2$output), "expected_output/check2_4.txt",
                      update = update_expected_output)
})
