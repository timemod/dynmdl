library(dynr)
library(gsubfn)

dynr:::create_fitmod("islm_fit_inp.mod", "islm_fit.mod")

# mdl <- compile_model("islm.mod")
# print(mdl, short = FALSE)
#
#
# mdl$solve_steady(control = list(trace = TRUE))
# mdl$set_period("2017Q1/20219Q3")
# mdl$set_endo_values(1200, names = "y", period = "2016Q4")
# mdl$set_endo_values(1000, names = "yd", period = "2016Q4")
# mdl$set_exo_values(280, names = "g", period = "2017Q1")
# mdl2$solve(control = list(trace = TRUE))
#
# pattern <- "\\[(-?\\d+)\\]"
# f <- function(x) {
#     print(x)
#     return (paste0("(", as.integer(x) + 2, ")"))
# }
# ret <- gsubfn(pattern, f, "x[2] + zz[-2]")
# print(ret)
