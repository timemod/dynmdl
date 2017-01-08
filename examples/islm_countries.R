library(dynr)

param_file <- "islm_country_params.csv"
fit_file <- "islm_countries_fit.csv"
output_file <- "islm_countries_result.csv"

# read parameters
param_data <- as.matrix(read.csv(param_file, row.names = 1))
param_names <- outer(rownames(param_data), colnames(param_data),
                     FUN = "paste", sep = "_")
params <- as.numeric(param_data)
names(params) <- as.character(param_names)

# read fit targets
fit_targets <- as.regts(read.csv("islm_countries_fit.csv", row.names = 1))

mdl <- compile_model("islm_countries.mod", fit_mod_file = "islm_countries.fmod")
print(mdl)

mdl$set_params(params)

print(mdl$get_params())

mdl$solve_steady(control = list(trace = TRUE))
mdl$set_period("2017Q1/2019Q3")

mdl$set_fit_targets(fit_targets)
cat("fit targets:\n")
print(mdl$get_fit_targets())

mdl$solve(control = list(trace = TRUE))

print(mdl$get_residuals())

cat("calculated endogenous variables for the fit target variables:\n")
print(mdl$get_endo_data(names = colnames(fit_targets)))

print(mdl$get_endo_data("y_.."))
plot(mdl$get_endo_data(names = c("y_nl", "y_be")), type = "o")

write.csv(as.data.frame(mdl$get_endo_data()), file = output_file)
