#include <R.h>
#include <Rinternals.h>

/* FIRST ATTEMPT TO DIRECTLY CALCULATE THE TRIPLET JACOBIAN,
 * WITHOUT INTERMEDIATE R FUNCTION */

extern "C" void jac_dynamic(double *y, double *x, int nb_row_x, double *params, 
                 int it_, double *g1);


SEXP get_triplet_jac(SEXP endos, SEXP exo_data, SEXP params,
                         SEXP nb_row_x_, SEXP nper_, SEXP max_lag_,
                         SEXP jac_work) {

    int nb_row_x = asInteger(nb_row_x_);
    int nper     = asInteger(nper_);
    int max_lag  = asInteger(max_lag_);

    for (int it = 0; it < nper; it++) {
        jac_dynamic(REAL(endos), REAL(exo_data), nb_row_x, REAL(params), 
                    it + 1 + max_lag, REAL(jac_work));
    }
    return(R_NilValue);
}
