/*
 * Copyright (C) 2003-2016 Dynare Team
 *
 * This file is part of Dynare.
 *
 * Dynare is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Dynare is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Dynare.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <sstream>
#include <fstream>

#include <cstdlib>
#include <cstring>
#ifndef PACKAGE_VERSION
# define PACKAGE_VERSION 4.
#endif

#include <unistd.h>
#include "ParsingDriver.hh"
#include "ExtendedPreprocessorTypes.hh"
#include "ConfigFile.hh"
#include "run_dynare.hh"
#include "parse.hh"
#include "dynout.hh"
#include "dyn_error.hh"

ModFile* parse(char * modfile, char *latex_basename, bool max_laglead_1, bool nostrict,
               bool no_tmp_terms, int n_fit_derivatives, bool warn_uninit_param,
               bool latex, const OutputParameters &output_params) {
  bool clear_all = true;
  bool clear_global = false;
  bool save_macro = false;
  string save_macro_file;
  bool debug = false;
  bool no_line_macro = false;
  bool no_log = false;
  bool no_warn = false;
  int params_derivs_order = 2;
  bool warn_uninit = false;
  bool console = false;
  bool nograph = false;
  bool nointeractive = false;
#if defined(_WIN32) || defined(__CYGWIN32__)
  bool cygwin = false;
  bool msvc = false;
#endif
  string parallel_config_file;
  bool parallel = false;
  string cluster_name;
  bool parallel_slave_open_mode = false;
  bool parallel_test = false;
  bool check_model_changes = false;
  bool minimal_workspace = false;
  bool compute_xrefs = false;
  map<string, string> defines;
  vector<string> path;
  FileOutputType output_mode = none;
  LanguageOutputType language = r;

  DynOut << "Starting Dynare (version " << PACKAGE_VERSION << ")." << endl
       << "Starting preprocessing of the model file ..." << endl;

  // Construct basename (i.e. remove file extension if there is one)
  string basename = modfile;
  size_t pos = basename.find_last_of('.');
  if (pos != string::npos)
    basename.erase(pos);

  WarningConsolidation warnings(no_warn);

  // Process config file
  ConfigFile config_file(parallel, parallel_test, parallel_slave_open_mode, cluster_name);
  config_file.getConfigFileInfo(parallel_config_file);
  config_file.checkPass(warnings);
  config_file.transformPass();

  // If Include option was passed to the [paths] block of the config file, add
  // it to paths before macroprocessing
  vector<string> config_include_paths = config_file.getIncludePaths();
  for (vector<string>::const_iterator it = config_include_paths.begin();
       it != config_include_paths.end(); it++)
    path.push_back(*it);

  // Do macro processing
  stringstream macro_output;
  parse_macro(modfile, basename, debug, save_macro, save_macro_file, no_line_macro, defines, path, macro_output);

  // Do the rest
  string latex_basename_string = latex_basename;
  ModFile *mod_file = parse_post_macro(macro_output, latex_basename_string, debug, clear_all, clear_global,
        no_tmp_terms, no_log, no_warn, warn_uninit, warn_uninit_param, console, nograph, nointeractive,
        parallel, config_file, warnings, nostrict, check_model_changes, minimal_workspace,
        compute_xrefs, output_mode, language, params_derivs_order, max_laglead_1,
        n_fit_derivatives, latex, output_params
#if defined(_WIN32) || defined(__CYGWIN32__)
        , cygwin, msvc
#endif
        );

  DynOut << "Preprocessing completed." << endl;

  int nwarn = mod_file->get_warning_count();
  if (nwarn > 0) {
      std::ostringstream msg;
      msg << nwarn << " warnings encountered in the preprocessor. Check the output";
      dyn_warning(msg);
  }

  return mod_file;
}
