extend_path

dynare islm_var1_simul noclearall
clean_dynare('islm_var1_simul', 'temp', false)

dlmwrite('output/islm_var1_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/islm_var1_exo_names.txt',   M_.exo_names,  'delimiter', '')
dlmwrite('output/islm_var1_steady.csv', oo_.steady_state, 'precision', 16)
eigval = [real(oo_.dr.eigval), imag(oo_.dr.eigval)];
dlmwrite('output/islm_var1_eigval.csv', eigval, 'precision', 16)
dlmwrite('output/islm_var1_simul_endo.csv', oo_.endo_simul, 'precision', 16)
dlmwrite('output/islm_var1_simul_exo.csv', oo_.exo_simul, 'precision', 16)

