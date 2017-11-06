library(dynmdl)
library(nlmrt)

mod_file <- "mod/islm_back.mod"

mdl <- dyn_mdl(mod_file)
print(mdl)

# prepare model
mdl$solve_steady()
mdl$set_period("2017q1/2017q4")
mdl$set_exo_values(280, names = "g", period = "2017Q1")
mdl$solve()


# read technical information about the model from an rds file
model_info <- readRDS("model_info.rds")

#cat(model_info$dynamic_model$dynamic_functions[1])
max_endo_lag <- model_info$dynamic_model$max_endo_lag
lead_lag_incidence <- model_info$dynamic_model$lead_lag_incidence

# create equations list
eqs <- vector("list", 8)
eqs[[1]] <- quote(y[3] - (y[6]+y[7]+x[it_, 1]))
eqs[[2]] <- quote(y[4] - (y[3]-y[5]))
eqs[[3]] <- quote(y[5] - (params[16]+y[3]*params[17]))
eqs[[4]] <-  quote(y[10] - (params[1]+params[2]*y[2]+y[4]*params[3]))
eqs[[5]] <- quote(y[6] - (y[10]+params[4]*y[9]+params[5]*t39))
eqs[[6]] <- quote(y[7] - (params[6]+params[7]*y[1]+y[3]*params[8]+
                         params[9]*y[11]+y[9]*params[10]+t39*params[11]))
eqs[[7]] <- quote(y[8] - (params[12]+y[3]*params[13]+y[9]*params[14]+t39*params[15]))
eqs[[8]] <- quote(y[8] - (x[it_, 2]))

eval_equation <- function(y, x, params, it_, eqs, ieq) {
  t39 <- y[9]**2
  return(eval(eqs[[ieq]]))
}

estimate <- function(mdl, par_names, ieqs) {
  per <- mdl$get_period()
  nper <- nperiod(per)
  
  period_shift <- mdl$get_max_lag()
  
  endo_data <- mdl$get_endo_data()
  t_endo_data <- t(endo_data)
  exo <- mdl$get_exo_data()
  
  max_endo_lag <- 1 
  nendo <- nrow(t_endo_data)
  lag_indices <- which(lead_lag_incidence[, 1 : max_endo_lag] != 0) + 
                  (period_shift - max_endo_lag) * nendo
  
  params <- mdl$get_param()
  # todo: also handle models with leads, for the time being iugnore leads
  
  start_per <- start_period(per)
  
  get_residues <- function(par) {
  
    params[names(par)] <- par
    
    residuals <- matrix(NA, nrow = nper, ncol = length(ieqs))
    for (iper in seq_len(nper)) {
      lags <- t_endo_data[lag_indices + (iper - 1) * nendo]
      cur_indices <- (1:nendo) + (iper - 1 + period_shift) * nendo
      cur <- t_endo_data[cur_indices]
      y <- c(lags, cur)
      residuals[iper, ] <- eval_equation(y, x, params, iper + period_shift, 
                                         eqs, ieqs) 
    }
    return(residuals)
  }
  
  start_param <- mdl$get_param(names = par_names)
  ret <- nlfb(start_param, resfn = get_residues)
  return(ret)
}

set.seed(123)
per <- mdl$get_period()
mdl$change_endo_data(names = "y", 
                       fun = function(x) (x + 0.01 * rnorm(nperiod(per))), 
                     period = per)
mdl$set_param(c(t0 = -17, t1 = 0.25))

ret <- estimate(mdl, par_names = c("t0", "t1"), ieqs = 3)
print(ret)