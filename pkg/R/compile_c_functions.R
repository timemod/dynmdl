compile_c_functions <- function(dll_dir) {

    cat("Compiling C functions ...\n")

    mdl_function_file <- system.file("c_wrappers", "mdl_functions.c",
                                     package = "dynr")
    printobj(mdl_function_file)

    file.copy(mdl_function_file, file.path(dll_dir, "mdl_functions.c"),
              overwrite = TRUE)

    r_home <- R.home(component = "bin")
    R <- file.path(r_home, "R")
    CC <- system("R CMD config CC", intern = TRUE)

    # separate compilation of f_static and f_dynamic (because we do not want
    # to use optimalization)
    system(paste(CC, "-c -fPIC", file.path(dll_dir, "f_static.c"),
             "-o", file.path(dll_dir, "f_static.o")))
    system(paste(CC, "-c -fPIC", file.path(dll_dir, "f_dynamic.c"),
             "-o", file.path(dll_dir, "f_dynamic.o")))

    source_file <- paste(dll_dir, c("mdl_functions.c", "f_static.c",
                                     "f_dynamic.c"),
                     sep = .Platform$file.sep)
    cmd <- paste(r_home, .Platform$file.sep,
             "R ", "CMD SHLIB ", paste(shQuote(source_file), collapse = " "),
                                         sep = "")
    output <- system(cmd, intern = TRUE)
    cat(output)
    cat("Done\n")

    dyn.load(file.path(dll_dir, "mdl_functions.so"))
}
