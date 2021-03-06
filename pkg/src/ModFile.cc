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

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <cassert>
#ifndef _WIN32
# include <unistd.h>
#endif

#include "ModFile.hh"
#include "ConfigFile.hh"
#include "ComputingTasks.hh"
#include "dyn_error.hh"
#include "dynout.hh"
#include "ExternalFunctionCalc.hh"
#include "PolishModel.hh"
#include "PolishModels.hh"
#include "DataTree.hh"

#ifdef USE_R
// For mkdir() 
#ifdef _WIN32
# include <direct.h>
#else
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
#endif
#endif


ModFile::ModFile(WarningConsolidation &warnings_arg)
  : expressions_tree(symbol_table, num_constants, external_functions_table),
    original_model(symbol_table, num_constants, external_functions_table),
    dynamic_model(symbol_table, num_constants, external_functions_table),
    trend_dynamic_model(symbol_table, num_constants, external_functions_table),
    ramsey_FOC_equations_dynamic_model(symbol_table, num_constants, external_functions_table),
    orig_ramsey_dynamic_model(symbol_table, num_constants, external_functions_table),
    static_model(symbol_table, num_constants, external_functions_table),
    steady_state_model(symbol_table, num_constants, external_functions_table, static_model),
    linear(false), block(false), byte_code(false), use_dll(false), no_static(false),
    differentiate_forward_vars(false), nonstationary_variables(false),
    param_used_with_lead_lag(false), warnings(warnings_arg)
{
}

ModFile::~ModFile()
{
  for (vector<Statement *>::iterator it = statements.begin();
       it != statements.end(); it++)
    delete (*it);
}

void
#ifdef USE_R
ModFile::evalAllExpressions(bool warn_uninit, bool warn_uninit_param, bool init_param_na)
#else
ModFile::evalAllExpressions(bool warn_uninit)
#endif

{
  DynOut << "Evaluating expressions...";

  // Loop over all statements, and fill global eval context if relevant
  for (vector<Statement *>::const_iterator it = statements.begin(); it != statements.end(); it++)
    {
      InitParamStatement *ips = dynamic_cast<InitParamStatement *>(*it);
      if (ips)
        ips->fillEvalContext(global_eval_context);

      InitOrEndValStatement *ies = dynamic_cast<InitOrEndValStatement *>(*it);
      if (ies)
        ies->fillEvalContext(global_eval_context);

      LoadParamsAndSteadyStateStatement *lpass = dynamic_cast<LoadParamsAndSteadyStateStatement *>(*it);
      if (lpass)
        lpass->fillEvalContext(global_eval_context);
    }

  // Evaluate model local variables
  dynamic_model.fillEvalContext(global_eval_context);

  DynOut << "done" << endl;

  // Check if some symbols are not initialized, and give them a zero value then
  for (int id = 0; id <= symbol_table.maxID(); id++)
    {
      SymbolType type = symbol_table.getType(id);
      if ((type == eEndogenous || type == eExogenous || type == eExogenousDet
           || type == eParameter || type == eModelLocalVariable)
          && global_eval_context.find(id) == global_eval_context.end())
        {
#ifdef USE_R
          if (warn_uninit_param && type == eParameter) {
            warnings << "WARNING: Can't find a numeric initial value for "
                     << "parameter "  << symbol_table.getName(id) << ", using ";
            if (init_param_na) {
               warnings << "NA";
            } else {
               warnings << "zero";
            }
            warnings << endl;
            
          }
          // At the moment the R version only gives warnings for
          // not-initialized parameters

          if (type == eParameter && init_param_na) {
              global_eval_context[id] = NA_REAL;
          } else {
              global_eval_context[id] = 0;
          }
#else
          if (warn_uninit)
            warnings << "WARNING: Can't find a numeric initial value for "
                     << symbol_table.getName(id) << ", using zero" << endl;
          global_eval_context[id] = 0;
#endif
        }
    }
}

void
ModFile::addStatement(Statement *st)
{
  statements.push_back(st);
}

void
ModFile::addStatementAtFront(Statement *st)
{
  statements.insert(statements.begin(), st);
}

