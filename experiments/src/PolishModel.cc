#include "PolishModel.hh"

PolishModel::PolishModel(unsigned int neq_in) {
    neq = neq_in;
    ieq = 0;
    equations = new vector<unsigned int>*[neq];
}

void PolishModel::new_equation(void) {
    cur_eq = new vector<unsigned int>();
    equations[ieq++] = cur_eq;
}

void PolishModel::add_endo(unsigned int index) {
    cur_eq->push_back(ENDO);
    cur_eq->push_back(index);
}

void PolishModel::add_param(unsigned int index) {
    cur_eq->push_back(PARAM);
    cur_eq->push_back(index);
}

void PolishModel::add_binop(char op) {
    ecode code;
    switch (op) {
        case '+': code = PLUS; break;
        case '-': code = MINUS; break;
        case '*': code = MULT; break;
        case '/': code = DIV; break;
    }
    cur_eq->push_back(code);
}

unsigned int PolishModel::get_equation_count() {
    return neq;
}

vector<unsigned int>**PolishModel::get_equations() {
    return equations;
}

// TODO:
// 1. Destructor  (release memory)
// 2. Overload the << operator (for debugging).
