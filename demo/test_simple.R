library(dynr)

mod_file <- system.file("extdata", "simple1.mod", package = "dynr")

mdl <- compile_model(mod_file)

# calculate the stready state
mdl$solve_steady()
print(mdl$endos)

mdl$set_period("2015/2060")

#mdl$params['a'] <- 1
#mdl$params['b'] <- 0.2

with(as.list(mdl$params), {
    mu_1 <<- (1 - sqrt(1 - 4 * a * b)) / (2 * a)
    mu_2 <<- (1 + sqrt(1 - 4 * a * b)) / (2 * a)
    cat(sprintf("mu_1 = %g\n", mu_1))
    cat(sprintf("mu_2 = %g\n", mu_2))
})

mdl$check()

mdl$endo_data["2014", 'y'] <- 1

get_analytical_solution = function(period, mu) {
    return (regts(cumprod(c(1, rep(mu, length_range(mdl$model_period) + 1))),
                  period = mdl$endo_period))
}

analytical_solution_1 <- get_analytical_solution(mdl$endo_period, mu_1)
analytical_solution_2 <- get_analytical_solution(mdl$endo_period, mu_2)

lead_per <- end_period(mdl$endo_period)
mdl$endo_data[lead_per, 'y'] <- analytical_solution_1[lead_per]

print(system.time({
    mdl$solve(control = list(trace = TRUE))
    solve_result <- mdl$endo_data
}))

mdl$solve_perturbation()
solve_perturb_result <- mdl$endo_data

plot(solve_result[mdl$endo_period, "y"], type = 'p')
lines(solve_perturb_result[mdl$endo_period, "y"], col = 'blue')
lines(analytical_solution_1[mdl$endo_period], col = "red")
lines(analytical_solution_2[mdl$endo_period], col = "green")
