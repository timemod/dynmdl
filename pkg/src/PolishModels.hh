#ifndef _POLISH_MODELS_HH
#define _POLISH_MODELS_HH

#include <vector>
#include "PolishModel.hh"

using std::vector;

class PolishModels {
    private: 
        static int model_index;
        static vector<PolishModel*> models;
    public:
        static int add_model(PolishModel *mdl);
        static PolishModel *get_model(int index);
};


#endif
