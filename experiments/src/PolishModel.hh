#ifndef _POLISH_MODEL_HH
#define _POLISH_MODEL_HH

#include <vector>
#include <stack>

using std::vector;
using std::stack;

enum ecode {
    CONST,
    ENDO,
    PARAM,
    PLUS,
    MULT,
    MINUS,
    DIV,
    UMIN  // unary minus
};


class PolishModel {
    public:
        PolishModel(int neq, int njac, const double constants[]);
        int get_equation_count();
        int get_jac_count();

        // functions for generating Polish code
        void new_equation();
        void new_jac_equation(int row, int col);
        void add_constant(int index);
        void add_endo(int index);
        void add_param(int index);
        void add_binop(char op);
        void add_unary_minus();

        // functions for evaluating the model
        void set_endo(double const y[]);
        void set_param(double const p[]);
        void get_residuals(double residuals[]);
        void get_jac(int rows[], int cols[], double values[]);

    private:
       // member defining the model
       int neq, njac;
       vector<int> **equations; 
       int *jac_rows;
       int *jac_cols;
       vector<int> **jac_equations; 
       const double *constants;

       // members used for generating Polish code
       int ieq, ieq_jac;
       vector<int> *cur_eq;

       // members for evaluating the model
       const double *y, *p;
       stack<double> stk;
       double eval_eq(vector<int> *eq);
};

#endif
