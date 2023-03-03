library(utils)
library(dynmdl)
library(testthat)


capture_output(mdl <- read_mdl("islm_model.rds"))

old_endo_data <- mdl$get_endo_data()
old_exo_data <- mdl$get_exo_data()

test_that("univariate timeseries", {
  mdl2 <- mdl$copy()
  mdl2$set_data(regts(-5, period = "2015Q2/2015Q4"), names = "c", fun = `+`)
  expected_data <- old_endo_data
  expected_data["2015Q2/2015Q4", "c"] <- expected_data["2015Q2/2015Q4", "c"] - 5
  expect_equal(mdl2$get_endo_data(), expected_data)
})

test_that("multivariate timeseries", {

  # prepare shock
  g <- regts(c(1.1, 1.2), period = "2015Q2/2015Q3")
  ms <-  regts(1.2, period = "2015Q2")
  x <- 2 * ms
  shock <- cbind(g, ms, x)

  mdl2 <- mdl$copy()
  expect_error(mdl2$set_data(shock, fun = `/`),
               "\"x\" is not a model variable")
  expect_warning(mdl2$set_data(shock, fun = `/`, name_err = "warn"),
               "\"x\" is not a model variable")
  expected_data <- old_exo_data
  expected_data["2015Q2/2015Q3", c("g", "ms")] <-
    expected_data["2015Q2/2015Q3", c("g", "ms")] / shock[, c("g", "ms")]
  expect_equal(mdl2$get_exo_data(), expected_data)

  mdl3 <- mdl$copy()
  mdl3$set_data(shock, fun = `/`, upd_mode = "updval", name_err = "silent")
  expected_data <- old_exo_data
  expected_data["2015Q2/2015Q3", "g"] <- expected_data["2015Q2/2015Q3", "g"] / g
  expected_data["2015Q2", "ms"] <- expected_data["2015Q2", "ms"] / ms
  expect_equal(mdl3$get_exo_data(), expected_data)
})

test_that("name error", {
  G <- regts(c(1.1, 1,2), period = "2015Q2/2015Q3")
  MS <-  regts(1.2, period = "2015Q2")
  shock <- cbind(G, MS)
  mdl2 <- mdl$copy()
  msg <- "The following names are no model variables: \"G\", \"MS\"\\."
  expect_error(mdl2$set_data(shock), msg)
  expect_warning(mdl2$set_data(shock, name_err = "warn"), msg)
  expect_silent(mdl2$set_data(shock, name_err = "silent"))
  expect_equal(mdl$get_exo_data(), mdl2$get_exo_data())
})



