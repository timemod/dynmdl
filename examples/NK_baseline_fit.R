library(dynr)

mdl <- compile_model("mod/NK_baseline_fit.mod",
	             fit_mod_file = "fmod/NK_baseline_fit.fmod")
print(mdl)
quit()

mdl$solve_steady(control = list(trace = TRUE))
mdl$set_period("2017Q1/2019Q3")

mdl$solve(control = list(trace = TRUE))

print(mdl$get_endo_data())
