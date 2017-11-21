library(dynmdl)

#print(check_mdl("mod/islm_lag2.mod"))
mdl <- dyn_mdl("mod/islm_lag2.mod", max_laglead_1 = TRUE)
mdl$set_static_endos(c(yd=2000))
mdl$check()

mdl$set_period("2010Q1/2011Q2")

mdl$solve()
print(mdl$get_endo_data())
