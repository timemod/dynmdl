# Basic example of the ISLM model with lags

library(dynmdl)

multiply <- function(x, y) {
  return(x * y);
}

square <- function(x) {
  return(x**2);
}

aap <- islm_mdl()

mdl <- read_mdl("testje.rds")

print(mdl$residual_check())
print(mdl$get_jacob())

mdl$solve_steady()
mdl$solve()
