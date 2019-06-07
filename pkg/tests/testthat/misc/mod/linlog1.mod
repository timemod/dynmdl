var y1 y2 y3;
varexo x;

parameters eps;
eps = 1e-3;


model;
y1 = linlog(x);
y2 = linlog(x, eps);
y3 = linlog(x, 0.1);
end;

initval;
 y1 = 1;
 y2 = 1;
 y3 = 1;
 x = 1;
end;
