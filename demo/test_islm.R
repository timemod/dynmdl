library(dynr)

mod_file <- system.file("extdata", "islm.mod", package = "dynr")
mdl <- compile_model(mod_file)

#print(mdl$endos)

system.time(
   mdl$solve_steady(control = list(trace = 1))
)
#print(mdl$endos)input <- as.regts(df)

mdl$check()

mdl$set_period(regperiod_range("2015", "2020"))

df <- read.csv("input.csv")
input <- as.regts(df, time_column = 1)
print(input)
mdl$set_data(input, update_mode = "updval")
#mdl$set_endo_data(input, update_mode = "update")
print(mdl$get_exo_data())
print(mdl$get_endo_data())

# shock for variable g in first solve perod
# mdl$set_exo_value(names = "g", value = 280, period = "2015")
# mdl$set_endo_value(names = "y", value = 1200, period = "2014")
# mdl$set_endo_value(names = "yd", value = 1000, period = "2014")

# print(system.time(
#     mdl$solve(control = list(trace = TRUE))
# ))
#
# plot(mdl$get_endo_data(names = 'y'))
