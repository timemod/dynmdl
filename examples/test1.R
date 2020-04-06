library(dynmdl)
mdl <- dyn_mdl("mod/test1.mod", latex_options = list(par_as_num = TRUE,
                                                    ndigits = 6), calc = "internal")
print(mdl)

print(mdl$get_mdldef())

mdl$solve_steady(control = list(trace = TRUE))
mdl$check()
