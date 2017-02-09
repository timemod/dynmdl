library(isismdl)

ret <- compile_mdl("islm_back_countries_500.mdl")
mdl <- read_mdl("islm_back_countries_500.mif")
print(mdl)

mdl$set_period("2017Q1/2066Q4")

g_data <- mdl$get_data(pattern = "^g_.*")
g_data[ , ] <- 240
mdl$set_data(g_data)

ms_data <- mdl$get_data(pattern = "^ms_.*")
ms_data[ , ] <- 230
mdl$set_data(ms_data)

r_data <- mdl$get_data(pattern = "^r_.*")
r_data[ , ] <- 3.5
mdl$set_data(r_data)

y_data <- mdl$get_data(pattern = "^y_.*")
y_data[ , ] <- 980
mdl$set_data(y_data)

yd_data <- mdl$get_data(pattern = "^yd_.*")
yd_data[ , ] <- 980
mdl$set_data(yd_data)

mdl$set_data(regts(1300,  period = "2016Q4"), names = "y_co_1")

mdl$solve(options = list(cnmtrx = 0.3))
