#include <string>
#include <Rcpp.h>
#include  "parse.hh"

// [[Rcpp::export]]
Rcpp::List compute_derivatives(std::string modfile) {
    // the treatement of char in the next statement does not deserve a beauty
    // price
    ModFile *mod_file = parse((char *) modfile.c_str(), true);
    
    Rcpp::List retval;
    retval =  mod_file->getDerivativeInfo();

    delete mod_file;

    return retval;
}
