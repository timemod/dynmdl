library(dynmdl)
library(testthat)

context("ISLM model with fit procedure")

rds_file <- "islm_model_fit.rds"
dynare_dir     <- "dynare/output"
endo_name_file <- file.path(dynare_dir, "islm_fit_endo_names.txt")
endo_file <- file.path(dynare_dir, "islm_fit_endo.csv")

report <- capture_output(mdl <- read_mdl(rds_file))
mdl$set_param(c(sigma_ut = 7, sigma_uc = 5, sigma_ui = 21, sigma_umd = 2))

mdl_old <- mdl$copy()

test_that("all.equal works correctly for fit models", {
  expect_true(isTRUE(all.equal(mdl, mdl_old)))
})

mdl$set_fit(regts(c(1250, 1255, 1260), start = "2016Q1"), names = "y")
mdl$set_fit(regts(c(250, 255), start = "2016Q1"), names = "t")

test_that("all.equal works correctly for fit models", {
  expect_false(isTRUE(all.equal(mdl, mdl_old)))
})

mdl$solve(control = list(silent = TRUE))

endo_names <- read.csv(endo_name_file, stringsAsFactors = FALSE,
                       header = FALSE, sep = "")[[1]]
endo_data <- t(as.matrix(read.csv(endo_file, header = FALSE)))
dynare_result <- regts(endo_data, start = start_period(mdl$get_period()) - 1,
                       names = endo_names)[, mdl$get_endo_names()]
dynare_result <- update_ts_labels(dynare_result, mdl$get_labels())
dynare_result <- dynare_result[, order(colnames(dynare_result))]
dynare_result <- update_ts_labels(dynare_result, mdl$get_labels())

test_that("dynare result equal to islm result", {
  p <- get_period_range(dynare_result)
  expect_equal(dynare_result, mdl$get_endo_data(period = p))
})
