library(dynparse)

mod_dir <- system.file("extdata", package = "dynparse")
mod_file = file.path(mod_dir, "islm.mod")

mdl <- compile_model(mod_file)

print(mdl@endos)

system.time(
    mdl <- solve_steady(mdl = mdl)
)
print(mdl@endos)

model_period(mdl) <- regperiod_range("2010Q1", "2011Q4")

# shock for variable g in first solve perod
mdl@exo_data['2010Q1', 'g'] <- 280

print(system.time(
    mdl2 <- solve_model(mdl, solver = "nleqslv")
))

print(mdl2@solve_out$message)
print(mdl2@solve_out$iter)

plot(mdl2@endo_data[, 'y'])
