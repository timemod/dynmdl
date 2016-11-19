@#include "../mod/NK_baseline.mod"

shocks;
var epsd; stderr exp(sigma_d);
var epsphi; stderr exp(sigma_phi);
var epsmu_I; stderr exp(sigma_mu);
var epsA; stderr exp(sigma_A);
var epsm; stderr exp(sigma_m);
end;

steady;
check;

stoch_simul(order=1,irf=20, nograph);
