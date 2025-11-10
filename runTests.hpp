/*
 * CSC-301
 * runTests.hpp
 * Fall 2025
 * Eric A. Autry
 * 11/23/22
 */

#ifndef RUNTESTS_HPP_
#define RUNTESTS_HPP_

#include <cstring>
#include <algorithm>
#include "Vertex.hpp"
#include "Edge.hpp"
#include "prim.hpp"
#include "kruskal.hpp"
#include "tsp.hpp"

/*
 * getDist
 * 
 * This function takes in two coordinates and returns the great circle distance
 * between them (in kilometers).
 * 
 * INPUTS
 * double lat1, long1: the latitude and longitude of the first city.
 * double lat2, long2: the latitude and longitude of the second city.
 * 
 * OUTPUTS
 * double dist: the great circle distance between the two cities (km).
 */
double getDist(double lat1, double long1, double lat2, double long2);

/*
 * getMap
 * 
 * This function will fill the adjacency list, adjacency matrix, and edge list
 * as well as print info about the optimal tour for the selected scenario.
 * 
 * INPUTS
 * int mapNum: the number of which map to select.
 * vector<Vertex> &adjList: the adjacency list to fill.
 * vector<double> &adjMat: the adjacency matrix to fill.
 * vector<Edge> &edgeList: the edge list to fill.
 * 
 * OUTPUTS
 * optTour.str(): a string printing info about the opt tour for this case
 * Note: will also fill the adjList, adjMat, and edgeList.
 */
std::string getMap(int mapNum, std::vector<Vertex> &adjList, 
                   std::vector<double> &adjMat, std::vector<Edge> &edgeList);

/*
 * getMSTWeight
 * 
 * This function will return the total weight of the MST given its edges.
 * 
 * INPUTS
 * vector<Edge> &mst: the list of edges in the MST.
 * 
 * OUTPUTS
 * double totalWeight: the sum of the weights
 */
double getMSTWeight(std::vector<Edge> &mst);

/*
 * getTourWeight
 * 
 * This function will return the total weight of the TSP tour.
 * 
 * INPUTS
 * vector<int> &tour: the list of vertex labels of the tour.
 * vector<Vertex> &adjList: the adjacency list.
 * vector<double> &adjMat: the adjacency matrix.
 * 
 * OUTPUTS
 * double tourWeight: the total weight of the tour.
 */
double getTourWeight(std::vector<int> &tour, std::vector<Vertex> &adjList, 
                     std::vector<double> &adjMat);

/*
 * testMaps
 * 
 * This function will test your code on the various maps.
 * 
 * INPUTS
 * bool verb: verbosity flag, if true will print info on solutions.
 *            defaulted to false
 * 
 * OUTPUTS
 * No return value, but prints info indicating number of tests passed.
 */
void testMaps(bool verb);

/* main
 * 
 * 
 *
 * Run this function with the command:
 *     ./runTests
 *
 * Note: you can turn on verbosity with a -v flag:
 *     ./runTests -v
 *
 */
int main(int argc, char* argv[]);

#endif  // RUNTESTS_HPP_
