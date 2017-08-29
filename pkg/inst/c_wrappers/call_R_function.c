#include <stdarg.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include "call_R_function.h"


static SEXP RCallBack, basePackage;
static double* result;

void init_call_R(void) {
  // Intialisation of variables for calling using functions
  basePackage = PROTECT(eval(lang2( install("getNamespace"),
      ScalarString(mkChar("base"))), R_GlobalEnv));
  RCallBack = PROTECT(RCallBack = allocVector(LANGSXP, 3)); 
  SETCAR(RCallBack, findFun( install("do.call"), basePackage));  
}

void close_call_R(void) {
    UNPROTECT(2);
}


void call_R_function(const char *func_name, int narg, ...) {

  va_list ap;
  int i;

  // collect arguments
  va_start(ap, narg);
  SEXP args = PROTECT(allocVector(VECSXP, narg));
  for (i = 0; i < narg; i++) {
      double argval = va_arg(ap, double);
      SET_VECTOR_ELT(args, i, ScalarReal(argval));
  }
  va_end(ap);

  SETCADR(RCallBack, mkString(func_name));
  SETCADDR(RCallBack, args);

  // call R
  SEXP result_ = PROTECT(eval(RCallBack, basePackage));

  result = REAL(result_);

  UNPROTECT(2);
}

double get_result(int i) {
    return(result[i]);
}
