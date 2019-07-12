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

SEXP serialize_polish_model(int model_index, bool dynamic);
SEXP serialize_ext_calc(int model_index);
void deserialize_polish_model(PolishModel *mdl, RawVector src);
void deserialize_ext_calc(ExternalFunctionCalc *ext_calc, RawVector src);

// [[Rcpp::export]]
List serialize_polish_models(int model_index) {

    SEXP stat_bin = serialize_polish_model(model_index, false);
    SEXP dyn_bin = serialize_polish_model(model_index, true);
    SEXP ext_calc_bin = serialize_ext_calc(model_index);

    List ret = List::create(Rcpp::Named("stat") = stat_bin, 
                            Rcpp::Named("dyn")  = dyn_bin,
                            Rcpp::Named("ext_calc") = ext_calc_bin);

    UNPROTECT(3);
    return ret;
}

// [[Rcpp::export]]
int deserialize_polish_models(List bin_data) {

    ExternalFunctionCalc *ext_calc = new ExternalFunctionCalc();
    PolishModel *stat_mdl = new PolishModel(ext_calc);
    PolishModel *dyn_mdl = new PolishModel(ext_calc);
    int model_index = PolishModels::add_model(stat_mdl, dyn_mdl, ext_calc);

    deserialize_polish_model(stat_mdl, bin_data["stat"]);
    deserialize_polish_model(dyn_mdl, bin_data["dyn"]);
    deserialize_ext_calc(ext_calc, bin_data["ext_calc"]);

    return model_index;
}

SEXP serialize_polish_model(int model_index, bool dynamic) {

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
    R_xlen_t len = ss.tellg();
    ss.seekg(0, ss.beg);

    // We do not use Rcpp:RawVector because it cannot handle long vectors.
    // The constructor of RawVector expects the size of the vector as an integer.
    // Therefore the maximum size of a RawVector would be 2^31-1. By using 
    // Rf_allocVector and R_xlen_t we do not suffer from this problem.
    SEXP retval = PROTECT(Rf_allocVector(RAWSXP, len));

    ss.read((char *) RAW(retval), len);

    return(retval);
}

SEXP serialize_ext_calc(int model_index) {

    ExternalFunctionCalc *ext_calc = PolishModels::get_ext_calc(model_index);

    std::stringstream ss; // any stream can be used
    {
    cereal::BinaryOutputArchive oarchive(ss); // Create an output archive
    oarchive(*ext_calc);
    }
    
    ss.seekg(0, ss.end);
    R_xlen_t len = ss.tellg();
    ss.seekg(0, ss.beg);
    
    // We do not use Rcpp:RawVector because it cannot handle long vectors.
    // The constructor of RawVector expects the size of the vector as an integer.
    // Therefore the maximum size of a RawVector would be 2^31-1. By using 
    // Rf_allocVector and R_xlen_t we do not suffer from this problem.
    SEXP retval = PROTECT(Rf_allocVector(RAWSXP, len));
    
    ss.read((char *) RAW(retval), len);
    
    return(retval);
}

void deserialize_polish_model(PolishModel *mdl, RawVector src) {
    std::stringstream ss;
    ss.write(reinterpret_cast<char*>(&src[0]), src.size());
    ss.seekg(0, ss.beg);
    {
    cereal::BinaryInputArchive iarchive(ss);
    iarchive(*mdl);
    }
}

void deserialize_ext_calc(ExternalFunctionCalc *ext_calc, RawVector src) {
    std::stringstream ss;
    ss.write(reinterpret_cast<char*>(&src[0]), src.size());
    ss.seekg(0, ss.beg);
    {
    cereal::BinaryInputArchive iarchive(ss);
    iarchive(*ext_calc);
    }
}
