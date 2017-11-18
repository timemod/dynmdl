library(dynmdl)

mdl <- dyn_mdl("mod/islm_lag2.mod")

mdl$solve_steady()
print(mdl$get_static_endos())
mdl$check()
mdl$set_period("2018/2022");
mdl$solve()
print(mdl$get_endo_data())
