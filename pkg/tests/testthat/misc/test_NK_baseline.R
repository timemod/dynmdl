library(dynmdl)
library(testthat)
rm(list = ls())
context("NK_baseline model")

source("../tools/read_dynare_result.R")

model_name <- "NK_baseline"
mod_file <- file.path("mod", paste0(model_name, ".mod"))
mod_file_linlogpow <- file.path("mod", paste0(model_name, "_linlogpow.mod"))
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
  mdl <- dyn_mdl(mod_file)
  mdl_linlogpow <- dyn_mdl(mod_file_linlogpow)
})
mdl$set_period(model_period)
mdl_linlogpow$set_period(model_period)

dynare_result <- read_dynare_result(model_name, mdl)

test_that("solve_steady", {
  mdl$solve_steady(control = list(trace = FALSE, silent = TRUE))
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
  
  mdl_linlogpow$solve_steady(control = list(trace = FALSE, silent = TRUE))
  expect_equal(mdl_linlogpow$get_static_endos(), dynare_result$steady)
})

test_that("eigenvalues", {
  check_output <- capture_output(mdl$check())
  eigval <- mdl$get_eigval()
  # the last eigenvalues are Inf or almost infinite
  expect_equal(Re(eigval[1:19]), dynare_result$eigval[1:19, 1])
  
  check_output <- capture_output(mdl_linlogpow$check())
  eigval <- mdl_linlogpow$get_eigval()
  # the last eigenvalues are Inf or almost infinite
  expect_equal(Re(eigval[1:19]), dynare_result$eigval[1:19, 1])
})

test_that("solve", {
  mdl2 <- mdl$clone()
  mdl2$put_static_endos()
  p <- start_period(model_period)
  with (as.list(mdl2$get_param()), {
    mdl2$set_exo_values(exp(sigma_d), names = "epsd", period = p);
    mdl2$set_exo_values(exp(sigma_phi), names = "epsphi", period = p);
    mdl2$set_exo_values(exp(sigma_mu), names = "epsmu_I", period = p);
    mdl2$set_exo_values(exp(sigma_A), names = "epsA", period = p);
    mdl2$set_exo_values(exp(sigma_m), names = "epsm", period = p);
  })
  mdl2$solve(control = list(silent = TRUE, trace = FALSE))
  
  expect_equal(mdl2$get_endo_data(period = model_period), dynare_result$endo)
})

test_that("solve linlogpow", {
  mdl2 <- mdl_linlogpow$clone()
  mdl2$put_static_endos()
  p <- start_period(model_period)
  with (as.list(mdl2$get_param()), {
    mdl2$set_exo_values(exp(sigma_d), names = "epsd", period = p);
    mdl2$set_exo_values(exp(sigma_phi), names = "epsphi", period = p);
    mdl2$set_exo_values(exp(sigma_mu), names = "epsmu_I", period = p);
    mdl2$set_exo_values(exp(sigma_A), names = "epsA", period = p);
    mdl2$set_exo_values(exp(sigma_m), names = "epsm", period = p);
  })
  mdl2$solve(control = list(silent = TRUE, trace = FALSE))
  
  expect_equal(mdl2$get_endo_data(period = model_period), dynare_result$endo)
})

test_that("get_equations", {
  eqs <- mdl$get_equations()
  if (.Platform$OS.type == "windows") {
    eqs_tmp <- gsub("\r\n", "\n", eqs)
  } else {
    eqs_tmp <- eqs
  }
  #print(eqs)
  expect_equal_to_reference(eqs_tmp, expected_equations_file)
})

test_that("solve_perturbation (1) compare with dynare result", {
    mdl2 <- mdl$clone()
    mdl2$put_static_endos(period = mdl$get_lag_period())
    p <- start_period(model_period)
    with (as.list(mdl2$get_param()), {
        mdl2$set_exo_values(exp(sigma_d), names = "epsd", period = p);
    })
    mdl2$solve_perturbation()
    
    stoch_per <- get_period_range(dynare_result$stoch_endo)
    stoch_endo <- dynare_result$stoch_endo +
        rep(mdl2$get_static_endos(), each = nperiod(stoch_per))
    expect_equal(mdl2$get_endo_data(period = stoch_per), stoch_endo)
})

test_that("get_names", {
  
  expect_known_output(mdl$get_endo_names(), 
                      "expected_output/NK_baseline_endo_names.rds")
  
  expect_known_output(mdl$get_endo_names(type = "lag"), 
                      "expected_output/NK_baseline_endo_lag_names.rds")
  
  expect_known_output(mdl$get_endo_names(type = "lead"),
                      "expected_output/NK_baseline_endo_lead_names.rds")
  
  expect_known_output(mdl$get_exo_names(),
                      "expected_output/NK_baseline_exo_names.rds")
  
  expect_known_output(mdl$get_par_names(),
                      "expected_output/NK_baseline_par_names.rds")
})
