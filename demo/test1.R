library(dynr)

mod_file <- "test1.mod"

mdl <- compile_model(mod_file)

# calculate the stready state
mdl$solve_steady()
print(mdl$endos)

mdl$set_period("2015/2016")

mdl$endo_data[1, ] <- 1

mdl$check()
mdl$solve_perturbation()

print(mdl$endo_data)
mdl$solve(control = list(trace = TRUE))
print(mdl$endo_data)


dynr:::printobj(mdl$rules$gx)
dynr:::printobj(mdl$rules$ghx)
