library(dynr)
library(readxl)

context("IFN model")

nperiods <- 99
mod_file <- "mod/ifn.mod"
input_file <- "dynare/ifn_input.xlsx"
dynare_dir     <- "dynare/output"
endo_name_file <- file.path(dynare_dir, "ifn_endo_names.txt")
exo_name_file  <- file.path(dynare_dir, "ifn_exo_names.txt")

p1 <- regperiod("2015")
model_period <- regperiod_range(p1, p1 + nperiods - 1)

report <- capture_output(mdl <- compile_model(mod_file))

#mdl$solve_steady()
mdl$set_period(model_period)
lag_per <- mdl$get_lag_period()

input_df <- read_excel(input_file)
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
    mdl2$solve(control = list(trace = FALSE))
    expect_equal(dynare_endo, mdl2$get_endo_data())
    #expect_error(mdl2$solve_perturbation(),
    #               "The perturbation approach currently only allows shocks in the first period")
})

# test_that("solve_perturb", {
#     mdl2 <- mdl$clone()
#     mdl2$set_endo_values(1200, "y", lag_per)
#     mdl2$set_exo_values(245, "g", start_period(model_period))
#     mdl2$solve()
#     mdl3 <- mdl2$clone()
#     mdl3$solve_perturbation()
#     # note that the results are not exactly equal because of nonlinear terms
#     expect_equal(mdl2$get_endo_data(), mdl3$get_endo_data(), tolerance = 1e-6)
# })
#
# test_that("solve_perturb linear model", {
#     mdl2 <- mdl$clone()
#     # set all non-linear parameters to 0
#     mdl2$set_params(c(c5 = 0, i5 = 0, m3 = 0))
#     mdl2$solve_steady()
#     mdl2$set_endo_values(1200, "y", lag_per)
#     # use a large shock, this should not matter if the model
#     # is exactly linear
#     mdl2$set_exo_values(280, "g", start_period(model_period))
#     mdl2$solve()
#     mdl3 <- mdl2$clone()
#     mdl3$solve_perturbation()
#     expect_equal(mdl2$get_endo_data(), mdl3$get_endo_data())
# })


