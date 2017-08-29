extend_path

dynare ifn_simul noclearall
clean_dynare('ifn_simul', 'temp', true)

dlmwrite('output/ifn_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/ifn_exo_names.txt',   M_.exo_names,  'delimiter', '')
dlmwrite('output/ifn_simul_endo.csv', oo_.endo_simul)
dlmwrite('output/ifn_simul_exo.csv', oo_.exo_simul)
