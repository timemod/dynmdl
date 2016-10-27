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
List get_triplet_jac(SEXP mdl_, NumericVector endos, Function jacfun) {
    Rcpp::S4 mdl(mdl_);
    int max_exo_lag = mdl.slot("max_exo_lag");
    int max_endo_lag = mdl.slot("max_endo_lag");
    int max_endo_lead = mdl.slot("max_endo_lead");
    int n_endo = mdl.slot("endo_count");
    int nper_data = endos.size() / n_endo;
    int nper = nper_data - max_endo_lag - max_endo_lead;

    IntegerMatrix lead_lag_incidence = mdl.slot("lead_lag_incidence");
    std::map<int, VarInfo> jacmap;
    std::vector<int> icols;
    int cnt = 0;
    for (int c = 0; c < lead_lag_incidence.ncol(); c++) {
        for (int r = 0; r < lead_lag_incidence.nrow(); r++) {
            int i = lead_lag_incidence(r, c);
            if (i) {
                jacmap[i - 1] = VarInfo(r, c - 1);
                icols.push_back(cnt);
            }
            cnt++;
        }
    }

    //NumericVector params = mdl.slot("params");
    NumericVector x(icols.size());

    vector<int> rows;
    vector<int> columns;
    vector<double> values;

    for (int it = 0; it < nper; it++) {
        for (int i = 0; i < icols.size(); i++) {
            x(i) = endos(icols[i]);
        }
        NumericMatrix jt = jacfun(x, it + 1 + max_exo_lag);
        for (int ieq = 0; ieq < n_endo; ieq++) {
            for (int ideriv = 0; ideriv < jacmap.size(); ideriv++) {
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
        for (int i = 0; i < icols.size(); i++) {
            icols[i] += n_endo;
        }
    }

    Rcpp::IntegerVector rows_r(rows.begin(), rows.end());
    Rcpp::IntegerVector columns_r(columns.begin(), columns.end());
    Rcpp::NumericVector values_r(values.begin(), values.end());
    return List::create(Rcpp::Named("rows") = rows_r,
                        Rcpp::Named("columns") = columns_r,
                        Rcpp::Named("values") = values_r);
}
