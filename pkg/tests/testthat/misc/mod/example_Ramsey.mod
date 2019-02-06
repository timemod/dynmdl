% Ramsey model from http://jeanpierre.laffargue.pagesperso-orange.fr/teaching/PPD/Chapter%207.pdf

varexo gx;
trend_var(growth_factor=gx) x;
var(deflator=x) c k;

% parameters
parameters alph gam delt bet a;

alph=0.5; 
gam=0.5; 
delt=0.02; 
bet=0.05; 
a=0.5; 

model;

% eq (1): equilibrium good markets
c + k - (1-delt)*k(-1)=a*(x^(1-alph))*k(-1)^alph; 

% eq (5): combi of FOC utility max. wrt c & k
c^(-gam) = (1+bet)^(-1)*(a*alph*(x(+1)^(1-alph))*k^(alph-1) + 1 - delt)*c(+1)^(-gam); 
end;

% steady state is solved analytically to get starting values (without growth); can be replaced by numerical values
initval; 
gx = 1.05;
k = ((delt+bet)/(1.0*a*alph))^(1/(alph-1)); 
c = a*k^alph-delt*k; 
end; 
