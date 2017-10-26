%Declaring variables
var y yd c i md r t;       % endogenous variables
varexo g ms;               % exogenous variables

%$fit$
varexo ut uc umd ui;       % fit instruments
parameters sigma_ut sigma_uc sigma_ui;
sigma_ut = 7; sigma_uc = 5; sigma_ui = 21;
%$endfit$

%Setting parameter values
parameters c0 c1 c2 c3 c4 c5;
parameters i0 i1 i2 i3 i4 i5;
parameters m0 m1 m2 m3;
parameters t0 t1;

c0 = 100; c1 = 0.28; c2 = 0.32; c3 = 0.10; c4 = -20; c5 = 1;
i0 = 100; i1 = 0.12; i2 = 0.08; i3 = 0.04; i4 = -40; i5 = -1.5;
m0 = 75; m1 = 0.23; m2 = -35; m3 = -1.5;
t0 = -15; t1 = 0.22;

model;
t = t0 + t1 * y + ut;
y = c + i + g;
yd = y - t;
c = c0 + c1 * yd(-1) + c2 * yd + c3 * yd(+1) + c4 * r + c5 * r^2 + uc;
i = i0 + i1 * y(-1) + i2 * y + i3 * y(+1) + i4 * r + i5 * r^2 + ui;
md = m0 + m1 * y + m2 * r + m3 * r^2 + umd;
md = ms;
end;

initval;
g  = 240; ms = 230; r  = 3.5; y  = 980; c  = 500; t = 100;
md = ms;
yd = y - t;
i  = y - c - g;
end;
