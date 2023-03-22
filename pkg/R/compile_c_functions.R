# this function compiled the c functions
# in directory dll_dir and returns the 
# path name of the generated dll file
compile_c_functions <- function(dll_dir) {
  
  cat("Compiling C functions ...\n")
  
  if (.Platform$OS.type == "windows") {
    # this fix needed for to prevent messages 
    # "CMD.EXE was started with the above path as the current directory.
    # UNC paths are not supported.  Defaulting to Windows directory."
    cpb_file_pattern <- "^\\\\\\\\cpb-dfs-.+/myshares"
    wd <- getwd()
    if (grepl(cpb_file_pattern, wd)) {
      wd <- sub(cpb_file_pattern, "m:", wd)
      setwd(wd)
    }
  }

  R_home <- R.home(component = "bin")
  R_cmd <- file.path(R_home, "R", fsep =  .Platform$file.sep)
  
  dll_ext <- system(paste(R_cmd, "CMD config SHLIB_EXT"), intern = TRUE)
  dll_file <- file.path(dll_dir, paste0("mdl_functions", dll_ext))
  
  c_wrappers_dir <- system.file("c_wrappers", package = "dynmdl")
  c_wrapper_files <- dir(path = c_wrappers_dir, full.names = TRUE)
  
  ok <- file.copy(c_wrapper_files, dll_dir)
  if (any(!ok)) {
    stop("Internal error in compile_c_functions: could not copy c wrapper files")
  }

  CC <- system(paste(R_cmd, "CMD config CC"), intern = TRUE)
  
  cpic_flags  <- system(paste(R_cmd, "CMD config CPICFLAGS"), intern = TRUE)
  cflags <- paste("-c", cpic_flags)

  # separate compilation of f_static and f_dynamic (because we do not want
  # to use optimalization)
  function_src <- file.path(dll_dir, c( "f_static.c", "f_dynamic.c"), 
                            fsep = .Platform$file.sep)
  function_obj <- gsub("\\.c$", ".o", function_src)
  
  
  for (i in seq_along(function_src)) {
    system(paste(CC, cflags, function_src[i], "-o", function_obj[i]))
  }

  c_wrapper_files <- file.path(dll_dir, basename(c_wrapper_files),  
                               fsep = .Platform$file.sep)
  src_files <- c(c_wrapper_files, function_src)
  
  cmd <- paste(R_cmd, "CMD SHLIB -o", dll_file, 
               paste(shQuote(src_files), collapse = " "))
  output <- system(cmd, intern = TRUE)
  
  # remove object files
  unlink(file.path(dll_dir, "*.o*"))
  
  return(dll_file)
}
