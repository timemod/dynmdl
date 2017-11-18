#include <string>
#include <Rcpp.h>
#include  "parse.hh"

// [[Rcpp::export]]
Rcpp::List compile_model_(std::string modfile, bool use_dll, 
                          std::string dll_dir, bool max_laglead_1) {
    // the treatement of char in the next statement does not deserve a beauty
    // price
    ModFile *mod_file = parse((char *) modfile.c_str(), max_laglead_1, false);
    
    Rcpp::List retval;
    retval =  mod_file->getModelListR();
        
    if (use_dll) {
        mod_file->writeCFilesForR(dll_dir);
    }

    delete mod_file;

    return retval;
}



