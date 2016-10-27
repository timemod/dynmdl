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
    mdl2 <- solve_model(mdl)
))

print(mdl2@solve_out$solved)
print(mdl2@solve_out$iter)

# compare analytical solution with calculated result
plot(mdl2@endo_data[mdl@model_period, 'E'])
lines(analytical_solution[mdl@model_period, 'E'], col = "red")

print(system.time(
    icols <- which(mdl@lead_lag_incidence != 0)
))
