export CXX=g++
export CXXFLAGS=-g -W -Wall -Werror -pedantic -std=c++11

all: list

list: list.o
	$(CXX) $(CXXFLAGS) list.o -o list

list.o: list.cpp option.hpp
	$(CXX) $(CXXFLAGS) -c list.cpp

clean:
	rm -rf list.dSYM/
	rm -f list
	rm -f *.o

.PHONY: clean

