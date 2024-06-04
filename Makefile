// gidirabi111@gmil.com
CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: tree

tree: main.o node.o tree.o
	$(CXX) $(CXXFLAGS) -o tree main.o node.o tree.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

node.o: node.cpp node.hpp
	$(CXX) $(CXXFLAGS) -c node.cpp

tree.o: tree.cpp tree.hpp node.hpp
	$(CXX) $(CXXFLAGS) -c tree.cpp

clean:
	rm -f *.o tree
