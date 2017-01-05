# Example of the ISLM model combined with the fit procedure employing
# the maximum likelihood method, this time for yearly observation for 
# variable y. The exogenous variable fit_y_year
# determines whether the variable is a fit target at a specific time.
# The endogenous variables ut, ui, uc and umd are the residuals
# of the fit procedure.

library(dynr)

period <- regperiod_range("2017Q1", "2019Q3")

mdl <- compile_model("islm_yearfit.mod")
mdl$solve_steady(control = list(trace = TRUE))
mdl$set_period(period)

mdl$set_fit_targets(regts(1275, start = "2017Q4"), names = "y_year")
mdl$solve(control = list(trace = TRUE))

print(mdl$get_endo_data())
plot(mdl$get_endo_data("y"), type = "o")