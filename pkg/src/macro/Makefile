LIB = libmacro.a
OBJS = MacroBison.o MacroDriver.o MacroFlex.o MacroValue.o

LEX_CMD = flex
YACC_CMD = bison

all : $(LIB)

$(LIB) : $(OBJS)
	$(AR) -rucs $@ $^

%.o : %.cc
	$(CXX) $(CXXFLAGS) -I.. -c -o $@ $<

# dependencies on headers
MacroBison.o : MacroBison.hh MacroDriver.hh
MacroDriver.o : MacroDriver.hh ../dyn_error.hh ../FlexLexer.h
MacroFlex.o : MacroDriver.hh ../FlexLexer.h
MacroValue.o : MacroDriver.hh

# rules for flex and bison
MacroFlex.cc: MacroFlex.ll ../FlexLexer.h
	-$(LEX_CMD) -o MacroFlex.cc MacroFlex.ll

MacroBison.cc MacroBison.hh location.hh stack.hh position.hh: MacroBison.yy
	-$(YACC_CMD) -o MacroBison.cc MacroBison.yy

clean:
	-rm -r *.o
	-rm -r *.a
