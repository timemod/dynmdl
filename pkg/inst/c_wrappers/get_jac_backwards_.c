#include <R.h>
#include <Rinternals.h>
#include <stdlib.h>
#include <time.h>


/* preliminary experiment with direct calculation of bvackwards jacobian
 * not used yet */

// TODO: put the next statement in a header
void jac_dynamic(double *y, double *x, int nb_row_x, double *params, 
                 int it_, double *g1);

static void alloc_x_work(int n_x_work);
static void alloc_jac_work(int n_jac_work);

static double *x_work = NULL;
static int x_work_size = 0;
static double *jac_work = NULL;
static int jac_work_size = 0;

clock_t begin, end;

SEXP get_jac_backwards_(SEXP x_, SEXP lags_, SEXP exo_data, SEXP params,
                        SEXP nb_row_x_, SEXP it_, SEXP max_lag_,
                        SEXP n_jac_cols_, SEXP cols_) {

    begin = clock();
    int nendo = length(x_);
    int nlags = length(lags_);
    int n_jac_cols = asInteger(n_jac_cols_);
    double *x = REAL(x_);
    double *lags = REAL(lags_);
    int *cols = INTEGER(cols_);
    int ncol = length(cols_);
    int nb_row_x = asInteger(nb_row_x_);
    int it = asInteger(it_);
    int max_lag = asInteger(max_lag_);
    end = clock();
    Rprintf("timing deel -2 %g\n",  ((double)(end - begin)) / CLOCKS_PER_SEC);
    begin = clock();

    alloc_x_work(nendo + nlags);
    for (int i = 0; i < nlags; i++) {
        x_work[i] = lags[i];
    }
    for (int i = 0; i < nendo; i++) {
        x_work[i + nlags] = x[i];
    }
    end = clock();
    Rprintf("timing deel -1 %g\n",  ((double)(end - begin)) / CLOCKS_PER_SEC);
    begin = clock();

    alloc_jac_work(nendo * n_jac_cols);
    int i;
    for (int i = 0; i < nendo * n_jac_cols; i++) {
        jac_work[i] = 0.0;
    }

    end = clock();
    Rprintf("timing deel a %g\n",  ((double)(end - begin)) / CLOCKS_PER_SEC);
    begin = clock();

    jac_dynamic(x_work, REAL(exo_data), nb_row_x, REAL(params), 
                it + max_lag, jac_work);

    end = clock();
    Rprintf("timing deel b %g\n",  ((double)(end - begin)) / CLOCKS_PER_SEC);

    begin = clock();
    /* count the number of nonzeros */
    int nelem = 0, ieq, icol;
    for (ieq = 0; ieq < nendo; ieq++) {
        for (icol = 0; icol < ncol; icol++) {
            double value = jac_work[ieq + (cols[icol]  - 1) * nendo];
            //double value = jac_work[12];
            //Rprintf("ieq, icol, value = %d %d %g\n", ieq, icol, value);
            //Rprintf("index = %d\n",ieq + (cols[icol]  - 1) *nendo);
            if (value != 0) {
                nelem++;
            }
        }
    }

    end = clock();
    Rprintf("timing deel c %g\n",  ((double)(end - begin)) / CLOCKS_PER_SEC);
    begin = clock();

    SEXP r = PROTECT(allocVector(INTSXP, nelem));
    SEXP c = PROTECT(allocVector(INTSXP, nelem));
    SEXP v = PROTECT(allocVector(REALSXP, nelem));
    int *r_ = INTEGER(r);
    int *c_ = INTEGER(c);
    double *v_ = REAL(v);

    int ielem = 0;
    for (ieq = 0; ieq < nendo; ieq++) {
        for (icol = 0; icol < ncol; icol++) {
            double value = jac_work[ieq + (cols[icol] - 1)* nendo];
            if (value != 0) {
                r_[ielem] = ieq + 1;
                c_[ielem] = icol + 1;
                v_[ielem] = value;
                ielem++;
            }
        }
    }

    end = clock();
    Rprintf("timing deel d %g\n",  ((double)(end - begin)) / CLOCKS_PER_SEC);
    begin = clock();
    
    SEXP ret   = PROTECT(allocVector(VECSXP, 3));
    SEXP names = PROTECT(allocVector(STRSXP, 3));

    SET_VECTOR_ELT(ret, 0, r);
    SET_VECTOR_ELT(ret, 1, c);
    SET_VECTOR_ELT(ret, 2, v);

    SET_STRING_ELT(names, 0, mkChar("rows"));
    SET_STRING_ELT(names, 1, mkChar("columns"));
    SET_STRING_ELT(names, 2, mkChar("values"));

    setAttrib(ret, R_NamesSymbol, names);

    end = clock();
    Rprintf("timing deel e %g\n",  ((double)(end - begin)) / CLOCKS_PER_SEC);

    UNPROTECT(5);

    return ret;
}

static void alloc_x_work(int n_x_work) {
    if (n_x_work > x_work_size) {
        if (x_work != NULL) {
            free(x_work);
        }
        x_work = (double *) malloc(n_x_work * sizeof(double));
    }
}

static void alloc_jac_work(int n_jac_work) {
    if (n_jac_work > jac_work_size) {
        if (jac_work != NULL) {
            free(jac_work);
        }
        jac_work = (double *) malloc(n_jac_work * sizeof(double));
    }
}
