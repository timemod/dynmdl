#ifndef _MODEL_CALC_HH
#define _MODEL_CALC_HH

#include <stack>
using std::stack;

#include "PolishModel.hh"


class ModelCalc {
    public:
        ModelCalc(PolishModel *model_in);
        void set_data(double *y_in, double *p_in);
        void get_residuals(double *residuals);

    private:
        unsigned int neq;
        double *constants;
        vector<unsigned int>**equations;
        double *y, *p;
        stack<double> stk;
        double eval_eq(int ieq);
};

#endif


