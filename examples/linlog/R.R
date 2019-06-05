library(dynmdl)

mod_file <- "linlog.mod"

mdl <- dyn_mdl(mod_file, period = "2018/2024", calc = "R")
mdl$set_param(c(eps2 = -Inf))
mdl$set_exo_values(c(-1, 0, 0.01, 0.5, 1, 2, 3), names = "x", period = "2018/2024")
print(mdl, short = FALSE)
mdl$solve()
print(mdl$get_data())
