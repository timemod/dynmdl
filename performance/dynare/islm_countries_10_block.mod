@#include "block_mod/islm_countries_100.mod"

initval;
y_co_1 = 1300;
end;

simul(periods=18, maxit = 100, stack_solve_algo = 4);
