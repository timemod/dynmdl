var y1 y2 y3;
varexo x;

parameters eps;
eps = 1e-3;

model;
y1 = linpow(x, 0.5);
y2 = linpow(x, 0.5, eps);
y3 = (abs(x) + 1e-12)^0.5;
end;

//write_latex_dynamic_model;
