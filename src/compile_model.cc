#include <string>
#include <Rcpp.h>
#include  "parse.hh"

// [[Rcpp::export]]
Rcpp::List compile_model_(std::string modfile) {
    // the treatement of char in the next statement does not deserve a beauty
    // price
    ModFile *mod_file = parse((char *) modfile.c_str());
    
    Rcpp::List retval;
    retval =  mod_file->getModelListR();

    delete mod_file;

    return retval;
}
