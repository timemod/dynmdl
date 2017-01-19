library(isismdl)

ret <- compile_mdl("islm_back_countries_200.mdl")
mdl <- read_mdl("islm_back_countries_200.mif")
print(mdl)

endo_input <- as.regts(read.csv("inp/islm_back_countries_200_endo.csv", 
                       row.names = 1))
exo_input <- as.regts(read.csv("inp/islm_back_countries_200_exo.csv", 
                       row.names = 1))


mdl$set_period("2017Q1/2022Q4")
mdl$set_data(endo_input)
mdl$set_data(exo_input)
mdl$solve()
