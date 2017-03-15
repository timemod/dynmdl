library(dynmdl)
library(testthat)


context("ISLM model")

nperiods <- 18
mod_file <- "mod/islm_backwards.mod"
dynare_dir     <- "dynare/output"
endo_name_file <- file.path(dynare_dir, "islm_backwards_endo_names.txt")
exo_name_file  <- file.path(dynare_dir, "islm_backwards_exo_names.txt")

p1 <- regperiod("2011Q3")
model_period <- regperiod_range(p1, p1 + nperiods - 1)

report <- capture_output(mdl <- create_mdl(mod_file))
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

dynare_endo <- get_dynare_endo("islm_backwards_simul_endo.csv", mdl$get_data_period())
dynare_exo <- get_dynare_exo("islm_backwards_simul_exo.csv", mdl$get_data_period())

test_that("solve", {
    mdl2 <- mdl$clone()
    mdl2$set_endo_data(dynare_endo[lag_per])
    mdl2$set_exo_data(dynare_exo)
    mdl2$solve(control = list(silent = TRUE))
    expect_equal(dynare_endo, mdl2$get_endo_data())
    expect_error(mdl2$solve_perturbation(),
        "No explosive roots. solve_first_order cannot handle this situation yet.")
})

test_that("solve with the stacked time method", {
    mdl2 <- mdl$clone()
    mdl2$set_endo_data(dynare_endo[lag_per])
    mdl2$set_exo_data(dynare_exo)
    mdl2$solve(control = list(silent = TRUE), force_stacked_time = TRUE)
    expect_equal(dynare_endo, mdl2$get_endo_data())
})
