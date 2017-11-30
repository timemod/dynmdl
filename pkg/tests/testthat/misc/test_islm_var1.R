library(dynmdl)
library(testthat)
rm(list = ls())
source("read_dynare_result.R")

context("ISLM variant1")

model <- "islm_var1"

mod_file <- file.path("mod", paste0(model, ".mod"))

expected_equations_file <- "expected_output/expected_equations_islm_var1.rds"

# compile the model 
report <- capture_output(mdl <- dyn_mdl(mod_file, period = "2015/2027"))

dynare_result <- read_dynare_result("islm_var1", mdl)

test_that("solve_steady", {
  mdl$solve_steady(control = list(trace = FALSE, silent = TRUE))
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
})

test_that("solve", {
  mdl2 <- mdl$clone()
  mdl2$set_data(dynare_result$endo[mdl$get_lag_period()])
  mdl2$set_data(dynare_result$endo[mdl$get_lead_period()])
  mdl2$set_data(dynare_result$exo)
  mdl2$solve(control = list(silent = TRUE, trace = FALSE))
  expect_equal(mdl2$get_endo_data(), dynare_result$endo)
})

test_that("check", {
  msg <- paste("Function solve_first_order does not work for models with",
               "max_lag > 1 or max_lead > 1.\n Tip: call function dyn_mdl",
              "with option max_laglead = TRUE.")
  capture_output(expect_error(mdl$check(), msg))
})

# now compile the model with option max_laglead_1
report <- capture_output(mdl_new <- dyn_mdl(mod_file, period = "2015/2027",
                                            max_laglead_1 = TRUE))

test_that("solve_steady", {
  mdl_new$solve_steady(control = list(trace = FALSE, silent = TRUE))
  expect_equal(mdl_new$get_static_endos(), dynare_result$steady)
})

test_that("solve", {
  mdl2 <- mdl_new$clone()
  mdl2$set_data(dynare_result$endo[mdl$get_lag_period()])
  mdl2$set_data(dynare_result$endo[mdl$get_lead_period()])
  mdl2$set_data(dynare_result$exo)
  mdl2$solve(control = list(silent = TRUE, trace = FALSE))
  expect_equal(mdl2$get_endo_data(), dynare_result$endo)
})

test_that("eigenvalues", {
  capture_output(mdl_new$check())
  eigval <- mdl_new$get_eigval()
 
  # the last eigenvalues is Inf or almost infinite
  expect_equal(Re(eigval)[1:10], dynare_result$eigval[1:10, 1])
  expect_equal(Im(eigval)[1:10], dynare_result$eigval[1:10, 2])
})

test_that("get_equations", {
  eqs <- mdl_new$get_equations()
  if (.Platform$OS.type == "windows") {
    eqs_tmp <- gsub("\r\n", "\n", eqs)
  } else {
    eqs_tmp <- eqs
  }
  #print(eqs)
  expect_equal_to_reference(eqs_tmp, expected_equations_file)
})



# 
# NOTE:
# solve_perturbation does currently not work for the islm_var1 model.
# this problem has to be solved.
#
# test_that("solve_perturbation (1) compare with dynare result", {
#     mdl2 <- mdl$clone()
#     p <- start_period(model_period)
#     with (as.list(mdl2$get_param()), {
#         mdl2$set_exo_values(exp(sigma_d), names = "epsd", period = p);
#     })
#     mdl2$solve_perturbation()
# 
#     # read in Dynare result (stoch_simul calculation)
#     stoch_endo_data <- t(as.matrix(read.csv(stoch_endo_data_file, header = FALSE)))
#     stoch_per <- period_range(start_period(model_period), end_period(data_period))
#     dynare_stoch_result <- regts(stoch_endo_data, period = stoch_per, names = endo_names)
#     dynare_stoch_result <- dynare_stoch_result +
#         rep(mdl$get_static_endos(), each = nperiod(stoch_per))
# 
#     expect_equal(mdl2$get_endo_data(period = stoch_per), dynare_stoch_result)
#     mdl2$get_endo_data(period = stoch_per) - dynare_stoch_result
# })
