#include <Rcpp.h>
#include <iostream>
#include <map>
#include <vector>
using namespace Rcpp;
using std::endl;
using std::map;
using std::vector;

class VarInfo {
public:
    int id, shift;
    VarInfo() {}
    VarInfo(int var_id, int t_shift):
        id(var_id), shift(t_shift)
        {}
};

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

    std::map<int, VarInfo> jacmap;
    std::vector<int> icols;
    int cnt = 0;
    for (int c = 0; c < lead_lag_incidence.ncol(); c++) {
        for (int r = 0; r < lead_lag_incidence.nrow(); r++) {
            int i = lead_lag_incidence(r, c);
            if (i) {
                jacmap[i - 1] = VarInfo(r, tshift[c]);
                icols.push_back(cnt);
            }
            cnt++;
        }
    }
    
    NumericVector x(icols.size());
    
    vector<int> rows;
    vector<int> columns;
    vector<double> values;

    for (int it = 0; it < nper; it++) {
        for (size_t i = 0; i < icols.size(); i++) {
            x(i) = endos(icols[i] + it * n_endo);
        }
        NumericMatrix jt  = jac_dynamic(x, exo_data, params, it + 1 + max_lag);
        for (int ieq = 0; ieq < n_endo; ieq++) {
            for (size_t ideriv = 0; ideriv < jacmap.size(); ideriv++) {
                VarInfo var_info = jacmap[ideriv];
                int id = var_info.id;
                int ivt = it + var_info.shift;
                double value = jt(ieq, ideriv);
                if (ivt >= 0 && ivt < nper && value != 0) {
                    rows.push_back(ieq + it * n_endo);
                    columns.push_back(id + ivt * n_endo);
                    values.push_back(value);
                }
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
