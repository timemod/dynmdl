extend_path

dynare islm_yearfit noclearall

clean_dynare('islm_yearfit', 'temp', false)

dlmwrite('output/islm_yearfit_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/islm_yearfit_exo_names.txt',   M_.exo_names,  'delimiter', '')
dlmwrite('output/islm_yearfit_simul_endo.csv', oo_.endo_simul, 'precision', 16)
dlmwrite('output/islm_yearfit_exo.csv', oo_.exo_simul, 'precision', 16)

