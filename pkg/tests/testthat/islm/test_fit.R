library(dynmdl)
library(testthat)
rm(list = ls())
context("ISLM model with fit procedure")

source("../tools/read_dynare_result.R")

rds_file <- "islm_model_fit.rds"
model_name <- "islm_fit"

report <- capture_output(mdl <- read_mdl(rds_file))

dynare_result <- read_dynare_result(model_name, mdl)

mdl$set_param(c(sigma_ut = 7, sigma_uc = 5, sigma_ui = 21, sigma_umd = 2))

endo_names <- c("y", "yd", "t", "c", "i", "md", "r") 
inames <- c("ut", "uc", "umd", "ui")

mdl_old <- mdl$copy()

test_that("all.equal works correctly for fit models", {
  expect_true(isTRUE(all.equal(mdl, mdl_old)))
})

test_that("steady state and eigenvalues original model", {
  
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
  expect_error(mdl$get_eigval(), 
               paste("Eigenvalues not available.",
                     "Calculate the eigenvalues with method check\\(\\)."))
  
  check_report <- capture_output(mdl$check())
  
  eigvals <- mdl$get_eigval()
  expect_equal(eigvals[1:6], dynare_result$eigval[1:6, 1])
  expect_equal(is.finite(eigvals[7:8]), c(FALSE, FALSE))
  
  tmpfile <- tempfile()
  write(check_report, tmpfile)
  eigval_data <- read.table(tmpfile, skip = 1, nrow = 8, header = TRUE)
  expect_equal(eigval_data$Real, Re(eigvals), tolerance = 1e-6)
  expect_equal(eigval_data$Imaginary, Im(eigvals), tolerance = 1e-6)
})



test_that("check steady state is compatible with dynamic model", {
  expect_output(mdl$solve(), "Convergence after 0 iterations")   
})



mdl$set_fit(regts(c(1250, 1255, 1260), start = "2016Q1"), names = "y")
mdl$set_fit(regts(c(250, 255), start = "2016Q1"), names = "t")

fit_targets <- mdl$get_fit()

test_that("all.equal works correctly for fit models", {
  expect_false(isTRUE(all.equal(mdl, mdl_old)))
})

mdl$solve(control = list(silent = TRUE))


dynare_endo <- update_ts_labels(dynare_result$endo, mdl$get_labels())

test_that("dynare result equal to islm result", {
  p <- mdl$get_period()
  expect_equal(dynare_endo, mdl$get_endo_data(period = p))
})


test_that("get_data", {
  p <- mdl$get_period()
  mdp <- mdl$get_data_period()
  endo_data <- mdl$get_endo_data()
  exo_data <- mdl$get_exo_data()
  expect_identical(colnames(exo_data), c("g", "ms"))
  fit_inst <- mdl$get_fit_instruments(period = mdp)
  all_data <- cbind(endo_data, exo_data, fit_inst)
  all_data <- all_data[, order(colnames(all_data))]

  expect_equal(mdl$get_data(), all_data)
  expect_equal(mdl$get_data(names = "g", period = p),
              all_data[p, "g", drop = FALSE])

  expect_equal(mdl$get_data(names = "ms", pattern = "^y",
                             period = p),
                all_data[p, c("ms", "y", "yd")])

  # errors
  expect_error(mdl$get_fit_instruments(names = "uii"), 
               "\"uii\" is not a fit instrument")
  expect_error(mdl$get_fit_instruments(names = c("uc", "uii", "aap")), 
               "\"uii\", \"aap\" are no fit instruments")
  expect_error(mdl$get_data(names = "uii"), "\"uii\" is not a model variable")
  expect_error(mdl$get_exo_data(names = c("ui", "aap")),
              "\"ui\", \"aap\" are no exogenous model variables")

  expect_null(mdl$get_endo_data(pattern = "^u"))
  expect_null(mdl$get_data(pattern = "^z"))
  expect_null(mdl$get_fit_instruments(pattern = "^z"))
  
})


test_that("get_names", {

  expect_equal(mdl$get_endo_names(), endo_names)

  expect_equal(mdl$get_endo_names(type = "lag"), c("y", "yd"))
  expect_equal(mdl$get_endo_names(type = "lead"), c("y", "yd"))

  expect_equal(mdl$get_exo_names(), c("g", "ms"))

  par_names <- c(paste0("sigma_u", c("t", "c", "i", "md")),
                 paste0("c", 0:5), paste0("i", 0:5), paste0("m", 0:3),
                 paste0("t", 0:1))
  expect_equal(mdl$get_par_names(), par_names)


  expect_equal(mdl$get_sigma_names(), paste0("sigma_", inames))
})

test_that("start solution with correct lagrange multipliers", {
  l <- mdl$get_lagrange()
  inst <- mdl$get_fit_instruments()
  endo_data <- mdl$get_endo_data(period = mdl$get_period())

  mdl2 <- mdl_old$copy()
  mdl2$set_fit(fit_targets)
  msg <- "The maximum number of iterations \\(1\\) has been reached"
  expect_warning(
    expect_output(
      mdl2$solve(control = list(maxiter = 1)), msg),
    msg)
  mdl2$set_data(cbind(endo_data, l, inst))
  expect_output(mdl2$solve(), "Convergence after 0 iterations")
})

test_that("miscellaneous set functions", {
  
  mdl$set_endo_values(2, names = "l_2")
  expect_identical(mdl$get_lagrange(names = "l_2")[, 1],
                   regts(2, period = mdl$get_period()))
  
  # errors
  expect_error(mdl$set_static_endos(c(l_2 = 2)),
               "\"l_2\" is not an endogenous model variable")
  
  expect_error(mdl$set_fit_values(2, names = c("g", "l_2")),
               "\"g\", \"l_2\" are no endogenous model variables")
  
  
  x <- regts(matrix(1, nrow = 2, ncol = 3), names = c("g", "l_2", "y"),
             period = "2016Q1")
  expect_error(mdl$set_fit(x), "\"g\", \"l_2\" are no endogenous model variables")
})

test_that("get_vars_pars", {
  
  vars_pars <- mdl$get_vars_pars("2016Q1/2016q2")
  
  pars <- unlist(vars_pars[mdl$get_par_names()])
  expect_identical(pars, mdl$get_param())
  
  var_names <- setdiff(names(vars_pars), names(pars))
  vars <- vars_pars[var_names]
  var_data <- do.call(cbind, vars)
  expect_identical(var_data, mdl$get_data(period = "2016q1/2016q2"))
})





