extend_path

dynare NK_baseline_simul noclearall

clean_dynare('NK_baseline_simul', 'temp', true)

dlmwrite('output/NK_baseline_param_names.txt',  M_.param_names, 'delimiter', '')
dlmwrite('output/NK_baseline_param_values.txt', M_.params)
dlmwrite('output/NK_baseline_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/NK_baseline_simul_endo.csv', oo_.endo_simul)
eigval = [real(oo_.dr.eigval), imag(oo_.dr.eigval)];
dlmwrite('output/NK_baseline_eigval.csv', eigval)
dlmwrite('output/NK_baseline_steady.csv', oo_.steady_state)

