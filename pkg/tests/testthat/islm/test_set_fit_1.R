library(utils)
library(dynmdl)
library(testthat)

context("set_fit (1) for the ISLM model")

rds_file <- "islm_model_fit.rds"
capture_output(mdl <- read_mdl(rds_file))
 
i <- regts(200, start = '2016Q1')
c <- regts(c(600, NA, 600), start = '2016Q1')
y <- regts(c(990, NA, 1010), start = '2016Q1')
fit <- cbind(i, c, y)
ts_labels(fit) <- c("Investment", "Consumption", "Income")

# an ordered list of fit values without identities:
fit_ordered <- fit[, order(colnames(fit))]
 
fit2 <- fit
fit2["2016q1", "i"] <- NA
fit2["2016q2", "c"] <- 650
 
fit_mdl <- mdl$copy()
fit_mdl <- fit_mdl$set_fit(fit)

test_that("set_fit update mode upd", {
 
  expect_equal(fit_mdl$get_fit(), fit_ordered)
  
  # the model data should not have changed
  expect_equal(fit_mdl$get_endo_data(), mdl$get_endo_data())
  
  fit_mdl2 <- mdl$copy()
  fit_mdl2$set_fit(fit)

  expect_equal(fit_mdl2$get_fit(), fit_ordered)
})

test_that("set_fit for update mode upd (second test)", {
  fit_mdl2 <- fit_mdl$copy()
  fit_mdl2$set_fit(fit2)

  fit_combi <- update_ts(fit, fit2, method = "upd")[, c("c", "y")]
  
  expect_equal(fit_mdl2$get_fit(), fit_combi)
  
  # the model data should not have changed
  expect_equal(fit_mdl2$get_endo_data(), mdl$get_endo_data())
})

test_that("errors", {
  
  fit_mdl2 <- fit_mdl$copy()
  weird_fit <- cbind(fit, x = 3)
 
  msg <-   "\"x\" is not an endogenous model variable"
  
  expect_error(fit_mdl2$set_fit(weird_fit), msg)

  
  expect_error(fit_mdl2$set_fit(weird_fit, name_err = "silent"), NA)
  expect_equal(fit_mdl2$get_fit(), fit_ordered)
  
  expect_warning(fit_mdl2$set_fit(weird_fit[, "x", drop = FALSE], 
                                  name_err = "warn"), msg)
  
  msg <-   "\"x\", \"z\" are no endogenous model variables"
  
  expect_warning(fit_mdl2$set_fit(cbind(weird_fit, z = 2)[, drop = FALSE], 
                                  name_err = "warn"), msg)
})

# 
# test_that("set_fit for update mode updval", {
#   fit_mdl2 <- fit_mdl$clone(deep = TRUE)
#   fit_mdl2$set_fit(fit2, upd_mode = "updval")
# 
#   fit_combi <- update_ts(fit, fit2, method = "updval")[, c("c", "i", "y")]
#   # update labels (update_ts does not handle labels correctly yet)
#   fit_combi <- update_ts_labels(fit_combi, ts_labels(fit))
# 
#   expect_equal(fit_mdl2$get_fit(), fit_combi)
#   expect_equal(fit_mdl2$get_data(), mdl$get_data())
# })
# 
# test_that("set_fit_values", {
#   fit_mdl2 <- fit_mdl$clone(deep = TRUE)
#   fit_mdl2$set_fit_values(NA, names = c("c", "y"), period = "2015Q4")
#   expect_equal(fit_mdl2$get_fit(), fit_ordered["2015Q2", , drop = FALSE])
# 
#   fit_mdl2$set_fit_values(NA, names = c("c", "i", "y"), period = "2015Q2")
#   expect_null(fit_mdl2$get_fit())
# })
