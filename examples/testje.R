# Basic example of the ISLM model with lags

library(dynmdl)

mdl <- dyn_mdl("mod/islm.mod", "2010Q2/2011Q4", use_dll = TRUE)
x <- mdl$serialize()
mdl$residual_check()

mdl_new = DynMdl$new()
mdl_new$deserialize(x)
print(mdl_new, short = FALSE)

mdl_new$residual_check()
