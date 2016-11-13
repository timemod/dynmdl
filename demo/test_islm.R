library(dynr)

mod_file <- system.file("extdata", "islm.mod", package = "dynr")
mdl <- compile_model(mod_file)

#print(mdl$endos)

system.time(
   mdl$solve_steady(control = list(trace = 1))
)
#print(mdl$endos)
mdl$check()

mdl$set_period(regperiod_range("2010Q1", "2011Q4"))

# shock for variable g in first solve perod
mdl$set_exo_value(names = "g", value = 280, period = "2010Q1")

print(system.time(
    mdl$solve(control = list(trace = TRUE))
))

plot(mdl$get_endo_data()[, 'y'])
