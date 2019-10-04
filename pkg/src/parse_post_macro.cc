/*
 * Parse the Model after the macro proprocessor
 *
 * The parsing is split in diffent parts  (macro and post macro)
 *  because ParsingDriver.h and MacroDriver.h can't be
 *  included simultaneously (because of Bison limitations).
 *
 * Copyright (C) 2008-2016 Dynare Team
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

#include "ParsingDriver.hh"
#include "ModFile.hh"
#include "ConfigFile.hh"
#include "ExtendedPreprocessorTypes.hh"
#include "parse.hh"

ModFile *parse_post_macro(stringstream &in, string &latex_basename, bool debug, bool clear_all, bool clear_global,
      bool no_tmp_terms, bool no_log, bool no_warn, bool warn_uninit, bool warn_uninit_param, bool console,
      bool nograph, bool nointeractive, bool parallel, ConfigFile &config_file,
      WarningConsolidation &warnings, bool nostrict, bool check_model_changes,
      bool minimal_workspace, bool compute_xrefs, FileOutputType output_mode,
      LanguageOutputType language, int params_derivs_order, bool max_laglead_1,
      int n_fit_derivatives, bool par_const
#if defined(_WIN32) || defined(__CYGWIN32__)
      , bool cygwin, bool msvc
#endif
      ) {
  ParsingDriver p(warnings, nostrict);

  // Do parsing and construct internal representation of mod file
  ModFile *mod_file = p.parse(in, debug);

  // Run checking pass
  mod_file->checkPass(nostrict);

  // Perform transformations on the model (creation of auxiliary vars and equations)
  mod_file->transformPass(nostrict, compute_xrefs, max_laglead_1, n_fit_derivatives);

  // Evaluate parameters initialization, initval, endval and pounds
  mod_file->evalAllExpressions(warn_uninit, warn_uninit_param);

  // Do computations
  mod_file->computingPass(no_tmp_terms, output_mode,  params_derivs_order);

  // Write LaTeX files
  mod_file->writeLatexFiles(latex_basename, n_fit_derivatives > 0, par_const);

  return mod_file;
}
