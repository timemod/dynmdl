library(dynmdl)
library(testthat)
rm(list = ls())
context("ISLM model with trends")

source("../tools/read_file.R")
source("../tools/cat_lines.R")

model_name <- "islm_fit"

fit_steady <- c(y = 1300, i = 300)

model_name <- "islm_trend"
mod_file <- file.path("mod", paste0(model_name, ".mod"))

test_that("check_static_eqs = TRUE", {
  expect_error(mdl <- dyn_mdl(mod_file, silent = TRUE, fit_mod_file = "aap",
                              check_static_eqs = FALSE),
               "For models with trends,")
  expect_warning(
    messages <- capture.output(mdl <<- dyn_mdl(mod_file, silent = TRUE,  
                                              check_static_eqs = TRUE, 
                                              debug = TRUE), 
                               type = "message")
  )
  fit_mod_file <- tempfile()
  expect_true(file.copy("fitmod.mod", fit_mod_file))
  expect_true(file.remove("fitmod.mod"))
  expect_true(file.remove("preprocessed.mod"))
  mdl$set_fit_steady(fit_steady)
  mdl$solve_steady(silent = TRUE)
  expect_equal(mdl$get_solve_status(), "OK")
  txt <- read_file(fit_mod_file)
  expect_known_output(cat(txt), 
                      file = "expected_output/islm_trend_fmod1.txt")
  
  mdl$set_period("2020")
  mdl$init_data()
  expect_equal(ncol(mdl$residual_check(tol = 1e-8)), 0)
  expect_equal(colnames(mdl$residual_check(tol = 1e-8, 
                                                    include_fit_eqs = TRUE)),
               "eq_19")
})
test_that("fit_fixed_period = TRUE", {
  expect_warning(
    messages <- capture.output(mdl <- dyn_mdl(mod_file, silent = TRUE,  
                                              check_static_eqs = TRUE,
                                              fit_fixed_period = TRUE,
                                              debug = TRUE), 
                               type = "message")
  )
  fit_mod_file <- tempfile()
  expect_true(file.copy("fitmod.mod", fit_mod_file))
  expect_true(file.remove("fitmod.mod"))
  expect_true(file.remove("preprocessed.mod"))
  mdl$set_fit_steady(fit_steady)
  mdl$solve_steady(silent = TRUE)
  expect_equal(mdl$get_solve_status(), "OK")
  txt <- read_file(fit_mod_file)
  expect_known_output(cat(txt), 
                      file = "expected_output/islm_trend_fmod2.txt")
  
  mdl$set_period("2020")
  mdl$init_data()
  expect_equal(ncol(mdl$residual_check(tol = 1e-8, include_fit_eqs = TRUE)), 0)
})

test_that("init data and the base period (1)", {
  mdl2 <- mdl$copy()
  mdl2$init_data(base_period = 2016)
  expect_equal(mdl2$get_base_period(), period(2016))
  expect_equal(mdl2$get_data_period(), period_range(2016, 2021))
  expect_equal(mdl2$get_period(), period_range(2020, 2020))
  expect_error(mdl2$init_data(data_period = period_range(2019, 2021)),
               "The data period should include the range 2016/2021.")
  expect_equal(mdl2$get_data_period(), period_range(2016, 2021))
  
  expect_error(mdl2$init_data(base_period = "2016q1"),
               paste0("Argument 'base_period' has a different frequency than the",
                      " model period\\."))
})


test_that("base period", {
  expect_warning(
    messages <- capture.output(mdl2 <- dyn_mdl(mod_file, silent = TRUE,
                                               period = 2020),
                               type = "message")
  )
  expect_equal(mdl2$get_base_period(), period(2020))
  expect_warning(
    messages <- capture.output(mdl2 <- dyn_mdl(mod_file, silent = TRUE,
                                               base_period = 2016),
                               type = "message")
  )
  expect_equal(mdl2$get_base_period(), period(2016))
  mdl2$set_period(2020)
  expect_equal(mdl2$get_base_period(), period(2016))
  expect_equal(mdl2$get_data_period(), period_range(2016, 2021))
  
  expect_warning(
    messages <- capture.output(mdl2 <- dyn_mdl(mod_file, silent = TRUE,
                                               base_period = 2016,
                                               period = 2020),
                               type = "message")
  )
  expect_equal(mdl2$get_base_period(), period(2016))
  expect_equal(mdl2$get_data_period(), period_range(2016, 2021))
  
  expect_error(
    messages <- capture.output(mdl2 <- dyn_mdl(mod_file, silent = TRUE,
                                               base_period = 2016,
                                               period = "2020q2"),
                               type = "message"),
    "Argument 'base_period' has a different frequency than argument 'period'.")
  
  data <- regts(matrix(1:10, ncol = 2), start = "2018q1", names = c("c", "i"))
  expect_error(
    messages <- capture.output(mdl2 <- dyn_mdl(mod_file, silent = TRUE,
                                               base_period = 2016,
                                               period = "2020",
                                               data = data),
                               type = "message"),
    "Argument 'data' has a different frequency than argument 'period'.")
  expect_error(
    messages <- capture.output(mdl2 <- dyn_mdl(mod_file, silent = TRUE,
                                               base_period = "2016",
                                               data = data),
                               type = "message"),
    "Argument 'data' has a different frequency than argument 'base_period'.")
  
  
  expect_warning(
  expect_error(
    messages <- capture.output(mdl2 <- dyn_mdl(mod_file, silent = TRUE,
                                               data = mdl$get_data(period = 2020)),
                               type = "message"),
    "The data period is too short. It should contain at least 3 periods"))
  
  expect_warning(
    messages <- capture.output(mdl2 <- dyn_mdl(mod_file, silent = TRUE, base_period = 2015,
                                               data = mdl$get_data(period = 2020)),
                               type = "message"))
  expect_equal(mdl2$get_base_period(), period(2015))
  expect_equal(mdl2$get_data_period(), period_range(2015, 2020))
  
  expect_warning(
    messages <- capture.output(mdl2 <- dyn_mdl(mod_file, silent = TRUE),
                               type = "message")
  )
  expect_null(mdl2$get_base_period())
  expect_null(mdl2$get_period())
  expect_null(mdl2$get_data_period())
  expect_error(
    mdl2$init_data(base_period = "2018m1", data_period = "2018/2022"),
    "Argument 'base_period' has a different frequency than argument 'data_period'.")
  expect_error(
    mdl2$init_data(data_period = "2018/2022", 
                   data = regts(matrix(1:10, ncol = 2), start = "2018q1", names = c("c", "i"))),
    "Argument 'data' has a different frequency than argument 'data_period'.")
  expect_error(
    mdl2$init_data(base_period = "2018", 
                   data = regts(matrix(1:10, ncol = 2), start = "2018q1", names = c("c", "i"))),
    "Argument 'data' has a different frequency than argument 'base_period'.")
})

test_that("get_equations", {
  expect_known_output(cat_lines(mdl$get_static_equations()), 
                      "expected_output/islm_trend_stat_eqs.txt")
  expect_known_output(cat_lines(mdl$get_equations()), 
                      "expected_output/islm_trend_eqs.txt")
  expect_known_output(cat_lines(mdl$get_original_equations()), 
                     "expected_output/islm_trend_orig_eqs.txt")
  
})