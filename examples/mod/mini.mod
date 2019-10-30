%Declaring variables
var yd;       % endogenous variables
varexo t y;               % exogenous variables
parameters alpha;

alpha = 1;

model;
yd = y - alpha * t;
end;

initval;
y = 100;
yd = 100;
end;
