var y1 y2 y3;
varexo x;

model;
y1 = linlog(x);
y2 = linlog(x, 1e-3);
y3 = log(abs(x + 1e-12));
end;

//write_latex_dynamic_model;
