library(dynmdl)
library(testthat)
rm(list = ls())


source("../tools/read_dynare_result.R")
source("utils.R")

mod_name <- "islm_extfunc2"

square <<- function(x) {
  return(x * x)
}

square_d1 <<- function(x) {
  return(2*x);
}


multiply <<- function(x, y) {
  return(x * y)
}

multiply_d1 <<- function(x, y) {
  return(y);
}

multiply_d2 <<- function(x, y) {
  return(x);
}


mdl <- make_mdl(mod_name)
model_period <- mdl$get_period()

dynare_result <- read_dynare_result("islm", mdl)
test_that("solve", {
  mdl2 <- simul_islm(mdl)
  expect_equal(dynare_result$endo, mdl2$get_endo_data(period = model_period))
})
