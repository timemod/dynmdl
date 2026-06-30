LIB = libmacro.a
OBJS = MacroBison.o MacroDriver.o MacroFlex.o MacroValue.o

all : $(LIB)

$(LIB) : $(OBJS)
	$(AR) -rucs $@ $^

%.o : %.cc
	$(CXX) $(CXXFLAGS) -I.. -c -o $@ $<

# dependencies on headers
MacroBison.o : MacroBison.hh MacroDriver.hh MacroValue.hh ../FlexLexer.h
MacroDriver.o : MacroDriver.hh ../dynout.hh ../dyn_error.hh ../FlexLexer.h \
                MacroValue.hh MacroBison.hh
MacroFlex.o : MacroDriver.hh MacroValue.hh MacroBison.hh ../FlexLexer.h
MacroValue.o : MacroDriver.hh MacroValue.hh MacroBison.hh

clean:
	-rm -r *.o
	-rm -r *.a
