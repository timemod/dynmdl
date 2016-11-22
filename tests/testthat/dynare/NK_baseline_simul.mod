@#include "../mod/NK_baseline.mod"
    
shocks;
var epsd; 
periods 1;
values (exp(sigma_d));
var epsphi; 
periods 1;
values (exp(sigma_phi));
var epsmu_I; 
periods 1;
values (exp(sigma_mu));
var epsA; 
periods 1;
values (exp(sigma_A));
var epsm;
periods 1;
values (exp(sigma_m));
end;

steady(solve_algo = 1);
check;

simul(periods=19);
