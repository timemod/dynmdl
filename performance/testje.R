library(dynmdl)
source("create_islm_country_model.R")

mod_file <- "mod/islm_countries_150.mod"
t <- system.time(mdl <- dyn_mdl(mod_file, use_dll = FALSE))
cat("compiling:\n")
print(t)

mdl$set_period("2017Q1/2066Q4")
mdl$set_endo_values(1300, names = "y_co_1", period = "2016Q4")

t <- system.time(mdl$write_mdl("tmp.rds"))
cat("writing:\n")
print(t)

t <- system.time(mdl2 <- read_mdl("tmp.rds"))
cat("reading:\n")
print(t)

#print(mdl2$get_endo_data())

unlink("tmp.rds")

#print(mdl2, short = FALSE)
