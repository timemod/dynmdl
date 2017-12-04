#ifndef _POLISH_MODEL_HH
#define _POLISH_MODEL_HH

#include <vector>
#include <stack>

using std::vector;
using std::stack;

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
    UMIN  // unary minus
};


class PolishModel {
    public:
        PolishModel(int neq, int njac, const vector<double> &constants_arg);
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
        void add_unary_minus();

        // functions for evaluating the model
        void set_endo(double const y[]);
        void set_exo(double const x[], int nrow_exo);
        void set_param(double const p[]);
        void get_residuals(const double y[], double residuals[], int it);
        void get_jac(const double y[], int rows[], int cols[], double values[], 
                     int it);

    private:
       // member defining the model
       int neq, njac, nexo;
       vector<int> **equations; 
       int *jac_rows;
       int *jac_cols;
       vector<int> **jac_equations; 
       double *constants;

       // members used for generating Polish code
       int ieq, ieq_jac;
       vector<int> *cur_eq;

       // members for evaluating the model
       const double *y, *p, *x;
       int nrow_exo;
       stack<double> stk;
       double eval_eq(vector<int> *eq, int it);
};

#endif
