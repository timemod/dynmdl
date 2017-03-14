library(dynmod)

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
stoch_endo_data_file <- file.path(dynare_dir, "NK_baseline_stoch_endo.csv")
steady_data_file <- file.path(dynare_dir, "NK_baseline_steady.csv")
eigval_file <- file.path(dynare_dir, "NK_baseline_eigval.csv")
start_period <- regperiod("2015")

# compile the model
report <- capture_output(mdl <- compile_model(mod_file))

# read in the dynare result, this is also used to determine the solution period
endo_names <- read.csv(endo_name_file, stringsAsFactors = FALSE,
                       header = FALSE, sep = "")[[1]]
endo_data <- t(as.matrix(read.csv(endo_data_file, header = FALSE)))
nper <- nrow(endo_data) - 2 # minus maximum lag and lead
model_period <- regperiod_range(start_period, start_period + nper - 1)
mdl$set_period(model_period)
data_period <- mdl$get_data_period()
dynare_result <- regts(endo_data, period = data_period, names = endo_names)

mdl$solve_steady(control = list(trace = FALSE))

test_that("solve_steady", {
    #  read in dynare result, and compare
    steady_endos <- read.csv(steady_data_file, header = FALSE, sep = "")[[1]]
    names(steady_endos) <- endo_names
    expect_equal(steady_endos, mdl$get_static_endos())
})

test_that("eigenvalues", {
    check_output <- capture_output(mdl$check())
    eigvals <- mdl$get_eigval()
    dynare_eigvals <- read.csv(eigval_file, header = FALSE, sep = ",")
    i <- order(apply(dynare_eigvals, MARGIN = 1,
                     FUN = function(x) sqrt(sum(x**2))))
    # the last eigenvalues are Inf or almost infinite
    expect_equal(Re(eigvals[1:19]), dynare_eigvals[i[1:19], 1])
})

test_that("solve", {
    mdl2 <- mdl$clone()
    p <- start_period(model_period)
    with (as.list(mdl2$get_params()), {
        mdl2$set_exo_values(exp(sigma_d), names = "epsd", period = p);
        mdl2$set_exo_values(exp(sigma_phi), names = "epsphi", period = p);
        mdl2$set_exo_values(exp(sigma_mu), names = "epsmu_I", period = p);
        mdl2$set_exo_values(exp(sigma_A), names = "epsA", period = p);
        mdl2$set_exo_values(exp(sigma_m), names = "epsm", period = p);
    })
    mdl2$solve(control = list(silent = TRUE, trace = FALSE))

    expect_equal(mdl2$get_endo_data(), dynare_result)
})

test_that("solve_perturbation (1) compare with dynare result", {
    mdl2 <- mdl$clone()
    p <- start_period(model_period)
    with (as.list(mdl2$get_params()), {
        mdl2$set_exo_values(exp(sigma_d), names = "epsd", period = p);
    })
    mdl2$solve_perturbation()

    # read in Dynare result (stoch_simul calculation)
    stoch_endo_data <- t(as.matrix(read.csv(stoch_endo_data_file, header = FALSE)))
    stoch_per <- regperiod_range(start_period(model_period), end_period(data_period))
    dynare_stoch_result <- regts(stoch_endo_data, period = stoch_per, names = endo_names)
    dynare_stoch_result <- dynare_stoch_result +
        rep(mdl$get_static_endos(), each = length_range(stoch_per))

    expect_equal(mdl2$get_endo_data(period = stoch_per), dynare_stoch_result)
    mdl2$get_endo_data(period = stoch_per) - dynare_stoch_result
})
