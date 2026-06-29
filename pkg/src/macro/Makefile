LIB = libmacro.a
OBJS = MacroBison.o MacroDriver.o MacroFlex.o MacroValue.o

all : $(LIB)

$(LIB) : $(OBJS)
	$(AR) -rucs $@ $^

%.o : %.cc
	$(CXX) -I.. $(CXXFLAGS) -c -o $@ $<

# dependencies on headers
MacroBison.o : MacroBison.hh MacroDriver.hh
MacroDriver.o : MacroDriver.hh ../dyn_error.hh ../FlexLexer.h
MacroFlex.o : MacroDriver.hh ../FlexLexer.h
MacroValue.o : MacroDriver.hh

clean:
	-rm -r *.o
	-rm -r *.a
