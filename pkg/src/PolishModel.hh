#ifndef _POLISH_MODEL_HH
#define _POLISH_MODEL_HH


#define NEAR_ZERO (1e-12)

#include <vector>
#include <stack>
#include <memory>
#include <iostream>
#include "ExternalFunctionCalc.hh"

using std::vector;
using std::stack;
using std::shared_ptr;

enum ecode {
    CONST,
    ENDO,
    EXO,
    EXO_LAG, // an exogenous variable with a lag or lead
    PARAM,
    PLUS,
    MULT,
    MINUS,
    DIV,
    POW,
    POW_DERIV,
    UMIN,  // unary minus
    EQ,
    NEQ,
    GT,
    GE,
    LT,
    LE,
    MAX,
    MIN,
    LINLOG,
    EXP,
    LOG,
    SQRT,
    ABS,
    SIGN,
    NORMCDF,
    NORMPDF,
    LINPOW,
    EXTFUN,    // external function
    EXTFUN_DERIV, // external function with analytical numerical derivative
    EXTFUN_NUMDERIV // external function numerical derivative
};


class PolishModel {
    public:
        PolishModel(ExternalFunctionCalc *ext_calc);
        PolishModel(int neq, int njac, const vector<double> &constants_arg,
                    ExternalFunctionCalc *ext_calc);
        int get_equation_count();
        int get_jac_count();

        // functions for generating Polish code
        void new_equation();
        void new_jac_equation(int row, int col);
        void add_constant(int index);
        void add_endo(int index);
        void add_exo(int index, int lag);
        void add_param(int index);
        void add_binop(char op);
        void add_op(ecode op_code);
        void add_unary_minus();
        void add_external_function_call(int index);
        void add_external_function_deriv(int index, int deriv);
        void add_external_function_numderiv(int index, int deriv);

        // functions for evaluating the model
        void set_endo(double const y[]);
        void set_exo(double const x[], int nrow_exo);
        void set_param(double const p[]);
        void get_residuals(const double y[], double residuals[], int it, 
                          bool debug);
        void get_jac(const double y[], int rows[], int cols[], double values[], 
                int it, bool debug);

        // set period information
        void set_period_info(int per_freq, int first_per_subp_count);

       // serialization
       template<class Archive>
       void save(Archive & ar) const {
           ar(neq, njac, nconst);
           for (int i = 0; i < nconst; i++) {
               ar(constants[i]);
           }
           for (int i = 0; i < neq; i++) {
               ar(equations[i]);
           }
           for (int i = 0; i < njac; i++) {
               ar(jac_rows[i]);
           }
           for (int i = 0; i < njac; i++) {
               ar(jac_cols[i]);
           }
           for (int i = 0; i < njac; i++) {
               ar(jac_equations[i]);
           }
       }
       template<class Archive>
       void load(Archive & ar) {
           ar(neq, njac, nconst);
           equations = new shared_ptr<vector<int>>[neq];
           jac_equations = new shared_ptr<vector<int>>[njac];
           jac_rows = new int[njac];
           jac_cols = new int[njac];
           constants = new double[nconst];
           for (int i = 0; i < nconst; i++) {
               ar(constants[i]);
           }
           for (int i = 0; i < neq; i++) {
               equations[i] = shared_ptr<vector<int>>(new vector<int>());
               ar(equations[i]);
           }
           for (int i = 0; i < njac; i++) {
               ar(jac_rows[i]);
           }
           for (int i = 0; i < njac; i++) {
               ar(jac_cols[i]);
           }
           for (int i = 0; i < njac; i++) {
               jac_equations[i] = shared_ptr<vector<int>>(new vector<int>());
               ar(jac_equations[i]);
           }
       }
    private:
       // member defining the model
       int neq, njac, nconst;
       shared_ptr<vector<int>> *equations; 
       int *jac_rows;
       int *jac_cols;
       shared_ptr<vector<int>> *jac_equations; 
       double *constants;

       // members used for generating Polish code
       int ieq, ieq_jac;
       shared_ptr<vector<int>> cur_eq;

       // members for evaluating the model
       ExternalFunctionCalc *ext_calc;
       const double *y, *p, *x;
       double *extfun_args;
       int nrow_exo;
    
       // for debug messages
       int per_freq, first_per_subp_count;

       stack<double> stk;
       double eval_eq(int it, int ieq, bool jac, bool debug);

       // private functions
       void allocate_extfun_args();

       inline std::string get_period_string(int it) const;
       inline void report_numerical_problem(int ieq, int it) const;
       
       inline double eval_norm_function(int code, double x, double mu, double sigma) const;
       inline double get_pow_deriv(double x, double p, int k) const;
       inline double linlog(double x, double eps) const;
       inline double linpow(double x, double p, double eps) const;
};

#endif
