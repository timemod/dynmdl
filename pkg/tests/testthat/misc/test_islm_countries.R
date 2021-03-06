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
  } else {
    eqs_tmp <- eqs
  }
  eqs_txt <- paste(eqs_tmp, collapse = "\n")
  expect_known_output(cat(eqs_txt), "expected_output/islm_countries_eqs.txt")
})

# TODO: test solve_steady and solve