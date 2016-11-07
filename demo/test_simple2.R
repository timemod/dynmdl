library(dynr)

source("solve_first_order2.R")
mod_file <- "simple2.mod"
mdl <- compile_model(mod_file)

# calculate the stready state
mdl$solve_steady()
print(mdl$endos)

mdl$set_period("2015/2060")

mdl$check()

solve_first_order2(mdl, solve = TRUE)

# mdl$endo_data["2014", 'y'] <- 1
#
# get_analytical_solution = function(period, mu) {
#     return (regts(cumprod(c(1, rep(mu, length_range(mdl$model_period) + 1))),
#                   period = mdl$endo_period))
# }
#
# analytical_solution_1 <- get_analytical_solution(mdl$endo_period, mu_1)
# analytical_solution_2 <- get_analytical_solution(mdl$endo_period, mu_2)
#
# lead_per <- end_period(mdl$endo_period)
# mdl$endo_data[lead_per, 'y'] <- analytical_solution_1[lead_per]
#
# print(system.time(
#     mdl$solve(control = list(trace = TRUE))
# ))
#
# print(mdl$solve_out$solved)
# print(mdl$solve_out$iter)
#
# plot(mdl$endo_data[mdl$endo_period, "y"], type = 'p')
# lines(analytical_solution_1[mdl$endo_period], col = "red")
# lines(analytical_solution_2[mdl$endo_period], col = "green")
