extend_path

dynare islm_var3_simul noclearall
clean_dynare('islm_var3_simul', 'temp', true)

dlmwrite('output/islm_var3_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/islm_var3_exo_names.txt',   M_.exo_names,  'delimiter', '')
dlmwrite('output/islm_var3_steady.csv', oo_.steady_state)
eigval = [real(oo_.dr.eigval), imag(oo_.dr.eigval)];
dlmwrite('output/islm_var3_eigval.csv', eigval)
dlmwrite('output/islm_var3_simul_endo.csv', oo_.endo_simul)
dlmwrite('output/islm_var3_simul_exo.csv', oo_.exo_simul)
