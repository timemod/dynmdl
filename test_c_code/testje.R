# Basic example of the ISLM model with lags

library(dynr)

#mdl <- compile_model("../examples/mod/islm.mod", use_dll = TRUE)
#print(mdl, short = FALSE)

file.copy("c_functions.c", "islm/c_functions.c")

src_dir <- "islm"
r_home <- R.home(component = "bin")
R <- file.path(r_home, "R")
CC <- system("R CMD config CC", intern = TRUE)

# separate compilation of f_static and f_dynamic:
system(paste(CC, "-c -fPIC", file.path(src_dir, "f_static.c"),
             "-o", file.path(src_dir, "f_static.o")))
system(paste(CC, "-c -fPIC", file.path(src_dir, "f_dynamic.c"),
             "-o", file.path(src_dir, "f_dynamic.o")))

source_file <- paste(src_dir, c("c_functions.c", "f_static.c", "f_dynamic.c"),
                     sep = .Platform$file.sep)
cmd <- paste(r_home, .Platform$file.sep,
             "R ", "CMD SHLIB ", paste(shQuote(source_file), collapse = " "),
                                         sep = "")
print(cmd)
system(cmd)

y <- numeric(7)
x <- numeric(2)
params <- numeric(12)
dyn.load("islm/c_functions.so")
ret <-  .Call("f_static_", y, x, params, 7, 2)
print(ret)
