library(dynr)
source("create_islm_country_model.R")

param_file <- "input/islm_country_params.csv"
basis_mod_file <- "mod/islm_countries.inp"
nextra_countries <- c(10, 100, 200)

# read parameters
param_data <- as.matrix(read.csv(param_file, row.names = 1))
param_names <- outer(rownames(param_data), colnames(param_data),
                     FUN = "paste", sep = "_")
params <- as.numeric(param_data)
names(params) <- as.character(param_names)

run_series <- function(nextra_countries, force_stacked_time) {
    times <- character(0)
    for (nextra in nextra_countries) {
        mod_file <- paste0("mod/islm_countries_",
                           as.character(nextra), ".mod")
        create_islm_country_model(basis_mod_file, mod_file, nextra)
        mdl <- compile_model(mod_file)
        mdl$set_period("2017Q1/2021Q2")
        mdl$set_endo_values(1300, names = "y_nl", period = "2016Q4")

        t <- system.time(mdl$solve(control = list(trace = TRUE),
                      force_stacked_time = force_stacked_time))
        times <- c(times, t["sys.self"] + t["user.self"])
    }
    return(times)
}


time_table <- data.frame(nextra_countries)
times <- run_series(nextra_countries, force_stacked_time = force_stacked_time)
time_table[, "cpu time"] <- times

print(time_table)
