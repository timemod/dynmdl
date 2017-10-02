#include <math.h>
#include "getPowerDeriv.h"

/*
 * The k-th derivative of x^p
 */
double getPowerDeriv(double x, double p, int k) {
#ifdef _MSC_VER
# define nearbyint(x) (fabs((x)-floor(x)) < fabs((x)-ceil(x)) ? floor(x) : ceil(x))
#endif
  if ( fabs(x) < 1e-12 && p > 0 && k > p && fabs(p-nearbyint(p)) < 1e-12 )
    return 0.0;
  else
    {
      int i = 0;
      double dxp = pow(x, p-k);
      for (; i<k; i++)
        dxp *= p--;
      return dxp;
    }
}
