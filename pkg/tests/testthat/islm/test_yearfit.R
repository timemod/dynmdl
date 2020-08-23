library(testthat)
library(dynmdl)
rm(list = ls())

context("ISLM model with year fit")

source("../tools/read_dynare_result.R")
source("../tools/read_file.R")

model_name <- "islm_yearfit"
nperiods <- 18
mod_file <- file.path("mod", paste0(model_name, ".mod"))
fit_mod_file <- "mod_out/islm_yearfit.mod"

p1 <- period("2016Q1")
model_period <- period_range(p1, p1 + nperiods - 1)

unlink(fit_mod_file)

if (.Platform$OS.type == "unix") {
  # test handling ~ in name of fit_mod_file
  fit_mod_file <- file.path(normalizePath(dirname(fit_mod_file)), 
                            basename(fit_mod_file)) 
  home_dir <- Sys.getenv("HOME") 
  fit_mod_file <- sub(home_dir, "~", fit_mod_file)
}

mdl <- dyn_mdl(mod_file, fit_mod_file = fit_mod_file, silent = TRUE)

mdl$solve_steady(control = list(silent = TRUE))
mdl$set_period(model_period)
mdl$set_fit(regts(1275, start = "2016Q4"), names = "y_year")
mdl$set_sigma(c(umd = 2, ui = 21))

mdl$solve(silent = TRUE)

dynare_result <- read_dynare_result(model_name, mdl)

test_that("generated fit mod file equal to reference ", {
  txt <- read_file(fit_mod_file)
  expect_known_output(cat(txt), file = "expected_output/yearfit_fmod_file.txt")
})

test_that("dynare result equal to dynr result", {
  p <- mdl$get_period()
  expect_equal(dynare_result$endo, mdl$get_endo_data(period = p))
})

test_that("get_names", {
  endo_names <- c("y", "yd", "t", "c", "i", "md", "r", "y_year") 
  expect_equal(mdl$get_endo_names(), endo_names)
  
  expect_equal(mdl$get_endo_names(type = "lag"), c("y", "yd"))
  expect_equal(mdl$get_endo_names(type = "lead"), c("y", "yd"))
  
  expect_equal(mdl$get_exo_names(), c("g", "ms"))
  
  par_names <- c(paste0("c", 0:5), paste0("i", 0:5), paste0("m", 0:3),
                 paste0("t", 0:1))
  expect_equal(mdl$get_par_names(), par_names)
  
  sigma_names <- paste0("sigma_u", c("t", "c", "i", "md"))
  expect_equal(mdl$get_sigma_names(), sigma_names)
})

test_that("error fit_mod_file", {
  expect_error(dyn_mdl(mod_file, fit_mod_file = "mod_out", silent = TRUE),
               "'mod_out' is a directory")
  expect_error(dyn_mdl(mod_file, fit_mod_file = c("mod_out", "x"), silent = TRUE),
               "Argument 'fit_mod_file' must be a character vector of length 1.")

})
