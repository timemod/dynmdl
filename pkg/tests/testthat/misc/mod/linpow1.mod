var y1 y2 y3;
varexo x;

parameters eps;
eps = 1e-3;


model;
y1 = linpow(x, 0.33);
y2 = linpow(x, 0.33, eps);
y3 = linpow(x, 0.33, 0.1);
end;

initval;
 y1 = 1;
 y2 = 1;
 y3 = 1;
 x = 1;
end;
