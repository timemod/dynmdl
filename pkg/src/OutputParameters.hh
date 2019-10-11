#ifdef USE_R
#ifndef _OUTPUT_PARAMETERS_HH
#define _OUTPUT_PARAMETERS_HH

#include "dyn_error.hh"

class OutputParameters {
    private:
        bool par_as_num = false;  // write parameters as constants
        int ndigits_latex = 4;   // number of printed digits when numericalal functions
                                 // are printed in the LaTeX file
                                 
    public:
        bool is_par_as_num() const {return par_as_num;}
        int  get_ndigits_latex() const {return ndigits_latex;}
        void set_par_as_num(bool new_par_as_num) {par_as_num = new_par_as_num;}

        void set_ndigits_latex(int ndigits) {
            if (ndigits < 0 || ndigits > 15) {
                dyn_error("ndigits should lie between 0 and 15");
            }
            ndigits_latex = ndigits;
        }
};
#endif
#endif
