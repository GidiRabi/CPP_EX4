# Makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: tree

tree: main.o Node.o Tree.o
	$(CXX) $(CXXFLAGS) -o tree main.o Node.o Tree.o

main.o: main.cpp Node.hpp Tree.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Node.o: Node.cpp Node.hpp
	$(CXX) $(CXXFLAGS) -c Node.cpp

Tree.o: Tree.cpp Tree.hpp Node.hpp
	$(CXX) $(CXXFLAGS) -c Tree.cpp

clean:
	rm -f *.o tree
