library(dynr)

# read in the analytical solution from Dynare (stochatic simulation, first
# 250 period). This analytical solution is for a shock in e_g in period 2
# with value 0.0115.
solution_csv <-  system.file("extdata", "sa4_solution.csv", package = "dynr")
analytical_solution <- as.regts(read.csv(solution_csv), time_column = 1,
                                fun = function(x) {as.regperiod(x) + 2013})

sa4 <- sa4_mdl

# check steady state. T All steady state values should be zero.
print(system.time(
    sa4$solve_steady()
))

# should be very small
print(sum(abs(sa4$endos)))

sa4$set_period(regperiod_range("2015", "2263"))

# analytical solution for lead period
per <- end_period(sa4$endo_period)
sa4$endo_data[per, names(sa4$endos)] <- analytical_solution[per,
                                                        names(sa4$endos)]

# use same shock as analytical solution
sa4$exo_data["2015", 'e_g'] <- 0.0115

print(system.time(
    sa4$solve()
))
print(sa4$solve_out$solved)
print(sa4$solve_out$iter)

# compare analytical solution with calculated result
plot(sa4$endo_data[sa4$model_period, 'E'])
lines(analytical_solution[sa4$model_period, 'E'], col = "red")
