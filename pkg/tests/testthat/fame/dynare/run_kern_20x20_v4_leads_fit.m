extend_path

dynare kern_20x20_v4_leads_fit noclearall

clean_dynare('kern_20x20_v4_leads_fit', 'temp', false)

dlmwrite('output/kern_20x20_v4_leads_fit_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/kern_20x20_v4_leads_fit_exo_names.txt',   M_.exo_names,  'delimiter', '')
eigval = [real(oo_.dr.eigval), imag(oo_.dr.eigval)];
dlmwrite('output/kern_20x20_v4_leads_fit_eigval.csv', eigval, 'precision', 16)
dlmwrite('output/kern_20x20_v4_leads_fit_steady.csv', oo_.steady_state, 'precision', 16)
