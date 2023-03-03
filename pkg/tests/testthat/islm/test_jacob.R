library(dynmdl)
library(testthat)


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

test_that("get_back_jacob", {
  
  jac <- mdl$get_back_jacob("2015q3")
  expect_known_value(jac,  "expected_output/islm_back_jac.rds")
})



