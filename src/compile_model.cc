#include <string>
#include "run_dynare.hh"

//' Compile a Dynare Model
//'
//' @param modfile The name of the model
//' @export
// [[Rcpp::export]]
int compile_model(std::string modfile) {
    return run_dynare((char *) modfile.c_str());
}
