# this function compiled the c function on directory dll_dir,
# and returns the path of the generated shared library
compile_c_functions <- function(dll_dir) {

    cat("Compiling C functions ...\n")

    dll_ext <- system("R CMD config SHLIB_EXT", intern = TRUE)
    dll_file <- file.path(dll_dir, paste0("mdl_functions", dll_ext))
    unlink(dll_file)

    mdl_function_file <- system.file("c_wrappers", "mdl_functions.c",
                                     package = "dynr")
    triplet_jac_file <- system.file("c_wrappers", "get_triplet_jac_new.cpp",
                                     package = "dynr")

    file.copy(mdl_function_file, file.path(dll_dir, "mdl_functions.c"),
              overwrite = TRUE)
    file.copy(triplet_jac_file, file.path(dll_dir, "get_triplet_jac_new.cpp"),
              overwrite = TRUE)

    r_home <- R.home(component = "bin")
    R <- file.path(r_home, "R")
    CC <- system("R CMD config CC", intern = TRUE)

    cpic_flags  <- system("R CMD config CPICFLAGS", intern = TRUE)
    cflags <- paste("-c", cpic_flags)

    # separate compilation of f_static and f_dynamic (because we do not want
    # to use optimalization)
    system(paste(CC, cflags, file.path(dll_dir, "f_static.c"),
             "-o", file.path(dll_dir, "f_static.o")))
    system(paste(CC, cflags, file.path(dll_dir, "f_dynamic.c"),
             "-o", file.path(dll_dir, "f_dynamic.o")))

    source_file <- paste(dll_dir, c("mdl_functions.c",
                                    "get_triplet_jac_new.cpp",
                                    "f_static.c", "f_dynamic.c"),
                     sep = .Platform$file.sep)
    cmd <- paste(r_home, .Platform$file.sep,
             "R ", "CMD SHLIB ", paste(shQuote(source_file), collapse = " "),
                                         sep = "")
    output <- system(cmd, intern = TRUE)
    cat(output)
    cat("Done\n")

    return(dll_file)
}
