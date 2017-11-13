#include <iostream>

#include "PolishModel.hh"
#include "ModelCalc.hh"

using namespace std;

int main() {

    double constants[] = {2};

    PolishModel mdl(2, constants);

    mdl.new_equation();
    mdl.add_endo(1);
    mdl.add_param(0);
    mdl.add_constant(0);
    mdl.add_param(1);
    mdl.add_endo(2);
    mdl.add_binop('*');
    mdl.add_binop('*');
    mdl.add_binop('+');
    mdl.add_binop('-');

    mdl.new_equation();
    mdl.add_endo(2);
    mdl.add_endo(0);
    mdl.add_param(2);
    mdl.add_binop('+');
    mdl.add_binop('-');

    ModelCalc calc = ModelCalc(&mdl);

    double y[] = {1, 0, 2};
    double p[] = {1, 2, 0.1};
    double *residuals = new double[2];
    calc.set_data(y, p);
    calc.get_residuals(residuals);

    cout << "residuals: " << endl;
    for (int i = 0; i < 2; i++) {
        cout << i << " " << residuals[i] << endl;;
    }
}

