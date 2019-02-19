library(dynmdl)
library(testthat)
rm(list = ls())

context("ISLM model miscellaneous errors")

test_that("undefined variable in parameter initialisation", {
  msg <-  paste0("Error evaluating parameter t1.\n",
   "Probably some variables on the right hand side do not exist.")      
  rep <- capture_output(
    expect_error(mdl1 <- dyn_mdl("mod/islm_error1.mod"), msg)
  )          
})

test_that("undefined variable in initval", {
  msg <-  paste0("Error evaluating initval/endval of variable md.\n",
                 "Probably some variables on the right hand side do not exist.")      
  rep <- capture_output(
    expect_error(mdl1 <- dyn_mdl("mod/islm_error2.mod"), msg)
  )          
})
