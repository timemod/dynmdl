library(dynmdl)
library(testthat)

rm(list = ls())
context("ISLM model with steady fit procedure")

rds_file <- "islm_model_fit.rds"
model_name <- "islm_fit"

mdl <- read_mdl(rds_file, silent = TRUE)

test_that("set_param for sigma parameters", {
  sigmas <- c(ut = 7, uc = 5, umd = 2, ui = 21)
  names(sigmas) <- paste0("sigma_",  names(sigmas))
  expect_silent(mdl$set_param(sigmas))
  expected_result <- sigmas
  expect_equal(mdl$get_sigmas(), expected_result)
  
  expect_warning(
    expect_equal(mdl$get_param(pattern = "sigma_"), sigmas[character(0)]),
    "No parameters match pattern \"sigma_\"\\.")
  
  expect_warning(
    expect_equal(mdl$get_sigma(pattern = ".+")[names(expected_result)], 
               expected_result),
    NA)
})

endo_names <- c("y", "yd", "t", "c", "i", "md", "r") 
exo_names <- c("g", "ms") 
inames <- c("ut", "uc", "umd", "ui")

l_names <- paste0("l_", 1:7)

mdl_old <- mdl$copy()

get_lagr <- function(mdl) {
  return(mdl$get_all_static_endos()[l_names])
}

test_that("fit instruments are zero in steady state", {
  inst <- mdl$get_static_data(names = inames)
  expect_equal(inst, c(ut = 0, uc = 0., umd = 0, ui = 0))
 
  lagr <- mdl$get_all_static_endos()[l_names]
  nlagr <- length(endo_names)
  lagr_ref <- rep(0, 7)
  names(lagr_ref) <- l_names
  expect_equal(lagr, lagr_ref)
})


fit_targets <- c(y = 1300, t = 250) 
mdl$set_fit_steady(fit_targets)


test_that("fit targets ok", {
  expect_equal(mdl$get_fit_steady(), fit_targets)
})

test_that("solve steady state", {
  mdl$solve_steady(control = list(silent = TRUE))
  expect_equal(mdl$get_static_endos(names = names(fit_targets)), fit_targets)
  expect_true(max(abs(mdl$get_all_static_endos()[l_names])) > 0)
})

test_that("get_static_data", {
  endos <- mdl$get_static_endos()
  exos <- mdl$get_static_exos()
  expect_identical(names(exos), c("g", "ms"))
  fit_inst <- mdl$get_all_static_endos()[inames]
  all_data <- c(endos, exos, fit_inst)
  all_data <- all_data[order(names(all_data))]
  
  expect_equal(mdl$get_static_data(), all_data)
  expect_equal(mdl$get_static_data(names = "g"), all_data["g"])
  
  expect_equal(mdl$get_static_data(names = "ms", pattern = "^y"),
               all_data[c("ms", "y", "yd")])
  
  # errors
  expect_error(mdl$get_static_data(names = "uii"), "\"uii\" is not a model variable\\.")
  
  msg <- "The following names are no exogenous variables: \"ui\", \"aap\"\\."
  expect_error(mdl$get_static_exos(names = c("ui", "aap")), msg)
  
  ref <- c(a = 1)
  ref <- ref[character(0)]
  expect_warning(expect_equal(mdl$get_static_endos(pattern = "^u"), ref),
                 "No endogenous variables match pattern \"\\^u\".")
  
  expect_warning(expect_equal(mdl$get_static_data(pattern = "^z"), numeric(0)),
                 "No model variables match pattern \"\\^z\".")
})

test_that("get_all_static_endos/ get_all_static_data", {
  
  all_endo_data <- mdl$get_all_static_endos()
  all_data <- mdl$get_all_static_data()
  
  expect_equal(setdiff(names(all_data), names(all_endo_data)),
               exo_names)
  
  expect_true(all(l_names %in% names(all_endo_data)))
  expect_true(all(inames %in% names(all_endo_data)))
})

