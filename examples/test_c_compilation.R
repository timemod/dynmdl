library(dynmdl)


multiply <- function(x, y) {
  return(x*y)
}

multiply3 <- function(x, y, z) {
  return(x*y*z)
}


dynmdl:::test_c_compilation("testje", as.numeric(2:5))