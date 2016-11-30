// error handling for dynr

#include <iostream>
using namespace std;

#ifdef USE_R
#include <Rcpp.h>
#endif
#include "dyn_error.hh"

void dyn_error(std::ostringstream &msg) {
    dyn_error(msg.str());
}

void dyn_error(std::string message) {
#ifdef USE_R
    Rf_error(message.c_str());
#else
    Cerr <<  message << endl;
    exit(EXIT_FAILURE)
#endif
}

void dyn_warning(std::ostringstream &msg) {
    dyn_warning(msg.str());
}

void dyn_warning(std::string message) {
#ifdef USE_R
    Rf_warning(message.c_str());
#else
    Cerr <<  message << endl;
#endif
}
