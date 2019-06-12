linpow <- function(x, p, eps) {
  if (x > eps) {
    return(x^p)
  } else {
    return(eps^p * (1 + p * (x - eps) / eps))
  }
}