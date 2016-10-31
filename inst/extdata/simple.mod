var y;
parameters a b;

a = 0.25;
b = 0.7;

model;
y  = a * y(1) + b * y(-1);
end;

initval;
y = 0;
end;
