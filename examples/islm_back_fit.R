library(dynmdl)

mdl <- dyn_mdl("mod/islm_back_fit.mod")
print(mdl)

mdl$solve_steady(control = list(trace = TRUE))
mdl$set_period("2017Q1/2050q4")

# set lags
mdl$set_endo_values(c(1300, 1310), names = "y", period = "2016Q3/2016Q4")
mdl$set_endo_values(c(1100, 1110), names = "yd", period = "2016Q3/2016Q4")
mdl$set_fit_values(1500, names = "y", period = "2017q1/2018q4")
print(mdl$get_endo_data(names = c("y", "yd")))
mdl$solve(control = list(trace = TRUE))

plot(mdl$get_endo_data(names = "y"))

print(mdl$get_static_endos(), digits = 8)
print(mdl$get_endo_data(period = "2050q4/2051q1"), digits = 8)