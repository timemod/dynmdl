/*
 * Copyright (C) 2006-2017 Dynare Team
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

#include "Statement.hh"
#include <boost/xpressive/xpressive.hpp>

ModFileStructure::ModFileStructure() :
  check_present(false),
  steady_present(false),
  perfect_foresight_solver_present(false),
  stoch_simul_present(false),
  estimation_present(false),
  osr_present(false),
  osr_params_present(false),
  optim_weights_present(false),
  ramsey_model_present(false),
  ramsey_policy_present(false),
  discretionary_policy_present(false),
  planner_objective_present(false),
  extended_path_present(false),
  order_option(0),
  bvar_present(false),
  svar_identification_present(false),
  identification_present(false),
  estimation_analytic_derivation(false),
  partial_information(false),
  k_order_solver(false),
  calibrated_measurement_errors(false),
  dsge_prior_weight_in_estimated_params(false),
  dsge_var_calibrated(""),
  dsge_var_estimated(false),
  bayesian_irf_present(false),
  estimation_data_statement_present(false),
  last_markov_switching_chain(0),
  calib_smoother_present(false),
  estim_params_use_calib(false),
  prior_statement_present(false),
  std_prior_statement_present(false),
  corr_prior_statement_present(false),
  options_statement_present(false),
  std_options_statement_present(false),
  corr_options_statement_present(false),
  ms_dsge_present(false),
  orig_eq_nbr(0),
  ramsey_eq_nbr(0)
{
}

Statement::~Statement()
{
}

void
Statement::checkPass(ModFileStructure &mod_file_struct, WarningConsolidation &warnings)
{
}

void
Statement::writeCOutput(ostream &output, const string &basename)
{
}

void
Statement::writeJuliaOutput(ostream &output, const string &basename)
{
}

void
Statement::computingPass()
{
}

NativeStatement::NativeStatement(const string &native_statement_arg) :
  native_statement(native_statement_arg)
{
}

void
NativeStatement::writeOutput(ostream &output, const string &basename, bool minimal_workspace) const
{
  using namespace boost::xpressive;
  string date_regex = "(-?\\d+([YyAa]|[Mm]([1-9]|1[0-2])|[Qq][1-4]|[Ww]([1-9]{1}|[1-4]\\d|5[0-2])))";
  sregex regex_lookbehind = sregex::compile("(?<!\\$|\\d|[a-zA-Z_]|\\')" + date_regex);
  sregex regex_dollar = sregex::compile("(\\$)"+date_regex);

  string ns = regex_replace(native_statement, regex_lookbehind, "dates('$&')");
  ns = regex_replace(ns, regex_dollar, "$2"); //replace $DATE with DATE
  output << ns << endl;
}

VerbatimStatement::VerbatimStatement(const string &verbatim_statement_arg) :
  verbatim_statement(verbatim_statement_arg)
{
}

void
VerbatimStatement::writeOutput(ostream &output, const string &basename, bool minimal_workspace) const
{
  output << verbatim_statement << endl;
}

void
OptionsList::writeOutput(ostream &output) const
{
  for (num_options_t::const_iterator it = num_options.begin();
       it != num_options.end(); it++)
    output << "options_." << it->first << " = " << it->second << ";" << endl;

  for (paired_num_options_t::const_iterator it = paired_num_options.begin();
       it != paired_num_options.end(); it++)
    output << "options_." << it->first << " = [" << it->second.first << "; "
           << it->second.second << "];" << endl;

  for (string_options_t::const_iterator it = string_options.begin();
       it != string_options.end(); it++)
    output << "options_." << it->first << " = '" << it->second << "';" << endl;

  for (date_options_t::const_iterator it = date_options.begin();
       it != date_options.end(); it++)
    output << "options_." << it->first << " = " << it->second << ";" << endl;

  for (symbol_list_options_t::const_iterator it = symbol_list_options.begin();
       it != symbol_list_options.end(); it++)
    it->second.writeOutput("options_." + it->first, output);

  for (vec_int_options_t::const_iterator it = vector_int_options.begin();
       it != vector_int_options.end(); it++)
    {
      output << "options_." << it->first << " = ";
      if (it->second.size() > 1)
        {
          output << "[";
          for (vector<int>::const_iterator viit = it->second.begin();
               viit != it->second.end(); viit++)
            output << *viit << ";";
          output << "];" << endl;
        }
      else
        output << it->second.front() << ";" << endl;
    }
}

void
OptionsList::writeOutput(ostream &output, const string &option_group) const
{
  // Initialize option_group as an empty struct iff the field does not exist!
  unsigned idx = option_group.find_last_of(".");
  if (idx < UINT_MAX)
    {
      output << "if ~isfield(" << option_group.substr(0, idx) << ",'" << option_group.substr(idx+1) << "')" << endl;
      output << "    " << option_group << " = struct();" << endl;
      output << "end" << endl;
    }
  else
    output << option_group << " = struct();" << endl;

  for (num_options_t::const_iterator it = num_options.begin();
       it != num_options.end(); it++)
    output << option_group << "." << it->first << " = " << it->second << ";" << endl;

  for (paired_num_options_t::const_iterator it = paired_num_options.begin();
       it != paired_num_options.end(); it++)
    output << option_group << "." << it->first << " = [" << it->second.first << "; "
           << it->second.second << "];" << endl;

  for (string_options_t::const_iterator it = string_options.begin();
       it != string_options.end(); it++)
    output << option_group << "." << it->first << " = '" << it->second << "';" << endl;

  for (date_options_t::const_iterator it = date_options.begin();
       it != date_options.end(); it++)
    output << option_group << "." << it->first << " = " << it->second << ";" << endl;

  for (symbol_list_options_t::const_iterator it = symbol_list_options.begin();
       it != symbol_list_options.end(); it++)
    it->second.writeOutput(option_group + "." + it->first, output);

  for (vec_int_options_t::const_iterator it = vector_int_options.begin();
       it != vector_int_options.end(); it++)
    {
      output << option_group << "." << it->first << " = ";
      if (it->second.size() > 1)
        {
          output << "[";
          for (vector<int>::const_iterator viit = it->second.begin();
               viit != it->second.end(); viit++)
            output << *viit << ";";
          output << "];" << endl;
        }
      else
        output <<  it->second.front() << ";" << endl;
    }
}

void
OptionsList::clear()
{
  num_options.clear();
  paired_num_options.clear();
  string_options.clear();
  date_options.clear();
  symbol_list_options.clear();
  vector_int_options.clear();
}
