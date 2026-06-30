# This is a gnu makefile with several commands to build, document and test
# the package.  The actual building and installation of the package is achieved
# with the standard R commands R CMD BUOLD and R CMD INSTALL.
#
# This script assumes that environment variable R_LIBS_USER exists.

PKGDIR=pkg
INSTALL_FLAGS=--no-multiarch --with-keep.source 
RCHECKARG=--no-multiarch

export OSTYPE=$(shell Rscript -e "cat(.Platform[['OS.type']])")

# Package name, Version and date from DESCIPTION
PKG=$(shell grep 'Package:' $(PKGDIR)/DESCRIPTION  | cut -d " " -f 2)
PKGTAR=$(PKG)_$(shell grep 'Version' $(PKGDIR)/DESCRIPTION  | cut -d " " -f 2).tar.gz

# Determine the Flex and bison commands and the include directory for FlexLexer.h file
# for Unix systems (Linux or MAC OS).
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
  LEX_CMD := lex
  LEX_INC := /usr/include
  BISON_CMD := bison
else ifeq ($(UNAME_S),Darwin)
  ifneq ($(wildcard /opt/homebrew/opt/flex/include/FlexLexer.h),)
    LEX_CMD := /opt/homebrew/opt/flex/bin/flex
    LEX_INC := /opt/homebrew/opt/flex/include
  else
    LEX_CMD := 
    LEX_INC :=
  endif
  ifneq ($(wildcard /opt/homebrew/opt/bison/bin/bison),)
    BISON_CMD :=  /opt/homebrew/opt/bison/bin/bison
  else 
    BISON_CMD := 
  endif
endif

SRC_DIR = pkg/src
LEX_YACC_DIR = pkg/src/lex_yacc
MACRO_DIR = pkg/src/macro

.PHONY: clean cleanx check install uninstall mkpkg bin pdf

help:
	@echo
	@echo "The following targets are available:"
	@echo "   help      - displays this help"
	@echo "   test      - run the tests"
	@echo "   covr      - check package coverage (package covr)"
	@echo "   check     - Run R CMD check $(PKGDIR)"
	@echo "   document  - run roxygen to generate Rd files and make pdf Reference manual"
	@echo "   mkpkg     - builds source package and checks with --as-cran"
	@echo "   bin       - builds binary package in ./tmp"
	@echo "   flex      - run flex (see README.md)
	@echo "   bison     - run bison (see README.md)
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
	@echo LEX_CMD=$(LEX_CMD)
	@echo LEX_INC=$(LEX_INC)
	@echo BISON_CMD=$(BISON_CMD)
	@echo .libPaths:
	@R --no-save --quiet --slave -e '.libPaths()'

test: install_deps
	R --slave -f test.R

test_covr:
	R --slave -f test_covr.R

check: cleanx 
	@echo " *** Running R CMD check ***"
	$(MAKE) -f Makedeps
	R CMD build $(PKGDIR)
	R CMD check $(RCHECKARG) $(PKGTAR)
	@rm -f  $(PKGTAR)

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
mkpkg: cleanx install_deps
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


flex:
ifeq ($(OSTYPE), windows)
	@echo Flex can not run on Windows
else ifeq ($(strip $(LEX_CMD)),)
	$(warning "Unknown Flex location")
else
	$(LEX_CMD) -o $(SRC_DIR)/DynareFlex.cc $(LEX_YACC_DIR)/DynareFlex.ll 
	$(LEX_CMD) -o $(MACRO_DIR)/MacroFlex.cc $(MACRO_DIR)/MacroFlex.ll 
	@# Copy FlexLexer.h from $LEX_INC to pkg/src. Otherwise the code cannot
	@# be compiled on systems where FLex is not available, or where
	@# the version of lex is incompatible with the version used
	@# to generate DynareFlex.cc.
	cp $(LEX_INC)/FlexLexer.h $(SRC_DIR)
	touch pkg/src/FlexLexer.h
endif

bison:
ifeq ($(OSTYPE), windows)
	@echo Bison can not run on Windows
else ifeq ($(strip $(LEX_CMD)),)
	$(warning "Unknown Bison location")
else
	$(BISON_CMD) -o $(SRC_DIR)/DynareBison.cc $(LEX_YACC_DIR)/DynareBison.yy
	$(BISON_CMD) -o $(MACRO_DIR)/MacroBison.cc $(MACRO_DIR)/MacroBison.yy
endif

makedeps:
	R --slave -f tools/create_makedeps_files.R

install: makedeps install_deps
	R CMD INSTALL $(INSTALL_FLAGS) $(PKGDIR)

installv: makedeps install_deps
	R CMD build $(PKGDIR)
	R CMD INSTALL $(INSTALL_FLAGS) $(PKGTAR)

install_deps:
	R --slave -f install_deps.R

uninstall:
	R CMD REMOVE $(PKG)

clean:
	$(MAKE) -f Makedeps clean
	$(MAKE) -C $(PKGDIR)/src/macro clean
	-rm -fr $(PKGDIR).Rcheck
	-rm -fr tmp
	-rm -f $(PKGTAR)
	-rm -f $(PKGDIR).pdf
	-rm -f $(PKGDIR).log
	-rm -f $(PKGDIR)/src/*.o
	-rm -f $(PKGDIR)/src/*.so
	-rm -f $(PKGDIR)/src/*.dll
