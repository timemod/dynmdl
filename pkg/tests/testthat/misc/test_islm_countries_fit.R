library(dynmdl)
library(testthat)

context("ISLM 2 countries model - fit")

mod_file <- "mod/islm_countries_fit.mod"
period <- "2016Q1/2020Q2"

report <- capture_output(mdl <- dyn_mdl(mod_file, period = period))

test_that("get_equations works correctly", {
  eqs <- mdl$get_equations()
  expect_equal_to_reference(eqs, "expected_output/islm_countries_fit_eqs.rds")
})

# TODO: test solve_steady and solve