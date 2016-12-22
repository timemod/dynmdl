# Example of the ISLM model combined with the fit procedure employing
# the maximum likelihood method. All endogenous variables of the original ISLM model
# can be fit targets.
# The exogenous variable fit_X (X is the name of the endogenous variables) 
# determine whether the variable is a fit target at a specific time. \
# The endogenous variables ut, ui, uc and umd are the residuals
# of the fit procedure.

library(dynr)

period <- regperiod_range("2017Q1", "2019Q3")
fit_target_csv <- "islm_fit_targets.csv"

mdl <- compile_model("islm_fit.mod")
mdl$solve_steady(control = list(trace = TRUE))

mdl$set_period(period)

endo_data <- as.regts(read.csv(fit_target_csv), time_column = 1)
cat("fit targets:\n")
print(endo_data)
mdl$set_endo_data(endo_data, update_mode = "updval")

fit_exo_names <- paste(colnames(endo_data), "exo", sep = "_")
mdl$set_exo_data(endo_data, names = fit_exo_names, update_mode = "updval")

fit_vars <- endo_data
fit_vars[] <- ifelse(is.na(fit_vars), 0, 1)
colnames(fit_vars) <- paste("fit", colnames(endo_data), sep = "_")
mdl$set_exo_data(fit_vars)

mdl$solve(control = list(trace = TRUE))
print(mdl$get_endo_data())
plot(mdl$get_endo_data("y"), type = "o")
