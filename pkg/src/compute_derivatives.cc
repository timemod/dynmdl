#include <string>
#include <Rcpp.h>
#include  "parse.hh"

// [[Rcpp::export]]
Rcpp::List compute_derivatives(std::string modfile, std::string latex_basename) {

    // Compute the derivatives for the fit procedure (first order conditions).
   
    // The treatement of char in the next statement does not deserve a beauty
    // price
    ModFile *mod_file = parse((char *) modfile.c_str(), 
                              (char *) latex_basename.c_str(),
                              false, true, true, 0, false);
    
    Rcpp::List retval;
    retval =  mod_file->getDerivativeInfo();

    delete mod_file;

    return retval;
}
