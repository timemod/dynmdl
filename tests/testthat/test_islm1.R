library(dynr)
context("ISLM model")

nperiods = 18

mod_file <- "mod/islm.mod"
endo_name_file <- "dynare/output/islm_endo_names.txt"
dynare_result_file <- "dynare/output/islm_simul.csv"
p1 <- regperiod("2011Q3")
model_period <- regperiod_range(p1, p1 + nperiods - 1)

report <- capture_output(mdl <- compile_model(mod_file))
mdl$solve_steady()
mdl$set_period(model_period)
lag_per <- start_period(mdl$get_endo_period())

endo_names <- read.csv(endo_name_file, stringsAsFactors = FALSE, header = FALSE,
                       sep = "")[[1]]


test_that("simulation with shock in g and historical value for y", {
    endo_data <- t(as.matrix(read.csv(dynare_result_file, header = FALSE)))
    dynare_result <- regts(endo_data,
                           start = start_period(mdl$get_endo_period()),
                           end = end_period(mdl$get_endo_period()),
                           names = endo_names)

    mdl$set_endo_values(1200, "y", lag_per)
    g_values <- c(245, 250, 260)
    mdl$set_exo_values(g_values, "g",
                       period = regperiod_range(p1, p1 + length(g_values) - 1))
    mdl$solve()
    expect_equal(dynare_result, mdl$get_endo_data())
})

