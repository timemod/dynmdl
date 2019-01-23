extend_path

dynare islm_var2_simul noclearall
clean_dynare('islm_var2_simul', 'temp', false)

dlmwrite('output/islm_var2_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/islm_var2_exo_names.txt',   M_.exo_names,  'delimiter', '')
dlmwrite('output/islm_var2_steady.csv', oo_.steady_state, 'precision', 16)
eigval = [real(oo_.dr.eigval), imag(oo_.dr.eigval)];
dlmwrite('output/islm_var2_eigval.csv', eigval, 'precision', 16)
dlmwrite('output/islm_var2_simul_endo.csv', oo_.endo_simul, 'precision', 16)
dlmwrite('output/islm_var2_simul_exo.csv', oo_.exo_simul, 'precision', 16)

