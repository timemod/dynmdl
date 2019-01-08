# Basic example of the ISLM model with lags

library(dynmdl)

mdl <- dyn_mdl("mod/islm.mod")
print(mdl, short = FALSE)

#mdl$solve_steady(control = list(trace = TRUE))

mdl$set_period("2017Q1/2019Q3")

#  set exogenous variables
mdl$set_exo_values(280, names = "g", period = "2017Q1")
#print(mdl$residual_check())
#print(mdl$get_jacob())
mdl$solve()

print(mdl$get_endo_data())
plot(mdl$get_endo_data(names = "y"), type = "o")
