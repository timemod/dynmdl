library(dynmdl)

period <- regperiod_range("2017Q1", "2019Q3")
fit_target_csv <- "input/NK_baseline_fit_targets.csv"


mdl <- create_mdl("mod/NK_baseline_fit.mod",
	              fit_mod_file = "fmod/NK_baseline_fit.fmod",
		          bytecode = FALSE)
print(mdl)
mdl$solve_steady(control = list(trace = TRUE))
print(mdl$get_static_endos())
mdl$set_period("2017Q1/2019Q3")
fit_targets <- as.regts(read.csv(fit_target_csv), time_column = 1)
cat("fit targets:\n")
print(fit_targets)

mdl$set_fit_targets(fit_targets)
print(mdl$get_fit_targets())

mdl$solve(control = list(trace = TRUE))
#print(mdl$get_lagrange())
#print(mdl$get_fit_targets())
