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
        static int create_model(PolishModel *&mdl, int row, int col,
                                const vector<double>& constants);
        static PolishModel *get_model(int index);
};


#endif
