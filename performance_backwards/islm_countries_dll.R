library(dynr)
source("create_islm_country_model.R")

param_file <- "input/islm_country_params.csv"
basis_mod_file <- "mod/islm_back_countries.inp"
nextra_countries <- c(10, 50, 100, 200, 500)

# read parameters
param_data <- as.matrix(read.csv(param_file, row.names = 1))
param_names <- outer(rownames(param_data), colnames(param_data),
                     FUN = "paste", sep = "_")
params <- as.numeric(param_data)
names(params) <- as.character(param_names)

run_series <- function(nextra_countries) {
    times <- character(0)
    nendo <- numeric(0)
    for (nextra in nextra_countries) {
        mod_file <- paste0("mod/islm_back_countries_",
                           as.character(nextra), ".mod")
        create_islm_country_model(basis_mod_file, mod_file, nextra)
        mdl <- compile_model(mod_file, use_dll = TRUE)
        mdl$set_period("2017Q1/2066Q4")
        mdl$set_endo_values(1300, names = "y_nl", period = "2016Q4")

        t <- system.time(mdl$solve(control = list(trace = TRUE)))
        times <- c(times, t["elapsed"])
        nendo <- c(nendo, length(mdl$get_endo_names()))

    }
    return(list(times = times, neq = nendo))
}


time_table <- data.frame(nextra_countries)
    ret <- run_series(nextra_countries)
    time_table[, "time"] <- ret$times
    time_table[, "neq"] <- ret$neq

print(time_table)
