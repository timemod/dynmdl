library(dynmdl)
library(testthat)


rm(list = ls())

test_that("dyn_mdl gives an error", {
  expect_error(dyn_mdl("non_existing.mod", silent = TRUE),
               "File 'non_existing.mod' does not exist")
  expect_error(dyn_mdl(c("non_existing.mod", "x"), silent = TRUE),
               "Argument 'mod_file' must be a character vector of length 1.")
  expect_error(dyn_mdl("mod", silent = TRUE),
               "'mod' is a directory")
  
  mod_file <- "test_ifn.R"
  msg <- paste("ERROR: test_ifn.R: line 1, cols 1-7: variable library is not",
               "a declared parameter or variable.")
  expect_error(dyn_mdl(mod_file, silent = TRUE), msg)

  if (.Platform$OS.type == "unix") {
    # test handling ~ in filename
    mod_file2 <- normalizePath(mod_file)
    home_dir <- Sys.getenv("HOME") 
    mod_file2 <- sub(home_dir, "~", mod_file2)
    msg <- sprintf(paste("ERROR: %s.+/test_ifn.R: line 1, cols 1-7: variable library is not",
                         "a declared parameter or variable."), home_dir)
    expect_error(dyn_mdl(mod_file2, silent = TRUE), msg)
  }
})
