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

// [[Rcpp::export]]
RawVector serialize_polish_model(int model_index) {

    PolishModel *mdl = PolishModels::get_model(model_index);

    std::stringstream ss; // any stream can be used
    {
    cereal::BinaryOutputArchive oarchive(ss); // Create an output archive
    oarchive(*mdl);
    }
    ss.seekg(0, ss.end);
    RawVector retval(ss.tellg());
    ss.seekg(0, ss.beg);
    ss.read(reinterpret_cast<char*>(&retval[0]), retval.size());
    return retval;
};

// [[Rcpp::export]]
int deserialize_polish_model(RawVector src) {

    PolishModel *mdl = new PolishModel();
    int model_index = PolishModels::add_model(mdl);

    std::stringstream ss;
    ss.write(reinterpret_cast<char*>(&src[0]), src.size());
    ss.seekg(0, ss.beg);
    {
    cereal::BinaryInputArchive iarchive(ss);
    iarchive(*mdl);
    }

    return model_index;
}
