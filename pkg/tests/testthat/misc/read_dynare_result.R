read_dynare_result <- function(model_name, mdl) {
  
  dynare_dir     <- "dynare/output"
  endo_name_file <- file.path(dynare_dir, paste0(model_name, "_endo_names.txt"))
  exo_name_file <- file.path(dynare_dir, paste0(model_name, "_exo_names.txt"))
  endo_data_file <- file.path(dynare_dir, paste0(model_name, "_simul_endo.csv"))
  exo_data_file <- file.path(dynare_dir, paste0(model_name, "_simul_exo.csv"))
  #stoch_endo_data_file <- file.path(dynare_dir, "islm_var1_stoch_endo.csv")
  steady_file <- file.path(dynare_dir, paste0(model_name, "_steady.csv"))
  eigval_file <- file.path(dynare_dir, paste0(model_name, "_eigval.csv"))
  
  endo_names_dynare  <- read.csv(endo_name_file, stringsAsFactors = FALSE,
                                 header = FALSE, sep = "")[[1]]
  exo_names_dynare <- read.csv(exo_name_file, stringsAsFactors = FALSE,
                               header = FALSE, sep = "")[[1]]
  endo_data <- t(as.matrix(read.csv(endo_data_file, header = FALSE)))
  exo_data <- as.matrix(read.csv(exo_data_file, header = FALSE))
  
  data_period <- mdl$get_data_period()
  endo_names <- mdl$get_endo_names()
  exo_names <- mdl$get_exo_names()
  
  endo <- regts(endo_data, period = data_period, names = endo_names_dynare)
  endo <- endo[ , endo_names]
  
  exo <- regts(exo_data, period = data_period, names = exo_names_dynare)
  exo <- exo[ , exo_names]
  
  steady <- read.csv(steady_file, header = FALSE, sep = "")[[1]]
  names(steady) <- endo_names_dynare
  steady <- steady[mdl$get_endo_names()]
  
  eigval <- read.csv(eigval_file, header = FALSE, sep = ",")
  i <- order(apply(eigval, MARGIN = 1,
                   FUN = function(x) sqrt(sum(x**2))))
  eigval <- eigval[i, ]  
  return(list(steady = steady, endo = endo, exo = exo, eigval = eigval))
}