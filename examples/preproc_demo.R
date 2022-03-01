library(dynmdl)

mdl <- dyn_mdl("mod/preproc_demo.mod", strict = FALSE)
print(mdl)

dynmdl:::run_macro("mod/preproc_demo.mod", "mod/preproc_demo_preprocessed.mod")
