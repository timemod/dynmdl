#
# Create a basic model from the mod file with name model_name + ".mod".
#
# PARAMETERS
#   model_name the name of the model (excluding extension .mod)
#   ...        arguments passed to function dyn_mdl
#
make_mdl <- function(model_name, ..., show_report = FALSE) {
  mod_file <- file.path("mod", paste0(model_name, ".mod"))
  p1 <- period("2011Q3")
  nperiods <- 18
  model_period <- period_range(p1, p1 + nperiods - 1)
  report <- capture_output({
    mdl <- dyn_mdl(mod_file, period = model_period, ...)
    mdl$solve_steady(control = list(silent = TRUE))
    mdl$put_static_endos()
  })
  if (show_report) {
    cat(report)
  }
  mdl$set_period(model_period)
  return(mdl)
} 

#
# This functies performs a simulation for the ISLM model as in Dynare mode file 
# islm_simul.mod.
#
simul_islm <- function(mdl) {
  mdl <- mdl$clone()
  p1 <- start_period(mdl$get_period())
  mdl$set_exo_values(c(245, 250, 260), names = "g", 
                      period = period_range(p1, p1 + 2))
  mdl$set_endo_values(1200, names = "y", period = mdl$get_lag_period())
  mdl$set_endo_values(1210.381827, names = "y", 
                       period = mdl$get_lead_period())
  mdl$solve(control = list(silent = TRUE))
  return(mdl)
}
