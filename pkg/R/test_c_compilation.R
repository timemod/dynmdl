# test compiling and running C-code, for internal usage only


test_c_compilation <- function(dll_dir, x) {
  
  if (dir.exists(dll_dir)) {
    unlink(dll_dir, recursive = TRUE)
  }
  
  dir.create(dll_dir)
  
  dll_ext <- system("R CMD config SHLIB_EXT", intern = TRUE)
  dll_file <- file.path(dll_dir, paste0("mdl_functions", dll_ext))
  
  mdl_function_file <- system.file("c_example_code", "mdl_functions.c",
                                   package = "dynmdl")
  r_function_file <- system.file("c_example_code", "call_R_function.c",
                                   package = "dynmdl")
  r_function_header <- system.file("c_example_code", "call_R_function.h",
                                 package = "dynmdl")
  c_file <- system.file("c_example_code", "f_static.c",  package = "dynmdl")
  
  ok <- file.copy(c_file, file.path(dll_dir, "f_static.c"), overwrite = TRUE)
  ok <- file.copy(mdl_function_file, file.path(dll_dir, "mdl_functions.c"), 
                  overwrite = TRUE)
  ok <- file.copy(r_function_file, file.path(dll_dir, "call_R_function.c"), 
                  overwrite = TRUE)
  ok <- file.copy(r_function_header, file.path(dll_dir, "call_R_function.h"), 
                  overwrite = TRUE)

  
  r_home <- R.home(component = "bin")
  R <- file.path(r_home, "R")
  CC <- system("R CMD config CC", intern = TRUE)
  
  cpic_flags  <- system("R CMD config CPICFLAGS", intern = TRUE)
  
  cpp_flags  <- system("R CMD config --cppflags", intern = TRUE)
  cflags <- paste("-c", cpic_flags, cpp_flags)
  
  # separate compilation of f_static and f_dynamic (because we do not want
  # to use optimalization)
  system(paste(CC, cflags, file.path(dll_dir, "f_static.c"),
               "-o", file.path(dll_dir, "f_static.o")))
  
  
  source_file <- paste(dll_dir, c("mdl_functions.c", "call_R_function.c",
                                  "f_static.c"), 
                                  sep = .Platform$file.sep)
  cmd <- paste(r_home, .Platform$file.sep,
               "R ", "CMD SHLIB ", paste(shQuote(source_file), collapse = " "),
               sep = "")
  output <- system(cmd, intern = TRUE)
  cat(output)
  
  
  dyn.load(dll_file)
  
  .Call("f_static_", x, PACKAGE = "mdl_functions")
  
  dyn.unload(dll_file)
  return(invisible(NULL))
  
}