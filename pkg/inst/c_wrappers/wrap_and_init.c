#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>

/* Declarations of generated functions */

void f_static(double *y, double *x, double *params, double *residual);
void f_dynamic(double *y, double *x, int nb_row_x, double *params, int it_, double *residual);
void jac_static(double *y, double *x, double *params, int *rows, int *cols, double *values);
void jac_dynamic(double *y, double *x, int nb_row_x, double *params, int it_,
                 int *rows, int *cols, double *values);

/* -----------------------
   Fast .Call wrappers (minimal checking)
   Argument names use the suffix __SEXP as requested.
   For scalar integer arguments we use Rf_asInteger() to coerce safely.
   Rows/cols vectors are accessed with INTEGER(...) and therefore
   must be integer vectors on the R side.
   ----------------------- */

SEXP f_static_call(SEXP y__SEXP, SEXP x__SEXP, SEXP params__SEXP, SEXP residual__SEXP) {
    /* Assumes y/x/params/residual are REALSXP; no runtime checks for speed */
    f_static(REAL(y__SEXP), REAL(x__SEXP), REAL(params__SEXP), REAL(residual__SEXP));
    return R_NilValue;
}

SEXP f_dynamic_call(SEXP y__SEXP, SEXP x__SEXP, SEXP nb_row_x__SEXP,
                    SEXP params__SEXP, SEXP it__SEXP, SEXP residual__SEXP) {
    /* Assumes y/x/params/residual are REALSXP; no runtime checks for speed */
    /* coerce scalar integer arguments safely */
    int nb_row_x = Rf_asInteger(nb_row_x__SEXP);
    int it_ = Rf_asInteger(it__SEXP);

    f_dynamic(REAL(y__SEXP), REAL(x__SEXP), nb_row_x, REAL(params__SEXP), it_, REAL(residual__SEXP));
    return R_NilValue;
}

SEXP jac_static_call(SEXP y__SEXP, SEXP x__SEXP, SEXP params__SEXP,
                     SEXP rows__SEXP, SEXP cols__SEXP, SEXP values__SEXP) {
    /* rows__SEXP and cols__SEXP must be integer vectors (INTSXP) */
    jac_static(REAL(y__SEXP), REAL(x__SEXP), REAL(params__SEXP), INTEGER(rows__SEXP), INTEGER(cols__SEXP), REAL(values__SEXP));
    return R_NilValue;
}

SEXP jac_dynamic_call(SEXP y__SEXP, SEXP x__SEXP, SEXP nb_row_x__SEXP,
                      SEXP params__SEXP, SEXP it__SEXP,
                      SEXP rows__SEXP, SEXP cols__SEXP, SEXP values__SEXP) {

    int nb_row_x = Rf_asInteger(nb_row_x__SEXP);
    int it_ = Rf_asInteger(it__SEXP);

    jac_dynamic(REAL(y__SEXP), REAL(x__SEXP), nb_row_x, REAL(params__SEXP), it_,
                INTEGER(rows__SEXP), INTEGER(cols__SEXP), REAL(values__SEXP));
    return R_NilValue;
}

/* -----------------------
   Registration: register the .Call wrappers. We register both plain and
   underscored names for backwards compatibility.
   ----------------------- */

static const R_CallMethodDef CallEntries[] = {
    {"f_static",    (DL_FUNC) &f_static_call,    4},
    {"f_static_",   (DL_FUNC) &f_static_call,    4},
    {"f_dynamic",   (DL_FUNC) &f_dynamic_call,   6},
    {"f_dynamic_",  (DL_FUNC) &f_dynamic_call,   6},
    {"jac_static",  (DL_FUNC) &jac_static_call,  6},
    {"jac_static_", (DL_FUNC) &jac_static_call,  6},
    {"jac_dynamic", (DL_FUNC) &jac_dynamic_call, 8},
    {NULL, NULL, 0}
};

void R_init_mdl_functions(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
