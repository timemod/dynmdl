dnl Process this file with autoconf to produce a configure script.

dnl Copyright (C) 2009-2016 Dynare Team
dnl
dnl This file is part of Dynare.
dnl
dnl Dynare is free software: you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation, either version 3 of the License, or
dnl (at your option) any later version.
dnl
dnl Dynare is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with Dynare.  If not, see <http://www.gnu.org/licenses/>.

AC_PREREQ([2.62])
AC_INIT([dynare], [4.6-unstable])
AC_CONFIG_SRCDIR([src/parse.cc])
AC_PROG_CC
AC_PROG_CXX

# Use C++ for testing headers
AC_LANG([C++])

dnl Now find the compiler and compiler flags to use
: ${R_HOME=`R RHOME`}
if test -z "${R_HOME}"; then
  echo "could not determine R_HOME"
  exit 1
fi
AC_SUBST(R_CXXFLAGS, [`"${R_HOME}/bin/R" CMD config CXXFLAGS`])
AC_SUBST(R_CXXPICFLAGS, [`"${R_HOME}/bin/R" CMD config CXXPICFLAGS`])

# If default 'ar' is not available, try to find one with a host prefix (see ticket #145)
AC_CHECK_PROGS([AR], [ar ${host_alias}-ar])

AC_PROG_RANLIB

AC_CHECK_PROG([YACC], [bison], [bison])
if test "x$YACC" = "x"; then
  unset YACC # AM_MISSING_PROG needs an unset variable: an empty variable won't do
  AC_ERROR("Can't find bison")
fi
AC_CHECK_PROG([LEX], [lex], [lex])
if test "x$LEX" = "x"; then
  unset YACC # AM_MISSING_PROG needs an unset variable: an empty variable won't do
  AC_ERROR("Can't find flex")
fi
# Hack to get lex include dir. 
AC_PATH_PROG([LEXPATH], [$LEX])
AC_SUBST([LEXINC], [`eval "echo $LEXPATH | sed 's|\(.*\)$LEX$|\1../include|'"`])

# We need 1.36 because of unordered_{set,hash} used by Dynare++
# AX_BOOST_BASE([1.36], [], [AC_ERROR([Can't find Boost >= 1.36])])

CPPFLAGS_SAVED="$CPPFLAGS"
CPPFLAGS="$CPPFLAGS $BOOST_CPPFLAGS"
AC_CHECK_HEADERS([boost/graph/adjacency_list.hpp], [], [AC_ERROR([Can't find Boost Graph Library])])
AC_CHECK_HEADERS([boost/algorithm/string/trim.hpp], [], [AC_ERROR([Can't find Boost String Library])])
AC_CHECK_HEADERS([boost/algorithm/string/split.hpp], [], [AC_ERROR([Can't find Boost String Library])])
AC_CHECK_HEADERS([boost/lexical_cast.hpp], [], [AC_ERROR([Can't find Boost Lexical Cast Header])])
CPPFLAGS="$CPPFLAGS_SAVED"

# Don't use deprecated hash structures
AC_DEFINE([BOOST_NO_HASH], [], [Don't use deprecated STL hash structures])

case ${host_os} in
  *mingw32*)
    # Ensure that -lpthread is statically linked under MinGW
    PTHREAD_LIBS="-Wl,-Bstatic -lpthread -Wl,-Bdynamic"
    ;;
esac
#AX_PTHREAD

AC_CONFIG_FILES([src/Makevars])
 

# Construct final output message

BUILD_PREPROCESSOR="yes"

AC_MSG_NOTICE([

Dynare is now configured for building the following components...

Binaries (with "make"):
 Dynare preprocessor:                   $BUILD_PREPROCESSOR
])

AC_OUTPUT