test_that("start solution with correct lagrange multipliers", {
  all_static_endos <- mdl$get_all_static_endos()
  l <- all_static_endos[l_names]
  inst <- all_static_endos[inames]
  endos <- mdl$get_static_endos()
  
  mdl2 <- mdl_old$copy()
  mdl2$set_fit_steady(fit_targets)
  msg <- "The maximum number of iterations \\(1\\) has been reached"
  expect_warning(
    expect_output(
      mdl2$solve_steady(control = list(maxiter = 1)), msg),
    msg)
  mdl2$set_static_data(c(endos, l, inst))
  expect_output(mdl2$solve_steady(), "Convergence after 0 iterations")
})


test_that("too many fit targets", {
  
  mdl2 <- mdl$copy()

  # set fit targets outside model period and with NA values should not mattter
  
  mdl2$set_fit_steady(c(c = 100, y = 1200, yd = 1000, md = 12, i = 3, t = 5))
  msg <- paste("The number of fit targets \\(6\\) exceeds the number",
               "of fit instruments \\(4\\)")
  expect_error(mdl2$solve_steady(), msg)
})

test_that("solve_steady replaces endogenous variables with fit targets before solving", {
  
  mdl$set_static_endos(c(y = 999, t = NA))
 
  # residual check should give errors
  expect_true(max(abs(mdl$static_residual_check()), na.rm = TRUE) > 1e-6)
  expect_true(is.na(max(abs(mdl$static_residual_check()), na.rm = FALSE)))
  
  # solve should convergence in 0 iterations, because it replaced endos with
  # fit targets (if present)
  expect_output(mdl$solve_steady(), "Convergence after 0 iterations")
})

test_that("changing fit instruments", {
  
  mdl2 <- mdl$copy()
  
  mdl2$set_static_data(c(ut = 1, uc = 3))
  expected_result <- mdl$get_all_static_endos()[inames]
  expected_result["ut"] <- 1
  expected_result["uc"] <- 3
  
  expect_equal(mdl2$get_all_static_endos()[inames], expected_result)
  expect_error(mdl2$set_static_endos(c(g = 12)),
               "\"g\" is not an endogenous variable")
})

test_that("clear_fit", {
  mdl2 <- mdl$copy()
  mdl2$clear_fit()
  expect_null(mdl2$get_fit_steady())
  expect_equal(unname(mdl2$get_sigmas()), numeric(0))
  expect_equal(get_lagr(mdl2), get_lagr(mdl) * 0)
  expect_output(mdl2$solve(), "Convergence after 0 iterations")
})


test_that("no fit targets", {
  mdl2 <- mdl$copy()
  mdl2$set_fit_steady(fit_targets * NA)
  expect_null(mdl2$get_fit_steady())
  mdl2$solve_steady(silent = TRUE)
  expect_identical(mdl2$get_lagrange(), mdl$get_lagrange() * 0)
  expect_identical(mdl2$get_fit_instruments(), mdl$get_fit_instruments() * 0)
  expect_equal(mdl2$get_endo_data(), mdl_old$get_endo_data())
})

test_that("no fit targets, removed fit instruments", {
  mdl2 <- mdl$copy()
  mdl2$set_fit_steady(mdl$get_fit_steady() * NA)
  mdl2$set_param_values(-1, names = c("sigma_ut", "sigma_umd"))
  mdl2$solve_steady(silent = TRUE)
  expect_identical(get_lagr(mdl2), get_lagr(mdl) * 0)
  inst_names <- c("uc", "ui")
  expect_identical(mdl2$get_all_static_data()[inst_names], 
                   mdl$get_all_static_data()[inst_names] * 0)
  old_inst_names <- c("ut", "umd")
  expect_identical(mdl2$get_all_static_data()[old_inst_names], 
                   mdl$get_all_static_data()[old_inst_names])
})

test_that("init data and steady fit targets", {
  mdl2 <- mdl$copy()    
  mdl2$set_period("2019q3")
  datap <- period_range("2019q1/2020q1")
  mdl2$init_data(data_period <- datap)
  expect_equal(ncol(mdl2$residual_check(tol = 1e-7)), 0)
  mdl2$set_fit_values(NA)
  mdl2$init_data()
  expect_equal(mdl2$get_data_period(), datap)
  expect_output(mdl2$solve(), "Convergence after 0 iterations")
})