#include <string>
#include <Rcpp.h>
#include  "parse.hh"

// [[Rcpp::export]]
Rcpp::List compute_derivatives(std::string modfile, std::string latex_basename,
                               Rcpp::CharacterVector instruments,
                               bool fixed_period, bool check_stat_eqs, bool latex, 
                               Rcpp::List latex_options) {

    OutputParameters output_params;
    double ndigits_latex = latex_options["ndigits"];
    bool par_as_num = latex_options["par_as_num"];
    output_params.set_ndigits_latex(ndigits_latex);
    output_params.set_par_as_num(par_as_num);


    // Compute the derivatives for the fit procedure (first order conditions).
   
    // The treatement of char in the next statement does not deserve a beauty
    // price
    ModFile *mod_file = parse((char *) modfile.c_str(), 
                              (char *) latex_basename.c_str(),
                              false, true, true, true, 0, false, false, latex, output_params);
    
    Rcpp::List retval;
    retval =  mod_file->getDerivativeInfo(instruments, fixed_period, check_stat_eqs);

    delete mod_file;

    return retval;
}
