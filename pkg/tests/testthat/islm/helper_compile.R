library(utils)
library(dynmdl)
library(testthat)

# create the normal ISLM model
capture_output(islm_model <- islm_mdl("2015Q2/2016Q3"))
islm_model$write_mdl("islm_model.rds")

# create a fit version
islm_labels <- islm_model$get_labels()
fit_mod_file <- "mod/islm_fit.mod"
fit_mdl_period <- period_range("2016Q1/2020Q2")
report <- capture_output(fit_mdl <- dyn_mdl(fit_mod_file))
fit_mdl$set_labels(islm_labels)
fit_mdl$solve_steady()
fit_mdl$set_period(fit_mdl_period)
fit_mdl$write_mdl("islm_model_fit.rds")