#include <stdarg.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include "call_R_function.h"

static SEXP RCallBack, basePackage;

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


void call_R_function(const char *func_name, int narg, double *value,
                     double *jac, ...) {

  va_list ap;
  int i;

  // collect arguments
  va_start(ap, jac);
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
  
  if (isList(result_) || 1) {
      //Rprintf("result_ is a list\n");
      SEXP value_ = VECTOR_ELT(result_, 0);
      SEXP jac_ = VECTOR_ELT(result_, 1);
      *value = REAL(value_)[0];
      for (i = 0; i < length(jac_); i++) {
        jac[i] = REAL(jac_)[i];
      }
      // currently we do nothing with the gradient (if supplied)
  } else {
      //Rprintf("result_ is not a list\n");
      // the R function returns a single value
      *value = REAL(result_)[0];
  }

  UNPROTECT(2);
}

void call_R_function_jac(const char *func_name, int narg, double *jac, ...) {

  va_list ap;
  int i;

  // collect arguments
  va_start(ap, jac);
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

  // collect Jacobian (currently we do nothing with second derivatives)
  for (i = 0; i < length(result__); i++) {
      jac[i] = REAL(jac_)[i];
  }

  UNPROTECT(2);
}
