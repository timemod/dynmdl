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

mdp <- mdl$get_data_period()

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

test_that("fit instruments are zero in steady state", {
  inst <- mdl$get_fit_instruments(period = mdp)
  inst_ref <- regts(matrix(0, ncol = length(inames)), names = inames,
                    period = mdp)
  ts_labels(inst_ref) <- ts_labels(inst)
  expect_equal(inst, inst_ref)
  
  lagr <- mdl$get_lagrange(period = mdp)
  nlagr <- length(endo_names)
  lagr_ref <- regts(matrix(0, ncol = nlagr), names = paste0("l_", 1:nlagr),
                    period = mdp)
  expect_equal(lagr, lagr_ref)
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
               "\"uii\" is not a fit instrument\\.")
  msg <- "The following names are no fit instruments: \"uii\", \"aap\"\\."
  expect_error(mdl$get_fit_instruments(names = c("uc", "uii", "aap")),  msg)
  expect_error(mdl$get_data(names = "uii"), "\"uii\" is not a model variable\\.")
  
  msg <- "The following names are no exogenous variables: \"ui\", \"aap\"\\."
  expect_error(mdl$get_exo_data(names = c("ui", "aap")), msg)
  
  expect_warning(expect_null(mdl$get_endo_data(pattern = "^u")),
                 "No endogenous variables match pattern \"\\^u\".")
  
  expect_warning(expect_null(mdl$get_data(pattern = "^z")),
                 "No model variables match pattern \"\\^z\".")
  
  expect_warning(expect_null(mdl$get_fit_instruments(pattern = "^z")),
                 "No fit instruments match pattern \"\\^z\".")
})


