# Example for the IFN model

library(dynmdl)

mod_file <- "mod/ifn.mod"
input_file <- "input/ifn_input.csv"

mdl <- create_mdl(mod_file)

input_df <- read.csv(input_file)
nperiods <- nrow(input_df) - 2  # subtract maximum lead and lag
p1 <- period("2015")
model_period <- period_range(p1, p1 + nperiods - 1)

mdl$set_period(model_period)
lag_per <- mdl$get_lag_period()

input <- regts(input_df, period = mdl$get_data_period(),
               names = tolower(colnames(input_df)))

mdl$set_data(input)
mdl$solve(control = list(trace = TRUE))
plot(mdl$get_endo_data("yd"), type = "o")
