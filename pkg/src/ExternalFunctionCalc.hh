#ifndef _EXTERNAL_FUNCTION_CALC_HH
#define _EXTERNAL_FUNCTION_CALC_HH

#include <vector>
#include <string>
#include "CallRFunction.hh"

using std::vector;
using std::string;

class ExternalFunctionCalc {
    public:
        ExternalFunctionCalc() {
            narg_max = 0;
        };
        void add_function(string name, int narg);
        int get_narg(int index) const;
        int get_narg_max() const;
        double eval_extfun(int index, double *args) const;
        double eval_extfun_deriv(int index, int deriv,
              double *args) const;
        double eval_extfun_numderiv(int index, int deriv,
              double *args) const;
        void init();
        void close();

    private:
        vector<string> function_names;
        vector<int> nargs;
        int narg_max;
        CallRFunction call_R_function;
};
#endif

