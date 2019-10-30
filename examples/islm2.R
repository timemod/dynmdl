# Basic example of the ISLM model with lags

library(dynmdl)

mdl <- dyn_mdl("mod/islm2.mod")
print(mdl)

mdl$solve_steady(control = list(trace = TRUE))
mdl$set_period("2017Q1/2040Q3")

#  set exogenous variables
shock_period <- mdl$get_period() 
mdl$set_exo_values(280 * cumprod(rep(1.005, nperiod(shock_period))), 
                   names = "g",  period = shock_period)
mdl$solve(control = list(trace = TRUE))

print(mdl$get_endo_data(period = mdl$get_period()))
plot(mdl$get_endo_data(names = "ddy", period = "2020Q2/"), type = "o")
