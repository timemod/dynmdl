library(dynr)
context("simple model expanded to a model with 4 equations")

source("simple_model_utils.R")

mod_file <- "mod/simple2.mod"

# compile the model
# TODO: capturing output does not work yet, probably we do not use
# Rcout
report <- capture_output(mdl <- compile_model(mod_file))

mdl$set_period("2015/2017")
endo_per <- mdl$get_endo_period()
nper <- length_range(endo_per)
lead_per <- end_period(endo_per)
lag_per  <- start_period(endo_per)

eigvals <- get_analytical_eigvals(mdl$get_params())
y_ref_per <- regperiod_range(start_period(endo_per), end_period(endo_per) + 1)
y_ref1 <- get_analytical_result(y0 = 1, x1 = 0, period = y_ref_per,
                                mdl$get_params())
y_ref2 <- get_analytical_result(y0 = 1, x1 = 1, period = y_ref_per,
                                mdl$get_params())

ymin_ref1  <- lag(y_ref1, -1)
colnames(ymin_ref1) <- "ymin"
yplus_ref1 <- lag(y_ref1, 1)
colnames(yplus_ref1) <- "yplus"
exo_ref1   <- regts(0, period = endo_per)
ref1 <- cbind(y_ref1, yplus_ref1, ymin_ref1, exo = exo_ref1)[endo_per]
ref1[lag_per, "ymin"] <- 0

ymin_ref2 <- lag(y_ref2, -1)[endo_per]
colnames(ymin_ref2) <- "ymin"
yplus_ref2 <- lag(y_ref2, 1)[endo_per]
colnames(yplus_ref2) <- "yplus"
exo_ref2 <- regts(c(0, 1, rep(0, nper - 2)), period = endo_per)
ref2 <- cbind(y_ref2, yplus_ref2, ymin_ref2, exo = exo_ref2)[endo_per]
ref2[lag_per, "ymin"] <- 0

mdl$set_endo_value("y", 1, start_period(mdl$get_endo_period()))

test_that("steady state calculation", {
    mdl_stat <- mdl$clone()
    mdl_stat$solve_steady(start = c(y = 2, yplus = 1, ymin = 9, exo = 0))
	expect_equal(mdl_stat$get_static_endos(), c(y = 0, yplus = 0, ymin = 0,
	                                            exo= 0))
})

test_that("solve", {
    mdl1 <- mdl$clone()
    mdl1$set_endo_value("y", ref1[lead_per, "y"], lead_per)
    mdl1$solve()
    mdl2 <- mdl1$clone()
    mdl2$set_endo_value("y", ref2[lead_per, "y"], lead_per)
    mdl2$set_exo_value("x", 1, start_period(mdl$get_period()))
    mdl2$solve()
    per <- mdl$get_period()
    expect_equal(mdl1$get_endo_data(per), ref1[per, ])
    expect_equal(mdl2$get_endo_data(per), ref2[per, ])
})

test_that("solve_perturbation", {
    mdl1 <- mdl$clone()
    mdl1$solve_perturbation()
    mdl1$set_endo_value("yplus", y_ref1[lag_per + 1], lag_per)
    expect_equal(mdl1$get_endo_data(), ref1)
    expect_equal(mdl1$get_eigval(), eigvals)
    mdl2 <- mdl1$clone()
    mdl2$set_endo_value("yplus", y_ref2[lag_per + 1], lag_per)
    mdl2$set_exo_value("x", 1, start_period(mdl$get_period()))
    mdl2$solve_perturbation()
    expect_equal(mdl1$get_endo_data(), ref1)
    expect_equal(mdl2$get_endo_data(), ref2)
})
