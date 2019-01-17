library(dynmdl)
library(testthat)
rm(list = ls())

model_name <- "kern_20x20_v4_leads_fit"

context(paste("model", model_name))

period <- "2010Q2/2011Q1"

# also check result with R version. We do this occasianlly because
# R version of the model is very slow.
check_calc_R <- FALSE

mod_file <- file.path("mod", paste0(model_name, ".mod"))

dum <- capture_output({
  toy_dll <- dyn_mdl(mod_file, period = period, calc  = "dll") 
  toy_internal <- dyn_mdl(mod_file, period = period, calc  = "internal")               
  if (check_calc_R) {
    toy_R <- dyn_mdl(mod_file, period = period, calc  = "R")               
  }
})

test_that("steady state", {
  
  expect_true(is.na(toy_internal$get_solve_status()))
  
  
  expected_warning <- paste0("Solving the steady state not succesful.\n",
                             "The maximum number of iterations \\(1\\) has been reached")
  expect_warning(
    expect_output(
      toy_internal$solve_steady(control = list(maxiter = 1, trace = T)),
      "No convergence after 1 iterations"
    ),
    expected_warning
  )
  expect_equal(toy_internal$get_solve_status(), "ERROR")
              
  # first solve internal calculator and solve
  toy_internal$solve_steady(control = list(maxiter = 6, silent = TRUE))
  
  expect_equal(toy_internal$get_solve_status(), "OK")
  
  expected_output_file <- file.path("expected_output",
                                    paste0(model_name, "_ss.rds"))
  expect_known_value(toy_internal$get_static_endos(),
                            expected_output_file)
  
  # check that the steady state solution is consistent with the
  # dynamic model
  toy_tmp <- toy_internal$copy()
  res <- toy_tmp$residual_check()
  expect_false(all(abs(res) < 1e-8))
  toy_tmp$put_static_endos()
  res <- toy_tmp$residual_check()
  expect_true(all(abs(res) < 1e-8))
  
  expect_output(toy_tmp$solve(control =  list(maxiter = 1)),
                "Convergence after 0 iterations")
  expect_equal(toy_tmp$get_solve_status(), "OK")
  
  # now dll version, the result must be equal
  toy_dll$solve_steady(control = list(maxiter = 6, silent = TRUE))
  expect_equal(toy_dll$get_static_endos(), toy_internal$get_static_endos())
  
  if (check_calc_R) {
    toy_R$solve_steady(control = list(maxiter = 6, silent = TRUE))
    expect_equal(toy_internal$get_static_endos(), toy_R$get_static_endos())
  }
})


# TODO: also check function check

test_that("dynamic model", {
  
  expected_warning <- paste0("Model solving not succesful.\n",
    "The maximum number of iterations \\(1\\) has been reached")
  expect_warning(
    expect_output(
      toy_internal$solve(control = list(maxiter = 1)),
      "No convergence after 1 iterations"
    ),
    expected_warning
  )
  expect_equal(toy_internal$get_solve_status(), "ERROR")
    
  # first solve internal calculator and solve
  toy_internal$solve(control = list(maxiter = 6, silent = TRUE))
  
  expect_equal(toy_internal$get_solve_status(), "OK")
  
  expected_output_file <- file.path("expected_output",
                                    paste0(model_name, "_solve.rds"))
  expect_known_value(toy_internal$get_endo_data(),
                            expected_output_file)
  
  expect_output(toy_internal$solve(control =  list(maxiter = 1)),
                "Convergence after 0 iterations")
  expect_equal(toy_internal$get_solve_status(), "OK")
  
  # now dll version, the result must be equal
  toy_dll$solve(control = list(maxiter = 6, silent = TRUE))
  expect_equal(toy_dll$get_endo_data(), toy_internal$get_endo_data())
  
  if (check_calc_R) {
    toy_R$solve()
    expect_equal(toy_internal$get_endo_data(), toy_R$get_endo_data())
  }
})

