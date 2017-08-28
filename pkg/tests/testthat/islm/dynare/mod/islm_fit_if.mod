%Declaring variables
var y yd c i md r t t_eq;       % endogenous variables
varexo g ms;               % exogenous variables

% Parameters for the standard deviation for the fit procedure:
parameters sigma_ut sigma_uc sigma_umd sigma_ui ;

var    ut uc umd ui;       % residuals
sigma_ut = 7; sigma_uc = 5; sigma_ui = 21; sigma_umd = 2;

%Setting parameter values
parameters c0 c1 c2 c3 c4 c5;
parameters i0 i1 i2 i3 i4 i5;
parameters m0 m1 m2 m3;
parameters t0 t1;

c0 = 100; c1 = 0.28; c2 = 0.32; c3 = 0.10; c4 = -20; c5 = 1;
i0 = 100; i1 = 0.12; i2 = 0.08; i3 = 0.04; i4 = -40; i5 = -1.5;
m0 = 75; m1 = 0.23; m2 = -35; m3 = -1.5;
t0 = -15; t1 = 0.22;

var l_1 l_2 l_3 l_4 l_5 l_6 l_7 l_8 ;
varexo fit_y fit_yd fit_c fit_i fit_md fit_r fit_t fit_t_eq ;
varexo y_exo yd_exo c_exo i_exo md_exo r_exo t_exo t_eq_exo ;

model;

% Model equations

t_eq = t0 + t1 * y;
% NOTE: for the Dynare version we use function min instead of if:
t = min(g + 10, t_eq) + ut;
y = c + i + g;
yd = y - t;
c = c0 + c1 * yd(-1) + c2 * yd + c3 * yd(+1) + c4 * r + c5 * r^2 + uc;
i = i0 + i1 * y(-1) + i2 * y + i3 * y(+1) + i4 * r + i5 * r^2 + ui;
md = m0 + m1 * y + m2 * r + m3 * r^2 + umd;
md = ms;

% First order condition the resisuals:

ut / sigma_ut^2 + l_2 * ((-1)) = 0;
uc / sigma_uc^2 + l_5 * ((-1)) = 0;
umd / sigma_umd^2 + l_7 * ((-1)) = 0;
ui / sigma_ui^2 + l_6 * ((-1)) = 0;

% First order conditions endogenous variables:

fit_y * ( y - y_exo ) + (1 - fit_y ) * ( l_6(1) * ((-i1)) + l_1 * ((-t1)) + l_3
    * (1) + l_4 * ((-1)) + l_6 * ((-i2)) + l_7 * ((-m1)) + l_6(-1) * ((-i3)) )
    = 0;
fit_yd * ( yd - yd_exo ) + (1 - fit_yd ) * ( l_5(1) * ((-c1)) + l_4 * (1) + l_5
    * ((-c2)) + l_5(-1) * ((-c3)) ) = 0;
fit_c * ( c - c_exo ) + (1 - fit_c ) * ( l_3 * ((-1)) + l_5 * (1) ) = 0;
fit_i * ( i - i_exo ) + (1 - fit_i ) * ( l_3 * ((-1)) + l_6 * (1) ) = 0;
fit_md * ( md - md_exo ) + (1 - fit_md ) * ( l_7 * (1) + l_8 * (1) ) = 0;
fit_r * ( r - r_exo ) + (1 - fit_r ) * ( l_5 * ((-(c4+c5*2*r))) + l_6 *
    ((-(i4+i5*2*r))) + l_7 * ((-(m2+m3*2*r))) ) = 0;
fit_t * ( t - t_exo ) + (1 - fit_t ) * ( l_2 * (1) + l_4 * (1) ) = 0;
fit_t_eq * ( t_eq - t_eq_exo ) + (1 - fit_t_eq ) * ( l_1 * (1) + l_2 *
    ((-(1-(t_eq>g+10)))) ) = 0;
end;

initval;
g  = 240; ms = 230; r  = 3.5; y  = 980; c  = 500;
md = ms;
yd = y - t;
i  = y - c - g;
end;
