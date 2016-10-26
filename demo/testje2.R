library(dynr)

# read in the analytical solution from Dynare (stochatic simulation, first
# 250 period). This analytical solution is for a shock in e_g in period 2
# with value 0.0115.
solution_csv <-  system.file("extdata", "sa4_solution.csv", package = "dynr")
analytical_solution <- as.regts(read.csv(solution_csv), time_column = 1,
                                fun = function(x) {as.regperiod(x) + 2013})

mod_file <- system.file("extdata", "sa4.mod", package = "dynr")
print(system.time(mdl <- compile_model(mod_file)))

# check steady state. T All steady state values should be zero.
print(system.time(
    mdl <- solve_steady(mdl = mdl)
))
# should be very small
print(sum(abs(mdl@endos)))

model_period(mdl) <- regperiod_range("2015", "2263")

# analytical solution for lead period
per <- end_period(mdl@endo_period)
mdl@endo_data[per, names(mdl@endos)] <- analytical_solution[per, names(mdl@endos)]

# use same shock as analytical solution
mdl@exo_data["2015", 'e_g'] <- 0.0115


print(system.time(
    jac <- get_jacob(mdl)
))

lags <- dynr:::get_lags(mdl)
leads <- dynr:::get_leads(mdl)
exo <- dynr:::get_exo(mdl)
nper <- regts::lensub(mdl@model_period)
endo <- dynr:::get_solve_endo(mdl)
print(system.time({
    for (it in 1:249) {
        ret <- mdl@f_dynamic(endo, exo, mdl@params, it + mdl@max_exo_lag,
                             jac = TRUE)
    }
}))


jacfun <- function(y, exos, params, it) {
    return (mdl@f_dynamic(y, exos, params, it, jac = TRUE)[[2]])
}

endos <-c(dynr:::get_lags(mdl), dynr:::get_solve_endo(mdl),
          dynr:::get_leads(mdl))
exos <- dynr:::get_exo(mdl)

print(system.time({
    mat_info <- dynr:::get_triplet_jac_(mdl, endos, exos, jacfun)
    n <- lensub(mdl@model_period) * mdl@endo_count
    mat <- new("dgTMatrix", i = mat_info$rows, j = mat_info$columns,
           x = mat_info$values, Dim = as.integer(rep(n, 2)))
}))

