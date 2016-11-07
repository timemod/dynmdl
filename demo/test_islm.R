library(dynr)
source("solve_first_order2.R")

mod_file <- system.file("extdata", "islm.mod", package = "dynr")
mdl <- compile_model(mod_file)

#print(mdl$endos)

system.time(
   mdl$solve_steady()
)
#print(mdl$endos)
mdl$check()

solve_first_order2(mdl, solve = TRUE)

#
#
# mdl$set_period(regperiod_range("2010Q1", "2011Q4"))
#
# # shock for variable g in first solve perod
# mdl$exo_data['2010Q1', 'g'] <- 280
#
# print(system.time(
#     mdl$solve()
# ))
#
# print(mdl$solve_out$message)
# print(mdl$solve_out$iter)
#
# plot(mdl$endo_data[, 'y'])
