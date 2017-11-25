#include <iostream>

#include "PolishModel.hh"

using namespace std;

int main() {

    double constants[] = {2, 1, -1};

    PolishModel mdl(2, 4, constants);

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

    mdl.new_jac_equation(0, 0);
    mdl.add_constant(1);
    mdl.new_jac_equation(0, 2);
    mdl.add_constant(0);
    mdl.add_param(1);
    mdl.add_binop('*');
    mdl.add_unary_minus();
    mdl.new_jac_equation(1, 0);
    mdl.add_constant(2);
    mdl.new_jac_equation(1, 2);
    mdl.add_constant(1);

    double y[] = {1, 0, 2};
    double p[] = {1, 2, 0.1};

    double *residuals = new double[2];
    mdl.set_data(y, p);
    mdl.get_residuals(residuals);

    int njac = mdl.get_jac_count();
    int *rows = new int[njac];
    int *cols = new int[njac];
    double *jac_values = new double[njac];
    mdl.get_jac(rows, cols, jac_values);

    cout << "residuals: " << endl;
    for (int i = 0; i < 2; i++) {
        cout << i << " " << residuals[i] << endl;;
    }

    cout << "Jacobian: " << endl;
    for (int i = 0; i < njac; i++) {
        cout << rows[i] << " " << cols[i] << " " << jac_values[i] << endl;;
    }
}

