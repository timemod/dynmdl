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
mdl$exo_data["2010Q1", "g"] <- mdl$exo_data["2010Q1", "g"] + 1
mdl$solve_perturbation()
print(mdl$endo_data)
mdl$solve(control = list(trace = TRUE))
print(mdl$endo_data)
