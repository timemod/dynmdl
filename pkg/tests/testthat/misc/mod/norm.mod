%Declaring variables
var y1 y2 y3 y4 y5;       % endogenous variables

external_function(name = pnorm, first_deriv_provided = dnorm, nargs = 3);

model;
y1 = normcdf(y1);
y2 = normcdf(y2, -0.1, 0.9);
y3 = normpdf(y3);
y4 = normpdf(y4, -0.1, 0.9);
y5 = pnorm(y5, -0.1, 0.9);
end;
