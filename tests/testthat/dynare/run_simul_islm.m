dynare islm_simul noclearall

clean_dynare('islm_simul', 'temp', true)

dlmwrite('output/islm_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/islm_simul.csv', oo_.endo_simul)

