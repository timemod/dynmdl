library(dynr)

mod_file <- system.file("extdata", "vraag_en_aanbod.mod", package = "dynr")
mdl <- compile_model(mod_file)

# calculate the stready state
mdl <- solve_steady(mdl = mdl)
model_period(mdl) <- regperiod_range("2015", "2016")

print(get_jacob(mdl))

jacfun <- function(y, exos, params, it) {
    return (mdl@f_dynamic(y, exos, params, it, jac = TRUE)[[2]])
}

endos <-c(dynr:::get_lags(mdl), dynr:::get_solve_endo(mdl),
          dynr:::get_leads(mdl))
exos <- dynr:::get_exo(mdl)

mat_info <- dynr:::get_triplet_jac_(mdl, endos, exos, jacfun)
n <- lensub(mdl@model_period) * mdl@endo_count
mat <- new("dgTMatrix", i = mat_info$rows, j = mat_info$columns,
           x = mat_info$values, Dim = as.integer(rep(n, 2)))
print(mat)
