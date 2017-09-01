library(dynmdl)
library(testthat)

context("Test for DynMdl methods set_data, set_endo_values and set_exo_values")

period <- period_range("2017Q1/2017Q2")


report <- capture_output(mdl <- islm_mdl(period))

data_period <- mdl$get_data_period()


update_mdl_data <- function(data, new_data) {
  p <- range_intersect(data_period, get_period_range(new_data))
  data[p, colnames(new_data)] <- new_data[p, ]
  return(data)
}

endo_data_org <- mdl$get_endo_data()
exo_data_org  <- mdl$get_exo_data()

test_that("set_data, set_endo_values and set_exo_values works correctly (1)", {
  
  # prepare data
  g  <- regts(c(241, NA, 243), start = start_period(period))
  y  <- regts(c(1210, 1215, 1220), start = start_period(period) + 1)
  yd <- y
  t <- regts(260, period = period)
  ms <- regts(240, period = period + 2)
  data <- cbind(g, y, t, ms, yd)
  
  mdl2 <- mdl$clone()
  
  expect_true(isTRUE(all.equal(mdl, mdl2)))
  
  mdl2$set_data(data)
  
  expect_false(isTRUE(all.equal(mdl, mdl2)))
  
  mdl3 <- mdl$clone()
  p <- get_period_range(data)
  mdl3$set_exo_values(as.numeric(data[, "g"]), names = "g", period = p)
  mdl3$set_endo_values(as.numeric(data[, "y"]), pattern = "^y.?", period = p)
  mdl3$set_endo_values(as.numeric(data[, "t"]), names = "t", period = p)
  mdl3$set_exo_values(as.numeric(data[, "ms"]), names = "ms", period = p)
  
  # calculate correct results
  endo_data <- update_mdl_data(endo_data_org, data[, c("y", "yd", "t")])
  exo_data <- update_mdl_data(exo_data_org, data[, c("ms", "g")])
  
  expect_equal(mdl2$get_endo_data(), endo_data)
  expect_equal(mdl2$get_exo_data(),  exo_data)
  expect_equal(mdl3$get_endo_data(), endo_data)
  expect_equal(mdl3$get_exo_data(),  exo_data)
})

test_that("mdl2 is a different object than mdl", {
  expect_equal(mdl$get_endo_data(), endo_data_org)
  expect_equal(mdl$get_exo_data(),  exo_data_org)
})

test_that("set_data and set_values works correctly (2)", {
  
  # prepare data
  data <- cbind(endo_data_org, exo_data_org)
  data[] <- 999
  
  mdl2 <- mdl$clone()
  mdl2$set_data(data)
  
  mdl3 <- mdl$clone()
  mdl3$set_endo_values(999)
  mdl3$set_exo_values(999)
  
  # calculate correct results
  endo_data <- endo_data_org
  exo_data <- exo_data_org
  endo_data[]  <- 999
  exo_data[]   <- 999
  
  expect_equal(mdl2$get_endo_data(), endo_data)
  expect_equal(mdl2$get_exo_data(),  exo_data)
  expect_equal(mdl3$get_endo_data(), endo_data)
  expect_equal(mdl3$get_exo_data(),  exo_data)
})
