library(dynmdl)
library(testthat)
rm(list = ls())
context("toy_free model")

source("../tools/read_dynare_result.R")

model_name <- "toy_free"
mod_file <- file.path("mod", paste0(model_name, ".mod"))
dynare_dir     <- "dynare/output"


#
# read dynare results
#
endo_name_file <- file.path(dynare_dir, paste0(model_name, "_endo_names.txt"))
steady_file <- file.path(dynare_dir, paste0(model_name, "_steady.csv"))
eigval_file <- file.path(dynare_dir, paste0(model_name, "_eigval.csv"))

endo_names_dynare  <- read.csv(endo_name_file, stringsAsFactors = FALSE,
                               header = FALSE, sep = "")[[1]]

steady_dynare <- read.csv(steady_file, header = FALSE, sep = "")[[1]]
names(steady_dynare) <- endo_names_dynare

eigval_dynare <- read.csv(eigval_file, header = FALSE, sep = ",")
i <- order(apply(eigval_dynare, MARGIN = 1, FUN = function(x) sqrt(sum(x**2))))
eigval_dynare <- eigval_dynare[i, ]

# compile the model
mdl <- dyn_mdl(mod_file, silent = TRUE)

test_that("solve_steady", {
  mdl$solve_steady(control = list(trace = FALSE, silent = TRUE))
  expect_equal(mdl$get_static_endos(), steady_dynare)
})

test_that("eigenvalues", {
  check_output <- capture_output({
    check_message <- capture.output(mdl$check(), type = "message")
  })
  BB_msgs <- c("", "Blanchard & Kahn conditions are not satisfied: indeterminacy",
               "")
  expect_equal(check_message, BB_msgs)
  eigval <- mdl$get_eigval()
  expect_equal(Re(eigval), eigval_dynare[, 1])
  expect_equal(Im(eigval), eigval_dynare[, 2])
})

test_that("run_initval",  {
  # check run_initval in case that the model has a parameters.
  mdl2 <- mdl$copy()
  mdl2$run_initval()
  expect_equal(mdl2$get_static_data(), c(i =  1, pi = 0.1, u = 0, y = 0.1))
})
