/*
 * CSC-301
 * Edge.cpp
 * Fall 2025
 * Eric A. Autry
 * 11/23/22
 */

#include "Edge.hpp"

using namespace std;

/*
 * Constructor for the Edge class.
 * 
 * Sets the vertices and edges to the input values.
 */
Edge::Edge(Vertex &u, Vertex &v, double weightSet) {
    first = u;
    second = v;
    weight = weightSet;
}

/*
 * printEdge creates a string that nicely prints info about the Edge.
 */
string Edge::printEdge() {
    stringstream toPrint;
    toPrint << "First Vertex: " << to_string(first.label) << ", ";
    toPrint << first.city << endl;
    toPrint << "Second Vertex: " << to_string(second.label) << ", ";
    toPrint << second.city << endl;
    toPrint << "Weight: " << to_string(weight) << endl;
    return toPrint.str();
}