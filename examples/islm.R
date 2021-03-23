# Basic example of the ISLM model with lags

library(dynmdl)
mdl <- dyn_mdl("mod/islm.mod", latex_options = list(par_as_num = TRUE,
                                                    ndigits = 6), calc = "internal")
print(mdl)

mdl$set_static_endos(c(i = 30000))
print(mdl$run_initval())

print(mdl$get_mdldef())

mdl$solve_steady(control = list(trace = TRUE))
mdl$check()
mdl$set_period("2017Q1/2019Q3")

#  set exogenous variables
mdl$set_exo_values(280, names = "g", period = "2017Q1")
mdl$solve(control = list(trace = TRUE))

print(mdl$get_endo_data())
plot(mdl$get_endo_data(names = "y"), type = "o")
