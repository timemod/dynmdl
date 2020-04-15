// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// prepare_internal_dyn
void prepare_internal_dyn(int model_index, NumericVector exos, int nrow_exo, NumericVector params, int per_freq, int first_per_subp_count);
RcppExport SEXP _dynmdl_prepare_internal_dyn(SEXP model_indexSEXP, SEXP exosSEXP, SEXP nrow_exoSEXP, SEXP paramsSEXP, SEXP per_freqSEXP, SEXP first_per_subp_countSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type model_index(model_indexSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type exos(exosSEXP);
    Rcpp::traits::input_parameter< int >::type nrow_exo(nrow_exoSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type params(paramsSEXP);
    Rcpp::traits::input_parameter< int >::type per_freq(per_freqSEXP);
    Rcpp::traits::input_parameter< int >::type first_per_subp_count(first_per_subp_countSEXP);
    prepare_internal_dyn(model_index, exos, nrow_exo, params, per_freq, first_per_subp_count);
    return R_NilValue;
END_RCPP
}
// internal_dyn_set_exo
void internal_dyn_set_exo(int model_index, NumericVector exos, int nrow_exo);
RcppExport SEXP _dynmdl_internal_dyn_set_exo(SEXP model_indexSEXP, SEXP exosSEXP, SEXP nrow_exoSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type model_index(model_indexSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type exos(exosSEXP);
    Rcpp::traits::input_parameter< int >::type nrow_exo(nrow_exoSEXP);
    internal_dyn_set_exo(model_index, exos, nrow_exo);
    return R_NilValue;
END_RCPP
}
// get_residuals_dyn
NumericVector get_residuals_dyn(int model_index, NumericVector endos, NumericVector icols, int n_endo, int nper, int period_shift, bool debug_eqs);
RcppExport SEXP _dynmdl_get_residuals_dyn(SEXP model_indexSEXP, SEXP endosSEXP, SEXP icolsSEXP, SEXP n_endoSEXP, SEXP nperSEXP, SEXP period_shiftSEXP, SEXP debug_eqsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type model_index(model_indexSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type endos(endosSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type icols(icolsSEXP);
    Rcpp::traits::input_parameter< int >::type n_endo(n_endoSEXP);
    Rcpp::traits::input_parameter< int >::type nper(nperSEXP);
    Rcpp::traits::input_parameter< int >::type period_shift(period_shiftSEXP);
    Rcpp::traits::input_parameter< bool >::type debug_eqs(debug_eqsSEXP);
    rcpp_result_gen = Rcpp::wrap(get_residuals_dyn(model_index, endos, icols, n_endo, nper, period_shift, debug_eqs));
    return rcpp_result_gen;
END_RCPP
}
// get_triplet_jac_dyn
List get_triplet_jac_dyn(int model_index, NumericVector endos, IntegerMatrix lead_lag_incidence, IntegerVector tshift, int n_endo, int nper, int period_shift, bool debug_eqs);
RcppExport SEXP _dynmdl_get_triplet_jac_dyn(SEXP model_indexSEXP, SEXP endosSEXP, SEXP lead_lag_incidenceSEXP, SEXP tshiftSEXP, SEXP n_endoSEXP, SEXP nperSEXP, SEXP period_shiftSEXP, SEXP debug_eqsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type model_index(model_indexSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type endos(endosSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type lead_lag_incidence(lead_lag_incidenceSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type tshift(tshiftSEXP);
    Rcpp::traits::input_parameter< int >::type n_endo(n_endoSEXP);
    Rcpp::traits::input_parameter< int >::type nper(nperSEXP);
    Rcpp::traits::input_parameter< int >::type period_shift(period_shiftSEXP);
    Rcpp::traits::input_parameter< bool >::type debug_eqs(debug_eqsSEXP);
    rcpp_result_gen = Rcpp::wrap(get_triplet_jac_dyn(model_index, endos, lead_lag_incidence, tshift, n_endo, nper, period_shift, debug_eqs));
    return rcpp_result_gen;
END_RCPP
}
// get_jac_dyn
List get_jac_dyn(int model_index, NumericVector endos, int it, bool debug_eqs);
RcppExport SEXP _dynmdl_get_jac_dyn(SEXP model_indexSEXP, SEXP endosSEXP, SEXP itSEXP, SEXP debug_eqsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type model_index(model_indexSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type endos(endosSEXP);
    Rcpp::traits::input_parameter< int >::type it(itSEXP);
    Rcpp::traits::input_parameter< bool >::type debug_eqs(debug_eqsSEXP);
    rcpp_result_gen = Rcpp::wrap(get_jac_dyn(model_index, endos, it, debug_eqs));
    return rcpp_result_gen;
END_RCPP
}
// get_res_back_dyn
NumericVector get_res_back_dyn(int model_index, NumericVector endos, NumericVector lags, NumericVector leads, int it, bool debug_eqs);
RcppExport SEXP _dynmdl_get_res_back_dyn(SEXP model_indexSEXP, SEXP endosSEXP, SEXP lagsSEXP, SEXP leadsSEXP, SEXP itSEXP, SEXP debug_eqsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type model_index(model_indexSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type endos(endosSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type lags(lagsSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type leads(leadsSEXP);
    Rcpp::traits::input_parameter< int >::type it(itSEXP);
    Rcpp::traits::input_parameter< bool >::type debug_eqs(debug_eqsSEXP);
    rcpp_result_gen = Rcpp::wrap(get_res_back_dyn(model_index, endos, lags, leads, it, debug_eqs));
    return rcpp_result_gen;
END_RCPP
}
// get_jac_back_dyn
List get_jac_back_dyn(int model_index, NumericVector endos, NumericVector lags, NumericVector leads, NumericVector cols, int iper, bool debug_eqs);
RcppExport SEXP _dynmdl_get_jac_back_dyn(SEXP model_indexSEXP, SEXP endosSEXP, SEXP lagsSEXP, SEXP leadsSEXP, SEXP colsSEXP, SEXP iperSEXP, SEXP debug_eqsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type model_index(model_indexSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type endos(endosSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type lags(lagsSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type leads(leadsSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type cols(colsSEXP);
    Rcpp::traits::input_parameter< int >::type iper(iperSEXP);
    Rcpp::traits::input_parameter< bool >::type debug_eqs(debug_eqsSEXP);
    rcpp_result_gen = Rcpp::wrap(get_jac_back_dyn(model_index, endos, lags, leads, cols, iper, debug_eqs));
    return rcpp_result_gen;
END_RCPP
}
// prepare_internal_stat
void prepare_internal_stat(int model_index, NumericVector exos, NumericVector params);
RcppExport SEXP _dynmdl_prepare_internal_stat(SEXP model_indexSEXP, SEXP exosSEXP, SEXP paramsSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type model_index(model_indexSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type exos(exosSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type params(paramsSEXP);
    prepare_internal_stat(model_index, exos, params);
    return R_NilValue;
END_RCPP
}
// get_residuals_stat
NumericVector get_residuals_stat(int model_index, NumericVector endos, bool debug_eqs);
RcppExport SEXP _dynmdl_get_residuals_stat(SEXP model_indexSEXP, SEXP endosSEXP, SEXP debug_eqsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type model_index(model_indexSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type endos(endosSEXP);
    Rcpp::traits::input_parameter< bool >::type debug_eqs(debug_eqsSEXP);
    rcpp_result_gen = Rcpp::wrap(get_residuals_stat(model_index, endos, debug_eqs));
    return rcpp_result_gen;
END_RCPP
}
// get_triplet_jac_stat
List get_triplet_jac_stat(int model_index, NumericVector endos, bool debug_eqs);
RcppExport SEXP _dynmdl_get_triplet_jac_stat(SEXP model_indexSEXP, SEXP endosSEXP, SEXP debug_eqsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type model_index(model_indexSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type endos(endosSEXP);
    Rcpp::traits::input_parameter< bool >::type debug_eqs(debug_eqsSEXP);
    rcpp_result_gen = Rcpp::wrap(get_triplet_jac_stat(model_index, endos, debug_eqs));
    return rcpp_result_gen;
END_RCPP
}
// compile_model_
Rcpp::List compile_model_(std::string modfile, std::string latex_basename, bool use_dll, std::string dll_dir, bool max_laglead_1, bool strict, bool internal_calc, int n_fit_derivatives, bool warn_uninit_param, bool init_param_na, bool latex, Rcpp::List latex_options);
RcppExport SEXP _dynmdl_compile_model_(SEXP modfileSEXP, SEXP latex_basenameSEXP, SEXP use_dllSEXP, SEXP dll_dirSEXP, SEXP max_laglead_1SEXP, SEXP strictSEXP, SEXP internal_calcSEXP, SEXP n_fit_derivativesSEXP, SEXP warn_uninit_paramSEXP, SEXP init_param_naSEXP, SEXP latexSEXP, SEXP latex_optionsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type modfile(modfileSEXP);
    Rcpp::traits::input_parameter< std::string >::type latex_basename(latex_basenameSEXP);
    Rcpp::traits::input_parameter< bool >::type use_dll(use_dllSEXP);
    Rcpp::traits::input_parameter< std::string >::type dll_dir(dll_dirSEXP);
    Rcpp::traits::input_parameter< bool >::type max_laglead_1(max_laglead_1SEXP);
    Rcpp::traits::input_parameter< bool >::type strict(strictSEXP);
    Rcpp::traits::input_parameter< bool >::type internal_calc(internal_calcSEXP);
    Rcpp::traits::input_parameter< int >::type n_fit_derivatives(n_fit_derivativesSEXP);
    Rcpp::traits::input_parameter< bool >::type warn_uninit_param(warn_uninit_paramSEXP);
    Rcpp::traits::input_parameter< bool >::type init_param_na(init_param_naSEXP);
    Rcpp::traits::input_parameter< bool >::type latex(latexSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type latex_options(latex_optionsSEXP);
    rcpp_result_gen = Rcpp::wrap(compile_model_(modfile, latex_basename, use_dll, dll_dir, max_laglead_1, strict, internal_calc, n_fit_derivatives, warn_uninit_param, init_param_na, latex, latex_options));
    return rcpp_result_gen;
END_RCPP
}
// compute_derivatives
Rcpp::List compute_derivatives(std::string modfile, std::string latex_basename, Rcpp::CharacterVector instruments, bool fixed_period, bool latex, Rcpp::List latex_options);
RcppExport SEXP _dynmdl_compute_derivatives(SEXP modfileSEXP, SEXP latex_basenameSEXP, SEXP instrumentsSEXP, SEXP fixed_periodSEXP, SEXP latexSEXP, SEXP latex_optionsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type modfile(modfileSEXP);
    Rcpp::traits::input_parameter< std::string >::type latex_basename(latex_basenameSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type instruments(instrumentsSEXP);
    Rcpp::traits::input_parameter< bool >::type fixed_period(fixed_periodSEXP);
    Rcpp::traits::input_parameter< bool >::type latex(latexSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type latex_options(latex_optionsSEXP);
    rcpp_result_gen = Rcpp::wrap(compute_derivatives(modfile, latex_basename, instruments, fixed_period, latex, latex_options));
    return rcpp_result_gen;
END_RCPP
}
// get_residuals_
NumericVector get_residuals_(NumericVector endos, NumericVector icols, SEXP exo_data, SEXP params, Function f_dynamic, int n_endo, int nper, int period_shift);
RcppExport SEXP _dynmdl_get_residuals_(SEXP endosSEXP, SEXP icolsSEXP, SEXP exo_dataSEXP, SEXP paramsSEXP, SEXP f_dynamicSEXP, SEXP n_endoSEXP, SEXP nperSEXP, SEXP period_shiftSEXP) {
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
    Rcpp::traits::input_parameter< int >::type period_shift(period_shiftSEXP);
    rcpp_result_gen = Rcpp::wrap(get_residuals_(endos, icols, exo_data, params, f_dynamic, n_endo, nper, period_shift));
    return rcpp_result_gen;
END_RCPP
}
// get_triplet_jac
List get_triplet_jac(NumericVector endos, IntegerMatrix lead_lag_incidence, IntegerVector tshift, SEXP exo_data, SEXP params, Function jac_dynamic, int n_endo, int nper, int period_shift);
RcppExport SEXP _dynmdl_get_triplet_jac(SEXP endosSEXP, SEXP lead_lag_incidenceSEXP, SEXP tshiftSEXP, SEXP exo_dataSEXP, SEXP paramsSEXP, SEXP jac_dynamicSEXP, SEXP n_endoSEXP, SEXP nperSEXP, SEXP period_shiftSEXP) {
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
    Rcpp::traits::input_parameter< int >::type period_shift(period_shiftSEXP);
    rcpp_result_gen = Rcpp::wrap(get_triplet_jac(endos, lead_lag_incidence, tshift, exo_data, params, jac_dynamic, n_endo, nper, period_shift));
    return rcpp_result_gen;
END_RCPP
}
// get_jac_backwards
List get_jac_backwards(NumericVector endos, NumericVector lags, NumericVector leads, NumericVector cols, SEXP exo_data, SEXP params, Function jac_dynamic, int iper);
RcppExport SEXP _dynmdl_get_jac_backwards(SEXP endosSEXP, SEXP lagsSEXP, SEXP leadsSEXP, SEXP colsSEXP, SEXP exo_dataSEXP, SEXP paramsSEXP, SEXP jac_dynamicSEXP, SEXP iperSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type endos(endosSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type lags(lagsSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type leads(leadsSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type cols(colsSEXP);
    Rcpp::traits::input_parameter< SEXP >::type exo_data(exo_dataSEXP);
    Rcpp::traits::input_parameter< SEXP >::type params(paramsSEXP);
    Rcpp::traits::input_parameter< Function >::type jac_dynamic(jac_dynamicSEXP);
    Rcpp::traits::input_parameter< int >::type iper(iperSEXP);
    rcpp_result_gen = Rcpp::wrap(get_jac_backwards(endos, lags, leads, cols, exo_data, params, jac_dynamic, iper));
    return rcpp_result_gen;
END_RCPP
}
// run_macro
void run_macro(std::string modfile, std::string new_modfile);
RcppExport SEXP _dynmdl_run_macro(SEXP modfileSEXP, SEXP new_modfileSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type modfile(modfileSEXP);
    Rcpp::traits::input_parameter< std::string >::type new_modfile(new_modfileSEXP);
    run_macro(modfile, new_modfile);
    return R_NilValue;
END_RCPP
}
// serialize_polish_models
List serialize_polish_models(int model_index);
RcppExport SEXP _dynmdl_serialize_polish_models(SEXP model_indexSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type model_index(model_indexSEXP);
    rcpp_result_gen = Rcpp::wrap(serialize_polish_models(model_index));
    return rcpp_result_gen;
END_RCPP
}
// deserialize_polish_models
int deserialize_polish_models(List bin_data);
RcppExport SEXP _dynmdl_deserialize_polish_models(SEXP bin_dataSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type bin_data(bin_dataSEXP);
    rcpp_result_gen = Rcpp::wrap(deserialize_polish_models(bin_data));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_dynmdl_prepare_internal_dyn", (DL_FUNC) &_dynmdl_prepare_internal_dyn, 6},
    {"_dynmdl_internal_dyn_set_exo", (DL_FUNC) &_dynmdl_internal_dyn_set_exo, 3},
    {"_dynmdl_get_residuals_dyn", (DL_FUNC) &_dynmdl_get_residuals_dyn, 7},
    {"_dynmdl_get_triplet_jac_dyn", (DL_FUNC) &_dynmdl_get_triplet_jac_dyn, 8},
    {"_dynmdl_get_jac_dyn", (DL_FUNC) &_dynmdl_get_jac_dyn, 4},
    {"_dynmdl_get_res_back_dyn", (DL_FUNC) &_dynmdl_get_res_back_dyn, 6},
    {"_dynmdl_get_jac_back_dyn", (DL_FUNC) &_dynmdl_get_jac_back_dyn, 7},
    {"_dynmdl_prepare_internal_stat", (DL_FUNC) &_dynmdl_prepare_internal_stat, 3},
    {"_dynmdl_get_residuals_stat", (DL_FUNC) &_dynmdl_get_residuals_stat, 3},
    {"_dynmdl_get_triplet_jac_stat", (DL_FUNC) &_dynmdl_get_triplet_jac_stat, 3},
    {"_dynmdl_compile_model_", (DL_FUNC) &_dynmdl_compile_model_, 12},
    {"_dynmdl_compute_derivatives", (DL_FUNC) &_dynmdl_compute_derivatives, 6},
    {"_dynmdl_get_residuals_", (DL_FUNC) &_dynmdl_get_residuals_, 8},
    {"_dynmdl_get_triplet_jac", (DL_FUNC) &_dynmdl_get_triplet_jac, 9},
    {"_dynmdl_get_jac_backwards", (DL_FUNC) &_dynmdl_get_jac_backwards, 8},
    {"_dynmdl_run_macro", (DL_FUNC) &_dynmdl_run_macro, 2},
    {"_dynmdl_serialize_polish_models", (DL_FUNC) &_dynmdl_serialize_polish_models, 1},
    {"_dynmdl_deserialize_polish_models", (DL_FUNC) &_dynmdl_deserialize_polish_models, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_dynmdl(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
