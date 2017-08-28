#include <stdarg.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include "call_R_function.h"

double* call_R_function(const char *func_name, int narg, ...) {

  // Intialisation of variables for calling using functions
  SEXP basePackage = PROTECT(eval(lang2( install("getNamespace"),
      ScalarString(mkChar("base"))), R_GlobalEnv));
  SEXP RCallBack = PROTECT(RCallBack = allocVector(LANGSXP, 3)); 
  SETCAR(RCallBack, findFun( install("do.call"), basePackage));  

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
  SEXP result = PROTECT(eval(RCallBack, basePackage));

  UNPROTECT(4);

  return(REAL(result));
}
