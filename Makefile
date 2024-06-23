CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
# LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Main targets
all: tree test

# Build the main demo executable
tree: Demo.o
	$(CXX) $(CXXFLAGS) -o tree Demo.o $(LDFLAGS)

# Build the test executable
test: Test.o
	$(CXX) $(CXXFLAGS) -o test Test.o $(LDFLAGS)

# Compile Demo.cpp
Demo.o: Demo.cpp Node.hpp Tree.hpp
	$(CXX) $(CXXFLAGS) -c Demo.cpp

# Compile Test.cpp
Test.o: Test.cpp Node.hpp Tree.hpp
	$(CXX) $(CXXFLAGS) -c Test.cpp

# Clean up build artifacts
clean:
	rm -f *.o tree test

.PHONY: all clean
