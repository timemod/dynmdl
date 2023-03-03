library(utils)
library(dynmdl)
library(testthat)

rm(list = ls())


rds_file <- "islm_model_fit.rds"
dum <- capture_output(mdl <- read_mdl(rds_file))

i <- regts(200, start = '2016Q1')
c <- regts(c(600, NA, 600), start = '2016Q1')
y <- regts(c(990, NA, 1010), start = '2016Q1')
fit <- cbind(i, c, y)
ts_labels(fit) <- c("Investment", "Consumption", "Income")
mdl$set_fit(fit)

new_fit <- fit[mdl$get_data_period(), ]
new_fit[ , "t" ] <- 210
new_fit["2016Q2/2017Q1", c("y", "c")] <- 810:813
new_fit["2017Q1", "i"] <- 190
new_fit <- new_fit[, intersect(mdl$get_endo_names(), colnames(new_fit))]
new_fit <- update_ts_labels(new_fit, c(t = "Tax"))

test_that("set_fit_values works correctly", {
  mdl2 <- mdl$copy()
  mdl2$set_fit_values(210, names = "t")
  mdl2$set_fit_values(810:813, names = c("y", "c"), period = "2016Q2/2017Q1")
  mdl2$set_fit_values(190, pattern = "^i$", period = "2017Q1")
  expect_equal(mdl2$get_fit(), new_fit)
  mdl2$set_fit_values(NA, names = "yd")
  expect_equal(mdl2$get_fit(), new_fit)
  mdl2$set_fit_values(NA, names = "t")
  expect_equal(mdl2$get_fit(), new_fit["2016Q1/2017Q1" , c("y", "c", "i")])
  mdl2$set_fit_values(NA, period = "2016Q4/")
  expect_equal(mdl2$get_fit(names = c("c", "i", "y")), 
               new_fit["2016Q1/2016Q3" , c("c", "i", "y")])
})

test_that("set_fit_values handles errors correctly", {
  mdl2 <- mdl$copy()
  msg <- "\"xxx\" is not an endogenous variable\\."
  expect_error(mdl2$set_fit_values(1, names = c("y", "xxx")), msg)
  msg <- "The following names are no endogenous variables: \"p\", \"xxx\"\\."
  expect_error(mdl2$set_fit_values(1, names = c("p", "xxx")), msg)
  expect_warning(mdl2$set_fit_values(1, pattern = "xxx"), 
                 "No endogenous variables match pattern \"xxx\".")
})
