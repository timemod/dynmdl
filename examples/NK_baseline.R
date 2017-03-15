library(dynmdl)

mdl <- create_mdl("mod/NK_baseline.mod", bytecode = FALSE)

mdl$solve_steady(control = list(trace = TRUE))
mdl$set_period("2017Q1/2019Q3")

mdl$solve(control = list(trace = TRUE))

print(mdl$get_endo_data())
