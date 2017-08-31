library(dynmdl)

param_file <- "input/islm_country_params.csv"
fit_file <- "input/islm_countries_fit.csv"

# read parameters
param_data <- as.matrix(read.csv(param_file, row.names = 1))
param_names <- outer(rownames(param_data), colnames(param_data),
                     FUN = "paste", sep = "_")
params <- as.numeric(param_data)
names(params) <- as.character(param_names)

# read fit targets
fit_targets <- as.regts(read.csv("input/islm_countries_fit.csv", row.names = 1))
print(fit_targets)

mdl <- dyn_mdl("mod/islm_countries.mod", 
                  fit_mod_file = "fmod/islm_countries.fmod")
print(mdl)

mdl$set_params(params)

print(mdl$get_params())

mdl$solve_steady(control = list(trace = TRUE))
mdl$set_period("2017Q1/2022Q4")

mdl$set_fit(fit_targets)
cat("fit targets:\n")
print(mdl$get_fit_targets())

mdl$solve(control = list(trace = TRUE))

print(mdl$get_residuals())

cat("calculated endogenous variables for the fit target variables:\n")
print(mdl$get_endo_data(names = colnames(fit_targets)))

print(mdl$get_endo_data("y_.."))
print(mdl$get_endo_data("tot_.+"))
plot(mdl$get_endo_data(names = c("y_nl", "y_be")), type = "o")