void
ModFile::checkPass(bool nostrict)
{
  for (vector<Statement *>::iterator it = statements.begin();
       it != statements.end(); it++)
    (*it)->checkPass(mod_file_struct, warnings);

  // Check the steady state block
  steady_state_model.checkPass(mod_file_struct.ramsey_model_present, warnings);

  // If order option has not been set, default to 2
  if (!mod_file_struct.order_option)
    mod_file_struct.order_option = 2;

  param_used_with_lead_lag = dynamic_model.ParamUsedWithLeadLag();
  if (param_used_with_lead_lag)
    warnings << "WARNING: A parameter was used with a lead or a lag in the model block" << endl;

  bool stochastic_statement_present = mod_file_struct.stoch_simul_present
    || mod_file_struct.estimation_present
    || mod_file_struct.osr_present
    || mod_file_struct.ramsey_policy_present
    || mod_file_struct.discretionary_policy_present
    || mod_file_struct.calib_smoother_present;

  // Allow empty model only when doing a standalone BVAR estimation
  if (dynamic_model.equation_number() == 0
      && (mod_file_struct.check_present
          || mod_file_struct.perfect_foresight_solver_present
          || stochastic_statement_present))
    {
      dyn_error("ERROR: At least one model equation must be declared!\n");
    }

  if ((mod_file_struct.ramsey_model_present || mod_file_struct.ramsey_policy_present)
      && mod_file_struct.discretionary_policy_present)
    {
      dyn_error("ERROR: You cannot use the discretionary_policy command when you use either ramsey_model or ramsey_policy and vice versa\n");
    }

  if (((mod_file_struct.ramsey_model_present || mod_file_struct.discretionary_policy_present)
       && !mod_file_struct.planner_objective_present)
      || (!(mod_file_struct.ramsey_model_present || mod_file_struct.discretionary_policy_present)
          && mod_file_struct.planner_objective_present))
    {
      dyn_error("ERROR: A planner_objective statement must be used with a ramsey_model, a ramsey_policy or a discretionary_policy statement and vice versa.\n");
    }

  if ((mod_file_struct.osr_present && (!mod_file_struct.osr_params_present || !mod_file_struct.optim_weights_present))
      || ((!mod_file_struct.osr_present || !mod_file_struct.osr_params_present) && mod_file_struct.optim_weights_present)
      || ((!mod_file_struct.osr_present || !mod_file_struct.optim_weights_present) && mod_file_struct.osr_params_present))
    {
      dyn_error("ERROR: The osr statement must be used with osr_params and optim_weights.\n");
    }

  if (mod_file_struct.perfect_foresight_solver_present && stochastic_statement_present)
    {
      dyn_error("ERROR: A .mod file cannot contain both one of {perfect_foresight_solver,simul} and one of {stoch_simul, estimation, osr, ramsey_policy, discretionary_policy}. This is not possible: one cannot mix perfect foresight context with stochastic context in the same file.\n");
    }

  if (mod_file_struct.k_order_solver && byte_code)
    {
      dyn_error("ERROR: 'k_order_solver' (which is implicit if order >= 3), is not yet compatible with 'bytecode'.\n");
    }

  if (use_dll && (block || byte_code))
    {
      dyn_error("ERROR: In 'model' block, 'use_dll' option is not compatible with 'block' or 'bytecode'\n");
    }

  if (block || byte_code)
    if (dynamic_model.isModelLocalVariableUsed())
      {
        dyn_error("ERROR: In 'model' block, 'block' or 'bytecode' options are not yet compatible with pound expressions\n");
      }

  if ((stochastic_statement_present || mod_file_struct.check_present || mod_file_struct.steady_present) && no_static)
    {
      dyn_error("ERROR: no_static option is incompatible with stoch_simul, estimation, osr, ramsey_policy, discretionary_policy, steady and check commands\n");
    }

  if (mod_file_struct.dsge_var_estimated)
    if (!mod_file_struct.dsge_prior_weight_in_estimated_params)
      {
        dyn_error("ERROR: When estimating a DSGE-VAR model and estimating the weight of the prior, dsge_prior_weight must "
                  "be referenced in the estimated_params block.\n");
      }

  if (symbol_table.exists("dsge_prior_weight"))
    {
      if (symbol_table.getType("dsge_prior_weight") != eParameter)
        {
          dyn_error("ERROR: dsge_prior_weight may only be used as a parameter.\n");
        }
      else
        warnings << "WARNING: When estimating a DSGE-Var, declaring dsge_prior_weight as a "
                 << "parameter is deprecated. The preferred method is to do this via "
                 << "the dsge_var option in the estimation statement." << endl;

      if (mod_file_struct.dsge_var_estimated || !mod_file_struct.dsge_var_calibrated.empty())
        {
          dyn_error("ERROR: dsge_prior_weight can either be declared as a parameter (deprecated) or via the dsge_var option "
                   "to the estimation statement (preferred), but not both.\n");
        }

      if (!mod_file_struct.dsge_prior_weight_initialized && !mod_file_struct.dsge_prior_weight_in_estimated_params)
        {
          dyn_error("ERROR: If dsge_prior_weight is declared as a parameter, it must either be initialized or placed in the "
                    "estimated_params block.\n");
        }

      if (mod_file_struct.dsge_prior_weight_initialized && mod_file_struct.dsge_prior_weight_in_estimated_params)
        {
          dyn_error("ERROR: dsge_prior_weight cannot be both initialized and estimated.\n");
        }
    }

  if (mod_file_struct.dsge_prior_weight_in_estimated_params)
    if (!mod_file_struct.dsge_var_estimated && !mod_file_struct.dsge_var_calibrated.empty())
      {
        dyn_error("ERROR: If dsge_prior_weight is in the estimated_params block, the prior weight cannot be calibrated "
                  "via the dsge_var option in the estimation statement.\n");
      }
    else if (!mod_file_struct.dsge_var_estimated && !symbol_table.exists("dsge_prior_weight"))
      {
        dyn_error("ERROR: If dsge_prior_weight is in the estimated_params block, it must either be declared as a parameter "
                  "(deprecated) or the dsge_var option must be passed to the estimation statement (preferred).\n");
      }

  if (dynamic_model.staticOnlyEquationsNbr() != dynamic_model.dynamicOnlyEquationsNbr())
    {
      dyn_error("ERROR: the number of equations marked [static] must be equal to the number of equations marked [dynamic]\n");
    }

  if (dynamic_model.staticOnlyEquationsNbr() > 0
      && (mod_file_struct.ramsey_model_present || mod_file_struct.discretionary_policy_present))
    {
      dyn_error("ERROR: marking equations as [static] or [dynamic] is not possible with ramsey_model, ramsey_policy or discretionary_policy\n");
    }

  if (stochastic_statement_present
      && (dynamic_model.isUnaryOpUsed(oSign)
          || dynamic_model.isUnaryOpUsed(oAbs)
          || dynamic_model.isBinaryOpUsed(oMax)
          || dynamic_model.isBinaryOpUsed(oMin)
          || dynamic_model.isBinaryOpUsed(oGreater)
          || dynamic_model.isBinaryOpUsed(oLess)
          || dynamic_model.isBinaryOpUsed(oGreaterEqual)
          || dynamic_model.isBinaryOpUsed(oLessEqual)
          || dynamic_model.isBinaryOpUsed(oEqualEqual)
          || dynamic_model.isBinaryOpUsed(oDifferent)))
    warnings << "WARNING: you are using a function (max, min, abs, sign) or an operator (<, >, <=, >=, ==, !=) which is unsuitable for a stochastic context; see the reference manual, section about \"Expressions\", for more details." << endl;

  if (linear
      && (dynamic_model.isUnaryOpUsed(oSign)
          || dynamic_model.isUnaryOpUsed(oAbs)
          || dynamic_model.isBinaryOpUsed(oMax)
          || dynamic_model.isBinaryOpUsed(oMin)
          || dynamic_model.isBinaryOpUsed(oGreater)
          || dynamic_model.isBinaryOpUsed(oLess)
          || dynamic_model.isBinaryOpUsed(oGreaterEqual)
          || dynamic_model.isBinaryOpUsed(oLessEqual)
          || dynamic_model.isBinaryOpUsed(oEqualEqual)
          || dynamic_model.isBinaryOpUsed(oDifferent)))
    warnings << "WARNING: you have declared your model 'linear' but you are using a function (max, min, abs, sign) or an operator (<, >, <=, >=, ==, !=) which potentially makes it non-linear." << endl;

  // Test if some estimated parameters are used within the values of shocks
  // statements (see issue #469)
  set<int> parameters_intersect;
  set_intersection(mod_file_struct.parameters_within_shocks_values.begin(),
                   mod_file_struct.parameters_within_shocks_values.end(),
                   mod_file_struct.estimated_parameters.begin(),
                   mod_file_struct.estimated_parameters.end(),
                   inserter(parameters_intersect, parameters_intersect.begin()));
  if (parameters_intersect.size() > 0)
    {
      std::ostringstream msg;
      msg << "ERROR: some estimated parameters (";
      for (set<int>::const_iterator it = parameters_intersect.begin();
           it != parameters_intersect.end();)
        {
          msg << symbol_table.getName(*it);
          if (++it != parameters_intersect.end())
            msg << ", ";
        }
      msg  << ") also appear in the expressions defining the variance/covariance matrix of shocks; this is not allowed.\n";
      dyn_error(msg);
    }

  // Check if some exogenous is not used in the model block, Issue #841
  set<int> unusedExo = dynamic_model.findUnusedExogenous();
  if (unusedExo.size() > 0)
    {
      ostringstream unused_exos;
      for (set<int>::iterator it = unusedExo.begin(); it != unusedExo.end(); it++) 
#ifdef USE_R
        {
            unused_exos << " \"" << symbol_table.getName(*it) << "\"";
        }
#else
        unused_exos << symbol_table.getName(*it) < " ";
#endif

      if (nostrict)
#ifdef USE_R
        warnings << "WARNING: the following exogenous variable(s) not used in model block:" 
                 << unused_exos.str() << "." << endl;
#else 
       warnings << "WARNING: " << unused_exos.str()
                 << "not used in model block, removed by nostrict command-line option" << endl;
#endif
      else
        {
#ifdef USE_R
          dyn_error("ERROR: the following exogenous variable(s) not used in model block"
                   "\n(to bypass this error, use argument strict = FALSE):\n" + 
                   unused_exos.str() + ".");
#else 
          cerr << "ERROR: " << unused_exos.str() << "not used in model block. To bypass this error, use the `nostrict` option. This may lead to crashes or unexpected behavior." << endl;
          exit(EXIT_FAILURE);
#endif
        }
    }
}

#ifdef USE_R
void
ModFile::transformPass(bool nostrict, bool compute_xrefs, bool max_laglead_1,
                       int n_fit_derivatives)
