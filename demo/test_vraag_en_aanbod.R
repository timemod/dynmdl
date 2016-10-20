library(dynparse)

mod_file <- system.file("extdata", "vraag_en_aanbod.mod", package = "dynparse")

mdl <- compile_model(mod_file)

# calculate the stready state
mdl <- solve_steady(mdl = mdl)
print(mdl@endos)

model_period(mdl) <- regperiod_range("2015", "2030")

mdl@endo_data[start_period(mdl@endo_period), "p"] <- 1.3


#View(get_jacob(mdl, sparse = FALSE))

print(system.time(
    mdl2 <- solve_model(mdl, control = list(trace = TRUE))
))

print(mdl2@solve_out$solved)
print(mdl2@solve_out$iter)

plot(mdl2@endo_data[, "p"])
