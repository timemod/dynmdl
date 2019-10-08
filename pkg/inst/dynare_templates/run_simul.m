% alleen voor octave
if is_octave()
    pkg load io
end

dynare simul_islm

dlmwrite('output/simul_islm_endo_names.txt',   M_.endo_names,  'delimiter', '')
eigval = [real(oo_.dr.eigval), imag(oo_.dr.eigval)];
dlmwrite('output/simul_islm_eigval.csv', eigval, 'precision', 16)
dlmwrite('output/simul_islm_steady.csv', oo_.steady_state, 'precision', 16)
eigval = [real(oo_.dr.eigval), imag(oo_.dr.eigval)];
dlmwrite('output/simul_islm_endo.csv', oo_.endo_simul, 'precision', 16)
dlmwrite('output/simul_islm_exo.csv', oo_.exo_simul, 'precision', 16)

