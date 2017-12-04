library(dynmdl)

mdl <- dyn_mdl("testje.mod", calc = "internal")
#print(mdl, short = FALSE)

mdl$set_period("2010Q1/2010Q2");
mdl$set_endo_values(names = "z", value = 1:4)
mdl$set_exo_values(names = "x", value = 0.1*(1:4))
print(mdl$get_endo_data())
print(mdl$get_exo_data())
print(mdl$residual_check())
print(mdl$get_jacob())
mdl$solve(control = list(trace = TRUE))
print(mdl$get_endo_data())
print(mdl$get_exo_data())
