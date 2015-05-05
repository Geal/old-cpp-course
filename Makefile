export CXX=g++
export CXXFLAGS=-g -W -Wall -Werror -pedantic -std=c++11

all: list

list: list.cpp
	$(CXX) $(CXXFLAGS) list.cpp -o list

clean:
	rm -rf list.dSYM/
	rm -f list

.PHONY: clean

