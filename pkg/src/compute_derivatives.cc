#include <string>
#include <Rcpp.h>
#include  "parse.hh"

// [[Rcpp::export]]
Rcpp::List compute_derivatives(std::string modfile, std::string latex_basename,
                               Rcpp::CharacterVector instruments,
                               bool fixed_period) {

    // Compute the derivatives for the fit procedure (first order conditions).
   
    // The treatement of char in the next statement does not deserve a beauty
    // price
    OutputParameters dum_output_params;
    ModFile *mod_file = parse((char *) modfile.c_str(), 
                              (char *) latex_basename.c_str(),
                              false, true, true, 0, false, dum_output_params);
    
    Rcpp::List retval;
    retval =  mod_file->getDerivativeInfo(instruments, fixed_period);

    delete mod_file;

    return retval;
}
