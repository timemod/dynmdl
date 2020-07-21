# Basic example of the ISLM model with lags

library(dynmdl)
mdl <- dyn_mdl("mod/islm_fit.mod", latex_options = list(par_as_num = TRUE,
                                                    ndigits = 6), 
               fit_fixed_period = TRUE, calc = "internal",
               debug = TRUE)
print(mdl)

mdl$solve_steady(control = list(trace = TRUE))

print(mdl$get_static_endos())

mdl$set_fit_steady(c(y = 1300, i = 300))
mdl$solve_steady(control = list(trace = TRUE))
print(mdl$get_static_endos())

print(mdl$get_fit_steady())

print(mdl$get_all_static_endos())

mdl$init_data(data_period = "2017/2020")
print(mdl$get_all_endo_data())
mdl$solve()

quit()
mdl$clear_fit()

print(mdl$get_all_static_endos())

mdl$solve_steady()

print(mdl$get_all_static_endos())
