/*
 * CSC-301
 * Edge.hpp
 * Fall 2025
 * Eric A. Autry
 * 11/23/22
 */

#ifndef EDGE_HPP_
#define EDGE_HPP_

#include "Vertex.hpp"

/*
 * Vertex Class for the MST/TSP project.
 */
class Edge {

    public:
        explicit Edge(Vertex &u, Vertex &v, double weightSet);

        Vertex first;  // One of the two vertices for this edge.
        Vertex second; // The other vertex for this edge.
        double weight; // The weight of this edge.

        // Overloaded comparison operators compare edges based on weight.
        bool operator == (Edge const &other) const {
            return weight == other.weight;
        }
        bool operator != (Edge const &other) const {
            return weight != other.weight;
        }
        bool operator < (Edge const &other) const {
            return weight < other.weight;
        }
        bool operator <= (Edge const &other) const {
            return weight <= other.weight;
        }
        bool operator >= (Edge const &other) const {
            return weight >= other.weight;
        }
        bool operator > (Edge const &other) const {
            return weight > other.weight;
        }

        // printEdge returns a string clearly printing info about the Edge.
        std::string printEdge();
};

#endif  // EDGE_HPP_