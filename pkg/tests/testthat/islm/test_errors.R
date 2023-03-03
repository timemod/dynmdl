library(dynmdl)
library(testthat)
rm(list = ls())


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

test_that("endogenous variables only with lags/leads", {
  msg <-  paste("The following endogenous variable\\(s\\) only appear\\(s\\) with",
                "lags/leads\nin the model equations and not as current",
                 "period variables:\n'yd'.")    
  expect_error(dyn_mdl("mod/islm_error3.mod", silent = TRUE), msg)
  
  msg <-  paste("The following endogenous variable\\(s\\) only appear\\(s\\) with",
                "lags/leads\nin the model equations and not as current",
                "period variables:\n'md', 'yd'.")    
  expect_error(dyn_mdl("mod/islm_error4.mod", silent = TRUE), msg)  
})

test_that("purely static model", {
  expect_silent(mdl <- dyn_mdl("mod/islm_error5.mod", silent = TRUE))  
  msg <-  paste("Methods 'check' and 'solve_perturbation' do not allow", 
                "purely static models\\.")
  expect_error(mdl$check(), msg)  
  mdl$set_period("1")
  expect_error(mdl$solve_perturbation(), msg)  
})
