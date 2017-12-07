library(dynmdl)

mod_file <- "mod/islm_countries_150.mod"


t <- system.time(mdl <- dyn_mdl(mod_file, use_dll = TRUE))
cat("compiling:\n")
print(t)
quit()

mdl$set_period("2017Q1/2066Q4")
mdl$set_endo_values(1300, names = "y_co_1", period = "2016Q4")

t <- system.time(mdl$solve(control = list(trace = TRUE)))
cat("solving:\n")
print(t)


ret  <- run_series(ncountries)
time_table <- data.frame(ncountries = ncountries)
time_table <- cbind(time_table, ret)
rownames(time_table) <- NULL
print(time_table)
