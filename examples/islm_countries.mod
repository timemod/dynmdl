@#define countries = ["nl", "uk", "be", "ge", "fr", "es", "dk", "us", "it", "ch"]

@#for co in countries
var y_@{co} yd_@{co} t_@{co} c_@{co} i_@{co} md_@{co} r_@{co}
    x_@{co} imp_@{co};
varexo g_@{co} ms_@{co};              
@#endfor

fit;
@#for co in countries
residuals ut_@{co} ui_@{co} uc_@{co} umd_@{co};
sigma_ut_@{co} = 6; sigma_uc_@{co} = 5; sigma_ui_@{co} = 21; sigma_umd_@{co} = 2;
@#endfor
end;

@#for co in countries
parameters c0_@{co} c1_@{co} c2_@{co} c3_@{co} c4_@{co} c5_@{co};
parameters i0_@{co} i1_@{co} i2_@{co} i3_@{co} i4_@{co} i5_@{co};
parameters m0_@{co} m1_@{co} m2_@{co} m3_@{co};
parameters t0_@{co} t1_@{co};
parameters x0_@{co} x1_@{co};
parameters imp0_@{co} imp1_@{co};

c0_@{co} = 100; c1_@{co} = 0.28; c2_@{co} = 0.32; c3_@{co} = 0.10; c4_@{co} = -20; c5_@{co} = 1;
i0_@{co} = 100; i1_@{co} = 0.12; i2_@{co} = 0.08; i3_@{co} = 0.04; i4_@{co} = -40; i5_@{co} = -1.5;
m0_@{co} = 75; m1_@{co} = 0.23; m2_@{co} = -35; m3_@{co} = -1.5;
t0_@{co} = -15; t1_@{co} = 0.22;
x0_@{co} = 14; x1_@{co} = 0.2;
imp0_@{co} = 32; imp1_@{co} = 0.2;
@#endfor
var tot_imp tot_x imp_adj;

model;
@#for co in countries
y_@{co} = c_@{co} + i_@{co} + g_@{co} + x_@{co} - imp_@{co};
yd_@{co} = y_@{co} - t_@{co};
t_@{co} = t0_@{co} + t1_@{co} * y_@{co} + ut_@{co};
c_@{co} = c0_@{co} + c1_@{co} * yd_@{co}(-1) + c2_@{co} * yd_@{co} + 
          c3_@{co} * yd_@{co}(+1) + c4_@{co} * r_@{co} + c5_@{co} * r_@{co}^2 +
          uc_@{co};
i_@{co} = i0_@{co} + i1_@{co} * y_@{co}(-1) + i2_@{co} * y_@{co} 
          + i3_@{co} * y_@{co}(+1) + i4_@{co} * r_@{co} + i5_@{co} * r_@{co}^2 +
          ui_@{co};
md_@{co} = m0_@{co} + m1_@{co} * y_@{co} + m2_@{co} * r_@{co} + 
           m3_@{co} * r_@{co}^2 + umd_@{co};
md_@{co} = ms_@{co};
x_@{co} = x0_@{co} + x1_@{co} * y_@{co};
imp_@{co} = imp_adj * (imp0_@{co} + imp1_@{co} * c_@{co});
@#endfor
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
tot_imp = tot_x;
end;

initval;
@#for co in countries
g_@{co}  = 240; ms_@{co} = 230; r_@{co}  = 3.5; y_@{co}  = 980; c_@{co}  = 500; t_@{co}  = 100;
md_@{co} = ms_@{co}; yd_@{co} = y_@{co} - t_@{co}; i_@{co}  = y_@{co} - c_@{co} - g_@{co};
@#endfor
end;
