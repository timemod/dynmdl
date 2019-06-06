library(dynmdl)

mod_file <- "linlogpow.mod"

x <- seq(0, 4, length.out = 100)[-1]
plot(x, log(x), type = "l")
lines(x,  ( x - 1), type = "l", col = "red")

mdl <- dyn_mdl(mod_file, period = "2018/2018", calc = "R")
print(mdl, short = FALSE)
#mdl$solve(control = list(allow_singular = TRUE, trace = TRUE), solver = "nleqslv")
mdl$solve_steady(control = list(allow_singular = TRUE, trace = TRUE))

mdl$solve_steady(control = list(allowSingular = TRUE, trace = TRUE), solver = "nleqslv")
print(mdl$get_data())
