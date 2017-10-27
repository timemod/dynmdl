library(dynmdl)
library(testthat)

context("ISLM 2 countries model")

mod_file <- "mod/islm_countries.mod"
period <- "2016Q1/2020Q2"

report <- capture_output(mdl <- dyn_mdl(mod_file, period = period))

test_that("get_equations works correctly", {
  eqs <- mdl$get_equations()
  if (.Platform$OS.type == "windows") {
    eqs_tmp <- gsub("\r\n", "\n", eqs)
  }
  expect_equal_to_reference(eqs_tmp, "expected_output/islm_countries_eqs.rds")
})

# TODO: test solve_steady and solve