CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

all: tree

tree: Demo.o
	$(CXX) $(CXXFLAGS) -o tree Demo.o

Demo.o: Demo.cpp Node.hpp Tree.hpp
	$(CXX) $(CXXFLAGS) -c Demo.cpp

clean:
	rm -f *.o tree

.PHONY: all clean
