extend_path

dynare kern_10x10_trends noclearall

clean_dynare('kern_10x10_trends', 'temp', false)

dlmwrite('output/kern_10x10_trends_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/kern_10x10_trends_exo_names.txt',   M_.exo_names,  'delimiter', '')
eigval = [real(oo_.dr.eigval), imag(oo_.dr.eigval)];
dlmwrite('output/kern_10x10_trends_eigval.csv', eigval, 'precision', 16)
dlmwrite('output/kern_10x10_trends_steady.csv', oo_.steady_state, 'precision', 16)

