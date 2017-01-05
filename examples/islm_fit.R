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
print(mdl)
mdl$solve_steady(control = list(trace = TRUE))

mdl$set_period(period)

fit_targets <- as.regts(read.csv(fit_target_csv), time_column = 1)
cat("fit targets:\n")
print(fit_targets)

mdl$set_fit_targets(fit_targets)
print(mdl$get_fit_targets())


mdl$solve(control = list(trace = TRUE))
print(mdl$get_endo_data())
print(mdl$get_exo_data())
print(mdl$get_residuals())
print(mdl$get_lagrange())
print(mdl$get_fit_targets())
plot(mdl$get_endo_data("y"), type = "o")