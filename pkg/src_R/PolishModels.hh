#ifndef _POLISH_MODELS_HH
#define _POLISH_MODELS_HH

#include <vector>
#include "PolishModel.hh"
#include "ExternalFunctionCalc.hh"

using std::vector;

class PolishModels {
    private: 
        static int model_index;
        static vector<PolishModel*> stat_models, dyn_models;
        static vector<ExternalFunctionCalc*> ext_calcs;
    public:
        static int add_model(PolishModel *stat_mdl, PolishModel *dyn_mdl,
                             ExternalFunctionCalc *ext_cal);
        static PolishModel *get_static_model(int index);
        static PolishModel *get_dynamic_model(int index);
        static ExternalFunctionCalc *get_ext_calc(int index);
};

#endif
