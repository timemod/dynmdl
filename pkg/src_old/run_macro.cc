#include <string>
#include <Rcpp.h>
#include  "run_macro_.hh"

// [[Rcpp::export]]
void run_macro(std::string modfile, std::string new_modfile) {
    run_macro_((char *) modfile.c_str(), new_modfile);
}
