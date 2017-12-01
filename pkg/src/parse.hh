#include "ModFile.hh"

ModFile *parse(char * modfile, bool max_laglead_1, bool no_tmp_terms);

void parse_macro(char *modfile, string &basename, bool debug, bool save_macro, string &save_macro_file, bool no_line_macro,
      map<string, string> &defines, vector<string> &path, stringstream &macro_output);


ModFile *parse_post_macro(stringstream &in, string &basename, bool debug, bool clear_all, bool clear_global,
      bool no_tmp_terms, bool no_log, bool no_warn, bool warn_uninit, bool console,
      bool nograph, bool nointeractive, bool parallel, ConfigFile &config_file,
      WarningConsolidation &warnings, bool nostrict, bool check_model_changes,
      bool minimal_workspace, bool compute_xrefs, FileOutputType output_mode,
      LanguageOutputType language, int params_derivs_order, bool max_laglead_1
#if defined(_WIN32) || defined(__CYGWIN32__)
      , bool cygwin, bool msvc
#endif
      );
