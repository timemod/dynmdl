library(dynmdl)

source("simple_model_utils.R")

mod_file <- "mod/simple1.mod"

# compile the model
report <- capture_output(mdl <- dyn_mdl(mod_file))

mdl$set_period("2015/2060")
data_per <- mdl$get_data_period()
eigvals <- get_analytical_eigvals(mdl$get_param())
ref1 <- get_analytical_result(y0 = 1, x1 = 0, period = data_per,
                              params = mdl$get_param())
ref2 <- get_analytical_result(y0 = 1, x1 = 1, period = data_per,
                              params = mdl$get_param())
ts_labels(ref1) <- colnames(ref1)
ts_labels(ref2) <- colnames(ref2)

lead_per <- mdl$get_lead_period()
lag_per <- mdl$get_lag_period()

mdl$set_data(regts(1, period = lag_per), names = "y")

test_that("steady state calculation", {
  mdl_stat <- mdl$clone()
  mdl_stat$set_static_endos(c(y = 2))
  mdl_stat$solve_steady(solver = "nleqslv", control = list(trace = 0))
  expect_equal(mdl_stat$get_static_endos(), c(y = 0))
})

test_that("solve", {
  mdl1 <- mdl$clone()
  mdl1$set_data(ref1[lead_per], names = "y")
  mdl1$solve(silent = TRUE)
  mdl2 <- mdl1$clone()
  mdl2$set_data(ref2[lead_per], names = "y")
  mdl2$set_data(regts(1, start = start_period(mdl$get_period())), 
                names = "x")
  mdl2$solve(silent = TRUE)
  expect_equal(mdl1$get_endo_data(), ref1)
  expect_equal(mdl2$get_endo_data(), ref2)
})

test_that("solve_perturbation", {
  mdl1 <- mdl$clone()
  mdl1$solve_perturbation()
  expect_equal(mdl1$get_endo_data(), ref1)
  expect_equal(mdl1$get_eigval(), eigvals)
  mdl2 <- mdl1$clone()
  mdl2$set_data(regts(1, start = start_period(mdl$get_period())), 
                names = "x")
  mdl2$solve_perturbation()
  expect_equal(mdl1$get_endo_data(), ref1)
  expect_equal(mdl2$get_endo_data(), ref2)
})
