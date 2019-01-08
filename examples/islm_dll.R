# Basic example of the ISLM model with lags

library(dynmdl)

mdl <- dyn_mdl("mod/islm.mod", calc = "dll")
#print(mdl, short = FALSE)

mdl$solve_steady(control = list(trace = TRUE))
mdl$set_period("2017Q1/2019Q3")

# set lags
mdl$set_endo_values(1200, names = "y", period = "2016Q4")
mdl$set_endo_values(1000, names = "yd", period = "2016Q4")

#  set exogenous variables
mdl$set_exo_values(280, names = "g", period = "2017Q1")
mdl$solve(control = list(trace = TRUE))

print(mdl$get_endo_data())
plot(mdl$get_endo_data("r"), type = "o")

# test writing and reading the model
rds_file <- "islm_dll.rds"
mdl$write_mdl(rds_file)
rm(mdl)
mdl <- read_mdl(rds_file)
mdl$solve(control = list(trace = TRUE))
unlink(rds_file)
