#include "PolishModel.hh"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

PolishModel::PolishModel(ExternalFunctionCalc *ext_calc) : ext_calc(ext_calc) {

    allocate_extfun_args();
}

PolishModel::PolishModel(int neq, int njac, const vector<double> &constants_arg,
                         ExternalFunctionCalc *ext_calc) : neq(neq), 
                                                njac(njac), ext_calc(ext_calc) {

    ieq = 0; ieq_jac = 0;
    equations = new shared_ptr<vector<int>>[neq];
    jac_equations = new shared_ptr<vector<int>>[njac];
    jac_rows = new int[njac];
    jac_cols = new int[njac];

    nconst = constants_arg.size();
    constants = new double[nconst];
    copy(constants_arg.begin(), constants_arg.end(), constants);

    allocate_extfun_args();

    //cout << "neq = " << neq << endl;
    //cout << "njac = " << njac << endl;
    //cout << "nconst = " << nconst << endl;

}

void PolishModel::allocate_extfun_args() {
    extfun_args = new double[ext_calc->get_narg_max()];
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

void PolishModel::add_op(ecode op_code) {
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

void PolishModel::add_external_function_deriv(int index, int deriv) {
    //cout << "unary minus " << endl;
    cur_eq->push_back(EXTFUN_DERIV);
    cur_eq->push_back(index);
    cur_eq->push_back(deriv);
}

void PolishModel::add_external_function_numderiv(int index, int deriv) {
    //cout << "external_function_numeriv " << index << " " << deriv << endl;
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
   double op, lop, rop, res, xarg, mu, sigma;
   while (pos < eq->size()) {
       int code = codes[pos];
       switch (code) {
           case CONST: index = codes[++pos];
                       stk.push(constants[index]);
                       break;
           case ENDO:  index = codes[++pos];
                       stk.push(y[index]);
                       //cout << "ENDO, index " << index << endl;
                       //cout << "ENDO, value " << y[index] << endl;
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
                       //cout << "PARAM, index " << index << endl;
                       //cout << "PARAM, value " << p[index] << endl;
                       break;
           case MULT: 
           case PLUS: 
           case DIV: 
           case MINUS: 
           case POW:  rop = stk.top();
                      stk.pop();
                      lop = stk.top();
                      switch (code) {
                          case MULT: res = lop * rop; break;
                          case PLUS: res = lop + rop; break;
                          case MINUS: res = lop - rop; break;
                          case DIV: res = lop / rop; break;
                          case POW: res = pow(lop, rop); break;
                      }
                      stk.top() = res;
                      break;
           case UMIN: stk.top() *= -1;
                      break;
           case EQ: 
           case NEQ: 
           case GT: 
           case GE: 
           case LT: 
           case LE: 
           case MIN:
           case MAX: 
           case LINLOG:
                      rop = stk.top();
                      stk.pop();
                      lop = stk.top();
                      switch (code) {
                          case EQ: res = lop == rop; break;
                          case NEQ: res = lop != rop; break;
                          case GT: res = lop > rop; break;
                          case GE: res = lop >= rop; break;
                          case LT: res = lop < rop; break;
                          case LE: res = lop <= rop; break;
                          case MAX: res = max(lop, rop); break;
                          case MIN: res = min(lop, rop); break;
                          case LINLOG: res = linlog(lop, rop); break;
                      }
                      stk.top() = res;
                      break;
           case EXP:
           case LOG:
           case SQRT:
           case ABS:
           case SIGN:
                      stk.top() = eval_function(code, stk.top());
                      break;
           case NORMCDF:
           case NORMPDF:
                      xarg = stk.top();
                      stk.pop();
                      mu = stk.top();
                      stk.pop();
                      sigma = stk.top();
                      stk.top() = eval_norm_function(code, xarg, mu, sigma);
                      break;
           case POW_DERIV:  rop = stk.top();
                            stk.pop();
                            lop = stk.top();
                            stk.top() = get_pow_deriv(lop, rop, 1);
                            break;
           case EXTFUN:
           case EXTFUN_DERIV:
           case EXTFUN_NUMDERIV:
                      {
                      index = codes[++pos];

                      // collect arguments
                      int nargs = ext_calc->get_narg(index);
                      for (int i = 0; i < nargs; i++) {
                          extfun_args[nargs - i - 1] = stk.top();
                          stk.pop();
                      }

                      int deriv = code != EXTFUN  ? codes[++pos] : -1;

                      switch (code) {
                       case EXTFUN:
                          res = ext_calc->eval_extfun(index, extfun_args);
                          break;
                       case EXTFUN_DERIV:
                          res = ext_calc->eval_extfun_deriv(index, deriv,
                                                            extfun_args);
                          break;
                       case EXTFUN_NUMDERIV:
                          res = ext_calc->eval_extfun_numderiv(index, deriv,
                                                               extfun_args);
                          break;
                      }
                      stk.push(res);
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

double PolishModel::eval_function(int  code, double arg) const {  
    switch(code) {
        case EXP: return exp(arg);
        case LOG: return log(arg);
        case SQRT: return sqrt(arg);
        case ABS: return abs(arg);
        case SIGN: return (arg > 0) ? 1 : ((arg < 0) ? -1 : 0);
        default: return 0;
    }
}


// evaluate the (cumulative) normal distribution function
double PolishModel::eval_norm_function(int  code, double x, double mu, 
                                       double sigma) const {  
    switch(code) {
        case NORMCDF: return 0.5 * (1 + erf(((x- mu)/(sigma * M_SQRT2))));
        case NORMPDF: return 1 / (sigma *sqrt(2 * M_PI) * exp(pow((x - mu) / sigma, 
                                                     2) / 2));
    }
}

// calculate the linearized logarithm
double PolishModel::linlog(double x, double eps) const {  
    if (x > eps || eps < 0) {
        return log(x);
    } else {
        return log(eps) + (x - eps) / eps;
    }
}

/*
 * The k-th derivative of x^p
 */
double PolishModel::get_pow_deriv(double x, double p, int k) const {
    if (abs(x) < NEAR_ZERO && p > 0 && k > p && 
            abs(p - nearbyint(p)) < NEAR_ZERO) {
        return 0.0;
    } else {
        double dxp = pow(x, p - k);
        for (int i = 0; i < k; i++) {
            dxp *= p--;
        }
        return dxp;
    }
}


// TODO:
// 1. Destructor  (release memory)
