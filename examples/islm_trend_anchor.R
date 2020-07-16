library(dynmdl)
rm(list = ls())

period <- period_range("2017Q1", "2022Q4")
fit_target_csv <- "input/islm_fit_targets.csv"

mod_name <- "islm_trend_anchor"
mod_file <- file.path("mod", paste0(mod_name, ".mod"))
fit_mod_file <- file.path("fmod", paste0(mod_name, "_fit.mod"))

mdl <- dyn_mdl(mod_file, fit = TRUE, strict = FALSE, fit_fixed_period = FALSE, debug = TRUE,
               check_static_fit = TRUE)
mdl$set_param(c(sigma_ut = 7, sigma_uc = 5, sigma_ui = 21, sigma_umd = 21))
mdl$set_fit_steady(c(y = 1300, i = 300))
mdl$solve_steady(control = list(trace = TRUE))
mdl$init_data(period)
mdl2 <- mdl$copy()
mdl2$solve()
dif <- tsdif(mdl$get_all_data(), mdl2$get_all_data(), fun = cvgdif, tol = 1e-7)
print(dif) 

quit()

#jac <- mdl$get_static_jacob()
#print(colSums(abs(jac)))

fit_targets <- as.regts(read.csv(fit_target_csv), time_column = 1)
cat("fit targets:\n")
print(fit_targets)

mdl$set_fit(fit_targets)
print(mdl$get_fit())

mdl$solve(control = list(trace = TRUE))
quit()
print(mdl$get_endo_data())
print(mdl$get_exo_data())
print(mdl$get_fit_instruments())
print(mdl$get_lagrange())
print(mdl$get_fit())
plot(mdl$get_endo_data(names = "y", trend = TRUE), type = "o")
