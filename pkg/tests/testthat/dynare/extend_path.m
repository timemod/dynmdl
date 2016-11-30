function extend_path()
    addpath utils
    if findstr(getenv('OS'), 'Windows-NT') 
        addpath m:\a_io\private\rvh\matlab\dynare\4.4.3\matlab
    end
