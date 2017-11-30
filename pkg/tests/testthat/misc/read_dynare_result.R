read_dynare_result <- function(model_name, mdl) {
  
  dynare_dir     <- "dynare/output"
  endo_name_file <- file.path(dynare_dir, paste0(model_name, "_endo_names.txt"))
  endo_data_file <- file.path(dynare_dir, paste0(model_name, "_simul_endo.csv"))
  #stoch_endo_data_file <- file.path(dynare_dir, "islm_var1_stoch_endo.csv")
  steady_file <- file.path(dynare_dir, paste0(model_name, "_steady.csv"))
  eigval_file <- file.path(dynare_dir, paste0(model_name, "_eigval.csv"))
  
  endo_names_dynare  <- read.csv(endo_name_file, stringsAsFactors = FALSE,
                                 header = FALSE, sep = "")[[1]]
  endo_data <- t(as.matrix(read.csv(endo_data_file, header = FALSE)))
  data_period <- mdl$get_data_period()
  endo_names <- mdl$get_endo_names()
 
  #
  # endogenous variables: return dynare result for the model period
  #
  model_period <- mdl$get_period()
  max_lead_dynare <- min(mdl$get_max_lead(), 1)
  max_lag_dynare  <- min(mdl$get_max_lag(), 1)
  nper <- nperiod(model_period) + max_lag_dynare + max_lead_dynare
  if (nper != nrow(endo_data)) {
  }
  dyn_period <- period_range(start_period(model_period) - max_lag_dynare,
                             end_period(model_period) + max_lead_dynare)
  endo <- regts(endo_data, period = dyn_period, names = endo_names_dynare)
  endo <- endo[model_period, endo_names]

  steady <- read.csv(steady_file, header = FALSE, sep = "")[[1]]
  names(steady) <- endo_names_dynare
  steady <- steady[mdl$get_endo_names()]
  
  eigval <- read.csv(eigval_file, header = FALSE, sep = ",")
  i <- order(apply(eigval, MARGIN = 1, FUN = function(x) sqrt(sum(x**2))))
  eigval <- eigval[i, ]  
  return(list(steady = steady, endo = endo, eigval = eigval))
}