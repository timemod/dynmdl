#ifdef USE_R
#include <Rcpp.h>
using Rcpp::Rcout;
using Rcpp::Rcerr;
#define DynOut Rcout
#define DynErr Rcerr
#else
#define DynOut cout
#define DynErr cerr
#endif
