library(dynmdl)
library(testthat)
rm(list = ls())
context("NK_baseline model fit")

source("../tools/read_dynare_result.R")

model_name <- "NK_baseline"
mod_file <- file.path("mod", paste0(model_name, "_fit.mod"))
dynare_dir     <- "dynare/output"
param_name_file <-  file.path(dynare_dir, "NK_baseline_param_names.txt")
param_value_file <-  file.path(dynare_dir, "NK_baseline_param_values.txt")

steady_data_file <- file.path(dynare_dir, "NK_baseline_steady.csv")
eigval_file <- file.path(dynare_dir, "NK_baseline_eigval.csv")
start_period <- period("2015")

# compile the model
model_period <- period_range("2015/2033")
mdl <- dyn_mdl(mod_file, calc = "internal", silent = TRUE, latex = FALSE)
mdl$set_period(model_period)

test_that("no latex directory created", {
  expect_false(dir.exists("latex"))
})

dynare_result <- read_dynare_result(model_name, mdl)

test_that("solve_steady", {
  mdl$solve_steady(control = list(trace = FALSE, silent = TRUE))
  mdl$put_static_endos()
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
})


test_that("solve with disabled fit procedure", {
  mdl2 <- mdl$clone()
  mdl2$set_param_values(-1, pattern = "sigma_eps.+")
  p <- start_period(model_period)
  with (as.list(mdl2$get_param()), {
    mdl2$set_endo_values(exp(sigma_d), names = "epsd", period = p);
    mdl2$set_endo_values(exp(sigma_phi), names = "epsphi", period = p);
    mdl2$set_endo_values(exp(sigma_mu), names = "epsmu_I", period = p);
    mdl2$set_endo_values(exp(sigma_A), names = "epsA", period = p);
    mdl2$set_endo_values(exp(sigma_m), names = "epsm", period = p);
  })
  mdl2$solve(silent = TRUE, control = list(trace = FALSE))
  
  expect_equal(mdl2$get_endo_data(period = model_period), dynare_result$endo)
})

test_that("solve with fit procedure but without fit targets", {
  mdl2 <- mdl$clone()
  p <- start_period(model_period)
  with (as.list(mdl2$get_param()), {
     mdl2$set_endo_values(exp(sigma_d), names = "epsd", period = p);
     mdl2$set_endo_values(exp(sigma_phi), names = "epsphi", period = p);
     mdl2$set_endo_values(exp(sigma_mu), names = "epsmu_I", period = p);
     mdl2$set_endo_values(exp(sigma_A), names = "epsA", period = p);
     mdl2$set_endo_values(exp(sigma_m), names = "epsm", period = p);
  })
  mdl2$solve(silent = TRUE, control = list(trace = FALSE))
  # the model should converge back to the steady state result
  expect_equal(mdl2$get_endo_data(), mdl$get_endo_data())
})


test_that("solve with fit procedure (1 target)", {
  mdl2 <- mdl$copy()
  fit_per <- period_range("2015/2018")
  mdl2$set_fit_values(5, names = "f", period = fit_per)

  report <- capture_output(mdl2$solve(control = list(silent = FALSE, 
                                                     trace = FALSE)))
  
  report <- gsub("Convergence after \\d+ iterations", 
                 "Convergence after XXX iterations", report)
  expect_known_output(cat(report), 
                     "expected_output/NK_baseline_fit_homotopy_report.txt")
  
  
  expect_equal(mdl2$get_solve_status(), "OK")
 
  
  expect_equal(mdl2$get_endo_data(names = "f", period = fit_per),
               regts(matrix(5, nrow = 4), period = fit_per, names = "f"),
               check.attributes = FALSE)
})


test_that("solve with fit procedure (2 targets)", {
  
  mdl2 <- mdl$clone()
  
  fit_per1 <- period_range("2015/2018")
  fit_per2 <- period_range(2015, 2015)
  mdl2$set_fit_values(5, names = "f", period = fit_per1)
  mdl2$set_fit_values(0.91234, names = "u", period = fit_per2)
  
  # first solve without homotopy -> should fail
  expect_warning(mdl2$solve(silent = TRUE, homotopy = FALSE))
  expect_equal(mdl2$get_solve_status(), "ERROR")
 

  expect_silent(mdl2$solve(silent = TRUE))
  expect_equal(mdl2$get_solve_status(), "OK")
  expect_output(mdl$solve(), "Convergence after 0 iterations")
  
  
  expect_equal(mdl2$get_endo_data(names = "f", period = fit_per1),
               regts(matrix(5, nrow = 4), period = fit_per1, names = "f"),
               check.attributes = FALSE)
  expect_equal(mdl2$get_endo_data(names = "u", period = fit_per2),
               regts(matrix(0.91234, nrow = 1), period = fit_per2, names = "u"),
               check.attributes = FALSE)
})

