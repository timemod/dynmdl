library(dynmod)
context("simple model with 1 equation")

source("simple_model_utils.R")

mod_file <- "mod/simple1.mod"

# compile the model
# TODO: capturing output does not work yet, probably we do not use
# Rcout
report <- capture_output(mdl <- create_mod(mod_file))

mdl$set_period("2015/2060")
data_per <- mdl$get_data_period()
eigvals <- get_analytical_eigvals(mdl$get_params())
ref1 <- get_analytical_result(y0 = 1, x1 = 0, period = data_per,
                              params = mdl$get_params())
ref2 <- get_analytical_result(y0 = 1, x1 = 1, period = data_per,
                              params = mdl$get_params())
lead_per <- mdl$get_lead_period()
lag_per <- mdl$get_lag_period()

mdl$set_endo_data(regts(1, period = lag_per), names = "y")

test_that("steady state calculation", {
    mdl_stat <- mdl$clone()
    mdl_stat$solve_steady(start = c(y = 2))
	expect_equal(mdl_stat$get_static_endos(), c(y = 0))
})

test_that("solve", {
    mdl1 <- mdl$clone()
    mdl1$set_endo_data(ref1[lead_per], names = "y")
    mdl1$solve(control = list(silent = TRUE))
    mdl2 <- mdl1$clone()
    mdl2$set_endo_data(ref2[lead_per], names = "y")
    mdl2$set_exo_data(regts(1, start = start_period(mdl$get_period())), 
                      names = "x")
    mdl2$solve(control = list(silent = TRUE))
    expect_equal(mdl1$get_endo_data(), ref1)
    expect_equal(mdl2$get_endo_data(), ref2)
})

test_that("solve_perturbation", {
    mdl1 <- mdl$clone()
    mdl1$solve_perturbation()
    expect_equal(mdl1$get_endo_data(), ref1)
    expect_equal(mdl1$get_eigval(), eigvals)
    mdl2 <- mdl1$clone()
    mdl2$set_exo_data(regts(1, start = start_period(mdl$get_period())), 
                      names = "x")
    mdl2$solve_perturbation()
    expect_equal(mdl1$get_endo_data(), ref1)
    expect_equal(mdl2$get_endo_data(), ref2)
})
