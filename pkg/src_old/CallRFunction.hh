#ifndef _CALL_R_FUNCTION_HH
#define _CALL_R_FUNCTION_HH

#include <string>

using std::string;

class CallRFunction {
    public:
        void init();
        void close();
        double call_function(string func_name, int narg, double *args) const;
        double call_function_deriv(string func_name, int narg, int deriv,
                 double *args) const;
        double call_function_numderiv(string func_name, int narg, int deriv,
                 double *args) const;
};
#endif

