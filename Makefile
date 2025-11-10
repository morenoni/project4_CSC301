# Makefile for CSC-301 Project #5
# Eric A. Autry, 11/23/22
# 
# As usual, you can build this software by typing:
#
#     make


# ----- Make Macros -----

CXXFLAGS =	-O3
CXX	=	clang

TARGETS =	runTests
OBJECTS =	runTests.cpp prim.cpp kruskal.cpp tsp.cpp Edge.cpp Vertex.cpp
REMOVE =	runTests.o prim.o kruskal.o tsp.o Edge.o Vertex.o
LINKS =	-std=c++2a -lstdc++ -lm
INCLUDE = 

# ----- Make Rules -----

all:	$(TARGETS)

runTests:	$(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o runTests $(OBJECTS) $(LINKS)

clean:
	rm -f $(TARGETS) $(REMOVE)
