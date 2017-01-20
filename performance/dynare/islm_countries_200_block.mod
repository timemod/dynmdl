@#include "block_mod/islm_countries_200.mod"

initval;
y_nl = 1300;
end;

simul(periods=18, maxit = 100, stack_solve_algo = 4);
