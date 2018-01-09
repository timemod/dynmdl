#include <Rinternals.h>
#include <Rdefines.h>
#include <string>

#include "CallRFunction.hh"
using std::string;

// TODO: use Rcpp to call R functions

static SEXP rcall_do_call, base_package;
static SEXP rcall_jacob_element, dynmdl_package;

void CallRFunction::init() {
  // Intialisation of variables for calling using functions
  base_package = PROTECT(eval(lang2( install("getNamespace"),
      ScalarString(mkChar("base"))), R_GlobalEnv));
  rcall_do_call = PROTECT(rcall_do_call = allocVector(LANGSXP, 3)); 
  SETCAR(rcall_do_call, findFun( install("do.call"), base_package));  

  /*
  dynmdl_package = PROTECT(eval(lang2( install("getNamespace"),
                           ScalarString(mkChar("dynmdl"))), R_GlobalEnv));
  rcall_jacob_element = PROTECT(rcall_jacob_element = allocVector(LANGSXP, 4)); 
  SETCAR(rcall_jacob_element, findFun(install("jacob_element"), dynmdl_package));  
  */
}

void CallRFunction::close() {
    //UNPROTECT(4);
    UNPROTECT(2);
}

double CallRFunction::call_function(string func_name, int narg, double *args) 
    const {

  // collect arguments
  SEXP arg_r = PROTECT(allocVector(VECSXP, narg));
  for (int i = 0; i < narg; i++) {
      SET_VECTOR_ELT(arg_r, i, ScalarReal(args[i]));
  }

  SETCADR(rcall_do_call, mkString(func_name.c_str()));
  SETCADDR(rcall_do_call, arg_r);

  // call R
  SEXP result_ = PROTECT(eval(rcall_do_call, base_package));

  double retval = REAL(result_)[0];
  UNPROTECT(2);
  return retval;
}
