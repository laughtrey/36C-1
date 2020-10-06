#
CXXFLAGS+=-IHeader -std=c++17 -Wall -Werror
CXXSOURCE=$(wildcard Source/*.cc)
CXXOBJS=$(patsubst %.cc,%.o,$(CXXSOURCE))

SearchNewBooks: $(CXXOBJS)
	    $(CXX) $(LDFLAGS) -o $@ $^
	# REMOVE THIS LINE BEFORE SUBMIT
	@create_testData 50 50

run :
	@echo "Running the program:"
	@./SearchNewBooks

edit:
	@vim Source/SearchNewBooks.cc

debug:
	@gdb ./SearchNewBooks

clean :
	@rm -f SearchNewBooks
	@rm -f request.dat
	@rm -f newbooks.dat
	@rm -f result.dat
	@rm -f Source/*.o
