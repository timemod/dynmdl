var y y2 y3 y4;
varexo x;
parameters a b;

a = 0.25;
b = 0.7;

model;
y  = a * y(1) + b * y(-1) + x + 0.1 * y4;
y2 = 0.7 * y2(-1) + 0.1 * y(-1);
y3 = y2 + 4;
y4 = y3(1);
end;

initval;
x = 0;
y = 0;
end;
