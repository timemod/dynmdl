# Arguguments:
# endo_data  endo data as stored in the dynmdl object
# solve_period
# data_period
# maxlag    maximum lag endogenous variables
# maxlead   maximum lead endogenous variables 
endo_data_solve <- function(endo_data, solve_period, maxlag, maxlead) {
  
  solve_data_period <-  period_range(start_period(solve_period) - maxlag,
                                     end_period(solve_period)   + maxlead)
  
  data_mat <- t(endo_data[solve_data_period])
  
  nper_cur <- nperiod(solve_period)
  
  has_lags <- maxlag > 0
  has_leads <- maxlead > 0
  
  if (has_lags) {
    lag_cols <- seq(1, maxlag)
  } else {
    lag_cols <- numeric(0)
  }
  
  if (has_leads) {
    lead_cols <- seq(maxlag + nper_cur + 1, nper_cur + maxlag + maxlead )
  } else {
    lead_cols <- numeric(0)
  }
  
  cur_cols <- seq(maxlag + 1, maxlag + nper_cur)
  
  ret <- list(mat = data_mat, has_lags = has_lags, has_leads = has_leads,
              lag_cols = lag_cols, lead_cols = lead_cols, 
              cur_cols = cur_cols, nper_cur = nper_cur)
  
  return(structure(ret, class = "endo_data_solve"))
}

cur_endos <- function(x) {
  return(x$mat[ , x$cur_cols, drop = FALSE]) 
}

`cur_endos<-` <- function(x, value) {
  x$mat[ , x$cur_cols] <- value
  return(x)
}

lag_endos <- function(x) {
  return(x$mat[ , x$lag_cols, drop = FALSE]) 
}

`lag_endos<-` <- function(x, value) {
  x$mat[ , x$lag_cols] <- value
  return(x)
}

lead_endos <- function(x) {
  return(x$mat[ , x$lead_cols, drop = FALSE]) 
}

`lead_endos<-` <- function(x, value) {
  x$mat[ , x$lead_cols] <- value
  return(x)
}
