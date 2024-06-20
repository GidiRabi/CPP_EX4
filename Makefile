# Makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

all: tree

tree: Demo.o Node.o Tree.o
	$(CXX) $(CXXFLAGS) -o tree Demo.o Node.o Tree.o

Demo.o: Demo.cpp Node.hpp Tree.hpp
	$(CXX) $(CXXFLAGS) -c Demo.cpp

Node.o: Node.cpp Node.hpp
	$(CXX) $(CXXFLAGS) -c Node.cpp

Tree.o: Tree.cpp Tree.hpp Node.hpp
	$(CXX) $(CXXFLAGS) -c Tree.cpp

clean:
	rm -f *.o tree

.PHONY: all clean
