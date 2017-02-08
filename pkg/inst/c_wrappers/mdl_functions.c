#include <R.h>
#include <Rinternals.h>

void f_static(double *y, double *x, double *params, double *residual);
void jac_static(double *y, double *x, double *params, double *g1);
void f_dynamic(double *y, double *x, int nb_row_x, double *params, int it_, double *residual);
void jac_dynamic(double *y, double *x, int nb_row_x, double *params, int it_,
                 int *rows, int *cols, double *values);

SEXP f_static_(SEXP y, SEXP x, SEXP params, SEXP res) {
    f_static(REAL(y), REAL(x), REAL(params), REAL(res));
    return R_NilValue;
}

SEXP jac_static_(SEXP y, SEXP x, SEXP params, SEXP jac) {
    jac_static(REAL(y), REAL(x), REAL(params), REAL(jac));
    return R_NilValue;
}

SEXP f_dynamic_(SEXP y, SEXP x, SEXP params, SEXP it__, SEXP nb_row_x_, SEXP res) {
    int nb_row_x = asInteger(nb_row_x_);
    int it_ = asInteger(it__);
    f_dynamic(REAL(y), REAL(x), nb_row_x, REAL(params), it_, REAL(res));
    return R_NilValue;
}

SEXP jac_dynamic_(SEXP y, SEXP x, SEXP params, SEXP it__, SEXP nb_row_x_,
                  SEXP rows, SEXP cols, SEXP values) {
    int nb_row_x = asInteger(nb_row_x_);
    int it_ = asInteger(it__);
    jac_dynamic(REAL(y), REAL(x), nb_row_x, REAL(params), it_, INTEGER(rows), 
                INTEGER(cols), REAL(values));
    return R_NilValue;
}
