library(dynr)


mod_file <- system.file("extdata", "simple.mod", package = "dynr")

mdl <- compile_model(mod_file)

# calculate the stready state
mdl$solve_steady()
print(mdl$endos)

mdl$set_period("2015/2017")

#mdl$params['a'] <- 1
#mdl$params['b'] <- 0.2

with(as.list(mdl$params), {
    mu_1 <<- (1 - sqrt(1 - 4 * a * b)) / (2 * a)
    mu_2 <<- (1 + sqrt(1 - 4 * a * b)) / (2 * a)
    cat(sprintf("mu_1 = %g\n", mu_1))
    cat(sprintf("mu_2 = %g\n", mu_2))
})

mdl$check()

mdl$stoch_simul()
print(mdl$endo_data)

