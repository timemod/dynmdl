# Exclude the following files from lintr. These files still contain many
# style errors. The style of these function should be fixed later.
exclusions <- list(
  "tests",
  "vignettes",
  "R/all.equal.R",
  "R/check_dynare_internal.R",
  "R/dyn_mdl.R",
  "R/DynMdl.R",
  "R/endo_data_solve.R",
  "R/get_data_period.R",
  "R/get_dynare_option_string.R",
  "R/get_power_deriv.R",
  "R/get_var_indices_back.R",
  "R/init_state_space.R",
  "R/RcppExports.R",
  "R/report_non_finite_residuals.R",
  "R/run_dynare_internal.R",
  "R/run_dynare.R",
  "R/solve_dynare_internal.R",
  "R/solve_first_order.R",
  "R/solve_perturbation_.R",
  "R/solve_steady_dynare_internal.R",
  "R/svd_analysis.R",
  "R/update_serialized_mdl.R",
  "R/time_functions.R",
  "R/trim_ts.R",
  "R/write_initval_file_internal.R",
  "R/write_mod_file_internal.R"
)

library(lintr)

# Create a list of linters that should be modified or removed ------------------
linters_mut <- list(
  line_length_linter = line_length_linter(100),
  object_name_linter = NULL,
  commented_code_linter = NULL,
  return_linter = NULL,
  trailing_whitespace_linter = NULL
)

# Some linters may not be available for the specific version of lintr.
sel <- names(linters_mut) %in% names(default_linters)
linters_mut <- linters_mut[sel]

#  Lint the files in the package -----------------------------------------------
linters <- do.call(linters_with_defaults, linters_mut)

# Some linters may not be available for the specific version of lintr.
sel <- names(linters_mut) %in% names(default_linters)
linters_mut <- linters_mut[sel]

#  Lint the files in the package -----------------------------------------------
linters <- do.call(linters_with_defaults, linters_mut)

lints <- lint_package("pkg", exclusions = exclusions, linters = linters)

if (length(lints) > 0) {
  cat("\nLinter detected style issues:\n")
  print(lints)
  stop("Linter failed. Please fix the above issues.")
} else {
  message("No linting issues found")
}
