@#include "../mod/islm_extfunc.mod"

steady;

initval;
y = 1200;
end;

endval;
y = 1210.381827;
end;

% Temp shock to government consumption
shocks;
var g; 
periods 1 2 3;
values 245 250 260;
end;

simul(periods=18);
