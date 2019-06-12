#include <Rcpp.h>
#include <iostream>
#include <map>
#include <vector>
#include "PolishModels.hh"
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
void prepare_internal_stat(int model_index, NumericVector exos,
                                NumericVector params) {

    PolishModel *mdl = PolishModels::get_static_model(model_index);
    mdl->set_param(REAL(params));
    mdl->set_exo(REAL(exos), 1);
    mdl->set_period_info(-1, -1);
}

// [[Rcpp::export]]
NumericVector get_residuals_stat(int model_index, NumericVector endos, 
                                 bool debug_eqs) {

    PolishModel *mdl = PolishModels::get_static_model(model_index);

    NumericVector res(endos.size());

    mdl->get_residuals(REAL(endos), REAL(res), 0, debug_eqs);

    return res;
}

// [[Rcpp::export]]
List get_triplet_jac_stat(int model_index, NumericVector endos, 
                          bool debug_eqs) {

    PolishModel *mdl = PolishModels::get_static_model(model_index);
        
    int njac = mdl->get_jac_count();

    IntegerVector rows(njac), cols(njac);
    NumericVector values(njac);

    mdl->get_jac(REAL(endos), INTEGER(rows), INTEGER(cols), REAL(values), 0, 
                debug_eqs);

    // add 1 because the index origin in R is 1
    rows = rows + 1;
    cols = cols + 1;

    return List::create(Rcpp::Named("rows") = rows, 
                        Rcpp::Named("cols") = cols,
                        Rcpp::Named("values") = values);
}
