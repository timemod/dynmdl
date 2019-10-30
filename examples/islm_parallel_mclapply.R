# Parallel example ISLM model, using mclapply.  This does not work on
# Windows, since mclapply relies on forking.

library(dynmdl)
library(parallel)

rm(list = ls())

mdl <- dyn_mdl("mod/islm.mod", calc = "internal")

mdl$solve_steady(control = list(trace = TRUE))
mdl$set_period("2017Q1/2019Q3")

solve_variant <- function(i) {
  var <- mdl$copy()
  outp <- capture.output({
    print(var)
    var$set_exo_values(280 + i, names = "g", period = "2017Q1/2017q4")
    var$solve(control = list(trace = TRUE))
  })
  writeLines(outp, file.path("reports", paste0("report", i, ".txt")))
  return(var$get_exo_data(names= "g")[ , 1])
}

result <- mclapply(1:8, FUN = solve_variant, mc.cores = 8)
names(result) <- paste0("var", 1:8)

result <- do.call(cbind, result)
print(result)
