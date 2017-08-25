#include <R.h>
#include <Rinternals.h>

void f_static(double *y);

SEXP f_static_(SEXP y) {

  f_static(REAL(y));

  return R_NilValue;
}
