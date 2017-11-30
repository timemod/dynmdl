@#include "../mod/islm_var1.mod"

initval;
y = 1200;
end;

endval;
y = 1250;
end;

steady;
check;

% Temp shock to government consumption
shocks;
var g; 
periods 1 2 3;
values 245 250 260;
end;

simul(periods=18);
