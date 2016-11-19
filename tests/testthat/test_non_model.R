library(dynr)
context("non existing mod file")

test_that("compile_model gives an error", {
    capture_output(expect_error(compile_model("non_existing.mod"),
       "ERROR: Could not open file: non_existing.mod"))
    capture_output(expect_error(compile_model("test_ifn.R"),
        "ERROR: test_ifn.R: line 66, cols 1-0: syntax error, unexpected \\$end"))
})
