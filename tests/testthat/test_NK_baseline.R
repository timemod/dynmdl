library(dynr)
context("NK_baseline model")

# NOTE: the IFN model is not normal DSGE model,
# the steady state is not well defined and
# the Blanchard-Kahn-conditions are not satisfied.
# However, it may still be solved with the stacked-time algorithm.

mod_file <- "mod/NK_baseline.mod"
dynare_dir     <- "dynare/output"
param_name_file <-  file.path(dynare_dir, "NK_baseline_param_names.txt")
param_value_file <-  file.path(dynare_dir, "NK_baseline_param_values.txt")
endo_name_file <- file.path(dynare_dir, "NK_baseline_endo_names.txt")
endo_data_file <- file.path(dynare_dir, "NK_baseline_simul_endo.csv")
start_period <- regperiod("2015")

# compile the model
report <- capture_output(mdl <- compile_model(mod_file))

# read ine result of stoch_simul with Dynare
endo_names <- read.csv(endo_name_file, stringsAsFactors = FALSE,
                       header = FALSE, sep = "")[[1]]
endo_data <- t(as.matrix(read.csv(endo_data_file, header = FALSE)))
nper <- nrow(endo_data) - 2 # minus maximum lag and lead
model_period <- regperiod_range(start_period, start_period + nper - 1)
mdl$set_period(model_period)
data_period <- mdl$get_data_period()
dynare_result <- regts(endo_data, period = data_period, names = endo_names)

# TODO: the computed steady state does not agree with the Dynare result.
# What is going on?
mdl$solve_steady(control = list(trace = 0))

# todo: handle imaginary parts
check_output <- capture.output(mdl$check())

test_that("solve", {
    mdl2 <- mdl$clone()
    mdl2$set_data(dynare_result[mdl$get_lead_period()])
    mdl2$set_data(dynare_result[mdl$get_lag_period()])
    p <- start_period(model_period)
    with (as.list(mdl2$get_params()), {
        mdl2$set_exo_values(exp(sigma_d), names = "epsd", period = p);
        mdl2$set_exo_values(exp(sigma_phi), names = "epsphi", period = p);
        mdl2$set_exo_values(exp(sigma_mu), names = "epsmu_I", period = p);
        mdl2$set_exo_values(exp(sigma_A), names = "epsA", period = p);
        mdl2$set_exo_values(exp(sigma_m), names = "epsm", period = p);
    })
    mdl2$solve(control = list(trace = FALSE))
    expect_equal(mdl2$get_endo_data(), dynare_result)
})
