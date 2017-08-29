/*
 * aap/f_static.c : Computes static model for Dynare
 *
 * Warning : this file is generated automatically by Dynare
 *           from model file (.mod)

 */
#include <math.h>
#include "call_R_function.h"
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
void f_static(double *y, double *x, double *params, double *residual) {

init_call_R();

double lhs, rhs;

  /* Residual equations */
double tef_1;
call_R_function("square",1, &tef_1, &tef_1, y[6]);
double t39 = tef_1;
double tef_2;
call_R_function("multiply",2, &tef_2, &tef_2, t39,y[1]);
double t57 = tef_2;
double tef_3;
call_R_function("multiply",2, &tef_3, &tef_3, params[14],y[6]);
double t68 = tef_3;
lhs = y[0];
rhs = y[3]+y[4]+x[0];
residual[0] = lhs - rhs;
lhs = y[1];
rhs = y[0]-y[2];
residual[1] = lhs - rhs;
lhs = y[2];
rhs = params[16]+y[0]*params[17];
residual[2] = lhs - rhs;
lhs = y[3];
rhs = params[0]+y[1]*params[1]+y[1]*params[2]+y[1]*params[3]+params[4]*y[6]+params[5]*t39;
residual[3] = lhs - rhs;
lhs = y[4];
rhs = params[6]+y[0]*params[7]+y[0]*params[8]+y[0]*params[9]+y[6]*params[10]+params[11]*t57/y[1];
residual[4] = lhs - rhs;
lhs = y[5];
rhs = params[12]+y[0]*params[13]+t68+params[15]*pow(y[6],2);
residual[5] = lhs - rhs;
lhs = y[5];
rhs = x[1];
residual[6] = lhs - rhs;

close_call_R();


return;
}

void jac_static(double *y, double *x, double *params, double *g1) {
  /* Jacobian  */
init_call_R();

double tef_1;
call_R_function("square",1, &tef_1, &tef_1, y[6]);
double t39 = tef_1;
double tef_2;
call_R_function("multiply",2, &tef_2, &tef_2, t39,y[1]);
double t57 = tef_2;
double tef_3;
call_R_function("multiply",2, &tef_3, &tef_3, params[14],y[6]);
double t68 = tef_3;
double tefd_fdd_2_1;
call_jacob_element("multiply", 2, 1, &tefd_fdd_2_1, t39,y[1]);
double t85 = tefd_fdd_2_1;
double tefd_fdd_2_2;
call_jacob_element("multiply", 2, 2, &tefd_fdd_2_2, t39,y[1]);
double t86 = tefd_fdd_2_2;
double tefd_fdd_1_1;
call_jacob_element("square", 1, 1, &tefd_fdd_1_1, y[6]);
double t93 = tefd_fdd_1_1;
double tefd_fdd_3_2;
call_jacob_element("multiply", 2, 2, &tefd_fdd_3_2, params[14],y[6]);
double t103 = tefd_fdd_3_2;
g1[0] = 1;
g1[21] = (-1);
g1[28] = (-1);
g1[1] = (-1);
g1[8] = 1;
g1[15] = 1;
g1[2] = (-params[17]);
g1[16] = 1;
g1[10] = (-(params[3]+params[1]+params[2]));
g1[24] = 1;
g1[45] = (-(params[4]+params[5]*t93));
g1[4] = (-(params[9]+params[7]+params[8]));
g1[11] = (-((y[1]*params[11]*t86-params[11]*t57)/(y[1]*y[1])));
g1[32] = 1;
g1[46] = (-(params[10]+params[11]*t85*t93/y[1]));
g1[5] = (-params[13]);
g1[40] = 1;
g1[47] = (-(t103+params[15]*2*y[6]));
g1[41] = 1;

close_call_R();

return;
}

