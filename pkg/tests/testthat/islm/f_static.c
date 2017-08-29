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
int nlhs_tef_1 = 2;
double *TEF_1, *TEFD_1; 
mxArray *plhs_tef_1[nlhs_tef_1];
int nrhs_tef_1 = 1;
mxArray *prhs_tef_1[nrhs_tef_1];
prhs_tef_1[0] = mxCreateDoubleScalar(2*y[6]);
mexCallMATLAB(nlhs_tef_1, plhs_tef_1, nrhs_tef_1, prhs_tef_1, "square");
TEF_1 = mxGetPr(plhs_tef_1[0]);
TEFD_1 = mxGetPr(plhs_tef_1[1]);
double t40 = *tef_1;
int nlhs_tef_2 = 2;
double *TEF_2, *TEFD_2; 
mxArray *plhs_tef_2[nlhs_tef_2];
int nrhs_tef_2 = 1;
mxArray *prhs_tef_2[nrhs_tef_2];
prhs_tef_2[0] = mxCreateDoubleScalar(y[6]);
mexCallMATLAB(nlhs_tef_2, plhs_tef_2, nrhs_tef_2, prhs_tef_2, "square");
TEF_2 = mxGetPr(plhs_tef_2[0]);
TEFD_2 = mxGetPr(plhs_tef_2[1]);
int nlhs_tef_3 = 2;
double *TEF_3, *TEFD_3; 
mxArray *plhs_tef_3[nlhs_tef_3];
int nrhs_tef_3 = 2;
mxArray *prhs_tef_3[nrhs_tef_3];
prhs_tef_3[0] = mxCreateDoubleScalar(*tef_2);
prhs_tef_3[1] = mxCreateDoubleScalar(y[1]);
mexCallMATLAB(nlhs_tef_3, plhs_tef_3, nrhs_tef_3, prhs_tef_3, "multiply");
TEF_3 = mxGetPr(plhs_tef_3[0]);
TEFD_3 = mxGetPr(plhs_tef_3[1]);
double t61 = *tef_3;
int nlhs_tef_4 = 2;
double *TEF_4, *TEFD_4; 
mxArray *plhs_tef_4[nlhs_tef_4];
int nrhs_tef_4 = 2;
mxArray *prhs_tef_4[nrhs_tef_4];
prhs_tef_4[0] = mxCreateDoubleScalar(params[14]);
prhs_tef_4[1] = mxCreateDoubleScalar(y[6]);
mexCallMATLAB(nlhs_tef_4, plhs_tef_4, nrhs_tef_4, prhs_tef_4, "multiply");
TEF_4 = mxGetPr(plhs_tef_4[0]);
TEFD_4 = mxGetPr(plhs_tef_4[1]);
double t72 = *tef_4;
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
rhs = params[0]+y[1]*params[1]+y[1]*params[2]+y[1]*params[3]+params[4]*y[6]+params[5]*t40/4;
residual[3] = lhs - rhs;
lhs = y[4];
rhs = params[6]+y[0]*params[7]+y[0]*params[8]+y[0]*params[9]+y[6]*params[10]+params[11]*t61/y[1];
residual[4] = lhs - rhs;
lhs = y[5];
rhs = params[12]+y[0]*params[13]+t72+params[15]*pow(y[6],2);
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

int nlhs_tef_1 = 2;
double *TEF_1, *TEFD_1; 
mxArray *plhs_tef_1[nlhs_tef_1];
int nrhs_tef_1 = 1;
mxArray *prhs_tef_1[nrhs_tef_1];
prhs_tef_1[0] = mxCreateDoubleScalar(2*y[6]);
mexCallMATLAB(nlhs_tef_1, plhs_tef_1, nrhs_tef_1, prhs_tef_1, "square");
TEF_1 = mxGetPr(plhs_tef_1[0]);
TEFD_1 = mxGetPr(plhs_tef_1[1]);
double t40 = *tef_1;
int nlhs_tef_2 = 2;
double *TEF_2, *TEFD_2; 
mxArray *plhs_tef_2[nlhs_tef_2];
int nrhs_tef_2 = 1;
mxArray *prhs_tef_2[nrhs_tef_2];
prhs_tef_2[0] = mxCreateDoubleScalar(y[6]);
mexCallMATLAB(nlhs_tef_2, plhs_tef_2, nrhs_tef_2, prhs_tef_2, "square");
TEF_2 = mxGetPr(plhs_tef_2[0]);
TEFD_2 = mxGetPr(plhs_tef_2[1]);
int nlhs_tef_3 = 2;
double *TEF_3, *TEFD_3; 
mxArray *plhs_tef_3[nlhs_tef_3];
int nrhs_tef_3 = 2;
mxArray *prhs_tef_3[nrhs_tef_3];
prhs_tef_3[0] = mxCreateDoubleScalar(*tef_2);
prhs_tef_3[1] = mxCreateDoubleScalar(y[1]);
mexCallMATLAB(nlhs_tef_3, plhs_tef_3, nrhs_tef_3, prhs_tef_3, "multiply");
TEF_3 = mxGetPr(plhs_tef_3[0]);
TEFD_3 = mxGetPr(plhs_tef_3[1]);
double t61 = *tef_3;
int nlhs_tef_4 = 2;
double *TEF_4, *TEFD_4; 
mxArray *plhs_tef_4[nlhs_tef_4];
int nrhs_tef_4 = 2;
mxArray *prhs_tef_4[nrhs_tef_4];
prhs_tef_4[0] = mxCreateDoubleScalar(params[14]);
prhs_tef_4[1] = mxCreateDoubleScalar(y[6]);
mexCallMATLAB(nlhs_tef_4, plhs_tef_4, nrhs_tef_4, prhs_tef_4, "multiply");
TEF_4 = mxGetPr(plhs_tef_4[0]);
TEFD_4 = mxGetPr(plhs_tef_4[1]);
double t72 = *tef_4;
double t89 = tefd_3[0];
double t90 = tefd_3[1];
double t97 = tefd_1[0];
double t103 = tefd_2[0];
double t110 = tefd_4[1];
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
g1[45] = (-(params[4]+params[5]*2*t97/4));
g1[4] = (-(params[9]+params[7]+params[8]));
g1[11] = (-((y[1]*params[11]*t90-params[11]*t61)/(y[1]*y[1])));
g1[32] = 1;
g1[46] = (-(params[10]+params[11]*t89*t103/y[1]));
g1[5] = (-params[13]);
g1[40] = 1;
g1[47] = (-(t110+2*y[6]*params[15]));
g1[41] = 1;

close_call_R();

return;
}

