/*
 * aap/f_dynamic.c : Computes dynamic model for Dynare
 *
 * Warning : this file is generated automatically by Dynare
 *           from model file (.mod)
 */
#include <math.h>
#include "call_R_function.h"
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
void f_dynamic(double *y, double *x, int nb_row_x, double *params, int it_, double *residual)
{

init_call_R();

double lhs, rhs;

  /* Residual equations */
double tef_1;
call_R_function("multiply",2, &tef_1, &tef_1, (double) (params[17]),(double) (y[2]));
double t21 = tef_1;
double tef_2;
call_R_function("multiply",2, &tef_2, &tef_2, (double) (params[3]),(double) (y[10]));
double t34 = tef_2;
double tef_3;
call_R_function("square",1, &tef_3, &tef_3, (double) (y[8]));
double t41 = tef_3;
lhs = y[2];
rhs = y[5]+y[6]+x[it_+0*nb_row_x];
residual[0] = lhs - rhs;
lhs = y[3];
rhs = y[2]-y[4];
residual[1] = lhs - rhs;
lhs = y[4];
rhs = params[16]+t21;
residual[2] = lhs - rhs;
lhs = y[5];
rhs = params[0]+params[1]*y[1]+y[3]*params[2]+t34+params[4]*y[8]+params[5]*t41;
residual[3] = lhs - rhs;
lhs = y[6];
rhs = params[6]+params[7]*y[0]+y[2]*params[8]+params[9]*y[9]+y[8]*params[10]+t41*params[11];
residual[4] = lhs - rhs;
lhs = y[7];
rhs = params[12]+y[2]*params[13]+y[8]*params[14]+t41*params[15];
residual[5] = lhs - rhs;
lhs = y[7];
rhs = x[it_+1*nb_row_x];
residual[6] = lhs - rhs;


close_call_R();

return;
}

  /* Jacobian  */
void jac_dynamic(double *y, double *x, int nb_row_x, double *params, int it_,
                 int *rows, int *cols, double *values) {
  /* Jacobian  */

init_call_R();

double tef_1;
call_R_function("multiply",2, &tef_1, &tef_1, (double) (params[17]),(double) (y[2]));
double t21 = tef_1;
double tef_2;
call_R_function("multiply",2, &tef_2, &tef_2, (double) (params[3]),(double) (y[10]));
double t34 = tef_2;
double tef_3;
call_R_function("square",1, &tef_3, &tef_3, (double) (y[8]));
double t41 = tef_3;
double tefd_fdd_1_2;
call_jacob_element("multiply", 2, 2, &tefd_fdd_1_2, (double) (params[17]),(double) (y[2]));
double t80 = tefd_fdd_1_2;
double tefd_fdd_2_2;
call_jacob_element("multiply", 2, 2, &tefd_fdd_2_2, (double) (params[3]),(double) (y[10]));
double t88 = tefd_fdd_2_2;
double tefd_fdd_3_1;
call_jacob_element("square", 1, 1, &tefd_fdd_3_1, (double) (y[8]));
double t90 = tefd_fdd_3_1;
rows[0] = 1;
cols[0] = 3;
values[0] = 1;
rows[1] = 1;
cols[1] = 6;
values[1] = (-1);
rows[2] = 1;
cols[2] = 7;
values[2] = (-1);
rows[3] = 1;
cols[3] = 12;
values[3] = (-1);
rows[4] = 2;
cols[4] = 3;
values[4] = (-1);
rows[5] = 2;
cols[5] = 4;
values[5] = 1;
rows[6] = 2;
cols[6] = 5;
values[6] = 1;
rows[7] = 3;
cols[7] = 3;
values[7] = (-t80);
rows[8] = 3;
cols[8] = 5;
values[8] = 1;
rows[9] = 4;
cols[9] = 2;
values[9] = (-params[1]);
rows[10] = 4;
cols[10] = 4;
values[10] = (-params[2]);
rows[11] = 4;
cols[11] = 11;
values[11] = (-t88);
rows[12] = 4;
cols[12] = 6;
values[12] = 1;
rows[13] = 4;
cols[13] = 9;
values[13] = (-(params[4]+params[5]*t90));
rows[14] = 5;
cols[14] = 1;
values[14] = (-params[7]);
rows[15] = 5;
cols[15] = 3;
values[15] = (-params[8]);
rows[16] = 5;
cols[16] = 10;
values[16] = (-params[9]);
rows[17] = 5;
cols[17] = 7;
values[17] = 1;
rows[18] = 5;
cols[18] = 9;
values[18] = (-(params[10]+params[11]*t90));
rows[19] = 6;
cols[19] = 3;
values[19] = (-params[13]);
rows[20] = 6;
cols[20] = 8;
values[20] = 1;
rows[21] = 6;
cols[21] = 9;
values[21] = (-(params[14]+params[15]*t90));
rows[22] = 7;
cols[22] = 8;
values[22] = 1;
rows[23] = 7;
cols[23] = 13;
values[23] = (-1);


close_call_R();

return;
}
