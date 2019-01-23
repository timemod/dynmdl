function clean_dynare(name_mod_file, name_directory_results, varargin)

% Input argument 1: name of mod file, without filename extension
% Input argument 2: name of sub-directory for results and backup
% Input argument 3: logical indicating whether to delete results

% Temporarily rename two main files (main mod file and steady-state m file)
copyfile([name_mod_file,'.mod'],['temp ',name_mod_file,'.mod'])
try copyfile([name_mod_file,'_steadystate.m'],...
	['temp ',name_mod_file,'_steadystate.m']),
end

% Move files to sub-directory (including main mod file and steady-state m file)
movefile([name_mod_file,'*'],name_directory_results)

% Restore the names of the two main files in the working directory
movefile(['temp ',name_mod_file,'.mod'],[name_mod_file,'.mod'])
try movefile(['temp ',name_mod_file,'_steadystate.m'],...
	[name_mod_file,'_steadystate.m']),
end

% If requested, delete all the files created by Dynare
if nargin == 3 && islogical(varargin{1}) && varargin{1},
	rmdir(name_directory_results,'s')
end