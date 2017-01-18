#include <R.h>
#include <Rinternals.h>

void f_static(double *y, double *x, int nb_row_x, double *params, double *residual);
void jac_static(double *y, double *x, int nb_row_x, double *params, double *g1);
void f_dynamic(double *y, double *x, int nb_row_x, double *params, int it_, double *residual);
void jac_dynamic(double *y, double *x, int nb_row_x, double *params, int it_, double *g1);

SEXP f_static_(SEXP y, SEXP x, SEXP params, SEXP neq_, SEXP nb_row_x_) {

    int neq      = asInteger(neq_);
    int nb_row_x = asInteger(nb_row_x_);

    SEXP out = PROTECT(allocVector(REALSXP, neq));

    f_static(REAL(y), REAL(x), nb_row_x, REAL(params), REAL(out));

    UNPROTECT(1);
    return out;
}

SEXP jac_static_(SEXP y, SEXP x, SEXP params, SEXP jac_dim_, SEXP nb_row_x_) {

    int jac_dim  = asInteger(jac_dim_);
    int nb_row_x = asInteger(nb_row_x_);

    SEXP out = PROTECT(allocVector(REALSXP, jac_dim));

    jac_static(REAL(y), REAL(x), nb_row_x, REAL(params), REAL(out));

    UNPROTECT(1);
    return out;
}

SEXP f_dynamic(SEXP y, SEXP x, SEXP params, SEXP neq_, SEXP it__, SEXP nb_row_x_) {

    int neq      = asInteger(neq_);
    int nb_row_x = asInteger(nb_row_x_);
    int it_ = asInteger(it__);

    SEXP out = PROTECT(allocVector(REALSXP, neq));

    f_dynamic(REAL(y), REAL(x), nb_row_x, REAL(params), it_REAL(out));

    UNPROTECT(1);
    return out;
}

SEXP jac_dynamic(SEXP y, SEXP x, SEXP params, SEXP jac_dim_, SEXP it__, SEXP nb_row_x_) {

    int jac_dim  = asInteger(jac_dim_);
    int nb_row_x = asInteger(nb_row_x_);
    int it_ = asInteger(it__);

    SEXP out = PROTECT(allocVector(REALSXP, jac_dim));

    jac_dynamic(REAL(y), REAL(x), nb_row_x, REAL(params), it_, REAL(out));

    UNPROTECT(1);
    return out;
}
