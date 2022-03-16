library(dynmdl)
library(testthat)
rm(list = ls())

context("ISLM model latex")


update_expected_output <- FALSE

model_name <- "islm_latex"
mod_file <- file.path("mod", paste0(model_name, ".mod"))
latex_main_dir <- "latex"
latex_dir <- file.path(latex_main_dir, model_name)

latex_filenames_ref <- c("dynamic_content.tex", 
                         "dynamic_single_eqs/consumption.tex",
                         "dynamic_single_eqs/income.tex",   
                         "dynamic.tex", "static_content.tex", 
                         "static_single_eqs/consumption.tex",
                         "static_single_eqs/income.tex",
                         "static.tex")

if (dir.exists(latex_main_dir)) unlink(latex_main_dir, recursive = TRUE)

test_that("no latex files created when latex = FALSE", {
  expect_silent(mdl <- dyn_mdl(mod_file, latex = FALSE, silent = TRUE))
  expect_false(dir.exists(latex_dir))
})

test_that("latex files written correctly", {
  expect_false(dir.exists(latex_dir))
  expect_silent(mdl <- dyn_mdl(mod_file, silent = TRUE))
  expect_true(dir.exists(latex_dir))
  latex_filenames <- list.files(latex_dir, recursive = TRUE)
  expect_equal(sort(latex_filenames),  sort(latex_filenames_ref))
  for (filename in latex_filenames) {
    expect_silent(lines <- readLines(file.path(latex_dir, filename)))
    filename_no_dir <- sub("(\\\\|/)", "_", filename)
    expected_output_file <- file.path("expected_output", 
                                      paste0("islm_", filename_no_dir))
    expect_known_output(lines, expected_output_file, print = TRUE,
                        update = update_expected_output)
  }
})

test_that("test case existing latex dir", {
  expect_true(dir.exists(latex_dir))
  expect_silent(mdl <- dyn_mdl(mod_file, silent = TRUE))
  writeLines("dummy", con = file.path(latex_dir, "dummy.txt"))
  latex_filenames <- list.files(latex_dir, recursive = TRUE)
  expected_output <- sort(c(latex_filenames_ref, "dummy.txt"))
  expect_equal(latex_filenames, expected_output)
})

if (dir.exists(latex_main_dir)) unlink(latex_main_dir, recursive = TRUE)

test_that("no latex dir created when the mod file has no latex statements", {
  expect_silent(mdl <- dyn_mdl("mod/islm.mod", silent = TRUE))
  expect_false(dir.exists(latex_dir))
})


