# Order eigenvalues by increasing Modulus. Eigenvalues with the same modulus
# are sorted with increasing imaginary part. The machine precision is taken
# into account.
order_eigval <- function(eigval) {

  # first order eigenvalues with increasing modulus
  eigval <- eigval[order(Mod(eigval))]
  
  # check if the modulus of an eigenvalue if close to their 
  # neigbours, if so set the modulus equal
  mod <- Mod(eigval)
  for (i in 2 : length(mod)) {
    d <- mod[i] - mod[i - 1]
    if (!is.na(d) && d < .Machine$double.eps) {
      mod[i] <- mod[i - 1]
    }
  }
  
  # order with increasing complex angle
  fac <- Im(eigval) / Re(eigval)
 
  return(eigval[order(mod, fac)])
}