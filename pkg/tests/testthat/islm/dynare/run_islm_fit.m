extend_path

dynare islm_fit noclearall

clean_dynare('islm_fit', 'temp', true)

dlmwrite('output/islm_fit_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/islm_fit_exo_names.txt',   M_.exo_names,  'delimiter', '')
dlmwrite('output/islm_fit_endo.csv', oo_.endo_simul)
dlmwrite('output/islm_fit_exo.csv', oo_.exo_simul)

