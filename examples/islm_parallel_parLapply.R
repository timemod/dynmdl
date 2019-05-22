# Parallel example ISLM model, using parLapply. Works on both Windows
# and Linux.

library(dynmdl)
library(parallel)

rm(list = ls())

mdl <- dyn_mdl("mod/islm.mod", calc = "internal")
#print(mdl, short = FALSE)

mdl$solve_steady(control = list(trace = TRUE))
mdl$set_period("2017Q1/2019Q3")

set.seed(123)

mdl$write_mdl("tmp.rds")

solve_variant <- function(i) {
  outp <- capture.output({
    var <- read_mdl("tmp.rds")
    var$set_exo_values(280 + i, names = "g", period = "2017Q1/2017q4")
    var$solve(control = list(trace = TRUE))
  })
  writeLines(outp, file.path("reports", paste0("report", i, ".txt")))
  return(var$get_exo_data(names= "g")[ , 1])
}

#result <- mclapply(1:8, FUN = solve_variant, mc.cores = 8)
cl <- makeCluster(mc <- 8)
clusterEvalQ(cl, library(regts))
clusterEvalQ(cl, library(dynmdl))
clusterExport(cl, c("solve_variant"))
result <- parLapply(cl, 1:8, fun = solve_variant)
stopCluster(cl)
names(result) <- paste0("var", 1:8)
result <- do.call(cbind, result)
print(result)
#plot(result)
