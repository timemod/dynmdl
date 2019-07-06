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

mdl <- dyn_mdl("mod/islm_fit.mod", calc = "internal", fit_fixed_time = TRUE)
print(mdl)

mdl$set_param(c(sigma_ut = 7, sigma_uc = 5, sigma_ui = -1, sigma_umd = -1))

mdl$solve_steady(control = list(trace = TRUE))

mdl$set_period(period)

fit_targets <- as.regts(read.csv(fit_target_csv), time_column = 1)["2017q1/2017q2"]
cat("fit targets:\n")
print(fit_targets)

mdl$set_fit(fit_targets)
print(mdl$get_fit())

mdl$solve(control = list(trace = TRUE))

inst1 <- mdl$get_fit_instruments()

mdl$set_param(c(sigma_ut = 2, sigma_uc = 3))

mdl$solve(control = list(trace = TRUE))

inst2 <- mdl$get_fit_instruments()

# results do not depend on the sigmas
tsdif(inst1, inst2, fun = cvgdif, tol = 1e-7)      


