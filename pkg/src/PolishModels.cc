#include "PolishModels.hh"

int PolishModels::add_model(PolishModel *stat_mdl, PolishModel *dyn_mdl) {
    stat_models.push_back(stat_mdl);
    dyn_models.push_back(dyn_mdl);
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


int PolishModels::model_index = 0;
vector<PolishModel*> PolishModels::stat_models, PolishModels::dyn_models;
