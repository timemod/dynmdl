library(dynmdl)

mod_file <- "mod/islm_countries.mod"


t <- system.time(mdl <- dyn_mdl(mod_file, calc = "internal"))
cat("compiling:\n")
print(t)

mdl$set_period("2017Q1/2066Q4")
mdl$set_endo_values(1300, names = "y_co_1", period = "2016Q4")

t <- system.time(mdl$solve(control = list(trace = TRUE)))
cat("solving:\n")
print(t)

t <- system.time(mdl$write_mdl("aap.rds"))
cat("write_mdl:\n")
print(t)
