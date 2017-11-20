library(dynmdl)

#print(check_mdl("mod/islm_lag2.mod"))
print(check_mdl("mod/islm_lag2.mod", endos = c(yd=2000), exos = c(g = 240)))
