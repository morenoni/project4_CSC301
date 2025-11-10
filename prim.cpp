/*
 * CSC-301
 * prim.cpp
 * Fall 2025
 *
 * Partner 1:
 * Partner 2:
 * Date:
 */

#include "prim.hpp"

using namespace std;

/*
 * getMin
 */
int getMin(vector<double> &cost, vector<bool> &visited) {
    return -1;
}

/*
 * isEmpty
 */
bool isEmpty(vector<bool> &visited) {
    return true;
}

/*
 * prim
 */
vector<Edge> prim(vector<Vertex> &adjList, vector<double> &adjMat) {
    // Initialize the empty MST.
    vector<Edge> mst;
    
    // For each vertex, we need a visited flag, a 'cost' for Prim's, and the
    // prev values to track the MST. Store these in seperate vectors.
    int n = adjList.size();
    vector<bool> visited(n, false);
    vector<double> cost(n, numeric_limits<double>::infinity());
    vector<int> prev(n, -1);

    return mst;
}