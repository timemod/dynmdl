library(dynmdl)
library(testthat)

context("backwards ISLM model")

nperiods <- 18
mod_file <- "mod/islm_backwards.mod"
dynare_dir     <- "dynare/output"
endo_name_file <- file.path(dynare_dir, "islm_backwards_endo_names.txt")
exo_name_file  <- file.path(dynare_dir, "islm_backwards_exo_names.txt")

p1 <- period("2011Q3")
model_period <- period_range(p1, p1 + nperiods - 1)

report <- capture_output(mdl <- dyn_mdl(mod_file))
report2 <- capture_output(mdl$solve_steady())
mdl$set_period(model_period)
lag_per <- mdl$get_lag_period()

get_dynare_endo <- function(endo_file, data_period) {
  endo_names <- read.csv(endo_name_file, stringsAsFactors = FALSE,
                         header = FALSE, sep = "")[[1]]
  endo_data <- t(as.matrix(read.csv(file.path(dynare_dir, endo_file),
                                    header = FALSE)))
  return(regts(endo_data, period = data_period, names = endo_names,
               labels = endo_names))
}

get_dynare_exo <- function(exo_file, data_period) {
  exo_names <- read.csv(exo_name_file, stringsAsFactors = FALSE,
                        header = FALSE, sep = "")[[1]]
  exo_data <- as.matrix(read.csv(file.path(dynare_dir, exo_file),
                                 header = FALSE))
  return(regts(exo_data, period = data_period, names = exo_names, 
               labels = exo_names))
}

dynare_endo <- get_dynare_endo("islm_backwards_simul_endo.csv", mdl$get_data_period())
dynare_exo <- get_dynare_exo("islm_backwards_simul_exo.csv", mdl$get_data_period())

test_that("solve", {
  mdl2 <- mdl$clone()
  mdl2$set_data(dynare_endo[lag_per])
  mdl2$set_data(dynare_exo)
  mdl2$solve(control = list(silent = TRUE))
  expect_equal(dynare_endo, mdl2$get_endo_data())
  expect_error(mdl2$solve_perturbation(),
               "No explosive roots. solve_first_order cannot handle this situation yet.")
})

test_that("solve with the stacked time method", {
  mdl2 <- mdl$clone()
  mdl2$set_data(dynare_endo[lag_per])
  mdl2$set_data(dynare_exo)
  mdl2$solve(control = list(silent = TRUE), force_stacked_time = TRUE)
  expect_equal(dynare_endo, mdl2$get_endo_data())
})

test_that("get_names", {
  endo_names <- c("y", "yd", "t",  "c", "i", "md", "r") 
  expect_equal(mdl$get_endo_names(), endo_names)
  
  expect_equal(mdl$get_endo_names(type = "lag"), c("y", "yd"))
  expect_equal(mdl$get_endo_names(type = "lead"), character(0))
  
  expect_equal(mdl$get_exo_names(), c("g", "ms"))
  
  par_names <- c(paste0("c", 0:5), paste0("i", 0:5), paste0("m", 0:3),
                 paste0("t", 0:1))
  par_names <- setdiff(par_names, c("c3", "i3"))
  expect_equal(mdl$get_par_names(), par_names)
})
