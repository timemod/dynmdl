extend_path

dynare NK_baseline_stoch noclearall

clean_dynare('NK_baseline_stoch', 'temp', false)

stoch_simul_results = cell2mat(struct2cell(oo_.irfs));

dlmwrite('output/NK_baseline_stoch_endo.csv', stoch_simul_results, 'precision', 16)

