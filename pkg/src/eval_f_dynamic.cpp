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
        for (int i = 0; i < nendo; i++) {
            x(i) = endos(icols[i] + it * n_endo);
        }
        List jac_data = jac_dynamic(x, exo_data, params, it + 1 + max_lag);
        IntegerVector rows_t   = jac_data[0];
        IntegerVector cols_t   = jac_data[1];
        NumericVector values_t = jac_data[2];
        for (int ideriv = 0; ideriv < rows_t.size();  ideriv++) {
            int ieq  = rows_t[ideriv] - 1;
            int icol = cols_t[ideriv] - 1;
            if (icol >= nendo) {
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

    List jac_data = jac_dynamic(x, exo_data, params, it + 1 + max_lag);
    IntegerVector rows_t   = jac_data[0];
    IntegerVector cols_t   = jac_data[1];
    NumericVector values_t = jac_data[2];

    vector<int> rows; 
    vector<int> columns;
    vector<double> values;

    for (int ideriv = 0; ideriv < rows_t.size();  ideriv++) {
        int ieq  = rows_t[ideriv];
        int icol = cols_t[ideriv];
        int ic = icol - nlags;
        if (ic < 1 || ic >  nendo) {
             continue;
        }
        double value = values_t[ideriv];
        if (value != 0) {
            // add 1 because the index origin in R is 1
            rows.push_back(ieq);
            columns.push_back(ic);
            values.push_back(value);
        }
    }
        
    Rcpp::IntegerVector rows_r(rows.begin(), rows.end());
    Rcpp::IntegerVector columns_r(columns.begin(), columns.end());
    Rcpp::NumericVector values_r(values.begin(), values.end());

    return List::create(Rcpp::Named("rows")    = rows_r,
                        Rcpp::Named("columns") = columns_r,
                        Rcpp::Named("values")  = values_r);
}
