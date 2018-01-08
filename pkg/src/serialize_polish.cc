#include <Rcpp.h>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>

#include <cereal/archives/binary.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/memory.hpp>

#include "PolishModels.hh"

using namespace Rcpp;
using namespace std;

RawVector serialize_polish_model(int model_index, bool dynamic);
void deserialize_polish_model(PolishModel *mdl, RawVector src);

// [[Rcpp::export]]
List serialize_polish_models(int model_index) {

    RawVector stat_bin = serialize_polish_model(model_index, false);
    RawVector dyn_bin = serialize_polish_model(model_index, true);

    return List::create(Rcpp::Named("stat") = stat_bin, 
                        Rcpp::Named("dyn")  = dyn_bin);
}

// [[Rcpp::export]]
int deserialize_polish_models(List bin_data) {

    PolishModel *stat_mdl = new PolishModel();
    PolishModel *dyn_mdl = new PolishModel();
    int model_index = PolishModels::add_model(stat_mdl, dyn_mdl);

    deserialize_polish_model(stat_mdl, bin_data["stat"]);
    deserialize_polish_model(dyn_mdl, bin_data["dyn"]);

    return model_index;
}

RawVector serialize_polish_model(int model_index, bool dynamic) {

    PolishModel *mdl;
    if (dynamic) {
        mdl = PolishModels::get_dynamic_model(model_index);
    } else {
        mdl = PolishModels::get_static_model(model_index);
    }

    std::stringstream ss; // any stream can be used
    {
    cereal::BinaryOutputArchive oarchive(ss); // Create an output archive
    oarchive(*mdl);
    }
    ss.seekg(0, ss.end);
    RawVector retval(ss.tellg());
    ss.seekg(0, ss.beg);
    ss.read(reinterpret_cast<char*>(&retval[0]), retval.size());
    
    return(retval);
};

void deserialize_polish_model(PolishModel *mdl, RawVector src) {

    // deserialize dynamic model TODO: also static model
    std::stringstream ss;
    ss.write(reinterpret_cast<char*>(&src[0]), src.size());
    ss.seekg(0, ss.beg);
    {
    cereal::BinaryInputArchive iarchive(ss);
    iarchive(*mdl);
    }
}
