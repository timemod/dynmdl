library(dynmdl)
library(testthat)

context("ISLM model get_equations")

report <- capture_output(mdl <- read_mdl("islm_model.rds"))

mdl$set_period("2015Q3/2015Q4")

test_that("get_static_jacob works correctly", {
  
  jac <- mdl$get_static_jacob()
  expect_known_value(jac,  "expected_output/islm_static_jac.rds")
  
  
  jac_sparse <- mdl$get_static_jacob(sparse = TRUE)
  expect_s4_class(jac_sparse, "dgCMatrix")
})


test_that("get_jacob works correctly", {
 
  jac <- mdl$get_jacob()
 
  expect_known_value(jac,  "expected_output/islm_jac.rds")
  
  
  jac_sparse <- mdl$get_jacob(sparse = TRUE)
  expect_s4_class(jac_sparse, "dgCMatrix")
})

test_that("get_back_jacob gives an error", {
  
  expect_error(mdl$get_back_jacob(), 
    "Method get_back_jacob can only be used for backward looking models")
})



