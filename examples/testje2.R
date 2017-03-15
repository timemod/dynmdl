# Basic example of the ISLM model with lags

library(dynmod)

mdl <- read_mdl("aap.rds")
print(mdl)
mdl$solve(control = list(trace = TRUE))
