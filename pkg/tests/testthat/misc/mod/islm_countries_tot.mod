tot_imp = 0
@#for co in countries
	+ imp_@{co}
@#endfor
;

tot_x = 0
@#for co in countries
	+ x_@{co}
@#endfor
;

% import == export
tot_imp = tot_x;
