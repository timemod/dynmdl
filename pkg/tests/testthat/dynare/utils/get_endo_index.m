function index = get_endo_index(name)
    global M_
    for i = 1:size(M_.endo_names,1)
        if strcmp(strtrim(M_.endo_names(i, :)), name)
            index = i;
	    break
        end
    end
end
