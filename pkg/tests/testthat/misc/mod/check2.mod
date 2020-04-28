%Declaring variables
var c d;
parameters c1 c2;
parameters d1 d2;

c1 = 4;
c2 = 0.5;

d1 = 0.99999999998;
d2 = 0.1;

model;
c = c1 * c(-1) + c2 * c(-1)^2;
d = d1 * d(-1) + d2 * d(-1)^2;
end;

initval;
c = 0;
d = 0;
end;
