#include <Rcpp.h>
#include <iostream>
#include <map>
#include <vector>
#include "PolishModels.hh"
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
void prepare_internal_dyn(int model_index, NumericVector exos, int nrow_exo,
                           NumericVector params) {

    PolishModel *mdl = PolishModels::get_dynamic_model(model_index);
    mdl->set_param(REAL(params));
    mdl->set_exo(REAL(exos), nrow_exo);
}

// [[Rcpp::export]]
NumericVector get_residuals_dyn(int model_index, NumericVector endos, 
                                NumericVector icols, int n_endo, int nper,
                                int period_shift) {

    PolishModel *mdl = PolishModels::get_dynamic_model(model_index);

    NumericVector res(nper * n_endo);

    double *y = new double[icols.size()];
    double *residuals = REAL(res);
    double *res_t = new double[n_endo];

    for (int it = 0; it < nper; it++) {
        for (int i = 0; i < icols.size(); i++) {
            y[i] = endos(icols(i) +  it * n_endo);
        }
        mdl->get_residuals(y, res_t, it + period_shift);
        for (int id = 0; id < n_endo; id++) {
            residuals[id + it * n_endo] = res_t[id];
        }
    }

    delete[] y;
    delete[] res_t;

    return res;
}

// [[Rcpp::export]]
List get_triplet_jac_dyn(int model_index, NumericVector endos, 
       IntegerMatrix lead_lag_incidence, IntegerVector tshift, 
       int n_endo, int nper, int period_shift) {

    PolishModel *mdl = PolishModels::get_dynamic_model(model_index);
        
    int nendo = max(lead_lag_incidence);
    int *jac_var_id = new int[nendo];
    int *jac_shift  = new int[nendo];
    int *icols      = new int[nendo];

    int cnt = 0;
    for (int c = 0; c < lead_lag_incidence.ncol(); c++) {
        for (int r = 0; r < lead_lag_incidence.nrow(); r++) {
            int i = lead_lag_incidence(r, c);
            if (i) {
                jac_var_id[i - 1] = r;
                jac_shift[i - 1] = tshift[c];
                icols[i - 1] = cnt;
            }
            cnt++;
        }
    }
    
    vector<int> rows; 
    vector<int> columns;
    vector<double> values;

    // variables for calculating the Jacobian at one period
    int  njac_t = mdl->get_jac_count();
    int *rows_t = new int[njac_t];
    int *cols_t = new int[njac_t];
    double *values_t = new double[njac_t];
    double *y = new double[nendo];
        
    for (int it = 0; it < nper; it++) {
        for (int i = 0; i < nendo; i++) {
            y[i] = endos(icols[i] +  it * n_endo);
        }
        mdl->get_jac(y, rows_t, cols_t, values_t, it + period_shift);
        for (int ideriv = 0; ideriv < njac_t;  ideriv++) {
            int ieq  = rows_t[ideriv];
            int icol = cols_t[ideriv];
            if (icol > nendo - 1) {
                // the calculated Jacobian also contains
                // derivatives w.r.t. the exogenous variables.
                // we don't need that. TODO: do not calculate 
                // these derivatives!
                continue;
            }
            int id  = jac_var_id[icol];
            int ivt = it + jac_shift[icol];
            double value = values_t[ideriv];
            if (ivt >= 0 && ivt < nper && value != 0) {
                // add 1 because the index origin in R is 1
                rows.push_back(ieq + it * n_endo + 1);
                columns.push_back(id + ivt * n_endo + 1);
                values.push_back(value);
            }
        }
    }

    delete[] jac_var_id;
    delete[] jac_shift;
    delete[] icols;
    delete[] rows_t;
    delete[] cols_t;
    delete[] values_t;
    
    Rcpp::IntegerVector rows_r(rows.begin(), rows.end());
    Rcpp::IntegerVector columns_r(columns.begin(), columns.end());
    Rcpp::NumericVector values_r(values.begin(), values.end());
    return List::create(Rcpp::Named("rows") = rows_r,
                        Rcpp::Named("cols") = columns_r,
                        Rcpp::Named("values") = values_r);
}

// [[Rcpp::export]]
List get_jac_dyn(int model_index, NumericVector endos, int it) {

    PolishModel *mdl = PolishModels::get_dynamic_model(model_index);

    int njac = mdl->get_jac_count();
    IntegerVector rows(njac), cols(njac);
    NumericVector values(njac);

    mdl->get_jac(REAL(endos), INTEGER(rows), INTEGER(cols), REAL(values), it - 1);

     // add 1 because the index origin in R is 1
    rows = rows + 1;
    cols = cols + 1;

    return List::create(Rcpp::Named("rows") = rows, 
                        Rcpp::Named("cols") = cols,
                        Rcpp::Named("values") = values);
}

// [[Rcpp::export]]
NumericVector get_res_back_dyn(int model_index, NumericVector endos,
                               NumericVector lags, int it, int period_shift) {

    PolishModel *mdl = PolishModels::get_dynamic_model(model_index);

    int nlags = lags.size();
    int nendo = endos.size();
    int nx = nlags + nendo;

    double *x = new double[nx];
    for (int i = 0; i < nlags; i++) {
        x[i] = lags[i];
    }
    for (int i = 0; i < nendo; i++) {
        x[i + nlags] = endos[i];
    }
    
    NumericVector res(nendo);
    mdl->get_residuals(x, REAL(res), it + period_shift - 1);

    delete[] x;

    return res;
}

// [[Rcpp::export]]
List get_jac_back_dyn(int model_index, NumericVector endos, NumericVector lags,
                      NumericVector cols, int it, int period_shift) {

    PolishModel *mdl = PolishModels::get_dynamic_model(model_index);

    int nlags = lags.size();
    int nendo = endos.size();
    int nx = nlags + nendo;

    double *x = new double[nx];
    for (int i = 0; i < nlags; i++) {
        x[i] = lags[i];
    }
    for (int i = 0; i < nendo; i++) {
        x[i + nlags] = endos[i];
    }

    int njac = mdl->get_jac_count();
    int *rows_t = new int[njac];
    int *cols_t = new int[njac];
    double *values_t = new double[njac];

    mdl->get_jac(x, rows_t, cols_t, values_t, it + period_shift - 1);

    vector<int> rows; 
    vector<int> columns;
    vector<double> values;

    for (int ideriv = 0; ideriv < njac;  ideriv++) {
        int ieq  = rows_t[ideriv];
        int icol = cols_t[ideriv];
        int ic = icol - nlags;
        if (ic < 0 || ic >=  nendo) {
             continue;
        }
        double value = values_t[ideriv];
        if (value != 0) {
            // add 1 because the index origin in R is 1.
            rows.push_back(ieq + 1);
            columns.push_back(ic + 1);
            values.push_back(value);
        }
    }

    delete[] x;
    delete[] rows_t;
    delete[] cols_t;
    delete[] values_t;
        
    Rcpp::IntegerVector rows_r(rows.begin(), rows.end());
    Rcpp::IntegerVector columns_r(columns.begin(), columns.end());
    Rcpp::NumericVector values_r(values.begin(), values.end());

    return List::create(Rcpp::Named("rows")    = rows_r,
                        Rcpp::Named("cols")    = columns_r,
                        Rcpp::Named("values")  = values_r);
}

