# Example of the ISLM model combined with the fit procedure employing
# the maximum likelihood method. All endogenous variables of the original ISLM model
# can be fit targets.
# The exogenous variable fit_X (X is the name of the endogenous variables) 
# determine whether the variable is a fit target at a specific time. \
# The endogenous variables ut, ui, uc and umd are the residuals
# of the fit procedure.

library(dynmdl)

period <- period_range("2017Q1", "2022Q4")
fit_target_csv <- "input/islm_fit_targets.csv"

mdl <- dyn_mdl("mod/islm_fit.mod", 
               fit_mod_file = "fmod/islm_fit_fixed_time.fmod", 
               calc = "internal", fit_fixed_time = TRUE)
print(mdl)

mdl$set_param(c(sigma_ut = 7, sigma_uc = 5, sigma_ui = 21, sigma_umd = 21))

mdl$solve_steady(control = list(trace = TRUE))

mdl$set_period(period)

fit_targets <- as.regts(read.csv(fit_target_csv), time_column = 1)
cat("fit targets:\n")
print(fit_targets)

mdl$set_fit(fit_targets)
print(mdl$get_fit())

mdl$solve(control = list(trace = TRUE))
print(mdl$get_endo_data())
print(mdl$get_exo_data())
print(mdl$get_fit_instruments())
print(mdl$get_lagrange())
print(mdl$get_fit())
plot(mdl$get_endo_data("y"), type = "o")
