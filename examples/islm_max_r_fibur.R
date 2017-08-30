# Basic example of the ISLM model with lags

library(dynmdl)

fibur <- function(x, y) {
  return(sqrt(x^2 + y^2) - x - y)
}

fibur_jac <- function(x, y) {
  r <- sqrt(x^2 + y^2)
  return(c(x/r - 1, y/r - 1))
}

mdl <- dyn_mdl("mod/islm_max_r_fibur.mod")
#print(mdl, short = FALSE)

mdl$solve_steady(control = list(trace = TRUE))
mdl$set_period("2017Q1/2019Q3")

# set lags 
mdl$set_endo_values(1240, names = "y", period = "2016Q4")
mdl$set_endo_values(1000, names = "yd", period = "2016Q4")

#  set exogenous variables
mdl$set_exo_values(280, names = "g", period = "2017Q1")
mdl$solve(control = list(trace = TRUE))

print(mdl$get_endo_data())
plot(mdl$get_endo_data(names = "r"), type = "o")
