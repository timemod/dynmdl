library(dynmdl)
library(testthat)
rm(list = ls())
context("IFN model")
source("../tools/read_dynare_result.R")

# NOTE: the IFN model is not normal DSGE model,
# the steady state is not well defined and
# the Blanchard-Kahn-conditions are not satisfied.
# However, it may still be solved with the stacked-time algorithm.
model_name <- "ifn"

mod_file <- file.path("mod", paste0(model_name, ".mod"))
input_file <- "input/ifn_input.csv"
dynare_dir     <- "dynare/output"

endo_name_file <- file.path(dynare_dir, "ifn_endo_names.txt")
exo_name_file  <- file.path(dynare_dir, "ifn_exo_names.txt")

# compile the model
model_period <- period_range("2015/2113")
report <- capture_output(mdl <- dyn_mdl(mod_file, model_period))

dynare_result <- read_dynare_result(model_name, mdl)

input_df <- read.csv(input_file)

lag_per <- mdl$get_lag_period()

input <- regts(input_df, period = mdl$get_data_period(),
               names = tolower(colnames(input_df)))


if (FALSE) {
  #
  # prepare data for Dynare. Dynare does not like NA values for endogeous 
  # variables in the lag or lead period, even if the corresponding variable
  # has no lags/leads. Therefore use update_ts to update the data.
  #
  input_for_dynare <- mdl$get_endo_data()
  input_for_dynare <- update_ts(input_for_dynare, input, method = "updval")
  write_ts_xlsx(input_for_dynare, "dynare/ifn_input.xlsx", rowwise = FALSE, 
              labels = "no")
}

test_that("solve", {
  mdl2 <- mdl$clone()
  mdl2$set_data(input)
  mdl2$solve(control = list(silent = TRUE, trace = FALSE))
  expect_equal(dynare_result$endo, mdl2$get_endo_data(period = model_period))
})

test_that("solve_steady, check and solve_perturb give an error", {
  # for the ifn model the steady state cannot be computed  

  omsg <- paste("The Jacobian is \\(nearly\\)",
                "singular at iteration 1. The inverse condition is 0.")
  wmsg <- paste("Solving the steady state not succesful.\nThe Jacobian is",
                "\\(nearly\\) singular at iteration 1.",
                "The inverse condition is 0.")
  expect_warning(
    expect_output(mdl$solve_steady(), omsg),
   wmsg)
  
  expect_warning(
    expect_output(mdl$solve_steady(control = list(silent = TRUE)), NA),
    wmsg)
  
  emsg <- "No steady state ... checking model is not possible"
  expect_warning(
    expect_error(mdl$check(), emsg), 
    wmsg)
    
  emsg <- paste("Method solve_perturbation does not work for models with",
                "exogenous lags or leads")
  expect_warning(
    expect_error(mdl$solve_perturbation(), emsg), 
    wmsg)
})
