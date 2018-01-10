# Basic example of the ISLM model with lags

library(dynmdl)

multiply <- function(x, y) {
  return(x * y);
}

multiply_d1 <- function(x, y) {
  return(y);
}

multiply_d2 <- function(x, y) {
  return(x);
}

square <- function(x) {
  return(x**2);
}

square_d1 <- function(x) {
  return(2*x);
}

mdl <- dyn_mdl("mod/islm_extfunc2.mod", calc = "internal",
               period = "2018")

print(mdl$residual_check())
print(mdl$get_jacob())

mdl$solve_steady()
mdl$solve()
