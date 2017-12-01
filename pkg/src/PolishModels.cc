#include "PolishModels.hh"

int PolishModels::create_model(PolishModel *&mdl, int nrow, int ncol,
                               const vector<double>& constants) {

    mdl = new PolishModel(nrow, ncol, constants);
    models.push_back(mdl);
    return model_index++;
}

PolishModel *PolishModels::get_model(int index) {
    return models[index];
}

int PolishModels::model_index = 0;
vector<PolishModel*> PolishModels::models;
