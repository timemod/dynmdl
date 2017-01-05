library(dynr)

context("ISLM model with year fit")

nperiods <- 18
mod_file <- "mod/islm_yearfit.mod"
fit_mod_file <- "mod_out/islm_yearfit.mod"
fit_mod_org_file <- "mod_out_org/islm_yearfit.mod"
dynare_dir     <- "dynare/output"
endo_name_file <- file.path(dynare_dir, "islm_yearfit_endo_names.txt")
endo_file <- file.path(dynare_dir, "islm_yearfit_endo.csv")

p1 <- regperiod("2016Q1")
model_period <- regperiod_range(p1, p1 + nperiods - 1)

unlink(fit_mod_file)
report <- capture_output(mdl <- compile_model(mod_file,
                         fit_mod_file = fit_mod_file))

mdl$solve_steady()
mdl$set_period(model_period)
mdl$set_fit_targets(regts(1275, start = "2016Q4"), names = "y_year")

mdl$solve(control = list(silent = TRUE))

endo_names <- read.csv(endo_name_file, stringsAsFactors = FALSE,
                           header = FALSE, sep = "")[[1]]
endo_data <- t(as.matrix(read.csv(endo_file, header = FALSE)))
dynare_result <- regts(endo_data, start = start_period(mdl$get_period()) - 1,
                       names = endo_names)[, mdl$get_endo_names()]

test_that("generated fit mod file equal to reference ", {
    new <- readLines(fit_mod_file)
    old <- readLines(fit_mod_org_file)
    expect_identical(old, new)
})

test_that("dynare result equal to dynr result", {
    p <- get_regperiod_range(dynare_result)
    expect_equal(dynare_result, mdl$get_endo_data(period = p))
})
