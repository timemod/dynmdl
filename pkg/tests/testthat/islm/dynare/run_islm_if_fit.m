extend_path

dynare islm_if_fit noclearall

clean_dynare('islm_if_fit', 'temp', false)

dlmwrite('output/islm_if_fit_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/islm_if_fit_exo_names.txt',   M_.exo_names,  'delimiter', '')
dlmwrite('output/islm_if_fit_simul_endo.csv', oo_.endo_simul, 'precision', 16)
dlmwrite('output/islm_if_fit_exo.csv', oo_.exo_simul, 'precision', 16)

