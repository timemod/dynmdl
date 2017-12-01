extend_path

dynare islm_fit_if noclearall

clean_dynare('islm_fit_if', 'temp', true)

dlmwrite('output/islm_fit_if_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/islm_fit_if_exo_names.txt',   M_.exo_names,  'delimiter', '')
dlmwrite('output/islm_fit_if_simul_endo.csv', oo_.endo_simul)
dlmwrite('output/islm_fit_if_exo.csv', oo_.exo_simul)

