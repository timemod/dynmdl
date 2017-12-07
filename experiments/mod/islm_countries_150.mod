@#define countries = ["co_1", "co_2", "co_3", "co_4", "co_5", "co_6", "co_7", "co_8", "co_9", "co_10", "co_11", "co_12", "co_13", "co_14", "co_15", "co_16", "co_17", "co_18", "co_19", "co_20", "co_21", "co_22", "co_23", "co_24", "co_25", "co_26", "co_27", "co_28", "co_29", "co_30", "co_31", "co_32", "co_33", "co_34", "co_35", "co_36", "co_37", "co_38", "co_39", "co_40", "co_41", "co_42", "co_43", "co_44", "co_45", "co_46", "co_47", "co_48", "co_49", "co_50", "co_51", "co_52", "co_53", "co_54", "co_55", "co_56", "co_57", "co_58", "co_59", "co_60", "co_61", "co_62", "co_63", "co_64", "co_65", "co_66", "co_67", "co_68", "co_69", "co_70", "co_71", "co_72", "co_73", "co_74", "co_75", "co_76", "co_77", "co_78", "co_79", "co_80", "co_81", "co_82", "co_83", "co_84", "co_85", "co_86", "co_87", "co_88", "co_89", "co_90", "co_91", "co_92", "co_93", "co_94", "co_95", "co_96", "co_97", "co_98", "co_99", "co_100", "co_101", "co_102", "co_103", "co_104", "co_105", "co_106", "co_107", "co_108", "co_109", "co_110", "co_111", "co_112", "co_113", "co_114", "co_115", "co_116", "co_117", "co_118", "co_119", "co_120", "co_121", "co_122", "co_123", "co_124", "co_125", "co_126", "co_127", "co_128", "co_129", "co_130", "co_131", "co_132", "co_133", "co_134", "co_135", "co_136", "co_137", "co_138", "co_139", "co_140", "co_141", "co_142", "co_143", "co_144", "co_145", "co_146", "co_147", "co_148", "co_149", "co_150"]
@#for co in countries
var y_@{co} yd_@{co} t_@{co} c_@{co} i_@{co} md_@{co} r_@{co};
varexo g_@{co} ms_@{co};              
@#endfor

@#for co in countries
varexo ut_@{co} ui_@{co} uc_@{co} umd_@{co};
@#endfor

@#for co in countries
parameters c0_@{co} c1_@{co} c2_@{co} c3_@{co} c4_@{co} c5_@{co};
parameters i0_@{co} i1_@{co} i2_@{co} i3_@{co} i4_@{co} i5_@{co};
parameters m0_@{co} m1_@{co} m2_@{co} m3_@{co};
parameters t0_@{co} t1_@{co};

c0_@{co} = 100; c1_@{co} = 0.28; c2_@{co} = 0.32; c3_@{co} = 0.10; c4_@{co} = -20; c5_@{co} = 1;
i0_@{co} = 100; i1_@{co} = 0.12; i2_@{co} = 0.08; i3_@{co} = 0.04; i4_@{co} = -40; i5_@{co} = -1.5;
m0_@{co} = 75; m1_@{co} = 0.23; m2_@{co} = -35; m3_@{co} = -1.5;
t0_@{co} = -15; t1_@{co} = 0.22;
@#endfor

model;
@#for co in countries
y_@{co} = c_@{co} + i_@{co} + g_@{co};
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
@#endfor
end;

initval;
@#for co in countries
g_@{co}  = 240; ms_@{co} = 230; r_@{co}  = 3.5; y_@{co}  = 980; c_@{co}  = 500; t_@{co}  = 100;
md_@{co} = ms_@{co}; yd_@{co} = y_@{co} - t_@{co}; i_@{co}  = y_@{co} - c_@{co} - g_@{co};
@#endfor
end;
