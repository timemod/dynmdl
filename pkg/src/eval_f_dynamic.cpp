#include <Rcpp.h>
#include <iostream>
#include <map>
#include <vector>
using namespace Rcpp;
using std::endl;
using std::map;
using std::vector;

// [[Rcpp::export]]
NumericVector get_residuals_(NumericVector endos, NumericVector icols, SEXP exo_data,
                             SEXP params, Function f_dynamic, int n_endo, int nper,
                             int max_lag) {

    NumericVector res(nper * n_endo);
    NumericVector x(icols.size());

    for (int it = 0; it < nper; it++) {
        for (int i = 0; i < icols.size(); i++) {
            x(i) = endos(icols(i) +  it * n_endo);
        }
        NumericVector res_t = f_dynamic(x, exo_data, params,
                                        it + 1 + max_lag);          
        for (int id = 0; id < n_endo; id++) {
            res(id + it * n_endo) = res_t[id];
        }
    }
    return res;
}

// [[Rcpp::export]]
List get_triplet_jac(NumericVector endos, IntegerMatrix lead_lag_incidence, 
                     IntegerVector tshift, SEXP exo_data,
                     SEXP params, Function jac_dynamic, int n_endo,
                     int nper, int max_lag) {
    
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
    
    NumericVector x(nendo);

    vector<int> rows; 
    vector<int> columns;
    vector<double> values;
        
    for (int it = 0; it < nper; it++) {
        for (size_t i = 0; i < nendo; i++) {
            x(i) = endos(icols[i] + it * n_endo);
        }
        NumericMatrix jt  = jac_dynamic(x, exo_data, params, it + 1 + max_lag);
        for (size_t ideriv = 0; ideriv < nendo;  ideriv++) {
            int id = jac_var_id[ideriv];
            int ivt = it + jac_shift[ideriv];
            for (int ieq = 0; ieq < n_endo; ieq++) {
                double value = jt(ieq, ideriv);
                if (ivt >= 0 && ivt < nper && value != 0) {
                    // add 1 because the index origin in R is 1
                    rows.push_back(ieq + it * n_endo + 1);
                    columns.push_back(id + ivt * n_endo + 1);
                    values.push_back(value);
                }
            }
        }
    }

    delete[] jac_var_id, jac_shift, icols;
    
    Rcpp::IntegerVector rows_r(rows.begin(), rows.end());
    Rcpp::IntegerVector columns_r(columns.begin(), columns.end());
    Rcpp::NumericVector values_r(values.begin(), values.end());
    return List::create(Rcpp::Named("rows") = rows_r,
                        Rcpp::Named("columns") = columns_r,
                        Rcpp::Named("values") = values_r);
    }

// [[Rcpp::export]]
List get_jac_backwards(NumericVector endos, NumericVector lags,
                       NumericVector cols, 
                       SEXP exo_data, SEXP params, Function jac_dynamic,
                       int it, int max_lag) {

    int nlags  = lags.size();
    int nendo = endos.size();
    int nx = nlags + nendo;
    NumericVector x(nx);
    for (int i = 0; i < nlags; i++) {
        x[i] = lags[i];
    }
    for (int i = 0; i < nendo; i++) {
        x[i + nlags] = endos[i];
    }

    NumericMatrix jt  = jac_dynamic(x, exo_data, params, it + 1 + max_lag);
        
    vector<int> rows; 
    vector<int> columns;
    vector<double> values;
    for (int ieq = 0; ieq < nendo; ieq++) {
        for (size_t ideriv = 0; ideriv < nendo;  ideriv++) {
            double value = jt(ieq, cols[ideriv] - 1);
            if (value != 0) {
               // add 1 because the index origin in R is 1
                rows.push_back(ieq + 1);
                columns.push_back(ideriv + 1);
                values.push_back(value);
            }
        }
    }

    Rcpp::IntegerVector rows_r(rows.begin(), rows.end());
    Rcpp::IntegerVector columns_r(columns.begin(), columns.end());
    Rcpp::NumericVector values_r(values.begin(), values.end());

    return List::create(Rcpp::Named("rows") = rows_r,
                        Rcpp::Named("columns") = columns_r,
                        Rcpp::Named("values") = values_r);
}