test_that("set_exo_values", {
  mdl2 <- mdl$copy()
  mdl2$set_static_exo_values(0)
  expect_identical(mdl2$get_static_exos(), c(g = 0, ms = 0))
  mdl2$set_static_exo_values(2, pattern = "^m")
  expect_identical(mdl2$get_static_exos(), c(g = 0, ms = 2))
  mdl2$set_static_exo_values(3, names = "g")
  expect_identical(mdl2$get_static_exos(), c(g = 3, ms = 2))
  
  expect_error(mdl2$set_static_exo_values(0, names = "ui"), 
               "\\ui\" is not an exogenous variable\\.")
  msg <- "The following names are no exogenous variables: \"ui\", \"l_1\"\\."
  expect_error(mdl2$set_static_exo_values(0, names = c("ui", "l_1")),  msg)
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

test_that("get_all_endo_data", {
  data <- mdl$get_all_endo_data()
  p <- mdl$get_data_period()
  expected_result <- cbind(mdl$get_endo_data(), 
                           mdl$get_fit_instruments(period = p),
                           mdl$get_lagrange(period = p))
  expect_equal(data, expected_result)
})

test_that("get_all_data", {
  data <- mdl$get_all_data()
  p <- mdl$get_data_period()
  expected_result <- cbind(mdl$get_endo_data(period = p), 
                           mdl$get_fit_instruments(period = p),
                           mdl$get_lagrange(period = p), 
                           mdl$get_exo_data())
  expected_result <- expected_result[ , order(colnames(expected_result))]
  expect_equal(data, expected_result)
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
  
  mdl2 <- mdl$copy()
  mdl2$set_endo_values(2, names = "l_2")
  expect_identical(mdl2$get_lagrange(names = "l_2")[, 1],
                   regts(2, period = mdl$get_period()))
  
  # errors
  expect_error(mdl2$set_static_endos(c(l_2 = 2)),
               "\"l_2\" is not an endogenous variable\\.")
  
  msg <- "The following names are no endogenous variables: \"g\", \"l_2\"\\."
  expect_error(mdl2$set_fit_values(2, names = c("g", "l_2")), msg)
  
  x <- regts(matrix(1, nrow = 2, ncol = 3), names = c("g", "l_2", "y"),
             period = "2016Q1")
  expect_error(mdl2$set_fit(x), msg)
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

test_that("too many fit targets", {
  
  mdl2 <- mdl$copy()
  
  mdl2$set_param(c(sigma_umd = -1))
  
  # set fit targets outside model period and with NA values should not mattter
  mdl2$set_fit_values(-999, names = "y", period = "2015q3/2015q4")
  mdl2$set_fit_values(3, names = "c", period = "2008q1")
  mdl2$set_fit_values(NA, names = "c", period = "2016q1")
  mdl2$set_fit_values(NA, names = "r", period = "2016q1/2016q4")
  
  expected_result <- mdl$get_fit()
  expected_result["2015q4", "y"] <- -999
  expect_identical(mdl2$get_fit(), expected_result)
  
  expect_identical(ncol(mdl2$residual_check(include_fit_eqs = TRUE, tol = 1e-8)), 
                   0L)
  expect_output(mdl2$solve(), "Convergence after 0 iterations")
  
  mdl2$set_fit_values(720, names = "c", period = "2016q1")
  mdl2$set_fit_values(3.35, names = "r", period = "2016q1/2016q4")
  msg <- paste("The number of fit targets \\(4\\) exceeds the number",
               "of fit instruments \\(3\\)")
  expect_error(mdl2$solve(), msg)
})

test_that("solve replaces endogenous variables with fit targets before solving", {
  
  mdl$set_endo_values(999, names = "y", period = "2016q1/2016q3")
  mdl$set_endo_values(NA, names = "t", period = "2016q1")
  
  # residual check should give errors
  expect_true(max(abs(mdl$residual_check()), na.rm = TRUE) > 1e-6)
  expect_true(is.na(max(abs(mdl$residual_check()), na.rm = FALSE)))
  
  # solve should convergence in 0 iterations, because it replaced endos with
  # fit targets (if present)
  expect_output(mdl$solve(), "Convergence after 0 iterations")
})

test_that("changing fit instruments", {
  
  mdl2 <- mdl$copy()
  
  ut <- regts(1:2, start = "2016q1")
  mdl2$set_data(ut, names = "ut")
  mdl2$set_endo_values(3, names = "uc", period = "2016q1")
  mdl2$change_endo_data(function(x) {x + 2}, names = "ui", 
                        period = "2016q1/2016q3")
  
  expected_result <- mdl2$get_fit_instruments()
  expected_result["2016q1/2016q2", "ut"] <- c(1,2)
  expected_result["2016q1", "ui"] <- c(3)
  expected_result["2016q1/2016q3"] <-  expected_result["2016q1/2016q3"] + 3
  
  
  expect_error(mdl2$change_endo_data(function(x) {x + 2}, names = "g", 
                                     period = "2016q1/2016q3"),
               "\"g\" is not an endogenous variable")
})

test_that("clear_fit", {
  mdl2 <- mdl$copy()
  mdl2$clear_fit()
  expect_null(mdl2$get_fit())
  expect_equal(unname(mdl2$get_sigmas()), numeric(0))
  expect_equal(mdl2$get_lagrange(), mdl$get_lagrange() * 0)
  expect_output(mdl2$solve(), "Convergence after 0 iterations")
})

test_that("error: fit instrument not in model block", {
  expect_warning(
    expect_error(
      msg <- capture.output(
        rep <- capture_output(mdl <- dyn_mdl("mod/islm_fit_error.mod")),
        type = "message"),
      "The following fit instruments do not occur in the model equations: uc.")
  )
})

test_that("set_static_endos/set_static_exos", {
  mdl2 <- mdl$copy()
  
  msg <- "\"ut\" is not an endogenous variable\\." 
  expect_error(mdl2$set_static_endos(c(c = 12, ut = 3)), msg)
  expect_warning(mdl2$set_static_endos(c(c = 13, ut = 3), name_err = "warn"), 
                 msg)
  expect_equal(mdl2$get_static_endos()["c"], c(c= 13))
  expect_silent(mdl2$set_static_endos(c(c = 14, ut = 3), name_err = "silent"))
  expect_equal(mdl2$get_static_endos()["c"], c(c = 14))
  expect_equal(mdl2$get_static_endos(names = "c"), c(c = 14))
  expect_equal(mdl2$get_static_endos(pattern = "c"), c(c = 14))
  
  expect_warning(x <- mdl2$get_static_endos(pattern = "^x"), 
                 "No endogenous variables match pattern \"\\^x\".")
  expect_equal(length(x), 0)
  
  msg <- "The following names are no exogenous variables: \"c\", \"uc\"\\."
  expect_error(mdl$set_static_exos(c(c = 12, uc = 3, g = 12)), msg)
  expect_warning(mdl2$set_static_exos(c(c = 12, uc = 3, g = 12), 
                                      name_err = "warn"), msg)
  expect_equal(mdl2$get_static_exos()["g"], c(g = 12))
  expect_equal(mdl2$get_static_exos(names = "g"), c(g = 12))
  expect_equal(mdl2$get_static_exos(pattern = "^g"), c(g = 12))
  
  expect_warning(x <- mdl2$get_static_exos(pattern = "^x"), 
                 "No exogenous variables match pattern \"\\^x\".")
  expect_equal(length(x), 0)
  
  expect_silent(mdl2$set_static_exos(c(c = 12, uc = 3, g = 122), 
                                     name_err = "silent"))
  expect_equal(mdl2$get_static_exos()["g"], c(g = 122))
  
  mdl2$set_static_endos(c(c = 333, y = 444))
  expect_equal(mdl2$get_static_endos(names = c("y", "c")),
               c(y = 444, c = 333))
  
  mdl2$set_static_endos(c(a = 3333, b = 4444), names = c("c", "y"))
  expect_equal(mdl2$get_static_endos(names = c("y", "c")),
               c(y = 4444, c = 3333))
  
  mdl2$set_static_exos(c(ms = 555, g = 666))
  expect_equal(mdl2$get_static_exos(pattern = "^(g|(ms))$"),
               c(g = 666, ms = 555))
  
  mdl2$set_static_exos(c(5555, 6666), names = c("ms", "g"))
  expect_equal(mdl2$get_static_exos(pattern = "^(g|(ms))$"),
               c(g = 6666, ms = 5555))
})

test_that("set_static_data / get_static_data", {
  
  mdl2 <- mdl$copy()
  
  model_names <- c(mdl$get_endo_names(), mdl$get_exo_names())
  
  expect_error(mdl2$set_static_data(c(utt  = 2)),
               '"utt" is not a model variable.')  
  expect_silent(mdl2$set_static_data(c(utt  = 2), name_err = "silent"))
  mdl2$set_static_data(mdl2$get_static_data())
  expect_equal(mdl2$get_static_data()[model_names],
               c(mdl$get_static_endos(), mdl$get_static_exos())[model_names])
  
  msg <- paste('The following names are no model',
               'variables: "xxx", "utt".')
  expect_warning(
    mdl2$set_static_data(c(c = 222, g = 333, xxx = 5, utt = 2), 
                         name_err = "warn"),
    msg)
  
  expected_result <- mdl$get_static_data()
  expected_result[c("c", "g")] <- c(222, 333)
  
  expect_equal(mdl2$get_static_data(), expected_result)
  
  expect_equal(mdl2$get_static_data(pattern = "^[gm]"), 
               expected_result[c("g", "md", "ms")])
  
  expect_warning(x <- mdl2$get_static_data(pattern = "^uu"), 
                 "No model variables match pattern \"\\^uu\".")
  expect_equal(length(x), 0)
  
  expect_silent(x <- mdl2$get_static_data(pattern = "^u"))
  expect_equal(x, c(uc = 0, ui = 0, umd = 0., ut = 0))
  
  expect_equal(length(mdl2$get_static_data(names = character(0))), 0)
  expect_equal(length(mdl2$get_static_endos(names = character(0))), 0)
  expect_equal(length(mdl2$get_static_exos(names = character(0))), 0)
  
  mdl2$set_static_data(c(ms = 555, md = 666))
  expect_equal(mdl2$get_static_data(pattern = "^m"),
               c(md = 666, ms = 555))
  
  mdl2$set_static_data(c(a = 5555, b = 6666), names = c("ms", "md"))
  expect_equal(mdl2$get_static_data(pattern = "^m"),
               c(md = 6666, ms = 5555))
  
  mdl2$set_static_data(c(ut  = 222))
  expect_equal(mdl2$get_static_data(names = "ut"), c(ut = 222))
    
})

test_that("get_fit for argument period, pattern and names", {
  
  per <- period_range("2015q1/2020q3")
  ref_result <- mdl$get_endo_data(period = per)
  ref_result[ , ] <- NA
  ref_result <- update_ts(ref_result, fit_targets)
  
  expect_equal(mdl$get_fit(period = per, pattern = ".*"), ref_result)
  expect_equal(mdl$get_fit(period = per), ref_result[, c("t", "y")])
  expect_equal(mdl$get_fit(names = c("c", "y")), 
               ref_result["2016q1/2016q3", c("c", "y")])
  
  result <- mdl$get_fit(period = "11q1/12q2")
  expect_equal(ncol(result), 0)
  expect_equal(get_period_range(result), period_range("11q1/12q2"))
  expect_null(mdl$get_fit(names = "c"))
  expect_equal(mdl$get_fit(names = "c", period = "2016q1"), 
               ref_result["2016q1", "c", drop = FALSE])
  
  expect_error(mdl$get_fit(names = c("x", "c")), 
                   "\"x\" is not an endogenous variable.")
})


