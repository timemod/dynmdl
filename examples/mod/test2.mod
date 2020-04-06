%Declaring variables
var a b;       % endogenous variables

model;
a = b(-1);
b = 3 * a;
end;
