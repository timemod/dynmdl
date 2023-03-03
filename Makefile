# This is a gnu makefile with several commands to build, document and test
# the package.  The actual building and installation of the package is achieved
# with the standard R commands R CMD BUOLD and R CMD INSTALL.
#
# This script assumes that environment variable R_LIBS_USER exists.

PKGDIR=pkg
INSTALL_FLAGS=--no-multiarch --with-keep.source 
RCHECKARG=--no-multiarch

export OSTYPE=$(shell Rscript -e "cat(.Platform[['OS.type']])")
RCPP_CXXFLAGS = $(shell Rscript -e "Rcpp:::CxxFlags()")

# Package name, Version and date from DESCIPTION
PKG=$(shell grep 'Package:' $(PKGDIR)/DESCRIPTION  | cut -d " " -f 2)
PKGTAR=$(PKG)_$(shell grep 'Version' $(PKGDIR)/DESCRIPTION  | cut -d " " -f 2).tar.gz

ifneq ($(OSTYPE), windows)
CC=$(shell R CMD config CC)
CPP=$(shell R CMD config CXX)
CPP_FLAGS=$(shell R CMD config --cppflags)
RCEREAL_DIR=$(shell Rscript -e "cat(system.file(\"include\", package = \"Rcereal\"))")
BH_DIR=$(shell Rscript -e "cat(system.file(\"include\", package = \"BH\"))")
PKG_CXXFLAGS = -DPACKAGE_NAME=\"dynare\" -DPACKAGE_TARNAME=\"dynare\" -DPACKAGE_VERSION=\"R-0.1-unstable\" -DPACKAGE_STRING=\"dynare\ R\ 0.1-unstable\" -DPACKAGE_BUGREPORT=\"\" -DPACKAGE_URL=\"\" -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_BOOST_GRAPH_ADJACENCY_LIST_HPP=1 -DHAVE_BOOST_ALGORITHM_STRING_TRIM_HPP=1 -DHAVE_BOOST_ALGORITHM_STRING_SPLIT_HPP=1 -DHAVE_BOOST_LEXICAL_CAST_HPP=1 -DBOOST_NO_HASH=/\*\*/ -DUSE_R -I$(PKGDIR)/src -I$(RCEREAL_DIR) -I$(BH_DIR) $(RCPP_CXXFLAGS) -std=c++11
endif

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
	@echo OSTYPE=$(OSTYPE)
	@echo PKGDIR=$(PKGDIR)
	@echo PKG=$(PKG)
	@echo PKGTAR=$(PKGTAR)
	@echo PKGDATE=$(PKGDATE)
ifneq ($(OSTYPE), windows)
	@echo CC=$(CC)
	@echo CPP=$(CPP)
	@echo CPP_FLAGS=$(CPP_FLAGS)
	@echo PKG_CXXFLAGS=$(PKG_CXXFLAGS)
	@echo RCPP_CXXFLAGS=$(RCPP_CXXFLAGS)
	@echo BH_DIR=$(BH_DIR)
	@echo RCEREAL_DIR=$(RCEREAL_DIR)
	@echo CPP_FLAGS=$(CPP_FLAGS)
endif
	@echo .libPaths:
	@R --no-save --quiet --slave -e '.libPaths()'

test: install_deps
	R --slave -f test.R

test_covr:
	R --slave -f test_covr.R

check: cleanx syntax
	@echo " *** Running R CMD check ***"
	$(MAKE) -f Makedeps
	R CMD build $(PKGDIR)
	R CMD check $(RCHECKARG) $(PKGTAR)
	@rm -f  $(PKGTAR)

syntax:
ifneq ($(OSTYPE), windows)
	$(CPP) $(CPP_FLAGS) $(PKG_CXXFLAGS) -c -fsyntax-only -Wall -pedantic $(PKGDIR)/src/*.c*
	$(CPP) $(CPP_FLAGS) $(PKG_CXXFLAGS) -c -fsyntax-only -Wall -pedantic $(PKGDIR)/src/macro/*.c*
else
	@echo Syntax checking not possible on Windows
endif

cleanx:
# Apple Finder rubbish
ifneq ($(OSTYPE), windows) 
	@find . -name '.DS_Store' -delete
endif
	@rm -f $(PKGTAR)
	@rm -fr $(PKG).Rcheck

# build date of package must be at least today
# build source package for submission to CRAN
# after building do a check as CRAN does it
mkpkg: cleanx syntax install_deps
ifeq ($(OSTYPE), windows)
	@echo Please run mkpkg on Linux or MAC OSX
else
	R CMD build $(PKGDIR)
	@cp -nv $(PKGTAR) archive
	./drat.sh --pkg=$(PKGTAR)
endif


bin: install_deps
	$(MAKE) -f Makedeps
	-@rm -rf tmp
	mkdir tmp
	R CMD build $(PKGDIR)
	R CMD INSTALL $(INSTALL_FLAGS) -l ./tmp --build $(PKGTAR)

document: install_deps
	$(MAKE) -f Makedeps
	-@rm -f refman.pdf
	R -e "devtools::document('"$(PKGDIR)"')"
	R CMD Rd2pdf --no-preview $(PKGDIR) -o refman.pdf 2>&1 >refman.log

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
