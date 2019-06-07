var y1 y2;

parameters eps;
eps = 1e-3;


%$fit$
varexo uy1; % fit instruments
%$endfit$


model;
0.5 * (y1 - 1) = linlog(y1, eps) + uy1;
2 * (y2 - 1) = linlog(y2);
end;

initval;
 y1 = 1;
 y2 = 1;
end;

//write_latex_dynamic_model;
