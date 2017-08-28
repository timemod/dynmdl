#include <math.h>
#include <stdlib.h>
#include <Rinternals.h>
#include <Rdefines.h>

#include "call_R_function.h"
    
void f_static(double *y) {

  init_call_R();

  call_R_function("multiply", 2, y[0], y[1]);
  Rprintf("\n\nResult of multiply: %g\n", get_result(0));

  call_R_function("multiply3", 3, y[0], y[1], y[1]);
  Rprintf("\n\nResult of multiply 3: %g\n", get_result(0));

  close_call_R();
  return;
}
