library(dynr)
context("simple model with 1 equation and no shock on exogenous data")

mod_file <- "mod/simple1.mod"

# compile the model
# TODO: capturing output does not work yet, probably we do not use
# Rcout
report <- capture_output(mdl <- compile_model(mod_file))

mdl$set_period("2015/2060")

# calculate the lowest eigenvalue
mu_1 <- with(as.list(mdl$get_params()), (1 - sqrt(1 - 4 * a * b)) / (2 * a))

# calculate the analytical result
ref <- regts(matrix(cumprod(c(1,
                       rep(mu_1, length_range(mdl$get_period()) + 1))),
                    ncol = 1),
             period = mdl$get_endo_period(),
             names = 'y')

# set lead value in the lead period
lead_per <- end_period(mdl$get_endo_period())
mdl$set_endo_value(names = "y", value = ref["2014", "y"])
mdl$set_endo_value(names = "y", value = ref[lead_per, "y"])

test_that("steady state calculation", {
    mdl2 <- mdl$clone()
    mdl2$solve_steady(start = c(y = 2))
	expect_equal(mdl2$get_static_endos(), c(y = 0))
})

test_that("solve", {
    mdl2 <- mdl$clone()
    mdl2$solve()
    expect_equal(mdl2$get_endo_data(), ref)
})

test_that("solve_perturbation", {
    mdl2 <- mdl$clone()
    mdl2$solve_perturbation()
    expect_equal(mdl2$get_endo_data(), ref)
})
