library(testthat)
library(dynmdl)

context("set_fit (2) for ISLM model")

rds_file <- "islm_model_fit.rds"
capture_output(mdl <- read_mdl(rds_file))

# prepare rms values and fit targets
i <- regts(200, start = '2016Q1')
y <- regts(c(990, NA, 1010), start = '2016Q1')
fit_targets <- cbind(y, i)
ts_labels(fit_targets) <- c("Income", "Investment")

fit_targets_sorted <- fit_targets[ , c("i", "y")]
 
capture_output(mdl <- read_mdl(rds_file))
 
mdl$set_fit(fit_targets)
 
test_that("Testing get_fit after copying", {
  expect_identical(mdl$get_fit(), fit_targets_sorted)
  mdl2 <- mdl$copy()
  expect_identical(mdl2$get_fit(), fit_targets_sorted)
  mdl2$set_fit_values(NA)
  expect_null(mdl2$get_fit())
  expect_identical(mdl$get_fit(), fit_targets_sorted)
  mdl3 <- mdl$copy()
  c <- regts(200, start = '2016Q1')
  t <- regts(c(990, NA, 1010), start = '2016Q1')
  fit_targets2 <- cbind(c, t)
  ts_labels(fit_targets2) <- c("Consumption", "Tax")
  mdl3$set_fit(fit_targets2)
  expect_identical(mdl$get_fit(), fit_targets_sorted)
  res_correct <- cbind(fit_targets_sorted, fit_targets2)
  res_correct <- res_correct[, order(colnames(res_correct))]
  expect_identical(mdl3$get_fit(), res_correct)
})

test_that("Testing fit_targets after reading the model", {
  capture_output(mdl$write_mdl("temp.rds"))
  capture_output(mdl4 <- read_mdl("temp.rds"))
  unlink("temp.rds")
  expect_identical(mdl4$get_fit(), fit_targets_sorted)
})

