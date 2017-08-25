#include <math.h>
#include <stdlib.h>
#include <Rinternals.h>
#include <Rdefines.h>
    
void f_static(double *y) {

  Rprintf("\ny[0] = %g\n", y[0]);
  return;
}
