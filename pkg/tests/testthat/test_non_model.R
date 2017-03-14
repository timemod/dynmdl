library(dynmod)
context("non existing mod file")

test_that("create_mod gives an error", {
    capture_output(expect_error(create_mod("non_existing.mod"),
       "ERROR: Could not open file: non_existing.mod"))
    capture_output(expect_error(create_mod("test_ifn.R"),
        "ERROR: test_ifn.R: line 66, cols 1-0: syntax error, unexpected \\$end"))
})
