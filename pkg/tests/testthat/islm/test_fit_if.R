library(dynmdl)

context("ISLM model with fit procedure and if statements")

ifelse_jac <<- function(x, y, z) {
  if (x) {
    return(c(0, 1, 0))
  } else {
    return(c(0, 0, 1))
  }
}

ifelse_d1 <<- function(x, y, z) {
  return(c(0, 0, 0, 0))
}

ifelse_d2 <<- function(x, y, z) {
  val <- if (x) {
        1
       } else {
         0
       }
  return(c(val, 0, 0, 0))  
}

ifelse_d3 <<- function(x, y, z) {
  val <- if (x) {
    0
  } else {
    1
  }
  return(c(val, 0, 0, 0))  
}


nperiods <- 18
mod_file <- "mod/islm_fit_if.mod"
dynare_dir     <- "dynare/output"
endo_name_file <- file.path(dynare_dir, "islm_fit_if_endo_names.txt")
endo_file <- file.path(dynare_dir, "islm_fit_if_endo.csv")

p1 <- period("2016Q1")
model_period <- period_range(p1, p1 + nperiods - 1)

report <- capture_output(mdl <- dyn_mdl(mod_file))
mdl$solve_steady()
mdl$set_period(model_period)
mdl$set_fit_targets(regts(c(1250, 1255, 1260), start = "2016Q1"), names = "y")
mdl$set_fit_targets(regts(c(250, 255), start = "2016Q1"), names = "t")

mdl$solve(control = list(silent = TRUE))

endo_names <- read.csv(endo_name_file, stringsAsFactors = FALSE,
                           header = FALSE, sep = "")[[1]]
endo_data <- t(as.matrix(read.csv(endo_file, header = FALSE)))
dynare_result <- regts(endo_data, start = start_period(mdl$get_period()) - 1,
                       names = endo_names)[, mdl$get_endo_names()]

test_that("dynare result equal to islm result", {
    p <- get_period_range(dynare_result)
    expect_equal(dynare_result, mdl$get_endo_data(period = p))
})
