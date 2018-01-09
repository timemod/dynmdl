#include "PolishModel.hh"
#include <iostream>
#include <algorithm>
#include <math.h>
#include <memory.h>

using namespace std;

PolishModel::PolishModel(int neq, int njac, const vector<double> &constants_arg,
                         ExternalFunctionCalc *ext_calc_arg) : neq(neq), 
                                                               njac(njac) {

    ieq = 0; ieq_jac = 0;
    equations = new shared_ptr<vector<int>>[neq];
    jac_equations = new shared_ptr<vector<int>>[njac];
    jac_rows = new int[njac];
    jac_cols = new int[njac];

    nconst = constants_arg.size();
    constants = new double[nconst];
    copy(constants_arg.begin(), constants_arg.end(), constants);

    ext_calc = ext_calc_arg;
    extfun_args = new double[ext_calc->get_narg_max()];

    //cout << "neq = " << neq << endl;
    //cout << "njac = " << njac << endl;
    //cout << "nconst = " << nconst << endl;

}

int PolishModel::get_equation_count() {
    return neq;
}

int PolishModel::get_jac_count() {
    return njac;
}

//
//  codes for generating polish code
//

void PolishModel::new_equation() {
    cur_eq = shared_ptr<vector<int>>(new vector<int>());
    //cout << "new equation " << ieq << endl;
    equations[ieq++] = cur_eq;
}

void PolishModel::new_jac_equation(int row, int col) {
    cur_eq = shared_ptr<vector<int>>(new vector<int>());
    jac_rows[ieq_jac] = row;
    jac_cols[ieq_jac] = col;
    jac_equations[ieq_jac++] = cur_eq;
}

void PolishModel::add_constant(int index) {
    //cout << "constant " << index << endl;
    cur_eq->push_back(CONST);
    cur_eq->push_back(index);
}

void PolishModel::add_endo(int index) {
    //cout << "endo " << index << endl;
    cur_eq->push_back(ENDO);
    cur_eq->push_back(index);
}

void PolishModel::add_exo(int index, int lag) {
    //cout << "exo " << index << " met lag " << lag << endl;
    ecode code = lag == 0 ? EXO : EXO_LAG;
    cur_eq->push_back(code);
    cur_eq->push_back(index);
    if (lag != 0) {
        cur_eq->push_back(lag);
    }
}

void PolishModel::add_param(int index) {
    //cout << "param " << index << endl;
    cur_eq->push_back(PARAM);
    cur_eq->push_back(index);
}

void PolishModel::add_binop(char op) {
    //cout << "binop " << op << endl;
    ecode code;
    switch (op) {
        case '+': code = PLUS; break;
        case '-': code = MINUS; break;
        case '*': code = MULT; break;
        case '/': code = DIV; break;
        case '^': code = POW; break;
    }
    cur_eq->push_back(code);
}

void PolishModel::add_logical_binop(ecode op_code) {
    //cout << "logical_binop " << op_code << endl;
    cur_eq->push_back(op_code);
}

void PolishModel::add_unary_minus() {
    //cout << "unary minus " << endl;
    cur_eq->push_back(UMIN);
}

void PolishModel::add_external_function_call(int index) {
    //cout << "unary minus " << endl;
    cur_eq->push_back(EXTFUN);
    cur_eq->push_back(index);
}

void PolishModel::add_external_function_numderiv(int index, int deriv) {
    //cout << "unary minus " << endl;
    cur_eq->push_back(EXTFUN_NUMDERIV);
    cur_eq->push_back(index);
    cur_eq->push_back(deriv);
}

//
// functions for evaluating the model
//

void PolishModel::set_endo(double const y[]) {
    this->y = y;
}

void PolishModel::set_param(double const p[]) {
    this->p = p;
}

void PolishModel::set_exo(double const x[], int nrow_exo) {
    this->x = x;
    this->nrow_exo = nrow_exo;
}

