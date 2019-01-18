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
  
  data <- cbind(endo_data, exo_data)
  d <<- data
  data <- data[, order(colnames(data))]
  testp <- "2017Q1"
  expect_equal(mdl3$get_data(period = testp), data[testp, ])
  
  names <- c("g", "c")
  pattern <- "^y.?$"
  expect_equal(mdl3$get_data(names = names, pattern = pattern), 
               data[, c("c", "g", "y", 'yd')])
  
  expect_equal(mdl3$get_data(names = "i"), data[, "i", drop = FALSE])
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

test_that("get_names", {
  endo_names <- c("y", "yd", "t",  "c", "i", "md", "r") 
  expect_equal(mdl$get_endo_names(), endo_names)
 
  expect_equal(mdl$get_endo_names(type = "lag"), c("y", "yd"))
  expect_equal(mdl$get_endo_names(type = "lead"), c("y", "yd"))
  
  expect_equal(mdl$get_exo_names(), c("g", "ms"))
  
  par_names <- c(paste0("c", 0:5), paste0("i", 0:5), paste0("m", 0:3),
                 paste0("t", 0:1))
  expect_equal(mdl$get_par_names(), par_names)
})

test_that("get_data errors", {
    
  expect_error(
    mdl$get_data(names = c("aap", "g"), pattern = "^y"),
      "\"aap\" is not a model variable"
  )
  expect_error(
    mdl$get_endo_data(names = c("aap", "g"), pattern = "^y"),
    "\"aap\", \"g\" are no endogenous model variables"
  )
  
  expect_error(
    mdl$get_exo_data(names = c("aap", "g"), pattern = "^y"),
    "\"aap\" is not an exogenous model variable"
  )
  
  expect_null(mdl$get_data(pattern = "xxx"))
  expect_null(mdl$get_endo_data(pattern = "xxx"))
  expect_null(mdl$get_exo_data(pattern = "xxx"))
})