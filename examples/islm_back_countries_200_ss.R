library(dynmdl)

param_file <- "input/islm_country_params.csv"

# read parameters
param_data <- as.matrix(read.csv(param_file, row.names = 1))
param_names <- outer(rownames(param_data), colnames(param_data),
                     FUN = "paste", sep = "_")
params <- as.numeric(param_data)
names(params) <- as.character(param_names)

mdl <- create_mdl("mod/islm_back_countries_200.mod", use_dll = TRUE)
print(mdl)

mdl$set_params(params)

print(system.time(
    mdl$solve_steady(control = list(trace = TRUE))
))

mdl$set_period("2017Q1/2022Q4")

# set lags
mdl$set_endo_values(1300, names = "y_nl", period = "2016Q4")
mdl$set_endo_values(1100, names = "yd_nl", period = "2016Q4")

print(system.time(
    mdl$solve(control = list(trace = TRUE), force_stacked_time = TRUE)
))

#mdl$solve(control = list(trace = TRUE), force_stacked_time = TRUE)
#plot(mdl$get_endo_data(names = c("y_nl", "y_be")), type = "o")
