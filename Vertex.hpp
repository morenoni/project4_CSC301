/*
 * CSC-301
 * Vertex.hpp
 * Fall 2025
 * Eric A. Autry
 * 11/23/22
 */

#ifndef VERTEX_HPP_
#define VERTEX_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>
#include <math.h>

/*
 * Vertex Class for the MST/TSP project.
 */
class Vertex {

    public:
        explicit Vertex();
        explicit Vertex(int labelSet, std::string citySet);

        // Info for the original graph:
        int label;                      // The label for this vertex as an int.
        std::string city;               // The city name for this vertex.
        std::vector<int> neighbors;     // The list of labels of the neighbors.
        std::vector<int> mstNeighbors; // The neighbor list for the MST!

        // Overloaded == compares two Vertex objects based on their labels.
        bool operator == (Vertex const &other) const {
            return label == other.label;
        }

        // printVertex returns a string clearly printing info about the Vertex.
        std::string printVertex();
};

#endif  // VERTEX_HPP_