% kernmodel voor bestudering steady state en inbouwen model-consistente verwachtingen



var  
y    $y$      %  gdp  
pi   $pi$
i
;

varexo 
u; 

parameters p_sigma p_beta p_kappa p_i1 p_i2;
 p_sigma  = .2;                
 p_kappa  = 2;   
 p_beta   = .95;
 p_i1     = 0;  p_i2     = 1; % i fixed
% p_i1     = 2 ; p_i2 = 0 ; % rente afhankelijk van inflatie
  
model;

y  = y(+1) - (i - pi(+1)) / p_sigma;
pi = p_beta * pi(+1) + p_kappa * y + u;
i  = p_i1 * pi + p_i2;  
end;

initval;
y = 0.1;
pi = 0.1;
i  = p_i1 * pi + p_i2;
u  = 0;


end;
% write_latex_dynamic_model ;

steady(maxit = 1000);
check;
