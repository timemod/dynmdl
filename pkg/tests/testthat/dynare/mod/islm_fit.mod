% A version of the ISLM model with leads, including the equation for the 
% fit procedure with the maximum likelihood method. All endogenous variables
% can be a fit target.

%declaring variables
var y yd t c i md r; %endogenous variables
varexo g ms; %exogenous variables
var ut uc ui umd; %residuals (endogenous)
%Lagrangian multipliers (one for each model equation):
var ly lyd lt lc li lmd lr; 
%dummy indicating conditioning period:
varexo fit_y fit_yd fit_t fit_c fit_i fit_md fit_r; 
%values for conditioning var in conditioning period:
varexo y_exo yd_exo c_exo i_exo t_exo md_exo r_exo; 

%Setting parameter values
parameters c0 c1 c2 c3 c4 c5;
parameters i0 i1 i2 i3 i4 i5;
parameters m0 m1 m2 m3;
parameters t0 t1;
parameters qt qc qi qmd; %standard deviations of residuals
c0 = 100; c1 = 0.28; c2 = 0.32; c3 = 0.10; c4 = -20; c5 = 1;
i0 = 100; i1 = 0.12; i2 = 0.08; i3 = 0.04; i4 = -40; i5 = -1.5;
m0 = 75; m1 = 0.23; m2 = -35; m3 = -1.5;
t0 = -15; t1 = 0.22;
qt = 7; qc = 5; qi = 21; qmd = 2;

model;

%Model equations:
y = c + i + g;
yd = y - t;
t = t0 + t1 * y + ut;
c = c0 + c1 * yd(-1) + c2 * yd + c3 * yd(+1) + c4 * r + c5 * r^2 + uc;
i = i0 + i1 * y(-1) + i2 * y + i3 * y(+1) + i4 * r + i5 * r^2 + ui;
md = m0 + m1 * y + m2 * r + m3 * r^2 + umd;
md = ms;

%First-order conditions with respect to residuals:
ut / qt^2 = lt ;
uc / qc^2 = lc ;
ui / qi^2 = li ;
umd / qmd^2 = lmd;

%First-order conditions with respect to model variables:
fit_y  * (y   - y_exo)  + (1 - fit_y)  * (- ly + lyd + t1 * lt + i1 * li(+1) +
    i2 * li + i3 * li(-1) + m1 * lmd) = 0;

fit_yd * (yd - yd_exo)  + (1 - fit_yd) * (- lyd + c1 * lc(+1) + c2 * lc +
    c3 * lc(-1)) = 0;

fit_c  * (c  -  c_exo)  + (1 - fit_c)  * (ly - lc) = 0;

fit_i  * (i  -  i_exo)  + (1 - fit_i)  * (ly - li) = 0;

fit_md * (md - md_exo)  + (1 - fit_md) * (- lmd - lr) = 0;

fit_r  * (r  -  r_exo)  + (1 - fit_r)  * (( c4 + 2 * c5 * r ) * lc + 
    ( i4 + 2 * i5 * r ) * li + ( m2 + 2 * m3 * r ) * lmd) = 0;

fit_t * ( t - t_exo ) + ( 1 - fit_t) * ( - lyd - lt ) = 0;
end;

initval;
g  = 240; ms = 230; r  = 3.5; y  = 980; c  = 500; t  = 100;
md = ms; yd = y - t; i  = y - c - g;
end;
