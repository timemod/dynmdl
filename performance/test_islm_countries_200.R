library(dynr)
source("create_islm_country_model.R")

param_file <- "input/islm_country_params.csv"
basis_mod_file <- "mod/islm_countries.inp"

# read parameters
param_data <- as.matrix(read.csv(param_file, row.names = 1))
param_names <- outer(rownames(param_data), colnames(param_data),
                     FUN = "paste", sep = "_")
params <- as.numeric(param_data)
names(params) <- as.character(param_names)
    
nextra = 200
mod_file <- paste0("mod/islm_countries_",
                   as.character(nextra), ".mod")
create_islm_country_model(basis_mod_file, mod_file, nextra)
mdl <- compile_model(mod_file, use_dll = TRUE)
mdl$set_period("2017Q1/2021Q2")
mdl$time_functions()
mdl$set_endo_values(1300, names = "y_nl", period = "2016Q4")

t <- system.time(mdl$solve(control = list(trace = TRUE),
              force_stacked_time = force_stacked_time))
print(t)

