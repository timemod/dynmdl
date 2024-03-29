library(dynmdl)
library(testthat)

rm(list = ls())


model <- "linlog1"

mod_file <- file.path("mod", paste0(model, ".mod"))

period <- period_range("2018/2030")
nper <- nperiod(period)

report <- capture_output({
  mdl <- dyn_mdl(mod_file, period = "2018/2030", calc = "internal")
})

test_that("solve_steady", {
  mdl$solve_steady(control = list(silent = TRUE))
  expect_equal(mdl$get_solve_status(), "OK")
  expect_equal(mdl$get_static_endos(), c(y1 = 0, y2 = 0, y3 = 0))
})

test_that("solve", {
  
  mdl$set_exo_values(seq(-0.1, 1, length.out = nper))
  mdl$solve(silent = TRUE)
  expect_equal(mdl$get_solve_status(), "OK")
  ed <- mdl$get_endo_data()

  exod <- as.numeric(mdl$get_exo_data())
  y1_exp <- sapply(as.numeric(exod), FUN = dynmdl:::linlog, eps = 1e-4)
  y2_exp <- sapply(as.numeric(exod), FUN = dynmdl:::linlog, eps = 1e-3)
  y3_exp <- sapply(as.numeric(exod), FUN = dynmdl:::linlog, eps = 1e-1)

  expected_result <- cbind(y1 = y1_exp, y2 = y2_exp, y3 = y3_exp)
  expected_result <- regts(expected_result, period = period)
  ts_labels(expected_result) <- paste0("y", 1:3)
  expect_equal(expected_result, ed)
  
  sel <- exod > 1e-1
  suppressWarnings(log_result <- log(cbind(y1 = exod, y2 = exod, y3 = exod)))
  log_result <- log_result[sel, ]

  expect_equal(log_result, ed[sel, ])
})
