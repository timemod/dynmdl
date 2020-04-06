%Declaring variables
var a b c;       % endogenous variables

model;
a = 2 * a(-1);
b = 3 * b(1);
c = 4 * c(-1) + 5 * c(1);
end;


write_latex_dynamic_model;
