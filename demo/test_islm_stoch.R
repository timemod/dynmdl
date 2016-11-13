library(dynr)

mod_file <- system.file("extdata", "islm.mod", package = "dynr")
mdl <- compile_model(mod_file)

#print(mdl$endos)

system.time(
   mdl$solve_steady()
)
#print(mdl$endos)
mdl$check()

mdl$set_period(regperiod_range("2010Q1", "2010Q2"))
mdl$set_exo_value(names = "g", value = 280, period = "2010Q1")
mdl$solve_perturbation()
print(mdl$get_endo_data())
mdl$solve(control = list(trace = TRUE))
print(mdl$get_endo_data())
