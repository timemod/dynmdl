#include "PolishModels.hh"

int PolishModels::create_model(PolishModel *mdl, int nrow, int ncol,
                               const double constants[]) {

    mdl = new PolishModel(nrow, ncol, constants);
    models[model_index] = mdl;
    return(model_index++);
}

int PolishModels::model_index = 0;
vector<PolishModel*> PolishModels::models;
