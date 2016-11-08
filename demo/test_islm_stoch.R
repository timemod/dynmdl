library(dynr)

mod_file <- system.file("extdata", "islm.mod", package = "dynr")
mdl <- compile_model(mod_file)

#print(mdl$endos)

system.time(
   mdl$solve_steady()
)
#print(mdl$endos)
mdl$check()

mdl$stoch_simul()

