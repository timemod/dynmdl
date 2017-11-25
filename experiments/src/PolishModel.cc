#include "PolishModel.hh"

PolishModel::PolishModel(unsigned int neq_in,
                         double *constants_in) {
    neq = neq_in;
    constants = constants_in;
    ieq = 0;
    equations = new vector<unsigned int>*[neq];
}

unsigned int PolishModel::get_equation_count() {
    return neq;
}

vector<unsigned int>**PolishModel::get_equations() {
    return equations;
}

double *PolishModel::get_constants() {
    return constants;
}

//
//  codes for generating polish code
//


void PolishModel::new_equation(void) {
    cur_eq = new vector<unsigned int>();
    equations[ieq++] = cur_eq;
}

void PolishModel::add_constant(unsigned int index) {
    cur_eq->push_back(CONST);
    cur_eq->push_back(index);
}

void PolishModel::add_endo(unsigned int index) {
    cur_eq->push_back(ENDO);
    cur_eq->push_back(index);
}

void PolishModel::add_param(unsigned int index) {
    cur_eq->push_back(PARAM);
    cur_eq->push_back(index);
}

void PolishModel::add_binop(char op) {
    ecode code;
    switch (op) {
        case '+': code = PLUS; break;
        case '-': code = MINUS; break;
        case '*': code = MULT; break;
        case '/': code = DIV; break;
    }
    cur_eq->push_back(code);
}

//
// functions for evaluating the model
//

void PolishModel::set_data(double *y_in, double *p_in) {
    y = y_in;
    p = p_in;
}

double PolishModel::eval_eq(int ieq) {
   vector<unsigned int> *eq = equations[ieq];
   unsigned int pos = 0;

   unsigned int *codes = &((*eq)[0]);
   unsigned int index;
   double lop, rop, res;
   while (pos < eq->size()) {
       unsigned int code = codes[pos];
       switch (code) {
           case CONST: index = codes[++pos];
                       stk.push(constants[index]);
                       break;
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

void PolishModel::get_residuals(double *residuals) {
    for (unsigned int ieq = 0; ieq < neq; ieq++) {
        residuals[ieq] = eval_eq(ieq);
    }
}

// TODO:
// 1. Destructor  (release memory)
