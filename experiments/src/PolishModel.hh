#ifndef _POLISH_MODEL_HH
#define _POLISH_MODEL_HH

#include <vector>

using std::vector;

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
        void new_equation(void);
        void add_constant(unsigned int index);
        void add_endo(unsigned int index);
        void add_param(unsigned int index);
        void add_binop(char op);
        vector<unsigned int> **get_equations();
        double *get_constants();
        unsigned int get_equation_count();

    private:
       unsigned int neq, ieq;
       double *constants;
       vector<unsigned int> *cur_eq;
       vector<unsigned int> **equations; 
};

#endif
