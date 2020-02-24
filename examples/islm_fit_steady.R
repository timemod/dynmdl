# Basic example of the ISLM model with lags

library(dynmdl)
mdl <- dyn_mdl("mod/islm_fit.mod", latex_options = list(par_as_num = TRUE,
                                                    ndigits = 6), calc = "internal")
print(mdl)

mdl$solve_steady(control = list(trace = TRUE))

print(mdl$get_static_endos())

mdl$set_fit_steady(c(y = 1300, i = 300))
mdl$solve_steady(control = list(trace = TRUE))
print(mdl$get_static_endos())

print(mdl$get_fit_steady())

print(mdl$get_all_static_endos())

mdl$clear_fit()

print(mdl$get_all_static_endos())

mdl$solve_steady()

print(mdl$get_all_static_endos())
