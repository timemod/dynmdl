extend_path

dynare NK_baseline_stoch noclearall

clean_dynare('NK_baseline_stoch', 'temp', true)

stoch_simul_results = cell2mat(struct2cell(oo_.irfs));

dlmwrite('output/NK_baseline_param_names.txt',  M_.param_names, 'delimiter', '')
dlmwrite('output/NK_baseline_param_values.txt', M_.params)
dlmwrite('output/NK_baseline_endo_names.txt',   M_.endo_names,  'delimiter', '')
dlmwrite('output/NK_baseline_stoch_endo.csv', stoch_simul_results)

