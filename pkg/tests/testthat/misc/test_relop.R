library(dynmdl)
library(testthat)
rm(list = ls())
context("model with relational operators")

# NOTE: the IFN model is not normal DSGE model,
# the steady state is not well defined and
# the Blanchard-Kahn-conditions are not satisfied.
# However, it may still be solved with the stacked-time algorithm.
model_name <- "relop"

update_expected_output <- FALSE

mod_file <- file.path("mod", paste0(model_name, ".mod"))
exo_data <- regts(matrix(1:4, ncol = 1), names = "x", start = "2015")

report <- capture_output({
  mdl_R <- dyn_mdl(mod_file, data = exo_data)$solve()
  mdl_internal <- dyn_mdl(mod_file, data = exo_data, calc = "internal")$solve()
  mdl_dll <- dyn_mdl(mod_file, data = exo_data, calc = "dll")$solve()
})

test_that("all resuls are equal", {
  result <- mdl_R$get_endo_data()
  expect_known_output(result, print = TRUE,
                      file = file.path("expected_output", "relop_result.txt"),
                      update = update_expected_output)
  expect_equal(result, mdl_internal$get_endo_data())
  expect_equal(result, mdl_dll$get_endo_data())
})

