var y;
varexo x;
parameters a b;

a = 0.25;
b = 0.7;

model;
y  = a * y(1) + b * y(-1) + x;
end;

initval;
x = 0;
y = 0;
end;
