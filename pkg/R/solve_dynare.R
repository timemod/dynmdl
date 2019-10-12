#' @importFrom tools file_path_sans_ext
#' @export
solve_dynare <- function(mod_file, period, data, scratch_dir, use_octave = FALSE, 
                         dynare_path) {
  
  period <- as.period_range(period)
  model_name <- file_path_sans_ext(basename(mod_file))
  #
  # create scratch directory
  #
  if (dir.exists(scratch_dir)) {
    if (unlink(scratch_dir, recursive = TRUE, force = TRUE)  == 1) {
      stop(sprintf("Not possible to delete directory %s.", scratch_dir))
    }
  }
  dir.create(scratch_dir)
  
  return(run_dynare(model_name, mod_file, period = period, data = data, 
                    scratch_dir = scratch_dir, 
                    use_octave = use_octave, dynare_path = dynare_path))
}