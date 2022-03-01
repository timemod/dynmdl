
// q_model: specify 1 for quarterly model and 0 for annual model
@#define q_model =  1
@#define p_vars = ["bd", "br", "be"]

var     bd_pj___ br_pj___ be_pj___;
varexo  bd_px___ br_px___ be_px___;
varexo  dumpj;

model;


// calculate various prices. For quarterly model, use
//pj = dumpj * pj_(-1) + (1 – dumpj) * (px_(-1) +px_(-2)+px_(-3) + px_(-4))/4
//
@#for p_var in p_vars
  @#if q_model
    [name = 'price @{p_var}']
    @{p_var}_pj___ = dumpj * @{p_var}_pj___(-1) + (1 - dumpj) * (
    @#for lag in 1:4
      + @{p_var}_px___(-@{lag})
    @#endfor
    ) / 4;
  @#else
    // annual version of the model
    @{p_var}_pj___ =  @{p_var}_px___(-1);
  @#endif
@#endfor

end;

write_latex_dynamic_model;
