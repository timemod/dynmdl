var y1 y2;
varexo x1 x2;
parameters a1 b1 c1 a2 b2 c2;

a1 = 0.25;
b2 = 0.7;
c1 = 0.1;
a2 = 0.4;
b2 = 0.5;
c2 = 0.2;

model;
y1  = a1 * y1(1) + b1 * y1(-1) + c1 * y2 + x1;
y2  = a2 * y2(1) + b2 * y2(-1) + c2 * y1 + x1;
end;
