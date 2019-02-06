%
% Status : main Dynare file
%
% Warning : this file is generated automatically by Dynare
%           from model file (.mod)

tic0 = tic;
% Save empty dates and dseries objects in memory.
dates('initialize');
dseries('initialize');
% Define global variables.
global M_ options_ oo_ estim_params_ bayestopt_ dataset_ dataset_info estimation_info ys0_ ex0_
options_ = [];
M_.fname = 'example_Ramsey';
M_.dynare_version = '4.5.6';
oo_.dynare_version = '4.5.6';
options_.dynare_version = '4.5.6';
%
% Some global variables initialization
%
global_initialization;
diary off;
diary('example_Ramsey.log');
M_.exo_names = 'gx';
M_.exo_names_tex = 'gx';
M_.exo_names_long = 'gx';
M_.endo_names = 'c';
M_.endo_names_tex = 'c';
M_.endo_names_long = 'c';
M_.endo_names = char(M_.endo_names, 'k');
M_.endo_names_tex = char(M_.endo_names_tex, 'k');
M_.endo_names_long = char(M_.endo_names_long, 'k');
M_.endo_partitions = struct();
M_.param_names = 'alph';
M_.param_names_tex = 'alph';
M_.param_names_long = 'alph';
M_.param_names = char(M_.param_names, 'gam');
M_.param_names_tex = char(M_.param_names_tex, 'gam');
M_.param_names_long = char(M_.param_names_long, 'gam');
M_.param_names = char(M_.param_names, 'delt');
M_.param_names_tex = char(M_.param_names_tex, 'delt');
M_.param_names_long = char(M_.param_names_long, 'delt');
M_.param_names = char(M_.param_names, 'bet');
M_.param_names_tex = char(M_.param_names_tex, 'bet');
M_.param_names_long = char(M_.param_names_long, 'bet');
M_.param_names = char(M_.param_names, 'a');
M_.param_names_tex = char(M_.param_names_tex, 'a');
M_.param_names_long = char(M_.param_names_long, 'a');
M_.param_partitions = struct();
M_.exo_det_nbr = 0;
M_.exo_nbr = 1;
M_.endo_nbr = 2;
M_.param_nbr = 5;
M_.orig_endo_nbr = 2;
M_.aux_vars = [];
M_.Sigma_e = zeros(1, 1);
M_.Correlation_matrix = eye(1, 1);
M_.H = 0;
M_.Correlation_matrix_ME = 1;
M_.sigma_e_is_diagonal = 1;
M_.det_shocks = [];
options_.block=0;
options_.bytecode=0;
options_.use_dll=0;
M_.hessian_eq_zero = 1;
erase_compiled_function('example_Ramsey_static');
erase_compiled_function('example_Ramsey_dynamic');
M_.orig_eq_nbr = 2;
M_.eq_nbr = 2;
M_.ramsey_eq_nbr = 0;
M_.set_auxiliary_variables = exist(['./' M_.fname '_set_auxiliary_variables.m'], 'file') == 2;
M_.lead_lag_incidence = [
 0 2 4;
 1 3 0;]';
M_.nstatic = 0;
M_.nfwrd   = 1;
M_.npred   = 1;
M_.nboth   = 0;
M_.nsfwrd   = 1;
M_.nspred   = 1;
M_.ndynamic   = 2;
M_.equations_tags = {
};
M_.static_and_dynamic_models_differ = 0;
M_.exo_names_orig_ord = [1:1];
M_.maximum_lag = 1;
M_.maximum_lead = 1;
M_.maximum_endo_lag = 1;
M_.maximum_endo_lead = 1;
oo_.steady_state = zeros(2, 1);
M_.maximum_exo_lag = 0;
M_.maximum_exo_lead = 1;
oo_.exo_steady_state = zeros(1, 1);
M_.params = NaN(5, 1);
M_.NNZDerivatives = [8; 0; -1];
M_.params( 1 ) = 0.5;
alph = M_.params( 1 );
M_.params( 2 ) = 0.5;
gam = M_.params( 2 );
M_.params( 3 ) = 0.02;
delt = M_.params( 3 );
M_.params( 4 ) = 0.05;
bet = M_.params( 4 );
M_.params( 5 ) = 0.5;
a = M_.params( 5 );
%
% INITVAL instructions
%
options_.initval_file = 0;
oo_.exo_steady_state( 1 ) = 1.05;
oo_.steady_state( 2 ) = ((M_.params(3)+M_.params(4))/(1.0*M_.params(5)*M_.params(1)))^(1/(M_.params(1)-1));
oo_.steady_state( 1 ) = M_.params(5)*oo_.steady_state(2)^M_.params(1)-M_.params(3)*oo_.steady_state(2);
if M_.exo_nbr > 0
	oo_.exo_simul = ones(M_.maximum_lag,1)*oo_.exo_steady_state';
end
if M_.exo_det_nbr > 0
	oo_.exo_det_simul = ones(M_.maximum_lag,1)*oo_.exo_det_steady_state';
end
steady;
oo_.dr.eigval = check(M_,options_,oo_);
%
% HISTVAL instructions
%
M_.endo_histval = zeros(M_.endo_nbr,M_.maximum_lag);
M_.exo_histval = zeros(M_.exo_nbr,M_.maximum_lag);
M_.exo_det_histval = zeros(M_.exo_det_nbr,M_.maximum_lag);
M_.endo_histval( 2, M_.maximum_lag + 0) = 8;
options_.periods = 100;
perfect_foresight_setup;
perfect_foresight_solver;
save('example_Ramsey_results.mat', 'oo_', 'M_', 'options_');
if exist('estim_params_', 'var') == 1
  save('example_Ramsey_results.mat', 'estim_params_', '-append');
end
if exist('bayestopt_', 'var') == 1
  save('example_Ramsey_results.mat', 'bayestopt_', '-append');
end
if exist('dataset_', 'var') == 1
  save('example_Ramsey_results.mat', 'dataset_', '-append');
end
if exist('estimation_info', 'var') == 1
  save('example_Ramsey_results.mat', 'estimation_info', '-append');
end
if exist('dataset_info', 'var') == 1
  save('example_Ramsey_results.mat', 'dataset_info', '-append');
end
if exist('oo_recursive_', 'var') == 1
  save('example_Ramsey_results.mat', 'oo_recursive_', '-append');
end


disp(['Total computing time : ' dynsec2hms(toc(tic0)) ]);
disp('Note: 1 warning(s) encountered in the preprocessor')
if ~isempty(lastwarn)
  disp('Note: warning(s) encountered in MATLAB/Octave code')
end
diary off
