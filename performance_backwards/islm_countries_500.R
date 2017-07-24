library(dynmdl)
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
nextra <- 500

mod_file <- paste0("mod/islm_back_countries_",
                   as.character(nextra), ".mod")
create_islm_country_model(basis_mod_file, mod_file, nextra)
mdl <- dyn_mdl(mod_file, use_dll = TRUE)
mdl$set_period("2017Q1/2017Q1")
mdl$set_endo_values(1300, names = "y_nl", period = "2016Q4")

mdl2 <- mdl$clone()
t <- system.time(mdl2$solve(control = list(trace = TRUE),
              solver = "umfpack"))
print(t)

mdl3 <- mdl$clone()
t <- system.time(mdl3$solve(control = list(trace = TRUE),
              solver = "umfpack", force_stacked_time = TRUE))
print(t)
