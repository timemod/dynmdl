%Declaring variables

% endogenous variables
var y $Y$ (long_name = 'Income')
    yd $Y_d$ (long_name = 'Disposable income')
    t $T$ (long_name = 'Tax')
    c $C$ (long_name = 'Consumption')
    i $I$ (long_name = 'Investment')
    md $M_d$ (long_name = 'Monet demand')
    ms $M_s$ (long_name = 'Money supply')
    r $r$ (long_name = 'Interest rate');

% exogenous variables
varexo g $G$ (long_name = 'Government spending');

%$fit$
varexo ut uc umd ui;       % residuals
parameters sigma_ut sigma_uc sigma_ui sigma_umd;
sigma_ut = 7; sigma_uc = 5; sigma_ui = 21; sigma_umd = 21;
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

parameters p_ms;
p_ms = 230;

model;
y = c + i + g;
yd = y - t;
t = t0 + t1 * y + ut;
c = c0 + c1 * yd(-1) + c2 * yd + c3 * yd(+1) + c4 * r + c5 * r^2 + uc;
i = i0 + i1 * y(-1) + i2 * y + i3 * y(+1) + i4 * r + i5 * r^2 + ui;
md = m0 + m1 * y + m2 * r + m3 * r^2 + umd;
md = ms;
[static]
ms = p_ms;
[dynamic]
ms = ms(-1);
end;

initval;
g  = 240; ms = p_ms; r  = 3.5; y  = 980; c  = 500; t = 100;
md = ms;
yd = y - t;
i  = y - c - g;
end;
