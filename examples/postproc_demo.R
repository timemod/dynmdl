library(dynmdl)

mdl <- dyn_mdl("mod/postproc_demo.mod", strict = FALSE)
print(mdl)

dynmdl:::run_macro("mod/postproc_demo.mod", "mod/postproc_demo_preprocessed.mod")
