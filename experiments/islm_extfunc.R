# Basic example of the ISLM model with lags

library(dynmdl)

mdl <- dyn_mdl("mod/islm_extfunc.mod", calc = "dll", dll_dir = "aap")
