library(dynr)
source("create_islm_country_model.R")

param_file <- "input/islm_country_params.csv"
basis_mod_file <- "mod/islm_back_countries.inp"
nextra_countries <- c(10, 100, 200)

# read parameters
param_data <- as.matrix(read.csv(param_file, row.names = 1))
param_names <- outer(rownames(param_data), colnames(param_data),
                     FUN = "paste", sep = "_")
params <- as.numeric(param_data)
names(params) <- as.character(param_names)
nextra <- 1000
mod_file <- paste0("mod/islm_back_countries_",
                   as.character(nextra), ".mod")
create_islm_country_model(basis_mod_file, mod_file, nextra)
mdl <- compile_model(mod_file, use_dll = TRUE)
mdl$set_period("2017Q1/2021Q2")
#mdl$set_period("2017Q1/2017Q1")
mdl$set_endo_values(1300, names = "y_nl", period = "2016Q4")

mdl$time_functions()

mdl2 <- mdl$clone()
mdl3 <- mdl$clone()

t <- system.time(mdl2$solve(control = list(trace = FALSE),
                            force_stacked_time = TRUE))
cat("\ntiming stacked time method\n")
print(t)

#t <- system.time(mdl3$solve(control = list(silent = TRUE, trace = TRUE), solver = "umfpackr"))
#cat("\ntiming backwards\n")
#print(t)
=======
#mdl$set_period("2017Q1/2017Q1")
mdl$set_period("2017Q1/2021Q2")
mdl$set_endo_values(1300, names = "y_nl", period = "2016Q4")

mdl2 <- mdl$clone()

mdl$time_functions()

t <- system.time(mdl$solve(control = list(trace = FALSE),
                 force_stacked_time = FALSE))
cat("timing van oplossen met backwards methode:\n")
print(t)

t <- system.time(mdl2$solve(control = list(trace = TRUE),
                            force_stacked_time = TRUE))
cat("timing van oplossen met stacked time\n")
print(t)
>>>>>>> 0214625935e42e5c6bc5302b47487c44d7ee0bd8
