library(dynmdl)
library(testthat)

context("function normcdf and normpdf")
library(dynmdl)

mod_file <- "mod/norm.mod"
period <- period("2018")

pnorm_d1 <<- dnorm

x <- capture_output({
  mdl_dll <- dyn_mdl("mod/norm.mod", period = period, calc = "dll")
  mdl_R <- dyn_mdl("mod/norm.mod", period = period, calc = "R")
  warnings <- capture_warnings(
      mdl_internal <- dyn_mdl("mod/norm.mod", period = period, 
                              calc = "internal")
  )
  expect_known_output(warnings, "expected_output/norm_warnings.txt",
                      print = TRUE)
})

test_that("solve_steady", {
  mdl_dll$solve_steady(control = list(silent = TRUE))
  mdl_R$solve_steady(control = list(silent = TRUE))
  mdl_internal$solve_steady(control = list(silent = TRUE))
  
  expect_equal(mdl_dll$get_static_endos(), mdl_R$get_static_endos())
  expect_equal(mdl_internal$get_static_endos(), mdl_R$get_static_endos())
})

test_that("solve", {

  mdl_dll$solve(silent = TRUE)
  mdl_R$solve(silent = TRUE)
  mdl_internal$solve(silent = TRUE)
  
  # check that y2 and y5 are equal
  ed <- mdl_R$get_endo_data()
  ts_labels(ed) <- NULL
  expect_equal(unname(ed[ , "y2"]), unname(ed[ , "y5"]))
  
  expect_known_output(ed, "expected_output/norm_endo_data.txt",
                      print = TRUE)
  
  expect_equal(mdl_dll$get_endo_data(), mdl_R$get_endo_data())
  expect_equal(mdl_dll$get_endo_data(), mdl_internal$get_endo_data())
  
  # check jacobians
  jac_dll <- mdl_dll$get_jacob()
  jac_R <- mdl_R$get_jacob()
  jac_internal <- mdl_internal$get_jacob()
  
  expect_equal(jac_dll, jac_R)
  expect_equal(jac_dll, jac_internal)
  
  # compare result with steady state result
  mdl <- mdl_R$copy()
  mdl$put_static_endos()
  expect_equal(mdl$get_endo_data(), mdl_R$get_endo_data())
})





