extend_path

dynare example_Ramsey noclearall nostrict

clean_dynare('example_Ramsey', 'temp', false)

dlmwrite('output/example_Ramsey_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/example_Ramsey_exo_names.txt',   M_.exo_names,  'delimiter', '')
dlmwrite('output/example_Ramsey_simul_endo.csv', oo_.endo_simul, 'precision', 16)
dlmwrite('output/example_Ramsey_simul_exo.csv', oo_.exo_simul, 'precision', 16)
eigval = [real(oo_.dr.eigval), imag(oo_.dr.eigval)];
dlmwrite('output/example_Ramsey_eigval.csv', eigval, 'precision', 16)
dlmwrite('output/example_Ramsey_steady.csv', oo_.steady_state, 'precision', 16)

