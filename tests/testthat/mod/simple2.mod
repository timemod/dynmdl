var y, yplus, ymin, exo;
varexo x;
parameters a b;

a = 0.25;
b = 0.7;

model;
y  = a * yplus + b * ymin + exo;
yplus = y(1);
ymin = y(-1);
exo = x;
end;
