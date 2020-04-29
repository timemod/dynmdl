%Declaring variables
var c;
parameters c1 c2;

c1 = 4;
c2 = 0.5;

model;
c = c1 * c(-1) + c2 * c(-1)^2;
end;

initval;
c = 0;
end;
