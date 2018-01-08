# Basic example of the ISLM model with lags

library(dynmdl)

mdl <- dyn_mdl("mod/islm.mod")
print(mdl, short = FALSE)

print(mdl$get_static_jacob())

mdl$solve_steady()
print(mdl$get_static_endos())
