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
expected_equations_file <- "expected_output/expected_equations.rds"

# compile the model
model_period <- period_range("2015/2033")
report <- capture_output({
  mdl <- dyn_mdl(mod_file, calc = "internal")
})
mdl$set_period(model_period)

#dynare_result <- read_dynare_result(model_name, mdl)

test_that("solve_steady", {
  mdl$solve_steady(control = list(trace = FALSE, silent = TRUE))
  mdl$put_static_endos()
  #expect_equal(mdl$get_static_endos(), dynare_result$steady)
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
  mdl2$solve(control = list(silent = TRUE, trace = FALSE))
  
  #expect_equal(mdl2$get_endo_data(period = model_period), dynare_result$endo)
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
  mdl2$solve(control = list(silent = TRUE, trace = TRUE))
  # the model should converge back to the steady state result
  expect_equal(mdl2$get_endo_data(), mdl$get_endo_data())
})


test_that("solve with fit procedure and fit targets", {
  mdl2 <- mdl$clone()
  mdl2$set_fit_values(5, names = "f", period = "2015/2018")
  mdl2$serialize()$mdldef$exos
  mdl2$solve(control = list(silent = FALSE, trace = TRUE), homotopy = TRUE)
  #mdl2$solve(control = list(silent = FALSE, trace = TRUE), homotopy = FALSE)
  # the model should converge back to the steady state result
  plot(mdl2$get_fit_instruments())
  plot(mdl2$get_endo_data(names = "f"))
  
  # TODO: compare with DYnare result?
})
