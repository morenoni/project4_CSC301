/*
 * CSC-301
 * Vertex.cpp
 * Fall 2025
 * Eric A. Autry
 * 11/23/22
 */

#include "Vertex.hpp"

using namespace std;

/*
 * Default Constructor for the Vertex class.
 * 
 * Sets the label to be -1.
 * Sets the city to be "".
 * Note that both neighbors vectors default to an empty vector automatically.
 */
Vertex::Vertex() {
    label = -1;
    city = "";
}

/*
 * Constructor for the Vertex class.
 * 
 * Sets the label to be the input label.
 * Sets the city to be the input city name.
 * Note that both neighbors vectors default to an empty vector automatically.
 */
Vertex::Vertex(int labelSet, string citySet) {
    label = labelSet;
    city = citySet;
}

/*
 * printVertex creates a string that nicely prints info about the Vertex.
 */
string Vertex::printVertex() {
    stringstream toPrint;
    toPrint << "Label: " << to_string(label);
    toPrint << endl;
    toPrint << "City: " << city;
    toPrint << endl;
    toPrint << "Neighbors:" << endl;
    for (int neigh : neighbors) {
        toPrint << to_string(neigh) << " ";
    }
    toPrint << endl;
    toPrint << endl;
    toPrint << "MST Neighbors:" << endl << "\t";
    for (int neigh : mstNeighbors) {
        toPrint << to_string(neigh) << " ";
    }
    toPrint << endl;

    return toPrint.str();
}