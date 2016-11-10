library(dynr)

mod_file <- "testje.mod"

mdl <- compile_model(mod_file)

# calculate the stready state
mdl$solve_steady()
print(mdl$endos)

mdl$set_period("2015/2018")

mdl$exo_data[1] <- 0.1

mdl$check()
mdl$solve_perturbation()

print(mdl$endo_data)
mdl$solve(control = list(trace = TRUE))
print(mdl$endo_data)

