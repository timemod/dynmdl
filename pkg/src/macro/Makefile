LIB = libmacro.a
OBJS = MacroBison.o MacroDriver.o MacroFlex.o MacroValue.o

all : $(LIB)

$(LIB) : $(OBJS)
	$(AR) -rucs $@ $^

%.o : %.cc
	$(CXX) $(CXXFLAGS) -I. -I.. -c -o $@ $<

# dependencies C files on headers
include makedeps

clean:
	-rm -r *.o
	-rm -r *.a
