library(dynmdl)

mdl <- dyn_mdl("mod/islm_back.mod")
print(mdl)

mdl$solve_steady(control = list(trace = TRUE))
mdl$set_period("2017Q1/2017Q3")

# set lags
mdl$set_endo_values(c(1300, 1310), names = "y", period = "2016Q3/2016Q4")
mdl$set_endo_values(c(1100, 1110), names = "yd", period = "2016Q3/2016Q4")

print(mdl$get_endo_data(names = c("y", "yd")))
mdl$solve(backrep = "total")
