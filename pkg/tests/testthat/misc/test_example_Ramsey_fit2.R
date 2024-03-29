library(testthat)
library(dynmdl)

rm(list = ls())

model_name <- "example_Ramsey_fit2"


source("../tools/read_dynare_result.R")

per <- period_range("2001/2100")

mod_file <- file.path("mod", paste0(model_name, ".mod"))

test_that("dyn_mdl gives a warning", {
  wmsg <- paste("WARNING: trends not compatible with balanced growth",
                "path; the second-order cross partial of equation 1",
                 "\\(line 34\\) w\\.r\\.t\\. trend variable x and endogenous",
                 "variable eps_1 is not null\\.")
  expect_warning(
    mdl <<- dyn_mdl(mod_file, period = per, silent = TRUE),
    wmsg)
})

dynare_result <- read_dynare_result(sub("_fit2$", "", model_name), mdl)

test_that("steady state and eigenvalues", {
  
  mdl$solve_steady(control = list(silent = TRUE))
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
  check_report <- capture_output(mdl$check())
  
  eigvals <- mdl$get_eigval()
  
  # two of the four eigenvalues should be nearly equal to the Dynare result
  expect_equal(Re(eigvals)[c(2, 4)], dynare_result$eigval[, 1])
  expect_equal(Im(eigvals)[c(2, 4)], dynare_result$eigval[, 2])
  
  eigval_data <- read.table(text = check_report, skip = 1, nrow = 4, 
                            header = TRUE)
  expect_equal(eigval_data$Real, Re(eigvals), tol =1e-5)
  expect_equal(abs(eigval_data$Imaginary), abs(Im(eigvals)), tol = 1e-5)
})


test_that("simulation", {
  
  mdl$put_static_endos()
  expect_output(mdl$solve(), "Convergence after 0 iterations")
  
  # For comparison with Dynare results, the detrended value of K should be 8.
  # Dynare always works with detrended variables.
  p <- period("2000")
  k_2000_trended <- 8 * as.numeric(mdl$get_trend_data(names = "x", period = p))
  mdl$set_endo_values(k_2000_trended, names = "k", period = p)
  mdl$solve(silent = TRUE)
  
  expect_equal(mdl$get_endo_data(period = per, trend = FALSE), 
               dynare_result$endo, tol = 1e-6)
  
  
  # now fit c. c is a variable with a trend.
  mdl_fit <- mdl$copy()
  fit_targets <- regts(matrix(c(1.06, 1.07), ncol = 1), start = 2005, names = "c")
  mdl_fit$set_fit(fit_targets)
  mdl_fit$solve(silent = TRUE)
  expect_equal(mdl_fit$get_endo_data(period = get_period_range(fit_targets),
                                  names = colnames(fit_targets)), fit_targets, 
               check.attributes = FALSE)
})
