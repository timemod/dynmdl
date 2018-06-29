extend_path

dynare islm_fit_exolag1 noclearall

clean_dynare('islm_fit_exolag1', 'temp', true)

dlmwrite('output/islm_fit_exolag1_exo_names.txt',   M_.exo_names,  'delimiter', '')
dlmwrite('output/islm_fit_exolag1_endo_names.txt',   M_.endo_names,  'delimiter', '')
eigval = [real(oo_.dr.eigval), imag(oo_.dr.eigval)];
dlmwrite('output/islm_fit_exolag1_eigval.csv', eigval)
dlmwrite('output/islm_fit_exolag1_steady.csv', oo_.steady_state)
dlmwrite('output/islm_fit_exolag1_simul_endo.csv', oo_.endo_simul)
dlmwrite('output/islm_fit_exolag1_simul_exo.csv', oo_.exo_simul)
