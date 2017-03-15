// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// compile_model_
Rcpp::List compile_model_(std::string modfile, bool use_dll, std::string dll_dir);
RcppExport SEXP dynmdl_compile_model_(SEXP modfileSEXP, SEXP use_dllSEXP, SEXP dll_dirSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type modfile(modfileSEXP);
    Rcpp::traits::input_parameter< bool >::type use_dll(use_dllSEXP);
    Rcpp::traits::input_parameter< std::string >::type dll_dir(dll_dirSEXP);
    rcpp_result_gen = Rcpp::wrap(compile_model_(modfile, use_dll, dll_dir));
    return rcpp_result_gen;
END_RCPP
}
// compute_derivatives
Rcpp::List compute_derivatives(std::string modfile);
RcppExport SEXP dynmdl_compute_derivatives(SEXP modfileSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type modfile(modfileSEXP);
    rcpp_result_gen = Rcpp::wrap(compute_derivatives(modfile));
    return rcpp_result_gen;
END_RCPP
}
// get_residuals_
NumericVector get_residuals_(NumericVector endos, NumericVector icols, SEXP exo_data, SEXP params, Function f_dynamic, int n_endo, int nper, int max_lag);
RcppExport SEXP dynmdl_get_residuals_(SEXP endosSEXP, SEXP icolsSEXP, SEXP exo_dataSEXP, SEXP paramsSEXP, SEXP f_dynamicSEXP, SEXP n_endoSEXP, SEXP nperSEXP, SEXP max_lagSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type endos(endosSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type icols(icolsSEXP);
    Rcpp::traits::input_parameter< SEXP >::type exo_data(exo_dataSEXP);
    Rcpp::traits::input_parameter< SEXP >::type params(paramsSEXP);
    Rcpp::traits::input_parameter< Function >::type f_dynamic(f_dynamicSEXP);
    Rcpp::traits::input_parameter< int >::type n_endo(n_endoSEXP);
    Rcpp::traits::input_parameter< int >::type nper(nperSEXP);
    Rcpp::traits::input_parameter< int >::type max_lag(max_lagSEXP);
    rcpp_result_gen = Rcpp::wrap(get_residuals_(endos, icols, exo_data, params, f_dynamic, n_endo, nper, max_lag));
    return rcpp_result_gen;
END_RCPP
}
// get_triplet_jac
List get_triplet_jac(NumericVector endos, IntegerMatrix lead_lag_incidence, IntegerVector tshift, SEXP exo_data, SEXP params, Function jac_dynamic, int n_endo, int nper, int max_lag);
RcppExport SEXP dynmdl_get_triplet_jac(SEXP endosSEXP, SEXP lead_lag_incidenceSEXP, SEXP tshiftSEXP, SEXP exo_dataSEXP, SEXP paramsSEXP, SEXP jac_dynamicSEXP, SEXP n_endoSEXP, SEXP nperSEXP, SEXP max_lagSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type endos(endosSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type lead_lag_incidence(lead_lag_incidenceSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type tshift(tshiftSEXP);
    Rcpp::traits::input_parameter< SEXP >::type exo_data(exo_dataSEXP);
    Rcpp::traits::input_parameter< SEXP >::type params(paramsSEXP);
    Rcpp::traits::input_parameter< Function >::type jac_dynamic(jac_dynamicSEXP);
    Rcpp::traits::input_parameter< int >::type n_endo(n_endoSEXP);
    Rcpp::traits::input_parameter< int >::type nper(nperSEXP);
    Rcpp::traits::input_parameter< int >::type max_lag(max_lagSEXP);
    rcpp_result_gen = Rcpp::wrap(get_triplet_jac(endos, lead_lag_incidence, tshift, exo_data, params, jac_dynamic, n_endo, nper, max_lag));
    return rcpp_result_gen;
END_RCPP
}
// get_jac_backwards
List get_jac_backwards(NumericVector endos, NumericVector lags, NumericVector cols, SEXP exo_data, SEXP params, Function jac_dynamic, int it, int max_lag);
RcppExport SEXP dynmdl_get_jac_backwards(SEXP endosSEXP, SEXP lagsSEXP, SEXP colsSEXP, SEXP exo_dataSEXP, SEXP paramsSEXP, SEXP jac_dynamicSEXP, SEXP itSEXP, SEXP max_lagSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type endos(endosSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type lags(lagsSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type cols(colsSEXP);
    Rcpp::traits::input_parameter< SEXP >::type exo_data(exo_dataSEXP);
    Rcpp::traits::input_parameter< SEXP >::type params(paramsSEXP);
    Rcpp::traits::input_parameter< Function >::type jac_dynamic(jac_dynamicSEXP);
    Rcpp::traits::input_parameter< int >::type it(itSEXP);
    Rcpp::traits::input_parameter< int >::type max_lag(max_lagSEXP);
    rcpp_result_gen = Rcpp::wrap(get_jac_backwards(endos, lags, cols, exo_data, params, jac_dynamic, it, max_lag));
    return rcpp_result_gen;
END_RCPP
}
// run_macro
void run_macro(std::string modfile, std::string new_modfile);
RcppExport SEXP dynmdl_run_macro(SEXP modfileSEXP, SEXP new_modfileSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type modfile(modfileSEXP);
    Rcpp::traits::input_parameter< std::string >::type new_modfile(new_modfileSEXP);
    run_macro(modfile, new_modfile);
    return R_NilValue;
END_RCPP
}
