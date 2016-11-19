extend_path

dynare islm_simul noclearall

clean_dynare('islm_simul', 'temp', true)

dlmwrite('output/islm_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/islm_exo_names.txt',   M_.exo_names,  'delimiter', '')
dlmwrite('output/islm_simul_endo.csv', oo_.endo_simul)
dlmwrite('output/islm_simul_exo.csv', oo_.exo_simul)

