var y1 y2 y3 y4;
varexo x;

parameters eps eps2;
eps = 1e-3;

model;
y1 = linlog(x);
y2 = linlog(x, eps);
y3 = log(abs(x) + 1e-12);
y4 = linlog(abs(x) + 1e-12, eps2);
end;

//write_latex_dynamic_model;
