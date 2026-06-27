# this function compiled the c functions
# in directory dll_dir and returns the
# path name of the generated dll file
compile_c_functions <- function(dll_dir, silent) {
  if (!silent) cat("Compiling C functions ...\n")

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
  R_cmd <- file.path(R_home, "R", fsep = .Platform$file.sep)

  dll_ext <- system(paste(R_cmd, "CMD config SHLIB_EXT"), intern = TRUE)
  dll_file <- file.path(dll_dir, paste0("mdl_functions", dll_ext))

  c_wrappers_dir <- system.file("c_wrappers", package = "dynmdl")
  c_wrapper_files <- dir(path = c_wrappers_dir, full.names = TRUE)

  ok <- file.copy(c_wrapper_files, dll_dir)
  if (any(!ok)) {
    stop("Internal error in compile_c_functions: could not copy c wrapper files")
  }

  CC <- system(paste(R_cmd, "CMD config CC"), intern = TRUE)
  cpic_flags <- system(paste(R_cmd, "CMD config CPICFLAGS"), intern = TRUE)
  cflags <- paste("-c", cpic_flags)

  # separate compilation of f_static and f_dynamic (because we do not want
  # to use optimalization)
  function_src <- file.path(dll_dir, c("f_static.c", "f_dynamic.c"),
    fsep = .Platform$file.sep
  )
  
  debug <- identical(getOption("dynmdl.dll_debug_mode"), TRUE)

  for (src in function_src) {
    obj <- gsub("\\.c$", ".o", src)
    cmd <- paste(CC, cflags, src,  "-o", obj)
    if (debug) cat("Running commmand '", cmd, "'\n", sep = "")
    system(cmd)
  }
  
  if (!debug) {
    on.exit(
      # remove object files
      unlink(file.path(dll_dir, "*.o"))
    )
  }
  
  c_wrapper_files <- file.path(
    dll_dir, 
    basename(c_wrapper_files),
    fsep = .Platform$file.sep
  )
  c_wrapper_files <- grep("\\.c$", c_wrapper_files, value = TRUE)
  src_files <- c(c_wrapper_files, function_src)

  cmd <- paste(
    R_cmd, "CMD SHLIB -o", dll_file,
    paste(shQuote(src_files), collapse = " ")
  )

  # Always ignore standard output (which always gives a lot of output), but
  # only ignore standard error if silent = TRUE.
  if (debug) if (debug) cat("Running commmand '", cmd, "'\n", sep = "")
  system(cmd, ignore.stdout = !debug , ignore.stderr = silent)
  
  return(dll_file)
}
