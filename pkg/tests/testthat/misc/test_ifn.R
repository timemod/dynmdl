library(dynmdl)
library(testthat)

context("IFN model")

# NOTE: the IFN model is not normal DSGE model,
# the steady state is not well defined and
# the Blanchard-Kahn-conditions are not satisfied.
# However, it may still be solved with the stacked-time algorithm.

mod_file <- "mod/ifn.mod"
input_file <- "input/ifn_input.csv"
dynare_dir     <- "dynare/output"
endo_name_file <- file.path(dynare_dir, "ifn_endo_names.txt")
exo_name_file  <- file.path(dynare_dir, "ifn_exo_names.txt")

# compile the model
report <- capture_output(mdl <- create_mdl(mod_file))

input_df <- read.csv(input_file)
nperiods <- nrow(input_df) - 2  # subtract maximum lead and lag
p1 <- period("2015")
model_period <- period_range(p1, p1 + nperiods - 1)

mdl$set_period(model_period)
lag_per <- mdl$get_lag_period()

input <- regts(input_df, period = mdl$get_data_period(),
               names = tolower(colnames(input_df)))

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

dynare_endo <- get_dynare_endo("ifn_simul_endo.csv", mdl$get_data_period())
dynare_exo <- get_dynare_exo("ifn_simul_exo.csv", mdl$get_data_period())

test_that("solve", {
    mdl2 <- mdl$clone()
    mdl2$set_data(input)
    mdl2$solve(control = list(silent = TRUE, trace = FALSE))
    expect_equal(dynare_endo, mdl2$get_endo_data())
})

test_that("solve_steady, check and solve_perturb give an error", {
    # for the ifn model the steady state cannot be computed
    msg <-  paste("Error solving the steady state.\n Jacobian is",
                  "too ill-conditioned \\(1/condition=\\d.\\d*e-\\d+\\)",
                  "\\(see allowSingular option\\)")
    expect_error(mdl$solve_steady(), msg)
    expect_error(mdl$check(), msg)
    expect_error(mdl$solve_perturbation(), msg)
})
