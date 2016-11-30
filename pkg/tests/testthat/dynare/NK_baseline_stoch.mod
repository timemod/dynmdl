@#include "../mod/NK_baseline.mod"

shocks;
var epsd; stderr exp(sigma_d);
end;

steady(solve_algo = 1);
check;

stoch_simul(order=1,irf=20, nograph);
