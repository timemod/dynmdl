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

/* Prototype for second part of main function
   Splitting main() in two parts was necessary because ParsingDriver.h and MacroDriver.h can't be
   included simultaneously (because of Bison limitations).
*/
void main2(stringstream &in, string &basename, bool debug, bool clear_all, bool clear_global,
           bool no_tmp_terms, bool no_log, bool no_warn, bool warn_uninit, bool console,
           bool nograph, bool nointeractive, bool parallel, ConfigFile &config_file,
           WarningConsolidation &warnings_arg, bool nostrict, bool check_model_changes,
           bool minimal_workspace, bool compute_xrefs, FileOutputType output_mode,
           LanguageOutputType lang, int params_derivs_order
#if defined(_WIN32) || defined(__CYGWIN32__)
           , bool cygwin, bool msvc
#endif
           );

void main1(char *modfile, string &basename, bool debug, bool save_macro, string &save_macro_file,
           bool no_line_macro,
           map<string, string> &defines, vector<string> &path, stringstream &macro_output);

void
usage()
{
  cerr << "Dynare usage: dynare mod_file [debug] [noclearall] [onlyclearglobals] [savemacro[=macro_file]] [onlymacro] [nolinemacro] [notmpterms] [nolog] [warn_uninit]"
       << " [console] [nograph] [nointeractive] [parallel[=cluster_name]] [conffile=parallel_config_path_and_filename] [parallel_slave_open_mode] [parallel_test]"
       << " [-D<variable>[=<value>]] [-I/path] [nostrict] [fast] [minimal_workspace] [compute_xrefs] [output=dynamic|first|second|third] [language=C|C++|julia]"
       << " [params_derivs_order=0|1|2]"
#if defined(_WIN32) || defined(__CYGWIN32__)
       << " [cygwin] [msvc]"
#endif
       << endl;
  exit(EXIT_FAILURE);
}

int run_dynare(char * modfile) {
  /*
    Redirect stderr to stdout.
    Made necessary because MATLAB/Octave can only capture stdout (but not
    stderr), in order to put it in the logfile (see issue #306)
  */
  dup2(STDOUT_FILENO, STDERR_FILENO);

  bool clear_all = true;
  bool clear_global = false;
  bool save_macro = false;
  string save_macro_file;
  bool debug = false;
  bool no_tmp_terms = false;
  bool only_macro = false;
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
  bool nostrict = false;
  bool check_model_changes = false;
  bool minimal_workspace = false;
  bool compute_xrefs = false;
  map<string, string> defines;
  vector<string> path;
  FileOutputType output_mode = none;
  LanguageOutputType language = matlab;

  cout << "Starting Dynare (version " << PACKAGE_VERSION << ")." << endl
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
  main1(modfile, basename, debug, save_macro, save_macro_file, no_line_macro, defines, path, macro_output);

  if (only_macro)
    return EXIT_SUCCESS;

  // Do the rest
  main2(macro_output, basename, debug, clear_all, clear_global,
        no_tmp_terms, no_log, no_warn, warn_uninit, console, nograph, nointeractive,
        parallel, config_file, warnings, nostrict, check_model_changes, minimal_workspace,
        compute_xrefs, output_mode, language, params_derivs_order
#if defined(_WIN32) || defined(__CYGWIN32__)
        , cygwin, msvc
#endif
        );

  return EXIT_SUCCESS;
}
