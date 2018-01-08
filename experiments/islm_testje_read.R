# Basic example of the ISLM model with lags

library(dynmdl)

#mdl_onzin  <- dyn_mdl("mod/islm.mod", calc = "internal")

mdl <- read_mdl("testje.rds")
print(mdl)
print(mdl$get_static_jacob())
mdl$solve_steady()

mdl$solve()
