library(dynmdl)
library(testthat)

context("ISLM model with external functions (dll)")

nperiods <- 18
mod_file <- "mod/islm_extfunc.mod"
dynare_dir     <- "dynare/output"
endo_name_file <- file.path(dynare_dir, "islm_endo_names.txt")
exo_name_file  <- file.path(dynare_dir, "islm_exo_names.txt")

p1 <- period("2011Q3")
model_period <- period_range(p1, p1 + nperiods - 1)

report <- capture_output(mdl <- dyn_mdl(mod_file, use_dll = TRUE, dll_dir = "aap"))

square <<- function(x) {
  return(x * x)
}
multiply <<- function(x, y) {
  return(x * y)
}

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

endo_names <- mdl$get_endo_names()
dynare_endo <- get_dynare_endo("islm_simul_endo.csv",
                               mdl$get_data_period())[, endo_names]
dynare_exo <- get_dynare_exo("islm_simul_exo.csv", mdl$get_data_period())

test_that("solve", {
  mdl2 <- mdl$clone()
  mdl2$set_data(dynare_endo[lag_per])
  mdl2$set_data(dynare_exo)
  mdl2$solve(control = list(silent = TRUE))
  expect_equal(dynare_endo, mdl2$get_endo_data())
  expect_error(mdl2$solve_perturbation(),
               "The perturbation approach currently only allows shocks in the first period")
})

