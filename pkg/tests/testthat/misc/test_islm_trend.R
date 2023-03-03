library(dynmdl)
library(testthat)
rm(list = ls())


source("../tools/read_file.R")
source("../tools/cat_lines.R")

model_name <- "islm_fit"
update_expected_output <- FALSE

fit_steady <- c(y = 1300, i = 300)

model_name <- "islm_trend"
mod_file <- file.path("mod", paste0(model_name, ".mod"))

test_that("check_static_eqs = TRUE", {
  expect_error(mdl <- dyn_mdl(mod_file, silent = TRUE, fit_mod_file = "aap",
                              check_static_eqs = FALSE),
               "For models with trends,")
  expect_silent(
    mdl <<- dyn_mdl(mod_file, silent = TRUE,  check_static_eqs = TRUE, 
                    debug = TRUE)
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
                      file = "expected_output/islm_trend_fmod1.txt",
                      update = update_expected_output)
  
  mdl$set_period("2020")
  mdl$init_data()
  expect_null(mdl$residual_check(tol = 1e-8))
  expect_equal(colnames(mdl$residual_check(tol = 1e-8, 
                                                    include_fit_eqs = TRUE)),
               "eq_19")
})
test_that("fit_fixed_period = TRUE", {
  expect_silent(
    mdl <- dyn_mdl(mod_file, silent = TRUE,  
                   check_static_eqs = TRUE,
                   fit_fixed_period = TRUE,
                   debug = TRUE)
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
                      file = "expected_output/islm_trend_fmod2.txt",
                      update = update_expected_output)
  
  mdl$set_period("2020")
  mdl$init_data()
  expect_null(mdl$residual_check(tol = 1e-8, include_fit_eqs = TRUE))
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
  expect_silent(
    mdl2 <- dyn_mdl(mod_file, silent = TRUE, period = 2020)
  )
  expect_equal(mdl2$get_base_period(), period(2020))
  expect_silent(
    mdl2 <- dyn_mdl(mod_file, silent = TRUE, base_period = 2016)
  )
  expect_equal(mdl2$get_base_period(), period(2016))
  mdl2$set_period(2020)
  expect_equal(mdl2$get_base_period(), period(2016))
  expect_equal(mdl2$get_data_period(), period_range(2016, 2021))
  
  expect_silent(
    mdl2 <- dyn_mdl(mod_file, silent = TRUE, base_period = 2016,
                    period = 2020)
  )
  expect_equal(mdl2$get_base_period(), period(2016))
  expect_equal(mdl2$get_data_period(), period_range(2016, 2021))
  
  expect_error(
    mdl2 <- dyn_mdl(mod_file, silent = TRUE, base_period = 2016,
                    period = "2020q2"),
    "Argument 'base_period' has a different frequency than argument 'period'."
  )
  
  data <- regts(matrix(1:10, ncol = 2), start = "2018q1", names = c("c", "i"))
  expect_error(
    mdl2 <- dyn_mdl(mod_file, silent = TRUE, base_period = 2016,
                    period = "2020", data = data),
    "Argument 'data' has a different frequency than argument 'period'.")
  expect_error(
    mdl2 <- dyn_mdl(mod_file, silent = TRUE, base_period = "2016",
                   data = data),
    "Argument 'data' has a different frequency than argument 'base_period'.")
  
  expect_warning(
    expect_error(
      mdl2 <- dyn_mdl(mod_file, silent = TRUE,
                      data = mdl$get_data(period = 2020)),
      "The data period is too short. It should contain at least 3 periods"), 
  NA)
  
  expect_silent(
    mdl2 <- dyn_mdl(mod_file, silent = TRUE, base_period = 2015,
                    data = mdl$get_data(period = 2020))
  )
  expect_equal(mdl2$get_base_period(), period(2015))
  expect_equal(mdl2$get_data_period(), period_range(2015, 2020))
  
  expect_warning(
    mdl2 <- dyn_mdl(mod_file, silent = TRUE),
    NA
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
                      "expected_output/islm_trend_stat_eqs.txt",
                      update = update_expected_output)
  expect_known_output(cat_lines(mdl$get_equations()), 
                      "expected_output/islm_trend_eqs.txt",
                      update = update_expected_output)
  expect_known_output(cat_lines(mdl$get_original_equations()), 
                     "expected_output/islm_trend_orig_eqs.txt",
                     update = update_expected_output)
})

test_that("set_period", {
  msg <- paste("The specified period \\(2018Q2/2019Q2\\) has a different",
               "frequency than the data period \\(2019/2021\\)\\.")
  expect_error(mdl$set_period("2018q2/2019q2"), msg)
})

test_that("set_data", {
  
  mdl2 <- mdl$copy()
  old_data <- mdl2$get_data()
  
  data <- regts(matrix(1:4, ncol = 2), start = "2019", names = c("y", "t"))
  mdl2$set_data(data)
  expected_result <- update_ts(old_data, data)
  expect_equal(mdl2$get_data(), expected_result)
})

test_that("set_data fun", {
  
  mdl2 <- mdl$copy()
  old_data <- mdl2$get_data()
  
  names <- c("y", "yd")
  p <- period_range(2019, 2020)
  
  data <- regts(matrix(1:4, ncol = 2), period = p, names = names)
  data[2, 2] <- NA
  mdl2$set_data(data, fun = `*`)
  
  expected_result1 <- old_data  
  expected_result1[p, names] <- old_data[p, names] * data
  expect_equal(mdl2$get_data(), expected_result1)
  
  # restore  original data and then test additive case:
  mdl2$set_data(old_data[ , names])
  
  mdl2$set_data(data, fun = `+`)
  
  expected_result2 <- old_data
  expected_result2[p, names] <- old_data[p, names] + data
  
  expect_equal(mdl2$get_data(), expected_result2)
})

test_that("set_data upd_mode", {
  
  mdl2 <- mdl$copy()
  old_data <- mdl2$get_data()
  
  p <- period_range(2019, 2022)
  names <- "y"
  data <- regts(c(1, 2,  NA, 4), period = p)
  
  mdl2$set_data(data, upd_mode = "updval", names = names)
  
  expected_result <- old_data
  expected_result[p, names] <- ifelse(is.na(data), expected_result[p, names],
                                      data)
  expected_result["2022", ] <- NA
  

  expect_equal(mdl2$get_data(period = p), expected_result)
  
  # restore  original data and then test case with only NA values:
  mdl2$set_data(old_data[ , names, drop = FALSE])

  mdl2$set_data(data * NA, upd_mode = "updval", names = names)
  
  expected_result <- old_data
  expected_result["2022", ] <- NA
  
  expect_equal(mdl2$get_data(period = p), expected_result)
})

test_that("set_data combi fun and upd mode", {
  
  mdl2 <- mdl$copy()
  old_data <- mdl2$get_data()
  
  names <- c("y", "r", "yd")
  p <- period_range(2019, 2021)
  
  data <- regts(matrix(1:9, ncol = 3), period = p, names = names)
  data[2, 2] <- NA
  data[2:3, 3] <- NA
  mdl2$set_data(data, fun = `*`, upd_mode = "updval")
  
  expected_result <- update_ts(old_data, old_data[p, names] * data,
                               method = "updval")
  
  expect_equal(mdl2$get_data(), expected_result)
})
