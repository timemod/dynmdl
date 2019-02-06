library(testthat)
library(dynmdl)

rm(list = ls())

source("../tools/read_dynare_result.R")

model_name <- "example_Ramsey"

per <- period_range("2001/2100")

mod_file <- file.path("mod", paste0(model_name, ".mod"))

expect_warning(
  capture_output(
    message <- capture.output(
      mdl <- dyn_mdl(mod_file, period = per, nostrict = TRUE),
      type = "message"
    )
  )
  , "1 warnings encountered in the preprocessor. Check the output")

expect_identical(message,
"WARNING: gx not used in model block, removed by nostrict command-line option")

dynare_result <- read_dynare_result(model_name, mdl)

test_that("steady state and eigenvalues", {
  
  mdl$solve_steady(control = list(silent = TRUE))
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
  check_report <- capture_output(mdl$check())
  
  eigvals <- mdl$get_eigval()
  expect_equal(Re(eigvals), dynare_result$eigval[, 1])
  expect_equal(Im(eigvals), dynare_result$eigval[, 2])
  
  eigval_data <- read.table(text = check_report, skip = 1, nrow = 2, 
                            header = TRUE)
  expect_equal(eigval_data$Real, Re(eigvals), tol =1e-5)
  expect_equal(abs(eigval_data$Imaginary), abs(Im(eigvals)), tol = 1e-5)
})


test_that("simulation", {
  
  mdl$put_static_endos()
  
  mdl$set_endo_values(8, names = "k", period = "2000")
  mdl$solve(control = list(silent = TRUE))
  
  expect_equal(mdl$get_endo_data(period = per), dynare_result$endo, tol = 1e-6)
  
  # plot(mdl$get_endo_data(names = "k"))
  # lines(dynare_result$endo[, "k"], ylab = "k", col = "red")
})