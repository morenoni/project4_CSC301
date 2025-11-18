/*
 * CSC-301
 * tsp.cpp
 * Fall 2025
 *
 * Partner 1: Nicky Moreno Gonzalez
 * Partner 2: Natalie Nardone 
 * Date:
 */

#include "tsp.hpp"

using namespace std;

/*
 * tsp
 */
vector<int> tsp(vector<Vertex> &adjList, Vertex &start) {
    // Create the empty tour.
    vector<int> tour;
    
    // Create the vector for tracking visited during the DFS.
    int n = adjList.size();
    vector<bool> visited(n, false);

    return tour;
}