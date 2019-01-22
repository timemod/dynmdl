@#include "mod/islm_fit.mod"

steady;

check;

% Observation in for yearly timeseries
shocks;
var fit_y;
periods 1 2 3;
values 1 1 1;
var y_exo; 
periods 1 2 3;
values 1250 1255 1260;
var fit_t;
periods 1 2;
values 1 1;
var t_exo; 
periods 1 2;
values 250 255;
end;

simul(periods=18);
