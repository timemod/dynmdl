library(dynmdl)
library(testthat)
rm(list = ls())

context("ISLM model steady state")

period = "2017/2022"

report <- capture_output(mdl <- islm_mdl())

mdl$set_static_exos(c(g = 250))
mdl_period <- mdl$copy()$set_period(period)

mdl_steady1 <- mdl$copy()$solve_steady(control = list(silent = TRUE))
mdl_steady1$set_period(period)

mdl_steady2 <- mdl_period$copy()$solve_steady(control = list(silent = TRUE))

test_that("steady state result is correct", {
  
  expect_false(isTRUE(all.equal(mdl_steady1$get_endo_data(), 
                                mdl_period$get_endo_data())))
  
  expected_diff <- mdl_period$get_endo_data(period = "2017/")
  expected_diff[] <- 0
  expect_equal(diff(mdl_steady1$get_endo_data()), expected_diff)
  
  expect_equal(as.numeric(mdl_steady1$get_endo_data(period = "2017")),
               as.numeric(mdl_steady1$get_static_endos()))
  
  # after solving the model the result should not change
  mdl_solve <- mdl_steady1$copy()$solve(control = list(silent = TRUE))
  expect_equal(mdl_solve$get_endo_data(), mdl_steady1$get_endo_data())
  
  expect_equal(mdl_steady2$get_endo_data(), mdl_period$get_endo_data())
})

test_that("put_static_endos", {
  
  mdl_steady3 <- mdl_steady2$copy()$put_static_endos()
  
  expect_equal(mdl_steady3$get_endo_data(), mdl_steady1$get_endo_data())
  expect_false(isTRUE(all.equal(mdl_steady3$get_endo_data(), 
                                mdl_steady2$get_endo_data())))
})

test_that("put_static_endos with period", {
  mdl_steady3 <- mdl_steady2$copy()
  period <- period_range("2022/")
  mdl_steady3$put_static_endos(period)
  
  expect_false(isTRUE(all.equal(mdl_steady3$get_endo_data(), 
                                mdl_steady2$get_endo_data())))
  expect_equal(mdl_steady3$get_endo_data(period = period),
               mdl_steady1$get_endo_data(period = period))
  expect_equal(mdl_steady3$get_endo_data(period = "/2021"),
               mdl_steady2$get_endo_data(period = "/2021"))
  
  mdl_steady3 <- mdl_steady2$copy()
  period <- period_range("2018", "2018")
  mdl_steady3$put_static_endos(period)
  
  expect_false(isTRUE(all.equal(mdl_steady3$get_endo_data(), 
                                mdl_steady2$get_endo_data())))
  expect_equal(mdl_steady3$get_endo_data(period = period),
               mdl_steady1$get_endo_data(period = period))
  expect_equal(mdl_steady3$get_endo_data(period = "/2017"),
               mdl_steady2$get_endo_data(period = "/2017"))
  expect_equal(mdl_steady3$get_endo_data(period = "2019/"),
               mdl_steady2$get_endo_data(period = "2019/"))
  
  #
  # errors
  #
  msg <- "The start period \\(2040\\) is after the end period \\(2023\\)"
  expect_error(mdl_steady3$put_static_endos("2040/"), msg)
})

test_that("non-finite values", {
  mdl_2 <- mdl$copy()
  mdl_2$set_static_endos(c(t  = NaN))
  mdl_2$set_static_exos(c(g = Inf))
  expect_silent(expect_warning(mdl_2$solve_steady(control = list(silent = TRUE)),
                                     "Solving the steady state not succesful"))
  expect_known_output(expect_warning(mdl_2$solve_steady(control = list(silent = FALSE)),
                                     "Solving the steady state not succesful"),
                      file = "expected_output/steady_non_finite_1.txt")
})

