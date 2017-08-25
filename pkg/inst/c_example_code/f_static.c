#include <math.h>
#include <stdlib.h>
#include <Rinternals.h>
#include <Rdefines.h>

    
void f_static(double *y) {

  // Intialisation of variables for calling using functions
  SEXP basePackage = PROTECT(eval(lang2( install("getNamespace"),
      ScalarString(mkChar("base")) ),
      R_GlobalEnv));
  SEXP RCallBack = PROTECT(RCallBack = allocVector(LANGSXP, 3)); 
  SETCAR(RCallBack, findFun( install("do.call"), basePackage));  

  // call multiply
  SEXP args = PROTECT(allocVector(VECSXP, 2));
  SET_VECTOR_ELT(args, 0, ScalarReal(y[0]));
  SET_VECTOR_ELT(args, 1, ScalarReal(y[1]));

  SETCADR(RCallBack, mkString("multiply"));
  SETCADDR(RCallBack, args);

  SEXP result = PROTECT(eval(RCallBack, basePackage));
  Rprintf("\n\nResult of multiply: %g\n", asReal(result));

  UNPROTECT(2);

  // call multiply3
  args = PROTECT(allocVector(VECSXP, 3));
  SET_VECTOR_ELT(args, 0, ScalarReal(y[0]));
  SET_VECTOR_ELT(args, 1, ScalarReal(y[1]));
  SET_VECTOR_ELT(args, 2, ScalarReal(y[2]));

  SETCADR(RCallBack, mkString("multiply3"));
  SETCADDR(RCallBack, args);

  result = PROTECT(eval(RCallBack, basePackage));
  Rprintf("\n\nResult of multiply3: %g\n", asReal(result));

  UNPROTECT(2);

  Rprintf("\ny[0] = %g\n", y[0]);

  UNPROTECT(2);
  return;
}
