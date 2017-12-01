@#include "../mod_out/islm_var2_fit.mod"

steady;
check;

initval;
y = 6000;
end;

sigma_uc = 1;

% Temp shock to government consumption
shocks;
var g; 
periods 1 2 3;
values 245 250 260;
var c_exo;
periods 1;
values 6000;
var fit_c;
periods 1;
values 1;
end;

simul(periods=18);