test_that("set_static_endos/set_static_exos", {
  mdl2 <- mdl$copy()
  
  msg <- "\"xxx\" is not an endogenous variable\\." 
  expect_error(mdl2$set_static_endos(c(c = 12, xxx = 3)), msg)
  expect_warning(mdl2$set_static_endos(c(c = 13, xxx = 3), name_err = "warn"), 
                 msg)
  expect_equal(mdl2$get_static_endos()["c"], c(c= 13))
  expect_equal(mdl2$get_static_endos(names = "c"), c(c= 13))
  expect_equal(mdl2$get_static_endos(pattern = "^c"), c(c= 13))
  
  expect_warning(x <- mdl2$get_static_endos(pattern = "^x"), 
               "No endogenous variables match pattern \"\\^x\".")
  expect_equal(length(x), 0)
  
  expect_silent(mdl2$set_static_endos(c(c = 14, xxx = 3), name_err = "silent"))
  expect_equal(mdl2$get_static_endos()["c"], c(c = 14))
  
  msg <- "The following names are no exogenous variables: \"c\", \"xxx\"\\."
  expect_error(mdl$set_static_exos(c(c = 12, xxx = 3, g = 12)), msg)
  expect_warning(mdl2$set_static_exos(c(c = 12, xxx = 3, g = 12), 
                                     name_err = "warn"), msg)
  expect_equal(mdl2$get_static_exos()["g"], c(g = 12))
  expect_equal(mdl2$get_static_exos(names = "g"), c(g = 12))
  expect_equal(mdl2$get_static_exos(pattern = "^g"), c(g = 12))
  
  expect_warning(x <- mdl2$get_static_exos(pattern = "^x"), 
                 "No exogenous variables match pattern \"\\^x\".")
  expect_equal(length(x), 0)
  
  expect_silent(mdl2$set_static_exos(c(c = 12, xxx = 3, g = 122), 
                         name_err = "silent"))
  expect_equal(mdl2$get_static_exos()["g"], c(g = 122))
  
  mdl2$set_static_endos(c(c = 333, y = 444))
  expect_equal(mdl2$get_static_endos(names = c("y", "c")),
               c(y = 444, c = 333))
  
  mdl2$set_static_exos(c(ms = 555, g = 666))
  expect_equal(mdl2$get_static_exos(pattern = "^(g|(ms))$"),
               c(g = 666, ms = 555))
  
  mdl2$set_static_endos(c(aap = 333, zzz = 444), names = c("c", "y"))
  expect_equal(mdl2$get_static_endos(names = c("y", "c")),
               c(y = 444, c = 333))
  
  mdl2$set_static_exos(c(jan = 5555, piet = 6666), names = c("ms", "g"))
  expect_equal(mdl2$get_static_exos(pattern = "^(g|(ms))$"),
               c(g = 6666, ms = 5555))
})


test_that("set_static_exo_values", {
  mdl2 <- mdl$copy()
  mdl2$set_static_exo_values(0)
  expect_identical(mdl2$get_static_exos(), c(g = 0, ms = 0))
  mdl2$set_static_exo_values(2, pattern = "^m")
  expect_identical(mdl2$get_static_exos(), c(g = 0, ms = 2))
  mdl2$set_static_exo_values(3, names = "g")
  expect_identical(mdl2$get_static_exos(), c(g = 3, ms = 2))
  
  expect_error(mdl2$set_static_exo_values(0, names = "xxx"), 
               "\"xxx\" is not an exogenous variable")
})

test_that("set_static_data / get_static_data", {
  
  mdl2 <- mdl$copy()
  
  model_names <- c(mdl$get_endo_names(), mdl$get_exo_names())
  
  expect_error(mdl2$set_static_data(c(z  = 2)),
                                    '"z" is not an endogenous or exogenous variable.')  
  expect_silent(mdl2$set_static_data(c(z  = 2), name_err = "silent"))
  mdl2$set_static_data(mdl2$get_static_data())
  expect_equal(mdl2$get_static_data(names = model_names),
               c(mdl$get_static_endos(), mdl$get_static_exos())[sort(model_names)])
  
  msg <- 'The following names are no endogenous or exogenous variables: "xxx", "yyy".'
  expect_warning(
    mdl2$set_static_data(c(c = 222, g = 333, xxx = 5, yyy = 2), 
                         name_err = "warn"),
    msg)
    
  expected_result <- mdl$get_static_data()
  expected_result[c("c", "g")] <- c(222, 333)
  
  expect_equal(mdl2$get_static_data(), expected_result)
  
  expect_warning(x <- mdl2$get_static_data(pattern = "^x"), 
                 "No endogenous or exogenous variables match pattern \"\\^x\".")
  expect_equal(length(x), 0)
  
  expect_equal(mdl2$get_static_data(pattern = "^[gm]"), 
                                    expected_result[c("g", "md", "ms")])
  
  
  expect_equal(length(mdl2$get_static_data(names = character(0))), 0)
  expect_equal(length(mdl2$get_static_endos(names = character(0))), 0)
  expect_equal(length(mdl2$get_static_exos(names = character(0))), 0)
  
  
  expect_warning(mdl2$set_static_data(c(ms = 555, md = 666, ms = -999)),
                                      paste0("Values contains duplicate names.",
                                            " The first value is used.\n",
                                            "The duplicated names are: ms."))
  expect_equal(mdl2$get_static_data(pattern = "^m"),
               c(md = 666, ms = 555))
  
  mdl2$set_static_data(c(5555, 6666), names = c("ms", "md"))
  expect_equal(mdl2$get_static_data(pattern = "^m"),
               c(md = 6666, ms = 5555))
  
  expect_error(mdl2$set_static_data(c(5555, 6666)),
       "If argument data has no names, than argument names must be specified.")
  
  expect_error(mdl2$set_static_data(c(5555, 6666), names = "xxx"),
               "The length of argument names \\(1\\) should be equal to the length of argument data \\(2\\).")
  
  expect_error(mdl2$set_static_data(c(c = "xxx")),
               "Argument data must be a numeric vector.")
  
})