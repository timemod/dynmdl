@#include "../mod/islm_yearfit.mod"

steady;

% Observation in for yearly timeseries
shocks;
var fit_y_year;
periods 4;
values 1;
var y_year_exo; 
periods 4;
values 1275;
end;

simul(periods=18);
