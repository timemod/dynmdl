#include "ExternalFunctionCalc.hh"
#include <iostream>
#include <algorithm>
#include "CallRFunction.hh"

using std::cout;
using std::endl;
using std::max;

void ExternalFunctionCalc::add_function(string name, int narg) {
    function_names.push_back(name);
    nargs.push_back(narg);
    narg_max = max(narg, narg_max);
}

int ExternalFunctionCalc::get_narg(int index) const {
    return nargs[index];
}

int ExternalFunctionCalc::get_narg_max() const {
    return narg_max;
}

double ExternalFunctionCalc::eval_extfun(int index, double *args) const {
    
#ifdef DEBUG
    cout << "in eval_extfun" << endl;
    cout << "function =  " << function_names[index] << endl;
    cout << "arguments:" << endl;
    for (int iarg = 0; iarg < nargs[index]; iarg++) {
        cout << args[iarg] << " ";
    }
    cout << endl;
#endif

    double retval = call_R_function.call_function(function_names[index], 
            nargs[index], args);
    
#ifdef DEBUG
    cout << "retval = " << retval << endl;
#endif
    return retval;
}

double ExternalFunctionCalc::eval_extfun_deriv(int index, int deriv,
              double *args) const {

    return call_R_function.call_function_deriv(function_names[index], 
            nargs[index], deriv, args);
}


double ExternalFunctionCalc::eval_extfun_numderiv(int index, int deriv,
              double *args) const {
#if DEBUG
    cout << "in eval_extfun_numderiv" << endl;
    cout << "function =  " << function_names[index] << endl;
    cout << "arguments:" << endl;
    for (int iarg = 0; iarg < nargs[index]; iarg++) {
        cout << args[iarg] << " ";
    }
    cout << endl;
#endif
    return call_R_function.call_function_numderiv(function_names[index], 
            nargs[index], deriv, args);
}


void ExternalFunctionCalc::init() {
    call_R_function.init();
}

void ExternalFunctionCalc::close() {
    call_R_function.close();
}
