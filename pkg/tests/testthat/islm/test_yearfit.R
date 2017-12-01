library(testthat)
library(dynmdl)
rm(list = ls())

context("ISLM model with year fit")

source("../tools/read_dynare_result.R")

model_name <- "islm_yearfit"
nperiods <- 18
mod_file <- file.path("mod", paste0(model_name, ".mod"))
fit_mod_file <- "mod_out/islm_yearfit.mod"
fit_mod_org_file <- "mod_out_org/islm_yearfit.mod"

p1 <- period("2016Q1")
model_period <- period_range(p1, p1 + nperiods - 1)

unlink(fit_mod_file)
report <- capture_output(mdl <- dyn_mdl(mod_file,
                                        fit_mod_file = fit_mod_file))

mdl$solve_steady(control = list(silent = TRUE))
mdl$set_period(model_period)
mdl$set_fit(regts(1275, start = "2016Q4"), names = "y_year")
mdl$set_param(c(sigma_umd = 2, sigma_ui = 21))

mdl$solve(control = list(silent = TRUE))

dynare_result <- read_dynare_result(model_name, mdl)

test_that("generated fit mod file equal to reference ", {
  new <- readLines(fit_mod_file)
  old <- readLines(fit_mod_org_file)
  expect_identical(old, new)
})

test_that("dynare result equal to dynr result", {
  p <- mdl$get_period()
  expect_equal(dynare_result$endo, mdl$get_endo_data(period = p))
})
