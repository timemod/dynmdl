#include <Rcpp.h>
#include <iostream>
#include <map>
#include <vector>
#include "PolishModels.hh"
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
NumericVector get_residuals_internal(int model_index, NumericVector endos, 
                                     NumericVector icols, NumericVector exo_data,
                                     NumericVector params, int n_endo, int nper,
                                     int period_shift) {

    PolishModel *mdl = PolishModels::get_model(model_index);

    NumericVector res(nper * n_endo);

    double *y = new double[icols.size()];
    double *x = REAL(exo_data);
    double *p = REAL(params);
    double *residuals = REAL(res);
    double *res_t = new double[n_endo];

    mdl->set_param(p);

    for (int it = 0; it < nper; it++) {
        for (int i = 0; i < icols.size(); i++) {
            y[i] = endos(icols(i) +  it * n_endo);
        }
        mdl->get_residuals(y, res_t, it + period_shift);
        for (int id = 0; id < n_endo; id++) {
            residuals[id + it * n_endo] = res_t[id];
        }
    }
    return res;
}
