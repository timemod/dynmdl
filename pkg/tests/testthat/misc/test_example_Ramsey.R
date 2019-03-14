library(testthat)
library(dynmdl)

rm(list = ls())

model_name <- "example_Ramsey"

context(model_name)

source("../tools/read_dynare_result.R")


per <- period_range("2001/2100")

mod_file <- file.path("mod", paste0(model_name, ".mod"))

expect_warning(
  capture_output(
    msg <- capture.output(
      mdl <- dyn_mdl(mod_file, period = per, nostrict = TRUE),
      type = "message"
    )
  )
  , "1 warnings encountered in the preprocessor. Check the output")

expect_identical(msg,
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
  
  # For comparison with Dynare results, the detrended value of K should be 8.
  # Dynare always works with detrended variables.
  p <- period("2000")
  k_2000_trended <- 8 * as.numeric(mdl$get_trend_data(names = "x", period = p))
  mdl$set_endo_values(k_2000_trended, names = "k", period = p)
  mdl$solve(control = list(silent = TRUE))
  
  expect_equal(mdl$get_endo_data(period = per, trend = FALSE), 
               dynare_result$endo, tol = 1e-6)
  
  # plot(mdl$get_endo_data(names = "k"))
  # lines(dynare_result$endo[, "k"], ylab = "k", col = "red")
})

test_that("trend_data", {
  endo_data <- mdl$get_endo_data()
  exo_data <- mdl$get_exo_data()
  trend_data <- mdl$get_trend_data()
  
  all_data <- cbind(endo_data, exo_data, trend_data)
  
  dif <- tsdif(all_data, mdl$get_data())
  expect_true(dif$equal)
  
  p <- period_range("2002")
  dif2 <- tsdif(all_data[p], mdl$get_data(period = p))
  expect_true(dif2$equal)
  
  c_trend <- mdl$get_data(names = "c")
  c_no_trend <- mdl$get_data(names = "c", trend = FALSE)
  x <- mdl$get_trend_data(names = "x")
  expect_equal(c_no_trend * x, c_trend)
  
  # errors
  expect_error(mdl$get_trend_data(names = "c"), 
               "\"c\" is not a trend variable")
  expect_error(mdl$get_endo_data(names = "x"), 
               "\"x\" is not an endogenous model variable")
})


test_that("write model to file and read again", {
  rds_file <- tempfile(fileext = "rds")  
  outp <- capture_output({
    mdl$write_mdl(rds_file)
    mdl2 <- read_mdl(rds_file)
  })
  expect_equal(mdl, mdl2)
  expect_output(mdl2$solve(), "Convergence after 0 iterations")
  expect_equal(mdl$get_trend_data(), mdl2$get_trend_data())
  expect_equal(mdl$get_endo_data(), mdl2$get_endo_data())
})

