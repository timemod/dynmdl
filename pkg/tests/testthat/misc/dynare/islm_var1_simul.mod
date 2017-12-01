@#include "../mod/islm_var1.mod"

steady;
check;

endval;
yd = 4800;
end;

% Temp shock to government consumption
shocks;
var g; 
periods 1 2 3;
values 245 250 260;
end;

simul(periods=18);
