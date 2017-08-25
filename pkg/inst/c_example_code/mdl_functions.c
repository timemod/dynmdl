#include <R.h>
#include <Rinternals.h>

void f_static(double *y);

SEXP f_static_(SEXP y) {

  SEXP statsPackage;
  PROTECT(
    statsPackage = eval( lang2( install("getNamespace"),
      ScalarString(mkChar("stats")) ),
      R_GlobalEnv
    )   
  );  

  SEXP RCallBack;
  PROTECT( RCallBack = allocVector(LANGSXP, 4 )); 
  SETCAR( RCallBack,
    findFun( install("runif"), statsPackage )
  );  

  SEXP n, min, max;
  n = ScalarInteger(3);
  min = ScalarInteger(-4);
  max = ScalarInteger(4);

  SETCADR( RCallBack, n );
  SET_TAG( CDR( RCallBack ), install("n") );

  SETCADDR( RCallBack, min );
  SET_TAG( CDDR( RCallBack ), install("min") );

  SETCADDDR( RCallBack, max );
  SET_TAG( CDR(CDDR( RCallBack )), install("max"));

  SEXP randoms;
  PROTECT(
    randoms = eval( RCallBack, statsPackage )
  );  

  double *val = REAL(randoms);
  int nn = length(randoms);
  int i;
  Rprintf("\n");
  for (i = 0; i < nn; i++) {
      Rprintf("value = %g\n", val[i]);
  }

  UNPROTECT(3);

  f_static(REAL(y));

  return R_NilValue;
}
