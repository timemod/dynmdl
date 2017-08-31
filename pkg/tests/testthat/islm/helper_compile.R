library(utils)
library(dynmdl)
library(testthat)

# create the normal ISLM model
capture_output(islm_model <- islm_mdl("2015Q2/2016Q3"))
capture_output(islm_model$write_mdl("islm_model.rds"))

# create a fit version
capture_output(fit_model <- islm_mdl("2016Q1/2020Q2", fit = TRUE))
capture_output(fit_model$write_mdl("islm_model_fit.rds"))