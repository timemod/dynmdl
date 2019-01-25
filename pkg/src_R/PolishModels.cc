#include "PolishModels.hh"

int PolishModels::add_model(PolishModel *stat_mdl, PolishModel *dyn_mdl,
                            ExternalFunctionCalc *ext_calc) {
    stat_models.push_back(stat_mdl);
    dyn_models.push_back(dyn_mdl);
    ext_calcs.push_back(ext_calc);
    // TODO: reuse old index.
    // TODO: smart pointers?
    return model_index++;
}

PolishModel *PolishModels::get_static_model(int index) {
    return stat_models[index];
}

PolishModel *PolishModels::get_dynamic_model(int index) {
    return dyn_models[index];
}

ExternalFunctionCalc *PolishModels::get_ext_calc(int index) {
    return ext_calcs[index];
}


int PolishModels::model_index = 0;
vector<PolishModel*> PolishModels::stat_models, PolishModels::dyn_models;
vector<ExternalFunctionCalc*> PolishModels::ext_calcs;
