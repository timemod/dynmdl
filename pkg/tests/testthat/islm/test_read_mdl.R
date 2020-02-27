library(dynmdl)
library(testthat)
rm(list = ls())

context("Reading and writing a model to an rds file")

mod_file <- "mod/islm.mod"
dll_dir <- "islm_dll"
islm_rds_file <- "islm_model.rds"
tmp_rds_file <- "mdl.rds"

mdl <- read_mdl(islm_rds_file, silent = TRUE)

mdl$set_param(c(c0 = 110))
mdl$solve(control = list(silent = TRUE))

mdl$write_mdl(tmp_rds_file, silent = TRUE)
mdl2 <- read_mdl(tmp_rds_file, silent = TRUE)

test_that("mdl and mdl2 are equal", {
  expect_equal(mdl, mdl2)
  expect_true(isTRUE(all.equal(mdl,  mdl2)))
  expect_equal(mdl2$get_param("c0"), c(c0 = 110))
})

mdl2$solve(control = list(silent = TRUE))

test_that("mdl and mdl2 are equal (after solving)", {
  expect_equal(mdl, mdl2)
})

report <- capture.output(mdl_dll <- dyn_mdl(mod_file, calc = "dll",
                                            dll_dir = dll_dir))
mdl_dll$solve_steady(control = list(silent = TRUE))
mdl_dll$set_period(mdl$get_period())
mdl_dll$set_param(c(c0 = 110))
mdl_dll$solve(control = list(silent = TRUE))

report <- capture_output(mdl_dll$write_mdl(tmp_rds_file))
unlink(dll_dir, recursive = TRUE)
report <- capture_output(mdl_dll2 <- read_mdl(tmp_rds_file, dll_dir = dll_dir))

test_that("mdl_dll and mdl_dll2 are equal", {
  expect_equal(mdl_dll, mdl_dll2)
  expect_true(isTRUE(all.equal(mdl_dll, mdl_dll2)))
  expect_equal(mdl_dll2$get_param("c0"), c(c0 = 110))
})

mdl_dll2$solve(control = list(silent = TRUE))

test_that("mdl_dll andn mdl_dll2 are equal (after solving)", {
  expect_equal(mdl_dll, mdl_dll2)
  expect_true(isTRUE(all.equal(mdl_dll, mdl_dll2)))
})

# clean up
unlink(tmp_rds_file)
unlink(dll_dir, recursive = TRUE)
