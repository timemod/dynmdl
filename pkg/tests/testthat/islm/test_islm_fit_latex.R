library(dynmdl)
library(testthat)
rm(list = ls())

context("ISLM fit model latex")

source("utils.R")

model_name <- "islm_fit_latex"
mod_file <- file.path("mod", paste0(model_name, ".mod"))

if (.Platform$OS.type == "windows") {
  latex_dir <- "a\\b\\c"
} else {
  latex_dir <- "a/b/c"
}
latex_main_dir <- "a"
latex_filenames_ref <- c("dynamic_content.tex",  
                          "dynamic_fit_content.tex",  
                          "dynamic_single_eqs/dispensible_income.tex",
                          "dynamic_fit_single_eqs/dispensible_income.tex",
                          "dynamic.tex", "static_content.tex", 
                          "dynamic_fit.tex", "static_fit_content.tex", 
                          "static_single_eqs/dispensible_income.tex",
                          "static_fit_single_eqs/dispensible_income.tex",
                          "static.tex", "static_fit.tex")

latex_options <- list(dir = latex_dir, par_as_num = TRUE)

if (dir.exists(latex_main_dir)) unlink(latex_main_dir, recursive = TRUE)

test_that("latex files written correctly", {
  expect_false(dir.exists(latex_dir))
  expect_silent(mdl <- dyn_mdl(mod_file, silent = TRUE, 
                               latex_options = latex_options))
  expect_true(dir.exists(latex_dir))
  latex_filenames <- list.files(latex_dir, recursive = TRUE)
  expect_equal(sort(latex_filenames),  sort(latex_filenames_ref))
  
  
  for (filename in latex_filenames) {
    expect_silent(lines <- readLines(file.path(latex_dir, filename)))
    filename_no_dir <- sub("(\\\\|/)", "_", filename)
    expected_output_file <- file.path("expected_output", 
                                      paste0("islm_fit_", filename_no_dir))
    expect_known_output(lines, expected_output_file, print = TRUE)
  }
})

test_that("errors", {
  msg <- "Latex option 'dir' should be a single non-empty character string."
  expect_error(dyn_mdl(mod_file, silent = TRUE, latex_options = list(dir = 2)),
               msg)
  expect_error(dyn_mdl(mod_file, silent = TRUE, latex_options = list(dir = "")),
               msg)
  expect_error(dyn_mdl(mod_file, silent = TRUE, 
                       latex_options = list(dir = "  ")),
               msg)
  expect_error(dyn_mdl(mod_file, silent = TRUE, 
                       latex_options = list(dir = c("a", "b"))),
               msg)
})

if (dir.exists(latex_main_dir)) unlink(latex_main_dir, recursive = TRUE)
