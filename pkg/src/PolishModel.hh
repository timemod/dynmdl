#ifndef _POLISH_MODEL_HH
#define _POLISH_MODEL_HH

#include <vector>
#include <stack>
#include <memory>
#include <iostream>

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
    UMIN  // unary minus
};


class PolishModel {
    public:
        PolishModel() {};
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
       const double *y, *p, *x;
       int nrow_exo;
       stack<double> stk;
       double eval_eq(shared_ptr<vector<int>> eq, int it);
};

#endif
