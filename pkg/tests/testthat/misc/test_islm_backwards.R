library(dynmdl)
library(testthat)

context("backwards ISLM model")

nperiods <- 18
mod_file <- "mod/islm_backwards.mod"
dynare_dir     <- "dynare/output"
endo_name_file <- file.path(dynare_dir, "islm_backwards_endo_names.txt")
exo_name_file  <- file.path(dynare_dir, "islm_backwards_exo_names.txt")

p1 <- period("2011Q3")
model_period <- period_range(p1, p1 + nperiods - 1)

report <- capture_output(mdl <- dyn_mdl(mod_file))
report2 <- capture_output(mdl$solve_steady())
report3 <- capture_output(mdl_int <- dyn_mdl(mod_file, calc = "internal"))
report4 <- capture_output(mdl_int$solve_steady())

mdl$set_period(model_period)
mdl_int$set_period(model_period)
lag_per <- mdl$get_lag_period()

get_dynare_endo <- function(endo_file, data_period) {
  endo_names <- read.csv(endo_name_file, stringsAsFactors = FALSE,
                         header = FALSE, sep = "")[[1]]
  endo_data <- t(as.matrix(read.csv(file.path(dynare_dir, endo_file),
                                    header = FALSE)))
  return(regts(endo_data, period = data_period, names = endo_names,
               labels = endo_names))
}

get_dynare_exo <- function(exo_file, data_period) {
  exo_names <- read.csv(exo_name_file, stringsAsFactors = FALSE,
                        header = FALSE, sep = "")[[1]]
  exo_data <- as.matrix(read.csv(file.path(dynare_dir, exo_file),
                                 header = FALSE))
  return(regts(exo_data, period = data_period, names = exo_names, 
               labels = exo_names))
}

dynare_endo <- get_dynare_endo("islm_backwards_simul_endo.csv", mdl$get_data_period())
dynare_exo <- get_dynare_exo("islm_backwards_simul_exo.csv", mdl$get_data_period())

test_that("solve", {
  mdl2 <- mdl$clone()
  mdl2$set_data(dynare_endo[lag_per])
  mdl2$set_data(dynare_exo)
  mdl2$solve(control = list(silent = TRUE))
  expect_equal(dynare_endo, mdl2$get_endo_data())
  expect_error(mdl2$solve_perturbation(),
               "No explosive roots. solve_first_order cannot handle this situation yet.")
})

test_that("solve with internal method", {
  mdl2 <- mdl_int$clone()
  mdl2$set_data(dynare_endo[lag_per])
  mdl2$set_data(dynare_exo)
  mdl2$solve(control = list(silent = TRUE))
  expect_equal(dynare_endo, mdl2$get_endo_data())
  expect_error(mdl2$solve_perturbation(),
               "No explosive roots. solve_first_order cannot handle this situation yet.")
})

test_that("solve with the stacked time method", {
  mdl2 <- mdl$clone()
  mdl2$set_data(dynare_endo[lag_per])
  mdl2$set_data(dynare_exo)
  mdl2$solve(control = list(silent = TRUE), force_stacked_time = TRUE)
  expect_equal(dynare_endo, mdl2$get_endo_data())
})

test_that("get_names", {
  endo_names <- c("y", "yd", "t",  "c", "i", "md", "r") 
  expect_equal(mdl$get_endo_names(), endo_names)
  
  expect_equal(mdl$get_endo_names(type = "lag"), c("y", "yd"))
  expect_equal(mdl$get_endo_names(type = "lead"), character(0))
  
  expect_equal(mdl$get_exo_names(), c("g", "ms"))
  
  par_names <- c(paste0("c", 0:5), paste0("i", 0:5), paste0("m", 0:3),
                 paste0("t", 0:1))
  par_names <- setdiff(par_names, c("c3", "i3"))
  expect_equal(mdl$get_par_names(), par_names)
})


test_that("get_jacob", {
  
  # create two copies of the model with only two periods
  mdl_2 <- mdl$copy()
  mdl_int_2 <- mdl_int$copy()
  
  p <- period_range("2013Q1/2013Q2")
  mdl_2$set_period(p)
  mdl_int_2$set_period(p)
  
  jac <- mdl_2$get_jacob()
  
  expect_known_value(jac,  "expected_output/islm_back_jac.rds")
  
  jac_int <- mdl_int_2$get_jacob()
  expect_equal(jac, jac_int)
  
  # modify data in some periods, this should not affect the result of 
  # get_back_jacob.
  mdl_2$set_endo_values(999, names = "r", period = "2012Q4") 
  mdl_2$set_endo_values(999, names = "r", period = "2013Q2") 
  
  back_jac <- mdl_2$get_back_jacob("2013Q1")
  back_jac_int <- mdl_int_2$get_back_jacob("2013Q1")
  expect_equal(back_jac, back_jac_int)
  
  # check that back_jac is equivalent with the full stacked-time Jacobian
  expected_result <- jac[1:7, 1:7]
  rownames(expected_result) <- NULL
  colnames(expected_result) <- sub("_t\\d$", "", colnames(expected_result))
  expect_equal(back_jac, expected_result)
  
  msg <- "The specified period \\(2011Q2\\) should lie within the range 2011Q3/2015Q4."
  expect_error(mdl$get_back_jacob("2011Q2"),  msg)
  
  jac_sparse <- mdl$get_back_jacob("2013Q1", sparse = TRUE)
  expect_s4_class(jac_sparse, "dgCMatrix")
})


