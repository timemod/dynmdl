library(dynr)

mod_file <- system.file("extdata", "vraag_en_aanbod.mod", package = "dynr")

mdl <- compile_model(mod_file)

# calculate the stready state
mdl$solve_steady()
print(mdl$endos)

mdl$set_period("2015/2030")
mdl$set_period("2015/2016")

mdl$endo_data[start_period(mdl$endo_period), "p"] <- 1.3


View(mdl$get_jacob(sparse = FALSE))

print(system.time(
    mdl$solve(control = list(trace = TRUE))
))

print(mdl$solve_out$solved)
print(mdl$solve_out$iter)

plot(mdl$endo_data[, "p"])
