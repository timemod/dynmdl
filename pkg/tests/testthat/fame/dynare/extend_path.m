function extend_path()
    addpath utils
    if findstr(getenv('OS'), 'Windows_NT')
        addpath m:\p_dynare\dynare\4.5.6_optim_only\matlab
    end