double PolishModel::eval_eq(shared_ptr<vector<int>> eq, int it) {

   unsigned int pos = 0;

   int *codes = &((*eq)[0]);
   int index, lag;
   double op, lop, rop, res;
   while (pos < eq->size()) {
       int code = codes[pos];
       switch (code) {
           case CONST: index = codes[++pos];
                       stk.push(constants[index]);
                       break;
           case ENDO:  index = codes[++pos];
                       stk.push(y[index]);
                       break;
           case EXO:   index = codes[++pos];
                       stk.push(x[index * nrow_exo + it]);
                       //cout << "EXO, index " << index << endl;
                       //cout << "EXO, value " << x[index * nrow_exo + it] << endl;
                       break;
           case EXO_LAG: index = codes[++pos];
                         lag = codes[++pos];
                         stk.push(x[index * nrow_exo + it + lag]);
                         break;
           case PARAM: index = codes[++pos];
                       stk.push(p[index]);
                       break;
           case MULT: 
           case PLUS: 
           case DIV: 
           case MINUS: 
           case POW: 
                      rop = stk.top();
                      stk.pop();
                      lop = stk.top();
                      stk.pop();
                      switch (code) {
                          case MULT: res = lop * rop; break;
                          case PLUS: res = lop + rop; break;
                          case MINUS: res = lop - rop; break;
                          case DIV: res = lop / rop; break;
                          case POW: res = pow(lop, rop); break;
                       }
                      stk.push(res);
                      break;
           case UMIN: op = stk.top();
                      stk.pop();
                      stk.push(-op);
                      break;
           case EQ: 
           case NEQ: 
           case GT: 
           case GE: 
           case LT: 
           case LE: 
                      rop = stk.top();
                      stk.pop();
                      lop = stk.top();
                      stk.pop();
                      switch (code) {
                          case EQ: res = lop == rop; break;
                          case NEQ: res = lop != rop; break;
                          case GT: res = lop > rop; break;
                          case GE: res = lop >= rop; break;
                          case LT: res = lop < rop; break;
                          case LE: res = lop <= rop; break;
                      }
                      stk.push(res);
                      break;
           case EXTFUN:
                      {
                      index = codes[++pos];
                      int nargs = ext_calc->get_narg(index);
                      for (int i = 0; i < nargs; i++) {
                          extfun_args[i] = stk.top();
                          stk.pop();
                      }
                      res = ext_calc->eval_extfun(index, extfun_args);
                      stk.push(res);
                      }
                      break;

           case EXTFUN_NUMDERIV:
                      {
                      index = codes[++pos];
                      int deriv = codes[++pos];
                      // TODO: handle code
                      }
                      break;
       }
       ++pos;
   }
   res = stk.top();
   stk.pop();

   // TODO: error if stk.size() != 0
   return res;
}

void PolishModel::get_residuals(const double y[], double residuals[], int it) {
    ext_calc->init();
    set_endo(y);
    //cout << "get_residuals, it =  " << it << endl;
    for (int ieq = 0; ieq < neq; ieq++) {
        //cout << "get_residuals, ieq " << ieq << endl;
        residuals[ieq] = eval_eq(equations[ieq], it);
    }
    ext_calc->close();
}

void PolishModel::get_jac(const double y[], int rows[], int cols[], 
                          double values[], int it) {
    ext_calc->init();
    set_endo(y);
    //cout << "get_jac, it =  " << it << endl;
    for (int ieq = 0; ieq < njac; ieq++) {
        rows[ieq] = jac_rows[ieq];
        cols[ieq] = jac_cols[ieq];
        values[ieq] = eval_eq(jac_equations[ieq], it);
        //cout << "get_jac, ieq, row, col =  " << ieq << " " << rows[ieq] <<
        //      " " << cols[ieq]  << endl;
        //cout << "get_jac, value = " << values[ieq] << endl;
    }
    ext_calc->close();
}

// TODO:
// 1. Destructor  (release memory)
