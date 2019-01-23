extend_path

dynare islm_backwards_simul noclearall

clean_dynare('islm_backwards_simul', 'temp', false)

dlmwrite('output/islm_backwards_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/islm_backwards_exo_names.txt',   M_.exo_names,  'delimiter', '')
dlmwrite('output/islm_backwards_simul_endo.csv', oo_.endo_simul, 'precision', 16)
dlmwrite('output/islm_backwards_simul_exo.csv', oo_.exo_simul, 'precision', 16)

