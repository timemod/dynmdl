library(dynmdl)

#print(check_mdl("mod/islm_lag2.mod"))
mdl <- dyn_mdl("mod/islm_lag2.mod", max_laglead_1 = TRUE)
print(mdl)
mdl$set_static_endos(c(yd=2000))
mdl$check()
print(mdl$get_static_endos())

mdl$set_period("2010Q1/2011Q2")

#mdl$set_endo_values(NA, names = "yd_lead_1")
mdl$set_endo_values(1:12, names = "yd")

print(mdl$get_endo_data())

mdl$solve()

print(mdl$get_endo_data())




