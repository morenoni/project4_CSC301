/*
 * CSC-301
 * tsp.hpp
 * Fall 2025
 *
 * Partner 1: Nicky Moreno Gonzalez
 * Partner 2: Natalie Nardone 
 * Date: Thursday, November 20, 2025
 */

#ifndef TSP_HPP_
#define TSP_HPP_

#include <stack>

#include "Vertex.hpp"

/*
 * tsp
 */
std::vector<int> tsp(std::vector<Vertex> &adjList, Vertex &start);

#endif  // TSP_HPP_