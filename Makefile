# This is a gnu makefile with several commands to build, document and test
# the package.  The actual building and installation of the package is achieved
# with the standard R commands R CMD BUOLD and R CMD INSTALL.
#
# This script assumes that environment variable R_LIBS_USER exists.

PKGDIR=pkg
INSTALL_FLAGS=--no-multiarch --with-keep.source 
RCHECKARG=--no-multiarch
R_HOME=$(shell R RHOME)

OSNAME := $(shell uname | tr A-Z a-z)
ifeq ($(findstring windows, $(OSNAME)), windows) 
    OSTYPE = windows
else
    # Linux or MAC OSX
    OSTYPE = unix
endif

# Package name, Version and date from DESCIPTION
PKG=$(shell grep 'Package:' $(PKGDIR)/DESCRIPTION  | cut -d " " -f 2)
PKGTAR=$(PKG)_$(shell grep 'Version' $(PKGDIR)/DESCRIPTION  | cut -d " " -f 2).tar.gz
PKGDATE=$(shell grep 'Date' $(PKGDIR)/DESCRIPTION  | cut -d " " -f 2)
TODAY=$(shell date "+%Y-%m-%d")
# make sure that R's variables are used
# if you don't do this you'll get make's initial values
# gives error doing syntax target
CC=$(shell R CMD config CC)
CPP=$(shell R CMD config CXX)
CPP_FLAGS=$(shell R CMD config --cppflags)
RCEREAL_DIR=`"$(R_HOME)/bin/Rscript" -e "cat(system.file(\"include\", package = \"Rcereal\"))"`
BH_DIR=`"$(R_HOME)/bin/Rscript" -e "cat(system.file(\"include\", package = \"BH\"))"`
PKG_CXXFLAGS = -DPACKAGE_NAME=\"dynare\" -DPACKAGE_TARNAME=\"dynare\" -DPACKAGE_VERSION=\"R-0.1-unstable\" -DPACKAGE_STRING=\"dynare\ R\ 0.1-unstable\" -DPACKAGE_BUGREPORT=\"\" -DPACKAGE_URL=\"\" -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_BOOST_GRAPH_ADJACENCY_LIST_HPP=1 -DHAVE_BOOST_ALGORITHM_STRING_TRIM_HPP=1 -DHAVE_BOOST_ALGORITHM_STRING_SPLIT_HPP=1 -DHAVE_BOOST_LEXICAL_CAST_HPP=1 -DBOOST_NO_HASH=/\*\*/ -DUSE_R -I$(PKGDIR)/src -I$(RCEREAL_DIR) -I$(BH_DIR) `"$(R_HOME)/bin/Rscript" -e "Rcpp:::CxxFlags()"` -std=c++11

testje:
	echo $(PKG_CXXFLAGS)

.PHONY: clean cleanx check install uninstall mkpkg bin pdf

help:
	@echo
	@echo "The following targets are available:"
	@echo "   help      - displays this help"
	@echo "   test      - run the tests"
	@echo "   covr      - check package coverage (package covr)"
	@echo "   check     - Run R CMD check $(PKGDIR)"
	@echo "   syntax    - check syntax .cc files"
	@echo "   document  - run roxygen to generate Rd files and make pdf Reference manual"
	@echo "   mkpkg     - builds source package and checks with --as-cran"
	@echo "   bin       - builds binary package in ./tmp"
	@echo "   install   - install package in .libPaths()[1]"
	@echo "   installv  - install package with vignettes in .libPaths()[1]"
	@echo "   uninstall - uninstall package from .libPaths()[1]"
	@echo "   clean     - cleans up everything"
	@echo "   flags     - display R config flags and some macros"

flags:
	@echo "R_HOME=$(R_HOME)"
	@echo "SHELL=$(SHELL)"
	@echo "CPP_FLAGS=$(CPP_FLAGS)"
	@echo "PKGDIR=$(PKGDIR)"
	@echo "PKG=$(PKG)"
	@echo "PKGTAR=$(PKGTAR)"
	@echo "PKGDATE=$(PKGDATE)"
	@echo "R .libPaths()"
	@echo "CC=$(CC)"
	@echo "CPP=$(CPP)"
	@echo "CPP_FLAGS=$(CPP_FLAGS)"
	@echo "PKG_CXXFLAGS=$(PKG_CXXFLAGS)"
	@R --no-save --quiet --slave -e '.libPaths()'

test:
	R --slave -f test.R

test_covr:
	R --slave -f test_covr.R

check: cleanx syntax
	@echo " *** Running R CMD check ***"
	$(MAKE) -f Makedeps
	R CMD build $(PKGDIR)
	R CMD check $(RCHECKARG) $(PKGTAR)
	@rm -f  $(PKGTAR)
	@echo "Today                           : $(TODAY)"
	@echo "Checked package description date: $(PKGDATE)"
# 	@Rscript -e 'cat("Installed version date          :",packageDescription("nleqslv", fields="Date"))'
	@echo ""

syntax:
	$(CXX) "$(CPP_FLAGS)" $(PKG_CXXFLAGS) -c -fsyntax-only -Wall -pedantic $(PKGDIR)/src/*.c*
	$(CXX) "$(CPP_FLAGS)" $(PKG_CXXFLAGS) -c -fsyntax-only -Wall -pedantic $(PKGDIR)/src/macro/*.c*

cleanx:
# Apple Finder rubbish
ifneq ($(findstring windows, $(OSNAME)), windows) 
	@find . -name '.DS_Store' -delete
endif
	@rm -f $(PKGTAR)
	@rm -fr $(PKG).Rcheck

# build date of package must be at least today
# build source package for submission to CRAN
# after building do a check as CRAN does it
mkpkg: cleanx syntax install_deps
	R CMD build $(PKG)
	R CMD check --as-cran $(RCHECKARG) $(PKGTAR)
	@cp -nv $(PKGTAR) archive
	@echo "Today                           : $(TODAY)"
	@echo "Checked package description date: $(PKGDATE)"
# 	@Rscript -e 'cat("Installed version date          :",packageDescription("nleqslv", fields="Date"))'
	@echo ""

bin: install_deps
	$(MAKE) -f Makedeps
	-@rm -rf tmp
	mkdir tmp
	R CMD build $(PKGDIR)
	R CMD INSTALL $(INSTALL_FLAGS) -l ./tmp --build $(PKGTAR)

document: install_deps
	$(MAKE) -f Makedeps
	-@rm -f $(PKGDIR).pdf
	R -e "devtools::document('"$(PKGDIR)"')"
	R CMD Rd2pdf --batch $(PKGDIR) 2>$(PKGDIR).log

install: install_deps
	$(MAKE) -f Makedeps
	R CMD INSTALL $(INSTALL_FLAGS) $(PKGDIR)

installv: install_deps
	$(MAKE) -f Makedeps
	R CMD build $(PKGDIR)
	R CMD INSTALL $(INSTALL_FLAGS) $(PKGTAR)

install_deps:
	R --slave -f install_deps.R


uninstall:
	R CMD REMOVE $(PKG)

clean:
	$(MAKE) -f Makedeps clean
	$(MAKE) -C $(PKGDIR)/src/macro clean
	rm -fr $(PKGDIR).Rcheck
	rm -fr tmp
	rm -f $(PKGTAR)
	rm -f $(PKGDIR).pdf
	rm -f $(PKGDIR).log
	rm -f $(PKGDIR)/src/*.o
	rm -f $(PKGDIR)/src/*.so
	rm -f $(PKGDIR)/src/*.dll
