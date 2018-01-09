# Basic example of the ISLM model with lags

library(dynmdl)

multiply <- function(x, y) {
  return(x * y);
}

square <- function(x) {
  return(x**2);
}

mdl <- dyn_mdl("mod/islm_extfunc.mod", calc = "internal",
               period = "2018")

print(mdl$residual_check())
print(mdl$get_jacob())

mdl$solve_steady()
mdl$solve()
