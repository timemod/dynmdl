var y0 y1 y2;

parameters eps;
eps = 1e-3;

model;
0.5 * (y0 - 1) = linlog(y0);
0.5 * (y1 - 1) = linlog(y1);
0.5 * (y2 - 1) = linlog(y2, eps);
end;

initval;
 y0 = 1;
 y1 = 2;
 y2 = 2;
end;

//write_latex_dynamic_model;
