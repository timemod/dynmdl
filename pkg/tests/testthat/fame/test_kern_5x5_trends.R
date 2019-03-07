library(dynmdl)
library(testthat)
rm(list = ls())

model_name <- "kern_5x5_trends"

context(paste("model", model_name))

source("../tools/read_dynare_result.R")

mod_file <- file.path("mod", paste0(model_name, ".mod"))
mod_file_expl <- file.path("mod", paste0(model_name, "_expl.mod"))

period <- period_range("2018Q1/2020Q4")

#
# create initial data for a simulation
#
groei_a <- regts(c(0.003, 0.0025), start = "2018q1")
groei_h <- regts(c(0.005, 0.0045), start = "2018q1")
k <- regts(1390, start = "2017q4")
y <- regts(c(470, 475, 472), start = "2017q4")
input_data <- cbind(groei_a, groei_h, k, y)

warnings <- capture_warnings(
  messages <- capture.output(
    dum <- capture_output({
      mdl <- dyn_mdl(mod_file, period = period, calc  = "internal",
                     base_period = "2017q4")
    })
  , type  = "message")
)


# mdl_expl is a version of the model with explicitly detrended equations
dum <- capture_output(
  mdl_expl <- dyn_mdl(mod_file_expl, period = period, calc  = "internal")
)

expect_known_output(warnings, 
                    file = file.path("expected_output", 
                                     paste0(model_name, "_warnings.,txt")),
                    print = TRUE)
expect_equal(messages, paste("WARNING: groei_a groei_h not used in model",
             "block, removed by nostrict command-line option"))

# dynare_result <- read_dynare_result(model_name, mdl)

test_that("steady state", {
  
  mdl$solve_steady(control = list(silent = TRUE))
  mdl_expl$solve_steady(control = list(silent = TRUE))

  expect_equal(mdl$get_solve_status(), "OK")
  expect_equal(mdl_expl$get_solve_status(), "OK")

  names <- mdl$get_endo_names()
  expect_equal(mdl$get_static_endos(), mdl_expl$get_static_endos()[names])
  
  # expect_equal(mdl$get_static_endos(), dynare_result$steady)
  
  # check that the steady state solution is consistent with the
  # dynamic model
  mdl_tmp <- mdl$copy()
  mdl_tmp$put_static_endos()
  res <- mdl_tmp$residual_check()
  expect_true(all(abs(res) < 1e-8))
})

test_that("check and eigenvalues", {
  
  check_report <- capture_output(mdl$check())

  eigvals <- mdl$get_eigval()
  
  # TODO: compare with Dynare result
  #expect_equal(Re(eigvals[1:26]), dynare_result$eigval[1:26, 1], 
  #             tolerance = 1e-7)
  #expect_equal(abs(Im(eigvals[1:26])), abs(dynare_result$eigval[1:26, 2]), 
  #             tolerance = 1e-7)
  
  #expect_true(all(Mod(eigvals[27:34]) > 1e5))
})

test_that("simulation and compare", {
  
  mdl$init_data(data = input_data, upd_mode = "updval")
  mdl$set_fit(input_data, name_err = "silent")
  mdl$solve(control = list(trace = TRUE))
  
  mdl_expl$set_param(c(p_make_trend = 1))
  mdl_expl$init_data(data = input_data, upd_mode = "updval")
  mdl_expl$set_fit(input_data$y, names = "y_trend")
  mdl_expl$solve(control = list(trace = TRUE))
  
  # check trend variables
  pre_lead_per <- range_union(mdl$get_lag_period(), period)
  asi_trend <- mdl$get_trend_data(names = "asi", period = pre_lead_per)
  asi_mdl_expl <- mdl_expl$get_endo_data(names = "asi", period = pre_lead_per)
  ts_labels(asi_mdl_expl) <- NULL
  expect_equal(asi_trend, asi_mdl_expl)
  
  trends <- mdl$get_trend_data(names = c("asi", "hi"), period = pre_lead_per)
  trends_mdl_expl <- mdl_expl$get_endo_data(names = c("asi", "hi"), 
                                            period = pre_lead_per)
  ts_labels(trends_mdl_expl) <- NULL
  expect_equal(trends, trends_mdl_expl)
  
  # check names
  trend_var_names <- grep("_trend$", mdl_expl$get_endo_names(), value = TRUE)
  names <- sub("_trend$", "", trend_var_names)
  
  data1 <- mdl$get_endo_data(names = names, period = pre_lead_per)
  data2 <- mdl_expl$get_endo_data(names = trend_var_names, period = pre_lead_per)
  colnames(data2) <- names
  ts_labels(data2) <- names
  
  #print(tsdif(data1[solve_period], data2[solve_period], fun = cvgdif, 
  #            tol = 1e-10)
})

