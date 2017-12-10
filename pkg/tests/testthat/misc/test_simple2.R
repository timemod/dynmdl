library(dynmdl)

context("simple model expanded to a model with 4 equations")

source("simple_model_utils.R")

mod_file <- "mod/simple2.mod"

# compile the model
report <- capture_output(mdl <- dyn_mdl(mod_file))

mdl$set_period("2015/2017")
data_per <- mdl$get_data_period()
nper <- nperiod(data_per)
lead_per <- mdl$get_lead_period()
lag_per  <- mdl$get_lag_period()

eigvals <- get_analytical_eigvals(mdl$get_param())
y_ref_per <- period_range(start_period(data_per), end_period(data_per) + 1)
y_ref1 <- get_analytical_result(y0 = 1, x1 = 0, period = y_ref_per,
                                mdl$get_param())
y_ref2 <- get_analytical_result(y0 = 1, x1 = 1, period = y_ref_per,
                                mdl$get_param())

ymin_ref1  <- lag(y_ref1, -1)
colnames(ymin_ref1) <- "ymin"
yplus_ref1 <- lag(y_ref1, 1)
colnames(yplus_ref1) <- "yplus"
exo_ref1   <- regts(0, period = data_per)
ref1 <- cbind(y_ref1, yplus_ref1, ymin_ref1, exo = exo_ref1)[data_per]
ref1[lag_per, "ymin"] <- 0
ts_labels(ref1) <- colnames(ref1)

ymin_ref2 <- lag(y_ref2, -1)[data_per]
colnames(ymin_ref2) <- "ymin"
yplus_ref2 <- lag(y_ref2, 1)[data_per]
colnames(yplus_ref2) <- "yplus"
exo_ref2 <- regts(c(0, 1, rep(0, nper - 2)), period = data_per)
ref2 <- cbind(y_ref2, yplus_ref2, ymin_ref2, exo = exo_ref2)[data_per]
ref2[lag_per, "ymin"] <- 0
ts_labels(ref2) <- colnames(ref2)

mdl$set_data(regts(1, period = lag_per), names = "y")

test_that("steady state calculation", {
  mdl_stat <- mdl$clone()
  mdl$set_static_endos(c(y = 2, yplus = 1, ymin = 9, exo = 0))
  mdl_stat$solve_steady(control = list(silent = TRUE))
  expected_result <- c(y = 0, yplus = 0, ymin = 0, exo= 0)
  expect_equal(mdl_stat$get_static_endos(), expected_result)
})

test_that("solve", {
  mdl1 <- mdl$clone()
  mdl1$set_data(ref1[lead_per, "y", drop = FALSE])
  mdl1$solve(control = list(silent = TRUE))
  mdl2 <- mdl1$clone()
  mdl2$set_data(ref2[lead_per, "y", drop = FALSE])
  mdl2$set_data(regts(1, start = start_period(mdl$get_period())), 
                names = "x")
  mdl2$solve(control = list(silent = TRUE))
  per <- mdl$get_period()
  expect_equal(mdl1$get_endo_data(period = per), ref1[per, ])
  expect_equal(mdl2$get_endo_data(period = per), ref2[per, ])
})

test_that("solve_perturbation", {
  mdl1 <- mdl$clone()
  mdl1$solve_perturbation()
  x <- lag(y_ref1)[lag_per]
  mdl1$set_data(lag(y_ref1)[lag_per], names = "yplus")
  expect_equal(mdl1$get_endo_data(), ref1)
  expect_equal(mdl1$get_eigval(), eigvals)
  mdl2 <- mdl1$clone()
  mdl2$set_data(lag(y_ref2)[lag_per], names = "yplus")
  mdl2$set_data(regts(1, start = start_period(mdl$get_period())), 
                names = "x")
  mdl2$solve_perturbation()
  expect_equal(mdl1$get_endo_data(), ref1)
  expect_equal(mdl2$get_endo_data(), ref2)
})
