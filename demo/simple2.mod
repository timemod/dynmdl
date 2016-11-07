var y1 y2;
varexo x1 x2;
parameters a b;

a = 0.25;
b = 0.7;

model;
y1  = a * y1(1) + b * y1(-1) + x1;
y2  = 1.01* a * y2(1) + 1.01 * b * y2(-1) + x2;
end;

initval;
x1 = 0;
y1 = 0;
x2 = 0;
y2 = 0;
end;
