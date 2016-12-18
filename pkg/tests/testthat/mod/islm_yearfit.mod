%declaring variables
var y yd t c i md r, y_year; %endogenous variables
varexo g ms; %exogenous variables
var ut uc ui umd; %residuals (as var instead of varexo)
var ly lyd lt lc li lmd lr ly_year; %Lagrangian multipliers (one for each model equation)
varexo fit_y_year; %dummy indicating conditioning period
varexo y_year_exo;  %values for conditioning var in conditioning period

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

%Model equations
y = c + i + g;
yd = y - t;
t = t0 + t1 * y + ut;
c = c0 + c1 * yd(-1) + c2 * yd + c3 * yd(+1) + c4 * r + c5 * r^2 + uc;
i = i0 + i1 * y(-1) + i2 * y + i3 * y(+1) + i4 * r + i5 * r^2 + ui;
md = m0 + m1 * y + m2 * r + m3 * r^2 + umd;
md = ms;

% yearly average
y_year = 0.25 * (y + y(-1) + y(-2) + y(-3));

%First-order conditions with respect to residuals
ut / qt^2 = lt ;
uc / qc^2 = lc ;
ui / qi^2 = li ;
umd / qmd^2 = lmd;

%First-order conditions with respect to model variables
fit_y_year  * (y_year   - y_year_exo)  + (1 - fit_y_year)  * (- ly_year) = 0;

(- ly + lyd + t1 * lt + i1 * li(+1) + i2 * li + i3 * li(-1) + m1 * lmd
    + 0.25 * (ly_year + ly_year(+1) + ly_year(+2) + ly_year(+3))) = 0;
(- lyd + c1 * lc(+1) + c2 * lc + c3 * lc(-1)) = 0;
(ly - lc) = 0;
ly - li = 0;
(- lmd - lr) = 0;
(( c4 + 2 * c5 * r ) * lc + ( i4 + 2 * i5 * r ) * li +
( m2 + 2 * m3 * r ) * lmd) = 0;
( - lyd - lt ) = 0; %dummy trick
end;

initval;
g = 240; ms = 230; 
md = ms;
y = 1000; %initial guess
t = t0 + t1 * y;
yd = y - t;
r = ( md - m0 - m1 * y ) / m2; %ignoring quadratic term
c = c0 + ( c1 + c2 + c3 ) * yd + c4 * r + c5 * r^2;
i = i0 + ( i1 + i2 + i3 ) * y + i4 * r + i5 * r^2;
ut = 0; uc = 0; ui = 0; umd = 0;
ly = 0; lyd = 0; lt = 0; lc = 0; li = 0; lmd = 0;
lr = 0; ly_year = 0;
fit_y_year = 0; 
y_year_exo = y;
end;
