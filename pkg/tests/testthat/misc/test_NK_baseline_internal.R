library(dynmdl)
library(testthat)
rm(list = ls())
context("NK_baseline model (internal calc.)")

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

# compile the model
model_period <- period_range("2015/2033")
mdl <- dyn_mdl(mod_file, calc = "internal", silent = TRUE, latex = FALSE)
mdl_linlogpow <- dyn_mdl(mod_file_linlogpow, calc = "internal", silent = TRUE)

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
  mdl2$set_endo_values(names = "phi", value = -1, period = p)
  mdl2$set_endo_values(names = "ld", value = -1, period = p)
  
  
  # TODO: with global = "no" an incorrect solution is found (not the real 
  # solution of the model)
  mdl2$solve(control = list(silent = TRUE, trace = TRUE, allow_singular = TRUE,
                            maxiter = 100),  global = "cline")
 
  
  mdl2$set_param(c(eps = -Inf, eps_lp = -Inf))
  mdl2$solve(control = list(silent = TRUE, trace = TRUE, allow_singular = TRUE,
                            maxiter = 100))
  
  expect_equal(mdl2$get_endo_data(period = model_period), dynare_result$endo)
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


test_that("homotopy", {
  mdl2 <- mdl$clone()
  mdl2$put_static_endos()
  p <- start_period(model_period)
  mdl2$set_exo_values(7, names = "epsd", period = p);
  expect_warning(mdl2$solve(silent = TRUE, 
                            control = list(silent = TRUE, trace = FALSE), 
                            homotopy = FALSE),
    "Model solving not succesful\\.\nFunction value contains non-finite values ")
  expect_equal(mdl2$get_solve_status(), "ERROR")
  expect_silent(mdl2$solve(silent = TRUE))
  expect_equal(mdl2$get_solve_status(), "OK")
  expect_output(mdl2$solve(), "Convergence after 0 iterations")
  
  mdl2$put_static_endos()
  report <- capture_output(mdl2$solve(control = list(silent = FALSE, 
                                                     trace = FALSE)))
  report <- gsub("Convergence after \\d+ iterations", 
                 "Convergence after XXX iterations", report)
  expect_known_output(cat(report), 
                      "expected_output/NK_baseline_homotopy_report_1.txt")
  expect_equal(mdl2$get_solve_status(), "OK")
  
  #print(tsdif(mdl$get_endo_data(), mdl2$get_endo_data(), fun = cvgdif, tol = 1e-1))
  #plot(mdl$get_endo_data(names = "f"))
  #lines(mdl2$get_endo_data(names = "f"), col = "red")
})

test_that("homotopy backward for shock in lag", {
  mdl2 <- mdl$clone()
  mdl2$put_static_endos()
  p <- start_period(model_period)
  mdl2$set_endo_values(4, names = "PI", period = "2014")
  expect_warning(mdl2$solve(silent = TRUE, homotopy = FALSE,
                            control = list(maxiter = 100)),
                 "Model solving not succesful\\.\nFunction value contains non-finite values ")
  expect_equal(mdl2$get_solve_status(), "ERROR")
  report <- capture_output({
    mdl2$solve(mode = "backwards", control = list(maxiter = 100),
               homotopy = TRUE, backrep = "total")
  })
  expect_equal(mdl2$get_solve_status(), "OK")
  expect_known_output(cat(report), 
                      "expected_output/NK_baseline_homotopy_report_2.txt")
  
})



test_that("homotopy backwards", {
  
  # with shock epds = 2
  mdl2 <- mdl$clone()
  mdl2$put_static_endos()
  p <- start_period(model_period)
  mdl2$set_exo_values(2, names = "epsd", period = p)
  expect_warning(mdl2$solve(silent = TRUE, homotopy = FALSE,
                            mode = "backwards", control = list(maxiter = 100)),
    "Model solving not succesful\\.\nFunction value contains non-finite values ")
  expect_equal(mdl2$get_solve_status(), "ERROR")
  
  report1 <- capture_output({
    mdl2$solve(mode = "backwards", control = list(maxiter = 100),
               homotopy = TRUE, backrep = "total")
  })
  expect_equal(mdl2$get_solve_status(), "OK")
  report1 <- gsub("Total number of iterations: \\d+", 
                   "Tota number of iterations: XXX", report1)
  expect_known_output(cat(report1), 
                      "expected_output/NK_baseline_homotopy_report_back_1.txt")
  
  # with shock epds = 5
  mdl2 <- mdl$clone()
  mdl2$put_static_endos()
  p <- start_period(model_period)
  mdl2$set_exo_values(5, names = "epsd", period = p)
  report2 <- capture_output({
    mdl2$solve(mode = "backwards", control = list(maxiter = 100),
               homotopy = TRUE, backrep = "total", global = "cline")
  })
  expect_equal(mdl2$get_solve_status(), "OK")
  report2 <- gsub("Total number of iterations: \\d+", 
                  "Tota number of iterations: XXX", report2)
  expect_known_output(cat(report2), 
                      "expected_output/NK_baseline_homotopy_report_back_2.txt")
})

test_that("homotopy backward for shock in lag", {
  mdl2 <- mdl$clone()
  mdl2$put_static_endos()
  p <- start_period(model_period)
  mdl2$set_endo_values(4, names = "PI", period = "2014")
  expect_warning(mdl2$solve(silent = TRUE, homotopy = FALSE,
                            mode = "backwards", control = list(maxiter = 100)),
                 "Model solving not succesful\\.\nFunction value contains non-finite values ")
  expect_equal(mdl2$get_solve_status(), "ERROR")
  report <- capture_output({
    mdl2$solve(mode = "backwards", control = list(maxiter = 100),
               homotopy = TRUE, backrep = "total")
  })
  expect_equal(mdl2$get_solve_status(), "OK")
  expect_known_output(cat(report), 
                      "expected_output/NK_baseline_homotopy_report_back_3.txt")
  
})



