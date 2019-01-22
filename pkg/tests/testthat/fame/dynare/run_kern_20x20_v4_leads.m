extend_path

dynare kern_20x20_v4_leads noclearall

clean_dynare('kern_20x20_v4_leads', 'temp', true)

dlmwrite('output/kern_20x20_v4_leads_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/kern_20x20_v4_leads_exo_names.txt',   M_.exo_names,  'delimiter', '')
eigval = [real(oo_.dr.eigval), imag(oo_.dr.eigval)];
dlmwrite('output/kern_20x20_v4_leads_eigval.csv', eigval)
dlmwrite('output/kern_20x20_v4_leads_steady.csv', oo_.steady_state)
