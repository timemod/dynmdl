#include <string>
#include <Rcpp.h>
#include  "parse.hh"

// [[Rcpp::depends(Rcereal)]]
// [[Rcpp::depends(BH)]]
//
// Enable C++11 via this plugin 
// [[Rcpp::plugins("cpp11")]]

// [[Rcpp::export]]
Rcpp::List compile_model_(std::string modfile, std::string latex_basename,
                          bool use_dll, std::string dll_dir, bool max_laglead_1, 
                          bool nostrict, bool internal_calc, int n_fit_derivatives,
                          bool warn_uninit_param, bool par_const) {

    // the treatement of char in the next statement does not deserve a beauty
    // price
    bool no_tmp_terms = internal_calc;
    ModFile *mod_file = parse((char *) modfile.c_str(), 
                              (char *) latex_basename.c_str(),
                              max_laglead_1, nostrict, no_tmp_terms, 
                              n_fit_derivatives, warn_uninit_param, par_const);
    
    Rcpp::List retval;
    retval =  mod_file->getModelListR(internal_calc);
        
    if (use_dll) {
        mod_file->writeCFilesForR(dll_dir);
    }

    delete mod_file;

    return retval;
}



