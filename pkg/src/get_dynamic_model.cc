#include <string>
#include <Rcpp.h>
#include  "parse.hh"

// [[Rcpp::export]]
Rcpp::List get_dynamic_model(std::string modfile, std::string latex_basename) {

    // the treatement of char in the next statement does not deserve a beauty
    // price

    ModFile *mod_file = parse((char *) modfile.c_str(), 
                              (char *) latex_basename.c_str(),
                              false, true, true);

    Rcpp::List retval, model_list, equations;

    model_list =  mod_file->getModelListR(false, true);
    equations = mod_file->getDynamicModelEquations();

    return Rcpp::List::create(Rcpp::Named("var_list") = model_list,
                              Rcpp::Named("equations") = equations);
}
