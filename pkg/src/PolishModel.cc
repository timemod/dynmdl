#include "PolishModel.hh"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <Rcpp.h>
#include <Rcpp.h>
#include <Rcpp.h>
#include <boost/format.hpp>

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

void PolishModel::set_period_info(int per_freq, int first_per_subp_count) {
    this->per_freq = per_freq;
    this->first_per_subp_count = first_per_subp_count;
}

std::string PolishModel::get_period_string(int it) const {
    int subp_count = first_per_subp_count + it;
    if (per_freq == 1) {
        return std::to_string(subp_count);
    } else {
        int year = subp_count / per_freq;
        int subp = subp_count % per_freq + 1;
        char freq_char;
        switch(per_freq) {
            case 4: freq_char = 'q'; break;
            case 12: freq_char = 'm'; break;
            default: freq_char = '/'; break;
        }
        return std::to_string(year) + freq_char + std::to_string(subp);
    }
}

void PolishModel::report_numerical_problem(int ieq, int it) const {
     Rcpp::Rcerr << "Numerical problem in eq. " << ieq + 1;
     if (per_freq != -1) {
         // per_freq == -1 when solving the steady state
         Rcpp::Rcerr << " for " <<  get_period_string(it) << ": ";
     } else {
         Rcpp::Rcerr << ": "; 
     }
}

//double PolishModel::eval_eq(shared_ptr<vector<int>> eq, int it, int ieq) {
double PolishModel::eval_eq(int ieq, int it, bool jac, bool debug) {


   shared_ptr<vector<int>> eq = jac ? jac_equations[ieq] : equations[ieq];

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
                          case DIV:  if (debug && rop == 0) {
                                         report_numerical_problem(ieq, it);
                                          Rcpp::Rcerr << "division by 0" <<  std::endl;
                                     }
                                     res = lop / rop; break;
                          case POW: if (debug && lop < 0 && std::floor(rop) != rop) {
                                        report_numerical_problem(ieq, it);
                                        Rcpp::Rcerr << "(" << boost::format("%.2g") % lop << ")^" 
                                                    << boost::format("%.2g") % rop << std::endl;
                                                    
                                    }
                                    res = pow(lop, rop); break;
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
           case EXP:  stk.top() = exp(stk.top()); break;
           case LOG:  rop = stk.top();
                      if (debug && rop <= 0) {
                          report_numerical_problem(ieq, it);
                          Rcpp::Rcerr << "log(" << boost::format("%.2g") % rop << ")" << std::endl;
                      }
                      stk.top() = log(rop); break;
           case SQRT: rop = stk.top();
                      if (debug && rop < 0) {
                          report_numerical_problem(ieq, it);
                          Rcpp::Rcerr << "sqrt(" << boost::format("%.2g") % rop << ")" << std::endl;
                      }
                      stk.top() = sqrt(rop); break;
           case ABS:  stk.top() = abs(stk.top()); break;
           case SIGN: rop = stk.top();
                      stk.top() = (rop > 0) ? 1 : ((rop < 0) ? -1 : 0);
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
           case LINPOW:
                      xarg = stk.top();
                      stk.pop();
                      mu = stk.top();
                      stk.pop();
                      sigma = stk.top();
                      stk.top() = linpow(xarg, mu, sigma);
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

   if (stk.size() != 0) {
       Rcpp::stop("Internal error: calculation stack not empy at the end of eval_eq");
   }

   return res;
}

void PolishModel::get_residuals(const double y[], double residuals[], int it, bool debug) {
    ext_calc->init();
    set_endo(y);
    //cout << "get_residuals, it =  " << it << endl;
    for (int ieq = 0; ieq < neq; ieq++) {
        //cout << "get_residuals, ieq " << ieq << endl;
        residuals[ieq] = eval_eq(ieq, it, false, debug);
    }
    ext_calc->close();
}

void PolishModel::get_jac(const double y[], int rows[], int cols[], 
                          double values[], int it, bool debug) {
    ext_calc->init();
    set_endo(y);
    //cout << "get_jac, it =  " << it << endl;
    for (int ieq = 0; ieq < njac; ieq++) {
        rows[ieq] = jac_rows[ieq];
        cols[ieq] = jac_cols[ieq];
        values[ieq] = eval_eq(ieq, it, true, debug);
        //cout << "get_jac, ieq, row, col =  " << ieq << " " << rows[ieq] <<
        //      " " << cols[ieq]  << endl;
        //cout << "get_jac, value = " << values[ieq] << endl;
    }
    ext_calc->close();
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
    if (x > eps) {
        return log(x);
    } else {
        return log(eps) + (x - eps) / eps;
    }
}

// calculate the linearized power
double PolishModel::linpow(double x, double p, double eps) const {  
    if (x > eps) {
        return pow(x, p);
    } else {
        return pow(eps, p) * (1 + p * (x - eps) / eps);
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
