/*
 * Copyright (C) 2010-2015 Dynare Team
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
#include <cassert>
#include <cerrno>
#include <cmath>
#include <iostream>

#include "ExternalFunctionsTable.hh"
#include "SymbolTable.hh"
#include "dyn_error.hh"

ExternalFunctionsTable::ExternalFunctionsTable()
{
}

void
ExternalFunctionsTable::addExternalFunction(int symb_id, const external_function_options &external_function_options_arg, bool track_nargs)
{
  assert(symb_id >= 0);
  assert(external_function_options_arg.nargs > 0);

  // Change options to be saved so the table is consistent
  external_function_options external_function_options_chng = external_function_options_arg;
  if (external_function_options_arg.firstDerivSymbID  == eExtFunSetButNoNameProvided)
    external_function_options_chng.firstDerivSymbID = symb_id;

  if (external_function_options_arg.secondDerivSymbID == eExtFunSetButNoNameProvided)
    external_function_options_chng.secondDerivSymbID = symb_id;

  if (!track_nargs)
    external_function_options_chng.nargs = eExtFunNotSet;

  // Ensure 1st & 2nd deriv option consistency
  if (external_function_options_chng.secondDerivSymbID == symb_id
      && external_function_options_chng.firstDerivSymbID  != symb_id)
    {
      dyn_error("ERROR: If the second derivative is provided by the top-level function "
                "the first derivative must also be provided by the same function.\n");
    }

  if ((external_function_options_chng.secondDerivSymbID != symb_id
       && external_function_options_chng.firstDerivSymbID  == symb_id)
      && external_function_options_chng.secondDerivSymbID != eExtFunNotSet)
    {
      dyn_error("ERROR: If the first derivative is provided by the top-level function, the "
                "second derivative cannot be provided by any other external function.\n");
    }

  if (external_function_options_chng.secondDerivSymbID != eExtFunNotSet
      && external_function_options_chng.firstDerivSymbID == eExtFunNotSet)
    {
      dyn_error("ERROR: If the second derivative is provided, the first derivative must also be provided.\n");
    }

  if (external_function_options_chng.secondDerivSymbID == external_function_options_chng.firstDerivSymbID
      && external_function_options_chng.firstDerivSymbID != symb_id
      && external_function_options_chng.firstDerivSymbID != eExtFunNotSet)
    {
      dyn_error("ERROR: If the Jacobian and Hessian are provided by the same function, that "
               "function must be the top-level function.\n");
    }

  // Ensure that if we're overwriting something, we mean to do it
  if (exists(symb_id))
    {
      bool ok_to_overwrite = false;
      if (getNargs(symb_id) == eExtFunNotSet) // implies that the information stored about this function is not important
        ok_to_overwrite = true;

      if (!ok_to_overwrite) // prevents multiple non-compatible calls to external_function(name=funcname)
        {                   // e.g. e_f(name=a,nargs=1,fd,sd) and e_f(name=a,nargs=2,fd=b,sd=c) should cause an error
          if (external_function_options_chng.nargs != getNargs(symb_id))
            {
              dyn_error("ERROR: The number of arguments passed to the external_function() statement do not "
                        "match the number of arguments passed to a previous call or declaration of the top-level function.\n");
            }

          if (external_function_options_chng.firstDerivSymbID != getFirstDerivSymbID(symb_id))
            {
              dyn_error("ERROR: The first derivative function passed to the external_function() statement does not "
                        "match the first derivative function passed to a previous call or declaration of the top-level function.\n");
            }

          if (external_function_options_chng.secondDerivSymbID != getSecondDerivSymbID(symb_id))
            {
              dyn_error("ERROR: The second derivative function passed to the external_function() statement does not "
                        "match the second derivative function passed to a previous call or declaration of the top-level function.\n");
            }
        }
    } 
#ifdef USE_R
    else {
      // symbol does not yet exist.
      external_function_symb_ids.push_back(symb_id);
    }
#endif

  externalFunctionTable[symb_id] = external_function_options_chng;
}

#ifdef USE_R

int ExternalFunctionsTable::get_external_function_count() const {
    return external_function_symb_ids.size();
}

int ExternalFunctionsTable::get_external_function_symb_id(int index) const {
    return external_function_symb_ids[index];
}

#endif
