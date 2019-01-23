extend_path

dynare toy_free noclearall

clean_dynare('toy_free', 'temp', false)

dlmwrite('output/toy_free_endo_names.txt',   M_.endo_names,  'delimiter', '')
eigval = [real(oo_.dr.eigval), imag(oo_.dr.eigval)];
dlmwrite('output/toy_free_eigval.csv', eigval, 'precision', 16)
dlmwrite('output/toy_free_steady.csv', oo_.steady_state, 'precision', 16)
