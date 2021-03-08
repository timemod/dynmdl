library(dynmdl)
library(testthat)
rm(list = ls())

context("ISLM trend model latex")

model_name <- "islm_trend_latex"
mod_file <- file.path("mod", paste0(model_name, ".mod"))

latex_filenames_ref <- c('islm_trend_dynamic_content.tex', 
                         'islm_trend_dynamic_fit_content.tex', 
                         'islm_trend_dynamic_fit_single_eqs/tax.tex', 
                         'islm_trend_dynamic_fit.tex', 
                         'islm_trend_dynamic_single_eqs/tax.tex', 
                         'islm_trend_dynamic.tex', 
                         'islm_trend_original_content.tex', 
                         'islm_trend_original_single_eqs/tax.tex', 
                         'islm_trend_original.tex', 
                         'islm_trend_static_content.tex', 
                         'islm_trend_static_fit_content.tex', 
                         'islm_trend_static_fit_single_eqs/tax.tex', 
                         'islm_trend_static_fit.tex', 
                         'islm_trend_static_single_eqs/tax.tex', 
                         'islm_trend_static.tex')

test_that("latex files written correctly", {
  latex_dir <- tempfile()
  latex_options <- list(dir = latex_dir, prefix = "islm_trend", 
                        par_as_num = TRUE, ndigits = 1)
  
  expect_warning(
    messages <- capture.output(mdl <<- dyn_mdl(mod_file, silent = TRUE,  
                                               check_static_eqs = TRUE, 
                                               latex_options = latex_options), 
                               type = "message")
  )
  expect_true(dir.exists(latex_dir))
  latex_filenames <- list.files(latex_dir, recursive = TRUE)
  expect_equal(sort(latex_filenames),  sort(latex_filenames_ref))
  for (filename in latex_filenames) {
    expect_silent(lines <- readLines(file.path(latex_dir, filename)))
    filename_no_dir <- sub("(\\\\|/)", "_", filename)
    expected_output_file <- file.path("expected_output", filename_no_dir)
    expect_known_output(lines, expected_output_file, print = TRUE)
  }
  
  if (dir.exists(latex_dir)) unlink(latex_dir, recursive = TRUE)
})


test_that("latex files (no_fit) written correctly", {
  latex_dir <- tempfile()
  # check if it also works with forward slashes (for windows)
  latex_dir <- gsub("\\\\", "/", latex_dir)
  latex_options <- list(dir = latex_dir, prefix = "islm_trend_no_fit", 
                        par_as_num = TRUE, ndigits = 1)
  expect_warning(
    messages <- capture.output(mdl <<- dyn_mdl(mod_file, silent = TRUE,  
                                               check_static_eqs = TRUE, 
                                               fit = FALSE, strict = FALSE,
                                               latex_options = latex_options), 
                               type = "message")
  )
  expect_true(dir.exists(latex_dir))
  latex_filenames <- list.files(latex_dir,  recursive = TRUE)
  expected <- latex_filenames_ref
  expected <- grep("_fit", expected, value = TRUE, invert = TRUE) 
  expected <- sub("islm_trend", "islm_trend_no_fit", expected)
  expected <- sort(expected)
  expect_equal(sort(latex_filenames),  expected)
  
  for (filename in latex_filenames) {
    expect_silent(lines <- readLines(file.path(latex_dir, filename)))
    filename_no_dir <- sub("(\\\\|/)", "_", filename)
    expected_output_file <- file.path("expected_output", filename_no_dir)
    expect_known_output(lines, expected_output_file, print = TRUE)
  }
  
  if (dir.exists(latex_dir)) unlink(latex_dir, recursive = TRUE)
})

test_that("errors", {
  msg <- "Latex option 'prefix' should be a single non-empty character string."
  expect_error(dyn_mdl(mod_file, silent = TRUE, latex_options = list(prefix = 2)),
               msg)
  expect_error(dyn_mdl(mod_file, silent = TRUE, latex_options = list(prefix = "")),
               msg)
  expect_error(dyn_mdl(mod_file, silent = TRUE,
                       latex_options = list(prefix = "  ")),
               msg)
  expect_error(dyn_mdl(mod_file, silent = TRUE,
                       latex_options = list(prefix = c("a", "b"))),
               msg)
  msg <- "Latex option prefix should not contain a directory separator"
  expect_error(dyn_mdl(mod_file, silent = TRUE,
                       latex_options = list(prefix = c("a/b"))),
               msg)
  if (.Platform$OS.type == "windows") {
    expect_error(dyn_mdl(mod_file, silent = TRUE,
                         latex_options = list(prefix = c("a\\b"))),
                 msg)
  }
})


