%Declaring variables
var x, y ;       % endogenous variables
varexo a, b;               % exogenous variables

%Setting parameter values
parameters c0 c1;

c0 = 100; c1 = 0.28;

model;
#t = 2;
y = t^2 *x + x(-1)^2 + sin(a) + b;
x = x(1)^2 + a;
end;
