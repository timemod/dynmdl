#include "ModelCalc.hh"
#include "PolishModel.hh"

ModelCalc::ModelCalc(PolishModel *model) {
    equations = model->get_equations();
    neq = model->get_equation_count();
}

void ModelCalc::set_data(double *y_in, double *p_in) {
    y = y_in;
    p = p_in;
}

double ModelCalc::eval_eq(int ieq) {
   vector<unsigned int> *eq = equations[ieq];
   unsigned int pos = 0;

   unsigned int *codes = &((*eq)[0]);
   unsigned int index;
   double lop, rop, res;
   while (pos < eq->size()) {
       unsigned int code = codes[pos];
       switch (code) {
           case ENDO: index = codes[++pos];
                      stk.push(y[index]);
                      break;
           case PARAM: index = codes[++pos];
                      stk.push(p[index]);
                      break;
           case MULT: 
           case PLUS: 
           case DIV: 
           case MINUS: 
                      rop = stk.top();
                      stk.pop();
                      lop = stk.top();
                      stk.pop();
                      switch (code) {
                          case MULT: res = lop * rop; break;
                          case PLUS:  res = lop + rop; break;
                          case MINUS:  res = lop - rop; break;
                          case DIV:  res = lop / rop; break;
                       }
                      stk.push(res);
       }
       ++pos;
   }
   res = stk.top();
   stk.pop();

   // TODO: error if stk.size() != 0
   return res;
}

void ModelCalc::get_residuals(double *residuals) {
    for (int ieq = 0; ieq < neq; ieq++) {
        residuals[ieq] = eval_eq(ieq);
    }
}
