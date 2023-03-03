library(dynmdl)
library(testthat)
rm(list = ls())


source("../tools/read_dynare_result.R")
source("utils.R")

mod_name <- "islm_extfunc2"

square <<- function(x) {
  return(list(x * x, 2 * x))
}
multiply <<- function(x, y) {
  return(list(x * y, c(y,  x)))
}

mdl <- make_mdl(mod_name, calc = "dll")
model_period <- mdl$get_period()

dynare_result <- read_dynare_result("islm", mdl)

test_that("solve", {
  mdl2 <- simul_islm(mdl)
  expect_equal(dynare_result$endo, mdl2$get_endo_data(period = model_period))
  expect_error(mdl2$solve_perturbation(),
               paste("The perturbation approach currently only allows shocks",
                     "in the first period"))
})

