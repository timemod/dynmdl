library(dynmod)
library(testthat)

context("ISLM model")

nperiods <- 18
mod_file <- "mod/islm.mod"
dynare_dir     <- "dynare/output"
endo_name_file <- file.path(dynare_dir, "islm_endo_names.txt")
exo_name_file  <- file.path(dynare_dir, "islm_exo_names.txt")

p1 <- regperiod("2011Q3")
model_period <- regperiod_range(p1, p1 + nperiods - 1)

report <- capture_output(mdl <- create_mod(mod_file))
mdl$solve_steady()
mdl$set_period(model_period)
lag_per <- mdl$get_lag_period()

get_dynare_endo <- function(endo_file, data_period) {
    endo_names <- read.csv(endo_name_file, stringsAsFactors = FALSE,
                           header = FALSE, sep = "")[[1]]
    endo_data <- t(as.matrix(read.csv(file.path(dynare_dir, endo_file),
                                      header = FALSE)))
    return (regts(endo_data, period = data_period, names = endo_names))
}

get_dynare_exo <- function(exo_file, data_period) {
    exo_names <- read.csv(exo_name_file, stringsAsFactors = FALSE,
                          header = FALSE, sep = "")[[1]]
    exo_data <- as.matrix(read.csv(file.path(dynare_dir, exo_file),
                                   header = FALSE))
    return (regts(exo_data, period = data_period, names = exo_names))
}

dynare_endo <- get_dynare_endo("islm_simul_endo.csv", mdl$get_data_period())
dynare_exo <- get_dynare_exo("islm_simul_exo.csv", mdl$get_data_period())

test_that("solve", {
    mdl2 <- mdl$clone()
    mdl2$set_endo_data(dynare_endo[lag_per])
    mdl2$set_exo_data(dynare_exo)
    mdl2$solve(control = list(silent = TRUE))
    expect_equal(dynare_endo, mdl2$get_endo_data())
    expect_error(mdl2$solve_perturbation(),
                   "The perturbation approach currently only allows shocks in the first period")
})

test_that("solve_perturb", {
    mdl2 <- mdl$clone()
    mdl2$set_endo_data(regts(1200, period = lag_per), names = "y")
    mdl2$set_exo_data(regts(245, period = start_period(model_period)), names = "g")
    mdl2$solve(control = list(silent = TRUE))
    mdl3 <- mdl2$clone()
    mdl3$solve_perturbation()
    # note that the results are not exactly equal because of nonlinear terms
    expect_equal(mdl2$get_endo_data(), mdl3$get_endo_data(), tolerance = 1e-6)
})

test_that("solve_perturb linear model", {
    mdl2 <- mdl$clone()
    # set all non-linear parameters to 0
    mdl2$set_params(c(c5 = 0, i5 = 0, m3 = 0))
    mdl2$solve_steady()
    mdl2$set_endo_values(1200, names = "y", period = lag_per)
    # use a large shock, this should not matter if the model
    # is exactly linear
    mdl2$set_exo_values(280, period = start_period(model_period), names = "g")
    mdl2$solve(control = list(silent = TRUE))
    mdl3 <- mdl2$clone()
    mdl3$solve_perturbation()
    expect_equal(mdl2$get_endo_data(), mdl3$get_endo_data())
})