#else
void
ModFile::transformPass(bool nostrict, bool compute_xrefs)
#endif
{
  // Save the original model (must be done before any model transformations by preprocessor)
  dynamic_model.cloneDynamic(original_model);

#ifdef USE_R
  // Unused endogenous variable. If nostrict, then remove the variable. If not
  // nostrict, then given an error.
  set<int> unusedEndogs = dynamic_model.findUnusedEndogenous();
  if (unusedEndogs.size() > 0) {
      ostringstream unused_endos;
      for (set<int>::iterator it = unusedEndogs.begin(); it != unusedEndogs.end(); it++) {
          symbol_table.changeType(*it, eUnusedEndogenous);
          unused_endos << " \"" << symbol_table.getName(*it) << "\"";
      }
      if (nostrict) {
         warnings << "WARNING: the following endogenous variable(s) not used in model block" 
                 << " are removed because strict = FALSE:"  
                 << unused_endos.str() << "." << endl;
      } else {
          dyn_error("ERROR: the following endogenous variable(s) not used in model block"
                    "\n(to bypass this error, use argument strict = FALSE):\n" 
                    + unused_endos.str() + ".");
      }
  }
#else 
  if (nostrict) 
    {
      set<int> unusedEndogs = dynamic_model.findUnusedEndogenous();
      for (set<int>::iterator it = unusedEndogs.begin(); it != unusedEndogs.end(); it++)
        {
          symbol_table.changeType(*it, eUnusedEndogenous);
          warnings << "WARNING: '" << symbol_table.getName(*it)
                   << "' not used in model block, removed by nostrict command-line option" << endl;
        }
    }
#endif

  if (symbol_table.predeterminedNbr() > 0)
    dynamic_model.transformPredeterminedVariables();

  // Create auxiliary vars for Expectation operator
  dynamic_model.substituteExpectation(mod_file_struct.partial_information);

  if (nonstationary_variables)
    {
      dynamic_model.detrendEquations(n_fit_derivatives);
      dynamic_model.cloneDynamic(trend_dynamic_model);
      dynamic_model.removeTrendVariableFromEquations(n_fit_derivatives);
    }

  mod_file_struct.orig_eq_nbr = dynamic_model.equation_number();
  if (mod_file_struct.ramsey_model_present)
    {
      StaticModel *planner_objective = NULL;
      for (vector<Statement *>::iterator it = statements.begin(); it != statements.end(); it++)
        {
          PlannerObjectiveStatement *pos = dynamic_cast<PlannerObjectiveStatement *>(*it);
          if (pos != NULL)
            planner_objective = pos->getPlannerObjective();
        }
      assert(planner_objective != NULL);

      /*
        clone the model then clone the new equations back to the original because
        we have to call computeDerivIDs (in computeRamseyPolicyFOCs and computingPass)
      */
      if (linear)
        dynamic_model.cloneDynamic(orig_ramsey_dynamic_model);
      dynamic_model.cloneDynamic(ramsey_FOC_equations_dynamic_model);
      ramsey_FOC_equations_dynamic_model.computeRamseyPolicyFOCs(*planner_objective);
      ramsey_FOC_equations_dynamic_model.replaceMyEquations(dynamic_model);
      mod_file_struct.ramsey_eq_nbr = dynamic_model.equation_number() - mod_file_struct.orig_eq_nbr;
    }

  // Workaround for #1193
  if (!mod_file_struct.hist_vals_wrong_lag.empty())
    {
      bool err = false;
      for (map<int, int>::const_iterator it = mod_file_struct.hist_vals_wrong_lag.begin();
           it != mod_file_struct.hist_vals_wrong_lag.end(); it++)
          if (dynamic_model.minLagForSymbol(it->first) > it->second - 1)
            {
              DynErr << "ERROR: histval: variable " << symbol_table.getName(it->first)
                     << " does not appear in the model with the lag " << it->second - 1
                     << " (see the reference manual for the timing convention in 'histval')" << endl;
              err = true;
            }
      if (err)
        dyn_error("Histval values with wrong lag\n");
    }

  if (mod_file_struct.stoch_simul_present
      || mod_file_struct.estimation_present
      || mod_file_struct.osr_present
      || mod_file_struct.ramsey_policy_present
      || mod_file_struct.discretionary_policy_present
      || mod_file_struct.calib_smoother_present)
    {
      // In stochastic models, create auxiliary vars for leads and lags greater than 2, on both endos and exos
      dynamic_model.substituteEndoLeadGreaterThanTwo(false);
      dynamic_model.substituteExoLead(false);
      dynamic_model.substituteEndoLagGreaterThanTwo(false);
      dynamic_model.substituteExoLag(false);
    }
#ifdef USE_R
  else if (max_laglead_1) 
      // For package dynmdl, it is not required to substitute
      // lags and leads > 2, except in function check_mdl. */
#else
  else
#endif
    {
      // In deterministic models, create auxiliary vars for leads and lags endogenous greater than 2, only on endos (useless on exos)
      dynamic_model.substituteEndoLeadGreaterThanTwo(true);
      dynamic_model.substituteEndoLagGreaterThanTwo(true);
   }
  if (differentiate_forward_vars)
    dynamic_model.differentiateForwardVars(differentiate_forward_vars_subset);

  if (mod_file_struct.dsge_var_estimated || !mod_file_struct.dsge_var_calibrated.empty())
    try
      {
        int sid = symbol_table.addSymbol("dsge_prior_weight", eParameter);
        if (!mod_file_struct.dsge_var_calibrated.empty())
          addStatementAtFront(new InitParamStatement(sid,
                                                     expressions_tree.AddNonNegativeConstant(mod_file_struct.dsge_var_calibrated),
                                                     symbol_table));
      }
    catch (SymbolTable::AlreadyDeclaredException &e)
      {
        dyn_error("ERROR: dsge_prior_weight should not be declared as a model variable / parameter "
                  "when the dsge_var option is passed to the estimation statement.\n");
      }

  // Freeze the symbol table
  symbol_table.freeze();

  if (compute_xrefs)
    dynamic_model.computeXrefs();

  /*
    Enforce the same number of equations and endogenous, except in three cases:
    - ramsey_model, ramsey_policy or discretionary_policy is used
    - a BVAR command is used and there is no equation (standalone BVAR estimation)
    - nostrict option is passed and there are more endogs than equations (dealt with before freeze)
  */
  if (!(mod_file_struct.ramsey_model_present || mod_file_struct.discretionary_policy_present)
      && !(mod_file_struct.bvar_present && dynamic_model.equation_number() == 0)
      && (dynamic_model.equation_number() != symbol_table.endo_nbr()))
    {
      std::ostringstream msg;
      msg << "ERROR: There are " << dynamic_model.equation_number() << " equations but " << symbol_table.endo_nbr() << " endogenous variables!\n";
      dyn_error(msg);
    }

  if (symbol_table.exo_det_nbr() > 0 && mod_file_struct.perfect_foresight_solver_present)
    {
      dyn_error("ERROR: A .mod file cannot contain both one of {perfect_foresight_solver, simul} and varexo_det declaration (all exogenous variables are deterministic in this case)\n");
    }

  if (mod_file_struct.ramsey_policy_present && symbol_table.exo_det_nbr() > 0)
    {
      dyn_error("ERROR: ramsey_policy is incompatible with deterministic exogenous variables\n");
    }

  if (mod_file_struct.ramsey_policy_present)
    for (vector<Statement *>::iterator it = statements.begin(); it != statements.end(); it++)
      {
        RamseyPolicyStatement *rps = dynamic_cast<RamseyPolicyStatement *>(*it);
        if (rps != NULL)
          rps->checkRamseyPolicyList();
      }

  if (mod_file_struct.identification_present && symbol_table.exo_det_nbr() > 0)
    {
      dyn_error("ERROR: identification is incompatible with deterministic exogenous variables\n");
    }

  if (!mod_file_struct.ramsey_model_present)
    DynOut << "Found " << dynamic_model.equation_number() << " equation(s)." << endl;
  else
    {
      DynOut << "Found " << mod_file_struct.orig_eq_nbr  << " equation(s)." << endl;
      DynOut << "Found " << dynamic_model.equation_number() << " FOC equation(s) for Ramsey Problem." << endl;
    }

  if (symbol_table.exists("dsge_prior_weight"))
    if (mod_file_struct.bayesian_irf_present)
      {
        if (symbol_table.exo_nbr() != symbol_table.observedVariablesNbr())
          {
            dyn_error("ERROR: When estimating a DSGE-Var and the bayesian_irf option is passed to the estimation "
                      "statement, the number of shocks must equal the number of observed variables.\n");
          }
      }
    else
      if (symbol_table.exo_nbr() < symbol_table.observedVariablesNbr())
        {
          dyn_error("ERROR: When estimating a DSGE-Var, the number of shocks must be "
                    "greater than or equal to the number of observed variables.\n");
        }
}

