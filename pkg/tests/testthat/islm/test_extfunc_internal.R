library(dynmdl)
library(testthat)
rm(list = ls())


source("../tools/read_dynare_result.R")
source("utils.R")

mod_name <- "islm_extfunc"

square <<- function(x) {
  return(x * x)
}
multiply <<- function(x, y) {
  return(x * y)
}

mdl <- make_mdl(mod_name, calc = "internal")
model_period <- mdl$get_period()

dynare_result <- read_dynare_result("islm", mdl)
test_that("solve", {
  mdl2 <- simul_islm(mdl)
  expect_equal(dynare_result$endo, mdl2$get_endo_data(period = model_period))
})

test_that("steady state and eigenvalues", {
  
  expect_equal(mdl$get_static_endos(), dynare_result$steady)
  check_report <- capture_output(mdl$check())
  
  eigvals <- mdl$get_eigval()
  expect_equal(eigvals[1:3], dynare_result$eigval[1:3, 1])
  expect_equal(is.finite(eigvals[4]), FALSE)
  
})
