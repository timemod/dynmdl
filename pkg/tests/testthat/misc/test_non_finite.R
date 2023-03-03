library(dynmdl)
library(testthat)


mod_file <- "mod/non_finite.mod"

update_expected_output <- FALSE

model_period <- period_range("2018q1", "2018q1")

report <- capture_output(mdl <- dyn_mdl(mod_file, period = model_period))

test_that("solve_steady", {
  mdl2 <- mdl$copy()
  msg <- paste0("Solving the steady state not succesful.\n",
                "Function value contains non-finite values",
                " \\(starting at index=2\\)")
  expect_known_output(expect_warning(mdl2$solve_steady(), msg),
                      file = "expected_output/non_finite_1.txt",
                      update = update_expected_output)
})

test_that("residual check", {
  
  expected_result <-regts(matrix(c(1, -3), ncol = 2), names = c("eq_1", "eq_2"),
                          start = "2018q1")
  res <- mdl$residual_check()
  expect_equal(res, expected_result)
  
  mdl2 <- mdl$copy()
 
  msg <- paste0("Model solving not succesful.\n",
                "Function value contains non-finite values",
                " \\(starting at index=2\\)")
  expect_known_output(expect_warning(mdl2$solve(homotopy = FALSE,
                                                control = list(trace = FALSE)), msg),
                      file = "expected_output/non_finite_2.txt",
                      update = update_expected_output)
  
  expected_result2 <-regts(matrix(c(0, -Inf), ncol = 2), names = c("eq_1", "eq_2"),
                          start = "2018q1")
  res2 <- mdl2$residual_check()
  expect_equal(res2, expected_result2)
})