#ifdef USE_R
void ModFile::computingPass(bool no_tmp_terms, FileOutputType output, 
                            int params_derivs_order, bool fit_deriv) {
#else
void
ModFile::computingPass(bool no_tmp_terms, FileOutputType output, int params_derivs_order)
{
#endif
  // Mod file may have no equation (for example in a standalone BVAR estimation)
  if (dynamic_model.equation_number() > 0)
    {
      if (nonstationary_variables)
        trend_dynamic_model.runTrendTest(global_eval_context);

      // Compute static model and its derivatives
      dynamic_model.toStatic(static_model);
      if (!no_static)
        {
          if (mod_file_struct.stoch_simul_present
              || mod_file_struct.estimation_present || mod_file_struct.osr_present
              || mod_file_struct.ramsey_model_present || mod_file_struct.identification_present
              || mod_file_struct.calib_smoother_present)
            static_model.set_cutoff_to_zero();

#ifdef USE_R
          const bool static_hessian = false;
#else
          const bool static_hessian = mod_file_struct.identification_present
            || mod_file_struct.estimation_analytic_derivation;
#endif
          int paramsDerivsOrder = 0;
          if (mod_file_struct.identification_present || mod_file_struct.estimation_analytic_derivation)
            paramsDerivsOrder = params_derivs_order;
#ifdef USE_R
          // if the derivatives are computed for constructing fit derivatives, then
          // we should calculate the derivatives w.r.t. the exogenous variables
          bool jacobianExo = fit_deriv;
          static_model.computingPass(jacobianExo, global_eval_context, no_tmp_terms, static_hessian,
                                     false, paramsDerivsOrder, block, byte_code);
#else
          static_model.computingPass(global_eval_context, no_tmp_terms, static_hessian,
                                     false, paramsDerivsOrder, block, byte_code);
#endif
        }

#ifdef USE_R
       dynamic_model.computingPass(true, false, false, none, global_eval_context, 
                                  no_tmp_terms, block, use_dll, byte_code);
#else
      // Set things to compute for dynamic model
      if (mod_file_struct.perfect_foresight_solver_present || mod_file_struct.check_present
          || mod_file_struct.stoch_simul_present
          || mod_file_struct.estimation_present || mod_file_struct.osr_present
          || mod_file_struct.ramsey_model_present || mod_file_struct.identification_present
          || mod_file_struct.calib_smoother_present)
        {
          if (mod_file_struct.perfect_foresight_solver_present)
            dynamic_model.computingPass(true, false, false, none, global_eval_context, no_tmp_terms, block, use_dll, byte_code);
          else
            {
              if (mod_file_struct.stoch_simul_present
                  || mod_file_struct.estimation_present || mod_file_struct.osr_present
                  || mod_file_struct.ramsey_model_present || mod_file_struct.identification_present
                  || mod_file_struct.calib_smoother_present)
                dynamic_model.set_cutoff_to_zero();
              if (mod_file_struct.order_option < 1 || mod_file_struct.order_option > 3)
                {
                  dyn_error("ERROR: Incorrect order option...\n");
                }
              bool hessian = mod_file_struct.order_option >= 2
                || mod_file_struct.identification_present
                || mod_file_struct.estimation_analytic_derivation
                || linear
                || output == second
                || output == third;
              bool thirdDerivatives = mod_file_struct.order_option == 3
                || mod_file_struct.estimation_analytic_derivation
                || output == third;
              int paramsDerivsOrder = 0;
              if (mod_file_struct.identification_present || mod_file_struct.estimation_analytic_derivation)
                paramsDerivsOrder = params_derivs_order;
              dynamic_model.computingPass(true, hessian, thirdDerivatives, paramsDerivsOrder, global_eval_context, no_tmp_terms, block, use_dll, byte_code);
              if (linear && mod_file_struct.ramsey_model_present)
                orig_ramsey_dynamic_model.computingPass(true, true, false, paramsDerivsOrder, global_eval_context, no_tmp_terms, block, use_dll, byte_code);
            }
        }
      else // No computing task requested, compute derivatives up to 2nd order by default
        dynamic_model.computingPass(true, true, false, none, global_eval_context, no_tmp_terms, block, use_dll, byte_code);
#endif

      if ((linear && !mod_file_struct.ramsey_model_present && !dynamic_model.checkHessianZero())
          || (linear && mod_file_struct.ramsey_model_present && !orig_ramsey_dynamic_model.checkHessianZero()))
        {
          map<int, string> eqs;
          if (mod_file_struct.ramsey_model_present)
            orig_ramsey_dynamic_model.getNonZeroHessianEquations(eqs);
          else
            dynamic_model.getNonZeroHessianEquations(eqs);

          std::ostringstream msg;
          msg << "ERROR: If the model is declared linear the second derivatives must be equal to zero.\n"
                    "       The following equations had non-zero second derivatives:" << endl;
          for (map<int, string >::const_iterator it = eqs.begin(); it != eqs.end(); it++)
            {
              msg << "       * Eq # " << it->first+1;
              if (!it->second.empty())
                msg << " [" << it->second << "]";
              msg << endl;
            }
          dyn_error(msg);
        }
    }

  for (vector<Statement *>::iterator it = statements.begin();
       it != statements.end(); it++)
    (*it)->computingPass();
}

void
ModFile::writeOutputFiles(const string &basename, bool clear_all, bool clear_global, bool no_log, bool no_warn,
                          bool console, bool nograph, bool nointeractive, const ConfigFile &config_file,
                          bool check_model_changes, bool minimal_workspace, bool compute_xrefs
#if defined(_WIN32) || defined(__CYGWIN32__)
                          , bool cygwin, bool msvc, bool mingw
#endif
                          ) const
{
  ofstream mOutputFile;

  if (basename.size())
    {
      string fname(basename);
      fname += ".m";
      mOutputFile.open(fname.c_str(), ios::out | ios::binary);
      if (!mOutputFile.is_open())
        {
          dyn_error("ERROR: Can't open file " + fname + " for writing\n");
        }
    }
  else
    {
      dyn_error("ERROR: Missing file name\n");
    }

  mOutputFile << "%" << endl
              << "% Status : main Dynare file" << endl
              << "%" << endl
              << "% Warning : this file is generated automatically by Dynare" << endl
              << "%           from model file (.mod)" << endl << endl;

  if (no_warn)
    mOutputFile << "warning off" << endl; // This will be executed *after* function warning_config()

  if (clear_all)
    mOutputFile << "if isoctave || matlab_ver_less_than('8.6')" << endl
                << "    clear all" << endl
                << "else" << endl
                << "    clearvars -global" << endl
                << "    clear_persistent_variables(fileparts(which('dynare')), false)" << endl
                << "end" << endl;
  else if (clear_global)
    mOutputFile << "clear M_ options_ oo_ estim_params_ bayestopt_ dataset_ dataset_info estimation_info ys0_ ex0_;" << endl;

  mOutputFile << "tic0 = tic;" << endl
              << "% Save empty dates and dseries objects in memory." << endl
              << "dates('initialize');" << endl
              << "dseries('initialize');" << endl
              << "% Define global variables." << endl
              << "global M_ options_ oo_ estim_params_ bayestopt_ dataset_ dataset_info estimation_info ys0_ ex0_" << endl
              << "options_ = [];" << endl
              << "M_.fname = '" << basename << "';" << endl
              << "M_.dynare_version = '" << PACKAGE_VERSION << "';" << endl
              << "oo_.dynare_version = '" << PACKAGE_VERSION << "';" << endl
              << "options_.dynare_version = '" << PACKAGE_VERSION << "';" << endl
              << "%" << endl
              << "% Some global variables initialization" << endl
              << "%" << endl;
  config_file.writeHooks(mOutputFile);
  mOutputFile << "global_initialization;" << endl
              << "diary off;" << endl;
  if (!no_log)
    mOutputFile << "diary('" << basename << ".log');" << endl;

  if (minimal_workspace)
    mOutputFile << "options_.minimal_workspace = 1;" << endl;

  if (console)
    mOutputFile << "options_.console_mode = 1;" << endl
                << "options_.nodisplay = 1;" << endl;
  if (nograph)
    mOutputFile << "options_.nograph = 1;" << endl;

  if (nointeractive)
    mOutputFile << "options_.nointeractive = 1;" << endl;

  if (param_used_with_lead_lag)
    mOutputFile << "M_.parameter_used_with_lead_lag = true;" << endl;

  DynOut << "Processing outputs ..." << endl;

  symbol_table.writeOutput(mOutputFile);

  // Initialize M_.Sigma_e, M_.Correlation_matrix, M_.H, and M_.Correlation_matrix_ME
  mOutputFile << "M_.Sigma_e = zeros(" << symbol_table.exo_nbr() << ", "
              << symbol_table.exo_nbr() << ");" << endl
              << "M_.Correlation_matrix = eye(" << symbol_table.exo_nbr() << ", "
              << symbol_table.exo_nbr() << ");" << endl;

  if (mod_file_struct.calibrated_measurement_errors)
    mOutputFile << "M_.H = zeros(" << symbol_table.observedVariablesNbr() << ", "
                << symbol_table.observedVariablesNbr() << ");" << endl
                << "M_.Correlation_matrix_ME = eye(" << symbol_table.observedVariablesNbr() << ", "
                << symbol_table.observedVariablesNbr() << ");" << endl;
  else
    mOutputFile << "M_.H = 0;" << endl
                << "M_.Correlation_matrix_ME = 1;" << endl;

  // May be later modified by a shocks block
  mOutputFile << "M_.sigma_e_is_diagonal = 1;" << endl;

  // Initialize M_.det_shocks
  mOutputFile << "M_.det_shocks = [];" << endl;

  if (linear == 1)
    mOutputFile << "options_.linear = 1;" << endl;

  mOutputFile << "options_.block=" << block << ";" << endl
              << "options_.bytecode=" << byte_code << ";" << endl
              << "options_.use_dll=" << use_dll << ";" << endl;

  if (parallel_local_files.size() > 0)
    {
      mOutputFile << "options_.parallel_info.local_files = {" << endl;
      for (size_t i = 0; i < parallel_local_files.size(); i++)
        {
          size_t j = parallel_local_files[i].find_last_of("/\\");
          if (j == string::npos)
            mOutputFile << "'', '" << parallel_local_files[i] << "';" << endl;
          else
            mOutputFile << "'" << parallel_local_files[i].substr(0, j+1) << "', '"
                        << parallel_local_files[i].substr(j+1, string::npos) << "';" << endl;
        }
      mOutputFile << "};" << endl;
    }

  mOutputFile << "M_.hessian_eq_zero = " << dynamic_model.checkHessianZero() << ";" << endl;

  config_file.writeCluster(mOutputFile);

  if (byte_code)
    mOutputFile << "if exist('bytecode') ~= 3" << endl
                << "  error('DYNARE: Can''t find bytecode DLL. Please compile it or remove the ''bytecode'' option.')" << endl
                << "end" << endl;

  bool hasModelChanged = !dynamic_model.isChecksumMatching(basename);
  if (!check_model_changes)
    hasModelChanged = true;

  if (hasModelChanged)
    {
      // Erase possible remnants of previous runs
      unlink((basename + "_dynamic.m").c_str());
      unlink((basename + "_dynamic.cod").c_str());
      unlink((basename + "_dynamic.bin").c_str());

      unlink((basename + "_static.m").c_str());
      unlink((basename + "_static.cod").c_str());
      unlink((basename + "_static.bin").c_str());

      unlink((basename + "_steadystate2.m").c_str());
      unlink((basename + "_set_auxiliary_variables.m").c_str());
    }

  if (!use_dll)
    {
      mOutputFile << "erase_compiled_function('" + basename + "_static');" << endl;
      mOutputFile << "erase_compiled_function('" + basename + "_dynamic');" << endl;
    }

#if defined(_WIN32) || defined(__CYGWIN32__)
# if (defined(_MSC_VER) && _MSC_VER < 1700)
  // If using USE_DLL with MSVC 10.0 or earlier, check that the user didn't use a function not supported by the compiler (because MSVC <= 10.0 doesn't comply with C99 standard)
  if (use_dll && msvc)
    {
      if (dynamic_model.isUnaryOpUsed(oAcosh))
        {
          dyn_error("ERROR: acosh() function is not supported with USE_DLL option and older MSVC compilers; use Cygwin, MinGW or upgrade your MSVC compiler to 11.0 (2012) or later.\n");
        }
      if (dynamic_model.isUnaryOpUsed(oAsinh))
        {
          dyn_error("ERROR: asinh() function is not supported with USE_DLL option and older MSVC compilers; use Cygwin, MinGW or upgrade your MSVC compiler to 11.0 (2012) or later.\n");
        }
      if (dynamic_model.isUnaryOpUsed(oAtanh))
        {
          dyn_error("ERROR: atanh() function is not supported with USE_DLL option and older MSVC compilers; use Cygwin, MinGW or upgrade your MSVC compiler to 11.0 (2012) or later.\n");
        }
    }
# endif
#endif

  // Compile the dynamic MEX file for use_dll option
  // When check_model_changes is true, don't force compile if MEX is fresher than source
  if (use_dll)
    {
#if defined(_WIN32) || defined(__CYGWIN32__) || defined(__MINGW32__)
      if (msvc)
        // MATLAB/Windows + Microsoft Visual C++
        mOutputFile << "dyn_mex('msvc', '" << basename << "', " << !check_model_changes << ")" <<  endl;
      else if (cygwin)
        // MATLAB/Windows + Cygwin g++
        mOutputFile << "dyn_mex('cygwin', '" << basename << "', " << !check_model_changes << ")" << endl;
      else if (mingw)
        // MATLAB/Windows + MinGW g++
        mOutputFile << "dyn_mex('mingw', '" << basename << "', " << !check_model_changes << ")" << endl;
      else
        mOutputFile << "if isoctave" << endl
                    << "    dyn_mex('', '" << basename << "', " << !check_model_changes << ")" << endl
                    << "else" << endl
                    << "    error('When using the USE_DLL option on Matlab, you must give the ''cygwin'', ''msvc'', or ''mingw'' option to the ''dynare'' command')" << endl
                    << "end" << endl;
#else
      // other configurations
      mOutputFile << "dyn_mex('', '" << basename << "', " << !check_model_changes << ")" << endl;
#endif
    }

  // Add path for block option with M-files
  if (block && !byte_code)
    mOutputFile << "addpath " << basename << ";" << endl;

  mOutputFile << "M_.orig_eq_nbr = " << mod_file_struct.orig_eq_nbr << ";" << endl
              << "M_.eq_nbr = " << dynamic_model.equation_number() << ";" << endl
              << "M_.ramsey_eq_nbr = " << mod_file_struct.ramsey_eq_nbr << ";" << endl
              << "M_.set_auxiliary_variables = exist(['./' M_.fname '_set_auxiliary_variables.m'], 'file') == 2;" << endl;

  if (dynamic_model.equation_number() > 0)
    {
      dynamic_model.writeOutput(mOutputFile, basename, block, byte_code, use_dll, mod_file_struct.order_option, mod_file_struct.estimation_present, compute_xrefs, false);
      if (!no_static)
        static_model.writeOutput(mOutputFile, block);
    }

  // Print statements
  for (vector<Statement *>::const_iterator it = statements.begin();
       it != statements.end(); it++)
    {
      (*it)->writeOutput(mOutputFile, basename, minimal_workspace);

      /* Special treatment for initval block: insert initial values for the
         auxiliary variables and initialize exo det */
      InitValStatement *ivs = dynamic_cast<InitValStatement *>(*it);
      if (ivs != NULL)
        {
          static_model.writeAuxVarInitval(mOutputFile, oMatlabOutsideModel);
          ivs->writeOutputPostInit(mOutputFile);
        }

      // Special treatment for endval block: insert initial values for the auxiliary variables
      EndValStatement *evs = dynamic_cast<EndValStatement *>(*it);
      if (evs != NULL)
        static_model.writeAuxVarInitval(mOutputFile, oMatlabOutsideModel);

      // Special treatment for load params and steady state statement: insert initial values for the auxiliary variables
      LoadParamsAndSteadyStateStatement *lpass = dynamic_cast<LoadParamsAndSteadyStateStatement *>(*it);
      if (lpass && !no_static)
        static_model.writeAuxVarInitval(mOutputFile, oMatlabOutsideModel);
    }

  // Remove path for block option with M-files
  if (block && !byte_code)
    mOutputFile << "rmpath " << basename << ";" << endl;

  mOutputFile << "save('" << basename << "_results.mat', 'oo_', 'M_', 'options_');" << endl
              << "if exist('estim_params_', 'var') == 1" << endl
              << "  save('" << basename << "_results.mat', 'estim_params_', '-append');" << endl << "end" << endl
              << "if exist('bayestopt_', 'var') == 1" << endl
              << "  save('" << basename << "_results.mat', 'bayestopt_', '-append');" << endl << "end" << endl
              << "if exist('dataset_', 'var') == 1" << endl
              << "  save('" << basename << "_results.mat', 'dataset_', '-append');" << endl << "end" << endl
              << "if exist('estimation_info', 'var') == 1" << endl
              << "  save('" << basename << "_results.mat', 'estimation_info', '-append');" << endl << "end" << endl
              << "if exist('dataset_info', 'var') == 1" << endl
              << "  save('" << basename << "_results.mat', 'dataset_info', '-append');" << endl << "end" << endl
              << "if exist('oo_recursive_', 'var') == 1" << endl
              << "  save('" << basename << "_results.mat', 'oo_recursive_', '-append');" << endl << "end" << endl;

  config_file.writeEndParallel(mOutputFile);

  mOutputFile << endl << endl
              << "disp(['Total computing time : ' dynsec2hms(toc(tic0)) ]);" << endl;

  if (!no_warn)
    {
      if (warnings.countWarnings() > 0)
        mOutputFile << "disp('Note: " << warnings.countWarnings() << " warning(s) encountered in the preprocessor')" << endl;

      mOutputFile << "if ~isempty(lastwarn)" << endl
                  << "  disp('Note: warning(s) encountered in MATLAB/Octave code')" << endl
                  << "end" << endl;
    }

  if (!no_log)
    mOutputFile << "diary off" << endl;

  mOutputFile.close();

  if (hasModelChanged)
    {
      // Create static and dynamic files
      if (dynamic_model.equation_number() > 0)
        {
          if (!no_static)
            {
              static_model.writeStaticFile(basename, block, byte_code, use_dll, false);
              static_model.writeParamsDerivativesFile(basename, false);
            }

          dynamic_model.writeDynamicFile(basename, block, byte_code, use_dll, mod_file_struct.order_option, false);
          dynamic_model.writeParamsDerivativesFile(basename, false);
        }

      // Create steady state file
      steady_state_model.writeSteadyStateFile(basename, mod_file_struct.ramsey_model_present, false);
    }

  DynOut << "done" << endl;
}

void
ModFile::writeExternalFiles(const string &basename, FileOutputType output, LanguageOutputType language) const
{
  switch (language)
    {
    case c:
      writeExternalFilesC(basename, output);
      break;
    case cpp:
      writeExternalFilesCC(basename, output);
      break;
    case julia:
      writeExternalFilesJulia(basename, output);
      break;
    default:
      dyn_error("This case shouldn't happen. Contact the authors of Dynare\n");
    }
}

void
ModFile::writeExternalFilesC(const string &basename, FileOutputType output) const
{
  writeModelC(basename);
  steady_state_model.writeSteadyStateFileC(basename, mod_file_struct.ramsey_model_present);

  dynamic_model.writeDynamicFile(basename, block, byte_code, use_dll, mod_file_struct.order_option, false);

  if (!no_static)
    static_model.writeStaticFile(basename, false, false, true, false);

  //  static_model.writeStaticCFile(basename, block, byte_code, use_dll);
  //  static_model.writeParamsDerivativesFileC(basename, cuda);
  //  static_model.writeAuxVarInitvalC(mOutputFile, oMatlabOutsideModel, cuda);

  dynamic_model.writeResidualsC(basename, cuda);
  // dynamic_model.writeParamsDerivativesFileC(basename, cuda);
  dynamic_model.writeFirstDerivativesC(basename, cuda);

  if (output == second)
    dynamic_model.writeSecondDerivativesC_csr(basename, cuda);
  else if (output == third)
    {
      dynamic_model.writeSecondDerivativesC_csr(basename, cuda);
      dynamic_model.writeThirdDerivativesC_csr(basename, cuda);
    }
}

void
ModFile::writeModelC(const string &basename) const
{
  string filename = basename + ".c";

  ofstream mDriverCFile;
  mDriverCFile.open(filename.c_str(), ios::out | ios::binary);
  if (!mDriverCFile.is_open())
    {
      dyn_error("Error: Can't open file " + filename + " for writing\n");
    }

  mDriverCFile << "/*" << endl
               << " * " << filename << " : Driver file for Dynare C code" << endl
               << " *" << endl
               << " * Warning : this file is generated automatically by Dynare" << endl
               << " *           from model file (.mod)" << endl
               << " */" << endl
               << endl
               << "#include \"dynare_driver.h\"" << endl
               << endl
               << "struct" << endl
               << "{" << endl;

  // Write basic info
  symbol_table.writeCOutput(mDriverCFile);

  mDriverCFile << endl << "params.resize(param_nbr);" << endl;

  if (dynamic_model.equation_number() > 0)
    {
      dynamic_model.writeCOutput(mDriverCFile, basename, block, byte_code, use_dll, mod_file_struct.order_option, mod_file_struct.estimation_present);
      //      if (!no_static)
      //        static_model.writeCOutput(mOutputFile, block);
    }

  // Print statements
  for (vector<Statement *>::const_iterator it = statements.begin();
       it != statements.end(); it++)
    (*it)->writeCOutput(mDriverCFile, basename);

  mDriverCFile << "} DynareInfo;" << endl;
  mDriverCFile.close();

  // Write informational m file
  ofstream mOutputFile;

  if (basename.size())
    {
      string fname(basename);
      fname += ".m";
      mOutputFile.open(fname.c_str(), ios::out | ios::binary);
      if (!mOutputFile.is_open())
        {
          dyn_error("ERROR: Can't open file " + fname
               + " for writing\n");
        }
    }
  else
    {
      dyn_error("ERROR: Missing file name\n");
    }

  mOutputFile << "%" << endl
              << "% Status : informational m file" << endl
              << "%" << endl
              << "% Warning : this file is generated automatically by Dynare" << endl
              << "%           from model file (.mod)" << endl << endl
              << "disp('The following C file was successfully created:');" << endl
              << "ls preprocessorOutput.c" << endl << endl;
  mOutputFile.close();
}

void
ModFile::writeExternalFilesCC(const string &basename, FileOutputType output) const
{
  writeModelCC(basename);
  steady_state_model.writeSteadyStateFileC(basename, mod_file_struct.ramsey_model_present);

  dynamic_model.writeDynamicFile(basename, block, byte_code, use_dll, mod_file_struct.order_option, false);

  if (!no_static)
    static_model.writeStaticFile(basename, false, false, true, false);

  //  static_model.writeStaticCFile(basename, block, byte_code, use_dll);
  //  static_model.writeParamsDerivativesFileC(basename, cuda);
  //  static_model.writeAuxVarInitvalC(mOutputFile, oMatlabOutsideModel, cuda);

  // dynamic_model.writeResidualsC(basename, cuda);
  // dynamic_model.writeParamsDerivativesFileC(basename, cuda);
  dynamic_model.writeResidualsC(basename, cuda);
  dynamic_model.writeFirstDerivativesC_csr(basename, cuda);

  if (output == second)
    dynamic_model.writeSecondDerivativesC_csr(basename, cuda);
  else if (output == third)
    {
      dynamic_model.writeSecondDerivativesC_csr(basename, cuda);
      dynamic_model.writeThirdDerivativesC_csr(basename, cuda);
    }
}

void
ModFile::writeModelCC(const string &basename) const
{
  string filename = basename + ".cc";

  ofstream mDriverCFile;
  mDriverCFile.open(filename.c_str(), ios::out | ios::binary);
  if (!mDriverCFile.is_open())
    {
      dyn_error("Error: Can't open file " + filename + " for writing\n");
    }

  mDriverCFile << "/*" << endl
               << " * " << filename << " : Driver file for Dynare C++ code" << endl
               << " *" << endl
               << " * Warning : this file is generated automatically by Dynare" << endl
               << " *           from model file (.mod)" << endl
               << " */" << endl
               << endl
               << "#include \"dynare_cpp_driver.hh\"" << endl
               << endl
               << "DynareInfo::DynareInfo(void)" << endl
               << "{" << endl;

  // Write basic info
  symbol_table.writeCCOutput(mDriverCFile);

  mDriverCFile << endl << "params.resize(param_nbr);" << endl;

  if (dynamic_model.equation_number() > 0)
    {
      dynamic_model.writeCCOutput(mDriverCFile, basename, block, byte_code, use_dll, mod_file_struct.order_option, mod_file_struct.estimation_present);
      //      if (!no_static)
      //        static_model.writeCOutput(mOutputFile, block);
    }

  // Print statements
  for (vector<Statement *>::const_iterator it = statements.begin();
       it != statements.end(); it++)
    (*it)->writeCOutput(mDriverCFile, basename);

  mDriverCFile << "};" << endl;
  mDriverCFile.close();

  // Write informational m file
  ofstream mOutputFile;

  if (basename.size())
    {
      string fname(basename);
      fname += ".m";
      mOutputFile.open(fname.c_str(), ios::out | ios::binary);
      if (!mOutputFile.is_open())
        {
          dyn_error("ERROR: Can't open file " + fname
               + " for writing\n");
        }
    }
  else
    {
      dyn_error("ERROR: Missing file name\n");
    }

  mOutputFile << "%" << endl
              << "% Status : informational m file" << endl
              << "%" << endl
              << "% Warning : this file is generated automatically by Dynare" << endl
              << "%           from model file (.mod)" << endl << endl
              << "disp('The following C++ file was successfully created:');" << endl
              << "ls preprocessorOutput.cc" << endl << endl;
  mOutputFile.close();
}

void
ModFile::writeExternalFilesJulia(const string &basename, FileOutputType output) const
{
  ofstream jlOutputFile;
  if (basename.size())
    {
      string fname(basename);
      fname += ".jl";
      jlOutputFile.open(fname.c_str(), ios::out | ios::binary);
      if (!jlOutputFile.is_open())
        {
          dyn_error("ERROR: Can't open file " + fname
               + " for writing\n");
        }
    }
  else
    {
      dyn_error("ERROR: Missing file name\n");
    }

  jlOutputFile << "module " << basename << endl
               << "#" << endl
               << "# NB: this file was automatically generated by Dynare" << endl
               << "#     from " << basename << ".mod" << endl
               << "#" << endl << endl
               << "using DynareModel" << endl
               << "using DynareOptions" << endl
               << "using DynareOutput" << endl << endl
               << "using Utils" << endl
               << "using SteadyState" << endl << endl
               << "using " << basename << "Static" << endl
               << "using " << basename << "Dynamic" << endl
               << "if isfile(\"" << basename << "SteadyState.jl"  "\")" << endl
               << "    using " << basename << "SteadyState" << endl
               << "end" << endl
               << "if isfile(\"" << basename << "SteadyState2.jl"  "\")" << endl
               << "    using " << basename << "SteadyState2" << endl
               << "end" << endl << endl
               << "export model_, options_, oo_" << endl;

  // Write Output
  jlOutputFile << endl
               << "oo_ = dynare_output()" << endl
               << "oo_.dynare_version = \"" << PACKAGE_VERSION << "\"" << endl;

  // Write Options
  jlOutputFile << endl
               << "options_ = dynare_options()" << endl
               << "options_.dynare_version = \"" << PACKAGE_VERSION << "\"" << endl;
  if (linear == 1)
    jlOutputFile << "options_.linear = true" << endl;

  // Write Model
  jlOutputFile << endl
               << "model_ = dynare_model()" << endl
               << "model_.fname = \"" << basename << "\"" << endl
               << "model_.dynare_version = \"" << PACKAGE_VERSION << "\"" << endl
               << "model_.sigma_e = zeros(Float64, " << symbol_table.exo_nbr() << ", "
               << symbol_table.exo_nbr() << ")" << endl
               << "model_.correlation_matrix = ones(Float64, " << symbol_table.exo_nbr() << ", "
               << symbol_table.exo_nbr() << ")" << endl
               << "model_.orig_eq_nbr = " << mod_file_struct.orig_eq_nbr << endl
               << "model_.eq_nbr = " << dynamic_model.equation_number() << endl
               << "model_.ramsey_eq_nbr = " << mod_file_struct.ramsey_eq_nbr << endl;

  if (mod_file_struct.calibrated_measurement_errors)
    jlOutputFile << "model_.h = zeros(Float64,"
                 << symbol_table.observedVariablesNbr() << ", "
                 << symbol_table.observedVariablesNbr() << ");" << endl
                 << "model_.correlation_matrix_me = ones(Float64, "
                 << symbol_table.observedVariablesNbr() << ", "
                 << symbol_table.observedVariablesNbr() << ");" << endl;
  else
    jlOutputFile << "model_.h = zeros(Float64, 1, 1)" << endl
                 << "model_.correlation_matrix_me = ones(Float64, 1, 1)" << endl;

  DynOut << "Processing outputs ..." << endl;
  symbol_table.writeJuliaOutput(jlOutputFile);

  if (dynamic_model.equation_number() > 0)
    {
      dynamic_model.writeOutput(jlOutputFile, basename, false, false, false,
                                mod_file_struct.order_option,
                                mod_file_struct.estimation_present, false, true);
      if (!no_static)
        {
          static_model.writeStaticFile(basename, false, false, false, true);
          static_model.writeParamsDerivativesFile(basename, true);
        }
      dynamic_model.writeDynamicFile(basename, block, byte_code, use_dll,
                                     mod_file_struct.order_option, true);
      dynamic_model.writeParamsDerivativesFile(basename, true);
    }
  steady_state_model.writeSteadyStateFile(basename, mod_file_struct.ramsey_model_present, true);

  // Print statements (includes parameter values)
  for (vector<Statement *>::const_iterator it = statements.begin();
       it != statements.end(); it++)
    (*it)->writeJuliaOutput(jlOutputFile, basename);

  jlOutputFile << "model_.static = " << basename << "Static.static!" << endl
               << "model_.dynamic = " << basename << "Dynamic.dynamic!" << endl
               << "if isfile(\"" << basename << "SteadyState.jl"  "\")" << endl
               << "    model_.user_written_analytical_steady_state = true" << endl
               << "    model_.steady_state = " << basename << "SteadyState.steady_state!" << endl
               << "end" << endl
               << "if isfile(\"" << basename << "SteadyState2.jl"  "\")" << endl
               << "    model_.analytical_steady_state = true" << endl
               << "    model_.steady_state = " << basename << "SteadyState2.steady_state!" << endl
               << "end" << endl
               << "if isfile(\"" << basename << "StaticParamsDerivs.jl"  "\")" << endl
               << "    using " << basename << "StaticParamsDerivs" << endl
               << "    model_.static_params_derivs = " << basename << "StaticParamsDerivs.params_derivs" << endl
               << "end" << endl
               << "if isfile(\"" << basename << "DynamicParamsDerivs.jl"  "\")" << endl
               << "    using " << basename << "DynamicParamsDerivs" << endl
               << "    model_.dynamic_params_derivs = " << basename << "DynamicParamsDerivs.params_derivs" << endl
               << "end" << endl
               << "end" << endl;
  jlOutputFile.close();
  DynOut << "done" << endl;
}


#ifdef USE_R

void
ModFile::writeCFilesForR(const string &basename) const {
    int dum = 1;
    dynamic_model.writeDynamicCFile(basename + "/f_dynamic", dum);
    static_model.writeStaticCFile(basename + "/f_");
}

Rcpp::List ModFile::getModelListR(bool internal_calc) {

    int exo_count = symbol_table.exo_nbr();
    int endo_count =  symbol_table.endo_nbr();
    int param_count = symbol_table.param_nbr();
    
    // names
    Rcpp::CharacterVector exo_names(exo_count);
    for (int i = 0; i < exo_count; i++) {
        exo_names[i] = symbol_table.getName(eExogenous, i).c_str();
    }
    Rcpp::CharacterVector endo_names(endo_count);
    for (int i = 0; i < endo_count; i++) {
        endo_names[i] = symbol_table.getName(eEndogenous, i).c_str();
    }
    Rcpp::CharacterVector param_names(param_count);
    for (int i = 0; i < param_count; i++) {
        param_names[i] = symbol_table.getName(eParameter, i).c_str();
    }

    // tex names
    Rcpp::CharacterVector exo_tex_names(exo_count);
    for (int i = 0; i < exo_count; i++) {
        exo_tex_names[i] = symbol_table.getTeXName(eExogenous, i).c_str();
    }
    Rcpp::CharacterVector endo_tex_names(endo_count);
    for (int i = 0; i < endo_count; i++) {
        endo_tex_names[i] = symbol_table.getTeXName(eEndogenous, i).c_str();
    }
    Rcpp::CharacterVector param_tex_names(param_count);
    for (int i = 0; i < param_count; i++) {
        param_tex_names[i] = symbol_table.getTeXName(eParameter, i).c_str();
    }

    // long names
    Rcpp::CharacterVector exo_long_names(exo_count);
    for (int i = 0; i < exo_count; i++) {
        exo_long_names[i] = symbol_table.getLongName(eExogenous, i).c_str();
    }
    Rcpp::CharacterVector endo_long_names(endo_count);
    for (int i = 0; i < endo_count; i++) {
        endo_long_names[i] = symbol_table.getLongName(eEndogenous, i).c_str();
    }
    Rcpp::CharacterVector param_long_names(param_count);
    for (int i = 0; i < param_count; i++) {
        param_long_names[i] = symbol_table.getLongName(eParameter, i).c_str();
    }
    
    // create a list with information about auxiliary variables
    int aux_count = symbol_table.get_aux_count();
    Rcpp::NumericVector aux_endos(aux_count);
    Rcpp::NumericVector aux_orig_endos(aux_count);
    Rcpp::NumericVector aux_orig_leads(aux_count);
    Rcpp::NumericVector aux_orig_symb_ids(aux_count);
    Rcpp::NumericVector aux_orig_expr_index(aux_count);
    for (int i = 0; i < aux_count; i++) {
        aux_endos[i] = symbol_table.get_aux_endo(i);
        aux_orig_endos[i] = symbol_table.get_aux_orig_endo(i);
        aux_orig_leads[i] = symbol_table.get_aux_orig_lead_lag(i);
        aux_orig_symb_ids[i] = symbol_table.get_aux_orig_symb_id(i);
        aux_orig_expr_index[i] = symbol_table.get_aux_orig_expr_index(i);
    }

    // create a list with info about auxiliary endogenous variable
    // (which are lagged or leaded version of original endogenous variables).
    // aux_count: number of auxiliary variables
    // endos: index of the auxiliary variables in list of endogenous
    //        variables.
    // orig_endos: index of original endos in the list of endegenous variables
    // orig_leads: lag or lead of original endos
    // orig_symb_ids: index if the original endenous variables in symbol table,
    //                used by Dynare to create the names of auxiliary 
    //                variables for lags.
    // orig_expr_index: index of the original expression, used by Dynare to
    //                  create the names of auxiliary variables for leads, 
    //                  also used in write_initval_file.
    Rcpp::List aux_vars = Rcpp::List::create(
            Rcpp::Named("aux_count") = aux_count,
            Rcpp::Named("endos") = aux_endos,
            Rcpp::Named("orig_endos") = aux_orig_endos,
            Rcpp::Named("orig_leads") = aux_orig_leads,
            Rcpp::Named("orig_symb_ids") = aux_orig_symb_ids,
            Rcpp::Named("orig_expr_index") = aux_orig_expr_index);

    Rcpp::List dynmdl = dynamic_model.getDynamicModelR(internal_calc);
    Rcpp::List statmdl = static_model.getStaticModelR(internal_calc);

    Rcpp::NumericVector exos(exo_count);
    Rcpp::NumericVector endos(endo_count);
    Rcpp::NumericVector params(param_count);

    // Values of exogenous variables
    for (int i = 0; i < symbol_table.exo_nbr(); i++) {
        int id = symbol_table.getID(eExogenous, i);
        exos[i] = global_eval_context[id];
    }
    // Values of endogenous variables
    for (int i = 0; i < symbol_table.endo_nbr(); i++) {
        int id = symbol_table.getID(eEndogenous, i);
        endos[i] = global_eval_context[id];
    }
    // Parameter values
    for (int i = 0; i < symbol_table.param_nbr(); i++) {
        int id = symbol_table.getID(eParameter, i);
        params[i] = global_eval_context[id];
    }
    exos.names() = exo_names;
    endos.names() = endo_names;
    params.names() = param_names;

    int model_index;
    if (internal_calc) {

        ExternalFunctionCalc *ext_calc = new ExternalFunctionCalc();
        for (int i = 0; i < external_functions_table.get_external_function_count(); 
             i++) {
            int symb_id = external_functions_table.get_external_function_symb_id(i);
            int narg  = external_functions_table.getNargs(symb_id);
            ext_calc->add_function(symbol_table.getName(symb_id), narg);
        }

        PolishModel *stat_mdl = static_model.makePolishModel(ext_calc);
        PolishModel *dyn_mdl  = dynamic_model.makePolishModel(ext_calc);
        model_index = PolishModels::add_model(stat_mdl, dyn_mdl, ext_calc);
    } else {
        model_index = NA_INTEGER;
    }

    Rcpp::List trend_info = dynamic_model.get_trend_info();
    Rcpp::CharacterVector dyn_equations = dynamic_model.get_equations();
    Rcpp::CharacterVector stat_equations = static_model.get_equations();

     // initval expressions
    std::ostringstream initval_block;
    for (vector<Statement *>::const_iterator it = statements.begin();
       it != statements.end(); it++) {
      InitValStatement *ivs = dynamic_cast<InitValStatement *>(*it);
      if (ivs != NULL) {
          ivs->writeInitvalEq(initval_block);
      }
     }

    return Rcpp::List::create(Rcpp::Named("exos") = exos,
                              Rcpp::Named("endos") = endos,
                              Rcpp::Named("params") = params,
                              Rcpp::Named("model_index") = model_index,
                              Rcpp::Named("exo_tex_names") = exo_tex_names,
                              Rcpp::Named("endo_tex_names") = endo_tex_names,
                              Rcpp::Named("param_tex_names") = param_tex_names,
                              Rcpp::Named("exo_long_names") = exo_long_names,
                              Rcpp::Named("endo_long_names") = endo_long_names,
                              Rcpp::Named("param_long_names") = param_long_names,
                              Rcpp::Named("aux_vars") = aux_vars,
                              Rcpp::Named("dynamic_model") = dynmdl,
                              Rcpp::Named("static_model") = statmdl,
                              Rcpp::Named("trend_info") = trend_info, 
                              Rcpp::Named("equations") = dyn_equations,
                              Rcpp::Named("stat_equations") = stat_equations,
                              Rcpp::Named("initval") = Rcpp::String(initval_block.str()));
}

// Return information about the derivatives of the equations
// for the fit procedure.
Rcpp::List ModFile::getDerivativeInfo(Rcpp::CharacterVector instruments,
                                      bool fixed_period, bool check_stat_eqs) const {


    int exo_count = symbol_table.exo_nbr();
    int endo_count =  symbol_table.endo_nbr();
    int param_count = symbol_table.param_nbr();

    Rcpp::CharacterVector exo_names(exo_count);
    for (int i = 0; i < exo_count; i++) {
        exo_names[i] = symbol_table.getName(eExogenous, i).c_str();
    }
    Rcpp::CharacterVector endo_names(endo_count);
    for (int i = 0; i < endo_count; i++) {
        endo_names[i] = symbol_table.getName(eEndogenous, i).c_str();
    }
    Rcpp::CharacterVector param_names(param_count);
    for (int i = 0; i < param_count; i++) {
        param_names[i] = symbol_table.getName(eParameter, i).c_str();
    }

    Rcpp::IntegerVector instr_index_exo = Rcpp::match(exo_names, instruments);

    Rcpp::List deriv_dyn = dynamic_model.getDerivativeInfoR(instruments.size(), 
                                                         instr_index_exo,
                                                         fixed_period);
    
    Rcpp::LogicalVector equation_has_static;
    if (check_stat_eqs) {
        equation_has_static = dynamic_model.equation_has_static();
    }

    Rcpp::List deriv_stat;
    if (check_stat_eqs && Rcpp::is_true(Rcpp::any(equation_has_static))) {
        deriv_stat = static_model.getDerivativeInfoR(instruments.size(), 
                                                         instr_index_exo);
    } else {
	deriv_stat = R_NilValue;
    }
    
    return Rcpp::List::create(Rcpp::Named("exo_names") = exo_names,
                              Rcpp::Named("endo_names") = endo_names,
                              Rcpp::Named("param_names") = param_names,
                              Rcpp::Named("equation_has_static") = equation_has_static,
                              Rcpp::Named("deriv_stat") = deriv_stat,
                              Rcpp::Named("deriv_dyn") = deriv_dyn);
}

int ModFile::get_warning_count() const {
    return(warnings.countWarnings());
}

/* Create LaTeX directory. This code assumes that the directory separator is a '/',
 * so make sure that Windows backslash separators have been converted to 
 * forward slashes in the R code */
void createLatexDir(const string &dir) {
     int r;
     size_t pos = 0;

#ifdef _WIN32
     if (dir.length() == 2 && dir.at(1) == ':') {
         /* dir specifies a disk drive (e.g. c:).
          * Obviously, it is not possible to create a new drive 
          * with function mkdir. But if the path is an existing 
          * drive, mkdir sometimes (but not always) fails
          * with error "Permission denied".
          * The failure occurs when we run the dynmdl test
          * tests/testthat/test_islm_trend_latex.R on Windows. 
          * Therefore return in this case. */
         return;
      }
#endif

     do {
#ifdef _WIN32
         pos = dir.find_first_of("\\/", pos + 1);
         if (pos == 2 && dir.at(1) == ':') {
             /* dir.substr(0, pos) specifies a disk drive (e.g. c:).
              * This can be problematic (see the comments above).
              * Therefore skip the call of mkdir. */
             continue;
         }
         r = mkdir(dir.substr(0, pos).c_str());
#else 
         pos = dir.find_first_of("/", pos + 1);
         r = mkdir(dir.substr(0, pos).c_str(), 0777);
#endif 
         if (r < 0 && errno != EEXIST) {
             dyn_error("ERROR creating " + dir.substr(0, pos) + ": " + 
                       string(std::strerror(errno)));
         }
    } while (pos != std::string::npos);
}

void ModFile::writeLatexFiles(const string &dir, const string &prefix,
                              bool fit, const OutputParameters &output_params) {


    // create directory LaTeX if it does not exist
    bool dir_created = false;

    for (vector<Statement *>::const_iterator it = statements.begin();
          it != statements.end(); it++) {

        WriteLatexDynamicModelStatement *wldms = 
              dynamic_cast<WriteLatexDynamicModelStatement *>(*it);
        if (wldms != NULL) {
           if (!dir_created) createLatexDir(dir);
           dir_created = true;
           bool write_eq_tags = wldms->get_write_equation_tags();
           dynamic_model.writeLatexFile(dir, prefix, write_eq_tags, fit, 
                                        output_params, global_eval_context);
           continue;
        }

        WriteLatexStaticModelStatement *wlsms = 
              dynamic_cast<WriteLatexStaticModelStatement *>(*it);
        if (wlsms != NULL) {
           if (!dir_created) createLatexDir(dir);
           dir_created = true;
           static_model.writeLatexFile(dir, prefix, fit, output_params,
                                       global_eval_context);
           continue;
        }

        if (!fit) {
            // do not write original model if this is a fit model
            //  -> the original model has already been written
            //     after the first parsing round
            WriteLatexOriginalModelStatement *wloms = 
                dynamic_cast<WriteLatexOriginalModelStatement *>(*it);
            if (wloms != NULL) {
               if (!dir_created) createLatexDir(dir);
               dir_created = true;
               original_model.writeLatexOriginalFile(dir, prefix, output_params,
                                                     global_eval_context);
            }
        }
    }
}

#endif
