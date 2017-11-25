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
        PolishModel(int neq_in,int njac_in, double *constants_in);
        int get_equation_count();
        int get_jac_count();

        // functions for generating Polish code
        void new_equation(void);
        void new_jac_equation(int row, int col);
        void add_constant(int index);
        void add_endo(int index);
        void add_param(int index);
        void add_binop(char op);
        void add_unary_minus();

        // functions for evaluating the model
        void set_data(double *y_in, double *p_in);
        void get_residuals(double *residuals);
        void get_jac(int *rows, int *cols, double *values);

    private:
       // member defining the model
       int neq, njac;
       vector<int> **equations; 
       int *jac_rows;
       int *jac_cols;
       vector<int> **jac_equations; 
       double *constants;

       // members used for generating Polish code
       int ieq, ieq_jac;
       vector<int> *cur_eq;

       // members for evaluating the model
       double *y, *p;
       stack<double> stk;
       double eval_eq(vector<int> *eq);
};

#endif
