library(dynmdl)

mdl <- dyn_mdl("testje.mod", calc = "internal")
print(mdl, short = FALSE)

mdl$set_period("2010Q1/2010Q2");
mdl$set_endo_values(names = "z", value = 1:3)
print(mdl$get_endo_data())
print(mdl$residual_check())
