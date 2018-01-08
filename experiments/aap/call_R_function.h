void init_call_R(void);
void close_call_R(void);
void call_R_function(const char *func_name, int narg, double *value,
                     double *jac, ...);
void call_R_function_jac(const char *func_name, int narg, double *jac, ...);
void call_jacob_element(const char *func_name, int narg, int index, double *jac_elem, ...);
