// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// compile_model_
Rcpp::List compile_model_(std::string modfile);
RcppExport SEXP dynparse_compile_model_(SEXP modfileSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type modfile(modfileSEXP);
    rcpp_result_gen = Rcpp::wrap(compile_model_(modfile));
    return rcpp_result_gen;
END_RCPP
}
