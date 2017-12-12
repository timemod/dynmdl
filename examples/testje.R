# Basic example of the ISLM model with lags

library(dynmdl)

mdl <- dyn_mdl("mod/islm.mod", calc = "internal")
mdl$set_period("2017Q1/2022Q1")
mdl$write_mdl("testje.rds")
mdl$solve()
