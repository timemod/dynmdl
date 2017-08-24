extend_path

dynare islm_extfunc noclearall

clean_dynare('islm_extfunc', 'temp', true)

%dlmwrite('output/islm_endo_names.txt',   M_.endo_names,  'delimiter', '')
%dlmwrite('output/islm_exo_names.txt',   M_.exo_names,  'delimiter', '')
%dlmwrite('output/islm_extfunc_endo.csv', oo_.endo_simul)
%dlmwrite('output/islm_extfunc_exo.csv', oo_.exo_simul)

