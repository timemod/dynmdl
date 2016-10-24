// This handle contains a number of macros for handling communication with
// the outside world
#ifdef USE_R
#include <Rcpp.h>
#define dynout Rcpp::Rcout
#define dynerr Rcpp::Rcerr
#else
#define dynout std::cout
#define dynerr std::cerr
#endif

// dynexit:  print a message and return
#ifdef USE_R
#define dynexit(...) Rf_error(__VA_ARGS__)
#else
#define dynexit(...) std::fprintf(stderr, __VA_ARGS__); \
                     exit(EXIT_FAILURE)
#endif
