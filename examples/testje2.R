# Basic example of the ISLM model with lags

library(dynmdl)

mdl <- read_mdl("aap.rds")
print(mdl)
mdl$solve(control = list(trace = TRUE))
