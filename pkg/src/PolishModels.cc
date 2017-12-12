#include "PolishModels.hh"

int PolishModels::add_model(PolishModel *mdl) {
    models.push_back(mdl);
    // TODO: reuse old index.
    // TODO: smart pointers?
    return model_index++;
}

PolishModel *PolishModels::get_model(int index) {
    return models[index];
}

int PolishModels::model_index = 0;
vector<PolishModel*> PolishModels::models;
