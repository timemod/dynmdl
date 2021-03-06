library(dynmdl)
source("create_islm_country_model.R")

basis_mod_file <- "mod/islm_countries_extfun1.inp"
ncountries <- c(150)

square <<- function(x) {
  return(x * x)
}
square_jac <<- function(x) {
  return(2 * x)
}

multiply <<- function(x, y) {
  return(x * y)
}
multiply_jac <<- function(x, y) {
  return(c(y,  x))
}


run_series <- function(ncountries) {
    user_times    <- numeric(0)
    sys_times     <- numeric(0)
    elapsed_times <- numeric(0)
    nendo <- numeric(0)
    for (nextra in ncountries) {
        mod_file <- paste0("mod/islm_countries_",
                           as.character(nextra), ".mod")
        create_islm_country_model(basis_mod_file, mod_file, nextra)
        mdl <- dyn_mdl(mod_file, use_dll = TRUE)
        mdl$set_period("2017Q1/2066Q4")
        mdl$set_endo_values(1300, names = "y_co_1", period = "2016Q4")

        t <- system.time(mdl$solve(control = list(trace = TRUE)))
        user_times <- c(user_times, t["user.self"])
        sys_times <- c(sys_times, t["sys.self"])
        elapsed_times <- c(elapsed_times, t["elapsed"])
        nendo <- c(nendo, length(mdl$get_endo_names()))
    }
    return(data.frame(neq = nendo, user_times = user_times,
                      sys_times = sys_times, elapsed_times = elapsed_times))
}


ret  <- run_series(ncountries)
time_table <- data.frame(ncountries = ncountries)
time_table <- cbind(time_table, ret)
rownames(time_table) <- NULL
print(time_table)
