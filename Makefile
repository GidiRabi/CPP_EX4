# 325483444 gidirabi111@gmail.com
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
# Include directory for SFML headers, adjust if SFML is installed in a non-standard location
SFML_INCLUDE_DIR = /usr/local/include
# Library directory for SFML, adjust if your SFML libraries are in a non-standard location
SFML_LIB_DIR = /usr/local/lib
LDFLAGS = -L$(SFML_LIB_DIR) -lsfml-graphics -lsfml-window -lsfml-system

# Main targets
all: tree test

# Build the main executable
tree: Main.o
	$(CXX) $(CXXFLAGS) -o tree Main.o $(LDFLAGS)

# Build the test executable
test: Test.o
	$(CXX) $(CXXFLAGS) -o test Test.o $(LDFLAGS)

# Compile Main.cpp
Main.o: Main.cpp Node.hpp Tree.hpp
	$(CXX) $(CXXFLAGS) -I$(SFML_INCLUDE_DIR) -c Main.cpp

# Compile Test.cpp
Test.o: Test.cpp Node.hpp Tree.hpp
	$(CXX) $(CXXFLAGS) -I$(SFML_INCLUDE_DIR) -c Test.cpp

# Clean up build artifacts
clean:
	rm -f *.o tree test

.PHONY: all clean
