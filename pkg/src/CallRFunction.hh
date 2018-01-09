#ifndef _CALL_R_FUNCTION_HH
#define _CALL_R_FUNCTION_HH

#include <string>

using std::string;

class CallRFunction {
    public:
        void init();
        void close();
        double call_function(string func_name, int narg, double *args) const;
};
#endif

