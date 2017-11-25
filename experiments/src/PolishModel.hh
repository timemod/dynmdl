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
    DIV
};


class PolishModel {
    public:
        PolishModel(unsigned int neq_in, double *constants_in);
        vector<unsigned int> **get_equations();
        double *get_constants();
        unsigned int get_equation_count();

        // functions for generating Polish code
        void new_equation(void);
        void add_constant(unsigned int index);
        void add_endo(unsigned int index);
        void add_param(unsigned int index);
        void add_binop(char op);

        // functions for evaluating the model
        void set_data(double *y_in, double *p_in);
        void get_residuals(double *residuals);

    private:
       // member defining the model
       unsigned int neq;
       vector<unsigned int> **equations; 
       double *constants;

       // members used for generating Polish code
       unsigned int ieq;
       vector<unsigned int> *cur_eq;

       // members for evaluating the model
       double *y, *p;
       stack<double> stk;
       double eval_eq(int ieq);

};

#endif
