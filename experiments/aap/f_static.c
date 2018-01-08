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
call_R_function("multiply",2, &tef_1, &tef_1, (double) (params[17]),(double) (y[0]));
double t21 = tef_1;
double tef_2;
call_R_function("multiply",2, &tef_2, &tef_2, (double) (params[3]),(double) (y[1]));
double t32 = tef_2;
double tef_3;
call_R_function("square",1, &tef_3, &tef_3, (double) (y[6]));
double t39 = tef_3;
lhs = y[0];
rhs = y[3]+y[4]+x[0];
residual[0] = lhs - rhs;
lhs = y[1];
rhs = y[0]-y[2];
residual[1] = lhs - rhs;
lhs = y[2];
rhs = params[16]+t21;
residual[2] = lhs - rhs;
lhs = y[3];
rhs = params[0]+y[1]*params[1]+y[1]*params[2]+t32+params[4]*y[6]+params[5]*t39;
residual[3] = lhs - rhs;
lhs = y[4];
rhs = params[6]+y[0]*params[7]+y[0]*params[8]+y[0]*params[9]+y[6]*params[10]+t39*params[11];
residual[4] = lhs - rhs;
lhs = y[5];
rhs = params[12]+y[0]*params[13]+y[6]*params[14]+t39*params[15];
residual[5] = lhs - rhs;
lhs = y[5];
rhs = x[1];
residual[6] = lhs - rhs;

close_call_R();


return;
}

void jac_static(double *y, double *x, double *params, int *rows, int *cols, double *values) {
  /* Jacobian  */
init_call_R();

double tef_1;
call_R_function("multiply",2, &tef_1, &tef_1, (double) (params[17]),(double) (y[0]));
double t21 = tef_1;
double tef_2;
call_R_function("multiply",2, &tef_2, &tef_2, (double) (params[3]),(double) (y[1]));
double t32 = tef_2;
double tef_3;
call_R_function("square",1, &tef_3, &tef_3, (double) (y[6]));
double t39 = tef_3;
double tefd_fdd_1_2;
call_jacob_element("multiply", 2, 2, &tefd_fdd_1_2, (double) (params[17]),(double) (y[0]));
double t75 = tefd_fdd_1_2;
double tefd_fdd_2_2;
call_jacob_element("multiply", 2, 2, &tefd_fdd_2_2, (double) (params[3]),(double) (y[1]));
double t83 = tefd_fdd_2_2;
double tefd_fdd_3_1;
call_jacob_element("square", 1, 1, &tefd_fdd_3_1, (double) (y[6]));
double t86 = tefd_fdd_3_1;
rows[0] = 1;
cols[0] = 1;
values[0] = 1;
rows[1] = 1;
cols[1] = 4;
values[1] = (-1);
rows[2] = 1;
cols[2] = 5;
values[2] = (-1);
rows[3] = 2;
cols[3] = 1;
values[3] = (-1);
rows[4] = 2;
cols[4] = 2;
values[4] = 1;
rows[5] = 2;
cols[5] = 3;
values[5] = 1;
rows[6] = 3;
cols[6] = 1;
values[6] = (-t75);
rows[7] = 3;
cols[7] = 3;
values[7] = 1;
rows[8] = 4;
cols[8] = 2;
values[8] = (-(params[1]+params[2]+t83));
rows[9] = 4;
cols[9] = 4;
values[9] = 1;
rows[10] = 4;
cols[10] = 7;
values[10] = (-(params[4]+params[5]*t86));
rows[11] = 5;
cols[11] = 1;
values[11] = (-(params[9]+params[7]+params[8]));
rows[12] = 5;
cols[12] = 5;
values[12] = 1;
rows[13] = 5;
cols[13] = 7;
values[13] = (-(params[10]+params[11]*t86));
rows[14] = 6;
cols[14] = 1;
values[14] = (-params[13]);
rows[15] = 6;
cols[15] = 6;
values[15] = 1;
rows[16] = 6;
cols[16] = 7;
values[16] = (-(params[14]+params[15]*t86));
rows[17] = 7;
cols[17] = 6;
values[17] = 1;

close_call_R();

return;
}

