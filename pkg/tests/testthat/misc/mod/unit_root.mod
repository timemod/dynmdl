var x1, x2 x3;
varexo eps1, eps2;

model;
x1 = x1(-1) + eps1;
x2 = 0.5 * x2(-1) + eps2;
x3 = 0.5 * x3(-1) * x2;
end;

initval;
x1 = 2;
x2 = 0.5;
end;

