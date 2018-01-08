#include <stdarg.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include "call_R_function.h"

static SEXP rcall_do_call, base_package;
static SEXP rcall_jacob_element, dynmdl_package;

void init_call_R(void) {
  // Intialisation of variables for calling using functions
  base_package = PROTECT(eval(lang2( install("getNamespace"),
      ScalarString(mkChar("base"))), R_GlobalEnv));
  rcall_do_call = PROTECT(rcall_do_call = allocVector(LANGSXP, 3)); 
  SETCAR(rcall_do_call, findFun( install("do.call"), base_package));  

  dynmdl_package = PROTECT(eval(lang2( install("getNamespace"),
                           ScalarString(mkChar("dynmdl"))), R_GlobalEnv));
  rcall_jacob_element = PROTECT(rcall_jacob_element = allocVector(LANGSXP, 4)); 
  SETCAR(rcall_jacob_element, findFun(install("jacob_element"), dynmdl_package));  
}

void close_call_R(void) {
    UNPROTECT(4);
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

  SETCADR(rcall_do_call, mkString(func_name));
  SETCADDR(rcall_do_call, args);

  // call R
  SEXP result_ = PROTECT(eval(rcall_do_call, base_package));
  
  if (isNewList(result_)) {
      SEXP value_ = VECTOR_ELT(result_, 0);
      SEXP jac_ = VECTOR_ELT(result_, 1);
      *value = REAL(value_)[0];
      for (i = 0; i < length(jac_); i++) {
        jac[i] = REAL(jac_)[i];
      }
      // currently we do nothing with the gradient (if supplied)
  } else {
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

  SETCADR(rcall_do_call, mkString(func_name));
  SETCADDR(rcall_do_call, args);

  // call R
  SEXP result_ = PROTECT(eval(rcall_do_call, base_package));

  // collect Jacobian (currently we do nothing with second derivatives)
  for (i = 0; i < length(result_); i++) {
      jac[i] = REAL(result_)[i];
  }

  UNPROTECT(2);
}

void call_jacob_element(const char *func_name, int narg, int index, double *jac_elem, ...) {

  va_list ap;
  int i;

  // collect arguments
  va_start(ap, jac_elem);
  SEXP args = PROTECT(allocVector(REALSXP, narg));
  double *args_ = REAL(args);
  for (i = 0; i < narg; i++) {
      args_[i] = va_arg(ap, double);
  }
  va_end(ap);

  SETCADR(rcall_jacob_element, mkString(func_name));
  SETCADDR(rcall_jacob_element, ScalarInteger(index));
  SETCADDDR(rcall_jacob_element, args);

  // call R
  SEXP result_ = PROTECT(eval(rcall_jacob_element, dynmdl_package));

  // collect Jacobian (currently we do nothing with second derivatives)
  *jac_elem = REAL(result_)[0];

  UNPROTECT(2);
}
